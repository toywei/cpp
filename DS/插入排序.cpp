#include <iostream>
using namespace std;
int main(){
    int list[]={1,35,56,445,64,56,43,667,34,778,346,78,347,88,4578,3478,};
    int len=sizeof(list)/sizeof(int);
    //这个算法也是分为排好序和没排好序的
    for (int start = 1; start <len; start++){  // start 1 是 未排序的开始,0认为是一个已经排好序的序列
        int num=list[start];
        for (int i=start; i>0; i--){
            list[i]=list[i-1]; //第一次被覆盖掉的我们已经用 num 保存了
                               //同样地，这使得 list[i-1]处行形成了空穴

            if (num>list[i]){
                list[i-1]=num;
            }
            
        }
    }

    for (int i = 0; i < len; ++i)
    {
        cout<<list[i]<<endl;
    }
    return 0;
}