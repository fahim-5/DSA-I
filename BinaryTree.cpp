#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
};
Node *addNode(int v){
    Node *newNode = new Node;
    newNode->val = v;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->val<<"->";
        inOrder(root->right);
    }
}
void preOrder(Node *root){
    if(root!=NULL){
        cout<<root->val<<"->";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main(){
    Node *root = NULL;
    root = addNode(12);
    root->left = addNode(7);
    root->right = addNode(3);
    root->left->left = addNode(1);
    root->left->right = addNode(5);
    root->right->left = addNode(8);
    root->right->right = addNode(11);
    root->right->right->left = addNode(13);
    cout<<"-----Inorder-------"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"---------PreOrder----"<<endl;
    preOrder(root);
    cout<<endl;

    return 0;
}
