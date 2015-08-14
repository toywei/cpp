#include <iostream>
#include <string>
#include <map>

class Add  
{  
    public:  
        int operator()(int a, int b)  
            {  
                return a + b;  
            };
    };

Add add;

using namespace std;
int main(){
    cout<<add(1,3);
    map <string ,int> dict;
    dict["1"]=0;
    cout<<dict["1"]<<endl;
    return 0;

   
}