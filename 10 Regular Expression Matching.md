# 10 Regular Expression Matching

1. iteration

   执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

   内存消耗 :8.4 MB, 在所有 C++ 提交中击败了92.77%的用户

   ```c++
   class Solution {
   public:
       bool isMatch(string s, string p) {
           int len_s=s.size();
           bool arr[len_s+1]={false};
           arr[0]=true;
           for(int i=0;i<p.size();i++){
               if(i+1<p.size()&&p[i+1]=='*'){
                   for(int j=len_s;j>0;j--){
                       if(arr[j-1]){
                           for(int k=j;k<=len_s&&(s[k-1]==p[i]||p[i]=='.');k++){
                               arr[k]=true;
                           }
                       }
                   }
                   i++;
               }else{
                   for(int j=len_s;j>0;j--){
                       arr[j]=arr[j-1]&&(s[j-1]==p[i]||p[i]=='.');
                   }
                   arr[0]=false;
               }
               /*for(int j=0;j<=len_s;j++){
                   cout<<arr[j];
               }cout<<endl;
           //*/
           }
           return arr[len_s];
       }
   };
   ```

2. recursion

   执行用时 :472 ms, 在所有 C++ 提交中击败了14.28%的用户

   内存消耗 :15.3 MB, 在所有 C++ 提交中击败了15.32%的用户

   ```c++
   class Solution {
   public:
       bool isMatch(string s, string p) {
           //cout<<s<<" "<<p<<endl;
           if(p=="")return s==p;
           if(p.size()>1&&p[1]=='*'){
               return isMatch(s,p.substr(2))||(s!=""&&(s[0]==p[0]||p[0]=='.')
                                               &&isMatch(s.substr(1),p));
           }else{
               return s!=""&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p.substr(1));
           }
       }
   };
   ```

   



