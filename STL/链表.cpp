#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(){
    list<string> strlist;
    strlist.push_back("abvc");
    strlist.push_back("abvc");
    strlist.push_back("abvc你好");
    for(list<string>::iterator i=strlist.begin();i!=strlist.end();i++)//启用 C++ 11的话可以用 autofixed 
    {
        cout<<*i<<endl;
    }
    return 0;
}