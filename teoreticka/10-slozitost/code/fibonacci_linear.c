#include <stdio.h>

typedef unsigned long long ull;

ull fib(int n) {
    if (n < 0) return -1;
    if (n < 2) return n;

    ull prepre = 0, pre = 1;
    ull result = 0;
    for (int i = 2; i <= n; i++) {
        result = prepre + pre;
        prepre = pre;
        pre = result;
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n); // n <= 92 (type)
    printf("%lld\n", fib(n));
    return 0;
}
