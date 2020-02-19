#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Function(int, int, float **, float **);

void Function(int m, int n, float **p1, float **p2)
{
    int k;
    int c,d = 0;
    int l,s,g = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(k = 0; k < m; k++) {
              if (p1[i][j] > p1[i][k]) {
                c++;
              }
              if(c == m) {
                d++;
              }
              if(d == n) {
                while(l < m) {
                  while(s < n) {
                    if(l == i) {
                      g = l;
                      l++;
                      p2[g][s] = p1[l][s];
                    }
                    else {
                      p2[g][s] = p1[l][s];
                    }
                    s++;
                  }
                  l++;
                  g++;
                }
              }
            }
        }
    }
}

int main(void)
{
  int m,n;
  FILE  *fp;
  FILE *out;
  float **a;
  float **b;
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

  //for(int s = 0; s < m; s++) {
  //  for(int l = 0; l < n; l++) {
  //    if (l == n-1) {
  //      fprintf(out, "%g \n", a[s][l]);
  //    }
  //    else {
  //      fprintf(out, "%g ", a[s][l]);
  //    }
  //  }
  //}

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
  b = (float**)malloc((m-1)*sizeof(float*) + (m-1)*n*sizeof(float*));
  Function(m,n,a,b);
  for(int s = 0; s < m-1; s++) {
    for(int l = 0; l < n; l++) {
      if (l == n-1) {
        fprintf(out, "%g \n", b[s][l]);
      }
      else {
        fprintf(out, "%g ", b[s][l]);
      }
    }
  }
  fclose(out);
  for(int h = 0; h < m; h++) {
      free(a[h]);
      a[h] = NULL;
  }
  free(a);
  for(int z = 0; z < m-1; z++) {
      free(b[z]);
      b[z] = NULL;
  }
  free(b);
  return 0;
}
