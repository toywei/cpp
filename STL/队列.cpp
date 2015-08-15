#include <queue>
#include <iostream>
using namespace std;
struct Node{
    int data;
};
int main(){
    Node *a= new Node();
    Node *b= new Node();
    queue<Node*> node_queue;
    node_queue.push(a);
    node_queue.push(b);
    cout<<node_queue.size()<<endl;
    while (!node_queue.empty()){
          cout<<node_queue.front()<<endl;
          node_queue.pop();

    }
    delete a;
    delete b;
    return 0;
}