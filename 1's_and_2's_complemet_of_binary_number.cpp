#include <stdio.h>
#include <string.h>

void onesComplement(char bin[]) {
    for (int i = 0; bin[i] != '\0'; i++) {
        bin[i] = (bin[i] == '0') ? '1' : '0'; // Flip bits
    }
}

void twosComplement(char bin[]) {
    int carry = 1;
    for (int i = strlen(bin) - 1; i >= 0; i--) {
        if (bin[i] == '1' && carry == 1) {
            bin[i] = '0'; // 1 + 1 = 10 (0 remains, carry=1)
        } else if (bin[i] == '0' && carry == 1) {
            bin[i] = '1'; // 0 + 1 = 1 (carry becomes 0)
            carry = 0;
        }
    }
}

int main() {
    char bin[20];

    printf("Enter a binary number: ");
    scanf("%s", bin);

    // Compute 1's complement
    char onesComp[20];
    strcpy(onesComp, bin);
    onesComplement(onesComp);
    printf("1's Complement: %s\n", onesComp);

    // Compute 2's complement
    twosComplement(onesComp); // Reuse onesComp for 2's complement
    printf("2's Complement: %s\n", onesComp);

    return 0;
}
