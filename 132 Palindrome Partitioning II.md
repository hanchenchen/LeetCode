# 132 Palindrome Partitioning II

1. `LIS` + `Palindrome` 

2. `dp[i]` 表示`s0-si` 需要分割多少次

   - 如果`arr[0][i]`为`true`，即`s0-si`为回文串，那么`dp[i]`==`0`
   - 如果 `arr[left][i]`为`true`，即`s0-si`为回文串，那么 `dp[i]` 可以等于` dp[left-1] +1`
   - 循环`left`，找到最小的`dp[i]`值

3. `Recursion`

   执行用时 :20 ms, 在所有 C++ 提交中击败了87.12%的用户

   内存消耗 :10.9 MB, 在所有 C++ 提交中击败了38.76%的用户

   ```c++
   class Solution {
   public:
      	bool arr[1500][1500];
       int dp[1500]={0};
       int func(int right){
           if(arr[0][right]||dp[right]){
               return dp[right];
           }
           dp[right]=INT_MAX;
           for(int i=1;i<=right;i++){
               if(arr[i][right])dp[right]=min(func(i-1),dp[right]);
           }
           dp[right]+=1;
           return dp[right];
       }
       int minCut(string s) {
           int n=s.size();
           if(n<2)return 0;
           memset(arr,0,sizeof(arr));
           for(int i=0;i<n;i++){
               arr[i][i]=true;
           }
           for(int i=1;i<n;i++){
               if(s[i]==s[i-1])arr[i-1][i]=true;
           }
           for(int len=3;len<=s.size();len++){
               for(int i=1;i+len<n+2;i++){
                   if(arr[i][i+len-3]&&(s[i-1]==s[i+len-2])){
                       arr[i-1][i+len-2]=true;
                   }     
               }
           }
           if(arr[0][n-1])return 0;
           func(n-1);
           return dp[n-1];
       }
   };
   ```

4. `Iteration`

   执行用时 :20 ms, 在所有 C++ 提交中击败了87.12%的用户

   内存消耗 :11 MB, 在所有 C++ 提交中击败了37.64%的用户

   ```c++
   class Solution {
   public:
       int minCut(string s) {
           int n=s.size();
           if(n<2)return 0;
           bool arr[n][n];
           memset(arr,0,sizeof(arr));
           for(int i=0;i<n;i++){
               arr[i][i]=true;
           }
           for(int i=1;i<n;i++){
               if(s[i]==s[i-1])arr[i-1][i]=true;
           }
           for(int len=3;len<=s.size();len++){
               for(int i=1;i+len<n+2;i++){
                   if(arr[i][i+len-3]&&(s[i-1]==s[i+len-2])){
                       arr[i-1][i+len-2]=true;
                   }     
               }
           }
           if(arr[0][n-1])return 0;
           int dp[n]={0};int left=0;
           for(int len=1;len<n;len++){
               if(arr[0][len]){
                   continue;
               }
               dp[len]=INT_MAX;
               for(int i=1;i<=len;i++){
                   if(arr[i][len])dp[len]=min(dp[i-1],dp[len]);
               }
               dp[len]+=1;
           }
           return dp[n-1];
       }
   };
   ```

#### 没有AC的：

1. ##### Recursion _超出时间限制🚫 **21 / 29** 个通过测试用例

   ```c++
   class Solution {
   public:
       int minCut(string s) {
           if(s==""||s.size()==1)return 0;
           int i=0;
           for(;i<s.size()/2;i++){
               if(s[i]!=s[s.size()-i-1])break;
           }
           if(i==s.size()/2)return 0;
           int ans=INT_MAX;
           int left=0,right=0;
           for(i=1;i<s.size();i++){
               left=minCut(s.substr(0,i));
               right=minCut(s.substr(i,s.size()-i));
               ans=min(left+right,ans);
           }
           return ans+1;
       }
   };
   ```

2. ##### Recursion+Memory _超出时间限制🚫 **23 / 29** 个通过测试用例

   ```c++
   class Solution {
   public:
       map<string,int> dp;
       map<string,int>::iterator iter;
       int minCut(string s) {
           if(s==""||s.size()==1)return 0;
           iter =dp.find(s);
           if(iter!=dp.end())return iter->second;
           int i=0;
           for(;i<s.size()/2;i++){
               if(s[i]!=s[s.size()-i-1])break;
           }
           if(i==s.size()/2)return 0;
           int ans=INT_MAX;
           int left=0,right=0;
           for(i=1;i<s.size();i++){
               left=minCut(s.substr(0,i));
               right=minCut(s.substr(i,s.size()-i));
               ans=min(left+right,ans);
           }
           dp.insert(pair<string,int>(s,ans+1));
           return ans+1;
       }
   };
   ```

   