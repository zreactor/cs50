#include <readability.h>
#include <stdio.h>

int const MAX_INPUT_LENGTH = 4000;

int main(void) {
    const int *il = &MAX_INPUT_LENGTH; // pointer variable
    int ix = *il; // shallow copy into ix
    char inputStr[*il];

    printf("Text input:  \n");
    fgets(inputStr, ix, stdin);
    readabilityParser(inputStr);
    return 0;
}