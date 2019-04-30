# 19 Remove Nth Node From End of List

执行用时 : 12 ms, 在Remove Nth Node From End of List的C++提交中击败了96.26% 的用户

内存消耗 : 8.7 MB, 在Remove Nth Node From End of List的C++提交中击败了74.09% 的用户

```
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int i=0;
        ListNode *p=head;
        while(i<n){
            i++; 
            p=p->next; 
        }
        ListNode *q=head;
        if(p==NULL){
            head=head->next;
            return head;
        }
        while(p->next!=NULL){
            p=p->next;
            q=q->next;
        }
        q->next=q->next->next;
        return head;
    }
};
```

1. ⚠️注意各种空指针