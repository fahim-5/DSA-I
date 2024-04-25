#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
};

void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->val<<"->";
        inOrder(root->right);
    }
}
Node* insertNode(Node *root,int v){
    if(root==NULL){
        Node *n = new Node;
        n->val = v;
        n->left = NULL;
        n->right = NULL;
        root = n;
        return root;
    }
    if(v<root->val){
        ///left side
        root->left = insertNode(root->left,v);
    }
    else{
        ///right side
        root->right = insertNode(root->right,v);
    }
    return root;
}
int findMin(Node *root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL){
        return root->val;
    }
    else{
        return findMin(root->left);
    }
}
int findMax(Node *root){
    if(root==NULL){
        return -1;
    }
    if(root->right==NULL){
        return root->val;
    }
    else{
        return findMax(root->right);
    }
}
bool searchNode(Node *root,int item){
    if(root==NULL)
        return 0;
    if(item<root->val){
        return searchNode(root->left,item);
    }
    else if(item>root->val){
        return searchNode(root->right,item);
    }
    else{
        return 1;
    }
}
Node* findMinNode(Node *root){
    if(root==NULL)
        return root;
    if(root->left==NULL)
        return root;
    else
        return findMinNode(root->left);
}
Node *deleteNode(Node *root,int item){
    if(root==NULL)
        return root;
    if(item<root->val){
        /// left
        root->left = deleteNode(root->left,item);
    }
    else if(item>root->val){
        ///right
        root->right = deleteNode(root->right,item);
    }
    else{
        /// We found the item
        /* 1. no child
            2. one child
            3. both child
            */
        if(root->left==NULL && root->right==NULL){
            delete root;
            root = NULL;
        }
        else if(root->left==NULL){
            Node *tmp = root;
            root = root->right;
            delete tmp;
        }
        else if(root->right==NULL){
            Node *tmp = root;
            root = root->left;
            delete tmp;
        }
        else{
            /// both child
            Node *tmp = findMinNode(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right,tmp->val);
        }
    }
    return root;

}
int main(){

    Node *root = NULL;
    root = insertNode(root,12);
    root = insertNode(root,15);
    root = insertNode(root,7);
    root = insertNode(root,3);
    root = insertNode(root,11);
    root = insertNode(root,13);
    root = insertNode(root,8);
    root = insertNode(root,9);
    root = insertNode(root,5);
    root = insertNode(root,17);
    root = insertNode(root,6);
    cout<<root->left->right->val<<endl;
    cout<<"-----Inorder-------"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<findMin(root)<<endl;
    cout<<findMax(root)<<endl;
    cout<<searchNode(root,2)<<endl;
    root = deleteNode(root,7);
    cout<<root->left->val<<endl;
    return 0;
}

