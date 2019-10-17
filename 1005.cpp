#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; ++i)
    {
        double x, y;
        scanf("%lf %lf", &x, &y);
        double d = (x*x+y*y)*M_PI_2/50;
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, (int)d + 1);
    }
    printf("END OF OUTPUT.");

    return 0;
}