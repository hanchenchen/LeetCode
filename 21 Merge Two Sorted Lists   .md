# 21 Merge Two Sorted Lists

执行用时 : 24 ms, 在Merge Two Sorted Lists的C++提交中击败了44.34%的用户

内存消耗 : 8.9 MB, 在Merge Two Sorted Lists的C++提交中击败了84.45% 的用户

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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *p =l1->val>l2->val?l1:l2;
        ListNode *head=l1->val<=l2->val?l1:l2;
        ListNode *q=head;
        ListNode *pre=q;
        //cout<<q->next->val<<endl;
        //cout<<head->next->val<<endl;
        while(p!=NULL&&q!=NULL){
            if(q->val<=p->val){
                pre=q;
                q=q->next;
                //cout<<q->next->val<<endl;
                //cout<<head->next->val<<endl;
                //return q;
            }else{
                ListNode *cc=p;
                p=p->next;
                cc->next=q;
                pre->next=cc;
                pre=cc;
                //q=pre->next;
                cout<<q->val<<"2"<<endl;
                //cout<<q->next->val<<endl;
            }
        }
        if(p!=NULL){
            pre->next=p;
        }

        return head;
    }
};
```

1. 各种为空，死循环

执行用时 : 28 ms, 在Merge Two Sorted Lists的C++提交中击败了37.25%的用户

内存消耗 : 9.2 MB, 在Merge Two Sorted Lists的C++提交中击败了72.71% 的用户

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *p =new ListNode(0);
        ListNode *q=p;
        while(l1&&l2){
            if(l1->val<=l2->val){
                q->next=new ListNode(l1->val);
                q=q->next;
                l1=l1->next;
            }else{
                q->next=new ListNode(l2->val);
                q=q->next;
                l2=l2->next;
            }
        }
        if(l1){
            q->next=l1;
        }
        if(l2){
            q->next=l2;
        }
        return p->next;
    }
};
```

