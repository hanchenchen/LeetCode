# [118][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/] Best Time to Buy ans Sell Stock IV

1. 状态转移

   当k>n/2时，令k=n/2。（第一天买，第二天卖、买，第三天卖==第一天买，第三天卖）

   执行用时 :920 ms, 在所有 C++ 提交中击败了5.53%的用户

   内存消耗 :9 MB, 在所有 C++ 提交中击败了35.95%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(int k, vector<int>& prices) {
           int n=prices.size();
           if(!n||!k)return 0;
           if(k>=n/2)k=n/2;
           //cout<<n<<endl;
           int dp[2][k+1];// 天 持有 已交易次数
           memset(dp,0,sizeof(dp));
           for(int j=k;j>=0;j--){
               dp[1][j]=-prices[0];
           }
           for(int i=1;i<prices.size();i++){
               for(int j=k;j>=1;j--){
                   if(dp[1][j]+prices[i]>dp[0][j]){
                       dp[0][j]=dp[1][j]+prices[i];
                   }
                   if(dp[0][j-1]-prices[i]>dp[1][j]){
                       dp[1][j]=dp[0][j-1]-prices[i];
                   }
               }
           }
           return dp[0][k];
       }
   };
   ```

2. 当k>n/2时，直接采用 [Best Time to Buy ans Sell Stock II ][https://github.com/hanchenchen/LeetCode/blob/master/DP/Buy%20ans%20Sell%20Stock/122%20Best%20Time%20to%20Buy%20ans%20Sell%20Stock%20II.md]中有差价就卖出的方式

   执行用时 :8 ms, 在所有 C++ 提交中击败了91.91%的用户

   内存消耗 :9 MB, 在所有 C++ 提交中击败了51.63%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(int k, vector<int>& prices) {
           int n=prices.size();
           if(!n||!k)return 0;
           if(k>=n/2){
           int dp[n][2];
           memset(dp,0,sizeof(dp));
           dp[0][1]=-prices[0];
           for(int i=1;i<prices.size();i++){
               dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
               dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
           }
           return dp[n-1][0];
           }
           //cout<<n<<endl;
           int dp[2][k+1];// 天 持有 已交易次数
           memset(dp,0,sizeof(dp));
           for(int j=k;j>=0;j--){
               dp[1][j]=-prices[0];
           }
           for(int i=1;i<prices.size();i++){
               for(int j=k;j>=1;j--){
                   if(dp[1][j]+prices[i]>dp[0][j]){
                       dp[0][j]=dp[1][j]+prices[i];
                   }
                   if(dp[0][j-1]-prices[i]>dp[1][j]){
                       dp[1][j]=dp[0][j-1]-prices[i];
                   }
               }
           }
           return dp[0][k];
       }
   };
   ```

   