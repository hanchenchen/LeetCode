# 76 Minimum Window Substring

1. 解答错误*10：

   "a" "aa"

   "ab" "b"

2. 编译错误+超时*2：先本地测试好再提交🤦‍♀️

3. 执行用时 :92 ms, 在所有 C++ 提交中击败了17.09%的用户

   内存消耗 :11.6 MB, 在所有 C++ 提交中击败了45.21%的用户

   ```c++
   class Solution {
   public:
       string minWindow(string s, string t) {
           int sarr['z'+1]={0};
           int tarr['z'+1]={0};
           vector<char> vc;
           for(int i=0;i<t.size();i++){
               tarr[t[i]]++;
               if(find(vc.begin(),vc.end(),t[i])==vc.end()){
                   vc.push_back(t[i]);
               }
           }
           int i=0,left=0;
           for(;i<s.size();i++){
               sarr[s[i]]++;
               int j=0;
               for(;j<vc.size();j++){
                   if(tarr[vc[j]]>sarr[vc[j]])break;
               }
               if(j==vc.size())break;
           }
           if(i==s.size())return "";
           int a=i;
           i++;
           while(tarr[s[left]]==0||tarr[s[left]]<sarr[s[left]]){
                   sarr[s[left]]--;
                   left++;
                   //while(tarr[s[left]]==0)left++;
           }
           int b=left;
           for(;i<s.size();i++){
               sarr[s[i]]++;
               while(tarr[s[left]]==0||tarr[s[left]]<sarr[s[left]]){
                   sarr[s[left]]--;
                   left++;
                   //while(tarr[s[left]]==0)left++;
               }
               if(i-left<a-b){
                   a=i,b=left;
               }
           }
           return s.substr(b,a-b+1);
       }
   };
   ```
   
   