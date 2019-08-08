# 28 Inplement strStr()

1. 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

   内存消耗 :9 MB, 在所有 C++ 提交中击败了86.66%的用户

   ```c++
   class Solution {
   public:
       int strStr(string haystack, string needle) {
           int ha=haystack.size();
           int ne=needle.size();
           if(!ne)return 0;
           if(ne>ha||!ha)return -1;
   
           for(int i=0;i<=ha-ne;i++){
               int j=0;
               for(;j<ne;j++){
                   if(haystack[i]==needle[j]){
                       i++;
                   }else{
                       break;
                   }
               }
               if(j==ne)return i-j;
               i=i-j;
           }
           return -1;
       }
   };
   ```

2. 超出时间限制   [测试用例94][https://leetcode-cn.com/submissions/detail/22759089/testcase/]

   ```c++
   class Solution {
   public:
       int strStr(string haystack, string needle) {
           int ha=haystack.size();
           int ne=needle.size();
           if(!ne)return 0;
           if(ne>ha||!ha)return -1;
           int arr[ha];
           memset(arr,0,sizeof(arr));
           for(int j=0;j<ne;j++){
               for(int i=ha-1;i>=j;i--){
                   //cout<<i<<" "<<j<<endl;
                   if(haystack[i]==needle[j]&&(j==0||arr[i-1]==1))arr[i]=1;
                   else arr[i]=0;
                   //cout<<arr[i][j];
               }
               //cout<<endl;
           }
           
           for(int i=ne-1;i<ha;i++){
               //cout<<arr[i]<<endl;
               if(arr[i]==1)return i-ne+1;
           }
           return -1;
       }
   };
   ```

3. 执行用时 :4 ms, 在所有 C++ 提交中击败了95.71%的用户

   内存消耗 :9.2 MB, 在所有 C++ 提交中击败了75.01%的用户

   ```c++
   class Solution {
   public:
       int strStr(string haystack, string needle) {
           int ha=haystack.size();
           int ne=needle.size();
           if(!ne)return 0;
           if(ne>ha||!ha)return -1;
           for(int i=0;i<=ha-ne;i++){
               if(haystack.substr(i,ne)==needle)return i;
           }
           return -1;
       }
   };
   ```

   

