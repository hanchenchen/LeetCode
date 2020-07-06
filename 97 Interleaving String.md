# 97 Interleaving String

1. arr[]

   执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

   内存消耗 :8.1 MB, 在所有 C++ 提交中击败了98.83%的用户

   ```c++
   class Solution {
   public:
       bool isInterleave(string s1, string s2, string s3) {
           int len1=s1.size();
           int len2=s2.size();
           bool arr[len1+1];
           if(s3.size()!=len1+len2)return false;
           arr[0]=true;
           int i=1;
           for(;i<=len1;i++){
               if(s3[i-1]==s1[i-1])arr[i]=true;
               else break;
           }
           for(;i<=len1;i++){
               arr[i]=false;
           }
           for(int j=1;j<=len2;j++){
               arr[0]=arr[0]&&s2[j-1]==s3[j-1];
               for(i=1;i<=len1;i++){
                   arr[i]=(arr[i-1]&&s1[i-1]==s3[i+j-1])||(arr[i]&&s2[j-1]==s3[i+j-1]);
               }
           }
           /*
           for(i=0;i<=len1;i++){
               cout<<arr[i]<<endl;
           }
           //*/
           return arr[len1];
       }
   };
   ```

2. arr [ ]  [ ]

   执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

   内存消耗 :8.3 MB, 在所有 C++ 提交中击败了89.47%的用户

3. ```c++
   class Solution {
   public:
       bool isInterleave(string s1, string s2, string s3) {
           int len1=s1.size();
           int len2=s2.size();
           bool arr[len1+1][len2+1];
           if(s3.size()!=len1+len2)return false;
           arr[0][0]=true;
           int i=1,j=1;
           for(;i<=len1;i++){
               if(s3[i-1]==s1[i-1])arr[i][0]=true;
               else break;
           }
           for(;i<=len1;i++){
               arr[i][0]=false;
           }
           for(;j<=len2;j++){
               if(s3[j-1]==s2[j-1])arr[0][j]=true;
               else break;
           }
           for(;j<=len2;j++){
               arr[0][j]=false;
           }
           for(i=1;i<=len1;i++){
               for(j=1;j<=len2;j++){
                   if(arr[i-1][j]&&s1[i-1]==s3[i+j-1]){
                       arr[i][j]=true;
                   }else if(arr[i][j-1]&&s2[j-1]==s3[i+j-1]){
                       arr[i][j]=true;
                   }else{
                       arr[i][j]=false;
                   }
               }
           }
           /*
           for(i=0;i<=len1;i++){
               for(j=0;j<=len2;j++){
                   cout<<arr[i][j]<<" ";
               }
               cout<<endl;
           }
           //*/
           return arr[len1][len2];
       }
   };
   ```