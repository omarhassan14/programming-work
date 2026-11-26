#include <stdio.h>
int main(void){int number=0; do{printf("Enter a positive number: "); if(scanf("%d",&number)!=1){printf("Invalid input.\n");return 1;} if(number<=0)printf("Invalid! ");}while(number<=0); printf("You entered: %d\n",number);return 0;}
