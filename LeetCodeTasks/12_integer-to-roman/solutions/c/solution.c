#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
    char* roman = malloc(sizeof(char) * 20);
    int pos = 0;

    while (num > 0) {
        if (num >= 1000) {
            roman[pos++] = 'M';
            num -= 1000;
        } else if (num >= 900) {
            roman[pos++] = 'C';
            roman[pos++] = 'M';
            num -= 900;
        } else if (num >= 500) {
            roman[pos++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            roman[pos++] = 'C';
            roman[pos++] = 'D';
            num -= 400;
        } else if (num >= 100) {
            roman[pos++] = 'C';
            num -= 100;
        } else if (num >= 90) {
            roman[pos++] = 'X';
            roman[pos++] = 'C';
            num -= 90;
        } else if (num >= 50) {
            roman[pos++] = 'L';
            num -= 50;
        } else if (num >= 40) {
            roman[pos++] = 'X';
            roman[pos++] = 'L';
            num -= 40;
        } else if (num >= 10) {
            roman[pos++] = 'X';
            num -= 10;
        } else if (num >= 9) {
            roman[pos++] = 'I';
            roman[pos++] = 'X';
            num -= 9;
        } else if (num >= 5) {
            roman[pos++] = 'V';
            num -= 5;
        } else if (num >= 4) {
            roman[pos++] = 'I';
            roman[pos++] = 'V';
            num -= 4;
        } else {
            roman[pos++] = 'I';
            num -= 1;
        }
    }

    roman[pos] = '\0';
    return roman;
}
