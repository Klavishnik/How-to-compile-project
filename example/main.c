#include <stdio.h> 
#include <stdbool.h> 

bool isNegative(int* num) {
    if (*num < 0) {
        *num *= -1;
        return true;
    }
    return false;
}

int isNull(int num);

int main() {
    int input, zero = 0, output = 0;
    bool negative = false;

    printf("Enter a number: ");
    scanf("%d", &input);
   
    zero = isNull(input);
    negative = isNegative(&input);

    int mult = 1;
    while (input > 0) {
        if (input % 10 == 0 ) {
            zero++;
        }
        else {
            output += input % 10 * mult;
            mult *= 10; 
        }

        input = input / 10;
    }
    if (negative == true)
        output += -1; 

    printf("Zero= %i\n", zero);
    printf("Output dd= %i\n", output);
    return 0;
}


int isNull(int num) {
    if (num == 0)
        return 1;
    else
        return 0;
}

