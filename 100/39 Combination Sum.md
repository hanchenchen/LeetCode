# 39 Combination Sum

执行用时 : 28 ms, 在Combination Sum的C++提交中击败了80.46% 的用户

内存消耗 : 11.9 MB, 在Combination Sum的C++提交中击败了51.52% 的用户

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> can;
    void func(vector<int> v,int x,int target){

        //cout<<target<<endl;
        if(x!=0)v.push_back(x);
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<can.size()&&target>=can[i];i++){
            if(can[i]>=x)
                func(v,can[i],target-can[i]);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        can=candidates;
        sort(can.begin(),can.end());
        vector<int> v;
        func(v,0,target);
        return ans;
    }
};
```

