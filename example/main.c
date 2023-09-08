#include <stdio.h> 
#include <stdbool.h> 

bool is_negative(int* num) {
    if (*num < 0) {
        *num *= -1;
        return true;
    }
    return false;
}

int is_null(int); //prototype

int main() {
    int input = 0, zero = 0, output = 0;
    bool negative = false;

    printf("Enter a number: ");
    // check input value
    int ret = scanf("%d", &input);
    if (ret != 1) {
        printf("Error input \n");
        return -1;
    }
   
    zero = is_null(input);
    negative = is_negative(&input);

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
    if (negative == true) // if (negative)
        output *= -1; 

    printf("Zero = %i\n", zero);
    printf("Output = %d\n", output);
    return 0;
}


int is_null(int num) {
    if (num == 0)
        return 1;
    else
        return 0;
}

