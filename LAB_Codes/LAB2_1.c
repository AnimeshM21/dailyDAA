#include <stdio.h>

int gcd(int m, int n) {
    int t = (m < n) ? m : n;
    while (t > 0) {
        if (m % t == 0 && n % t == 0)
            return t;
        t--;
    }
    return 1;
}

int main() {
    int m, n;
    printf("Enter two numbers: ");
    scanf("%d %d", &m, &n);
    printf("GCD of %d and %d is %d\n", m, n, gcd(m, n));
    return 0;
}