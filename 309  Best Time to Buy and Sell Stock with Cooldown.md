# [309][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/]  Best Time to Buy and Sell Stock with Cooldown

执行用时 :8 ms, 在所有 C++ 提交中击败了60.69%的用户

内存消耗 :8.5 MB, 在所有 C++ 提交中击败了94.18%的用户

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)return 0;
        int dp[n][2];// 第i天 持有(0 无 1 有)
        memset(dp,0,sizeof(dp));
        dp[0][1]=-prices[0];
        dp[1][1]=max(dp[0][1],-prices[1]);
        dp[1][0]=max(dp[0][0],dp[0][1]+prices[1]);
        for(int i=2;i<prices.size();i++){
            dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i]);
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
        }
        return dp[n-1][0];
    }
};
```