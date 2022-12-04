#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// rock = A, paper = B, scissors = C
// rock = X, paper = Y, scissors = Z
// scores of choices:
// rock: 1, paper: 2, scissors: 3

int main() {
    char buff[4];
    int score = 0;

    // for readability:
    char rock = 'A';
    char paper = 'B';
    char scissors = 'C';

    char lose = 'X';
    char draw = 'Y';
    char win = 'Z';


    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 4, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            if (strcmp(buff, "\n")) { // only runs if the line isn't empty/just has newline
                printf("Buff is: %s\n", buff);
                
                if(buff[0] == rock) {
                    if(buff[2] == win) {
                        score += 8; // win 6, paper 2
                    } else if(buff[2] == draw) {
                        score += 4; // draw 3, rock 1
                    } else if(buff[2] == lose) {
                        score += 3; // scissors 3
                    }

                } else if(buff[0] == paper) {
                    if(buff[2] == win) {
                        score += 9; // win 6, scissors 3
                    } else if(buff[2] == draw) {
                        score += 5; // draw 3, paper 2
                    } else if(buff[2] == lose) {
                        score += 1; // rock 1
                    }
                } else if(buff[0] == scissors) {
                    if(buff[2] == win) {
                        score += 7; // win 6, rock 1
                    } else if(buff[2] == draw) {
                        score += 6; // draw 3, scissors 3
                    } else if(buff[2] == lose) {
                        score += 2; // paper 2
                    }
                }
            }
        }
    }
    printf("Score:%d\n", score);
}