#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Selfcrossing

typedef struct point {
    float x;
    float y;
} Point;

int main(void)
{   int num;
    Point *p;
    printf("Quantity of points = ");
    scanf("%d", &num);
    p = (Point*)calloc(num, sizeof(Point));
    for (int i = 0; i < num; i++) {
       printf("Enter x: ");
       scanf("%g", &p[i].x);
       printf("Enter y: ");
       scanf("%g", &p[i].y);
    }
    for (int j = 0; j < num; j++) {
       printf("%g", p[j].x);
       printf("  ");
       printf("%g\n", p[j].y);
    }
    Selfcrossing(p);
    return 0;
}

void Selfcrossing(curve)
{

}
