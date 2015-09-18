#include <iostream>
//在 xv6 源码里看到的
using namespace std;
struct segdesc {
  uint lim_15_0 : 16;  // Low bits of segment limit
  uint base_15_0 : 16; // Low bits of segment base address
  uint base_23_16 : 8; // Middle bits of segment base address
  uint type : 4;       // Segment type (see STS_ constants)
  uint s : 1;         
};

int main(){

    segdesc a;
    //cout<<a.lim_15_0;
    //a.s=5;
    a.s=1;
    cout<<a.s;
}