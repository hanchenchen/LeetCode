# 69 Sqrt(x)

1. 1e-6：1*10的-6次方

2. 执行用时 :4 ms, 在所有 C++ 提交中击败了94.73%的用户

   内存消耗 :8.3 MB, 在所有 C++ 提交中击败了75.23%的用户

   ```c++
   class Solution {
   public:
       int mySqrt(int x) {
           if(x>=2147395600)return 46340;
           if(x==0)return 0;
           double n=1;
           while(abs(n-(n+x/n)/2)>=1e-6){
               n=(n+x/n)/2;
           }
           return n;
       }
   };
   ```

3. 执行出错：int overflow!!

4. 执行用时 :36 ms, 在所有 C++ 提交中击败了25.83%的用户

   内存消耗 :8.4 MB, 在所有 C++ 提交中击败了73.49%的用户

5. 