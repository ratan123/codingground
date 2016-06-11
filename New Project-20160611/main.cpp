//program to print vertically element of a given binary tree 
#include <iostream>
#include<vector>//use for allocating dynamic size of array
#include<map>//use for hash function

using namespace std;

//structure of node for a binary tree
struct Node{
    int key;
    Node *left,*right;
};

//A utility function to create a new node 
struct Node* newnode(int key){
    struct Node *node=new Node;
    node->key=key;
    node->left=node->right=NULL;
    return node;
};
void get_vertical_order(struct Node * root,map <int,vector<int> > &vertical,int hd){
    if(!root)
        return;
    //store the current node in hashmap
    vertical[hd].push_back(root->key);
    //store nodes in left subtree
    get_vertical_order(root->left,vertical,hd-1);
    //store nodes in right subtree
    get_vertical_order(root->right,vertical,hd+1);
}
void print_vertical_order(struct Node* root){
    //create a unordered map 
    map <int,vector<int> > vertical;
    int hd=0;
    //function call for get vertical order
    get_vertical_order(root,vertical,hd);
    //iterate hash map using iterator
    //traverse the map and print nodes at every horigontal distance
    
    map< int,<vector<int> > :: iterator m;
    for(int y=vertical.begin();y!=vertical.end();y++){
    //for(auto p :vertical){
        for(int i=0;i< vertical[y]->second.size();i++)
        //for(auto x:p.second)
            cout<<m->second[i]<<" ";
        cout<<endl;    
    }
    
}
int main()
{
   Node *root=newnode(1);
   root->left=newnode(2);
   root->right=newnode(3);
   root->left->left=newnode(4);
   root->left->right=newnode(5);
   root->right->left=newnode(6);
   root->right->right=newnode(7);
   root->left->left->left=newnode(8);
   root->left->left->right=newnode(9);
   root->left->right->left=newnode(10);
   root->left->right->right=newnode(11);
   
   cout<<"Vertical order traversal is \n:";
   print_vertical_order(root);

   return 0;
}

