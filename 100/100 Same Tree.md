# 100 Same Tree

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :9.7 MB, 在所有 C++ 提交中击败了90.19%的用户

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true;
        else if(!p||!q)return false;
        if(p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right))return true;
        return false;
    }
};
```

