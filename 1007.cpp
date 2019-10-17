#include <stdio.h>
#include <stdlib.h>
#include <string.h>

template <class T>
int nvpairs(T *begin, T *end)
{
    int n = end - begin;
    if (n <= 1)
        return 0;
    T *mid = begin + n / 2;
    int npairs = 0;
    npairs += nvpairs(begin, mid);
    npairs += nvpairs(mid, end);

    T *buffer = new T[end - begin];

    T *pbuffer = buffer, *pbegin = begin, *pmid = mid;
    while (pbegin < mid && pmid < end)
    {
        if (*pmid < *pbegin)
        {
            *(pbuffer++) = *(pmid++);
            npairs += mid - pbegin;
        }
        else
            *(pbuffer++) = *(pbegin++);
    }
    while (pbegin < mid)
        *(pbuffer++) = *(pbegin++);
    while (pmid < end)
        *(pbuffer++) = *(pmid++);

    pbuffer = buffer, pbegin = begin;
    while (pbegin < end)
        *(pbegin++) = *(pbuffer++);

    delete[] buffer;

    return npairs;
}

char chs[110][60];

struct nvsort
{
    char *ch;
    int nv;

    bool operator<(const nvsort &rhs) const
    {
        return nv < rhs.nv;
    }
} nvs[110];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf(" %s", chs[i]);
        nvs[i].ch = chs[i];
        char buffer[60];
        memcpy(buffer, chs[i], n);
        nvs[i].nv = nvpairs(buffer, buffer + n);
    }

    nvpairs(nvs, nvs + m);

    for (int i = 0; i < m; ++i)
        printf("%s\n", nvs[i].ch);

    return 0;
}
