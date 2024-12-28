#include <stdio.h>
#include <math.h>
#include <time.h>

#define LMAX 131075 //Tamanho máx. do array de amostras
#define Ts 0.000125 //Tempo de amostragem
#define fc_lo 100 //Frequência de corte do filtro passa alta
#define fc_hi 900 //Frequência de corte do filtro passa alta
#define fd 100 //Distância mínima, em Hz, entre cada pico do espectro de fourier
#define abs(a) ((a) < 0 ? (a)*(-1) : (a))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct{
  int x;
  double y;
} Point;

void double_swap(double *a, double *b)
{
  double temp = *a;
  *a = *b;
  *b = temp;
}

void fft(double *data, const int n, const int isign)
{
  int nn, mmax, m, j, istep, i;
  double wtemp, wr, wpr, wpi, wi, theta, tempr, tempi;
  nn = n << 1;
  j = 1;
  for(i = 1; i < nn; i+=2) {
    if(j > i) {
        double_swap(&data[j-1], &data[i-1]);
        double_swap(&data[j], &data[i]);
    }
    m = n;
    while(m >= 2 && j > m) {
        j -= m;
        m >>= 1;
    }
    j += m;
  }

  mmax = 2;
  while(nn > mmax) {
    istep = mmax << 1;
    theta = isign*(6.28318530717959/mmax);
    wtemp = sin(0.5*theta);
    wpr = -2.0*wtemp*wtemp;
    wpi = sin(theta);
    wr = 1.0;
    wi = 0.0;
    for(m = 1; m < mmax; m += 2) {
      for(i = m; i <= nn; i += istep) {
        j = i+mmax;
        tempr = wr*data[j-1]-wi*data[j];
        tempi = wr*data[j]+wi*data[j-1];
        data[j-1] = data[i-1]-tempr;
        data[j] = data[i]-tempi;
        data[i-1] += tempr;
        data[i] += tempi;
      }
      wr = (wtemp = wr)*wpr-wi*wpi+wr;
      wi = wi*wpr+wtemp*wpi+wi;
    }
    mmax = istep;
  }
}

void point_swap(Point *a, Point *b)
{
  Point temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(Point *arr, int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l < n && arr[l].y < arr[largest].y)
    largest = l;

  if(r < n && arr[r].y < arr[largest].y)
    largest = r;

  if(largest != i) {
    point_swap(&arr[i], &arr[largest]);

    heapify(arr, n, largest);
  }
}

void heapsort(Point *arr, int n)
{
  for(int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for(int i = n - 1; i > 0; i--) {
    point_swap(&arr[0], &arr[i]);

    heapify(arr, i, 0);
  }
}

double f0(double *data, const int L, const double threshold)
{
  //Range [left, rigth] do array onde o pico será detectado
  int left = (int)(fc_lo*L*Ts)*2, rigth = (int)(fc_hi*L*Ts)*2, delta = fd*L*Ts;
  int l = (rigth-left)/2 + 1;

  //Array do espectro bilateral de fourier
  Point data_fft[l];

  // double ymax = -1;
  //Construção do espectro bilateral de fourier
  for(int i = left; i <= rigth; i += 2) {
    data_fft[(i-left)/2].x = i/2;
    data_fft[(i-left)/2].y = sqrt(data[i]*data[i] + data[i+1]*data[i+1]);
    // ymax = max(ymax, data_fft[j].y);
    // printf("%lf %lf\n", (i/2)/(L*Ts), data_fft[i/2]);
  }

  heapsort(data_fft, l); //Ordenação de modo decrescente

  Point pico = data_fft[0];
  double ymax = pico.y;
  // printf("%lf %lf\n", pico.x/(L*Ts), pico.y/ymax);
  for(int i = 0; i < l; i++) {

    // printf("%lf %lf\n", data_fft[i].x/(L*Ts), data_fft[i].y/ymax);

    if((data_fft[i].y/ymax) < threshold)
      break;

    // printf("%lf\n", data_fft[i].y/ymax);

    if((pico.x - data_fft[i].x) >= delta) {
      pico = data_fft[i];
      // printf("%lf %lf\n", pico.x/(L*Ts), pico.y/ymax);
    }

  }

  return pico.x/(L*Ts);
}

int main(void)
{
  // clock_t t; 
  // t = clock(); 
  
  //Array dos dados lidos
  double data[2*LMAX] = {};

  //Leitura dos dados
  int i = 0;
  while(scanf("%lf", &data[i]) != EOF) {
    data[i] /= 100;
    i += 2;
  }

  //Encontrando a próxima potência de 2
  int L = i/2;
  if(L < 2 || L&(L-1))
    L = 1 << ((int)(log2(L)+1));

  //Execução da fft
  fft(data, L, 1);

  printf("%lf\n", f0(data, L, 0.2));

  // t = clock() - t; 
  // printf("%lf\n", ((double)t)/CLOCKS_PER_SEC); // in seconds 

  return 0;
}