# Best Time to Buy ans Sell Stock I II III

121 记录前 i 个的最低价，找 prices[ i ] 和 前 i 天的最低价 最大的一天

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

122 II

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

2. 有差价就卖，买

   执行用时 :8 ms, 在所有 C++ 提交中击败了85.04%的用户

   内存消耗 :9.5 MB, 在所有 C++ 提交中击败了33.90%的用户

3. ```c++
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

2. 找两个最大差价 