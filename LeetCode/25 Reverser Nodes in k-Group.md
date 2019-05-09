# 25 Reverser Nodes in k-Group

执行用时 : 36 ms, 在Reverse Nodes in k-Group的C++提交中击败了59.24% 的用户

内存消耗 : 11.3 MB, 在Reverse Nodes in k-Group的C++提交中击败了5.33% 的用户

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!k)return head;
        ListNode* p=head;stack<ListNode*> st;
        for(int i = 0;i<k;i++){
            if(p==NULL)return  head;
            st.push(p);
            //cout<<p->val<<endl;
            p=p->next;
        }
        head->next=reverseKGroup(p,k);
        head=st.top();
        while(!st.empty()){
            p=st.top();st.pop();
            if(!st.empty())p->next=st.top();
        }
        return head;
    }
};
```

