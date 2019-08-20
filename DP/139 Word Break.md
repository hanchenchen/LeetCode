# 139 Word Break

1. `Recusion`+`Memory`

   执行用时 :8 ms, 在所有 C++ 提交中击败了91.85%的用户

   内存消耗 :10.9 MB, 在所有 C++ 提交中击败了73.44%的用户

   ```c++
   class Solution {
   public:
       vector<string> word['z'+1];
       map<string,bool> m;
       bool func(string s){
           if(s=="")return true;
           if(m.find(s)!=m.end())return m[s];
           int len=0;
           for(int i=0;i<word[s[0]].size();i++){
               len=word[s[0]][i].size();
               if(s.substr(0,len)==word[s[0]][i]&&func(s.substr(len,s.size()-len)))
               {m.insert(pair<string,bool>(s,1));return true;}
           }
           m.insert(pair<string,bool>(s,0));
           return false;
       }
       bool wordBreak(string s, vector<string>& wordDict) {
           for(int i=0;i<wordDict.size();i++){
               word[wordDict[i][0]].push_back(wordDict[i]);
           }
           return func(s);
       }
   };
   ```

2. `dp[][]`

   执行用时 :12 ms, 在所有 C++ 提交中击败了81.37%的用户

   内存消耗 :8.6 MB, 在所有 C++ 提交中击败了98.58%的用户

   - `s.size()`是`unsigned long`，与`int`运算会有误差。

   ```c++
   class Solution {
   public:
       bool wordBreak(string s, vector<string>& wordDict) {
           int n=s.size();
           bool ifmatched[n][n];
           bool dp[n]={0};
           memset(ifmatched,0,sizeof(ifmatched));
           for(int i=0;i<wordDict.size();i++){
               int len=wordDict[i].size();
               for(int j=0;j<1+(int)s.size()-len;j++){//j<1+s.size()-len WA
                   if(s.substr(j,len)==wordDict[i])ifmatched[j][j+len-1]=true;
               }
           }
           for(int i=0;i<n;i++){
               if(ifmatched[0][i]){
                   dp[i]=true;
                   //cout<<dp[i]<<endl;
                   continue;
               }
               for(int j=0;j<i;j++){
                   if(dp[j]&&ifmatched[j+1][i]){
                       dp[i]=true;
                       break;
                   }
               }
               //cout<<dp[i]<<endl;
           }
           return dp[n-1];
       }
   };
   ```

3. 1