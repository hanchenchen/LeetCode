# 94 Binary Tree Inorder Traversal

1. Iteration

   执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

   内存消耗 :9.2 MB, 在所有 C++ 提交中击败了45.14%的用户

   ```c++
   class Solution {
   public:
       vector<int> ans;
       vector<int> inorderTraversal(TreeNode* root) {
           stack<TreeNode*> st;
           TreeNode* q=root;
           while(!st.empty()||q){
               while(q){
                   st.push(q);
                   q=q->left;
               }
               q=st.top()->right;
               ans.push_back(st.top()->val);
               st.pop();
           }
           return ans;
       }
   };
   ```

2. Recursive solution

   执行用时 :12 ms, 在所有 C++ 提交中击败了19.93%的用户

   内存消耗 :9.3 MB, 在所有 C++ 提交中击败了33.24%的用户

   ```c++
   public:
       vector<int> ans;
       void inorder(TreeNode* root){
           if(!root)return;
           inorder(root->left);
           ans.push_back(root->val);
           inorder(root->right);
       }
       vector<int> inorderTraversal(TreeNode* root) {
           inorder(root);
           return ans;
       }
   };
   ```

   

3. 1