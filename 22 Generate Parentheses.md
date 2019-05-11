# 22 Generate Parentheses

执行用时 : 24 ms, 在Generate Parentheses的C++提交中击败了47.15%的用户

内存消耗 : 17.6 MB, 在Generate Parentheses的C++提交中击败了30.05% 的用户

```c++
class Solution {
public:
    int ob;
    vector<string> ans;
    void func(string s,int left,int right){
        if(right>=ob){
            ans.push_back(s);
            //cout<<s<<endl;
            return;
        }
        if(left>right){
            func(s+")",left,right+1);
        }
        if(left<ob){
            func(s+"(",left+1,right);
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        if(n==0)return ans;
        string s="";ob=n;
        func(s,0,0);
        return ans;
        
    }
};
```

