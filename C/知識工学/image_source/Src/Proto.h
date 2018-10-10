#ifndef PROTOTYPE
#define PROTOTYPE

#include"Colorbar.c"
#include"RgbYc.c"
#include"CSh.c"
#include"ShImage.c"
#include"TranYsh.c"

#include"Hist2Im.c"
#include"Histgram.c"
#include"OutHist.c"
#include"ThreshC.c"
#include"HardMask.c"
#include"SoftMask.c"
#include"Synth.c"
#include"Ssynth.c"
#include"Perspect.c"

#include"Median.c"
#include"Scale.c"
#include"ScaleNG.c"
#include"ScaleNea.c"
#include"HistImag.c"
#include"Rotation.c"
#include"Shift.c"
#include"Affine.c"
#include"Smooth.c"
#include"Template.c"
#include"Gradient.c"
#include"Laplacia.c"

#include"Masking.c"
#include"Fft1.c"
#include"Fft2.c"
#include"FftFilt.c"
#include"FftImage.c"
#include"Amplify.c"
#include"Plane.c"
#include"Range.c"
#include"Expand.c"
#include"Labeling.c"
#include"Features.c"
#include"Thresh.c"
#include"Thinning.c"
#include"Sextract.c"
#include"Rextract.c"
#include"Dilation.c"
#include"Erosion.c"
#include"HistSmth.c"
#include"HistPrin.c"

int main( int argc, char *argv[]);
void outputHistgram(long histgram[256]);

void affine(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], 
 float deg, float zx, float zy, float px, float py);
void amplify(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], float n);
void c_to_sh(int c1[Y_SIZE][X_SIZE], int c2[Y_SIZE][X_SIZE],
 int sat[Y_SIZE][X_SIZE], int hue[Y_SIZE][X_SIZE]);
void sh_to_c(int sat[Y_SIZE][X_SIZE], int hue[Y_SIZE][X_SIZE], 
 int c1[Y_SIZE][X_SIZE], int c2[Y_SIZE][X_SIZE]);
void colorbar(unsigned char image_r[Y_SIZE][X_SIZE], 
 unsigned char image_g[Y_SIZE][X_SIZE], 
 unsigned char image_b[Y_SIZE][X_SIZE], int level);
void dilation(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE]);
void dpcm1(unsigned char image_in[Y_SIZE][X_SIZE], int line,
 short data_out[X_SIZE]);
void dpcm2(unsigned char image_in[Y_SIZE][X_SIZE], int line,
 short data_out[X_SIZE]);
int dpcm_vlcode(unsigned char image_int[Y_SIZE][X_SIZE],
 unsigned char image_buft[Y_SIZE][X_SIZE]);
void erosion(unsigned char image_in[Y_SIZE][X_SIZE],
 unsigned char image_out[Y_SIZE][X_SIZE]);
int event(short dt);
void expand(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], int fmax, int fmin);
void features(unsigned char image_label_in[Y_SIZE][X_SIZE], 
 unsigned char image_label_out[Y_SIZE][X_SIZE], 
 int cnt, float size[], float ratio[], char *buf);
int fft1(float a_rl[], float a_im[], int ex, int inv);
int fft2 (float a_rl[Y_SIZE][X_SIZE], float a_im[Y_SIZE][X_SIZE], int inv);
int fftfilter(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], int a, int b);
int fftimage(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE]);
void gradient(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], float amp);
void hard_mask(unsigned char image_in_r[Y_SIZE][X_SIZE], 
 unsigned char image_in_g[Y_SIZE][X_SIZE], 
 unsigned char image_in_b[Y_SIZE][X_SIZE], 
 unsigned char image_key[Y_SIZE][X_SIZE], int thresh);
void hist2_image(unsigned char  image_in1[Y_SIZE][X_SIZE], 
 unsigned char image_in2[Y_SIZE][X_SIZE], 
 unsigned char image_hist[Y_SIZE][X_SIZE]);
void histgram(unsigned char image_in[Y_SIZE][X_SIZE], long hist[256]);
void histimage(long hist[256], unsigned char image_hist[Y_SIZE][X_SIZE]);
void histprint(long hist[256], char *buf);
void histsmooth(long hist_in[256], long hist_out[256]);
void hue_image(int sat[Y_SIZE][X_SIZE], int hue[Y_SIZE][X_SIZE], 
 float stdhue, unsigned char image_out[Y_SIZE][X_SIZE]);
void idpcm1(short data_in[X_SIZE], int line, 
 unsigned char image_out[Y_SIZE][X_SIZE]);
void idpcm2(short data_in[X_SIZE], int line, 
 unsigned char image_out[Y_SIZE][X_SIZE]);
int idpcm_vlcode(unsigned char image_buft[Y_SIZE][X_SIZE], 
 unsigned char image_outt[Y_SIZE][X_SIZE]);
int ievent(short ev);
void image_clear(unsigned char image[Y_SIZE][X_SIZE]);
void image_clear_color(unsigned char image[3][Y_SIZE][X_SIZE]);
void image_copy(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE]);
void image_copy_color(unsigned char image_in[3][Y_SIZE][X_SIZE], 
 unsigned char image_out[3][Y_SIZE][X_SIZE]);
int image_read(unsigned char image[Y_SIZE][X_SIZE], char *filename);
int image_read_color(unsigned char image[3][Y_SIZE][X_SIZE], char *filename);
int image_write(unsigned char image[Y_SIZE][X_SIZE], char *filename);
int image_write_color(unsigned char image[3][Y_SIZE][X_SIZE], char *filename);
void ivlcode(char vlc_in[], int no, short int data_out[]);
int labeling(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_label[Y_SIZE][X_SIZE], int *cnt, char *buf);
void laplacian(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], float amp);
void masking(unsigned char image_int[Y_SIZE][X_SIZE],
 unsigned char image_outt[Y_SIZE][X_SIZE],
 unsigned char image_maskt[Y_SIZE][X_SIZE]);
void median(unsigned char image_in[Y_SIZE][X_SIZE],
 unsigned char image_out[Y_SIZE][X_SIZE]);
void perspect(unsigned char image_in[Y_SIZE][X_SIZE],
 unsigned char image_out[Y_SIZE][X_SIZE], float ax, float ay,
 float px, float py, float pz, float rz,
 float rx, float ry, float v, float s);
void plane(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], 
 unsigned char image_buf[Y_SIZE][X_SIZE], long hist[256]);
void ratio_extract(unsigned char image_label_in[Y_SIZE][X_SIZE], 
 unsigned char image_label_out[Y_SIZE][X_SIZE], 
 int cnt, float ratio[], float ratio_min, float ratio_max);
void range(unsigned char image_in[Y_SIZE][X_SIZE], int *fmax, int *fmin);
void rgb_to_yc(unsigned char image_r[Y_SIZE][X_SIZE],
 unsigned char image_g[Y_SIZE][X_SIZE],
 unsigned char image_b[Y_SIZE][X_SIZE],
 int y[Y_SIZE][X_SIZE], int c1[Y_SIZE][X_SIZE], int c2[Y_SIZE][X_SIZE]);
void rotation(unsigned char image_in[Y_SIZE][X_SIZE],
 unsigned char image_out[Y_SIZE][X_SIZE], float deg);
int sat_image(int sat[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE]);
void scale(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], float zx, float zy);
void scale_near(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], float zx, float zy);
void scale_ng(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], float zx, float zy);
void shift(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE], float px, float py);
void size_extract(unsigned char image_label_in[Y_SIZE][X_SIZE],
 unsigned char image_label_out[Y_SIZE][X_SIZE], 
 int cnt, float size[], float size_min, float size_max);
void smooth(unsigned char image_in[Y_SIZE][X_SIZE], 
 unsigned char image_out[Y_SIZE][X_SIZE]);
void soft_mask(unsigned char image_in_r[Y_SIZE][X_SIZE],
 unsigned char image_in_g[Y_SIZE][X_SIZE], 
 unsigned char image_in_b[Y_SIZE][X_SIZE],
 unsigned char image_key[Y_SIZE][X_SIZE], int thdh, int thdl);
void synth(unsigned char image_in1_r[Y_SIZE][X_SIZE], 
 unsigned char image_in1_g[Y_SIZE][X_SIZE],
 unsigned char image_in1_b[Y_SIZE][X_SIZE],
 unsigned char image_in2_r[Y_SIZE][X_SIZE],
 unsigned char image_in2_g[Y_SIZE][X_SIZE],
 unsigned char image_in2_b[Y_SIZE][X_SIZE],
 unsigned char image_out_r[Y_SIZE][X_SIZE],
 unsigned char image_out_g[Y_SIZE][X_SIZE],
 unsigned char image_out_b[Y_SIZE][X_SIZE],
 unsigned char image_key[Y_SIZE][X_SIZE]);
void s_synth(unsigned char image_in1_r[Y_SIZE][X_SIZE], 
 unsigned char image_in1_g[Y_SIZE][X_SIZE],
 unsigned char image_in1_b[Y_SIZE][X_SIZE],
 unsigned char image_in2_r[Y_SIZE][X_SIZE],
 unsigned char image_in2_g[Y_SIZE][X_SIZE],
 unsigned char image_in2_b[Y_SIZE][X_SIZE],
 unsigned char image_out_r[Y_SIZE][X_SIZE],
 unsigned char image_out_g[Y_SIZE][X_SIZE],
 unsigned char image_out_b[Y_SIZE][X_SIZE],
 unsigned char image_key[Y_SIZE][X_SIZE]);
void template_matching(unsigned char image_in[Y_SIZE][X_SIZE],
 unsigned char image_out[Y_SIZE][X_SIZE], float amp);
void thinning(unsigned char image_in[Y_SIZE][X_SIZE],
 unsigned char image_out[Y_SIZE][X_SIZE]);
void threshold(unsigned char image_in[Y_SIZE][X_SIZE],
 unsigned char image_out[Y_SIZE][X_SIZE], int thresh, int mode);
void thresh_color(unsigned char image_in_r[Y_SIZE][X_SIZE],
 unsigned char image_in_g[Y_SIZE][X_SIZE],
 unsigned char image_in_b[Y_SIZE][X_SIZE],
 unsigned char image_out_r[Y_SIZE][X_SIZE],
 unsigned char image_out_g[Y_SIZE][X_SIZE],
 unsigned char image_out_b[Y_SIZE][X_SIZE],
 int thdrl, int thdrm, int thdgl, int thdgm, int thdbl, int thdbm);
void tran_ysh(int in_y[Y_SIZE][X_SIZE], int in_sat[Y_SIZE][X_SIZE],
 int in_hue[Y_SIZE][X_SIZE], int out_y[Y_SIZE][X_SIZE],
 int out_sat[Y_SIZE][X_SIZE], int out_hue[Y_SIZE][X_SIZE],
 float ym, float sm, float hd);
int vlcode(short int data_in[], int no, char vlc_out[]);
void yc_to_rgb(int y[Y_SIZE][X_SIZE], int c1[Y_SIZE][X_SIZE],
 int c2[Y_SIZE][X_SIZE],
 unsigned char image_r[Y_SIZE][X_SIZE],
 unsigned char image_g[Y_SIZE][X_SIZE],
 unsigned char image_b[Y_SIZE][X_SIZE]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void array_to_qimage(QImage *image, unsigned char array[3][Y_SIZE][X_SIZE]);
void qimage_to_array(QImage *image, unsigned char array[3][Y_SIZE][X_SIZE]);
void array_to_qimage(QImage *image, unsigned char array[Y_SIZE][X_SIZE]);
void qimage_to_array(QImage *image, unsigned char array[Y_SIZE][X_SIZE]);
void array_to_array(unsigned char in[3][Y_SIZE][X_SIZE], unsigned char out[3][Y_SIZE][X_SIZE]);
void array_to_array(unsigned char in[Y_SIZE][X_SIZE], 
      unsigned char out[Y_SIZE][X_SIZE]);
void image_clear_color(unsigned char in[3][Y_SIZE][X_SIZE]);
void image_clear(unsigned char in[Y_SIZE][X_SIZE]);

#endif
