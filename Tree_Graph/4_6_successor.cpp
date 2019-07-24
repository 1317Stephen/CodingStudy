/*
 * < Cracking The Coding Interview 6/E >
 * Problem #4.6 Find the in-order successor.
 * 
 * Author: YeEun Ko
 * 
 */
#include <iostream>
#define T int
class TreeNode
{
    public:
        T data;
        TreeNode*left;
        TreeNode*right;
        TreeNode*parent;
        TreeNode(T data)
        {
            this->data=data;
        }
        int height()
        {
            if(this==nullptr)
            {
                return 0;
            }
            int lHeight=this->left->height();
            int rHeight=this->right->height();
            return (lHeight>rHeight? lHeight:rHeight);  
        }
};

TreeNode* leftMostChild(TreeNode*node);
TreeNode* inOrderSuccessor(TreeNode *node);

int main()
{
    
    return 0;
}
TreeNode* inOrderSuccessor(TreeNode *node)
{
    if(node==nullptr)
    {
        return nullptr;
    }

    if(node->right!=nullptr)
    {
        return leftMostChild(node->right);
    }   
    else
    {
        TreeNode *current=node;
        TreeNode *up=node->parent;
        while(up!=nullptr && up->left!=current)
        {
            current=up;
            up=up->parent;
        }
        return up;
    }
    
}
TreeNode* leftMostChild(TreeNode*node)
{
    if(node==nullptr)
    {
        return nullptr;
    }  
    while(node->left!=nullptr)
    {
        node=node->left;
    }
    return node;
}