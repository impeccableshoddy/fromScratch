#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_safe_string(char *buffer, int size) {
    fgets(buffer, size, stdin);

    // Checking if we got the whole line or user typed too much
    // If the user types too much, we flush.
    // Otherwise we just strip the \n
    char *newline = strchr(buffer, '\n');
    if (newline == NULL) {
        int temp;
        while ((temp = getchar()) != '\n' && temp != EOF);
    } else *newline = '\0';
}

int get_safe_int(void) {
    char temp_text[10];
    get_safe_string(temp_text, sizeof(temp_text));

    return (int)strtol(temp_text, NULL, 10);
}

int main(void) {
    char name[30];
    int age, current_year, study_year;

    printf("Enter your name: ");
    get_safe_string(name, 30);

    printf("Enter your age: ");
    age = get_safe_int();

    printf("Enter your current year of study: ");
    study_year = get_safe_int();

    printf("Enter current year (ex - 2025, 2026 etc.): ");
    current_year = get_safe_int();

    if (name[0] == '\0') {
        printf("Name can't be Empty!\n");
    } else {
        printf("Hello %s!\n", name);
        if (age <= 0 || current_year <= 0 || study_year <= 0) {
            printf("Field can't be empty!\n");
        } else {
            int total_years_to_graduate = 4;
            int remaining_years = total_years_to_graduate - study_year;
            int graduation = current_year + remaining_years;

            printf("You are %d! and are in year %d.\n", age, study_year);
            printf("You will be graduating in %d.\n", graduation);
        }
    }

    return 0;
}