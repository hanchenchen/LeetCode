# 70 Climbing Stairs

<!--暴力法+记忆数组-->

1. 执行用时 :24 ms, 在所有 C++ 提交中击败了7.11%的用户

   内存消耗 :12.4 MB, 在所有 C++ 提交中击败了5.01%的用户

   ```c++
   class Solution {
   public:
       int arr[1000000]={0};
       int climbStairs(int n) {
           if(n==1||n==2)return n;
           if(arr[n]==0)
               arr[n]=climbStairs(n-1)+climbStairs(n-2);
           return arr[n];
       }
   };
   ```

2. 超出时间限制

   ```c++
   class Solution {
   public:
       //int arr[1000000]={0};
       int climbStairs(int n) {
           if(n==1||n==2)return n;
           //if(arr[n]==0)
               //arr[n]=climbStairs(n-1)+climbStairs(n-2);
           //return arr[n];
           return climbStairs(n-1)+climbStairs(n-2);
       }
   };
   ```

3. 执行用时 :8 ms, 在所有 C++ 提交中击败了60.60%的用户

   内存消耗 :8.4 MB, 在所有 C++ 提交中击败了41.78%的用户

   ```c++
   class Solution {
   public:
       int arr[100]={0};
       int climbStairs(int n) {
           if(n==1||n==2)return n;
           if(arr[n]==0)
               arr[n]=climbStairs(n-1)+climbStairs(n-2);
           return arr[n];
       }
   };
   ```

   

<!--斐波那契数 空间 O（1）-->

1. 执行用时 :4 ms, 在所有 C++ 提交中击败了91.17%的用户

   内存消耗 :8.3 MB, 在所有 C++ 提交中击败了65.15%的用户

   ```c++
   class Solution {
   public:
       int climbStairs(int n) {
           if(n<=3)return n;
           int a=1,b=2;
           int ans;
           for(int i=3;i<=n;i++){
               ans=a+b;
               a=b;
               b=ans;
           }
           return ans;
       }
   };
   ```

   



