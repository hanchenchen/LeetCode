# [714][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/] Best Time to Buy and Sell Stock with Transaction Fee

1. dp [ ] [ ]

   执行用时 :156 ms, 在所有 C++ 提交中击败了49.70%的用户

   内存消耗 :15.2 MB, 在所有 C++ 提交中击败了63.53%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices, int fee) {
           int n=prices.size();
           if(n<2)return 0;
           int dp[n][2];// 第i天 持有(0 无 1 有)
           memset(dp,0,sizeof(dp));
           dp[0][1]=-prices[0];
           for(int i=1;i<prices.size();i++){
               dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
               dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
           }
           return dp[n-1][0];
       }
   };
   ```

2. int * 2

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices, int fee) {
           int n=prices.size();
           if(n<2)return 0;
           int dp1=-prices[0];
           int dp0=0;
           for(int i=1;i<prices.size();i++){
               dp1=max(dp1,dp0-prices[i]);
               dp0=max(dp0,dp1+prices[i]-fee);
           }
           return dp0;
       }
   };
   ```

   