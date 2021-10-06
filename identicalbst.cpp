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
Node* insertbst(Node* root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(root->data>val)
    {
        root->left=insertbst(root->left,val);
    }
    else
    {
        root->right=insertbst(root->right,val);
    }
    return root;
}
bool identicalbst(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else if(root1!=NULL && root2!=NULL)
    {
        if(root1->data==root2->data)
        {
            return identicalbst(root1->left,root2->left) && identicalbst(root1->right,root2->right);
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
    Node* root1=NULL;
    root1=insertbst(root1,5);
    insertbst(root1,1);
    insertbst(root1,3);
    insertbst(root1,4);
    insertbst(root1,2);
    insertbst(root1,7);

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<identicalbst(root,root)<<endl;
    cout<<identicalbst(root1,root1)<<endl;
    cout<<identicalbst(root,root1)<<endl;
    return 0;
}
