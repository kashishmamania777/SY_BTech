#include <stdio.h>
#include <stdint.h>
int i;
void printBinary(uint64_t bits, int numBits) {
    for (i = numBits - 1; i >= 0; i--) {
        uint64_t mask = 1ULL << i;
        putchar((bits & mask) ? '1' : '0');
    }
}

typedef union {
    double value;
    uint64_t bits;
    struct {
        uint64_t fraction : 52;
        uint64_t exponent : 11;
        uint64_t sign : 1;
    } parts;
} DoubleUnion;

int main() {
    DoubleUnion du;

    printf("Enter a double-precision floating-point number: ");
    scanf("%lf", &du.value);

    printf("Binary representation: ");
    printBinary(du.parts.sign, 1);
    printf(" ");
    printBinary(du.parts.exponent, 11);
    printf(" ");
    printBinary(du.parts.fraction, 52);
    printf("\n");
    return 0;
}
