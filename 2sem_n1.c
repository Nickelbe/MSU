#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Function(int, int, float **, float **);

int Function(int m, int n, float **p1, float **p2)
{
    int c,g,d;
    c = d = g = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(p1[i][j] > p1[k][j]) {
                    c++;
                }
            }
            printf("c = ");
            printf("%d \n", c);
            if(c == m-1) {
                d++;
            }
            c = 0;
            printf("d = ");
            printf("%d \n", d);
        }
        if(d == n) {
          printf("Woszli \n");
          c = 0;
          d = 0;
          while(c < m) {
            while(d < n) {
              if(i == (m-1)) {
                return 2;
              }
              if(c == i) {
                c++;
              }
              p2[g][d] = p1[c][d];
              d++;
            }
            d = 0;
            c++;
            g++;
          }
          return 1;
        }
    }
    return -1;
}

int main(void)
{
  int m,n;
  int mark;
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

  b = (float**)malloc((m-1)*sizeof(float*));
  for(int p = 0; p < m-1; p++) {
    b[p] = (float*)malloc(n*sizeof(float));
  }
  mark = Function(m,n,a,b);
  printf("%d \n", mark);
  if(mark == 1) {
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
  }
  else if(mark == -1) {
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
  }
  else if(mark == 2) {
    for(int s = 0; s < m-1; s++) {
        for(int l = 0; l < n; l++) {
            if (l == n-1) {
                fprintf(out, "%g \n", a[s][l]);
            }
            else {
                fprintf(out, "%g ", a[s][l]);
            }
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
