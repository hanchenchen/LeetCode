# 877 Stone Game

1. ##### Recusion + Memory (计算能赢得多少个石头)

   执行用时 :560 ms, 在所有 C++ 提交中击败了5.10%的用户

   内存消耗 :10 MB, 在所有 C++ 提交中击败了21.20%的用户

   ```c++
   class Solution {
   public:
       vector<int> p;
       int dp[505][505];
       int func(int left,int right){
           if(left==right)return p[left];
           if(right-left==1)return max(p[left],p[right]);
           if(dp[left][right]!=0)return dp[left][right];
           int re=0,sum=0;
           for(int i=left;i<=right;i++){
               sum+=p[i];
           }
           re=sum-func(left+1,right);
           re=max(re,sum-func(left,right-1));
           dp[left][right]=re;
           return re;
       }
       bool stoneGame(vector<int>& piles) {
           p=piles;
           memset(dp,0,sizeof(dp));
           //memset(s,0,sizeof(s));
           int s=0;
           for(int i=0;i<p.size();i++){
               s+=p[i];
           }
           if(func(0,p.size()-1)>s/2)return true;
           return false;
       }
   };
   ```

   

2. ##### Recusion + Memory (计算赢得石头之差)

   执行用时 :52 ms, 在所有 C++ 提交中击败了5.10%的用户

   内存消耗 :9.8 MB, 在所有 C++ 提交中击败了23.60%的用户

   ```c++
   class Solution {
   public:
       vector<int> p;
       int dp[505][505];
       int func(int left,int right){
           if(left==right)return p[left];
           if(right-left==1)return abs(p[left]-p[right]);
           if(dp[left][right]!=0)return dp[left][right];
           int re=0,sum=0;
           re=p[left]-func(left+1,right);
           re=max(re,p[right]-func(left,right-1));
           dp[left][right]=re;
           return re;
       }
       bool stoneGame(vector<int>& piles) {
           p=piles;
           memset(dp,0,sizeof(dp));
           if(func(0,p.size()-1)>0)return true;
           return false;
       }
   };
   ```

3. ##### dp [ ] [ ] （斜着遍历数组）

   执行用时 :20 ms, 在所有 C++ 提交中击败了37.52%的用户

   内存消耗 :9.6 MB, 在所有 C++ 提交中击败了27.60%的用户

   ```c++
   class Solution {
   public:
       bool stoneGame(vector<int>& piles) {
           int n=piles.size();
           int dp[n][n];
           memset(dp,0,sizeof(dp));
           for(int i=0;i<n;i++){
               dp[i][i]=piles[i];
           }
           for(int j=1;j<=n-1;j++){
               for(int i=0;i+j<n;i++){
                   dp[i][i+j]=max(piles[i]-dp[i+1][i+j],piles[i+j]-dp[i][i+j-1]);
               }
           }
           if(dp[0][n-1]>0)return true;
           return false;
       }
   };
   ```

4. 1