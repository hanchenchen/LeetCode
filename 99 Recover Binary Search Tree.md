# 99 Recover Binary Search Tree

1. J

   ```c++
   class Solution {
      public:
          vector<TreeNode*> v;
          TreeNode* p1;
          int Count = 0;
          void recover(TreeNode* root){
              if(root->left){
                  recover(root->left);
              }
              if(p1){
                  if(root->val < p1->val){
                      v.push_back(p1);
                      v.push_back(root);
                      Count++;
                      if(Count>=2){
                          return;
                      }
                  }
              }
              p1 = root;
              if(root->right){
                  recover(root->right);
              }
          }
          void recoverTree(TreeNode* root) {
              recover(root);
              int temp = v[0]->val;
              v[0]->val = v.back()->val;
              v.back()->val = temp;
          }
      };
   ```


2. space O(1)

   执行用时 :40 ms, 在所有 C++ 提交中击败了79.48%的用户

   内存消耗 :17.7 MB, 在所有 C++ 提交中击败了88.98%的用户

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
       TreeNode* pre;
       TreeNode* first=NULL;
       TreeNode* last=NULL;
       void dfs2(TreeNode* root){
           if(!root)return;
           dfs2(root->left);
           if(root->val<pre->val){
               if(!first)first=pre;
               last=root;
           }
           pre=root;
           dfs2(root->right);
       }
       void recoverTree(TreeNode* root) {
           pre=root;
           while(pre->left)
               pre=pre->left;
           dfs2(root);
           if(first){
               int temp=first->val;
               first->val=last->val;
               last->val=temp;
           }
           return;
       }
   };
   ```

   

3. space O(n)

   执行用时 :52 ms, 在所有 C++ 提交中击败了57.84%的用户

   内存消耗 :18.4 MB, 在所有 C++ 提交中击败了77.12%的用户

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
       //TreeNode* 
       vector<int> v;
       int dfs(TreeNode* root,int pre){
           if(!root)return 0;
           int l=dfs(root->left,pre);
           //cout<<l+pre<<endl;
           root->val=v[l+pre];
           int r=dfs(root->right,l+pre+1);
           return l+r+1;
       }
       void dfs2(TreeNode* root){
           if(!root)return;
           dfs2(root->left);
           dfs2(root->right);
           v.push_back(root->val);
       }
       void recoverTree(TreeNode* root) {
           dfs2(root);
           sort(v.begin(),v.end());
           dfs(root,0);
       }
   };
   ```

   

4. ,

5. 



