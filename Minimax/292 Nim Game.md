# 292 Nim Game

1. `Recursion	` `TLE` **39 / 60** 个通过测试用例

2. `Recursion`+`Memory`

   `1348820612`: `overflow` **50 / 60** 个通过测试用例

   ```c++
   class Solution {
   public:
       int dp[1000]={0};
       bool canWinNim(int n) {
           if(dp[n]!=0)return dp[n]==1;
           if(n==0)return false;
           if(n<=3)return true;
           for(int i=1;i<=3;i++){
               if(!canWinNim(n-i)){dp[n]=1;return true;}
           }
           dp[n]=-1;
           return false;
       }
   };
   ```

3. 找规律可以得到 当`n%4==0`时，return false;

   ```c++
   class Solution {
   public:
       bool canWinNim(int n) {
           return n%4!=0;
       }
   };
   ```

   

## Bash_Game 巴什博奕

> #### if(`n%(m+1)==0`)return false;

