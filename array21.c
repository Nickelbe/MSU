#include <stdio.h>
#include <stdlib.h>

void Function(float*, int);
void Function(float *p, int n)
{
//char output[256];
    int k,c,h;
    float d,sum;
    for (int i = 0; i < n-1; i++) {
        sum = 0;
        c = 1;
        if(p[i] < p[i+1]) {
              d = 1;
              k = i;
              h = i;
              sum += p[i];
              while(p[k] < p[k+1]) {
                k++;
                c++;
                d++;
                sum += p[k];
                printf("summa posl-ti:= %g\n", sum);
              }
              while(c != 2) {
                p[h+1] = sum/d;
                h++;
                c--;
              }
        }
    }
    for(int g = 0; g < n; g++) {
        printf("Poluczivszyesja: %.2g\n", p[g]);
    }
    //FILE *out;
    //printf("Введите имя выходного файла:\n");
    //scanf("%s", output);
    //out = fopen(output, "w");
    //for (int k = 0; k < n; n++) {
     //   fprintf(out, "%d", p[k]);
    //}
    //fclose(out);
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