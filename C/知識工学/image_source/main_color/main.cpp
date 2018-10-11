#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<qlabel.h>
#include<qpixmap.h>
#include<qimage.h>
#include<qapplication.h>
#include<qstring.h>

#include"Params.h"
#include"Proto.h"
/////////////////////////


/*********************************************************************
 main fanction
*********************************************************************/
int main( int argc, char *argv[] ){
    QApplication application( argc, argv );
    QLabel widget_in(NULL, "in");//window for input image    
    QLabel widget_out(NULL, "out");//window for output image
    QLabel widget_work(NULL, "work");//window for output image
    QLabel widget_key(NULL, "key");//window for output image
    QImage input_image, output_image, work_image, key_image;//images   
    QPixmap pixmap_in, pixmap_out, pixmap_work, pixmap_key;//pixmap for label
    long hist[256];//histgram array
    char source[20];
    char c;
    int mode=1, copynum;
    int thresh,thresh_max,thresh_min;
    int loop_x, loop_y;//for loop
    int command, n;//switch
    int r_min=0,r_max=255,g_min=0,g_max=255,b_min=0,b_max=255;//thresh
    
    //array for image
    unsigned char image_in[3][Y_SIZE][X_SIZE];
    unsigned char image_out[3][Y_SIZE][X_SIZE];
    unsigned char image_work[3][Y_SIZE][X_SIZE];
    unsigned char image_key[3][Y_SIZE][X_SIZE];
    int  y[Y_SIZE][X_SIZE];
    int  c1[Y_SIZE][X_SIZE];
    int  c2[Y_SIZE][X_SIZE];
    int  sat[Y_SIZE][X_SIZE];
    int  hue[Y_SIZE][X_SIZE];
    
    //fanction value
    float stdhue;
    float y_amp, sat_amp, hue_add;
    
    application.setMainWidget( &widget_in );//Set main application
    
    output_image = QImage(X_SIZE, Y_SIZE, 32);
    work_image = QImage(X_SIZE, Y_SIZE, 32);
    key_image = QImage(X_SIZE, Y_SIZE, 32);
    input_image = QImage(X_SIZE, Y_SIZE, 32);

    do{
 while (command) {
     printf("\n*** Color Image Processing Menu ***\n");
     printf(" 1:Read image file\n");
     printf(" 2:Write image file\n");
     printf(" 3:Clear image\n");
     printf(" 4:Generate colorbar\n");
     printf(" 5:Copy image\n");
     printf(" 6:Binary operation\n");
     printf(" 7:Filter (3x3)\n");
     printf(" 8:Geometrical transform\n");
     printf(" 9:Change color\n");
     printf("10:Synthesis\n");
     printf(" 0:End\n");
     printf("Process number ?  ");
     scanf("%d", &command);
     switch (command) {
     case 1:
  printf("  Filename (read) ?  ");
  scanf("%s", source);
  printf("  Which window (1:IN, 2:OUT, 3:WORK, 4:KEY) ?  ");
  scanf("%d", &n);
  switch (n) {
  case 1:
      if (input_image.load(QString::QString(source)) != -1) 
   qimage_to_array(&input_image, image_in);
      else
   printf("--File open error !\n");
      break;
  case 2:
      if (output_image.load(QString::QString(source)) != -1) 
   qimage_to_array(&output_image, image_out);
   else
       printf("--File open error !\n");
      break;
  case 3:
      if (work_image.load(QString::QString(source)) != -1) 
   qimage_to_array(&work_image, image_work);
      else
   printf("--File open error !\n");
      break;
  case 4:
      if (key_image.load(QString::QString(source)) != -1)
   qimage_to_array(&key_image, image_key);
      else
   printf("--File open error !\n");
      break;
  default:
      printf("--Not defined number !\n"); 
      break;
  }
  break;
     case 2:
  printf("  Which window (1:IN, 2:OUT, 3:WORK, 4:KEY) ?  ");
  scanf("%d", &n);
  printf("  Filename (write) ?  ");
  scanf("%s", destin);
  switch (n) {
  case 1:
      array_to_qimage(&input_image, image_in);
      if (input_image.save(QString::QString(destin), "BMP") == -1)
   printf("--File open error !\n");
      break;
  case 2:
      array_to_qimage(&output_image, image_out);
      if (output_image.save(QString::QString(destin), "BMP") == -1)
   printf("--File open error !\n");
      break;
  case 3:
      array_to_qimage(&work_image, image_work);
      if (work_image.save(QString::QString(destin), "BMP") == -1)
   printf("--File open error !\n");
      break;
  case 4:
      array_to_qimage(&key_image, image_key);
      if (key_image.save(QString::QString(destin), "BMP") == -1)
   printf("--File open error !\n");
      break;
  default:
      printf("--Not defined number !\n"); 
      break;
  }
  break;
     case 3:
  printf("  Which window (1:IN, 2:OUT, 3:WORK, 4:KEY) ?  ");
  scanf("%d", &n);
  switch (n) {
  case 1:
      image_clear_color(image_in);
      break;
  case 2:
      image_clear_color(image_out);
      break;
  case 3:
      image_clear_color(image_work);
      break;
  case 4:
      image_clear_color(image_key);
      break;
  default:
      printf("--Not defined number\n"); 
      break;
  }
  break;
     case 4:
  printf("  Which window (1:IN, 2:OUT, 3:WORK, 4:KEY) ?  ");
  scanf("%d", &n);
  switch (n) {
  case 1:
      colorbar(image_in[0], image_in[1],
        image_in[2], 255);      
      break;
  case 2:
      colorbar(image_out[0], image_out[1],
        image_out[2], 255);      
      break;
  case 3:
      colorbar(image_work[0], image_work[1],
        image_work[2], 255);      
      break;
  case 4:
      colorbar(image_key[0], image_key[1],
        image_key[2], 255);
      break;
  default:
      printf("--Not defined number !\n"); 
      break;
  }
  break;
     case 5:
  printf(" 1:IN   -> OUT\n");
  printf(" 2:IN   -> WORK\n");
  printf(" 3:IN   -> KEY\n");
  printf(" 4:OUT  -> IN\n");
  printf(" 5:OUT  -> WORK\n");
  printf(" 6:OUT  -> KEY\n");
  printf(" 7:WORK -> IN\n");
  printf(" 8:WORK -> OUT\n");
  printf(" 9:WORK -> KEY\n");
  printf("10:KEY  -> IN\n");
  printf("11:KEY  -> OUT\n");
  printf("12:KEY  -> WORK  ?  ");
  scanf("%d", &n);
  switch (n) {
  case 1:
      array_to_array(image_in, image_out);      
      break;
  case 2:
      array_to_array(image_in, image_work);
      break;
  case 3:
      array_to_array(image_in, image_key);
      break;
  case 4:
      array_to_array(image_out, image_in);      
      break;
  case 5:
      array_to_array(image_out, image_work);
      break;
  case 6:
      array_to_array(image_out, image_key);
      break;
  case 7:
      array_to_array(image_work, image_in);      
      break;
  case 8:
      array_to_array(image_work, image_out);      
      break;
  case 9:
      array_to_array(image_work, image_key);
      break;
  case 10:
      array_to_array(image_key, image_in);
      
      break;
  case 11:
      array_to_array(image_key, image_out);
      
      break;
  case 12:
      array_to_array(image_key, image_work);      
      break;
  default :
   printf("--Not defined number !\n"); 
  break;
     }
  break;
     case 6:
  printf(" 1:1D histgram\n");
  printf(" 2:2D histgram\n");
  printf(" 3:Thresolding  ?  ");
  scanf("%d", &n);
  switch (n) {
  case 1:
      histgram(image_in[0], hist);
      histimage(hist, image_out[0]);
      image_clear(image_out[1]);
      image_clear(image_out[2]);
      
      histgram(image_in[1], hist);
      histimage(hist, image_work[1]);
      image_clear(image_work[0]);
      image_clear(image_work[2]);
      
      histgram(image_in[2], hist);
      histimage(hist, image_key[2]);
      image_clear(image_key[0]);
      image_clear(image_key[1]);
      
      break;
  case 2:
      hist2_image(image_in[0], image_in[1], image_out[0]);
      array_to_array(image_out[0], image_out[1]);
      array_to_array(image_out[0], image_out[2]);
      
      hist2_image(image_in[1], image_in[2], image_work[0]);
      array_to_array(image_work[0], image_work[1]);
      array_to_array(image_work[0], image_work[2]);
      
      hist2_image(image_in[2], image_in[0], image_key[0]);
      array_to_array(image_key[0], image_key[1]);
      array_to_array(image_key[0], image_key[2]);
      
      break;
  case 3:
      printf("  R Threshold (min,max) ?  "); 
      scanf("%d %d", &tr1, &tr2);
      printf("  G Threshold (min,max) ?  "); 
      scanf("%d %d", &tg1, &tg2);
      printf("  B Threshold (min,max) ?  "); 
      scanf("%d %d", &tb1, &tb2);
      thresh_color(image_in[0], image_in[1], image_in[2],
     image_out[0], image_out[1], image_out[2],
     tr1, tr2, tg1, tg2, tb1, tb2);
      
      break;
  default:
      printf("--Not defined number !\n"); 
      break;
  }
  break;
     case 7:
  printf(" 1:Gradient\n");
  printf(" 2:Laplacian\n");
  printf(" 3:Prewitt\n");
  printf(" 4:Smooth\n");
  printf(" 5:Median         ?  ");
  scanf("%d", &n);
  if (n < 0) break;
  if (n == 1 || n == 2 || n == 3) {
      printf("  Amplitude ?  ");
      scanf("%f", &a);
  }
  if (n == 1) {
      for (i = 0; i < 3; i++)
   gradient(image_in[i], image_out[i], a);
  }
  if (n == 2) {
      for (i = 0; i < 3; i++)
   laplacian(image_in[i], image_out[i], a);
  }
  if (n == 3) {
      for (i = 0; i < 3; i++)
   template_matching(image_in[i], image_out[i], a);
  }
  if (n == 4) {
      for (i = 0; i < 3; i++)
   smooth(image_in[i], image_out[i]);
  }
  if (n == 5) {
      for (i = 0; i < 3; i++)
   median(image_in[i], image_out[i]);
  }
  
  break;
     case 8:
  printf(" 1:Resize (near)\n");
  printf(" 2:Resize (bilinear)\n");
  printf(" 3:Move\n");
  printf(" 4:Rotate\n");
  printf(" 5:Affine\n");
  printf(" 6:Perspective  ");
  scanf("%d",&n);
  switch (n) {
  case 1:
      printf("  ax, ay (float) ?  ");
      scanf("%f %f", &a, &b);
      for (i = 0; i < 3; i++)
   scale_near(image_in[i], image_out[i], a, b);
      
      break;
  case 2:
      printf("  ax, ay (float) ?  ");
      scanf("%f %f", &a, &b);
      for (i = 0; i < 3; i++)
   scale(image_in[i], image_out[i], a, b);
      
      break;
  case 3:
      printf("  dx, dy (float) ?  ");
      scanf("%f %f", &x0, &y0);
      for (i = 0; i < 3; i++)
   shift(image_in[i], image_out[i], x0, y0);
      
      break;
  case 4:
      printf("  deg (float) ?  ");
      scanf("%f", &deg);
      for (i = 0; i < 3; i++)
   rotation(image_in[i], image_out[i], deg);
      
      break;
  case 5:
      printf("  ax, ay (float) ?  ");
      scanf("%f %f", &a, &b);
      printf("  dx, dy (float) ?  ");
      scanf("%f %f", &x0, &y0);
      printf("  deg (float) ?  ");
      scanf("%f", &deg);
      for (i = 0; i < 3; i++)
   affine(image_in[i], image_out[i],
          deg, a, b, x0, y0);
      
      break;
  case 6:
      printf("  ax, ay (float) ?  ");
      scanf("%f %f", &a, &b);
      printf("  dx, dy, dz (float) ?  ");
      scanf("%f %f %f", &x0, &y0, &z0);
      printf("  degz, degx, degy (float) ?  ");
      scanf("%f %f %f", &zr, &xr, &yr);
      printf("  viewz (float) ?  ");
      scanf("%f", &v);
      printf("  screenz (float) ?  ");
      scanf("%f", &scr);
      for (i = 0; i < 3; i++)
   perspect(image_in[i], image_out[i], 
     a, b, x0, y0, z0, zr, xr, yr,v,scr);
      
      break;
  default:
      printf("--Not defined number !\n"); 
      break;
  }
  break;
     case 9:
  printf(" 1:Display y, hue, sat\n");
  printf(" 2:Change y, hue, sat  ?  ");
  scanf("%d", &n);
  switch (n) {
  case 1:
      printf("  Initial hue ?  ");
      scanf("%f", &hd);
      rgb_to_yc(image_in[0], image_in[1], image_in[2],
         y, c1, c2);
      c_to_sh(c1, c2, sat, hue);
      for (i = 0; i < Y_SIZE; i++) {
   for (j = 0; j < X_SIZE; j++) {
       if (y[i][j] < 0) y[i][j] = 0;
       if (y[i][j] > 255) y[i][j] = 255;
       image_out[0][i][j] = y[i][j];
   }
      }
      sat_image(sat, image_work[0]);
      hue_image(sat, hue, hd, image_key[0]);
      array_to_array(image_out[0], image_out[1]);
      array_to_array(image_out[0], image_out[2]);
      array_to_array(image_work[0], image_work[1]);
      array_to_array(image_work[0], image_work[2]);
      array_to_array(image_key[0], image_key[1]);
      array_to_array(image_key[0], image_key[2]);
      
      
      
      break;
  case 2:
      printf("  Amplitude of y ?  ");
      scanf("%f", &ym);
      printf("  Amplitude of sat ?  ");
      scanf("%f", &sm);
      printf("  Shift of hue ?  ");
      scanf("%f", &hd);
      rgb_to_yc(image_in[0], image_in[1], image_in[2],
         y, c1, c2);
      c_to_sh(c1, c2, sat, hue);
      tran_ysh(y, sat, hue, y, sat, hue, ym, sm, hd);
      sh_to_c(sat, hue, c1, c2);
      yc_to_rgb(y, c1, c2,
         image_out[0], image_out[1], image_out[2]);
      
      break;
  default:
      printf("--Not defined number !\n"); 
      break;
  }
  break;
     case 10:
  printf(" 1:Generate hardkey\n");
  printf(" 2:Generate softkey\n");
  printf(" 3:Synthesis by hardkey\n");
  printf(" 4:Synthesid by softkey  ?  ");
  scanf("%d",&n);
  switch (n) {
  case 1:
      printf("  Threshold ?  "); 
      scanf("%d", &tg1);
      hard_mask(image_in[0], image_in[1], image_in[2],
         image_key[0], tg1);
      array_to_array(image_key[0], image_key[1]);
      array_to_array(image_key[0], image_key[2]);
      
      break;
  case 2:
      printf("  Threshold (min,max) ?  "); 
      scanf("%d %d", &tg1, &tg2);
      soft_mask(image_in[0], image_in[1], image_in[2],
         image_key[0], tg2, tg1);
      array_to_array(image_key[0], image_key[1]);
      array_to_array(image_key[0], image_key[2]);
      break;
  case 3:
      synth(image_in[0], image_in[1], image_in[2],
     image_work[0], image_work[1], image_work[2],
     image_out[0], image_out[1], image_out[2],
     image_key[0]);      
      break;
  case 4:
      s_synth(image_in[0], image_in[1], image_in[2],
       image_work[0], image_work[1], image_work[2],
       image_out[0], image_out[1], image_out[2],
       image_key[0]);      
      break;
  default:
      printf("--Not defined number !\n"); 
      break;
  }
  break;
     case 0:
  printf("...Bye-bye ........\n"); 
  break;
     default:
  printf("--Not defined number !\n"); 
  break;
     }
 } 
    }while(mode);
    
    //???Image???    
    array_to_qimage(&input_image, image_in);
    array_to_qimage(&output_image, image_out);
    array_to_qimage(&work_image, image_work);
    array_to_qimage(&key_image, image_key);
    
    /////////////////////////////////////////////test//
    key_image.save("key.bmp","BMP");
    //test////////////////////////////////////////////
    
    widget_in.setFixedWidth(X_SIZE);//window?
    widget_in.setFixedHeight(Y_SIZE);
    widget_out.setFixedWidth(X_SIZE);
    widget_out.setFixedHeight(Y_SIZE);
    widget_work.setFixedWidth(X_SIZE);
    widget_work.setFixedHeight(Y_SIZE);
    widget_key.setFixedWidth(X_SIZE);
    widget_key.setFixedHeight(Y_SIZE);
    widget_in.setCaption("IN");
    widget_out.setCaption("OUT");
    widget_work.setCaption("WORK");
    widget_key.setCaption("KEY");
    pixmap_in.convertFromImage(input_image);//pixmap?Image???  
    pixmap_out.convertFromImage(output_image);
    pixmap_work.convertFromImage(work_image);
    pixmap_key.convertFromImage(key_image);
    widget_in.setPixmap(pixmap_in);//pixmap?indow?a??    
    widget_out.setPixmap(pixmap_out);
    widget_work.setPixmap(pixmap_work);
    widget_key.setPixmap(pixmap_key);
    widget_in.show();//windowÅ@
    widget_out.show();
    widget_work.show();
    widget_key.show();
    
    return application.exec();//???Qt??
}

//Original fanctions
void array_to_qimage(QImage *image, unsigned char array[3][Y_SIZE][X_SIZE]){
    int loop_x, loop_y;
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     image->setPixel(loop_x, loop_y, qRgb((int)array[R][loop_y][loop_x],
       (int)array[G][loop_y][loop_x],
       (int)array[B][loop_y][loop_x]));
 }
    }
}
void qimage_to_array(QImage *image, unsigned char array[3][Y_SIZE][X_SIZE]){
    int loop_x, loop_y;
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     array[R][loop_y][loop_x] = qRed(image->pixel(loop_x, loop_y));
     array[G][loop_y][loop_x] = qGreen(image->pixel(loop_x, loop_y));
     array[B][loop_y][loop_x] = qBlue(image->pixel(loop_x, loop_y));
 }
    }
}
void array_to_array(unsigned char in[3][Y_SIZE][X_SIZE], unsigned char out[3][Y_SIZE][X_SIZE]){
    int loop_x, loop_y;
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     out[R][loop_y][loop_x] = in[R][loop_y][loop_x];
     out[G][loop_y][loop_x] = in[G][loop_y][loop_x]; 
     out[B][loop_y][loop_x] = in[B][loop_y][loop_x];
 }
    }
}

void array_to_array(unsigned char in[Y_SIZE][X_SIZE], unsigned char out[Y_SIZE][X_SIZE]){
    int loop_x, loop_y;
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     out[loop_y][loop_x] = in[loop_y][loop_x];
     out[loop_y][loop_x] = in[loop_y][loop_x]; 
     out[loop_y][loop_x] = in[loop_y][loop_x];
 }
    }
}


void image_clear_color(unsigned char in[3][Y_SIZE][X_SIZE]){
    int loop_x, loop_y;
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     in[R][loop_y][loop_x] = 0;
     in[G][loop_y][loop_x] = 0;
     in[B][loop_y][loop_x] = 0;
 }
    }
}

void image_clear(unsigned char in[Y_SIZE][X_SIZE]){
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     in[loop_y][loop_x] = 0;
 }
    }
} 
