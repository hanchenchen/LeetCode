# 95 Unique Binary Search Tree II

1. 0!!

2. vector<TreeNode*>中存放的是地址，更改已经放进去的TreeNode * 的值，vector中相应TreeNode * 也会改变。

3.  （ vector<TreeNode*>） v.push_back(NULL);

4. return vector<TreeNode*> ();

5. 执行用时 :28 ms, 在所有 C++ 提交中击败了85.67%的用户

   内存消耗 :17.4 MB, 在所有 C++ 提交中击败了17.94%的用户

   ```c++
   class Solution {
   public:
       
       vector<TreeNode*> func(int start,int end) {
           vector<TreeNode*> re;
           if(start>end){
               re.push_back(NULL);//!!!
               return re;
           }
           for(int i=start;i<=end;i++){
               vector<TreeNode*> left=func(start,i-1);
               vector<TreeNode*> right=func(i+1,end);
               //TreeNode* root=new TreeNode(i);
               for(int k=0;k<left.size();k++){
                   for(int j=0;j<right.size();j++){
                       TreeNode* root=new TreeNode(i);
                       root->left=left[k];
                       root->right=right[j];
                       re.push_back(root);
                   }
               }
           }
           return re;
           
       }
       vector<TreeNode*> generateTrees(int n) {
           if(n==0){
               return vector<TreeNode*> ();
           }
           return func(1,n);
       }
   };
   ```

   

