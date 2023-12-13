#include "cube3d.h"



int setmove(int* key)
{
	if(*key == 0)
		*key = 1;
	else
		*key = 0;
	return(1);
}
int	move_w(t_data *vars)
{

	while (vars->move_w == 1)
	{
		// int xo=0; if(vars->player.dx*5<0){ xo=-vars->longest_row;} else{ xo=vars->longest_row;}
		// int yo=0; if(vars->player.dy*5<0){ yo=-vars->final_c;} else{ yo=vars->final_c;} 
		// int ipx = vars->player.x/vars->scale;
		// int ipy = vars->player.y/vars->scale;
		// int ipxadd = (ipx +xo)/vars->scale;
		// int ipxsub = (ipx-xo)/vars->scale;
		// int ipyadd = (ipy+yo)/vars->scale;
		// int ipysub = (ipy-yo)/vars->scale;
		
		if(vars->map[(int)(vars->player.y -vars->player.dy *5.2)/vars->scale ][(int)(vars->player.x -vars->player.dx *5.2)/vars->scale]!=1)
		{
			vars->player.y -= vars->player.dy*5;
			vars->player.x -= vars->player.dx*5;
		}
		else
		{
			printf("mapw %d\n",(vars->map[(int)(vars->player.y -vars->player.dy *5.2)/vars->scale ][(int)(vars->player.x -vars->player.dx *5.2)/vars->scale ]));
		}
		// if(vars->map[(int)vars->player.y/vars->scale][(int)(vars->player.x -vars->player.dx *5.2)/vars->scale ]==0)
			move(vars,0,0);
			mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);

		// if(vars->map[(int)vars->cy ][(int)(vars->cx + vars->player.dx*2 )] == 0) 
		// 	vars->cx  += vars->player.dx*2 ;
        // if(vars->map[(int)(vars->cy  + vars->player.dy *2)][(int)vars->cx ] == 0) 
		// 	vars->cy  += vars->player.dy*2 ;
        
	}
	return(1);
}

int	move_s(t_data *vars)
{
	while (vars->move_s == 1)
	{
		if(vars->map[(int)(vars->player.y +vars->player.dy *5.2)/vars->scale ][(int)(vars->player.x +vars->player.dx *5.2)/vars->scale ]!=1)
		{

			vars->player.y += vars->player.dy*5;
			vars->player.x += vars->player.dx*5;
		}
		else
		{
			printf("maps %d\n",(vars->map[(int)(vars->player.y +vars->player.dy *5.2)/vars->scale ][(int)(vars->player.x +vars->player.dx *5.2)/vars->scale ]));
		}
		move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		// if(vars->map[(int)vars->player.y/vars->scale][(int)(vars->player.x +vars->player.dx *5.2)/vars->scale ]==0)
		// if(vars->map[(int)vars->cy ][(int)(vars->cx - vars->player.dx )] == 0) vars->cx -= vars->player.dx ;
        // if(vars->map[(int)(vars->cy  - vars->player.dy )][(int)vars->cx ] == 0) vars->cy -= vars->player.dy ;
	}
	return(1);
}

int	move_a(t_data *vars)
{
	while (vars->move_a == 1)
	{
		// vars->player.da -=0.1;
		// if (vars->player.da < 0)
		// 	vars->player.da += 2*PI;
		// vars->player.dx = cos(vars->player.da);
		// vars->player.dy = sin(vars->player.da);

		vars->player.da -=10;
			FixAng(vars->player.da);
			
		vars->player.dx = cos(radiansfd(vars->player.da));
		vars->player.dy = sin(radiansfd(vars->player.da));
		// double oldDirX = vars->player.dx;
		// vars->player.dx = vars->player.dx * cos(1) - vars->player.dy * sin(1);
		// vars->player.dy = oldDirX * sin(1) + vars->player.dy * cos(1);
		// double oldPlaneX = vars->camaera.x;
		// vars->camaera.x = vars->camaera.x * cos(1) - vars->camaera.y * sin(1);
		// vars->camaera.y = oldPlaneX * sin(1) + vars->camaera.y * cos(1);
		move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
	}
	return(1);
}
int	move_d(t_data *vars)
{
	while (vars->move_d == 1)
	{
		vars->player.da +=10;
			FixAng(vars->player.da);
		// vars->player.da +=0.1;
		// if (vars->player.da >2*PI)
			// vars->player.da -= 2*PI;
		// vars->player.dx = cos((vars->player.da));
		// vars->player.dy = sin((vars->player.da));

		vars->player.dx = cos(radiansfd(vars->player.da));
		vars->player.dy = sin(radiansfd(vars->player.da));
		// double oldDirX = vars->player.dx;
		// vars->player.dx = vars->player.dx * cos(-1) - vars->player.dy * sin(-1);
		// vars->player.dy = oldDirX * sin(-1) + vars->player.dy * cos(-1);
		// double oldPlaneX = vars->camaera.x;
		// vars->camaera.x = vars->camaera.x * cos(-1) - vars->camaera.y * sin(-1);
		// vars->camaera.y = oldPlaneX * sin(-1) + vars->camaera.y * cos(-1);
		move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
	}
	return(1);
}

int moves(int keycode, t_data *vars)
{
    // printf("keycode :: %d\n",keycode);
	

	if ((keycode == 13 || keycode == 119) && setmove(&vars->move_w))
    {
			// move_w(vars,1,0);
			// move_w(vars,,1);
	while (vars->move_w == 1)
	{
		//   int xo=0; if(vars->player.dx<0){ xo=-vars->final_c;} else{ xo=vars->final_c;}
		//   int yo=0; if(vars->player.dy<0){ yo=-vars->longest_row;} else{ yo=vars->longest_row;} 
		// int ipx = vars->player.x/vars->scale;
		// int ipxadd = (vars->player.x+xo)/vars->scale;
		// int ipxsub = (vars->player.x-xo)/vars->scale;
		// int ipyadd = (vars->player.y+yo)/vars->scale;
		// int ipysub = (vars->player.y-yo)/vars->scale;
		// int ipy = vars->player.y/vars->scale;
		// printf("px %d %d\n",ipx,ipxadd);
		// printf("py %d %d\n",ipy,ipyadd);
		// if(vars->map[ipy][ipxsub]==0)
		// 	vars->player.x -= vars->player.dx*5;
		// if(vars->map[ipysub][ipx]==0)
		// 	vars->player.y -= vars->player.dy*5;
		// if(vars->map[(int)vars->cy ][(int)(vars->cx + vars->player.dx*2 )] == 0) 
		// 	vars->cx  += vars->player.dx*2 ;
        // if(vars->map[(int)(vars->cy  + vars->player.dy *2)][(int)vars->cx ] == 0) 
		// 	vars->cy  += vars->player.dy*2 ;
		move_w(vars);
        
		// move(vars,0,0);
        // mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
	}

	}
	else if ((keycode == 1|| keycode == 115) && setmove(&vars->move_s))
    {
		move_s(vars);
    }//a
    else if ((keycode == 0|| keycode == 97) && setmove(&vars->move_a))
    {
		move_a(vars);
    }//d
    else if ((keycode == 2|| keycode == 100)  && setmove(&vars->move_d))
    {
		move_d(vars);
    }
    if (keycode == 53 || keycode == 65307)
    {
		mlx_clear_window(vars->mlx_ptr,vars->win_ptr);
		mlx_destroy_image(vars->mlx_ptr,vars->img);
		mlx_destroy_window(vars->mlx_ptr,vars->win_ptr);
		exit(0);
	}
    return (0);
}