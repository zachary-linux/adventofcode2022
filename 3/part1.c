#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
    char buff[50];
    int inLower[25]; // storing letters as their ascii codes
    int inUpper[25];
    int toRm;

    // assigning to inLower
    for(int i = 0; i < 26; i++) {
        inLower[i] = 97 + i; // 97 is ascii for 'a'
    }
    // assigning to inUpper
    for(int i = 0; i < 26; i++) {
        inUpper[i] = 65 + i; // 65 is ascii for 'A'
    }

    int size;
    int half;
    int isIn = 0;
    int score = 0;

    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 50, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            // get buff's length to calculate where to half it
            size = strlen(buff) - 1;
            half = size/2;
            printf("%s", buff);
            printf("%d, %d\n\n", size, half);
            // this for loop checks if characters in the first half of buff are also in the second half
            for(int i = 0; i < half; i++) {
                for(int j = half; j < size; j++) {
                    if(buff[i] == buff[j]) {
                        isIn = 1;
                        printf("%c is equal to %c\n", buff[i], buff[j]);
                        buff[j] = '@'; // stops two letters from seeing the same letter as equal
                    }
                }
                if(isIn) { // if a character is found:
                    printf("%c is in the buff\n", buff[i]);
                    if(islower(buff[i])) {
                        score += buff[i] - 96;
                    } else if(isupper(buff[i])) {
                        score += buff[i] - 38;
                    }
                }
                isIn = 0;
            }
        }
    }
    printf("%d\n", score);
}