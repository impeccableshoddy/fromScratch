#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_text_input(char *buffer, int size) {
    
    if (fgets(buffer, size, stdin)) {

        char *newline = strchr(buffer, '\n');
        if (newline) *newline = '\0';
        else {

            int temp;
            while ((temp = getchar()) != '\n' && temp != EOF);

        }

    }

}

int get_int_input(int min, int max, int *output) {

    char temp_buf[64];
    char *endptr;

    get_text_input(temp_buf, sizeof(temp_buf));
    long val = strtol(temp_buf, &endptr, 10);

    if (endptr == temp_buf || *endptr != '\0') {

        printf("Error: %s is a not a number!\n", temp_buf);
        return 0;

    }    

    if ( val < min || val > max) {
        
        printf("Eror: Please enter number between %d and %d.\n", min, max);
        return 0;

    }

    *output = (int)val;
    
    return 1;

}

void collect_data(char **names, int *grades, int count) {

    printf("\n--- Data Collection ---\n");
    for (int i = 0; i < count; i++) {

        printf("\n Student %d enter your name: ", i+1);
        get_text_input(names[i], 30);

        while (1) {

            printf("\n Enter student's grade: ");
            if (get_int_input(0, 100, &grades[i])) break;

        }

    }

}

void analyze_data(int *grades, int count, int *hi, int *low, float *avg) {

    int sum = 0;
    *hi = 0, *low = 0;

    for (int i = 0; i < count; i++) {

        sum += grades[i];

        if (grades[i] > grades[*hi]) *hi = i;

        if (grades[i] < grades[*low]) *low = i;
        
    }

    *avg = (float) sum/count;

}

void display_report(char **names, int *grades, int count, int hi, int low, float avg) {

    printf("\n================ STUDENT REPORT ================\n");
    printf("%-20s | %-10s | %-10s\n", "Name", "Grade", "Result");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) {

        printf("%-20s | %-10d | %-10s\n", 
               names[i], 
               grades[i], 
               (grades[i] >= 40) ? "PASS" : "FAIL");

    }

    printf("--------------------------------------------------\n");
    printf("Average Score:      %.2f\n", avg);
    printf("Top Student:    %s      (%d)\n", names[hi], grades[hi]);
    printf("Needs Help:    %s       (%d)\n", names[low], grades[low]);
    printf("================================================\n");

}

int main(void) {

    int choice = 1;

    do {
        
        int count, highest_idx, lowest_idx;
        float average;

        printf("\nWelcome to Student Grade tracker\n");
        printf("\n----------------------------------------\n");
        printf("\nEnter the count of students(2 - 10): ");
        if (!get_int_input(2, 10, &count)) continue;

        int *grades = malloc(count * sizeof(int));
        char **names = malloc(count * sizeof(char *));

        if (!grades || !names) {
            printf("Memory allocation failed.\n");
            break;
        }

        for (int i = 0; i < count; i++)
            names[i] = malloc(30 * sizeof(char));
        
        collect_data(names, grades, count);
        analyze_data(grades, count, &highest_idx, &lowest_idx, &average);
        display_report(names, grades, count, highest_idx, lowest_idx, average);

        for (int i = 0; i < count; i++) free(names[i]);
        
        free(grades);
        free(names);
        
        printf("\n----------------------------------------\n");
        printf(" [1] Stop and Exit\n");
        printf(" [Anything else] to Analyze another number\n");
        printf(" Choice: ");

        choice = getchar();

        while (getchar() != '\n');

        if (choice == '1') break;

    } while (choice != '1');

    return 0;

}