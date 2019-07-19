# 96 Unique Binary Search Trees

1. dynamic plan

   执行用时 :4 ms, 在所有 C++ 提交中击败了82.42%的用户

   内存消耗 :8.1 MB, 在所有 C++ 提交中击败了80.45%的用户

   ```c++
   class Solution {
   public:
       int arr[10000]={0};
       int numTrees(int n) {
           if(n==0)return 1;
           if(arr[n])return arr[n];
           int re=0;
           for(int i=1;i<=n;i++){
               int left=numTrees(i-1);
               int right=numTrees(n-i);
               re=re+left*right;
           }
           arr[n]=re;
           return re;
       }
   };
   ```

2. [Catalan number][https://baike.baidu.com/item/卡特兰数/6125746?fr=aladdin]

   1. h(0)=h(1)=1
   2. h(n)=h(n-1)* (4 *n-2)(n+1)
   3. h(n)=c(2n,n)/(n+1)

   执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

   内存消耗 :8 MB, 在所有 C++ 提交中击败了91.76%的用户

   ```c++
   class Solution {
   public:
       int numTrees(int n) {
           if(n<2)return 1;
           unsigned long long ans=2;//!!!!
           for(int i=3;i<=n;i++){
               ans=ans*(4*i-2)/(i+1);
           }
           return ans;
       }
   };
   ```

   

