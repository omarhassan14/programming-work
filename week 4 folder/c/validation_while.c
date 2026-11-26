#include <stdio.h>
int main(void){int number; printf("Enter a positive number: "); if(scanf("%d",&number)!=1){printf("Invalid input.\n");return 1;} while(number<=0){printf("Invalid! Please enter a positive number: "); if(scanf("%d",&number)!=1){printf("Invalid input.\n");return 1;}} printf("You entered: %d\n",number);return 0;}
