q2
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 512

int main() {
    char paragraph[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    printf("Enter a paragraph (press Ctrl+D or Ctrl+Z to finish):\n");

    // Read the paragraph
    while (word_count < MAX_WORDS && scanf("%s", paragraph[word_count]) != EOF) {
        // Convert each word to lowercase
        for (int i = 0; i < strlen(paragraph[word_count]); ++i) {
            paragraph[word_count][i] = tolower(paragraph[word_count][i]);
        }
        word_count++;
    }

    // Calculate word frequencies
    int frequencies[MAX_WORDS] = {0};
    for (int i = 0; i < word_count; ++i) {
        if (strlen(paragraph[i]) > 0) {
            frequencies[i]++;
            for (int j = i + 1; j < word_count; ++j) {
                if (strcmp(paragraph[i], paragraph[j]) == 0) {
                    frequencies[i]++;
                    paragraph[j][0] = '\0'; // Mark duplicate words as empty
                }
            }
        }
    }

    // Print word frequencies
    printf("\nWord frequencies:\n");
    for (int i = 0; i < word_count; ++i) {
        if (strlen(paragraph[i]) > 0) {
            printf("%s: %d\n", paragraph[i], frequencies[i]);
        }
    }

    return 0;
}
