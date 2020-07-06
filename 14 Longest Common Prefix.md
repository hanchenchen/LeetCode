# 14 Longest Common Prefix

执行用时 : 12 ms, 在Longest Common Prefix的C++提交中击败了95.10%的用户

内存消耗 : 8.6 MB, 在Longest Common Prefix的C++提交中击败了94.54% 的用户

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        if(strs.size()==1)return strs[0];
        int ans=0;
        while(1){
            for(int i=1;i<strs.size();i++){
                if(strs[i].size()<=ans||strs[i][ans]!=strs[0][ans]){
                    return strs[0].substr(0,ans);
                }
            }
            ans++;
        }
    }
};
```

1. 特殊情况strs.size()==1||0

# 17 Letter Combinations of a Phone Number

执行用时 : 8 ms, 在Letter Combinations of a Phone Number的C++提交中击败了95.00% 的用户

内存消耗 : 8.7 MB, 在Letter Combinations of a Phone Number的C++提交中击败了36.79% 的用户

```c++
class Solution {
public:
    vector<string> ans;
    string d;
    int len;
    void func(int n,string s){
        if(n<len){
            char cc=3*(d[n]-'2')+'a';
            if(cc=='s'||cc=='v')cc++;
            func(n+1,s+cc);cc++;
            //cout<<s+cc<<endl;
            func(n+1,s+cc);cc++;
            //cout<<s+cc<<endl;
            func(n+1,s+cc);
            //cout<<s+cc<<endl;
            if(cc=='y'||cc=='r'){
                cc++;func(n+1,s+cc);
            }
            
        }if(n==len){
            ans.push_back(s);
        }
    }
    vector<string> letterCombinations(string digit) {
        len=digit.size();
        d = digit;
        if(len!=0)func(0,"");
        //sort(ans.begin(),ans.end());
        return ans;
    }
};
```

1. 输入为🈳️，输出vector为空

   输入：**""**

   输出：**[""]**

   预期：**[]**

2. 下标和迭代器之间转化

   ```c++
   ans[i]
   ans.begin()+i
   ```

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

# 20 Valid Parentheses

执行用时 : 8 ms, 在Valid Parentheses的C++提交中击败了96.74% 的用户

内存消耗 : 8.5 MB, 在Valid Parentheses的C++提交中击败了77.25% 的用户

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.empty())return false;
                char cc = st.top();
                st.pop();
                if(cc=='('){
                    if(s[i]!=')')return false;
                }else if(cc=='['){
                    if(s[i]!=']')return false;
                }else{
                     if(s[i]!='}')return false;
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};
```

1. 考虑第一个输入为右括号导致stack为空的情况

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

# 22 Generate Parentheses

执行用时 : 24 ms, 在Generate Parentheses的C++提交中击败了47.15%的用户

内存消耗 : 17.6 MB, 在Generate Parentheses的C++提交中击败了30.05% 的用户

```c++
class Solution {
public:
    int ob;
    vector<string> ans;
    void func(string s,int left,int right){
        if(right>=ob){
            ans.push_back(s);
            //cout<<s<<endl;
            return;
        }
        if(left>right){
            func(s+")",left,right+1);
        }
        if(left<ob){
            func(s+"(",left+1,right);
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        if(n==0)return ans;
        string s="";ob=n;
        func(s,0,0);
        return ans;
        
    }
};
```

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

