#include <bits/stdc++.h>

using namespace std;


class Node{

    Node *left, *right;
    int val;

public :

    Node(Node* root,int r){
            root->val = r;
            root->left = NULL;
            root->right = NULL;


    }

    void insert(Node* root,int val){


         Node *temp = root,*prev,*NewNode ;
         NewNode = (Node *)malloc(sizeof(Node));

        if(root == NULL){

            root = NewNode;

        }else{


            NewNode->val = val;
            NewNode->right = NULL;
            NewNode->left =  NULL;

            while(temp!=NULL){

                prev = temp;

                if(val < temp->val){

                    temp = temp->left;
                }else{

                    temp = temp->right;
                }
            }
            if (prev->val < val){

                prev->right = NewNode;

            }else{

                prev->left = NewNode;
            }
        }
    }

    void inOrder(Node* root){

        if(root == NULL)
            return;
        inOrder(root->left);
        cout <<"\t " <<root->val;
        inOrder(root->right);
    }
    void preOrder(Node* root){

        if(root == NULL)
            return;
        cout << "\t " << root->val;
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Node* root){

        if(root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<"\t "<< root->val;
    }

};

int main(){

    Node *root;
    int rootValue;
    cout << "\nenter root value : ";
    cin >> rootValue;
    Node Tree1(root,rootValue);

    int m;
    cout << "\nenter number of nodes : ";
    cin >> m;
    int val;
    for (int i = 0; i < m;i++){

        cout << "\nenter node value : ";
        cin >> val;
        Tree1.insert(root,val);
    }
    cout << "\n Pre Order :\t";
    Tree1.preOrder(root);

    cout << "\nIN Order :\t";
    Tree1.inOrder(root);

    cout << "\n Post Order :\t";
    Tree1.postOrder(root);
}
