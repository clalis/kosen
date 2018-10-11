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
    long hist[256], histbuf[256];;//histgram array
    char source[20],destin[20];
    int command, mode, n, m;//switch
    
    //Array for image
    unsigned char image_in[Y_SIZE][X_SIZE];
    unsigned char image_out[Y_SIZE][X_SIZE];
    unsigned char image_work[Y_SIZE][X_SIZE];
    unsigned char image_key[Y_SIZE][X_SIZE];
    
    //fanction value
    int thres;
    char prnbuf[10000];
    int cnt;
    float ratio[128], size[128];
    float ratio_min, ratio_max;
    float size_min, size_max;
    float amp;
    int fmax, fmin;
    float a, b, x0, y0, z0, deg, xr, yr, zr, v, scr;
    
    application.setMainWidget( &widget_in );//Set main application
    
    //initialization
    input_image = QImage(X_SIZE, Y_SIZE, 32);
    output_image = QImage(X_SIZE, Y_SIZE, 32);
    work_image = QImage(X_SIZE, Y_SIZE, 32);
    key_image = QImage(X_SIZE, Y_SIZE, 32);
    
    // Start ==============================================
    do{ 
 printf("\n*** Image Processing Menu  ***\n"); 
 printf(" 1: Read image file\n"); 
 printf(" 2: Write image file\n"); 
 printf(" 3: Clear image\n"); 
 printf(" 4: Copy image\n"); 
 printf(" 5: Binary operation\n"); 
 printf(" 6: Filter (3x3)\n"); 
 printf(" 7: Gray scale transform\n"); 
 printf(" 8: Geometrical transform\n"); 
 printf(" 9: FFT & Filter\n"); 
 printf("10: Mask by key image\n"); 
 printf(" 0: End\n"); 
 printf("Process Number ?  "); 
 scanf("%d", &command); 
 switch (command) { 
 case 1: 
     printf("  Filename (read) ?  "); 
     scanf("%s", source);
     printf("  Which window (1:IN, 2:OUT, 3:WORK, 4:KEY) ?  "); 
     scanf("%d", &n); 
     switch (n) { 
     case 1: 
  if (input_image.load(QString::QString(source)) != -1){
      qimage_to_array(&input_image, image_in);
  }else 
      printf("--File open error !\n"); 
  break; 
     case 2: 
  if (output_image.load(QString::QString(source)) != -1){
      qimage_to_array(&output_image, image_out);
  }else 
      printf("--File open error !\n"); 
  break; 
     case 3: 
  if (work_image.load(QString::QString(source)) != -1){
      qimage_to_array(&work_image, image_work);
  }else 
      printf("--File open error !\n"); 
  break; 
     case 4: 
  if (key_image.load(QString::QString(source)) != -1){
      qimage_to_array(&key_image, image_key);
  }else 
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
  if (input_image.save(QString::QString(destin), "BMP") == -1) 
      printf("--File open error !\n"); 
  break; 
     case 2: 
  if (output_image.save(QString::QString(destin), "BMP") == -1) 
      printf("--File open error !\n"); 
  break; 
     case 3: 
  if (work_image.save(QString::QString(destin), "BMP") == -1) 
      printf("--File open error !\n"); 
  break; 
     case 4: 
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
  image_clear(image_in);
  break; 
     case 2: 
  image_clear(image_out);   
  break; 
     case 3: 
  image_clear(image_work);  
  break; 
     case 4: 
  image_clear(image_key);   
  break; 
     default: 
  printf("--Not defined number !\n");  
  break; 
     } 
     break; 
 case 4: 
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
     default: 
  printf("--Not defined number !\n"); 
  break; 
     } 
     break; 
 case 5: 
     printf(" 1:Histgram \n"); 
     printf(" 2:Thresholding\n"); 
     printf(" 3:Erosion\n"); 
     printf(" 4:Dialtion\n"); 
     printf(" 5:Thinning\n"); 
     printf(" 6:Features   ?  "); 
     scanf("%d", &n); 
     switch (n) { 
     case 1: 
  printf(" Mode (1:Graph, 2:Smooth graph, 3:Text 4:Text file) ? "); 
  scanf("%d", &command);
  switch (command) { 
  case 1: 
      histgram(image_in, hist); 
      histimage(hist, image_work);
      
      break; 
  case 2: 
      histsmooth(hist, histbuf); 
      for (n = 0; n < 256; n++) hist[n] = histbuf[n]; 
      histimage(hist, image_work); 
      
      break; 
  case 3: 
      histgram(image_in, hist); 
      histprint(hist, prnbuf); 
      printf("%s", prnbuf); 
      break;
  case 4: 
      histgram(image_in, hist); 
      outputHistgram(hist); 
      break; 
  default: 
      printf("--Not defined number !\n"); 
      break; 
  } 
  break; 
     case 2: 
  printf("  Threshold ?  "); 
  scanf("%d", &thres); 
  printf("  Mode (1:Normal, 2:Inverse) ?  ");  
  scanf("%d", &mode); 
  threshold(image_in, image_out, thres, mode); 
  
  break; 
     case 3: 
  erosion(image_in, image_out); 
  
  break; 
     case 4: 
  dilation(image_in, image_out); 
  
  break; 
     case 5: 
  thinning(image_in, image_out); 
  
  break; 
     case 6: 
  labeling(image_in, image_out, &cnt, prnbuf); 
  printf("%s", prnbuf); 
  features(image_out, image_work, cnt, size, ratio, 
    prnbuf); 
  printf("%s", prnbuf); 
  
  array_to_array(image_out, image_in); 
  do { 
      printf("  Extract by (1:shape, 2:size, 0:End) ? "); 
      scanf("%d", &n); 
      if (n == 1) { 
   printf("  min max (float) ?  "); 
   scanf("%f %f", &ratio_min, &ratio_max); 
   ratio_extract(image_in, image_out, cnt, ratio, 
          ratio_min, ratio_max); 
      } 
      if (n == 2) { 
   printf("  min max (float) ?  "); 
   scanf("%f %f", &size_min, &size_max); 
   size_extract(image_in, image_out, cnt, size, 
         size_min, size_max); 
      } 
      threshold(image_out, image_out, 1, 1); 
      
  } while (n != 0); 
  break; 
     default: 
  printf("--Not defined number !\n"); 
  break; 
     } 
     break; 
 case 6: 
     printf(" 1:Gradient\n"); 
     printf(" 2:Laplacian\n"); 
     printf(" 3:Prewitt\n"); 
     printf(" 4:Smooth\n"); 
     printf(" 5:Median         ?  "); 
     scanf("%d", &n); 
     switch (n) { 
     case 1: 
  printf("  Amplitude (float) ?  "); 
  scanf("%f", &amp); 
  gradient(image_in, image_out, amp); 
  
  break; 
     case 2: 
  printf("  Amplitude (float) ?  "); 
  scanf("%f", &amp); 
  laplacian(image_in, image_out, amp); 
  
  break; 
     case 3: 
  printf("  Amplitude (float) ?  "); 
  scanf("%f", &amp); 
  template_matching(image_in, image_out, amp);  
  break; 
     case 4: 
  smooth(image_in, image_out);   
  break; 
     case 5: 
  median(image_in, image_out);   
  break; 
     default: 
  printf("--Not defined number\n"); 
  break; 
     } 
     break; 
 case 7: 
     printf(" 1:Amplify\n"); 
     printf(" 2:Expand\n"); 
     printf(" 3:Plane   ?  "); 
     scanf("%d", &n); 
     switch (n) { 
     case 1: 
  printf("  Amplitude (float) ?  "); 
  scanf("%f", &amp); 
  amplify(image_in, image_out, amp);
  
  break; 
     case 2: 
  range(image_in, &fmax, &fmin); 
  expand(image_in, image_out, fmax,fmin); 
  
  break; 
     case 3: 
  histgram(image_in, hist); 
  plane(image_in, image_out, image_work, hist); 
  
  break; 
     default: 
  printf("--Not defined number !\n"); 
  break; 
     } 
     break; 
 case 8: 
     printf(" 1:Resize (near)\n"); 
     printf(" 2:Resize (bilinear)\n"); 
     printf(" 3:Resize (bad method)\n"); 
     printf(" 4:Move\n"); 
     printf(" 5:Rotate\n"); 
     printf(" 6:Affine\n"); 
     printf(" 7:Perspective  ?  "); 
     scanf("%d",&n); 
     switch (n) { 
     case 1: 
  printf("  ax, ay (float) ?  "); 
  scanf("%f %f", &a, &b); 
  scale_near(image_in, image_out, a, b); 
  
  break; 
     case 2: 
  printf("  ax, ay (float) ?  "); 
  scanf("%f %f", &a, &b); 
  scale(image_in, image_out, a, b); 
  
  break; 
     case 3: 
  printf("  ax, ay (float) ?  "); 
  scanf("%f %f", &a, &b); 
  scale_ng(image_in, image_out, a, b); 
  
  break; 
     case 4: 
  printf("  dx, dy (float) ?  "); 
  scanf("%f %f", &x0, &y0); 
  shift(image_in, image_out, x0, y0); 
  
  break; 
     case 5: 
  printf("  deg (float) ?  "); 
  scanf("%f", &deg); 
  rotation(image_in, image_out, deg); 
  
  break; 
     case 6: 
  printf("  ax, ay (float) ?  "); 
  scanf("%f %f", &a, &b); 
  printf("  dx, dy (float) ?  "); 
  scanf("%f %f", &x0, &y0); 
  printf("  deg (float) ?  "); 
  scanf("%f", &deg); 
  affine(image_in, image_out, deg, a, b, x0, y0); 
  
  break; 
     case 7: 
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
  perspect(image_in, image_out,  
    a, b, x0, y0, z0, zr, xr, yr,v,scr); 
  
  break; 
     default: 
  printf("--Not defined number !\n"); 
  break; 
     } 
     break; 
 case 9: 
     printf(" 1:FFT\n"); 
     printf(" 2:FFT Filter  ?  "); 
     scanf("%d", &n); 
     switch(n) { 
     case 1: 
  if (fftimage(image_in, image_out) == -1) 
      printf("--Memory allocation error !\n"); 
  break; 
     case 2: 
  printf("  range min max ?  "); 
  scanf("%i %i", &m, &n); 
  if (fftfilter(image_in, image_out, m, n) == -1) 
      printf("--Memory allocation error !\n"); 
  break; 
     default: 
  printf("--Not defined number !\n"); 
  break; 
     } 
     break; 
 case 10: 
     masking(image_in, image_out, image_key); 
     
     break; 
 case 0: 
     printf("...Bye-bye ........\n");  
     break; 
 default: 
     printf("--Not defined number !\n");  
     break; 
 } 
    }while(command);
   
    //Copy to QImage 
    array_to_qimage(&input_image, image_in);
    array_to_qimage(&output_image, image_out);
    array_to_qimage(&work_image, image_work);
    array_to_qimage(&key_image, image_key);
    
    widget_in.setFixedWidth(X_SIZE);//window resize
    widget_in.setFixedHeight(Y_SIZE);
    widget_out.setFixedWidth(X_SIZE);
    widget_out.setFixedHeight(Y_SIZE);
    widget_work.setFixedWidth(X_SIZE);
    widget_work.setFixedHeight(Y_SIZE);
    widget_key.setFixedWidth(X_SIZE);
    widget_key.setFixedHeight(Y_SIZE);
    widget_in.setCaption("IN");//set caption
    widget_out.setCaption("OUT");
    widget_work.setCaption("WORK");
    widget_key.setCaption("KEY");
    pixmap_in.convertFromImage(input_image);//convert to pixmap
    pixmap_out.convertFromImage(output_image);
    pixmap_work.convertFromImage(work_image);
    pixmap_key.convertFromImage(key_image);
    widget_in.setPixmap(pixmap_in);//set pixmap
    widget_out.setPixmap(pixmap_out);
    widget_work.setPixmap(pixmap_work);
    widget_key.setPixmap(pixmap_key);
    widget_in.show();//show windows
    widget_out.show();
    widget_work.show();
    widget_key.show();
    
    return application.exec();//Pass control to Qt
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
void array_to_qimage(QImage *image, unsigned char array[Y_SIZE][X_SIZE]){
    int loop_x=0, loop_y=0;
    int data;
    *image = image->convertDepth(32);
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     data = (int)array[loop_y][loop_x];
     image->setPixel(loop_x, loop_y, qRgb(data,data,data));
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
void qimage_to_array(QImage *image, unsigned char array[Y_SIZE][X_SIZE]){
    int loop_x, loop_y;
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     array[loop_y][loop_x] = qGray(image->pixel(loop_x, loop_y));
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
    int loop_x, loop_y;
    for(loop_y=0; loop_y<Y_SIZE; loop_y++){
 for(loop_x=0; loop_x<X_SIZE; loop_x++){
     in[loop_y][loop_x] = 0;
 }
    }
} 
