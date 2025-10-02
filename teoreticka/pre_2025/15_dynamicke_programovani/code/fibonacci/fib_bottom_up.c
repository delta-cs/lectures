#include <stdio.h>
#include <stdlib.h>

typedef unsigned int ui;
typedef long long ll;

ll fib_bottom_up(ui n, ll *memo) {
    if (n < 2) return n;

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

ll fib(ui n) {
    ll *memo = (ll *) calloc(n + 1, sizeof(ll));
    ll result = fib_bottom_up(n, memo);
    free(memo);
    return result;
}

int main() {
    int n;
    scanf("%d", &n); // n <= 92 (type)
    printf("%lld\n", fib(n));
    return 0;
}
