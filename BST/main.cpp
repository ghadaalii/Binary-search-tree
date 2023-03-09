#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left , *right;

    Node(int value){
        data = value ;
        left = right = NULL;
    }
};

class BTS{
public:
    Node *root;

    BTS(){
        root = NULL;
    }

    Node *Insert(Node *r , int item){
        if(r == NULL){
            Node *newnode = new Node(item);
            r = newnode;
        }else if(item < r -> data){
            r -> left = Insert(r -> left , item);
        }else if(item > r -> data)
            r -> right = Insert(r -> right , item);
        return  r;
    }

    void Insert(int item){
        root = Insert(root , item);
    }

    void Preorder(Node *r){
        if(r == NULL)
            return;
        cout << r -> data << "\t";
        Preorder(r -> left);
        Preorder(r -> right);
    }

    void Inorder(Node *r){
        if(r == NULL)
            return;
        Inorder(r -> left);
        cout << r -> data << "\t";
        Inorder(r -> right);
    }

    void postorder(Node *r){
        if(r == NULL)
            return;
        postorder(r -> left);
        postorder(r -> right);
        cout << r -> data << "\t";
    }
    Node* search(Node *r , int key){
        if(r == NULL)
            return NULL;
        else if(key == r->data)
            return r;
        else if(key < r->data)
            return search(r->left , key);
        else if(key > r->data)
            return search(r->right , key);
    }

    bool search(int key){
        Node *result = search(root, key);
        if(result == NULL)
            return false;
        else
            return true;
    }

    Node *findMin(Node *r){
        if(r == NULL)
            return NULL;
        else if(r->left == NULL)
            return r;
        else if(r->left)
            return findMin(r->left);
    }

    Node *findMax(Node *r){
        if(r == NULL)
            return NULL;
        else if(r->right == NULL)
            return r;
        else if(r->right)
            return findMax(r->right);
    }

    Node *Delete(Node * r ,int key){
        if(r == NULL)
            return NULL;
        else if(key < r->data)
            r->left = Delete(r->left, key);
        else if(key > r->data)
            r->right = Delete(r->right , key);
        else{
            if(r->left == NULL && r->right == NULL)
                r = NULL;
            else if(r->right == NULL && r->left != NULL){
                r->data = r->left->data;
                delete r->left;
                r->left = NULL;
            }
            else if(r->left == NULL && r->right != NULL){
                r->data = r->right->data;
                delete r->right;
                r->right = NULL;
            }
            else{
                Node *max = findMax(r->left);
                r->data = max->data;
                r->left = Delete(r->left,max->data);
            }
        }
        return r;
    }
};
int main() {
    BTS btree;
    int n ;
    cout << "numbers of elements ?" << endl;
    cin >> n;
    cout << "Enter the elements : " << endl;
    for(int i = 0 ; i < n ; i++){
        int elements;
        cin >> elements;
        btree.Insert(elements);
    }
    cout << "Display tree elements :) Pre"<< endl;
    btree.Preorder(btree.root);
    cout << "\n" ;
    cout << "Display tree elements :) In"<< endl;
    btree.Inorder(btree.root);
    cout << "\n" ;
    cout << "Display tree elements :) Post"<< endl;
    btree.postorder(btree.root);
    cout << "\n" ;
    cout << "Enter element to search for :"<< endl;
    cin >> n ;
    if(btree.search(n))
        cout << "element is found :)" << endl;
    else
        cout << "element is not found :(" << endl;
    cout << "To find min" << endl;
    Node *min = btree.findMin(btree.root);
    if(min == NULL)
        cout << "No elements found" << endl;
    else
        cout << "Min is : "<< min->data << endl;
    Node *max = btree.findMax(btree.root);
    if(max == NULL)
        cout << "No elements found" << endl;
    else
        cout << "Max is : "<< max->data << endl;
    cout << "To delete items "<< endl;
    cin >> n;
    btree.Delete(btree.root,n);
    cout << "tree pre after delete item "<< endl;
    btree.Preorder(btree.root);
    return 0;
}
