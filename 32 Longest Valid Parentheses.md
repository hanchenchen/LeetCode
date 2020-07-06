# 32 Longest Valid Parentheses

#### 方法一：正反两次遍历

##### C++

执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗：7 MB, 在所有 C++ 提交中击败了100.00%的用户

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


#### 方法二：栈

1. 使用栈来匹配括号对，标记匹配过的括号
2. 遍历一边标记，求到最长被标记过的部分

##### Python3

执行用时：64 ms, 在所有 Python3 提交中击败了40.96%的用户

内存消耗：14.3 MB, 在所有 Python3 提交中击败了11.11%的用户

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        st=[]
        if_matched=[0 for i in range(len(s))]
        for i in range(len(s)):
            if s[i]=='(':
                st.append(i)
            else:
                if len(st):
                    if_matched[st.pop()]=1
                    if_matched[i]=1
        ans=0
        p=0
        for i in range(len(s)):
            if if_matched[i]:
                p+=1
                if ans<p:
                    ans=p
            else:
                p=0
        return ans
```

