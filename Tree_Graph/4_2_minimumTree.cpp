/*
 * < Cracking The Coding Interview 6/E >
 * Problem #4.2 Implement the minimum height Binary Search Tree with ordered array.
 * 
 * Author: YeEun Ko
 * 
 */
#include<iostream>
#include<cmath>
#include<algorithm>
#define T int
class TreeNode
{
    public:
        T name;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
        TreeNode(T data)
        {
            this->name=data;
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
                return (lHeight>rHeight ? lHeight+1:rHeight+1);
            }
        }
};
class Tree
{
    public:
        TreeNode *root;
        Tree()
        {
            this->root=nullptr;
        }

};

using namespace std;
void insertBinarySearchTree(TreeNode *root, int *arr, int arrSize, int middleIndex);


TreeNode* createMinimalBST(int *arr, int size);
TreeNode* createMinimalBST(int *arr, int start, int end);

int main()
{
            //0  1  2  3  4
    int i,j;
    
    /*          4                       3
            2       6                2      5     
        1   3       5   7           1           6

        2^h-1=N ;   h=log2(N+1)
     */

    // int size=(sizeof(arr)/sizeof(int));
    // int middleIndex=size/2;
    // int height=log2(size+1);
    
    // printf("size:%d middle:%d height:%d\n", size, middleIndex, height);

    // Tree *tree=new Tree();
    // TreeNode*node=new TreeNode(arr[middleIndex]);
    // tree->root=node;
    // insertBinarySearchTree(tree->root, arr, size, middleIndex);

    int arr[]={1, 2, 3, 4, 5, 6, 7};
    cout<<"size "<<sizeof(arr)/sizeof(int)<<"\n";
    TreeNode*root=createMinimalBST(arr, sizeof(arr)/sizeof(int));
    cout<<"height: "<<root->height(root)<<"\n";

    return 0;
}
TreeNode* createMinimalBST(int *arr, int size)
{
    return createMinimalBST(arr, 0, size-1);
}
TreeNode* createMinimalBST(int *arr, int start, int end)
{
    if(end<start)
    {
        return nullptr;
    }
    int mid=(start+end)/2;
    TreeNode *n=new TreeNode(arr[mid]);
    cout<<n->name<<"\n";
    n->left=createMinimalBST(arr, start, mid-1);
    n->right=createMinimalBST(arr, mid+1, end);
    
    return n;
}
void insertBinarySearchTree(TreeNode *root, int *arr, int arrSize, int middleIndex)
{
    int index=middleIndex/2;
    //TreeNode*current=root;
    //cout<<"middle: "<<middleIndex<<" minus: "<<index<<"\n";
    if(middleIndex==1)
    {
        TreeNode*left = new TreeNode(arr[0]);
        root->left=left; left->parent=root;
        return;
    }
    if(middleIndex-index>=0 && middleIndex!=1)
    {
        TreeNode*left = new TreeNode(arr[middleIndex-index]);
        root->left=left; left->parent=root;
        cout<<arr[middleIndex-index]<<" ";
        insertBinarySearchTree(root->left, arr, arrSize, middleIndex-index);
    }
    if(middleIndex+index<arrSize)
    {
        TreeNode*right = new TreeNode(arr[middleIndex+index]);
        root->right=right; right->parent=root;
        cout<<arr[middleIndex+index]<<" ";
        insertBinarySearchTree(root->right, arr, arrSize, middleIndex+index);
    }
}