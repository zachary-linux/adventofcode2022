#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// compares 3 strings and returns the only common char
char compStrings(char a[], int lena, char b[], int lenb, char c[], int lenc) {
    
    char compInt[100] = {'@'};
    int compIntIndex = 0;
    int lencomp;
    char returnvar;

    // comparing a with b.
    for(int i = 0; i < lena - 2; i++) {
        for(int j = 0; j < lenb - 2; j++) {
            if(a[i] == b[j]) {
                compInt[compIntIndex] = a[i];
                compIntIndex++;
            } 
        }
    }

    lencomp = strlen(compInt);
    for(int i = 0; i < lencomp - 1; i++) {
        for(int j = 0; j < lenc - 1; j++) {
            if(compInt[i] == c[j]) {
                returnvar = compInt[i];
            }
        }
    }
    return returnvar;
}


int main() {
    char buff[50];
    char inLower[25]; // storing letters as their ascii codes
    char inUpper[25];
    char allCharVar[100];

    int len;
    int len2;
    int half;
    int check = 0;
    int index;

    // assigning to inLower
    for(int i = 0; i < 26; i++) {
        inLower[i] = 97 + i; // 97 is ascii for 'a'
    }
    // assigning to inUpper
    for(int i = 0; i < 26; i++) {
        inUpper[i] = 65 + i; // 65 is ascii for 'A'
    }

    strcat(inLower, inUpper);
    strcpy(allCharVar, inLower);

    char buffcpy1[30];
    char buffcpy2[30];
    char buffcpy3[30];

    int lena;
    int lenb;
    int lenc;

    int counter = 0;
    char charForPriCheck;
    int priScore = 0;


    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 50, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            if(counter == 0) {
                buff[strlen(buff) - 1] = '!';
                strcpy(buffcpy1, buff);
                lena = strlen(buffcpy1);
                counter++;
            } else if(counter == 1) {
                buff[strlen(buff) - 1] = '!';
                strcpy(buffcpy2, buff);
                lenb = strlen(buffcpy2);
                counter++;
            } else if(counter == 2) {
                buff[strlen(buff) - 1] = '!';
                strcpy(buffcpy3, buff);
                lenc = strlen(buffcpy3);
                charForPriCheck = compStrings(buffcpy1, lena, buffcpy2, lenb, buffcpy3, lenc);
                printf("char for pri check: %c\n", charForPriCheck);
                printf("buffs: 1: %s\n2: %s\n3: %s\n", buffcpy1, buffcpy2, buffcpy3);
                counter = 0;

                if(islower(charForPriCheck)) {
                    priScore += charForPriCheck - 96;
                    printf("The letter is %c and the score added is %d (lower)\n", charForPriCheck, charForPriCheck - 96);
                } else if(isupper(charForPriCheck)) {
                    priScore += charForPriCheck - 38;
                    printf("The letter is %c and the score added is %d (upper)\n", charForPriCheck, charForPriCheck - 38);
                }
            }
        }
    }
    printf("%d\n", priScore);
}