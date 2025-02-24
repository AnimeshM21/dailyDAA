#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int gcdMiddleSchool(int a, int b) {
    int gcd = 1;
    // Checking divisibility from 2 to min(a, b)
    for (int i = 2; i <= min(a, b); i++) {
        while (a % i == 0 && b % i == 0) { 
            gcd *= i;  // Multiply common prime factors
            a /= i;
            b /= i;
        }
    }
    return gcd;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcdMiddleSchool(a, b));
    return 0;
}