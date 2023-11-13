#include <stdio.h>
#include <stdlib.h>
int main(){

    char letter = 'A';
    // B pointer to letter
    char *B = &letter;
    printf("B is %f",B);

    *B = 'C';
    printf("letter is %s", letter);
}