#include <stdio.h>

// Function prototype
long long convertToBinary(int);

int main() {
    int n;

    // Input: Decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    // Convert and display binary equivalent
    printf("%d in decimal = %lld in binary\n", n, convertToBinary(n));

    return 0;
}

// Function to convert decimal to binary
long long convertToBinary(int n) {
    long long binary = 0;
    int rem, place = 1;

    while (n > 0) {
        rem = n % 2;  // Get remainder (0 or 1)
        binary += rem * place; // Add to binary result
        n /= 2;  // Divide by 2
        place *= 10;  // Shift left (move place value)
    }

    return binary;
}

