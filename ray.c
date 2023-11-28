#include "cube3d.h"
void drawline(int *vals, t_data *img, int *color_list);
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
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
    // px = img->player_center.x -  img->player.dx*5;
    px = img->player_center.x ;
    py = img->player_center.y ;
    // py = img->player_center.y - img->player.dy*5;
    int r,mx,my,mp,dof,side; float vx,vy,rx,ry,ra,xo,yo,disV,disH;
    ra = img->player.da + 140.0f *PI/180.0F - 0.001;
    // ra = img->player.da + PI ;
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
    int color;
	if(d1 > d2)
    {
        // rx = rx * img->width/(64*2) ;
        // ry = ry * img->height/(64*2);
    	// drawline((int []){px,py,rx,ry},img,(int[]){0xFF0000});
        finald = d2;
        color =create_trgb(0,255,0,0);
    }
    else
    {
        // x1 = x1 * img->width/(64*2) ;
        // y1 = y1 * img->height/(64*2);
		// drawline((int []){px,py,x1,y1},img,(int[]){0xFF0000});
        finald = d1;
        color =create_trgb(0,25,0,0);

    }
        float ca  = img->player.da - ra;
        if (ca<0)
            ca +=2*PI;
        if (ca> 2*PI)
            ca -=2*PI;

    finald = finald* cos(ca);
	float lh = (64 *640)/finald;
    if(lh >640)
        lh=640;
	float lo = 420 -lh/2;
    int j=0;
    while (j <8)
    {
        drawline((int []){((i*8) + j),lo,(i*8)+j,lh+lo},img,(int[]){color});
        j++;
    }
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