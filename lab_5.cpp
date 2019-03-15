#include <iostream>
using namespace std;

class Node{
public:    
    int data;
    Node * left;
    Node * right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    Node * root;
    BST(){
        root = NULL;
    }
    void insert(int val){
        insertHelper(root, val);
    }

    void insertHelper(Node * curr, int val){
        if (root == NULL){
            root = new Node(val);
        }
        else if (val < curr->data){
             if(curr->left == NULL) curr->left = new Node(val);
             else insertHelper(curr->left, val);
        }
        else{
            if(curr->right == NULL) curr->right = new Node(val);
             else insertHelper(curr->right, val);
        }     
    }
    
    void display(){
        dissplay(root);
            }
    
    void dissplay(Node * curr){
        if (curr == NULL) return;
        dissplay(curr->left);
        cout << curr->data <<",";
        dissplay(curr->right);
    }
    bool search(int val){
        Node * temp=search1(root,val);
        if(temp==NULL) return false;
        else return true;
    

    }
    
    Node * search1(Node * curr, int val){
        if (curr == NULL || curr->data == val) return curr;
        else if (val < curr->data) return search1 (curr->left, val);
        else return search1 (curr->right, val);
    }
};



int main(){
    BST b1;
    b1.insert(7);
    b1.insert(6);
    b1.insert(11);
    b1.display();
    cout<<b1.search(7);
    return 0;
}