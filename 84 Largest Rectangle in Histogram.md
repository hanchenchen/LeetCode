# 84 Largest Rectangle in Histogram

1. space O(1)

   执行用时 :16 ms, 在所有 C++ 提交中击败了88.77%的用户

   内存消耗 :9.8 MB, 在所有 C++ 提交中击败了91.79%的用户

   ```c++
   class Solution {
   public:
       int largestRectangleArea(vector<int>& heights) {
           if(heights.size()==0)return 0;
           int ans=0;
           int i=1,j=0;
           for(;i<heights.size();i++){
               for(j=i-1;j>=0&&heights[j]>heights[i];j--){
                   ans=max(ans,(i-j)*heights[j]);
                   heights[j]=heights[i];
               }
           }
           for(j=i-1;j>=0;j--){
               ans=max(ans,(i-j)*heights[j]);
           }
           return ans;
       }
   };
   ```

2. stack O(n)

   执行用时 :20 ms, 在所有 C++ 提交中击败了75.43%的用户

   内存消耗 :10.5 MB, 在所有 C++ 提交中击败了49.43%的用户

   ```c++
   class Solution {
   public:
       int largestRectangleArea(vector<int>& heights) {
           if(heights.size()==0)return 0;
           stack<int> st;
           int ans=0;
           st.push(heights[0]);
           for(int i=1;i<heights.size();i++){
               int l=1;
               while(!st.empty()&&heights[i]<st.top()){
                   ans=max(ans,l*st.top());
                   st.pop();
                   l++;
               }
               while(l>0){
                   st.push(heights[i]);
                   l--;
               }
           }
           int l=1;
           while(!st.empty()){
               ans=max(ans,l*st.top());
               st.pop();
               l++;
           }
           return ans;
       }
   };
   ```

   