#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void printMissingLetters(const char* sentence) {
    int letterCount[ALPHABET_SIZE] = {0};
    char missingLetters[ALPHABET_SIZE] = "";
    int missingLettersCount = 0;

    printf("::: %s\n", sentence);
    for (int i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            char lowercaseChar = tolower(sentence[i]);
            letterCount[lowercaseChar - 'a']++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (letterCount[i] == 0) {
            missingLetters[missingLettersCount++] = 'a' + i;
        }
    }

    if (missingLettersCount == 0) {
        printf("NULL\n");
    } else {
        missingLetters[missingLettersCount] = '\0';
        printf("%s\n", missingLetters);
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    if (strlen(sentence) > 0 && sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';  // remove the newline character
    }
    printf(":: %s\n", sentence);
    printMissingLetters(sentence);

    return 0;
}
