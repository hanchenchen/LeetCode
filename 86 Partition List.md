# 86 Partition List

执行用时 :12 ms, 在所有 C++ 提交中击败了81.75%的用户

内存消耗 :8.7 MB, 在所有 C++ 提交中击败了28.01%的用户

1. 记得给末尾指针的next赋值NULL

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
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode* before=new ListNode(0);
        ListNode* after=new ListNode(0);
        ListNode* be=before;
        ListNode* af=after;
        ListNode* p=head;
        while(p!=NULL){
             ///*
             if(p->val<x){
                be->next=p;
                be=p;
            }else{
                af->next=p;
                af=p;
            }// */ 
            p=p->next;
        }
        af->next=NULL;//!!!
        be->next=after->next;
        return before->next;
    }
};
```

