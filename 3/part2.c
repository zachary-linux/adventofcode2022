#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// compares 3 strings and returns the only common char
char compStrings(char a[], char b[], char c[]) {
    
    // comparing a with b.
    for(int i = 0; a[i]; i++) { // 20
        for(int j = 0; b[j]; j++) {
            for(int k = 0; c[k]; k++) {
                if(a[i] == b[j] && b[j] == c[k]) {
                    return a[i];
                }
            }
        }
    }
}


int main() {
    char buff[50];
    char allCharVar[100];

    int index;

    
    char buffcpy1[50];
    char buffcpy2[50];
    char buffcpy3[50];

    int counter = 0;
    char charForPriCheck;
    int priScore = 0;


    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 50, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            if(counter == 0) {
                buff[strlen(buff) - 1] = '\0';
                strcpy(buffcpy1, buff);
                counter++;
            } else if(counter == 1) {
                buff[strlen(buff) - 1] = '\0';
                strcpy(buffcpy2, buff);
                counter++;
            } else if(counter == 2) {
                buff[strlen(buff) - 1] = '\0';
                strcpy(buffcpy3, buff);
                charForPriCheck = compStrings(buffcpy1, buffcpy2, buffcpy3);
                printf("char for pri check: %c\n", charForPriCheck);
                printf("buffs: 1: %s\n2: %s\n3: %s\n", buffcpy1, buffcpy2, buffcpy3);
                counter = 0;

                if(islower(charForPriCheck)) {
                    priScore += charForPriCheck - 96;
                    printf("The letter is %c and the score added is %d (lower)\n", charForPriCheck, charForPriCheck - 96);
                } else if(isupper(charForPriCheck)) {
                    priScore += charForPriCheck - 38;
                    printf("The letter is %c and the score added is %d (upper)\n", charForPriCheck, charForPriCheck - 38);
                } else {
                    printf("Not char");
                }
            }
        }
    }
    printf("%d\n", priScore);
}