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
