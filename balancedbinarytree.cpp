#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
bool balanced(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    if(balanced(root->left) && balanced(root->right))
    {
        int lh=height(root->left);
        int rh=height(root->right);

        if(abs(lh-rh)<=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
} 
//optimisedway
bool balanced1(Node* root,int* height)
{
    if(root==NULL)
    {
        *height=0;
        return true;
    }
    int lh=0,rh=0;
     if(balanced1(root->left,&lh) && balanced1(root->right,&rh))
    {
        *height=max(lh,rh)+1;
        if(abs(lh-rh)<=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    int height=0;
    cout<<balanced(root)<<endl;
    cout<<balanced1(root,&height);
    return 0;
}