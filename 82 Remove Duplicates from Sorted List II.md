# 82 Remove Duplicates from Sorted List II

1. 执行用时 :16 ms, 在所有 C++ 提交中击败了80.36%的用户

   内存消耗 :9.2 MB, 在所有 C++ 提交中击败了9.57%的用户

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
           int c=head->val;int n=1;
           ListNode *ans=new ListNode(0);
           ListNode *q=ans;
           while(p){
               if(p->val!=c){
                   if(n<=1){
                       ans->next=new ListNode(c);
                       ans=ans->next;
                   }
                   c=p->val;
                   n=1;
               }else{
                   n++;
               }
               p=p->next;
           }
           if(n<=1){
               ans->next=new ListNode(c);
           }
           return q->next;
       }
   };
   ```

   