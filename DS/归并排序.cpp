#include <iostream>
using namespace std;

//合并小函数
int *merge(int *start,int *mid,int *end){

    int *save=start; //返回内存起始地址所需
    int *a=start;  //复制时用的指针

    int *b=mid+1; //mid 需要+1
    int *temp=new int[end-start+1];
    int *i=temp;    //复制时用的指针
    int *j=temp;    //写回的指针

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
    while(start<=end){
        //cout<<"w"<<*j<<';';
        *start++=*j++;
    }
    delete[] temp;
    return save;

}

int* merge_sort(int *start,int *end){
    if (start-end==0){
        return start;
    }
    int *mid=start+(end-start)/2;
    int *left=merge_sort(start,mid);
    int *right=merge_sort(mid+1,end);
    return merge(start,mid,end);

}

void test_merge(){
    int list[]={11,5,1,166,14,5,235,453,96,1264,145,99999999};
    int *start=&list[0];
    int *mid=&list[4];
    int *end=&list[sizeof(list)/sizeof(int)-1];
    merge_sort(start,end);
    for (int t=0;t<end-start+1;t++){
        cout<<list[t]<<endl;
    }
}

int main(){
    test_merge();
}

