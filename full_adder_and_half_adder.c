#include <stdio.h>

// Function prototypes
void halfAdder(int, int);
void fullAdder(int, int, int);

int main() {
    int A, B, Cin;

    // Half Adder
    printf("Enter two binary inputs for Half Adder (0 or 1): ");
    scanf("%d %d", &A, &B);
    halfAdder(A, B);

    // Full Adder
    printf("\nEnter three binary inputs for Full Adder (A B Cin): ");
    scanf("%d %d %d", &A, &B, &Cin);
    fullAdder(A, B, Cin);

    return 0;
}

// Function for Half Adder
void halfAdder(int A, int B) {
    int Sum = A ^ B;   // XOR for sum
    int Carry = A & B; // AND for carry
    printf("Half Adder Output -> Sum: %d, Carry: %d\n", Sum, Carry);
}

// Function for Full Adder
void fullAdder(int A, int B, int Cin) {
    int Sum = A ^ B ^ Cin;            // XOR for sum
    int Carry = (A & B) | (Cin & (A ^ B)); // Carry logic
    printf("Full Adder Output -> Sum: %d, Carry: %d\n", Sum, Carry);
}

