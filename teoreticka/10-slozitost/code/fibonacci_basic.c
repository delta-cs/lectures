#include <stdio.h>

typedef unsigned long long ull;

ull fib(int n) {
    if (n < 0) return -1;
    if (n < 2) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    scanf("%d", &n); // n <= 92 (type) && n <= 50 (time)
    printf("%lld\n", fib(n));
    return 0;
}
