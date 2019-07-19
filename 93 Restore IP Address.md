# 93 Restore IP Address

1. "0000"

2. "010010"

   ```c++
           if(right[0]=='0'){
               func(n+1,left+"0",right.substr(1,len-1));
               return;
           }
   ```

   

3. 执行用时 :8 ms, 在所有 C++ 提交中击败了75.74%的用户

   内存消耗 :8.6 MB, 在所有 C++ 提交中击败了54.71%的用户

   ```c++
   class Solution {
   public:
       vector<string> v;
       void func(int n,string left,string right){
           if(n==5&&right==""){
               v.push_back(left);
               return;
           }
           if(n>1)left+=".";
           int len=right.size();
           if(right[0]=='0'){
               func(n+1,left+"0",right.substr(1,len-1));
               return;
           }
           for(int i=max(len-3*(4-n),1);i<=len-(4-n)&&i<=3;i++){
               int x=0;
               for(int j=0;j<i;j++){
                   x*=10;
                   x=x+(right[j]-'0');
               }
               if(x>255)break;
               func(n+1,left+right.substr(0,i),right.substr(i,len-i));
           }
       }
       vector<string> restoreIpAddresses(string s) {
           if(s.size()>12||s.size()<4)return v;
           func(1,"",s);
           return v;
       }
   };
   ```

   