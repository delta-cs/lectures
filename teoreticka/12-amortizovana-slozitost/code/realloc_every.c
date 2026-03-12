#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int n = 1000000;
    int *array = NULL;

    clock_t start = clock();

    for (int i = 0; i < n; i++)
    {
        array = realloc(array, (i + 1) * sizeof(int));
        array[i] = i;
    }

    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("realloc every step: %.3f s\n", time);
    printf("elements: %d\n", n);

    free(array);
    return 0;
}
