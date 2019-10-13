#include <stdio.h>
#include <stdlib.h>

int Function(int *p, int n)
{
    //char output[256];
    for (int j = 1; j <= n; j++) {
        if(p[j] < 0) {
           for (int l = j; l <= n-1; l++) {
               p[l] = p[l+1];
           }
           n--;
           j--;
        }
    }
    for (int k = 1; k <= n; k++) {
        printf("%d\n", p[k]);
    }
    //FILE *out;
    //printf("Введите имя выходного файла:\n");
    //scanf("%s", output);
    //out = fopen(output, "w");
    //for (int k = 0; k < n; n++) {
     //   fprintf(out, "%d", p[k]);
    //}
    //fclose(out);

    return 0;
}

int main(void)
{
    char filename[256];
    int num;
    int *ptr;
    printf("введите имя файла: ");
    scanf("%s", filename);
    FILE *fp;
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
    ptr = (int*)calloc(num, sizeof(int));
    if (ptr == NULL) {
       printf("память не выделена!\n");
       return 0;
    }

    for(int i = 1; i <= num; i++) {
       fscanf(fp, "%d", &ptr[i]);
       printf("элемент массива: %d\n", ptr[i]);
    }
    fclose(fp);
    Function(ptr, num);
    free(ptr);
    return 0;
}
