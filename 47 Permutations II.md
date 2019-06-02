# 47 Permutations II

执行用时 : 36 ms, 在Permutations II的C++提交中击败了95.04% 的用户

内存消耗 : 13.6 MB, 在Permutations II的C++提交中击败了11.80% 的用户

```c++

class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> v,int x){
        if(x==0){
            ans.push_back(v);
            return;
        }
        sort(v.begin(),v.begin()+x);
        for(int i=0;i<x;i++){
            if(v[i]==v[x]||v[i]==v[i+1])continue;
            int mid = v[i];
            v[i]=v[x];
            v[x]=mid;
            func(v,x-1);
            v[x] = v[i];
            v[i]=mid;
        }
        func(v,x-1);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        func(nums,nums.size()-1);
        //sort(ans.begin(),ans.end());
        return ans;
    }
};
```

