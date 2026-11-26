#include <iostream>
using namespace std;
int main(){int number=0; do{cout<<"Enter a positive number: "; if(!(cin>>number)){cout<<"Invalid input."<<endl;return 1;} if(number<=0)cout<<"Invalid! ";}while(number<=0); cout<<"You entered: "<<number<<endl;return 0;}
