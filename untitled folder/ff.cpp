#include <iostream>
using namespace std;

char * func(char *raw ,int len){
    char *buffer=new char[len];
    int start=-1;
    int end=len-2+1;
    int offset=0;
    while (start < len-2){
        start ++;
        end--;
        if ((start==end && raw[start] =='#') || end==0 ){
            buffer[start-offset]=raw[start];
            continue;
        }
        if (raw[start] !='#'){
            buffer[start-offset]=raw[start];
            continue;
        }

        if  (raw[start] =='#'){
            offset++;
        }
    }
    return buffer;
}

int main(){
    char  raw[] = "sb#a#";

    int   len  = sizeof(raw);
    char* temp= func(raw,len);
    cout<<func(raw,len)<<endl;
    delete temp;

    return 0;
}