#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>

//题一：相同的树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==NULL&&q!=NULL)
    return false;
    else if(p!=NULL&&q==NULL)
    return false;
    else if(p==NULL&&q==NULL)
    return true;
    else
    {
        if(p->val!=q->val)
        return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
}

//题二：平衡二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//法一：（时间复杂度O(N*N)） 
int TreeDepth(struct TreeNode* root)
{
    if(root==NULL)
    return 0;
    int leftdepth=TreeDepth(root->left);
    int rightdepth=TreeDepth(root->right);
    return leftdepth>rightdepth?(leftdepth+1):(rightdepth+1);
}

bool isBalanced(struct TreeNode* root){
    if(root==NULL)
    return true;
    int depth1=TreeDepth(root->left);
    int depth2=TreeDepth(root->right);
    if(abs(depth1-depth2)>1)//取绝对值是abs不是sqrt！！
    {
        return false;
    }
    return isBalanced(root->left)&&isBalanced(root->right);
}

 
//法二：（时间复杂度O(N)） 
bool _isBalanced(struct TreeNode* root,int* pheight)
{
    if(root==NULL)
    {
        *pheight=0;
        return true;
    }
    else
    {
        int leftheight=0;
        if(_isBalanced(root->left,&leftheight)==false)
        return false;
        int rightheight=0;
        if(_isBalanced(root->right,&rightheight)==false)
        return false;
        if(abs(leftheight-rightheight)>1)
        return false;
        (*pheight)=leftheight>rightheight?(leftheight+1):(rightheight+1);
        return true;
    }
}

bool isBalanced(struct TreeNode* root){
    int height=0;
    return _isBalanced(root,&height);
} 

//题三：二叉树的最大深度
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    int depth=0;
    if(root==NULL)
    return 0;
    int leftdepth=maxDepth(root->left);
    int rightdepth=maxDepth(root->right);
    return leftdepth>rightdepth?(leftdepth+1):(rightdepth+1);
}

//题四：二叉树的前序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void _preorderTraversal(struct TreeNode* root,int** ppsize,int** arr)
{
    if(root==NULL)
    {
        return;
    }
    (*arr)[**ppsize]=root->val;
    (**ppsize)++;
    _preorderTraversal(root->left,ppsize,arr);
    _preorderTraversal(root->right,ppsize,arr);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* retarr=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    _preorderTraversal(root,&returnSize,&retarr);
    return retarr;
}

//题五：翻转二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if(root==NULL)
    {
        return root;
    }
    struct TreeNode* tmp=root->left;
    root->left=invertTree(root->right);
    root->right=invertTree(tmp);
    return root;
}

//题六：单值二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root){
    if(root==NULL||(root->left==NULL&&root->right==NULL))
    return true;
    if(root->left!=NULL&&root->val!=root->left->val)
    return false;
    if(root->right&&root->val!=root->right->val)
    return false;
    return isUnivalTree(root->left)&&isUnivalTree(root->right);
}

//题七：对称二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
关于这题的思路历程： 
最开始知道要比左子树的右孩子和右子树的左孩子，右子树的右孩子和左子树的左孩子，但是没有意识到在这里是需要递归的
刚开始没有想到要另外封装一个函数，想了很久怎么依次判断每个root以及对应孩子的值是否相等
后面考虑递归时候想到了root的对应孩子的比较可以用递归
由于给定的函数只有又给参数1，然后我就开始考虑另外封装一个函数来判断root对应的孩子的值是否相等 
*/ 
bool _isSymmetric(struct TreeNode* lefttree,struct TreeNode* righttree)
{
    if(!lefttree&&!righttree)
    return true;
    if(!lefttree&&righttree)
    return false;
    if(!righttree&&lefttree)
    return false;
    if(lefttree->val!=righttree->val)
    return false;
    return _isSymmetric(lefttree->right,righttree->left)
            &&_isSymmetric(lefttree->left,righttree->right);
}

bool isSymmetric(struct TreeNode* root){
    if(!root)
    return true;
    return _isSymmetric(root->left,root->right);
}

 
