# 71 Simplify Path

1. 解答错误：

   Input: "/../"
   Output: "/"
   Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

2. 解答错误：
  
  Input: "/..."
  Output: 
  
  - "/"✖️
  - "/…"☑️
  
3. 解答错误：

   Input:"/a//b////c/d//././/.."

   Output:

   - "/a/b/c/."✖️

   - "/a/b/c"☑️

4. 解答错误：

   Input:"/home/of/foo/../../bar/../../is/./here/."

   Output:

   - "/is"✖️

   - "/is/here"☑️

5. 执行错误：stack为🈳️！！

   ```c++
   if(s==".."){
     if(!st.empty())st.pop();
   }
   ```

6. 执行用时 :20 ms, 在所有 C++ 提交中击败了51.65%的用户

   内存消耗 :11.6 MB, 在所有 C++ 提交中击败了35.40%的用户

   ```c++
   class Solution {
   public:
       string simplifyPath(string path) {
           stack<string> st;
           int index=0;
           for(int i=0;i<path.size();i++){
               while(i<path.size()&&path[i]=='/')i++;
               if(i>=path.size())break;
               string s;
               while(i<path.size()&&path[i]!='/'){
                   s=s+path[i];i++;
               }
               //cout<<s<<endl;
               if(s==".."){
                   if(!st.empty())st.pop();
               }else if(s=="."){
   
               }else{
                   st.push(s);
               } 
               
           }
           string ans;
           while(!st.empty()){
               ans='/'+st.top()+ans;
               st.pop();
           }
           return ans==""?"/":ans;
       }
   };
   ```

   

- 特殊的测试用例！！