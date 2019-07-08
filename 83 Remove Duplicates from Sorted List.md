# 83 Remove Duplicates from Sorted List

1. []

2. 执行用时 :16 ms, 在所有 C++ 提交中击败了94.44%的用户

   内存消耗 :9.3 MB, 在所有 C++ 提交中击败了11.10%的用户

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
       ListNode* deleteDuplicates(ListNode* head) {
           if(!head)return head;
           ListNode* p=head->next;
           int c=head->val;
           ListNode* pre=head;
           while(p){
               if(c==p->val){
                   pre->next=p->next;
               }else{
                   c=p->val;
                   pre=p;
               }
               p=p->next;
           }
           return head;
       }
   };
   ```

   

