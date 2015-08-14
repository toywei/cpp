#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

Node* my_reverse(Node * & head){

    if (head->next==NULL && head->next->next==NULL)
        return 0;
    Node *follow=head->next;  //准备好 head 和 follow 
    head->next=NULL;  //这个太容易忘了我擦。。调了几分钟，成环了。。
    while (follow!=NULL){
        Node * next_follow=follow->next; //
        Node * next_head=follow;        //   准备好下次循环所需
        follow->next=head;

        follow=next_follow;              //    准备好下次循环
        head=next_head;                 //
    }
    return NULL;    
}
int main(){

   Node a=Node();
   a.data=4;
   a.next=NULL;
   Node b=Node();
   b.data=3;
   b.next=&a;
   Node c=Node();
   c.data=2;
   c.next=&b;
   Node d=Node();
   d.data=1;
   d.next=&c;
   Node *head=&d;
   my_reverse(head);
   Node *view=head;
   while (view->next !=NULL){
       cout<<view->data<<endl;
       view=view->next;
   }
   cout<<view->data;
}