#include <iostream>
#include <assert.h>
using namespace std;


int quicksort(int *left,int *right){
    int *start=left;
    int *end=right;
    int base=*left;
    if (left>right) return 0;  //基本前提

    while (left!=right){
        while (*right <= base && right>left){
            right--;
        }
        while (*left >= base && right>left){
            left++;
        }
        if (left!=right)
        {//swap   
            int temp=*right;
            *right=*left;
            *left=temp;
        }
        else
        {//swap 基准数 和 碰撞点
            int temp=*right;
            *right=*start;
            *start=temp;
            assert(left==right);//现在其实是一个意思
            quicksort(start,left);
            quicksort(right+1,end);
            break;
        }

    }

    return 0;
}
int main(){
    int the_list[]={70,45,54,54,34566,347,67,4356,5,667,3,146,56,46};
    size_t len_of_the_list=sizeof(the_list) / sizeof(int);
    int *left=NULL,*right=NULL;
    left=&the_list[0];
    right = &the_list[0] + len_of_the_list-1;
    cout<<right-left<<endl;
    quicksort(left,right);


    for (int i=0;i<len_of_the_list;i++){
        cout<<the_list[i]<<",";
    }
}