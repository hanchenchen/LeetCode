# 23 Merge k Sorted List

1. []

2. 分治

   执行用时 :36 ms, 在所有 C++ 提交中击败了93.41%的用户

   内存消耗 :11.1 MB, 在所有 C++ 提交中击败了85.59%的用户

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
       ListNode* mergeKLists(vector<ListNode*>& lists) {
           int len=lists.size();
           if(!len)return NULL;
           while(len>1){
               int index=len/2+len%2;
               for(int i=0;i+index<len;i++){
                   //lists[i]=merge(lists[i],lists[i+index]);
                   ListNode* head=new ListNode(0);
                   ListNode* p=head;
                   ListNode* a=lists[i];
                   ListNode* b=lists[i+index];
                   while(a&&b){
                       if(a->val>b->val){
                           p->next=b;
                           p=p->next;
                           b=b->next;
                       }else{
                           p->next=a;
                           p=p->next;
                           a=a->next;
                       }
                   }
                   if(a)p->next=a;
                   if(b)p->next=b;
                   lists[i]=head->next;
               }
               len=index;
           }
           return lists[0];
       }
   };
   ```

3. 执行用时 :676 ms, 在所有 C++ 提交中击败了6.98%的用户

   内存消耗 :10.6 MB, 在所有 C++ 提交中击败了98.76%的用户

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
       ListNode* mergeKLists(vector<ListNode*>& lists) {
           ListNode* head=new ListNode(0);
           ListNode* ans=head;
           int p=0;
           for(;p<lists.size()&&lists[p]==NULL;p++);
           while(p<lists.size()){
               for(int i=1;i<lists.size();i++){
                   if(lists[i]!=NULL&&lists[p]->val>lists[i]->val)p=i;
               }
               //cout<<p<<endl;
               head->next=lists[p];
               head=head->next;
               lists[p]=lists[p]->next;
               for(p=0;p<lists.size()&&lists[p]==NULL;p++);
           }
           return ans->next;
       }
   };
   ```