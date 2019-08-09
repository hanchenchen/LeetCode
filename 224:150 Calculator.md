# Calculator

## 150.Evalute Reverse Polish Notation

执行用时 :12 ms, 在所有 C++ 提交中击败了99.35%的用户

内存消耗 :11.6 MB, 在所有 C++ 提交中击败了21.04%的用户

```c++
class Solution {
public:
    int num(string s){
        int re=0,c=1;
        int i=0;
        if(s[0]=='-'){
            c=-1;
            i++;
        }
        else if(s[0]=='+'){
            c=1;
            i--;
        }
        for(;i<s.size();i++){
            re=10*re-'0'+s[i];
        }
        return re*c;
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())return 0;
        stack<int> st;
        int a,b;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i].size()>1||(tokens[i][0]>='0'&&tokens[i][0]<='9')){
                st.push(num(tokens[i]));
            }else if(tokens[i]=="+"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(a+b);
            }else if(tokens[i]=="-"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b-a);
            }else if(tokens[i]=="/"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b/a);
            }else if(tokens[i]=="*"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(a*b);
            }
        }
        return st.top();
    }
};
```

## 224.Basic Calculator

1. Recursion

   执行用时 :24 ms, 在所有 C++ 提交中击败了60.90%的用户

   内存消耗 :10.9 MB, 在所有 C++ 提交中击败了54.13%的用户

   ```c++
   class Solution {
   public:
       int index=0;
       string s;
       int num(){
           int re=0;
           while(s[index]<='9'&&s[index]>='0'){
               re=10*re-'0'+s[index];
               index++;
           }
           return re;
       }
       int quo(){
           int c=1;
           int re=0;
           while(s[index]!=')'){
               if(s[index]=='+'){
                   c=1;
                   index++;
               }else if(s[index]=='-'){
                   c=-1;
                   index++;
               }else if(s[index]=='('){
                   index++;
                   re+=(c*quo());
               }else if(s[index]<='9'&&s[index]>='0'){
                   re+=(c*num());
               }else{
                   index++;
               }
           }
           index++;
           return re;
       }
       int calculate(string i) {
           s=i+')';
           return quo();
       }
   };
   ```

2. Reverse Polish Notation

   执行用时 :68 ms, 在所有 C++ 提交中击败了17.18%的用户

   内存消耗 :43.3 MB, 在所有 C++ 提交中击败了12.03%的用户

   ```c++
   class Solution {
   public:
       int num(string s){
           int re=0,c=1;
           int i=0;
           if(s[0]=='-'){
               c=-1;
               i++;
           }
           else if(s[0]=='+'){
               c=1;
               i--;
           }
           for(;i<s.size();i++){
               re=10*re-'0'+s[i];
           }
           return re*c;
       }
       int evalRPN(vector<string> tokens) {
           if(tokens.empty())return 0;
           stack<int> st;
           int a,b;
           for(int i=0;i<tokens.size();i++){
               //cout<<tokens[i]<<endl;
               if(tokens[i].size()>1||(tokens[i][0]>='0'&&tokens[i][0]<='9')){
                   st.push(num(tokens[i]));
               }else if(tokens[i]=="+"){
                   a=st.top();
                   st.pop();
                   b=st.top();
                   st.pop();
                   st.push(a+b);
               }else if(tokens[i]=="-"){
                   a=st.top();
                   st.pop();
                   b=st.top();
                   st.pop();
                   st.push(b-a);
               }else if(tokens[i]=="/"){
                   a=st.top();
                   st.pop();
                   b=st.top();
                   st.pop();
                   st.push(b/a);
               }else if(tokens[i]=="*"){
                   a=st.top();
                   st.pop();
                   b=st.top();
                   st.pop();
                   st.push(a*b);
               }
           }
           return st.top();
       }
       int calculate(string s) {
           vector<string> tokens;
           string num;
           stack<string> sign;
           stack<int> priority;
           int prio=0;
           for(int i=0;i<s.size();i++){
               
               if(s[i]>='0'&&s[i]<='9'){
                   num="";
                   while(s[i]>='0'&&s[i]<='9'){
                       num+=s[i];
                       i++;
                   }
                   tokens.push_back(num);
               }
               if(s[i]=='('){
                   prio++;
               }else if(s[i]==')'){
                   prio--;
               }else if(s[i]=='+'){
                   while(!sign.empty()&&priority.top()>=prio){
                           tokens.push_back(sign.top());
                           sign.pop();
                           priority.pop();
                       }
                   sign.push("+");
                   priority.push(prio);
               }else if(s[i]=='-'){
                   while(!sign.empty()&&priority.top()>=prio){
                           tokens.push_back(sign.top());
                           sign.pop();
                           priority.pop();
                       }
                   sign.push("-");
                   priority.push(prio);
               }
           }
           while(!sign.empty()){
               tokens.push_back(sign.top());
               sign.pop();
           }
           return evalRPN(tokens);
       }
   };
   ```

