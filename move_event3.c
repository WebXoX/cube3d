#include "cube3d.h"
int setmove(int* key)
{
    if(*key == 0)
        *key = 1;
    else
        *key = 0;
    return(1);
}
void movews(t_data *vars)
{
    int dir;
    int newx;
    int newy;
    if (vars->move.w == 1)
        dir = 1;
    else if (vars->move.s == 1)
        dir = -1;
    printf("hello----------------------?>%d\n",vars->move.w);
    // while (vars->move.w == 1|| vars->move.s == 1)
	// {
       if (vars->cx + vars->player.dx*0.6*dir   < vars->longest_row && vars->cx + vars->player.dx*0.6*dir  >= 0 && vars->cy < vars->final_c && vars->cy >= 0
        && vars->map[(int)vars->cy][(int)(vars->cx + vars->player.dx*0.6*dir) ] != 1)
		{
			vars->player.x += vars->player.dx*4;
			vars->cx  += vars->player.dx*(0.45 *dir) ;
		}
		if (vars->cx  < vars->longest_row && (vars->cx) >= 0 
		&& (int)(vars->cy  + vars->player.dy * 0.6*dir) < vars->final_c 
		&& (int)(vars->cy  + vars->player.dy * 0.6*dir) >= 0
			&& vars->map[(int)(vars->cy  + vars->player.dy * 0.6*dir)][(int)(vars->cx) ] != 1)
		{
			vars->player.y += vars->player.dy*14;
			vars->cy  += vars->player.dy*(0.45*dir);
		}    
	
		move(vars);
        setmove(&vars->move.w);
        setmove(&vars->move.s);
        // mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
    // }
}
int moves(int keycode, t_data *vars)
{
    printf("hello----------------------?> %d\n",keycode);
    
    if ((keycode == 13 || keycode == 119) && setmove(&vars->move.w))
        movews(vars);
    else if ((keycode == 1|| keycode == 115) && setmove(&vars->move.s))
    {
        movews(vars);
    }//a
    // else if ((keycode == 0|| keycode == 97) && setmove(&vars->move.a))
    // {
    //     move_a(vars);
    // }//d
    // else if ((keycode == 2|| keycode == 100)  && setmove(&vars->move.d))
    // {
    //     move_d(vars);
    // }
    // else if ((keycode == 124|| keycode == 65363) && setmove(&vars->move.r))
    // {
    //     move_r(vars);
    // }//d
    // else if ((keycode == 123|| keycode == 65361)  && setmove(&vars->move.l))
    // {
    //     move_l(vars);
    // }
    if (keycode == 53 || keycode == 65307)
		exit(0);
        // error_free(vars, -1, "Exit\n");
    return (0);
}
