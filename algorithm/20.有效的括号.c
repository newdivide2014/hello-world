/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#define MAXSIZE 1024

bool isValid(char * s){
    char *p = s;
    int top  = -1, i = 0;
    char *stack = (char*)malloc(MAXSIZE * sizeof(char));

    while(*p)
    {
        if( p[i] == "(" || p[i] == "[" || p[i] == "{")
        {
            stack[++top] = p[i];
        }
    }
}


// @lc code=end

