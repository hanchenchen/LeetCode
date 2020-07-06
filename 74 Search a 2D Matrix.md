# 74 Search a 2D Matrix

1. 执行出错*2：

   *[[]] 1*

   matrix[0] [0]❌

2. 解答错误：

   *[[1],[3]] 3*

   输出：**false**

   预期：**true**

3. 执行用时 :4 ms, 在所有 C++ 提交中击败了99.84%的用户

   内存消耗 :9.9 MB, 在所有 C++ 提交中击败了74.31%的用户

   ```c++
   class Solution {
   public:
       bool searchMatrix(vector<vector<int>>& matrix, int target) {
           int m=matrix.size();
           if(m==0)return false;
           int n=matrix[0].size();
           if(n==0||target<matrix[0][0])return false;
           int i=0;
           for(;i<m&&target>=matrix[i][0];i++);i--;
           if(target==matrix[i][0])return true;
           int j=0;
           for(;j<n;j++){
               if(matrix[i][j]==target)return true;
           }
           return false;
       }
   };
   ```

   

