# Best Time to Buy ans Sell Stock I II III

[121][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/] 



[122 II][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/]


123 III

1. dp [ ] [ ] ( 26004长的测试用例，数组遭不住)

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int n=prices.size();
           if(!n)return 0;
           cout<<n<<endl;
           int dp[n][n];
           int times[n][n];
           memset(dp,0,sizeof(dp));
           memset(times,0,sizeof(times));
           for(int i=2;i<=prices.size();i++){
               for(int j=0;j+i<=prices.size();j++){
                   for(int k=0;k<i-1;k++){
                       if(times[j][j+k]+times[j+k][j+i-1]<=2
                          &&dp[j][j+i-1]<dp[j][j+k]+dp[j+k][j+i-1]){
                           dp[j][j+i-1]=dp[j][j+k]+dp[j+k][j+i-1];
                           times[j][j+i-1]=times[j][j+k]+times[j+k][j+i-1];
                       }
                   }
                   if(dp[j][j+i-1]<=prices[j+i-1]-prices[j]){
                       dp[j][j+i-1]=prices[j+i-1]-prices[j];
                       times[j][j+i-1]=1;
                   }
                   cout<<j<<" "<<j+i-1<<" "<<dp[j][j+i-1]<<endl;
               }
           }
           return dp[0][n-1];
       }
   };
   ```

2. 找一个最大差价 ，找两边的最大值，和中间的最大下降值，（ans要么是 最大差价 和另一个较小差价的和，要么是最大差值中的两个最大值）

   执行用时 :8 ms, 在所有 C++ 提交中击败了92.99%的用户

   内存消耗 :9.5 MB, 在所有 C++ 提交中击败了68.60%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           if(prices.size()<1)return 0;
           int ans=0;int m=0;
           int left=0,right=0;
           for(int i=0;i<prices.size();i++){
               if(prices[i]<prices[m]){
                   m=i;
               }
               if(prices[i]-prices[m]>ans){
                   ans=prices[i]-prices[m];
                   left=m;right=i;
               }
           }
           m=0;int a1=0;
           for(int i=0;i<left;i++){
               if(prices[i]<prices[m]){
                   m=i;
               }
               if(prices[i]-prices[m]>a1){
                   a1=prices[i]-prices[m];
               }
           }
           m=right;int a2=0;
           for(int i=right;i<prices.size();i++){
               if(prices[i]<prices[m]){
                   m=i;
               }
               if(prices[i]-prices[m]>a2){
                   a2=prices[i]-prices[m];
               }
           }
           m=right;int a3=0;
           for(int i=right;i>left;i--){
               if(prices[i]<prices[m]){
                   m=i;
               }
               if(prices[i]-prices[m]>a3){
                   a3=prices[i]-prices[m];
               }
           }
           //cout<<a1<<" "<<a2<<" "<<a3<<endl;
           ans=max(max(ans+a1,ans+a2),ans+a3);
           return ans;
       }
   };
   ```

3. 状态转移

   执行用时 :12 ms, 在所有 C++ 提交中击败了72.99%的用户

   内存消耗 :10.2 MB, 在所有 C++ 提交中击败了7.92%的用户

   ```c++
   class Solution {
   public:
       int maxProfit(vector<int>& prices) {
           int n=prices.size();
           if(!n)return 0;
           int dp[n][2][3];// 天 持有 已交易次数
           memset(dp,0,sizeof(dp));
           dp[0][1][1]=-prices[0];
           dp[0][1][2]=-prices[0];
           for(int i=1;i<prices.size();i++){
               dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][0]-prices[i]);
               dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][1]+prices[i]);
               
               dp[i][1][2]=max(dp[i-1][1][2],dp[i-1][0][1]-prices[i]);
               dp[i][0][2]=max(dp[i-1][0][2],dp[i-1][1][2]+prices[i]);
           }
           return dp[n-1][0][2];
       }
   };
   ```

4. dp