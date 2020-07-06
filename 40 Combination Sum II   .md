# 40 Combination Sum II

执行用时 : 40 ms, 在Combination Sum II的C++提交中击败了47.95% 的用户

内存消耗 : 13.1 MB, 在Combination Sum II的C++提交中击败了44.67% 的用户

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> can;
    void func(vector<int> v,int x,int target){
        if(x!=-1)v.push_back(can[x]);
        if(target==0){
            if(find(ans.begin(),ans.end(),v)==ans.end())
            ans.push_back(v);
            return;
        }
        
        for(int i=x+1;i<can.size()&&target>=can[i];i++){
            func(v,i,target-can[i]);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        can=candidates;
        sort(can.begin(),can.end());
        vector<int> v;
        func(v,-1,target);
        return ans;
    }
};
```

1. 重复可以是[1,1,6]，但不能是[1,7] ,[1,7]