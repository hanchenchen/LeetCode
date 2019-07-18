# 87 Scramble String

1. s.substr(x,n):

   从第x位截取长度为n的字符串

2. 递归

   执行用时 :12 ms, 在所有 C++ 提交中击败了84.81%的用户

   内存消耗 :9.7 MB, 在所有 C++ 提交中击败了80.70%的用户

   ```c++
   class Solution {
   public:
       bool isScramble(string s1, string s2) {
           //cout<<s1<<endl;
           //cout<<s2<<endl;
           if(s1==s2)return true;
           if(s1.size()!=s2.size())return false;
           int len=s1.size();
           int arr['z'-'a'+1]={0};
           for(int i=0;i<s1.size();i++){
               arr[s1[i]-'a']++;
               arr[s2[i]-'a']--;
           }
           for(int i=0;i<'z'-'a'+1;i++){
               if(arr[i]!=0)return false;
           }
           for(int i=1;i<s1.size();i++){
               if(isScramble(s1.substr(0,i),s2.substr(0,i))
                  &&isScramble(s1.substr(i,len-i),s2.substr(i,len-i)))return true;
               if(isScramble(s1.substr(0,i),s2.substr(len-i,i))
                      &&isScramble(s1.substr(i,len-i),s2.substr(0,len-i)))return true;
           }
           return false;
       }
   };
   ```

   

