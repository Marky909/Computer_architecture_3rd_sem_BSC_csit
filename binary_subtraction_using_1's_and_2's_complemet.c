#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void binarySubtractionTwos(char *, char *);
void binarySubtractionOnes(char *, char *);
char *onesComplement(char *);
char *twosComplement(char *);
char *binaryAddition(char *, char *);

// Function to read input as a binary string
void readBinaryInput(char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    scanf("%s", buffer);
}

int main() {
    char bin1[65], bin2[65];

    // Input two binary numbers
    readBinaryInput("Enter first binary number: ", bin1, 65);
    readBinaryInput("Enter second binary number: ", bin2, 65);

    // Perform Binary Subtraction using 2's Complement
    printf("\nBinary Subtraction (2's Complement): ");
    binarySubtractionTwos(bin1, bin2);

    // Perform Binary Subtraction using 1's Complement
    printf("Binary Subtraction (1's Complement): ");
    binarySubtractionOnes(bin1, bin2);

    return 0;
}

// Function to perform binary subtraction using 2's complement
void binarySubtractionTwos(char *bin1, char *bin2) {
    char *bin2TwosComp = twosComplement(bin2);
    char *result = binaryAddition(bin1, bin2TwosComp);

    printf("%s - %s = %s\n", bin1, bin2, result);

    free(bin2TwosComp);
    free(result);
}

// Function to perform binary subtraction using 1's complement
void binarySubtractionOnes(char *bin1, char *bin2) {
    char *bin2OnesComp = onesComplement(bin2);
    char *result = binaryAddition(bin1, bin2OnesComp);

    printf("%s - %s = %s\n", bin1, bin2, result);

    free(bin2OnesComp);
    free(result);
}

// Function to compute 1's complement of a binary number
char *onesComplement(char *bin) {
    size_t len = strlen(bin);
    char *result = (char *)malloc(len + 1);

    for (size_t i = 0; i < len; i++) {
        result[i] = (bin[i] == '0') ? '1' : '0';
    }
    result[len] = '\0';

    return result;
}

// Function to compute 2's complement (1's complement + 1)
char *twosComplement(char *bin) {
    char *onesComp = onesComplement(bin);
    char *result = binaryAddition(onesComp, "1");

    free(onesComp);
    return result;
}

// Function to add two binary numbers
char *binaryAddition(char *bin1, char *bin2) {
    size_t len1 = strlen(bin1);
    size_t len2 = strlen(bin2);
    size_t maxLen = (len1 > len2) ? len1 : len2;

    char *result = (char *)malloc(maxLen + 2); // +2 for possible carry and null terminator
    result[maxLen + 1] = '\0';

    int carry = 0, sum;
    for (int i = 0; i < maxLen; i++) {
        int bit1 = (i < len1) ? bin1[len1 - 1 - i] - '0' : 0;
        int bit2 = (i < len2) ? bin2[len2 - 1 - i] - '0' : 0;

        sum = bit1 + bit2 + carry;
        result[maxLen - i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry) {
        result[0] = '1';
        return result;
    } else {
        return result + 1; // Skip leading zero
    }
}

