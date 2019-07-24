/*
 * < Cracking The Coding Interview 6/E >
 * Problem #4.4 Check the balance(difference of depth is at least 1) of the binary tree.
 * 
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<cmath>
#define T int
class TreeNode
{
    public:
        T data;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
        TreeNode(T data)
        {
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
            this->parent=nullptr;
        }
        int height(TreeNode *node)
        {
            if(node==nullptr)
            {
                return 0;
            }
            else
            {
                int lHeight=height(node->left);
                int rHeight=height(node->right);
                return (lHeight>rHeight? lHeight+1:rHeight+1);
            }
        }
};
TreeNode* createMinimalBST(int *arr, int size);
TreeNode* createMinimalBST(int *arr, int start, int end);

bool isBalanceBT(TreeNode *node);

int main()
{
    int arr[]={1, 2, 3, 4, 5, 6, 7};
    TreeNode *root=new TreeNode(1);
    TreeNode *node=new TreeNode(2);
    root->left=node;    node->parent=root;
    node=new TreeNode(3);
    root->left->left=node;  root->left->left->parent= root->left;

    std::cout<<isBalanceBT(createMinimalBST(arr, sizeof(arr)/sizeof(int)))<<"\n";
    //std::cout<<isBalanceBT(root);
    return 0;
}
bool isBalanceBT(TreeNode *node)
{
    
    if(node==nullptr)
    {
        std::cout<<" call ";
        return true;
    }
    else
    {
        std::cout<<" call"<<node->data<<"  ";
        int lHeight=node->height(node->left);
        int rHeight=node->height(node->right);
        if(abs(lHeight-rHeight)>1)
        {
            return false;
        }
        else
        {
            isBalanceBT(node->left);
            isBalanceBT(node->right);
        }
        
    }
    return true;
}
TreeNode* createMinimalBST(int *arr, int size)
{
    return createMinimalBST(arr, 0, size-1);
}
TreeNode* createMinimalBST(int *arr, int start, int end)
{
    if(start>end)
    {
        return nullptr;
    }
    int mid=(start+end)/2;
    TreeNode *node = new TreeNode(arr[mid]);
    node->left=createMinimalBST(arr, start, mid-1);
    node->right=createMinimalBST(arr, mid+1, end);
    return node;
}