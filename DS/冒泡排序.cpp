#include <iostream>
using namespace std;
int main(){
    int a[]={456,3,3565,34,1,4,5,677,56,46,34577,36,3,6789,353,346,567};
    size_t len_of_a = sizeof(a)/sizeof(int);
    for (int i = 0; i < len_of_a; ++i)
    {
            for (int j = 0; j < len_of_a - i; ++j)
            {
                if (a[j] <  a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;

                }
            }
    }
    for (int i=0 ; i<len_of_a; ++i)
    {
        cout<<a[i]<<",";
    }

}