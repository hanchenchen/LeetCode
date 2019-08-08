# 61 Rotate List

执行用时 : 12 ms, 在Rotate List的C++提交中击败了96.41% 的用户

内存消耗 : 9 MB, 在Rotate List的C++提交中击败了75.57% 的用户

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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p,*q;
        if(head)p=head;
        else return head;
        int len=1;
        for(;p->next;p=p->next)len++;
        k=k%len;
        if(k==0)return head;
        q=head;
        for(int i=1;i<len-k;i++){
            q=q->next;
        }
        p->next=head;
        head=q->next;
        q->next=NULL;
        return head;
        
    }
};
```

