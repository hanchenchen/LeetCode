# 139 Word Break

1. `Recusion`+`Memory`+`Array` 

   执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

   内存消耗 :8.7 MB, 在所有 C++ 提交中击败了96.07%的用户

   ```c++
   class Solution {
   public:
       vector<string> word['z'+1];
       int dp[1000];
       string s;int n;
       bool func(int index){
           if(index==n)return true;
           if(dp[index]!=-1)return dp[index];
           int len=0;
           for(int i=0;i<word[s[index]].size();i++){
               len=word[s[index]][i].size();
               if(n-index>=len&&s.substr(index,len)==word[s[index]][i]&&func(index+len))
               {dp[index]=1;return true;}
           }
           dp[index]=0;
           return false;
       }
       bool wordBreak(string str, vector<string>& wordDict) {
           memset(dp,-1,sizeof(dp));
           s=str;
           n=(int)s.size();
           for(int i=0;i<wordDict.size();i++){
               word[wordDict[i][0]].push_back(wordDict[i]);
           }
           return func(0);
       }
   };
   ```

2. `Recusion`+`Memory`+`Map` 

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

3. `Iteration`+`dp[][]`

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

4. `Queue` TLE 

   **29 / 36** 个通过测试用例

   ```c++
   class Solution {
   public:
       bool wordBreak(string s, vector<string>& wordDict) {
           int n=(int)s.size();
           bool ifmatched[n][n];
           bool dp[n]={0};
           memset(ifmatched,0,sizeof(ifmatched));
           for(int i=0;i<wordDict.size();i++){
               int len=wordDict[i].size();
               for(int j=0;j<1+n-len;j++){
                   if(s.substr(j,len)==wordDict[i])ifmatched[j][j+len-1]=true;
               }
           }
           queue<int> q;
           q.push(-1);
           while(!q.empty()){
               int x=q.front()+1;q.pop();
               if(x==n)return true;
               for(int j=x;j<n;j++){
                   if(ifmatched[x][j])q.push(j);
               }
           }
           return false;
       }
   };
   ```

5. 1