#include <stdio.h>
#include <stdlib.h>

typedef unsigned int ui;
typedef long long ll;

ll fib_memoization(ui n, ll *memo) {
    if (memo[n] > 0) return memo[n];
    if (n < 2) return memo[n] = n;

    memo[n] = fib_memoization(n - 1, memo) + fib_memoization(n - 2, memo);
    return memo[n];
}

ll fib(ui n) {
    ll *memo = (ll *) calloc(n + 1, sizeof(ll));
    ll result = fib_memoization(n, memo);
    free(memo);
    return result;
}

int main() {
    int n;
    scanf("%d", &n); // n <= 92 (type)
    printf("%lld\n", fib(n));
    return 0;
}
