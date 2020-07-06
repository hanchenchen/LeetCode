#  [121][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/] Best Time to Buy ans Sell Stock I

1. 状态转移 [[参考]][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen]

   执行用时 :16 ms, 在所有 C++ 提交中击败了29.85%的用户

   内存消耗 :9.9 MB, 在所有 C++ 提交中击败了5.10%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int n=prices.size();
           if(!n)return 0;
           int dp[n][2][2];// 天 持有 已交易次数
           memset(dp,0,sizeof(dp));
           dp[0][1][1]=-prices[0];
           for(int i=1;i<prices.size();i++){
               dp[i][0][0]=dp[i-1][0][0];
               dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][0]-prices[i]);
               dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][1]+prices[i]);
           }
           return dp[n-1][0][1];
       }
   };
   ```

2. 简化版 dp [ ] [ ]

   执行用时 :12 ms, 在所有 C++ 提交中击败了60.68%的用户

   内存消耗 :9.6 MB, 在所有 C++ 提交中击败了16.09%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int n=prices.size();
           if(!n)return 0;
           int dp[n][2];// 天 持有 已交易次数
           memset(dp,0,sizeof(dp));
           dp[0][1]=-prices[0];
           for(int i=1;i<prices.size();i++){
               dp[i][1]=max(dp[i-1][1],-prices[i]);
               dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
           }
           return dp[n-1][0];
       }
   };
   ```

3. int * 2

   执行用时 :20 ms, 在所有 C++ 提交中击败了20.41%的用户

   内存消耗 :9.5 MB, 在所有 C++ 提交中击败了44.57%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int n=prices.size();
           if(!n)return 0;
           int dp_i_0=0,dp_i_1=-prices[0];
           for(int i=1;i<prices.size();i++){
               dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
               dp_i_1=max(dp_i_1,-prices[i]);
           }
           return dp_i_0;
       }
   };
   ```

4. 记录前 i 个的最低价，找 prices[ i ] 和 前 i 天的最低价 最大的一天

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           if(prices.size()<1)return 0;
           int ans=0;int m=prices[0];
           for(int i=0;i<prices.size();i++){
               if(prices[i]<m){
                   m=prices[i];
               }
               ans=max(ans,prices[i]-m);
           }
           return ans;
       }
   };
   ```

5. 1
