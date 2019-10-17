#include <stdio.h>

int main()
{
    double sum = 0;
    for(int i = 0; i < 12; ++i)
    {
        double cur;
        scanf("%lf", &cur);
        sum += cur;
    }
    printf("$%.02lf\n", sum / 12);
    return 0;
}