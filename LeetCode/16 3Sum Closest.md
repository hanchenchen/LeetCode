# 16 3Sum Closest

执行用时 : 16 ms, 在3Sum Closest的C++提交中击败了87.67% 的用户
内存消耗 : 8.6 MB, 在3Sum Closest的C++提交中击败了90.84% 的用户
```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i=0,j=i+1,k=nums.size()-1;
        int ans=10000000;int ifans=0;
        sort(nums.begin(),nums.end());
        for(;i<nums.size();i++){
            j=i+1,k=nums.size()-1;
            int s;//=nums[i]+nums[j]+nums[k];
            while(j<k){
                s=nums[i]+nums[j]+nums[k];
                if(s>target){
                    int cc=ans>target?ans-target:target-ans;
                    ans=cc<s-target?ans:s;
                    k--;ifans=1;
                }else if(s==target){
                    return target;
                }else{
                    int cc=ans>target?ans-target:target-ans;
                    ans=cc<target-s?ans:s;
                    j++;ifans=1;
                }
            }
        }
        if(ifans)return ans;
        else return 0;
    }
};
```

