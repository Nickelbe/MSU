#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float gen(float, float);

int main(void)
{
    float *ptr;
    clock_t time;
    size_t n;
    float a,b;
    printf("левая и правая границы: \n");
    scanf("%g", &a);
    scanf("%g", &b);
    printf("число элементов в массиве: ");
    scanf("%lu", &n);
    ptr = (float*)calloc(n, sizeof(float));
    if (ptr == NULL) {
       printf("память не выделена \n");
       return 0;
    }
    time = clock();
    for (size_t i = 0; i < n; i++) {
       ptr[i] = gen(a,b);
    }
    time = clock() - time;
    printf("time = %g\n", (float)time/CLOCKS_PER_SEC);
    for (size_t j = 0; j < n; j++) {
       printf("элемент массива := %g\n", ptr[j]);
    }
    free(ptr);
    return 0;
}

float gen(float k, float l)
{
    float res;
    static const float h = 1.0/(RAND_MAX);
    res = rand()*h*(l-k)+k;
    return res;
}