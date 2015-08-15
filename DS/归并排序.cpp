#include <iostream>
using namespace std;
//合并小函数


int merge(int *start,int *mid,int *end){
    int offset=end-start;
    int *a=start;
    int *b=mid+1; //mid 需要+1
    int* temp=new int[end-start+1];
    int *i=temp;    //
    int *j=temp;    // temp 是删除用的指针 i，j 分别是复制 和写回时候用的指针
    while (a <= mid && b <= end){
        (*a<=*b)?*i++=*a++:*i++=*b++;
    }

    while(a <= mid){
        *i++=*a++;
    }
      while(b <= end){
        *i++=*b++;
    }
    //写回原来的内存
    while(start<end){
        *start++=*j++;
    }
    delete[] temp;
    return 0;

}

void test_merge(){
    int list[]={1,5,8,11,14,2,4,9,12,15};
    int *start=&list[0];
    int *mid=&list[4];
    int *end=&list[sizeof(list)/sizeof(int)-1];
    merge(start,mid,end);
    for (int t=0;t<end-start+1;t++){
        cout<<list[t]<<endl;
    }
}

int main(){
    test_merge();
}

