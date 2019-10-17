#include <stdio.h>

int main()
{
    int count = 0;
    while (true)
    {
        count++;
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == -1)
            break;
        a = a % 23, b = b % 28, c = c % 33;
        for (; (c - a) % 23 != 0 || (c - b) % 28 != 0; c += 33)
            ;
        d = (c - d + 21252) % 21252;
        if (d == 0)
            d = 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", count, d);
    }

    return 0;
}