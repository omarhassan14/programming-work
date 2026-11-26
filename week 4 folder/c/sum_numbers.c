#include <stdio.h>
int main(void){int n; long long sum=0; printf("Enter a positive number (N): "); if(scanf("%d",&n)!=1||n<=0){printf("Invalid input.\n");return 1;} for(int i=1;i<=n;i++) sum+=i; printf("The sum of numbers from 1 to %d is: %lld\n",n,sum); return 0;}
