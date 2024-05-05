#include <stdio.h>

long long minEnd(int n, int x) {
    long long last = x;
    for (int i = 1; i < n; ++i) {
        last = (last + 1) | x;
    }
    return last;
}

int main() {
    int n, x;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Minimum possible value of nums[n - 1]: %lld\n", minEnd(n, x));
    return 0;
}
