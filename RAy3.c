#include "cube3d.h"
void drawline(int *vals, t_data *img, int *color_list);
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void ray(t_data *img)
{
    int scale = img->scale;
    float px, py;
    px = img->player.x + scale/4;//-  img->player.dx*2;
    py = img->player.y + scale/4;//- img->player.dy*2;
	float xs, ys;
    int r,mx,my,mp,dof,side; float vx,vy,rx,ry,ra,xo,yo,disV,disH;
    // ra = img->player.da-DR*30;
    ra = img->player.da *PI;

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
    for (size_t i = 0; i < 120; i++)
    {
        dof =0;
        float tan1 = 1/tan(ra);
        //horizontal detection
        if (ra > PI)
        {
            //left  angles
            ry = py- (((int)py/scale)*scale)-0.0001;
            rx=ry/tan1;
            yo = -scale;
            xo=yo*tan1;
        }
        if(ra < PI)
        {
            // right side angles
            ry = py- (((int)py/scale)*scale)-0.0001;
            rx=ry/tan1;
            yo= scale;
            xo=yo*tan1;
        }
        if(ra==0 || ra==PI)
        {
            //when angle is 180
            rx=px; ry=py; dof=img->final_c;
        }
    printf("ray1 :: %d------------------------------------->\n",dof);

	float x1 = rx;
	float y1 = ry;
	float d1 = sqrt(pow(rx - px, 2) + pow(ry - py, 2));

        dof =0;
        printf("hoo\n");
        float tan2 = tan(ra);
        //vertical detection

        if (ra>PI/2 && ra <3*PI/2)
        {
            // left side
            rx = px - (((int)px/scale)*scale)+scale;
            ry=rx*tan2;
            xo = -scale;
            yo=xo*tan1;
        }
       else  if(ra<PI/2 || ra >3*PI/2)
        {
            //right side
            rx = px - (((int)px/scale)*scale)+scale;
            ry = rx*tan2;
            xo = scale;
            yo = xo*tan1;
        }
        else if(ra==0 || ra==PI)
        {
		rx=px; ry=py; dof=0;
        }
        
        float finald;
	float d2 = sqrt(pow(rx - px, 2) + pow(ry - py, 2));
	int color;
	if(d1 > d2)
    {
    	drawline((int []){px,py,rx,ry},img,(int[]){0xFF0000});
        finald = d2;
        color =create_trgb(0,255,0,0);
    }
    else
    {
		drawline((int []){px,py,x1,y1},img,(int[]){0xFF0000});
        finald = d1;
        color =create_trgb(0,20,0,0);
    }
        float ca  = img->player.da - ra;
        if (ca<0)
        {
            ca +=2*PI;
        }
        if (ca> 2*PI)
        {
            ca -=2*PI;
        }
        finald = finald* cos(ca);
	float lh = (scale *640)/finald;
    if(lh >640)
        lh=640;
	float lo = 640/2 -lh/2;
    	// drawline((int []){(i*8)+529,0,(i*8)+529,lh},img,(int[]){0xFF0000});
        int j=0;

        while (j < 8)
        {
    	    drawline((int []){((i*8) + j),lo,(i*8)+j,lh+lo},img,(int[]){color});
            j++;
        }
        
    	// drawline((int []){(i*8)+531,0,(i*8)+531,lh},img,(int[]){0xFF0000});
     ra += DR/2;
        
    if (ra<0)
    {
        ra +=2*PI;
    }
    if (ra> 2*PI)
    {
        ra -=2*PI;
    }
    }
}
