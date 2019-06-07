# 58 Length of Last Word

执行用时 : 8 ms, 在Length of Last Word的C++提交中击败了89.21% 的用户

内存消耗 : 8.9 MB, 在Length of Last Word的C++提交中击败了61.81% 的用

```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;int j=s.size()-1;
        while(s[j]==' ')j--;
        for(;j>=0;j--){
            if(s[j]!=' ')ans++;
            else break;
        }
        return ans;
    }
};
```

1. 解答错误："a "

   ```c++
   while(s[j]==' ')j--;
   ```

   