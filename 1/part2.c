#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char buff[100];
    int mostCarried[] = {0, 0, 0};
    int total = 0;

    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 100, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            if (strcmp(buff, "\n")) { // check if empty line (return 0 if the same)
                total += atoi(buff); // atoi converts string to int
            } else {
                
                if (total > mostCarried[0]) {
                    mostCarried[2] = mostCarried[1];
                    mostCarried[1] = mostCarried[0];
                    mostCarried[0] = total;
                } else if (total > mostCarried[1]) {
                    mostCarried[2] = mostCarried[1];
                    mostCarried[1] = total;
                } else if (total > mostCarried[2]) {
                    mostCarried[2] = total;
                }
                total = 0;
            }
        }
    }
    
    printf("Top 3 highest calories carried: %d, %d and %d\n", mostCarried[0], mostCarried[1], mostCarried[2]);

    printf("Top 3 highest calories carried combined: %d\n", mostCarried[0]+mostCarried[1]+mostCarried[2]);
}