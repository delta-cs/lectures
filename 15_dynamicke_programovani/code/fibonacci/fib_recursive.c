#include <stdio.h>

typedef unsigned int ui;
typedef long long ll;

ll fib(ui n) {
    if (n < 2) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    scanf("%d", &n); // n <= 92 (type) && n <= 50 (time)
    printf("%lld\n", fib(n));
    return 0;
}
