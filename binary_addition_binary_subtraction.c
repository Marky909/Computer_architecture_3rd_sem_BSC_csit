#include <stdio.h>
#include <string.h>

// Function prototypes
long long binaryAddition(long long, long long);
long long binarySubtraction(long long, long long);
long long onesComplement(long long);
long long twosComplement(long long);

int main() {
    long long bin1, bin2;

    // Input two binary numbers
    printf("Enter first binary number: ");
    scanf("%lld", &bin1);
    printf("Enter second binary number: ");
    scanf("%lld", &bin2);

    // Perform Binary Addition
    printf("\nBinary Addition: %lld + %lld = %lld\n", bin1, bin2, binaryAddition(bin1, bin2));

    // Perform Binary Subtraction
    printf("Binary Subtraction: %lld - %lld = %lld\n", bin1, bin2, binarySubtraction(bin1, bin2));

    return 0;
}

// Function to perform binary addition
long long binaryAddition(long long bin1, long long bin2) {
    long long sum = 0, carry = 0, place = 1;

    while (bin1 > 0 || bin2 > 0 || carry > 0) {
        int bit1 = bin1 % 10;
        int bit2 = bin2 % 10;
        int bitSum = bit1 + bit2 + carry;

        sum += (bitSum % 2) * place;  // Store binary sum
        carry = bitSum / 2;           // Calculate carry
        bin1 /= 10;
        bin2 /= 10;
        place *= 10;                  // Move place value
    }

    return sum;
}

// Function to perform binary subtraction using 2's complement
long long binarySubtraction(long long bin1, long long bin2) {
    long long bin2TwosComp = twosComplement(bin2);
    return binaryAddition(bin1, bin2TwosComp); // A - B = A + 2's Complement of B
}

// Function to compute 1's complement of a binary number
long long onesComplement(long long bin) {
    long long result = 0, place = 1;

    while (bin > 0) {
        int bit = bin % 10;
        result += (bit == 0 ? 1 : 0) * place; // Flip 0 -> 1, 1 -> 0
        bin /= 10;
        place *= 10;
    }

    return result;
}

// Function to compute 2's complement (1's complement + 1)
long long twosComplement(long long bin) {
    return binaryAddition(onesComplement(bin), 1); // 1's complement + 1
}

