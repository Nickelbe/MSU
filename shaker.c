#include <stdio.h>
#include <stdlib.h>

void Sort(float *, int);

int main(void)
{
    char filename[256];
    int num;
    float *ptr;
    FILE *fp;
    printf("введите имя файла: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
       printf("ошибка при открытии\n");
       return 0;
    }
    else {
       printf("файл открыт\n ");
    }
    fscanf(fp, "%d", &num);
    printf("n = %d\n",num);
    ptr = (float*)calloc(num, sizeof(float));
    if (ptr == NULL) {
       printf("память не выделена!\n");
       return 0;
    }

    for(int i = 0; i < num; i++) {
       fscanf(fp, "%g", &ptr[i]);
       printf("элемент массива: %g\n", ptr[i]);
    }
    fclose(fp);
    Sort(ptr, num);
    free(ptr);
    return 0;
}

void Sort(float *p, int n)
{
  int l,r;
  float temp;
  l = 0;
  r = n - 1;
  while (l <= r)
  {
    for (int i = r; i >= l; i--) {
      if (p[i - 1] > p[i]) {
        temp = p[i];
        p[i] = p[i-1];
        p[i-1] = temp;
      }
    }
    l++;

    for (int k = l; k < r; k++) {
      if (p[k] > p[k+1]) {
        temp = p[k];
        p[k] = p[k+1];
        p[k+1] = temp;
      }
    }
    r--;
  }
  for (int j = 0; j < n; j++) {
    printf("New array's element := %g\n", p[j]);
  }
}
