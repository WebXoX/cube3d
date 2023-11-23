/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:12:05 by jperinch          #+#    #+#             */
/*   Updated: 2023/11/23 14:14:23 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI 3.1415926535
#define DR 0.0174533
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

// void ray4(t_data *img)
// {
//     float fFOV = PI/4;
//         int map[8][8]=           //the map array. Edit to change level but keep the outer walls
//             {
//             {1,1,1,1,1,1,1,1},
//             {1,0,1,0,0,0,0,1},
//             {1,0,1,0,0,0,0,1},
//             {1,0,1,0,0,0,0,1},
//             {1,0,0,0,0,0,0,1},
//             {1,0,0,0,0,1,0,1},
//             {1,0,2,0,0,0,0,1},
//             {1,1,1,1,1,1,1,1}
//             };
//  float ra;
//  ra =  img->player.da-DR*180;
//   float fRayAngle = atan2(img->player.dy/64 - img->player.y * 64,img->player.dx/64 -img->player.x * 64);
// 	float angle[2];

//     while (1)
//     {
//         for (size_t i = 0; i < 64; i++)
//         {
//             float fRaya = (ra - fFOV/2.0)+((float)i/64.0)*fFOV;

//             float fDist = 0;
//             int t=0;
//             float fex = sinf(fRayAngle);
//             float fey= cosf(fRayAngle);
//             while (t==0 && fDist < 64)
//             {
//                 fDist +=0.1;
//                 int tx= (int)(img->player.x + fex *fDist);
//                 int ty= (int)(img->player.y + fey *fDist);
//                 if(tx < 0 || tx> )
//             }

//         }

//     }

// }
// void ray3(t_data *img)
// {
//     int map[8][8]=           //the map array. Edit to change level but keep the outer walls
//             {
//             {1,1,1,1,1,1,1,1},
//             {1,0,1,0,0,0,0,1},
//             {1,0,1,0,0,0,0,1},
//             {1,0,1,0,0,0,0,1},
//             {1,0,0,0,0,0,0,1},
//             {1,0,0,0,0,1,0,1},
//             {1,0,2,0,0,0,0,1},
//             {1,1,1,1,1,1,1,1}
//             };
//  float ra;
//  ra =  img->player.da-DR*180;
//   float fRayAngle = atan2(img->player.dy/64 - img->player.y * 64,img->player.dx/64 -img->player.x * 64);
// 	float angle[2];
// 	angle[0] =cos(fRayAngle);
// 	angle[1] =sin(fRayAngle);
//  float roots[2];
//  float start[2];
// int mapcor[2];
// int step[2];

// start[0] =  img->player.dx;
// start[0] =  img->player.dy;
// mapcor[0] = 3;
// // mapcor[1] = 6;

// //  roots[0] =sqrt(1+(img->player.dy/img->player.dx)*(img->player.dy/img->player.dx));
// //  roots[1] =sqrt(1+(img->player.dx/img->player.dy)*(img->player.dx/img->player.dy));

//  roots[0] =sqrt(1+(angle[1]/angle[0])*(angle[1]/angle[0]));
//  roots[1] =sqrt(1+(angle[0]/angle[1])*(angle[0]/angle[1]));
//  float len[2];

// 	if(img->player.dx < 0)
// 	{
// 		step[0]=-1;
// 		len[0]= img->player.x *64  -(mapcor[0]*64) * roots[0];
// 		// len[0]= (start[0]-img->player.x)* roots[0];
// 	}
// 	else
// 	{
// 		step[0]=1;
// 		// len[0]= img->player.x *64  -(mapcor[0]*64) * roots[0];
// 		len[0]=(((mapcor[0] + 1) * 64) - img->player.x * 64) * len[0];
// 		// len[0]= ((img->player.x + 1 )-start[0])* roots[0];
// 	}

// 	if(img->player.dy < 0)
// 	{
// 		step[1]=-1;
// 		len[1]= img->player.y *64  -(mapcor[1]*64) * roots[1];
// 		// len[1]= (start[1]-img->player.y)* roots[1];
// 	}
// 	else
// 	{
// 		step[1]=1;
// 		len[1]=(((mapcor[1] + 1) * 64) - img->player.y * 64) * len[1];

// 		// len[1]= img->player.y *64  -(mapcor[1]*64) * roots[1];
// 		// len[1]= ((img->player.y + 1 )-start[1])* roots[1];
// 	}

// 	int bTileFound = 0;
// 	float fMaxDistance = 300.0f;
// 		float fDistance = 0.0f;
// 		while (!bTileFound && fDistance < fMaxDistance)
// 		{
// 			// Walk along shortest path
// 			if (len[0] < len[1])
// 			{
// 				mapcor[0] += step[0];
// 				fDistance = len[0];
// 				len[0] += roots[0];
// 			}
// 			else
// 			{
// 				mapcor[1] += step[1];
// 				fDistance = len[1];
// 				len[1] += roots[1];
// 			}

// 			// Test tile at new test point
// 			if (	mapcor[0] >= 0 && 	mapcor[0] < 8 && 	mapcor[1] >= 0 && 	mapcor[1] < 8)
// 			{
// 				if (map[mapcor[0]][	mapcor[1]] == 1)
// 				{
// 					bTileFound = 1;
// 				}
// 			}
// 		}
// 		float rxy[2];
// 		if(bTileFound ==1)
// 		{
// 			rxy[0]=start[0] + img->player.x * fDistance;
// 			rxy[1]=start[1] + img->player.y * fDistance;
// 		}

// 				drawline((int []){img->player.x,img->player.y,rxy[0],rxy[1]},img,(int[]){0xFF001});

// }
// if(ra > PI)
// {
//     ry=(((int)img->player.y/64) * 64)-0.0001;
//     rx=  (img->player.y-ry)*aTan+img->player.x;
//     yo=-64;
//     xo=-yo*aTan;
// }
// if(ra < PI)
// {
//     ry=(((int)img->player.y/64)*64)+64;
//     rx=  (img->player.y-ry)*aTan+img->player.x;
//     yo=64;
//     xo=-yo*aTan;
// }
// if(ra > PI/2 && ra < 3*PI/2)
// {
//     rx=(((int)img->player.x >>6)<<6)-0.0001;
//     ry=  (img->player.x-rx)*nTan+img->player.y;
//     xo=-64;
//     yo=-xo*nTan;
// }
// if(ra < PI/2 || ra > 3*PI/2)
// {
//     rx=(((int)img->player.x >>6)<<6)+64;
//     ry=  (img->player.x-rx)*nTan+img->player.y;
//     xo=64;
//     yo=-xo*nTan;
// }
// if(ra==0||ra==PI)
// {
//     ry=img->player.y;
//     rx= img->player.x;
//     dof=8;
// }

// void ray(t_data *img)
// {
//     int map[]=           //the map array. Edit to change level but keep the outer walls
//     {
//     1,1,1,1,1,1,1,1,
//     1,0,1,0,0,0,0,1,
//     1,0,1,0,0,0,0,1,
//     1,0,1,0,0,0,0,1,
//     1,0,0,0,0,0,0,1,
//     1,0,0,0,0,1,0,1,
//     1,0,0,0,0,0,0,1,
//     1,1,1,1,1,1,1,1,
//     };
//     int r,cx,cy,mx,my,mp,dof,i,j;
//     float rx,ry,ra,xo,yo, dista;
//     ra = img->player.da-DR*180;
//     if (ra<0)
//     {
//         ra +=2*PI;
//         /* code */
//     }
//     if (ra> 2*PI)
//     {
//         ra -=2*PI;
//         /* code */
//     }
// 	int index = 0 ;
//     for (i= 0; i < 8; i++)
//     {
//         for (j = 0; j< 8; j++)
//         {
//             int v1[2] ,v2[2] ,v3[2] ,v4[2];

//             v1[0] = i * 64;
//             v1[1] = j * 64;
//             v2[0] = (i * 64)+64;
//             v2[1] = (j * 64);
//             v3[0] = (i * 64);
//             v3[1] = (j * 64)+64;
//             v4[0] = (i * 64)+64;
//             v4[1] = (j * 64)+64;
//             float aTan = -1/tan(ra);

//             printf("v1: %d %d ,v2: %d %d , v3: %d %d , v4: %d %d\n",v1[0],v1[1],v2[0],v2[1],v3[0],v3[1],v4[0],v4[1]);
//             if(img->player.x >= v1[0] && img->player.x<= v4[0] && img->player.y >= v1[1] && img->player.y<= v4[1])
//             {
// 				//looking up
// 				 if(ra > PI)
// 				{
// 					ry=	v1[1];
// 					rx=  (img->player.y-ry)*aTan+img->player.x;
// 					yo=-64;
// 					xo=-yo*aTan;
// 				}
// 				if(ra < PI) //looking down
// 				{
// 					ry=v1[1];
// 					rx=  (img->player.y-ry)*aTan+img->player.x;
// 					yo=64;
// 					xo=-yo*aTan;
// 				}
// 				if(ra==0||ra==PI)
// 				{
// 					ry=img->player.y;
// 					rx= img->player.x;
// 				}
// 				 int dof=0;
// 				while (dof <8)
// 				{

// 				 	mx=(int)(rx)/64;
// 					my=(int)(ry)/64;
//                         printf(" %f  %f\n",rx,ry);
//                         printf("mx %d  %d\n",mx,my);
// 					mp=(my-1)*8+mx;
//                         printf("map %d\n",map[0]);
// 					// printf("angle will make it map bounce %d\n\n",mp);
// 					if(mp>0 && mp<64 &&map[mp]==1)
// 					{
//                         printf("hi");
// 						dof=8;
//                         break;
// 					}
// 					else
// 					{
// 						rx+=xo;
// 						ry+=yo;
// 						dof+=1;
// 					}
// 				}
// 				drawline((int []){img->player.x,img->player.y,rx,ry},img,(int[]){0xFF001});
// //      float disv=1000000;
//                 // printf(" player x %f player y %f\n",img->player.x,img->player.y);
//                 // rx = img->player.x - dist();
//                 // ry =
//                 // drawline((int []){img->player.x,img->player.y,v1[0]-64,v1[1]},img,(int[]){0xFF001});
//                 // drawline((int []){img->player.x,img->player.y,v2[0],v2[1]},img,(int[]){0xFF001});

//                 // exit(9);
//             }
//             // if(i * 64)
//         }
//     }
// }
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
    px = img->player.x;
    py = img->player.y;
    int r,mx,my,mp,dof,side; float vx,vy,rx,ry,ra,xo,yo,disV,disH;
    ra = img->player.da-DR*180;
    // ra = img->player.da;

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
    for (size_t i = 0; i < 90; i++)
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
	float d2 = sqrt(pow(rx - px, 2) + pow(ry - py, 2));
	if(d1 > d2)
    	drawline((int []){px,py,rx,ry},img,(int[]){0xFF0000});
    else
		drawline((int []){px,py,x1,y1},img,(int[]){0xFF0000});
     ra +=DR;
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
    mlx_key_hook(canva->win_ptr, moves, &(*canva));
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

int cast(t_data *canva)
{
    float x1 = 0;
    float x2 = 0;
    float dir_x = -10;
    float dir_y = 0;
    float y1 = canva->height;
    float y2 = canva->width;

    float x3 = canva->player.x;
    float y3 = canva->player.y;
    float x4 = canva->player.x + dir_x;
    float y4 = canva->player.y + dir_y;

    printf("HEREEEEEE %f %f %f %f \n", x3, x4, y3, y4);
    // drawline((int[]){0,0,400,800},canva,(int[]){0x880808});
    // drawline((int[]){x3,y3,x4,y4},canva,(int[]){0x880808});
    float den = (((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
    if (den == 0)
        return 0;
    float t = (((x1-x3) * (y3-y4)) - ((y1 - y3) * (x3 - x4)))/(((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
    float u = (((x1-x3) * (y1-y2)) - ((y1 - y3) * (x1 - x2)))/(((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
    if(t >= 0 && t <= 1 && u >= 0 && u >= 0)
        return 1;
    else
        return 0;
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
    // int ratio_y = img->height/4;
    // int ratio_x = img->width/6;
    coordinate_t point;
    point.x=0;
    point.y=0;
    //wall and tile re draw
    wall(img);
    tile(img);
    img->player.y -= y;
    img->player.x -= x;
    i=0;
    //player re draw
    // while (j <10)
    // {
        printf("in motion player y: %f\n", img->player.y);
        printf("in motion player x: %f\n\n", img->player.x);
    //  drawline((int[]){img->player.x ,img->player.y + j ,img->player.x+ 10 ,img->player.y + j} ,img,(int[]){0xFFFFFFF});
    //  j++;
    // }
    player(img);
    drawline((int[]){img->player.x,img->player.y+6,img->player.x -img->player.dx*2,img->player.y-img->player.dy *2},img,(int[]){0xFFFFFFF});
    drawline((int[]){img->player.x,img->player.y+5,img->player.x -img->player.dx*2,img->player.y-img->player.dy *2},img,(int[]){0xFFFFFFF});
    drawline((int[]){img->player.x,img->player.y+4,img->player.x -img->player.dx*2,img->player.y-img->player.dy *2},img,(int[]){0xFFFFFFF});

    //ray is called in this function
    // render(img);
    //runs loop
    ray(img);

    run(img);
    return (0);
}

void player(t_data *img)
{
    int i;
    int j;
    int c;
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
    j=0;
        while (i < 8)
        {
            j=0;
            while (j < 8)
            {
                if(map[i][j]==2)
                {
                    c=0;
                    // img->player.x = point.x  + 64/2;
                    // img->player.y = point.y  + 64/2;

                    while (c < 10)
                    {
                        // printf("in player x:%d\n\n",c);
                        drawline((int[]){img->player.x ,img->player.y + c ,img->player.x+ 10 ,img->player.y + c} ,img,(int[]){0x735674});

                        c++;
                    }
                }
                point.x+=64;
                j++;
            }
            point.x=0;
            point.y+=64;
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
    while (i < 8)
    {
        j=0;
        while (j < 8)
        {
            int c;
            if(map[i][j]==0 || map[i][j]== 2)
            {
                c = 0;
                while (c < 64 - 2)
                {
                    // printf("from tile : %d\n",c);
                    drawline((int[]){point.x ,point.y + c ,point.x
                            + 64-2 ,point.y + c} , img, (int[]){0x000});
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
            point.x+=64;
            j++;
        }
        point.x=0;
        point.y+=64;
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
                while (c < 64 - 2)
                {
                    printf("from wall: %d\n",c);
                    drawline((int[]){point.x ,point.y + c ,point.x
                            + 64-2 ,point.y + c} , img, (int[]){0xFFFFFFF});
                    c++;
                }
            }
            point.x+=64;
            j++;
        }
        point.x=0;
        point.y+=64;
        i++;
    }
}

void    call(t_data *canva)
{
    int     status;

    canva->img = mlx_new_image(canva->mlx_ptr, canva->width, canva->height);
    canva->addr = mlx_get_data_addr(canva->img, &canva->bpp,
            &canva->line_bytes, &canva->endian);
    canva->win_ptr = mlx_new_window(canva->mlx_ptr, canva->width, canva->height,
                "cub3d");
    canva->player.x = 64 *2  + 64/2;
    canva->player.y = 64 * 6 + 64/2;

    wall(canva);
    tile(canva);
    player(canva);
    drawline((int[]){canva->player.x ,canva->player.y+6 ,canva->player.x -canva->player.dx*2,canva->player.y - canva->player.dy *2},canva,(int[]){0xFFFFFFF});
    drawline((int[]){canva->player.x ,canva->player.y+5 ,canva->player.x -canva->player.dx*2,canva->player.y - canva->player.dy *2},canva,(int[]){0xFFFFFFF});
    drawline((int[]){canva->player.x ,canva->player.y+4 ,canva->player.x -canva->player.dx*2,canva->player.y - canva->player.dy *2},canva,(int[]){0xFFFFFFF});
    ray(canva);
    printf("hi");
    run(canva);
    // render(canva);
}

int main(int argv, char *argc[])
{

    t_data  canva;
    canva.height = 512;
    canva.width = 1024;
    canva.player.da = DR;
    canva.player.dx = cos(canva.player.da)*5;
    canva.player.dy = sin(canva.player.da)*5;
    canva.mlx_ptr = mlx_init();
    call( &canva);
    return (0);
}

