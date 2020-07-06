# 78 Subsets

执行用时 :12 ms, 在所有 C++ 提交中击败了85.05%的用户

内存消耗 :9.4 MB, 在所有 C++ 提交中击败了26.58%的用户

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> num;
    void func(int n,int k,vector<int> v){
        v.push_back(num[n]);
        ans.push_back(v);
        if(k==0){
            return;
        }
        for(int i=n-1;i>=0;i--){
            func(i,k-1,v);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        num=nums;
        int k=nums.size();
        vector<int> v;
        for(int i=k-1;i>=0;i--){
            func(i,k-1,v);
        }
        ans.push_back(v);
        return ans;
    }
};
```

