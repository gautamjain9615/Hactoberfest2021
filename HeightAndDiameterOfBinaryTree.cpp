#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    return max(leftHeight,rightHeight)+1; //1 to add the current node
}
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int currDiam=height(root->left)+height(root->right)+1;
    int leftDiam=diameter(root->left);
    int rightDiam=diameter(root->right);
    return max(currDiam,max(leftDiam,rightDiam));//max(leftDiam,rightDiam)-when not travelling through the root node and currDiam when travelling through root node
}
int calcDiam(node* root,int *height){
    if(root==NULL){
        *height=0; //we can omit this if we have wriiten-int lh=10,rh=10;
        return 0;
    }
    int lh=10,rh=10;//these initialisations doesnt matter (if we mentioned*height=0; in base consition) so we can sip it or give any value whatever it is, otherwise it will matter
    //change in*height is equivalent to changing in lh and rh because *height=&lh /  *height=&th in the later function call
    int leftDiam=calcDiam(root->left,&lh);
    int rightDiam=calcDiam(root->right,&rh);
    int currDiam=lh+rh+1;
    *height=max(lh,rh)+1; //changing height so changing in location of rh and lh
    cout<<*height<<"+"<<currDiam<<" ";
    return max(currDiam,max(leftDiam,rightDiam));

}
int main(){
    node* root= new node(1);
    root->left=new node(2);
    root->right=new node(3);
    /*  1
       / \
      2   3
     / \  / \
    4   5 6 7
    */ 
   root->left->left=new node(4);
   root->left->right=new node(5);
   root->right->left=new node(6);
   root->right->right=new node(7);
   cout<<height(root);
   //cout<<"\n"<<diameter(root);
   int height=0;
   cout<<"\n"<<calcDiam(root,&height);
    return 0;
}