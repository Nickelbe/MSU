#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct point {
        float x;
        float y;
} Point;

int main(void)
{     int num;
      Point* p;
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
        Selfcrossing(p, num);
		free(p);
        return 0;
}

int Selfcrossing(Point* L, int n)
{
	float S1,S2;
	int mark1, mark2, mark3, mark4;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			S1 = (L[i+1].x - L[i].x)*(L[j].y - L[i].y) - (L[j].x - L[i].x)*(L[i+1].y - L[i].y);
			S2 = (L[i+1].x - L[i].x)*(L[j+1].y - L[i].y) - (L[j+1].x - L[i].x)*(L[i+1].y - L[i].y);
			if ((min(L[j].x, L[j+1].x) < max(L[i].x, L[i+1].x)) && (min(L[j].y, L[j+1].y) < max(L[i].y, L[i+1].y))) {
                mark3 = 1;
            }
            if ((min(L[j].x, L[j+1].x) < max(L[i].x, L[i+1].x)) && (max(L[j].y, L[j+1].y) < min(L[i].y, L[i+1].y))) {
                mark4 = 1;
            }
            if ((max(L[j].x, L[j+1].x) < min(L[i].x, L[i+1].x)) && (min(L[j].y, L[j+1].y) < max(L[i].y, L[i+1].y))) {
                mark2 = 1;
            }
            if ((max(L[j].x, L[j+1].x) < min(L[i].x, L[i+1].x)) && (max(L[j].y, L[j+1].y) < min(L[i].y, L[i+1].y))) {
                mark1 = 1;
            }
			if (((S1 > 0) && (S2 < 0)) || ((S1 < 0) && (S2 > 0)) && ((mark1 == 1) || (mark2 == 1) || (mark3 == 1) || (mark4 == 1))) {
				printf("Yes\n");
				return 0;
			}
			}
		}
    printf("No\n");
	return 0;
}
