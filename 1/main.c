#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char buff[100];
    int mostCarried = 0;
    int total = 0;

    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 100, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            if (strcmp(buff, "\n")) { // check if empty line (return 0 if the same)
                total += atoi(buff); // atoi converts string to int
                printf("Total = %d\n", total);
            } else {
                if (total > mostCarried) {
                    mostCarried = total;
                    total = 0;
                    printf("end\n");
                }
            }
        }
    }

    printf("Highest calories carried: %d\n", mostCarried);
}