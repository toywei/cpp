#include <string>
#include <iostream>
using namespace std;
int main(){
    string a="你好";
    cout<<a.size()<<endl;
    cout<<a.c_str()<<endl; //常量，需要赋值到别的变量才可使用
    cout<<a<<endl;
}