// #include  "cube3d.h"
// typedef struct point3d
// {
//     float x;
//     float y;
//     float z;
// }   coordinate_t;
// typedef struct  s_data {
//   void  *img;
//   char  *addr;
//   int   bits_per_pixel;
//   int   line_length;
//   int   endian;
// }       t_data;
// void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//   char  *dst;
//   dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//   *(unsigned int*)dst = color;
// }
// void drawline(float x, float y, float x1, float y1,t_data img, void *mlx_win)
// {
//     float m = (y1-y)/(x1-x);
//     float x2 = x ;
//     float y2 = y;
//     while (x2<x1)
//     {
//         my_mlx_pixel_put(&img,800.0/2.0 + x2, 800.0/2.0+ y2,0x00FFFFF);
//         x2 = (x2 + 0.0001);
//         y2 = m*(x2-x)+y;
//     }
// }
// void drawtriangle(t_data img, void * mlx_win, coordinate_t cor[3],int color)
// {
//   drawline(cor[0].x,cor[0].y,cor[1].x,cor[1].y,img,mlx_win);
//   drawline(cor[0].x,cor[0].y,cor[2].x,cor[2].y,img,mlx_win);
//   drawline(cor[2].x,cor[2].y,cor[1].x,cor[1].y,img,mlx_win);
// }
// void  mtrxmulti(t_data img, void * mlx_win,coordinate_t m[2][3],float matx[4][4],coordinate_t prints[2][3])
// {
//   int i;
//   int j;
//   float w[2][3];
//   i = 0;
//     while (i<2)
//     {
//       j=0;
//       while (j<3)
//       {
//         prints[i][j].x= m[i][j].x *matx[0][0] +  m[i][j].x *matx[1][0]  +  m[i][j].x *matx[2][0] + matx[3][0];
//         prints[i][j].y= m[i][j].y *matx[0][1] +  m[i][j].y *matx[1][1]  +  m[i][j].y *matx[2][1] + matx[3][1];
//         prints[i][j].z= m[i][j].y *matx[0][2] +  m[i][j].z *matx[1][2]  +  m[i][j].z *matx[2][2] + matx[3][2];

//         w[i][j] = m[i][j].x *matx[0][3] +  m[i][j].x *matx[1][3]  +  m[i][j].x *matx[2][3] + matx[3][3];
//         if(w[i][j] != 0.0f)
//         {
//           prints[i][j].x/=w[i][j];
//           prints[i][j].y/=w[i][j];
//           prints[i][j].z/=w[i][j];
//         }
//         prints[i][j].x += 1.0f;
//         prints[i][j].y += 1.0f;

//         prints[i][j].x *= 0.5f* 800.0f;
//         prints[i][j].y *=  0.5f* 800.0f;
//        printf("x: %f y: %f\n\n",   prints[i][j].x,  prints[i][j].y);
//        printf("m: %f m: %f m: %f m: %f \n", matx[0][0],matx[0][1],matx[0][2],matx[0][3]);
//        printf("m: %f m: %f m: %f m: %f \n", matx[1][0],matx[1][1],matx[1][2],matx[1][3]);
//        printf("m: %f m: %f m: %f m: %f \n", matx[2][0],matx[2][1],matx[2][2],matx[2][3]);
//        printf("m: %f m: %f m: %f m: %f \n", matx[3][0],matx[3][1],matx[3][2],matx[3][3]);

//         j++;
//       }
//       printf("\n");
//         // drawtriangle(img,mlx_win,prints[i],0x00FFFFF);
//     drawline(prints[i][0].x -400,prints[i][0].y -400,prints[i][1].x -400,prints[i][1].y-400 ,img,mlx_win);

//       i++;

//     }
    
// }

// int main()
// {
//     float matx[4][4]={0};
//     float matx1[4][4]={0};
//     float Q = 90.0f;
//     float height=800.0;
//     float width= 800.0;
//     float aspectr=(float)width/(float)height;
//     float f= 1.0f;
//     float Znear= 0.1f;
//     float Zfar= 800.0f;
//     float Znorm = Zfar/(Zfar-Znear) - Zfar*Znear/(Zfar-Znear);
//     coordinate_t sides[6][2][3];
//     coordinate_t prints[2][3];
//     coordinate_t tri[3];
//     coordinate_t east[2][3];
//     coordinate_t west[2][3];
//     coordinate_t north[2][3];
//     coordinate_t top[2][3];
//     coordinate_t bot[2][3];
//     sides[0][0][0].x=0.0f;
//     sides[0][0][0].y=0.0f;
//     sides[0][0][0].z=0.0f;
//     sides[0][0][1].x=0.0f;
//     sides[0][0][1].y=1.0f;
//     sides[0][0][1].z=0.0f;
//     sides[0][0][2].x=1.0f;
//     sides[0][0][2].y=1.0f;
//     sides[0][0][2].z=0.0f;
//     tri[0].x=0.0f;
//     tri[0].y=200.0f;
//     tri[0].z=0.0f;
//     tri[1].x=90.0f;
//     tri[1].y=100.0f;
//     tri[1].z=0.0f;
//     tri[2].x=40.0f;
//     tri[2].y=100.0f;
//     tri[2].z=0.0f;
//     sides[0][1][0].x=0.0f;
//     sides[0][1][0].y=0.0f;
//     sides[0][1][0].z=0.0f;
//     sides[0][1][1].x=1.0f;
//     sides[0][1][1].y=1.0f;
//     sides[0][1][1].z=0.0f;
//     sides[0][1][2].x=1.0f;
//     sides[0][1][2].y=0.0f;
//     sides[0][1][2].z=0.0f;
//     sides[1][0][0].x=1.0f;
//     sides[1][0][0].y=0.0f;
//     sides[1][0][0].z=0.0f;
//     sides[1][0][1].x=1.0f;
//     sides[1][0][1].y=1.0f;
//     sides[1][0][1].z=0.0f;
//     sides[1][0][2].x=1.0f;
//     sides[1][0][2].y=1.0f;
//     sides[1][0][2].z=1.0f;
//     sides[1][1][0].x=1.0f;
//     sides[1][1][0].y=0.0f;
//     sides[1][1][0].z=0.0f;
//     sides[1][1][1].x=1.0f;
//     sides[1][1][1].y=1.0f;
//     sides[1][1][1].z=1.0f;
//     sides[1][1][2].x=1.0f;
//     sides[1][1][2].y=0.0f;
//     sides[1][1][2].z=1.0f;
//     sides[2][0][0].x=1.0f;
//     sides[2][0][0].y=0.0f;
//     sides[2][0][0].z=1.0f;
//     sides[2][0][1].x=1.0f;
//     sides[2][0][1].y=1.0f;
//     sides[2][0][1].z=1.0f;
//     sides[2][0][2].x=0.0f;
//     sides[2][0][2].y=1.0f;
//     sides[2][0][2].z=1.0f;
//     sides[2][1][0].x=1.0f;
//     sides[2][1][0].y=0.0f;
//     sides[2][1][0].z=1.0f;
//     sides[2][1][1].x=0.0f;
//     sides[2][1][1].y=1.0f;
//     sides[2][1][1].z=1.0f;
//     sides[2][1][2].x=0.0f;
//     sides[2][1][2].y=0.0f;
//     sides[2][1][2].z=1.0f;
//     sides[3][0][0].x=0.0f;
//     sides[3][0][0].y=0.0f;
//     sides[3][0][0].z=1.0f;
//     sides[3][0][1].x=0.0f;
//     sides[3][0][1].y=1.0f;
//     sides[3][0][1].z=1.0f;
//     sides[3][0][2].x=0.0f;
//     sides[3][0][2].y=1.0f;
//     sides[3][0][2].z=0.0f;
//     sides[3][1][0].x=0.0f;
//     sides[3][1][0].y=0.0f;
//     sides[3][1][0].z=1.0f;
//     sides[3][1][1].x=0.0f;
//     sides[3][1][1].y=1.0f;
//     sides[3][1][1].z=0.0f;
//     sides[3][1][2].x=0.0f;
//     sides[3][1][2].y=0.0f;
//     sides[3][1][2].z=0.0f;
//     sides[4][0][0].x=0.0f;
//     sides[4][0][0].y=1.0f;
//     sides[4][0][0].z=0.0f;
//     sides[4][0][1].x=0.0f;
//     sides[4][0][1].y=1.0f;
//     sides[4][0][1].z=1.0f;
//     sides[4][0][2].x=1.0f;
//     sides[4][0][2].y=1.0f;
//     sides[4][0][2].z=1.0f;
//     sides[4][1][0].x=0.0f;
//     sides[4][1][0].y=1.0f;
//     sides[4][1][0].z=0.0f;
//     sides[4][1][1].x=1.0f;
//     sides[4][1][1].y=1.0f;
//     sides[4][1][1].z=1.0f;
//     sides[4][1][2].x=1.0f;
//     sides[4][1][2].y=1.0f;
//     sides[4][1][2].z=0.0f;
//     sides[5][0][0].x=1.0f;
//     sides[5][0][0].y=0.0f;
//     sides[5][0][0].z=1.0f;
//     sides[5][0][1].x=0.0f;
//     sides[5][0][1].y=0.0f;
//     sides[5][0][1].z=1.0f;
//     sides[5][0][2].x=0.0f;
//     sides[5][0][2].y=0.0f;
//     sides[5][0][2].z=0.0f;
//     sides[5][1][0].x=1.0f;
//     sides[5][1][0].y=0.0f;
//     sides[5][1][0].z=1.0f;
//     sides[5][1][1].x=0.0f;
//     sides[5][1][1].y=0.0f;
//     sides[5][1][1].z=0.0f;
//     sides[5][1][2].x=1.0f;
//     sides[5][1][2].y=0.0f;
//     sides[5][1][2].z=0.0f;
//     matx[0][0] = aspectr *f;
//     matx[1][1] = f;
//     matx[2][2] = Zfar/(Zfar-Znear);
//     matx[3][2] = (-Zfar*Znear)/(Zfar-Znear);
//     matx[2][3] = 1.0f;
//     matx[3][3] = 0.0f;
//   void  *mlx;
//   void  *mlx_win;
//   t_data  img;
//   mlx = mlx_init();
//   mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
//   img.img = mlx_new_image(mlx, 800, 800);
//   img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//                 &img.endian);
//     // drawline(10,60,100,60,img,mlx_win);
//   // drawtriangle(img,mlx_win,tri,0x0ffff);
//   int k = 0;
//   while (k<6)
//   {
//     mtrxmulti(img, mlx_win, sides[k],matx,prints);
//     k++;
//   }
  
//   mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//   mlx_loop(mlx);
//   // mlx_clear_window(&mlx,mlx_win);
//   // mlx_put_image_to_window(mlx, mlx_win, img2.img, 0, 0);
//   // mlx_destroy_image(mlx, img.img);
// }
