# 38 Count and Say

执行用时 : 8 ms, 在Count and Say的C++提交中击败了95.95% 的用户

内存消耗 : 9 MB, 在Count and Say的C++提交中击败了39.06% 的用户

```c++
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string pre=countAndSay(n-1);
        string ans;
        char cc;
        for(int i=0;i<pre.size();i++){
            cc=pre[i];
            int num=0;
            while(i<pre.size()
                  &&cc==pre[i]){
                i++;num++;
            }
            string s=to_string(num);
            ans+=s;
            ans+=cc;
            i--;
        }
        return ans;
    }
};
```

1. string s = to_string (int val)
2. string s = to_string (long val)
3. string s = to_string (float val)![20180915110957142](assets/20180915110957142.png)