# 132 Palindrome Partitioning II

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

3. 

4. 1