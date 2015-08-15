#include <iostream>
using namespace std;
union T{
    char p[4];
    int n;
};
typedef int int32;
int main(){
    {
        T a;
        a.n='A'+256*'B'+256*256*'C'+256*256*256*'D';
        cout<<a.p[0]<<a.p[1]<<a.p[2]<<a.p[3]<<endl;
    }
    cout<< sizeof (int*) <<endl; //64bit 是8
    int a[5]={1,453,3,4,5};
    int b[5]={9461,2,3,4,5};
    cout<<&b-&a<<endl;
    cout<<&b[0]-&a[0]<<endl;
    cout<<"(long)&b[0]-(long)&a[0]"<<(long)&b[0]-(long)&a[0]<<endl;
    cout<<"(long)&b[0]-(long)&a[0]"<<(long)&b-(long)&a<<endl;
    cout<<"a+1-a: "<<(long)(a+1)-(long)&a<<endl;
    int *ptr1=(int *)(&a+1);
    int *ptr2=a+1;
    int i=1;
    while (1){
    i--;
    if (ptr1[i]==9461){
        break;
    }
   }
   cout<<"i: "<<i<<endl;
   cout<<ptr1[-11]<<endl<<*ptr2<<endl;
   return 0;
}