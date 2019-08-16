# 198 House Robber

### < LIS >

执行用时 :4 ms, 在所有 C++ 提交中击败了77.81%的用户

内存消耗 :8.5 MB, 在所有 C++ 提交中击败了91.08%的用户

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(!n)return 0;
        if(n==1)return nums[0];
        int ans=max(nums[0],nums[1]);
        if(n==2)return ans;
        int dp[n];
        dp[0]=nums[0];dp[1]=nums[1];
        for(int i=2;i<n;i++){
            dp[i]=0;
            for(int j=0;j<i-1;j++){
                dp[i]=max(dp[i],dp[j]);
            }
            dp[i]+=nums[i];
            ans=max(dp[i],ans);
        }
        return ans;
    }
};
```

1. 长度为 1、2时，需要特别处理