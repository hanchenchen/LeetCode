# [122][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/] Best Time to Buy ans Sell Stock II

1. 笨方法（TLE **199 / 201** 个通过测试用例） dp [ ] [ ] 的长度++，由小于n的长度的dp [ ] [ ]算出dp [ ] [ ]

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int n=prices.size();
           if(!n)return 0;
           int dp[n][n];
           memset(dp,0,sizeof(dp));
           for(int i=2;i<=prices.size();i++){
               for(int j=0;j+i<=prices.size();j++){
                   for(int k=0;k<i-1;k++){
                       dp[j][j+i-1]=max(dp[j][j+i-1],dp[j][j+k]+dp[j+k][j+i-1]);
                   }
                   dp[j][j+i-1]=max(prices[j+i-1]-prices[j],dp[j][j+i-1]);
                   //cout<<j<<" "<<j+i-1<<" "<<dp[j][j+i-1]<<endl;
               }
           }
           return dp[0][n-1];
       }
   };
   ```

2. 状态转移 [参考][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen]

   执行用时 :16 ms, 在所有 C++ 提交中击败了19.87%的用户

   内存消耗 :9.6 MB, 在所有 C++ 提交中击败了5.21%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int n=prices.size();
           if(!n)return 0;
           int dp[n][2];// 第i天 持有(0 无 1 有)
           memset(dp,0,sizeof(dp));
           dp[0][1]=-prices[0];
           for(int i=1;i<prices.size();i++){
               dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
               dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
           }
           return dp[n-1][0];
       }
   };
   ```

3. 有差价就卖，买

   执行用时 :8 ms, 在所有 C++ 提交中击败了85.04%的用户

   内存消耗 :9.5 MB, 在所有 C++ 提交中击败了33.90%的用户

4. ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int n=prices.size();
           if(!n)return 0;
           int ans=0;
           for(int i=1;i<n;i++){
               if(prices[i]>prices[i-1])ans+=(prices[i]-prices[i-1]);
           }
           return ans;
       }
   };
   ```