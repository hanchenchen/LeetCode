# 24 Swap Nodes in Pairs

执行用时 : 8 ms, 在Swap Nodes in Pairs的C++提交中击败了96.69% 的用户

内存消耗 : 8.6 MB, 在Swap Nodes in Pairs的C++提交中击败了86.92%的用户

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p=head;
        if(p==NULL)return p;
        ListNode* q=p->next;
        if(q==NULL)return p;
        head=q;
        ListNode* k=q->next;
        while(q){
            if(k==NULL){
                p->next=NULL;
                q->next=p;
                return head;
            }
            if(!k->next)
                p->next=k;
            else
                p->next=k->next;
            q->next=p;
            p=k;
            q=k->next;
            if(!q)break;
            k=q->next;
        }
        return head;
    }
};
```

1. 输入为[]

2. 奇数偶数时处理不一样

   ```c++
   if(k==NULL){
                   p->next=NULL;
                   q->next=p;
                   return head;
               }
               if(!k->next)
                   p->next=k;
   ```

   

