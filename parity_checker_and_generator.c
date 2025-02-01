#include <stdio.h>

// Function prototypes
int generateParity(int, int);
int checkParity(int, int);

int main() {
    int data, parityType, parityBit, receivedData;

    // Input: Binary data
    printf("Enter a binary number: ");
    scanf("%d", &data);

    // Choose parity type
    printf("Choose Parity Type (0 for Even, 1 for Odd): ");
    scanf("%d", &parityType);

    // Generate parity
    parityBit = generateParity(data, parityType);
    printf("Generated Parity Bit: %d\n", parityBit);

    // Append parity bit to data
    int transmittedData = (data * 10) + parityBit;
    printf("Transmitted Data (with parity bit): %d\n", transmittedData);

    // Simulating Receiver Side
    printf("\nEnter Received Data (including parity bit): ");
    scanf("%d", &receivedData);

    // Check if received data has correct parity
    if (checkParity(receivedData, parityType))
        printf("Parity Check: Data is correct (No error detected).\n");
    else
        printf("Parity Check: Error detected in received data!\n");

    return 0;
}

// Function to generate parity bit
int generateParity(int data, int parityType) {
    int count = 0, temp = data;

    while (temp) {
        count += temp % 10; // Count 1s
        temp /= 10;
    }

    return (parityType == 0) ? (count % 2 == 0 ? 0 : 1) : (count % 2 == 0 ? 1 : 0);
}

// Function to check parity
int checkParity(int receivedData, int parityType) {
    return generateParity(receivedData / 10, parityType) == (receivedData % 10);
}

