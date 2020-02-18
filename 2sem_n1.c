#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
  int m,n;
  FILE  *fp;
  FILE *out;
  float **a;
  fp = fopen("data.txt", "r");
  if (fp == NULL) {
     printf("ошибка при открытии\n");
     return 0;
  }
  else {
         printf("файл открыт\n ");
  }
  fscanf(fp, "%d", &m);
  fscanf(fp, "%d", &n);
  printf("m = %d\n", m);
  printf("n = %d\n", n);
  a = (float**)malloc(m*sizeof(float*));
  for(int k = 0; k < m; k++) {
    a[k] = (float*)malloc(n*sizeof(float));
  }
  for( int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      fscanf(fp, "%g", &a[i][j]);
    }
  }
  fclose(fp);
  out = fopen("out.txt", "w");
  for(int s = 0; s < m; s++) {
    for(int l = 0; l < n; l++) {
      if (l == n-1) {
        fprintf(out, "%g \n", a[s][l]);
      }
      else {
        fprintf(out, "%g ", a[s][l]);
      }
    }
  }
  for(int t = 0; t < m; t++) {
    for(int p = 0; p < n; p++) {
      if (p == n-1) {
        printf("%g \n", a[t][p]);
      }
      else {
        printf("%g ", a[t][p]);
      }
    }
  }
  fclose(out);
  return 0;
}
