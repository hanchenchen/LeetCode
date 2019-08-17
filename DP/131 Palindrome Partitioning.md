# 131 Palindrome Partitioning

1. `Recursion`+`Palindrome`

   执行用时 :44 ms, 在所有 C++ 提交中击败了80.65%的用户

   内存消耗 :57.1 MB, 在所有 C++ 提交中击败了18.49%的用户

   ```c++
   class Solution {
   public:
       vector<vector<string>> ans;
       string s;
       bool arr[200][200];
       void func(vector<string> v,int right){
           v.insert(v.begin(),"");
           if(arr[0][right]){
               v[0]=s.substr(0,right+1);
               ans.push_back(v);
           }
           for(int i=1;i<=right;i++){
               if(arr[i][right]){
                   v[0]=s.substr(i,right-i+1);
                   func(v,i-1);
               }
           }
       }
       vector<vector<string>> partition(string ss) {
           s=ss;
           int n=s.size();
           memset(arr,0,sizeof(arr));
           for(int i=0;i<n;i++){
               arr[i][i]=true;
           }
           for(int i=1;i<n;i++){
               if(s[i]==s[i-1])arr[i-1][i]=true;
           }
           for(int len=3;len<=n;len++){
               for(int i=1;i+len<n+2;i++){
                   if(arr[i][i+len-3]&&(s[i-1]==s[i+len-2])){
                       arr[i-1][i+len-2]=true;
                   }     
               }
           }
           func(vector<string>(),n-1);
           return ans;
       }
   };
   ```

2. 1

