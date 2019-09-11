#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[256];
    int a;
    printf("insert filename: ");
    scanf("%s", filename);
    printf("insert the element you need: ");
    scanf("%d", &a);
    Function(filename, a);
    return 0;
}

int Function(char f[], int x)
{
    int c;
    FILE *fp;
    fp = fopen(f, "r");
    if (fp == NULL) {
       printf("error\n");
       return -1;
    }
    else {
       printf("done\n");
    }
    while ((fscanf(fp, "%d",&c)!=EOF)) {
       if (c == x) {
       printf("Element exists");
       }
       }
    fclose(fp);
    return 0;
}
