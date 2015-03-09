#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 4096

void get_input(char * buffer);
int compare(char * string1, char * string2);

int main(int argc, char * argv[]) {
    char string1[BUF_SIZE];
    char string2[BUF_SIZE];
    int count;

    if(argc != 3) {
        printf("Hello!\n");
        printf("Please enter your first string: ");
        get_input(string1);

        printf("Please enter your second string: ");
        get_input(string2);

        count = compare(string1, string2);
    }
    else {
        count = compare(argv[1], argv[2]);
    }

    printf("Result: %i\n", count);

    return EXIT_SUCCESS;
}

int compare(char * string1, char * string2) {
    int i, j;
    int size1 = (unsigned) strlen(string1);
    int size2 = (unsigned) strlen(string2);
    int count = 0;

    for(i = 0; i < size1; i++) {
        for(j = 0; j < size2; j++) {
            if(string1[i] == string2[j]) {
                count++;
            }
        }
    };
    return count;
}

void get_input(char * buffer) {
    unsigned len;

    if(fgets(buffer, BUF_SIZE, stdin) == NULL) {
        printf("Error reading stdin into buffer");
        exit(EXIT_SUCCESS);
    }

    len = (unsigned) strlen(buffer);
    buffer[len - 1] = '\0'; // For newline
}
