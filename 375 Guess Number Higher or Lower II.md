# 375 Guess Number Higher or Lower II

1. `Recusion` 

   TLE **8 / 13** 个通过测试用例

   ```c++
   class Solution {
   public:
       int func(int left,int right){
           if(left>=right)return 0;
           int x=1e7;
           for(int i=left;i<=right;i++){
               x=min(max(func(left,i-1),func(i+1,right))+i,x);
           }
           return x;
       }
       int getMoneyAmount(int n) {
           return func(1,n);
       }
   };
   ```

2. `Recusion` +`Memory`

   1. `fill(memory[0],memory[0]+1000*1000,0);`
      - `memory[1000][1000]`首地址为`memory[0]`
   2. `memset(memory,0,sizeof(memory));`
      - 按字节赋值，只用于0、-1
      - sizeof(int)==4

   *执行用时 :128 ms, 在所有 C++ 提交中击败了5.08%的用户*

   *内存消耗 :12 MB, 在所有 C++ 提交中击败了5.83%的用户*

   ```c++
   class Solution {
   public:
       int memory[1000][1000];
       int func(int left,int right){
           if(left>=right)return 0;
           if(memory[left][right])return memory[left][right];
           int x=1e7;
           for(int i=left;i<=right;i++){
               x=min(max(func(left,i-1),func(i+1,right))+i,x);
           }
           memory[left][right]=x;
           return x;
       }
       int getMoneyAmount(int n) {
           fill(memory[0],memory[0]+1000*1000,0);
           return func(1,n);
       }
   };
   ```

3. `DP[][]` `len++`

   *执行用时 :48 ms, 在所有 C++ 提交中击败了27.12%的用户*

   *内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户*

   ```c++
   class Solution {
   public:
       int getMoneyAmount(int n) {
           int dp[n+1][n+1];
           fill(dp[0],dp[0]+(n+1)*(n+1),0);
           for(int len=2;len<=n;len++){
               for(int i=1;i+len-1<=n;i++){
                   dp[i][i+len-1]=i+dp[i+1][i+len-1];
                   for(int j=i+1;j<i+len-1;j++){
                       dp[i][i+len-1]=min(max(dp[i][j-1],dp[j+1][i+len-1])+j,dp[i][i+len-1]);
                   }
                   dp[i][i+len-1]=min(i+len-1+dp[i][i+len-2],dp[i][i+len-1]);
               }
           }
           return dp[1][n];
       }
   };
   ```

4. `DP[][]` `len++` 剪枝

   执行用时 :16 ms, 在所有 C++ 提交中击败了94.58%的用户

   内存消耗 :8.4 MB, 在所有 C++ 提交中击败了90.29%的用户

   ```c++
   class Solution {
   public:
       int getMoneyAmount(int n) {
           int dp[n+1][n+1];
           fill(dp[0],dp[0]+(n+1)*(n+1),0);
           for(int len=2;len<=n;len++){
               for(int i=1;i+len-1<=n;i++){
                   int right=i+len-1;
                   dp[i][right]=i+dp[i+1][right];
                   for(int j=(i+right)/2;j<i+len-1;j++){
                       dp[i][right]=min(max(dp[i][j-1],dp[j+1][right])+j,dp[i][right]);
                   }
                   dp[i][right]=min(i+len-1+dp[i][right-1],dp[i][right]);
               }
           }
           return dp[1][n];
       }
   };
   ```

5. 1