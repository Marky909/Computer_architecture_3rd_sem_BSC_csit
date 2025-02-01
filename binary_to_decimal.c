#include <stdio.h>

// function prototype
long long convert(long long);

int main() {

    long long n;

    printf("Enter a binary number: ");
    scanf("%lld", &n);

    printf("%lld in binary = %lld in decimal", n, convert(n));

    return 0;
}

// function definition
long long convert(long long n) {

    long long dec = 0;
    int i = 0, rem;

    while (n != 0) {

        // get remainder of n divided by 10
        rem = n % 10;

        // add the rem * (2 ^ i) to dec
        dec += rem << i; // Using bitwise shift instead of pow

        // divide n by 10
        n /= 10;

        // increment i
        ++i;
    }

    return dec;
}
