# 53 Maximum subarray

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            if(sum<=0){
                sum=nums[i];
            }else{
                sum+=nums[i];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
```

