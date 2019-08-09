# 101 Symmetric Tree

1. recursion

   执行用时 :12 ms, 在所有 C++ 提交中击败了56.14%的用户

   内存消耗 :14.7 MB, 在所有 C++ 提交中击败了86.57%的用

   ```c++
   class Solution {
   public:
       bool func(TreeNode* left,TreeNode* right){
           if(!left||!right)return left==right;
           return left->val==right->val&&func(left->left,right->right)
              &&func(left->right,right->left);
       }
       bool isSymmetric(TreeNode* root) {
           if(root)
               return func(root->left,root->right);
           else 
               return true;
       }
   };
   ```

2. iteration

3. 执行用时 :8 ms, 在所有 C++ 提交中击败了81.03%的用户

   内存消耗 :14.9 MB, 在所有 C++ 提交中击败了80.52%的用户
   
   ```c++
   class Solution {
   public:
       bool isSymmetric(TreeNode* root) {
           if(!root)return true;
           stack<TreeNode*> l;
           stack<TreeNode*> r;
           TreeNode* p=root->left;
           TreeNode* q=root->right;
           while(p&&q||!l.empty()&&!r.empty()){
               //cout<<p->val<<"  "<<q->val<<endl;
               while(p&&q){
                   //cout<<p->val<<"  "<<q->val<<endl;
                   if(p->val!=q->val)return false;
                   l.push(p);
                   r.push(q);
                   p=p->left;
                   q=q->right;
               }
               //cout<<p->val<<"  "<<q->val<<endl;
               if(p||q)return false;
               p=l.top()->right;
               q=r.top()->left;
               l.pop();
               r.pop();
           }
           if(p!=q||!l.empty()||!r.empty())return false;
           return true;
       }
   };
   ```