#include <stdio.h>
#include <stdlib.h>

int length(FILE *f)
{
  int l = 0;
  float c;
  while(fscanf(f,"%g", &c)==1) {
     l++;
  }
  return l;
}

void Zapis(FILE *f, float *ar, int l)
{
  for(int i = 0; i < l; i++) {
     fscanf(f, "%g", &ar[i]);
  }
}

void Sort(float *ar, int n)
{
  int l,r;
  float temp;
  l = 0;
  r = n - 1;
  while(l <= r) {
     for(int i = r; i >= 1; i--) {
        if(ar[i-1] > ar[i]) {
           temp = ar[i];
           ar[i] = ar[i-1];
           ar[i-1] = temp;
        }
     }
     l++;
     for(int j = l; j < r; j++) {
        if(ar[j] > ar[j+1]) {
           temp = ar[j];
           ar[j] = ar[j+1];
           ar[j+1] = temp;
        }
     }
     r--;
  }
}

int Func(float *A, float *B, int a, int b)
{
    int k = 0;
    if(a <= b) {
        for(int i = 0; i < b; i++) {
            if(i <= a) {
                if(A[i] > B[i]) {
                    return 0;
                }
            }
            else {
                if(A[a-1] > B[i]) {
                    return 0;
                }
            }
        }
    }
    else {
        for(int i = 0; i < a; i++) {
            if(i <= b) {
                if(A[i] > B[i]) {
                    return 0;
                }
            }
            else {
                if(A[i] > B[b-1]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(void)
{
  FILE *ina, *inb, *out;
  int a,b,c;
  float *A, *B;
  ina = fopen("data.txt", "r");
  inb = fopen("datb.txt", "r");
  out = fopen("out.txt", "w");
  if(ina == NULL) {
     return -1;
  }
  if(inb == NULL) {
     fclose(ina);
     return -1;
  }
  if(out == NULL) {
     fclose(ina);
     fclose(inb);
     return -1;
  }
  a = length(ina);
  b = length(inb);
  rewind(ina);
  rewind(inb);
  A = (float*)calloc(a, sizeof(float));
  B = (float*)calloc(b, sizeof(float));
  Zapis(ina, A, a);
  Zapis(inb, B, b);
  Sort(A,a);
  Sort(B,b);
  c = Func(A, B, a, b);
  if (c == 1) {
    fprintf(out, "YES");
  }
  else {
    fprintf(out, "NO");
  }
  fclose(ina);
  fclose(inb);
  fclose(out);
  free(A);
  free(B);
  return 0;
}
