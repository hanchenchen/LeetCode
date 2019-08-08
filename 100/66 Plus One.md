# 66 Plus One

1. vector 没有push_front

   c.insert(p,t)//在p迭代器位置插入t

   c.insert(p,n,t)//在p迭代器位置插入n个t

   c.insert(p,b,e)//在p迭代器位置插入b迭代器和e迭代器之间的元素

   

执行用时 :4 ms, 在所有C++提交中击败了96.22%的用户

内存消耗 :8.8 MB, 在所有C++提交中击败了5.45%的用户

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        digits[i]++;
        int c=digits[i]/10;
        digits[i]=digits[i]%10; 
        i--;
        for(;i>=0;i--){
            digits[i]+=c;
            c=digits[i]/10;
            digits[i]=digits[i]%10;
        }
        if(c!=0)digits.insert(digits.begin(),c);
        return digits;
    }
};
```

