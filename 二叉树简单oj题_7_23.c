#include<stdio.h>
#include<string.h>
#include<math.h>
#include<assert.h>

//题一：二叉树的中序遍历
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

void _inorderTraversal(struct TreeNode* root, int** ppsize,int** arr)
{
    if(root==NULL)
    return ;
    _inorderTraversal(root->left,ppsize,arr);
    (*arr)[**ppsize]=root->val;
    (**ppsize)++;
    _inorderTraversal(root->right,ppsize,arr);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* retarr=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    _inorderTraversal(root,&returnSize,&retarr);
    return retarr;
}

//题二：后序遍历
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

void _postorderTraversal(struct TreeNode* root, int** ppsize,int** arr)
{
    if(root==NULL)
    return;
    _postorderTraversal(root->left,ppsize,arr);
    _postorderTraversal(root->right,ppsize,arr);
    (*arr)[**ppsize]=root->val;
    (**ppsize)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* retarr=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    _postorderTraversal(root,&returnSize,&retarr);
    return retarr;
}

