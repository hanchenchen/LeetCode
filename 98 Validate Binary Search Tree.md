# 98 Validate Binary Search Tree

1. [-2147483648] 

   刚好给的x的初始值就是INT_MIN，解答错误

2. recursion

   执行用时 :28 ms, 在所有 C++ 提交中击败了52.65%的用户

   内存消耗 :20.6 MB, 在所有 C++ 提交中击败了61.06%的用户

   ```c++
   /**
    * Definition for a binary tree node.
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
   class Solution {
   public:
       bool ans=true;
       int x=0;
       bool ifx=1;
       void inorder(TreeNode* root){
           
           if(!ans)return;
           if(root->left)inorder(root->left);
           //cout<<root->val<<x<<endl;
           if(x<root->val||ifx){
               ifx=0;
               x=root->val;
           }else{
               ans=false;return;
           }
           if(root->right)inorder(root->right);
       }
       bool isValidBST(TreeNode* root) {
           if(!root)return true;
           x=0;
           inorder(root);
           return ans;
       }
   };
   ```

3. stack

   执行用时 :8 ms, 在所有 C++ 提交中击败了99.64%的用户

   内存消耗 :20.6 MB, 在所有 C++ 提交中击败了52.90%的用户

   ```c++
   /**
    * Definition for a binary tree node.
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
   class Solution {
   public:
       bool isValidBST(TreeNode* root) {
           stack<TreeNode*> st;
           TreeNode* pre=NULL;
           while(root||!st.empty()){
               while(root){
                   st.push(root);
                   root=root->left;
               }
               if(!pre||pre->val<st.top()->val){
                   pre=st.top();
               }else
                   return false;
               root=st.top()->right;
               st.pop();
           }
           return true;
       }
   };
   ```