#include <stdio.h>

#define NMAX 80000 //Número máximo de amostras
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
  int data[NMAX];

  int N = 0;
  while(scanf("%d", &data[N]) != EOF) N++;

  // N = 27615-8240+1;
  int window = 2048;
  int corte = N-window;
  int l = max(corte/2, 0);
  int r = min(N-corte/2-corte%2, N);
  // printf("%d, 0", data[l]);
  // for(int i = l+1; i < r; i++) {
  //   printf(", %d, 0", data[i]);
  // }
  for(int i = l; i < r; i++) {
    printf("%d\n", data[i]);
  }
  // for(int i = 0; i < min(window, N); i++) {
  //   printf("%d\n", data[i]);
  // }

  return 0;
}