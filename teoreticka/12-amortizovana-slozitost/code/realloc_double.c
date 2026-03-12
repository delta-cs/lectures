#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int n = 1000000;
    int *array = NULL;
    int capacity = 1;

    array = malloc(capacity * sizeof(int));

    clock_t start = clock();

    for (int i = 0; i < n; i++)
    {
        if (i == capacity)
        {
            capacity *= 2;
            array = realloc(array, capacity * sizeof(int));
        }
        array[i] = i;
    }

    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("realloc by doubling: %.3f s\n", time);
    printf("elements: %d\n", n);

    free(array);
    return 0;
}
