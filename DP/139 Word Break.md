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

2. 1