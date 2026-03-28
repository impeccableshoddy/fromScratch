#include <stdio.h>
#include <stdlib.h>

void get_string(char *c, int size);
void print_header(const char* title);

int count_characters(const char *c);
int count_words(const char *c);
int is_palindrome(const char *c);

const char* reverse_string(const char *c);
const char* convert_toupper(const char *c);
const char* convert_tolower(const char *c);

int main(void) {

    int choice;
    char s[101];

    do {

        printf("\nEnter a string: ");
        get_string(s, 101);

        print_header("String Operations");
        printf("\n");
        print_header("[1] Count Characters");
        printf("The no. of characters in the string is %d\n\n", count_characters(s));

        print_header("[2] Count words");
        printf("The no. of words in your sentence is %d\n\n", count_words(s));

        print_header("[3] Reverse the string");
        const char* reversed = reverse_string(s);
        printf("The reversed string is - %s\n\n", reversed);
        free((char*) reversed);

        print_header("[4] Check if Palindrome");
        printf("Is it a palindrome? %s\n\n", is_palindrome(s) ? "Yes" : "No" );

        print_header("[5] Convert to Uppercase");
        const char* uppercase = convert_toupper(s);
        printf("Your string in Uppercase - %s\n\n", uppercase);
        free((char*) uppercase);

        print_header("[6] Convert to Lowercase");
        const char* lowercase = convert_tolower(s);
        printf("Your string in Lowercase - %s\n\n", lowercase);
        free((char*) lowercase);

        print_header("[7] Exit");
        printf("Enter 1 to continue, 0 to exit: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

    } while (choice != 0);

    return 0;
}

void print_header(const char* title) {

    int len = count_characters(title), total = 50;
    int side = (total - len - 2) / 2;

    printf("%*s %s %*s\n", side, "", title, side, "");
    for(int i = 0; i < total; i++) printf("-"); printf("\n");

}

void get_string(char *c, int size) {

    while(fgets(c, size, stdin) == NULL)
        printf("Error. Please try again: ");
    printf("\n");

    size_t len = count_characters(c);
    if ( len > 0 && c[len - 1] == '\n') c[len - 1] = '\0';
    else {
        int clear;
        while((clear = getchar()) != '\n' && clear != EOF);
    }

}

int count_characters(const char *c) {
    int len = 0;
    while(c[len]) len++;
    return len;
}

int count_words(const char *c) {

    int count = 0, in_word = 0;

    while (*c) {
        if (*c != ' ' && !in_word) {
            count++;
            in_word = 1;
        } else if (*c == ' ') in_word = 0;
        c++;
    }

    return count;
}

const char* reverse_string(const char *c) {

    size_t size = count_characters(c);
    char* rev = malloc(size + 1);

    for(int i = 0, j = size - 1; i < size && j >= 0; i++, j--) {
        rev[i] = c[j];
    }
    rev[size] = '\0';

    return rev;

}

int is_palindrome(const char* c) {
    size_t len = count_characters(c);

    for(int i = 0, j = len - 1; i < j; i++, j--)
        if (c[i] != c[j]) return 0;

    return 1;
}

const char* convert_toupper(const char *c) {
    size_t size = count_characters(c);
    char *upper = malloc(size + 1);

    for(int i = 0; i < size; i++) {
        if ('a' <= c[i] && c[i] <= 'z') {
            upper[i] = c[i];
            upper[i] -= 32;
        } else upper[i] = c[i];
    }
    upper[size] = '\0';

    return upper;
}

const char* convert_tolower(const char *c) {
    size_t size = count_characters(c);
    char *lower = malloc(size + 1);

    for(int i = 0; i < size; i++) {
        if ('A' <= c[i] && c[i] <= 'Z') {
            lower[i] = c[i];
            lower[i] += 32;
        } else lower[i] = c[i];
    }
    lower[size] = '\0';

    return lower;
}