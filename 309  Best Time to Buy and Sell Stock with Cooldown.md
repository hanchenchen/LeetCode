# [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

#### 方法一：动态规划

#### Python3

执行用时：52 ms, 在所有 Python3 提交中击败了72.99%的用户

内存消耗：13.7 MB, 在所有 Python3 提交中击败了9.09%的用户

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<2:
            return 0
        dp = [0,0,0]
        dp[0] = 0 # have no stock and can buy a stock
        dp[1] = 0 # cooldown
        dp[2] = -prices[0] # have a stock
        for i in range(1,len(prices)):
            dp[0], dp[1], dp[2] = max(dp[1], dp[0]), (dp[2] + prices[i]), max(dp[2],dp[0]-prices[i])
        return max(dp[0],dp[1])
```


##### C++

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


