# -135 Candy

1. 左到右、右到左各遍历一遍，取`max`

   *执行用时 :44 ms, 在所有 C++ 提交中击败了34.98%的用户*

   *内存消耗 :11.1 MB, 在所有 C++ 提交中击败了12.89%的用户*

   ```c++
   class Solution {
   public:
       int candy(vector<int>& ratings) {
           int n=ratings.size(),sum=0;
           if(n==1)return 1;
           vector<int> ans1(n+1,1),ans2(n+1,1);
           for(int i=1;i<n;i++){
               if(ratings[i]>ratings[i-1])ans1[i]=ans1[i-1]+1;
           }
           for(int i=n-2;i>=0;i--){
               if(ratings[i]>ratings[i+1])ans2[i]=ans2[i+1]+1;
           }
           for(int i=0;i<n;i++){
               sum+=max(ans1[i],ans2[i]);
           }
           return sum;
       }
   };
   ```

2. 1