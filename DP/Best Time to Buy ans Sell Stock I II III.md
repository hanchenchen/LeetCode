# Best Time to Buy ans Sell Stock I II III

[121][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/] 

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

[122 II][https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/]

1. 笨方法（TLE **199 / 201** 个通过测试用例） dp [ ] [ ]

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