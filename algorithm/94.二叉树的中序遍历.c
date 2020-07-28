/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXSIZE 1024

typedef struct _stack {
    int top;
    int *array;
} Stack;

Stack *init_stack()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    s->array = (int*)calloc(MAXSIZE, sizeof(int));
    return s;
}

int isEmpty(Stack *s)
{
    return (s->top == -1) ? 1 : 0;
}

void stack_push(Stack *s, struct TreeNode* p)
{
    if(s->top < MAXSIZE)
    {
        s->array[++(s->top)] = p->val;
    }
}

void stack_pop(Stack *s)
{
    if(!isEmpty(s))
    {
        s->top--;
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *buf = (int*)calloc(MAXSIZE, sizeof(int));
    Stack *s = init_stack();
    struct TreeNode* p = root;
    *returnSize = 0;
    while( p || !isEmpty(s) )
    {

        if(p)
        {
            stack_push(s, p);
            p->left;
        }
        else {
            stack_pop(s);
            buf[(*returnSize)++]  = p->val;
            p->right;
        }
    }
    return returnSize;
}


// @lc code=end

