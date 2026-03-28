#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int_in_range(int *output, int min, int max) {

    char buffer[64];
    char *endptr;
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0;

    char *newline = strchr(buffer, '\n');
    if (newline == NULL) {

        int temp;
        while ((temp = getchar()) != '\n' && temp != EOF);

    } else *newline = '\0';

    if (buffer[0] == '\0') {
        printf("!! Error: You didn't type anything.\n");
        return 0;
    }

    long val = strtol(buffer, &endptr, 10);

    if (endptr == buffer) {
        printf("!! Error: '%s' is not a number.\n", buffer);
        return 0;
    }

    if (val < min || val > max) {
        printf("Error: Number must be between %d and %d.\n", min, max);
        return 0;
    }

    *output = (int)val;
    return 1;

}

int main(void) {

    int n;
    printf("Enter a number (between 1 to 100): ");

    if (get_int_in_range(&n, 1, 100)) {
        
        printf("\nMultiplication of table of number %d.\n", n);
        for (int i = 1; i <= 10; i++ )
        printf("%d x %d = %d \n", n, i, n*i);

        printf("\nLeft aligned traingle of height %d.\n", n);
        for (int j=1; j <= n; j++) {
            for (int k=1; k <=j; k++) printf("*");
            printf("\n");
        }

    } else {
        printf("That didn't work. Try again.\n");
    }

    return 0;

}