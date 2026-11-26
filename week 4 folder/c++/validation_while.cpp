#include <iostream>
using namespace std;
int main(){int number; cout<<"Enter a positive number: "; if(!(cin>>number)){cout<<"Invalid input."<<endl;return 1;} while(number<=0){cout<<"Invalid! Please enter a positive number: "; if(!(cin>>number)){cout<<"Invalid input."<<endl;return 1;}} cout<<"You entered: "<<number<<endl;return 0;}
