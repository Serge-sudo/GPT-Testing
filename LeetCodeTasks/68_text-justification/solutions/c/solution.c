#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    // Calculate number of lines needed to hold the formatted text
    int numLines = 0, currentWidth = 0, count = 0;
    for (int i = 0; i < wordsSize; i++) {
        int wordLen = strlen(words[i]);
        if (currentWidth + wordLen + count > maxWidth) {
            numLines++;
            currentWidth = 0;
            count = 0;
        }
        currentWidth += wordLen;
        count++;
    }
    numLines++;

    // Allocate memory for the result
    char** result = (char**)malloc(sizeof(char*) * numLines);
    *returnSize = numLines;

    int lineIndex = 0, wordIndex = 0;
    while (wordIndex < wordsSize) {
        // Start a new line
        int lineWidth = 0, numWordsInLine = 0, lineStart = wordIndex;
        while (wordIndex < wordsSize && lineWidth + strlen(words[wordIndex]) + numWordsInLine <= maxWidth) {
            lineWidth += strlen(words[wordIndex]);
            numWordsInLine++;
            wordIndex++;
        }

        // Create the line with even spaces
        result[lineIndex] = (char*)malloc(sizeof(char) * (maxWidth + 1));
        int spaceWidth = maxWidth - lineWidth;
        int gaps = numWordsInLine - 1;
        char* currentLine = result[lineIndex];

        if (gaps == 0 || wordIndex == wordsSize) { // Last line or line with one word
            currentLine[0] = '\0';
            for (int j = lineStart; j < wordIndex; j++) {
                strcat(currentLine, words[j]);
                if (j < wordIndex - 1) strcat(currentLine, " ");
            }
            int tailSpaces = maxWidth - strlen(currentLine);
            memset(currentLine + strlen(currentLine), ' ', tailSpaces);
            currentLine[maxWidth] = '\0';
        } else {
            int evenSpaces = spaceWidth / gaps;
            int extraSpaces = spaceWidth % gaps;
            int offset = 0;
            for (int j = lineStart; j < wordIndex; j++) {
                strcpy(currentLine + offset, words[j]);
                offset += strlen(words[j]);
                if (j < wordIndex - 1) {
                    int spaces = evenSpaces + (j - lineStart < extraSpaces ? 1 : 0);
                    memset(currentLine + offset, ' ', spaces);
                    offset += spaces;
                }
            }
            currentLine[maxWidth] = '\0';
        }
        lineIndex++;
    }

    return result;
}
