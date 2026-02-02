#include <stdio.h>
#include <math.h>

long double sqrt5, phi;

long double fib(long long n) {
    return floorl((powl(phi, n) / sqrt5) + 0.5);
}

int main() {
    sqrt5 = sqrt(5);
    phi = (1 + sqrt5) / 2;

    long long n;
    scanf("%lld", &n); // n <= 70 (type)
    printf("%.0Lf\n",  fib(n));
    return 0;
}
