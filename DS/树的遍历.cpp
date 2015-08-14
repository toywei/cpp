#include <iostream>
using namespace std;
struct Node
{
    Node* left;
    Node* right;
    int value;
    Node(int val){
        value=val;
        right=left=NULL;  //一定要初始化 否则是野指针。。还是 C++写得少。
    }
};

int my_travel_preorder(Node* root){//前序遍历
    cout<<(root->value);
    if (root->left!=NULL)
        my_travel_preorder(root->left);
    if (root->right!=NULL)
        my_travel_preorder(root->right);
    return 0;
}
int my_travel_inorder(Node* root){//中序遍历
    if (root->left!=NULL)
        my_travel_preorder(root->left);
    cout<<(root->value);
    if (root->right!=NULL)
        my_travel_preorder(root->right);
    return 0;
}
int my_travel_postorder(Node* root){//后序遍历

    if (root->left!=NULL)
        my_travel_preorder(root->left);
    if (root->right!=NULL)
        my_travel_preorder(root->right);
    cout<<(root->value);
    return 0;
}
int main(){
    Node l1s1=Node(1);
    Node l2s1=Node(2);
    Node l2s2=Node(3);
    Node l3s1=Node(4);
    Node l3s2=Node(5);
    Node l3s3=Node(6);
    Node l3s4=Node(7);
    l1s1.left=&l2s1;
    l1s1.right=&l2s2;

    l2s1.left=&l3s1;
    l2s1.right=&l3s2;
    l2s2.left=&l3s3;
    l2s2.right=&l3s4;

    cout<<my_travel_preorder(&l1s1)<<endl;
    cout<<my_travel_inorder(&l1s1)<<endl;
    cout<<my_travel_postorder(&l1s1)<<endl;

    return 0;
}