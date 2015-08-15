#include <iostream>
void swap(void *a,void *b){
    void* temp=a;
    a=b;
    b=temp;
}
using namespace std;
int main(){
    int list[]={1,3,5,6,6,7,4,77,5,5577,4555,4,4,677,3467,54,767,567};
    int len_of_list=sizeof(list)/sizeof(int);
    int max=0; //最大元素所在
    for (int split =0; split<len_of_list; split++){
    //split 分割序列 0~split-1 已排序 split~ 是未排序序列

        max=split;                                       //
        for (int i =split+1; i<len_of_list; i++){        //
            if (list[i]>list[max]){                      //     这一部分是求取最大
                max=i;                                   //
            }                                            //
        }                                                //

        swap(list[max],list[split]); //交换最大元素 和 已排序好序
    }


    for (int i=0;i<len_of_list;i++){
        cout<<list[i]<<endl;
    }
    return 0;
}