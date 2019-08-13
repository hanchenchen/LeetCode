# [118][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/] Best Time to Buy ans Sell Stock IV

1. 状态转移

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

2. 当k>n/2时，直接采用 Best Time to Buy ans Sell Stock II 