#include <iostream>
using namespace std;
int sum(int times){
    int sumval=0;
    __asm__ __volatile__(
            "xorl %%eax, %%eax;" //a=0
            "xorl %%ecx, %%ecx;" //c=0
            "movl %0,%%ebx;"  //b=sumval
            "loop:"
            "incl %%ecx;"        //c++
            "addl %%ecx,%%eax;"  //a+=c
            "cmpl %%ebx,%%ecx;"   // b vs c?
            "jl loop;"            // < goto loop
            "movl %%eax,%0;"
             :"=r"(sumval)
             :"r"(times)
             :"eax","ecx" ,"ebx"       
             );
    return sumval;
}

void swap(int a,int b){
    __asm__ __volatile__("xchg %1, %0;"  //x86 only
             :"=r"(b),"=r"(a)
             :"r"(b),"r"(a)     
             );
    cout<<a<<","<<b<<endl;
}

int main(){


    swap(1,8);
    cout<<sum(100);
    return 0;
}
