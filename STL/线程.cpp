#include <thread>
#include <iostream>
#include <ctime>
#include <cmath>

#define NANO_SECOND_MULTIPLIER  1000000L

struct test{
    int a;
};                      
struct test test1 = {666};  //

struct timespec req = {0};   //原来这里是对ctime 中定义的 timespec 的填充 我在上面自己定义了一个，你可以参考一下
/*
time_t tv_sec
This represents the number of whole seconds of elapsed time.
long int tv_usec
This is the rest of the elapsed time (a fraction of a second), represented as the number of microseconds. It is always less than one million.
*/
struct timespec rem = {0};
using namespace std;
void run(){
    cout<<test1.a;
    //req.tv_sec  = 0;//(time_t)9; //这里是 int 也可以的 暂不知有什么区别,我认为是范围的区别 需查证
    //req.tv_nsec = 2*pow(1000,3); //我
    for (int i = 0; i < 10; ++i)
    {
        //usleep(1000*1000); #include <unistd.h> unix only
        //nanosleep(&req,&rem);
        nanosleep((const struct timespec[]){{2, 500*NANO_SECOND_MULTIPLIER}}, NULL);  //1.5 秒，后一个指针如果你传入相同的结构体，那么会返回剩余没有 sleep 完成的时间
        cout<<"a"<<endl;
    }

}
int main(){
    thread a(run);

    a.join();
    cout<<"test"<<endl;
    for (int i = 0; i < 10; ++i)
    {
        //usleep(1000*1000);; #include <unistd.h> unix only
        cout<<"b"<<endl;
    }
}
