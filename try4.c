/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:12:05 by jperinch          #+#    #+#             */
/*   Updated: 2023/11/28 12:59:39 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
int move(t_data *img,float x,float y);
void drawline(int *vals, t_data *img, int *color_list);
void ray(t_data *img);
void wall(t_data *img);
void tile(t_data *img);
void player(t_data *img);


int moves(int keycode, t_data *vars)
{
    // printf("keycode :: %d\n",keycode);
    //w
    if (keycode == 13 || keycode == 119)
    {
        vars->player.x -= vars->player.dx;
        vars->player.y -= vars->player.dy;

        move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
        return (1);
    }//s
    else if (keycode == 1|| keycode == 115)
    {
        vars->player.x += vars->player.dx;
        vars->player.y += vars->player.dy;

        move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);

        return (1);
    }//a
    else if (keycode == 0|| keycode == 97)
    {
        vars->player.da -=0.1;
        if (vars->player.da < 0)
        {
            vars->player.da += 2*PI;
        }
        vars->player.dx = cos(vars->player.da)*5;
        vars->player.dy = sin(vars->player.da)*5;
        move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
        return (1);
    }//d
    else if (keycode == 2|| keycode == 100)
    {
        vars->player.da +=0.1;
        if (vars->player.da >2*PI)
        {
            vars->player.da -= 2*PI;
        }
        vars->player.dx = cos(vars->player.da)*5;
        vars->player.dy = sin(vars->player.da)*5;
        move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
        return (1);
    }
    if (keycode < 0)
        exit(1);
    return (0);
}
float dist(float ax, float ay, float bx, float by, float amgle)
{
    return (sqrt((bx-ax)*(bx-ax) - (by-ay)*(by-ay)));
}

int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}
void ray(t_data *img)
{
    int map[]=           //the map array. Edit to change level but keep the outer walls
    {
    1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
    };
    float px, py;
    px = img->player.x -  img->player.dx*2;
    py = img->player.y - img->player.dy*2;
    int r,mx,my,mp,dof,side; float vx,vy,rx,ry,ra,xo,yo,disV,disH;
    // ra = img->player.da-DR*30;
    ra = img->player.da + PI;
    printf("ray :: %f------------------------------------->\n",ra);

    if (ra<0)
    {
        ra +=2*PI;
        /* code */
    }
    if (ra> 2*PI)
    {
        ra -=2*PI;
        /* code */
    }
    printf("ray :: %f------------------------------------->\n",ra);
    for (size_t i = 0; i < 120; i++)
    {
        dof =0;
        float tan1 = -1/tan(ra);
        //horizontal detection
        if (ra > PI)
        {
            //left  angles
            ry = (((int)py>>6)<<6)-0.0001;
            rx=(py-ry)*tan1+px;
            yo = -64;
            xo=-yo*tan1;
        }
        if(ra < PI)
        {
            // right side angles
            ry = (((int)py>>6)<<6)+64;
            rx=(py-ry)*tan1+px;
            yo= 64;
            xo=-yo*tan1;
        }
        if(ra==0 || ra==PI)
        {
            //when angle is 180
            rx=px; ry=py; dof=8;
        }
        while(dof<8)
        {

            mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*8+mx;
            if(mp>0 && mp<8*8 && map[mp]==1)
				dof=8; //hit
            else
			{
				rx+=xo; ry+=yo; dof+=1;
			}//check next horizontal
        }
	float x1 = rx;
	float y1 = ry;
	float d1 = sqrt(pow(rx - px, 2) + pow(ry - py, 2));

        dof =0;
        printf("hoo\n");
        float tan2 = -tan(ra);
        //vertical detection

        if (ra>PI/2 && ra <3*PI/2)
        {
            // left side
            rx = (((int)px>>6)<<6)-0.0001;
            ry=(px-rx)*tan2+py;
            xo = -64;
            yo=-xo*tan2;
        }
       else  if(ra<PI/2 || ra >3*PI/2)
        {
            //right side
            rx = (((int)px>>6)<<6)+64;
            ry=(px-rx)*tan2+py;
            xo= 64;
            yo=-xo*tan2;
        }
        else if(ra==0 || ra==PI)
        {
		rx=px; ry=py; dof=8;
        }
        while(dof<8)
        {
            printf("hoo dof %f: %f:\n",rx,ry);

            mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*8+mx;
            if(mp>0 && mp<8*8 && map[mp]==1){ dof=8; }//hit
            else
			{
				rx+=xo; ry+=yo; dof+=1;
			}//check next horizontal
        }
        float finald;
	float d2 = sqrt(pow(rx - px, 2) + pow(ry - py, 2));
	if(d1 > d2)
    {
    	drawline((int []){px,py+4,rx,ry},img,(int[]){0xFF0000});
        finald = d2;
    }
    else
    {
		drawline((int []){px,py+4,x1,y1},img,(int[]){0xFF0000});
        finald = d1;
    }
        float ca  = img->player.da - ra;
        if (ca<0)
        {
            ca +=2*PI;
            /* code */
        }
        if (ca> 2*PI)
        {
            ca -=2*PI;
            /* code */
        }
        finald = finald* cos(ca);
	float lh = (64 *800)/finald;
    if(lh >640)
        lh=640;
	float lo = 320 -lh/2;
    	// drawline((int []){(i*8)+529,0,(i*8)+529,lh},img,(int[]){0xFF0000});
        int j=0;

        while (j <8)
        {
    	    drawline((int []){((i*8) + j),lo,(i*8)+j,lh+lo},img,(int[]){0xFF0000});
            /* code */
            j++;
        }
        
    	// drawline((int []){(i*8)+531,0,(i*8)+531,lh},img,(int[]){0xFF0000});
     ra +=0.001;
        
    if (ra<0)
    {
        ra +=2*PI;
        /* code */
    }
    if (ra> 2*PI)
    {
        ra -=2*PI;
        /* code */
    }
    }

}

void    run(t_data *canva)
{
    mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0,
        0);
        mlx_hook(canva->win_ptr, 2, 1L << 1, moves, &(*canva));
    // mlx_key_hook(canva->win_ptr, moves, &(*canva));
    mlx_loop(canva->mlx_ptr);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    if ((data->width > x && data->height > y) && (0 <= x && 0 <= y))
    {
        dst = data->addr + (y * data->line_bytes + x * (data->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

void    step(int *p2, int *p1, double *error, double dp)
{
    *error = *error + dp;
    if (*p1 < *p2)
        *p1 = *p1 + 1;
    else
        *p1 = *p1 - 1;
}


void    drawline(int *vals, t_data *img, int *color_list)
{
    int i;
    int color;
    t_line line;

    color = color_list[0];
    line.dx = abs(vals[2] - vals[0]);
    line.dy = -abs(vals[3] - vals[1]);
    line.error = line.dx + line.dy;
    i = 0;
    while (1)
    {
        my_mlx_pixel_put(img, vals[0], vals[1], color);
        if (vals[1] == vals[3] && vals[2] == vals[0])
            break ;
        line.e2 = 2 * line.error;
        if (line.e2 <= line.dx)
        {
            if (vals[3] == vals[1])
                break ;
            step(&vals[3], &vals[1], &(line.error), line.dx);
        }
        if (line.e2 >= line.dy)
        {
            if (vals[0] == vals[2])
                break ;
            step(&vals[2], &vals[0], &(line.error), line.dy);
        }
        i++;
    }
}
void render(t_data *img)
{
    int i   =   0;
    int j   =   0;
    int map[8][8]=           //the map array. Edit to change level but keep the outer walls
    {
    {1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,1},
    {1,0,2,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
    };
    // drawline((int[]){img->player.x,img->player.y,img->player.x -img->player.dx*5,img->player.y-img->player.dy *5},img,(int[]){0xFFFFFFF});
    // ray(img);
    run(&(*img));
}


int move(t_data *img,float x, float y)
{
    int i ;
    int j =0;
    coordinate_t point;
    point.x=0;
    point.y=0;
    // wall and tile re draw
    wall(img);
    tile(img);
    img->player.y -= y;
    img->player.x -= x;
    i=0;
    //player re draw
    //ray is called in this function
    // render(img);
    //runs loop
    ray(img);
    // drawline((int[]){img->player.x,img->player.y+5,img->player.x -(img->player.dx*2),img->player.y-1-(img->player.dy *2)},img,(int[]){0x735674});
    player(img);

    run(img);
    return (0);
}

void player(t_data *img)
{
    int i;
    int j;
    int c;
    coordinate_t point;
    int ratio_y = img->height/64;
    int ratio_x = img->width/64;
    int player_h;
    // if(ratio_y < 10)
        player_h = ratio_x/4;
    int map[8][8]=           //the map array. Edit to change level but keep the outer walls
        {
        {1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,1},
        {1,0,2,0,0,0,0,1},
        {1,1,1,1,1,1,1,1}
        };
    i=0;
    j=0;
        while (i < 8)
        {
            j=0;
            while (j < 8)
            {
                if(map[i][j]==2)
                {
                    c=0;
                    while (c < player_h)
                    {
                        drawline((int[]){img->player.x ,img->player.y + c ,img->player.x+ ratio_x/4 ,img->player.y + c} ,img,(int[]){0x735674});
                        c++;
                    }
                }
                point.x+=ratio_x;
                j++;
            }
            point.x=0;
            point.y+=ratio_y;
            i++;
        }
}


void tile(t_data *img)
{
    int i;
    int j;
    coordinate_t point;
    int map[8][8]=           //the map array. Edit to change level but keep the outer walls
    {
    {1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,1},
    {1,0,2,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
    };
    i=0;
    int ratio_y = img->height/64;
    int ratio_x = img->width/64;

    
    while (i < 8)
    {
        j=0;
        while (j < 8)
        {
            int c;
            if(map[i][j]==0 || map[i][j]== 2)
            {
                c = 0;
                // while (c < 66)
                // {
                //     // printf("from tile : %d\n",c);
                //     drawline((int[]){point.x -1 ,point.y-1 + c ,point.x
                //             + ratio_y +1 ,point.y -1 + c} , img, (int[]){0x045680});
                //     c++;
                // }
                c = 0;

                while (c < ratio_y - 2)
                {
                    // printf("from tile : %d\n",c);
                    drawline((int[]){point.x ,point.y + c ,point.x
                            + ratio_x-2 ,point.y + c} , img, (int[]){0x000});
                    c++;
                }
                if ( map[i][j] == 2)
                {
                    // img->player.x = point.x  + 64/2;
                    // img->player.y = point.y  + 64/2;

                    c = 0;
                    while (c < 10)
                    {
                        // printf("in player x:%d\n\n",c);
                        // drawline((int[]){img->player.x ,img->player.y + c ,img->player.x+ 10 ,img->player.y + c} ,img,(int[]){0x75643});

                        c++;
                    }
                    // return ;
                }

            }
            point.x+=ratio_x;
            j++;
        }
        point.x=0;
        point.y+=ratio_y;
        i++;
    }
}
void wall(t_data *img)
{
    int i;
    int j;
    coordinate_t point;
    int map[8][8]=           //the map array. Edit to change level but keep the outer walls
    {
        {1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,1},
        {1,0,2,0,0,0,0,1},
        {1,1,1,1,1,1,1,1}
    };
    j   =   0;
    i   =   0;
    int ratio_y = img->height/64;
    int ratio_x = img->width/64;
    while (i < img->height)
    {

        drawline((int[]){0,i ,img->width ,i} ,img, (int[]){0x045680});
        i++;
    }
    i=0;
    j=0;
    while (i < 8)
    {
        j=0;
        while (j < 8)
        {
            int c;
            if(map[i][j]==1)
            {
                c = 0;
                while (c < ratio_y - 2)
                {
                    printf("from wall: %d\n",c);
                    drawline((int[]){point.x ,point.y + c ,point.x
                            +ratio_x-2 ,point.y + c} , img, (int[]){0xFFFFFFF});
                    c++;
                }
            }
            point.x+=ratio_x;
            j++;
        }
        point.x=0;
        point.y+=ratio_y;
        i++;
    }
}

void    call(t_data *canva)
{
    int     status;
    int     ratio_x;
    int     ratio_y;
    canva->img = mlx_new_image(canva->mlx_ptr, canva->width, canva->height);
    canva->addr = mlx_get_data_addr(canva->img, &canva->bpp,
            &canva->line_bytes, &canva->endian);
    canva->win_ptr = mlx_new_window(canva->mlx_ptr, canva->width, canva->height,
                "cub3d");
    
    ratio_x = canva->width/64;
    ratio_y = canva->height/64;
    canva->player.x = ratio_x *2  + ratio_x/2;
    canva->player.y = ratio_y * 6 + ratio_y/2;

    // wall(canva);
    // tile(canva);
    // ray(canva);
    // player(canva);
    // drawline((int[]){canva->player.x ,canva->player.y+6 ,canva->player.x -canva->player.dx*2,canva->player.y - canva->player.dy *2},canva,(int[]){0x735674});
    // drawline((int[]){canva->player.x ,canva->player.y+5 ,canva->player.x -canva->player.dx*2,canva->player.y -1 - canva->player.dy *2},canva,(int[]){0x735674});
    // drawline((int[]){canva->player.x ,canva->player.y+4 ,canva->player.x -canva->player.dx*2,canva->player.y - canva->player.dy *2},canva,(int[]){0x735674});
    // printf("hi");
    run(canva);
    // render(canva);
}

int main(int argv, char *argc[])
{

    t_data  canva;
    canva.height = 640;
    canva.width = 960;
    canva.player.da = 60.0f *PI/180.0F;
    canva.player.dx = cos(canva.player.da)*5;
    canva.player.dy = sin(canva.player.da)*5;
    canva.mlx_ptr = mlx_init();
    call( &canva);
    return (0);
}

