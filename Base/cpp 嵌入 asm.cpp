#include <iostream>
using namespace std;
int main(){
    int a=8, b=1;

    asm ("xchg %1, %0;"
        // "nop;"

             :"=r"(b),"=r"(a)    
             :"r"(b),"r"(a)        
             );      

    printf("Result: %d, %d\n", a, b);

    return 0;
}
