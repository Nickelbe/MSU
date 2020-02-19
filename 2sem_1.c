#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Function(int, int, float **, float **);

void Function(int m, int n, float **p1, float **p2)
{
    int k;
    int c = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(k = 0; k < m; k++) {
                if(p1[i][j] > p1[k][j]) {
                    c++;
                }
                if(c == m) {
                    for(int l = 0; l < m; l++) {
                        for(int f = 0; f < n; f++) {
                            p2[l][f] = p1[l][f];
                        }
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
  b = (float**)malloc((m-1)*sizeof(float*) + (m-1)*n*sizeof(float));
  Function(m,n,a,b);
  for(int s = 0; s < m; s++) {
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
  for(int x = 0; x < (m-1); x++) {
      free(b[x]); 
      b[x] = NULL;
  }
  free(b);
  return 0;
}
