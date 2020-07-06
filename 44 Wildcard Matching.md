# 44 Wildcard Matching

1. 注意switch：int的范围，在case中定义的量可以作用在整个switch中，重复定义回报错

   jump to case label [-fpermissive]    

2. "" ""

3. "" "a"

4. method 1

   执行用时 :8 ms, 在所有 C++ 提交中击败了97.04%的用户

   内存消耗 :8.7 MB, 在所有 C++ 提交中击败了94.90%的用户
   
   ```c++
   class Solution {
   public:
       bool isMatch(string s, string p) {
           int lens=s.size();
           int lenp=p.size();
           if(p=="")return s==p;
           if(s==""){
               for(int i=0;i<lenp;i++){
                   if(p[i]!='*')return false;
               }
               return true;
           }
           int i=0,j=0;
           int ss=-1,pp=-1;
           while(i<lens){
               //cout<<i<<j<<endl;
               if(p[j]=='*'){
                   ss=i;pp=j;
                   j++;
               }else if(p[j]==s[i]||p[j]=='?'){
                   i++;j++;
               }else if(ss>-1){
                   ss++;
                   i=ss;j=pp+1;
               }else return false;
           }
           while(j<lenp&&p[j]=='*')j++;
           if(j==lenp)return true;
           return false;
       }
   };
   ```
   
5. method 2

   执行用时 :28 ms, 在所有 C++ 提交中击败了75.89%的用户

   内存消耗 :8.7 MB, 在所有 C++ 提交中击败了95.39%的用户

   ```c++
   class Solution {
   public:
       bool isMatch(string s, string p) {
           int lens=s.size();
           int lenp=p.size();
           if(p=="")return s==p;
           bool arr[lens+1]={false};
           switch(p[0]){
               case '*':
                   for(int j=0;j<=lens;j++){
                       arr[j]=true;
                   }
                   break;
               case '?':
                   if(!lens)return false;
                   arr[1]=true;
                   break;
               default :
                   if(!lens)return false;
                   arr[1]=s[0]==p[0];
           }
           int j=0;
           for(int i=1;i<lenp;i++){
               switch(p[i]){
                   case '*':
                       for(j=0;j<=lens;j++){
                           if(arr[j]==true)break;
                       }
                       for(;j<=lens;j++){
                           arr[j]=true;
                       }
                       break;
                   case '?':
                       for(int j=lens;j>0;j--){
                           arr[j]=arr[j-1];
                       }
                       arr[0]=false;
                       break;
                   default:
                       for(int j=lens;j>0;j--){
                           arr[j]=arr[j-1]&&(p[i]==s[j-1]);
                       }
                       arr[0]=false;
                       break;
               }
           }
           return arr[lens];
       }
   };
   ```

   