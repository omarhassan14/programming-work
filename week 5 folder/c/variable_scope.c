// WEEK 5 - ACTIVITY 2: GLOBAL VS LOCAL SCOPE
#include <stdio.h>

int globalCounter = 100;  // Global variable

void displayGlobal(void) {
    printf("Inside displayGlobal: globalCounter = %d\n", globalCounter);
}

void modifyGlobal(void) {
    globalCounter = 500;
    printf("Inside modifyGlobal: globalCounter changed to %d\n", globalCounter);
}

void localDemo(void) {
    int globalCounter = 999;  // Local variable shadows the global
    printf("Inside localDemo: globalCounter = %d\n", globalCounter);
}

int main(void) {
    int localCounter = 50;
    printf("In main: globalCounter = %d\n", globalCounter);
    printf("In main: localCounter = %d\n", localCounter);

    displayGlobal();
    modifyGlobal();
    localDemo();

    printf("Back in main: globalCounter = %d\n", globalCounter);
    return 0;
}
