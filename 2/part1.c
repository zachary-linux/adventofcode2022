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
    char rockOpponent = 'A';
    char paperOpponent = 'B';
    char scissorsOpponent = 'C';

    char rock = 'X';
    char paper = 'Y';
    char scissors = 'Z';


    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 4, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            if (strcmp(buff, "\n")) { // only runs if the line isn't empty/just has newline
                if(buff[0] == buff[2]) { // checks for draw
                    if(buff[0] == rockOpponent)
                        score += 4; // 3 for draw 1 for rock
                    else if(buff[0] == paperOpponent)
                        score += 5; // 3 for draw 2 for paper
                    else if(buff[0] == scissorsOpponent)
                        score += 6; // 3 for draw 3 for scissors

                } else if(buff[0] == rockOpponent) { // check if rock played by opponent
                    // cases with rock vs paper/scissors
                    if(buff[2] == paper)
                        score += 8; // 6 for win 2 for paper
                    else 
                        score += 4; // 1 for loss 3 for scissors

                } else if(buff[0] == paperOpponent) { // check if paper played by opponent
                    // cases with paper vs scissors/rock
                    if(buff[2] == scissors)
                        score += 9; // 6 for win 3 for scissors
                    else
                        score += 2; // 1 for loss 1 for rock

                } else if(buff[0] == scissorsOpponent) { // check if scissors played by opponent
                    // cases with scissors vs rock/paper
                    if(buff[2] == rock)
                        score += 7; // 6 for win 1 for rock
                    else
                        score += 4; // 1 for loss 3 for scissors
                }
            }
        }
    }

    printf("Score:%d\n", score);
}