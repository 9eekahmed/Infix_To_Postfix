#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char infix_exp[401], stack[10], postfix_exp[401];
    int t,y, stack_len, postfix_len;
    
    memset(stack, 0, 10);
    memset(postfix_exp, 0, 401);
    
    scanf("%400s",infix_exp);

    for(y=0; y <=strlen(infix_exp); y++)
    {
        
        stack_len = strlen(stack);
        postfix_len = strlen(postfix_exp);

        int z = postfix_len;
        int l = stack_len-1;
        switch (*(infix_exp+y))
        {
            case '+':
                if (stack[stack_len-1] == '+' || stack[stack_len-1] == '-' || stack[stack_len-1] == '/' || stack[stack_len-1] == '*' || stack[stack_len-1] == '^')
                {
                    postfix_exp[postfix_len] = stack[stack_len-1];
                    stack[stack_len-1] = '+';
                }else{
                    stack[stack_len] = '+';    
                }
                break;
            case '-':
                if (stack[stack_len-1] == '+' || stack[stack_len-1] == '-' || stack[stack_len-1] == '/' || stack[stack_len-1] == '*' || stack[stack_len-1] == '^')
                {
                    postfix_exp[postfix_len] = stack[stack_len-1];
                    stack[stack_len-1] = '-';
                }else{
                    stack[stack_len] = '-';    
                }
                break;
            case '*':
                if (stack[stack_len-1] == '*' || stack[stack_len-1] == '/' || stack[stack_len-1] == '^')
                {
                    postfix_exp[postfix_len] = stack[stack_len-1];
                    stack[stack_len-1] = '*';
                }else{
                    stack[stack_len] = '*';    
                }
                break;
            case '/':
                if (stack[stack_len-1] == '*' || stack[stack_len-1] == '/' || stack[stack_len-1] == '^')
                {
                    postfix_exp[postfix_len] = stack[stack_len-1];
                    stack[stack_len-1] = '/';
                }else{
                    stack[stack_len] = '/';    
                }
                break;

            case '^':
                if (stack[stack_len-1] == '^')
                {
                    postfix_exp[postfix_len] = stack[stack_len-1];
                    stack[stack_len-1] = '^';
                }else {
                    stack[stack_len] = '^';    
                }
                
                break;
            case '(':
                stack[stack_len] = '(';
                break;

            case ')':
                
                while (1)
                {
                    if (stack[l] == '(')
                    {
                        stack[l] = '\0';          
                        break;
                       
                    }
                    postfix_exp[z] = stack[l]; 
                    stack[l] = '\0';              
                    z++;
                    l--;
                }
                break;
               
            default:
                postfix_exp[postfix_len] = *(infix_exp+y);
        }
    }

    int n=strlen(stack)-1;
    int f=0;
    char re[10];
    memset(re, 0, 10);
    while(n>=0)
    {
        re[f] = stack[n];
        n--;
        f++;
    }
    strcat(postfix_exp, re);
    
    printf("%s\n", postfix_exp);
    return 0; 
}
