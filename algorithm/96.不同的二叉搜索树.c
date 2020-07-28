/*
 * @Author: your name
 * @Date: 2020-07-06 14:24:31
 * @LastEditTime: 2020-07-06 16:19:28
 * @LastEditors: Please set LastEditors
 * @Description: 二叉树搜索树的种类 = 选择根的方式种类 x 左边种类 x 右边种类
 * 则，我们有n个结点，如果我们用C（n）表示二叉搜索树的种类。
 * 皮皮狗可以用递归的方法：如下：
 *   1.  如果选择1作为根节点，左子树为空，n-1个元素在右子树。
 *   2.  如果选择2作为根节点，1个元素在左子树，n-2个元素在右子树。
 *   3.  如果选择3作为根节点，2个元素在左子树，n-3个元素在右子树。
 * 依此类推，
 * 如果选择元素i作为根节点，则i-1个元素在左子树，n-i个元素在右子树。
 * 则C（n） = C（0）C（n-1）+ C（1）C（n-2）+……+ C（i-1）C（n-i）+……+C（n-1）C（0）。
 * 其中C（0）=1，因为空节点的二叉搜索树只有一个，C（1）=1，一个节点的二叉搜索树也是唯一的。
 * 上述的求和式子可以分解一下就是我们所说的CatalanNumber，卡特兰数。
 * 96.不同的二叉搜索树.c
 */
/*
 * @lc app=leetcode.cn id=96 lang=c
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start

int numTrees(int n)
{
    int *C = (int*)calloc((n+1), sizeof(int));
    C[0] = C[1] = 1;

    int i = 0, j = 0;
    for(i = 2; i <= n; ++i)
    {
        for(j = 1; j <= i; ++j)
        {
            C[i] += C[j-1] * C[i-j];
        }
    }
    return C[n];
}

// @lc code=end
