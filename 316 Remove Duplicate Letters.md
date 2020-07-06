# 316 Remove Duplicate Letters

1. 维护两个数组，分别统计`i`之后字符分别有多少，放入`ans`的字符分别有多少
2. 如果`s[i]`<`stack.top()`，弹出⏏️，直到遇到一个不能弹出的（`i`之后没有剩余）

```c++
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int arr[26]={0},arrans[26]={0},n=s.size();
        stack<char> remain;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        string ans;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']--;
            if(arrans[s[i]-'a']==1)continue;
            while(!remain.empty()&&arr[remain.top()-'a']>=1&&s[i]<=remain.top()){
                arrans[remain.top()-'a']--;
                remain.pop();
            }
            arrans[s[i]-'a']++;
            remain.push(s[i]);
        }
        while(!remain.empty()){
            ans=remain.top()+ans;
            remain.pop();
        }
        return ans;
    }
};
```

