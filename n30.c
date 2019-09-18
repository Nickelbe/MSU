#include <stdio.h>
#include <stdlib.h>

int Function(char f[])
{
    int c;
    int min;
    int k;
    k = 0;
    FILE *fp;
    fp = fopen(f, "r");
    if (fp == NULL) {
       printf(" ошибка\n ");
       return -1;
    }
    else {
       printf(" сделано\n ");
    }
    fscanf(fp, "%d", &min);
    while ((fscanf(fp, "%d",&c)!=EOF)) {
         if (min == c) {
         k++;
         }
         if (min > c) {
         min = c;
         k = 0;
         }
       }
    fclose(fp);
    printf("ответ: %d", k);
    return k;
}

int main(void)
{
    char filename[256];
    printf("введите имя файла: ");
    scanf("%s", filename);
    Function(filename);
    return 0;
}

