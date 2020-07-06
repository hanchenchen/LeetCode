# 1131 Maximum of Absolute Value Expression

1. Manhattan Distance

2. d(i,j)=|X1-X2|+|Y1-Y2|.

3. 执行用时 :32 ms, 在所有 C++ 提交中击败了98.68%的用户

   内存消耗 :11.4 MB, 在所有 C++ 提交中击败了100.00%的用户

4. ```c++
   class Solution {
   public:
       int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
           int len=arr1.size();
           //int s1[len]={0},s2[len]={0},s3[len]={0},s4[len]={0};
           int max1=0,min1=0,max2=0,min2=0,max3=0,min3=0,max4=0,min4=0;
           for(int i=0;i<len;i++){
               max1=max(max1,arr1[i]+arr2[i]+i);
               min1=min(min1,arr1[i]+arr2[i]+i);
               max2=max(max2,arr1[i]-arr2[i]+i);
               min2=min(min2,arr1[i]-arr2[i]+i);
               max3=max(max3,-arr1[i]+arr2[i]+i);
               min3=min(min3,-arr1[i]+arr2[i]+i);            
               max4=max(max4,-arr1[i]-arr2[i]+i);
               min4=min(min4,-arr1[i]-arr2[i]+i);
           }
           return max(max(abs(max1-min1),abs(max2-min2)),max(abs(max3-min3),abs(max4-min4)));
       }
   };
   ```

   