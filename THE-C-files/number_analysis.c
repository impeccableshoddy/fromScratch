#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int_in_range(int *output, int min, int max) {

    char buffer[64];
    char *endptr;

    if ((fgets(buffer, sizeof(buffer), stdin)) == NULL) {

        printf("Delivery failed!\n");
        return 0;
        
    }

    char *newline = strchr(buffer, '\n');
    if (newline == NULL) {

        int temp;
        while((temp = getchar()) != '\n' && temp != EOF);
        
    } else *newline = '\0';

    if (buffer[0] == '\0') {

        printf("You didn't type anything!\n");
        return 0;

    }

    long val = strtol(buffer, &endptr, 10);

    if (endptr == buffer) {

        printf("Error: %s is a not a number!\n", buffer);
        return 0;

    }

    if (val < min || val > max) {

        printf("Eror: Please enter number between %d and %d.\n", min, max);
        return 0;

    }

    *output = (int)val;

    return 1;

}

char* reverse_number(int n) {

    //Reversed Section:
    // My initial approach was - for(int temp_n = n; temp_n>0; printf("%d", temp_n % 10), temp_n /= 10 );
    char *rev_bus = malloc(12 * sizeof(char)); 
    if (rev_bus == NULL) return NULL;
    
    int temp_n = n;
    int count = 0;

    do {

        int digit = temp_n % 10;
        
        if (count < 11) {
            rev_bus[count] = (char)(digit + '0');
            count++;
        }
        
        temp_n /= 10;

    } while (temp_n > 0); //This approach handles edge case of n = 0;

    rev_bus[count] = '\0';

    return rev_bus;

}

int is_palindrome(int n) {

    // Palindrome Section:

    /*
    Mathematical Approach -
    for (long reversed_n = 0; temp_n>0; reversed_n = (reversed_n * 10) + (temp_n % 10), temp_n /= 10);
    */

    char rev[64];
    snprintf(rev, sizeof(rev), "%d", n);
    int len = strlen(rev);
    int is_palindrome = 1;

    for (int i = 0; i < len / 2 ; i++)
    if (rev[i] != rev[len - i - 1]) {
        is_palindrome = 0;
        break;
    }

    return is_palindrome;

}

int digit_sum(int n) {

    /* Sum Section */
    int sum = 0;
    for (int temp_n = n; temp_n > 0; sum += temp_n % 10, temp_n /= 10);

    return sum;

}

int is_armstrong(int n) {

    /* Armstrong Section */
    int arm_sum = 0;
    for (int temp_n = n; temp_n > 0; temp_n /= 10) {
        
        int digit = temp_n % 10, p = 1;
        for (int temp_c = n; temp_c > 0; temp_c /= 10) p *= digit;
        arm_sum += p;

    }

    return arm_sum == n;

}

void print_report(int n) {

    char *rev = reverse_number(n);
    printf("Reversed:       %s\n", rev);
    free(rev);

    printf("Palindrome:       %s\n", is_palindrome(n) ? "Yes" : "No");
    printf("Digits sum:     %d\n", digit_sum(n));
    printf("Armstrong:      %s\n", is_armstrong(n) ? "Yes" : "No");

}

int main(void) {

    int choice = 0;
    int n;

    do {

        system("clear");

        printf("\nEnter a number between -10000 and 10000: ");

        if (get_int_in_range(&n, -10000, 10000)) {

            int analysis_n = (n < 0) ? -n : n;

            printf("\n=== Number Analysis ===\n");
            printf("Original:       %d\n", n);

            print_report(analysis_n);

        } else {
            
            printf("\nThat didn't work; please try again.\n");

        }

        printf("\n----------------------------------------\n");
        printf(" [1] Stop and Exit\n");
        printf(" [Anything else] to Analyze another number\n");
        printf(" Choice: ");

        choice = getchar();

        while(getchar() != '\n');

        if (choice == '1') break;

    } while (choice != '1');
    
    printf("\nAnalysis complete. Goodbye!\n");
    return 0;

}