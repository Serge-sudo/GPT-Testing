#include <stdio.h>

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int first = 1, second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int main() {
    int n;
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    printf("Number of ways to climb to the top: %d\n", climbStairs(n));
    return 0;
}
