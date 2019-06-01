# 46 Permutations

执行用时 : 20 ms, 在Permutations的C++提交中击败了92.41% 的用户

内存消耗 : 10.7 MB, 在Permutations的C++提交中击败了6.76% 的用户

```c++
class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> v,int x){
        if(x==0){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<x;i++){
            int mid = v[i];
            v[i]=v[x];
            v[x]=mid;
            func(v,x-1);
            v[x] = v[i];
            v[i]=mid;
        }
        func(v,x-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        func(nums,nums.size()-1);
        return ans;
    }
};
```

