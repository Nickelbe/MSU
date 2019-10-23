#include <stdio.h>
#include <stdlib.h>

void Function(float*, int);

void Function(float *p, int n)
{
    int k;
    float sum;
    sum = 0;
    k = 1;
    for(int i = 0; i < n-2; i++) {
       if((p[i+1] > p[i]) && (p[i+2] > p[i+1])) {
          while(p[i] < p[i+1]) {
             k++;
             sum += p[i];
          }
          for (int j = i; j <= k; j++) {
             p[j] = (sum/k);
          }
       k = 1;
       sum = 0;
       }
    }
    for(int g = 0; g < n; g++) {
       printf("element of the array: %g\n", p[g]);
    }
}


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
    Function(ptr, num);
    free(ptr);
    return 0;
}