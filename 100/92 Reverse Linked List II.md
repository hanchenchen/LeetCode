# 92 Reverse Linked List II

执行用时 :4 ms, 在所有 C++ 提交中击败了94.31%的用户

内存消耗 :8.5 MB, 在所有 C++ 提交中击败了87.94%的用户

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)return head;
        if(m==1){
            int i=1;
            ListNode* q=head;
            for(;i<m;i++){
                q=q->next;
            }
            ListNode* m_node=q;
            q=q->next;i++;
            ListNode* k=m_node;
            for(;i<=n;i++){
                m_node->next=q->next;
                q->next=k;
               k=q;
               q=m_node->next;
           }
            return k;
        }
        int i=1;
        ListNode* q=head;
        for(;i<m-1;i++){
            q=q->next;
        }
        ListNode* m_pre=q;
        q=q->next;i++;
        ListNode* m_node=q;
        q=q->next;i++;
        ListNode* k=m_node;
        for(;i<=n;i++){
            m_node->next=q->next;
            m_pre->next=q;
            q->next=k;
            k=q;
            q=m_node->next;
        }
        
        return head;
        
    }
};
```

