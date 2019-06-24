# 73 Set Matrix Zeros

1. O(m+n) space

   执行用时 :128 ms, 在所有 C++ 提交中击败了17.06%的用户

   内存消耗 :11.5 MB, 在所有 C++ 提交中击败了39.52%的用户

   ```c++
   class Solution {
   public:
       void setZeroes(vector<vector<int>>& matrix) {
           int m=matrix.size();
           if(m==0)return;
           int n=matrix[0].size();
           int c[m]={0};
           int r[n]={0};
           for(int i=0;i<m;i++){
               for(int j=0;j<n;j++){
                   if(matrix[i][j]==0){
                       c[i]=1;r[j]=1;
                   }
               }
           }
           for(int i=0;i<m;i++){
               for(int j=0;j<n;j++){
                   if(c[i]==1||r[j]==1){
                       matrix[i][j]=0;
                   }
               }
           }
       }
   };
   ```

   

2. O(1) space

   执行用时 :72 ms, 在所有 C++ 提交中击败了83.87%的用户

   内存消耗 :11.5 MB, 在所有 C++ 提交中击败了34.44%的用户

   ```c++
   class Solution {
   public:
       void setZeroes(vector<vector<int>>& matrix) {
           int m=matrix.size();
           if(m==0)return;
           int n=matrix[0].size();
           //int c[m]={0};
           //int r[n]={0};
           int c=0,r=0;
           for(int i=0;i<m;i++){
               if(matrix[i][0]==0){c=1;break;}
           }
           for(int i=0;i<n;i++){
               if(matrix[0][i]==0){r=1;break;}
           }
           for(int i=0;i<m;i++){
               for(int j=0;j<n;j++){
                   if(matrix[i][j]==0){
                       matrix[i][0]=0;matrix[0][j]=0;
                   }
               }
           }
           for(int i=1;i<m;i++){
               if(matrix[i][0]==0)
                   for(int j=0;j<n;j++){
                       matrix[i][j]=0;
                   }
           }
           for(int j=1;j<n;j++){
               if(matrix[0][j]==0)
                   for(int i=0;i<m;i++){
                       matrix[i][j]=0;
                   }
           }
           if(c==1)for(int i=0;i<m;i++){
               matrix[i][0]=0;
           }
           if(r==1)for(int i=0;i<n;i++){
               matrix[0][i]=0;
           }
       }
   };
   ```

   