#include <stdio.h>
#include <math.h>

#define LMAX 131075 //Tamanho máx. do array de amostras
#define offset 2140 //Offset do sinal
#define frame 512
#define abs(a) ((a) < 0 ? (a)*(-1) : (a))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{ 
  //Array dos dados lidos
  double data[LMAX] = {}, energy[(int)(LMAX/frame) + 5], signal[2*LMAX] = {};

  //Leitura dos dados
  int L = 0;
  double data_max = 0;
  while(scanf("%lf", &data[L]) != EOF) {
    data[L] -= offset; //Retirando o offset
    data_max = max(data_max, data[L]);
    L++;
  }

  //Normalizando o sinal
  double sum = 0, energy_max = 0;
  int n = 0;

  for(int i = 0; i < L; i++) {

    data[i] /= data_max;
    sum += data[i]*data[i];

    if(i%frame == frame-1) {
      sum /= frame;
      energy[n] = sum;
      energy_max = max(energy[n], energy_max);
      sum = 0;
      n++;
    }
  }

  double threshold = 0.1;

  for(int i = 0; i < n; i++) {
    if(energy[i] > energy_max*threshold) {
      for(int j = 0; )
    }
  }

  return 0;
}