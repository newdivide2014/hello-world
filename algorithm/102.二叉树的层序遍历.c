/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
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

#define MAXSIZE 10240

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root == NULL) 
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    *returnColumnSizes = malloc(MAXSIZE * sizeof(int));
    
    struct TreeNode *p = root;
    int level = 0, colNode = 0,  front = 0, rear = 0, i = 0;
    struct TreeNode *nodeQueue[MAXSIZE];
    nodeQueue[rear++] = p;

    int **buf = (int**)malloc(MAXSIZE * sizeof(int));
    while(front != rear)
    {
        colNode = (front<rear)?(rear-front):(MAXSIZE+rear-front);
        buf[level] = (int*)calloc(colNode, sizeof(int));
        for(i = 0; i < colNode; i++)
        {
            p = nodeQueue[front];
            buf[level][i] = p->val;
            front = (front + 1) % MAXSIZE;
            if(p->left)
            {
                 nodeQueue[rear] = p->left; 
                 rear = (rear + 1) % MAXSIZE;
            }
            if(p->right)
            {
                nodeQueue[rear] = p->right;
                rear = (rear + 1) % MAXSIZE; 
            }
        }
        (*returnColumnSizes)[level] = colNode;
        level++;
    }
    *returnSize = level;
    return buf;
}


// @lc code=end

