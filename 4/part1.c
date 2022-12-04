#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int arrayToNum(int arr[], int size) {
    int num;
    char charArr[3];

    for(int i = 0; i < size; i++) {
        charArr[i] = arr[i];
    }
    num = atoi(charArr);
    return num;
} 


int main() {
    char buff[50];
    //char *dashp1;
    //char *dashp2;
    int buffSize;
    int number1[3] = {-1};
    int number2[3] = {-1};
    int number3[3] = {-1};
    int number4[3] = {-1};
    int onNo2 = 0;
    int onNo3 = 0;
    int onNo4 = 0;

    int counter = 0;

    FILE * fp; // fp is a pointer to the file
    fp = fopen("input.txt", "r");

    if (fp != NULL) {
        while(fgets(buff, 50, fp) != NULL) { // iterates through file - pointers can be null, ints can't
            // dashp1 = strchr(buff, '-'); gets first occurence of dash
            // dashp2 = strrchr(buff, '-'); gets second occurence of dash
            int onNo2 = 0;
            int onNo3 = 0;
            int onNo4 = 0;

            buffSize = strlen(buff);
            int index = 0;

            for(int i = 0; i < buffSize; i++) { // sorts numbers into correct array.
                printf("Buff: %s\n", buff);
                if(!onNo2) {
                    if(buff[i] != '-') {
                        number1[index] = buff[i];
                        index++;
                    } else {
                        onNo2 = 1;
                        index = 0;
                    }
                } else if(!onNo3) {
                    if(buff[i] != ',') {
                        number2[index] = buff[i];
                        index++;
                    } else {
                        onNo3 = 1;
                        index = 0;
                    }
                } else if (!onNo4) {
                    if(buff[i] != '-') {
                        number3[index] = buff[i];
                        index++;
                    } else {
                        onNo4 = 1;
                        index = 0;
                    }
                } else {
                    if(buff[i] != '\n') {
                        number4[index] = buff[i]; // minus 48??
                        index++;
                    }
                }
            }
            int arrSize1 = sizeof(number1)/sizeof(number1[0]);
            int arrSize2 = sizeof(number2)/sizeof(number2[0]);
            int arrSize3 = sizeof(number3)/sizeof(number3[0]);
            int arrSize4 = sizeof(number4)/sizeof(number4[0]);


            int num1 = arrayToNum(number1, arrSize1);
            int num2 = arrayToNum(number2, arrSize2);
            int num3 = arrayToNum(number3, arrSize3);
            int num4 = arrayToNum(number4, arrSize4);

            printf("check %d, %d, %d, %d\n", num1, num2, num3, num4);

            int lower1;
            int higher1;
            int lower2;
            int higher2;

            // ordering numbers to make if statements easier
            if(num1<num2) {
                lower1 = num1;
                higher1 = num2;
            } else if(num1>num2) {
                lower1 = num2;
                higher1 = num1;
            }

            if(num3<num4) {
                lower2 = num3;
                higher2 = num4;
            } else if(num3>num4) {
                lower2 = num4;
                higher2 = num3;
            }

            printf("Counter up maybe?: %d-%d, %d-%d\n", lower1, higher1, lower2, higher2);
            if(lower1<=lower2 && higher1>=higher2) {
                counter++;
                printf("Counter up: %d-%d, %d-%d\n", lower1, higher1, lower2, higher2);
            } else if (lower2<=lower1 && higher2>=higher1) {
                counter++;
                printf("Counter up: %d-%d, %d-%d\n", lower1, higher1, lower2, higher2);
            }
        }
    }
    printf("%d\n", counter);
}