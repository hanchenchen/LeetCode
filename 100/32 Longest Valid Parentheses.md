# 32 Longest Valid Parentheses

执行用时 : 4 ms, 在Longest Valid Parentheses的C++提交中击败了100.00% 的用户

内存消耗 : 9 MB, 在Longest Valid Parentheses的C++提交中击败了97.75%的用户

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int left=0;
        int len=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')left++;
            else left--;
            if(left>0){
                len++;
            }else if(left==0){
                len++;
                ans=ans>len?ans:len;
            }else{
                len=0;
                left=0;
            }
        }
        int right=0;
        len=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')right++;
            else right--;
            if(right>0){
                len++;
            }else if(right==0){
                len++;
                ans=ans>len?ans:len;
            }else{
                len=0;
                right=0;
            }
        }
        return ans;
    }
};
```

1. 正序查找一遍，再逆序查找一遍。正序匹配以 ( - ) 个数大于零为准，当）个数大于（个数时重新计数，字符串前面多余的（会使整个字符串无法匹配；逆序匹配以 ) - (  个数大于零为准，，；前后不可能同时多余。

   