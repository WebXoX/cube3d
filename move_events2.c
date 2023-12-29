#include "cube3d.h"
int setmove(int* key)
{
    if(*key == 0)
        *key = 1;
    else
        *key = 0;
    return(1);
}
int move_w(t_data *vars)
{
	while (vars->move.w == 1)
	{
		if (vars->cx + vars->player.dx*1  < vars->longest_row && vars->cx + vars->player.dx*1  >= 0 && vars->cy < vars->final_c && vars->cy >= 0
        && vars->map[(int)vars->cy][(int)(vars->cx + vars->player.dx*1) ] != 1)
		{
			vars->player.x += vars->player.dx*14;
			vars->cx  += vars->player.dx*(0.8) ;
		}
		if (vars->cx  < vars->longest_row && (vars->cx) >= 0 
		&& (int)(vars->cy  + vars->player.dy *1) < vars->final_c 
		&& (int)(vars->cy  + vars->player.dy *1) >= 0
			&& vars->map[(int)(vars->cy  + vars->player.dy *1)][(int)(vars->cx) ] != 1)
		{
			vars->player.y += vars->player.dy*14;
			vars->cy  += vars->player.dy*(0.8);
		}    
	
		move(vars);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
    }
    return(1);
}
int move_s(t_data *vars)
{
    while (vars->move.s == 1)
    {
        if ((int)vars->cx   < vars->longest_row && (int)vars->cx   >= 0//&& vars->cy < vars->final_c && vars->cy >= 0
        && vars->map[(int)vars->cy][(int)(vars->cx - vars->player.dx*1) ] != 1)
		{
			vars->player.x -= vars->player.dx*14;
			vars->cx  -= vars->player.dx*0.8 ;
		}
		if (vars->cx  < vars->longest_row && (vars->cx) >= 0 
		&& (int)(vars->cy  + vars->player.dy *1) < vars->final_c 
		&& (int)(vars->cy  + vars->player.dy *1) >= 0
			&& vars->map[(int)(vars->cy  - vars->player.dy *1)][(int)(vars->cx) ] != 1)
		{
			vars->player.y -= vars->player.dy*14;
			vars->cy  -= vars->player.dy*0.8;
		}    
		move(vars);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
    }
    return(1);
}
int move_a(t_data *vars)
{
    while (vars->move.a == 1)
    {
        double rayAngle = (atan2l(vars->player.dy,vars->player.dx) -  vars->directionstart*( PI/2));
        if (vars->cx +cos(rayAngle)*0.6  < vars->longest_row && vars->cx +cos(rayAngle)*0.6 >= 0 && vars->cy < vars->final_c && vars->cy >= 0
        && vars->map[(int)vars->cy][(int)(vars->cx +cos(rayAngle)*0.6) ] != 1)
        {
            vars->player.x -= vars->player.dx*0.8;
            vars->cx  += cos(rayAngle)*0.5 ;
        }
        if (vars->cx  < vars->longest_row && (vars->cx) >= 0
        && (int)(vars->cy +sin(rayAngle)*0.6) < vars->final_c
        && (int)(vars->cy + sin(rayAngle)*0.6) >= 0
            && vars->map[(int)(vars->cy + sin(rayAngle)*0.6)][(int)(vars->cx) ] != 1)
        {
            vars->player.y+= vars->player.dy*0.5;
            vars->cy += sin(rayAngle)*0.5 ;
        }
        move(vars);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
    }
    return(1);
}
int move_d(t_data *vars)
{
    while (vars->move.d == 1)
    {
        double rayAngle = (atan2l(vars->player.dy,vars->player.dx) - vars->directionstart*(PI/2));
        if (vars->cx - cos(rayAngle)*0.4  < vars->longest_row && vars->cx - cos(rayAngle)*0.4 >= 0 && vars->cy -  sin(rayAngle)*0.4< vars->final_c && vars->cy -  sin(rayAngle)*0.4 >= 0
            && vars->map[(int)(vars->cy)][(int)(vars->cx - cos(rayAngle)*0.4) ] != 1)
        {
            vars->player.x -= vars->player.dx*0.3;
            vars->cx  -= cos(rayAngle)*0.3 ;
        }
        if (vars->cx  < vars->longest_row && (vars->cx) >= 0
        && (int)(vars->cy  - sin(rayAngle)*0.4) < vars->final_c
        && (int)(vars->cy  - sin(rayAngle)*0.4) >= 0
            && vars->map[(int)(vars->cy -sin(rayAngle)*0.4) ][(int)(vars->cx) ] != 1)
        {
            vars->player.y -= vars->player.dy*0.4;
            vars->cy  -= sin(rayAngle)*0.3;
        }
        move(vars);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
    }
    return(1);
}
int move_l(t_data *vars)
{
    while (vars->move.l == 1)
    {
        double rayAngle = vars->directionstart;
        double oldDirX = vars->player.dx;
        vars->player.dx = vars->player.dx * cos(-0.1 *rayAngle) - vars->player.dy * sin(-0.1 *rayAngle);
        vars->player.dy = oldDirX * sin(-0.1 *rayAngle) + vars->player.dy * cos(-0.1 *rayAngle);
        double oldPlaneX = vars->camaera.x;
        vars->camaera.x = vars->camaera.x * cos(-0.1 *rayAngle) - vars->camaera.y * sin(-0.1 *rayAngle);
        vars->camaera.y = oldPlaneX * sin(-0.1 *rayAngle) + vars->camaera.y * cos(-0.1 *rayAngle);
        move(vars);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
    }
    return(1);
}
int move_r(t_data *vars)
{
    while (vars->move.r == 1)
    {
        double rayAngle =  vars->directionstart;
        double oldDirX = vars->player.dx;
        vars->player.dx = vars->player.dx * cos(0.1 *rayAngle) - vars->player.dy * sin(0.1 *rayAngle);
        vars->player.dy = oldDirX * sin(0.1 *rayAngle) + vars->player.dy * cos(0.1 *rayAngle);
        double oldPlaneX = vars->camaera.x;
        vars->camaera.x = vars->camaera.x * cos(0.1 *rayAngle) - vars->camaera.y * sin(0.1 *rayAngle);
        vars->camaera.y = oldPlaneX * sin(0.1 *rayAngle) + vars->camaera.y * cos(0.1 *rayAngle);
        move(vars);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
    }
    return(1);
}
int moves(int keycode, t_data *vars)
{
    printf("keycode :: %d\n",keycode);
    if ((keycode == 13 || keycode == 119) && setmove(&vars->move.w))
        move_w(vars);
    else if ((keycode == 1|| keycode == 115) && setmove(&vars->move.s))
    {
        move_s(vars);
    }//a
    else if ((keycode == 0|| keycode == 97) && setmove(&vars->move.a))
    {
        move_a(vars);
    }//d
    else if ((keycode == 2|| keycode == 100)  && setmove(&vars->move.d))
    {
        move_d(vars);
    }
    else if ((keycode == 124|| keycode == 65363) && setmove(&vars->move.r))
    {
        move_r(vars);
    }//d
    else if ((keycode == 123|| keycode == 65361)  && setmove(&vars->move.l))
    {
        move_l(vars);
    }
    printf("cy%f, cy%f, px%f, py%f \n",vars->camaera.x, vars->camaera.y, vars->player.dx,vars->player.dy);
    if (keycode == 53 || keycode == 65307)
		exit(0);
        // error_free(vars, -1, "Exit\n");
    return (0);
}