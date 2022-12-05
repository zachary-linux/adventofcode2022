#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
    char buff[50];

    char num1arr[3];
    char num2arr[3];
    char num3arr[3];
    char num4arr[3];

    char *dashp1;
    char *dashp2;
    char *commap;
    char *nlp;

    int num1;
    int num2;
    int num3;
    int num4;

    int overlap = 0;

    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 50, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            dashp1 = strchr(buff, '-'); //gets address of first dash dash
            dashp2 = strrchr(buff, '-'); //gets address of second dash
            commap = strchr(buff, ','); // gets address of comma
            nlp = strchr(buff, '\n'); // gets address of newline
            
            // format: arg1 is destination, arg2 is start, arg3 is end
            strncpy(num1arr,buff,dashp1-buff); // dashp1 points to first dash, buff points to start of line
            num1arr[dashp1-buff] = '\0';

            strncpy(num2arr,dashp1+1,commap-dashp1-1); // this one starts at the char after the one the pointer is pointing to
            num2arr[commap-dashp1 -1] = '\0';

            strncpy(num3arr,commap+1,dashp2-commap-1); // starts at comma, ends at second dash
            num3arr[dashp2-commap -1] = '\0';

            strncpy(num4arr,dashp2+1,nlp-dashp2-1); // starts at second dash, ends at newline
            num4arr[nlp-dashp2 -1] = '\0';
            // obviously the dashes/newlines weren't included

            // printf("char: %s %s %s %s\n", num1arr, num2arr, num3arr, num4arr);
            
            num1 = atoi(num1arr);
            num2 = atoi(num2arr);
            num3 = atoi(num3arr);
            num4 = atoi(num4arr);

            // printf("int: %d %d %d %d\n", num1, num2, num3, num4);

            // putting nums in order to make if statements easier:
            int temp;
            if(num2<num1) {
                temp = num1;
                num1 = num2;
                num2 = temp;
            }
            if(num4<num3) {
                temp = num3;
                num3 = num4;
                num4 = temp;
            }

            // checking if the sets overlap
            if(num1 <= num4 && num3 <=num2) { // if first set is bigger than second with no overlap
                // printf("Sets overlap?: %d-%d, %d-%d\n", num1, num2, num3, num4);
                overlap++;
            }
        }
    }
    printf("%d\n", overlap);
}