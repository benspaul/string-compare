#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 16384

void get_input(char * buffer);
int compare(char * string1, char * string2);

int main(int argc, char * argv[]) {
    char string1[BUF_SIZE];
    char string2[BUF_SIZE];
    int count;

    // If no command line args were given, prompt the user for strings:
    if(argc != 3) {
        printf("Hello!\n");
        printf("Please enter your first string: ");
        get_input(string1);

        printf("Please enter your second string: ");
        get_input(string2);

        count = compare(string1, string2);
    }
    // Else, use the command line args:
    else {
        count = compare(argv[1], argv[2]);
    }

    printf("Result: %i\n", count);

    return EXIT_SUCCESS;
}

/*
 *  This is the actual compare method.
 *  It takes two strings, and returns the number
 *  of matching characters between them.
 */
int compare(char * string1, char * string2) {
    int i, j;
    int count = 0;

    // Iterate through all characters in first string:
    for(i = 0; string1[i] != '\0'; i++) {

        // And for each character int the second string:
        for(j = 0; string2[j] != '\0'; j++) {

            // If they match, increment the counter:
            if(string1[i] == string2[j]) {
                count++;
            }
        }
    };
    return count;
}

/*
 * This method simply gets some input from stdin
 * and stores it in the given buffer.  Removes
 * the trailing newline.
 */
void get_input(char * buffer) {
    unsigned len;

    if(fgets(buffer, BUF_SIZE, stdin) == NULL) {
        printf("Error reading stdin into buffer");
        exit(EXIT_SUCCESS);
    }

    len = (unsigned) strlen(buffer);
    buffer[len - 1] = '\0'; // For newline
}
