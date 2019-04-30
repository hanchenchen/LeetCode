# 20 Valid Parentheses

执行用时 : 8 ms, 在Valid Parentheses的C++提交中击败了96.74% 的用户

内存消耗 : 8.5 MB, 在Valid Parentheses的C++提交中击败了77.25% 的用户

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.empty())return false;
                char cc = st.top();
                st.pop();
                if(cc=='('){
                    if(s[i]!=')')return false;
                }else if(cc=='['){
                    if(s[i]!=']')return false;
                }else{
                     if(s[i]!='}')return false;
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};
```

1. 考虑第一个输入为右括号导致stack为空的情况