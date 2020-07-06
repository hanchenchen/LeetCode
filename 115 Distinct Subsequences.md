# 115 Distinct Subsequences

1. DFS(TLE)

   ```c++
   class Solution {
   public:
       string S,T;
       int ans=0;
       int func(int i,int j,int matched){
           if(matched==T.size()){
               ans++;
               return;
           }
           if(i==S.size()||j==T.size())return;
           func(i+1,j,matched);
           if(S[i]==T[j])func(i+1,j+1,matched+1);
       }
       int numDistinct(string s, string t) {
           S=s;
           T=t;
           func(0,0,0);
           return ans;
       }
   };
   ```

2. Dynamic Programing

   int dp[ ] [ ]  -> long long dp[ ] [ ]

   **Line 15: Char 43: runtime error: signed integer overflow: 2073949853 + 592325108 cannot be represented in type 'int' (solution.cpp)**

3. Dynamic Programing

4. dp [ ] 

   执行用时 :8 ms, 在所有 C++ 提交中击败了92.98%的用户

   内存消耗 :8.5 MB, 在所有 C++ 提交中击败了95.98%的用户

   ```c++
   class Solution {
   public:
       int numDistinct(string s, string t) {
           if(s.size()==0)return 0;
           long long dp[t.size()+1]={0};
           dp[0]=1;
           for(int i=1;i<=s.size();i++){
               for(int j=t.size();j>=1;j--){
                   if(s[i-1]==t[j-1])dp[j]+=dp[j-1];
               }
           }
           return dp[t.size()];
       }
   };
   ```

5. dp [ ] [ ]

   执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

   内存消耗 :13.1 MB, 在所有 C++ 提交中击败了59.20%的用户

   ```c++
   class Solution {
   public:
       int numDistinct(string s, string t) {
           int slen=s.size(),tlen=t.size();
           long long dp[tlen+1][slen+1];
           for(int i=0;i<=tlen;i++){
               dp[i][0]=0;
           }
           for(int i=0;i<=slen;i++){
               dp[0][i]=1;
           }
           for(int i=1;i<=tlen;i++){
               for(int j=1;j<=slen;j++){
                   dp[i][j]=dp[i][j-1];
                   if(s[j-1]==t[i-1])dp[i][j]+=dp[i-1][j-1];
               }
           }
           return dp[tlen][slen];
       }
   };
   ```

   