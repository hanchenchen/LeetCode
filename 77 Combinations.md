# 77 Combinations

执行用时 :120 ms, 在所有 C++ 提交中击败了83.66%的用户

内存消耗 :19 MB, 在所有 C++ 提交中击败了31.60%的用户

```c++
class Solution {
public:
    vector<vector<int>> ans;
    void func(int n,int k,vector<int> v){
        v.push_back(n);
        if(k==0){
            ans.push_back(v);
            return;
        }
        for(int i=n-1;i>=k;i--){
            func(i,k-1,v);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        for(int i=n;i>=k;i--){
            func(i,k-1,v);
        }
        //sort(ans.begin(),ans.end());
        return ans;
    }
};
```

