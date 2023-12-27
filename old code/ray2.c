#include "cube3d.h"

void ray(t_data *img)
{
    int scale = img->scale;

    float px, py;
    px = img->player.x + scale/4;//-  img->player.dx*2;
    py = img->player.y + scale/4;//- img->player.dy*2;
    int mx,my,mp,dof,side; float rx,ry,ra,xo,yo,disV,disH;
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
        float tan1 = -1/tan(ra);
        //horizontal detection
        if (ra > PI)
        {
            //left  angles
            ry = (((int)py/scale)*scale)-0.0001;
            rx=(py-ry)*tan1+px;
            yo = -scale;
            xo=-yo*tan1;
        }
        if(ra < PI)
        {
            // right side angles
            ry = (((int)py/scale)*scale)+scale;
            rx=(py-ry)*tan1+px;
            yo= scale;
            xo=-yo*tan1;
        }
        if(ra==0 || ra==PI)
        {
            //when angle is 180
            rx=px; ry=py; dof=img->final_c;
        }
    printf("ray1 :: %d------------------------------------->\n",dof);

        while(dof<img->final_c)
        {
            printf("ray1 :: %d------------------------------------->\n",dof);

            mx=(int)(rx)/scale; my=(int)(ry)/scale; mp=my*(img->final_c)+mx;
            printf("mx:%d\nmy:%d\nmp:%dmap:%d sacle %d\n",mx,my,img->longest_row,img->final_c,scale);
            // printf("mx:%d\nmy:%d\nmp:%dmap:%d %d\n",mx,my,mp,scale,img->map[my][mx]);
            if(mp>0 && mp<((img->longest_row)*(img->final_c)) &&(mx < img->longest_row && mx >0 && my < img->final_c && my >0
            && img->map[my][mx] == 1))
				dof = img->final_c; //hit
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
            rx = (((int)px/scale)*scale)-0.0001;
            ry=(px-rx)*tan2+py;
            xo = -scale;
            yo=-xo*tan2;
        }
       else  if(ra<PI/2 || ra >3*PI/2)
        {
            //right side
            rx = (((int)px/scale)*scale)+scale;
            ry=(px-rx)*tan2+py;
            xo= scale;
            yo=-xo*tan2;
        }
        else if(ra==0 || ra==PI)
        {
		rx=px; ry=py; dof=0;
        }
        while(dof<img->longest_row)
        {
        printf("hoo dof %f: %f:\n",rx,ry);

            mx=(int)(rx)/scale; my=(int)(ry)/scale; mp=my*(img->longest_row-1)+mx;
            if(mp>0 && mp<((img->longest_row)*(img->final_c)) &&(mx < img->longest_row && mx >0 && my < img->final_c && my >0
            && img->map[my][mx]==1)){ dof=img->longest_row; }//hit
            else
			{
				rx+=xo; ry+=yo; dof+=1;
			}//check next horizontal
        }
        float finald;
	float d2 = sqrt(pow(rx - px, 2) + pow(ry - py, 2));
	int color;
	if(d1 > d2)
    {
    	drawline((int []){px,py,rx,ry},img,(int[]){0xFF0000});
        finald = d2;
        color = create_trgb(0,255,0,0);

    }
    else
    {
		drawline((int []){px,py,x1,y1},img,(int[]){0xFF0000});
        finald = d1;
        color = create_trgb(0,0,0,0);
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
