#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>

//��һ����ͬ����
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

//�����ƽ�������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//��һ����ʱ�临�Ӷ�O(N*N)�� 
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
    if(abs(depth1-depth2)>1)//ȡ����ֵ��abs����sqrt����
    {
        return false;
    }
    return isBalanced(root->left)&&isBalanced(root->right);
}

 
//��������ʱ�临�Ӷ�O(N)�� 
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

//��������������������
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

//���ģ���������ǰ�����
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

//���壺��ת������
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

//��������ֵ������
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

//���ߣ��Գƶ�����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
���������˼·���̣� 
�ʼ֪��Ҫ�����������Һ��Ӻ������������ӣ����������Һ��Ӻ������������ӣ�����û����ʶ������������Ҫ�ݹ��
�տ�ʼû���뵽Ҫ�����װһ�����������˺ܾ���ô�����ж�ÿ��root�Լ���Ӧ���ӵ�ֵ�Ƿ����
���濼�ǵݹ�ʱ���뵽��root�Ķ�Ӧ���ӵıȽϿ����õݹ�
���ڸ����ĺ���ֻ���ָ�����1��Ȼ���ҾͿ�ʼ���������װһ���������ж�root��Ӧ�ĺ��ӵ�ֵ�Ƿ���� 
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

 
