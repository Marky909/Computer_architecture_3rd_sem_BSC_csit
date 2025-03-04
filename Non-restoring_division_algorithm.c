/* C Program For Implementation Of Non - Restoring Division */

#include <stdio.h>

int a[5] = {0, 0, 0, 0, 0}, q[5], b[5], b2c[5]; // Adjust size of q array to match loop count

void comp();
void nonresdiv();
void shiftleft();
void a_minus_b();
void a_plus_b();

int main()
{
    printf("Enter dividend in binary form: ");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &q[i]);
    }
    q[4] = 0; // Ensure extra bit for binary operations

    printf("Enter divisor in binary form: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &b[i]);
    }

    comp();

    printf("\n\t[A]\t[M]\n");
    for (int i = 0; i < 4; i++)
    {
        nonresdiv();
        printf("\t");

        for (int j = 0; j < 5; j++)
        {
            printf("%d", a[j]);
        }

        printf("\t");
        for (int k = 0; k < 4; k++)
        {
            printf("%d", q[k]);
        }
        printf("\n");
    }

    if (a[0] == 1)
    {
        a_plus_b();
    }
    printf("\t");

    for (int j = 0; j < 5; j++)
    {
        printf("%d", a[j]);
    }
    printf("\t");

    for (int k = 0; k < 4; k++)
    {
        printf("%d", q[k]);
    }
    printf("\n");

    printf("\n\tThe Quotient is:\t");
    for (int k = 0; k < 4; k++)
    {
        printf("%d", q[k]);
    }

    printf("\n\tThe Remainder is:\t");
    for (int j = 0; j < 5; j++)
    {
        printf("%d", a[j]);
    }

    return 0;
}

void comp()
{
    int i = 4;
    do
    {
        b2c[i] = b[i];
        i--;
    } while (i >= 0 && b[i + 1] != 1);
    while (i >= 0)
    {
        b2c[i] = (b[i] + 1) % 2;
        i--;
    }
    printf("\n\tB's complement:");
    for (i = 0; i < 5; i++)
        printf("%d", b2c[i]);
    printf("\n");
}

void nonresdiv()
{
    shiftleft();
    if (a[0] == 0)
        a_minus_b();
    else
        a_plus_b();
    q[4] = (a[0] + 1) % 2; // Use the 5th bit to store quotient information
}

void shiftleft()
{
    int i;
    for (i = 0; i < 4; i++)
        a[i] = a[i + 1];
    a[4] = q[0];
    for (i = 0; i < 4; i++)
        q[i] = q[i + 1];
}

void a_minus_b()
{
    int i, carry = 0, sum = 0;
    for (i = 4; i >= 0; i--)
    {
        sum = (a[i] + b2c[i] + carry);
        a[i] = sum % 2;
        carry = sum / 2;
    }
}

void a_plus_b()
{
    int i, carry = 0, sum = 0;
    for (i = 4; i >= 0; i--)
    {
        sum = (a[i] + b[i] + carry);
        a[i] = sum % 2;
        carry = sum / 2;
    }
}
