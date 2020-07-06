# 5175 Can Make Palindrome from Substring

@[JOHNKRAM](https://leetcode-cn.com/u/johnkram)

```c++
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        int arr[100005][26];
        fill(arr[0],arr[0]+26,0);
        for(int i=0;i<s.size();i++){
            copy(arr[i],arr[i]+26,arr[i+1]);
            arr[i+1][s[i]-'a']^=1;
          //统计s第i位之前（不包括第i位）每个字符出现的次数为奇数次还是偶数次
          //奇数次 1 偶数次 0
        }
        for(int i=0;i<queries.size();i++){
            int modify=0;
            for(int j=0;j<26;j++){
                modify+=(arr[queries[i][0]][j]^arr[queries[i][1]+1][j]);
              //计算s中 queries[i][0] 位 到queries[i][1] 位 出现次数 为 奇数次 的 字符 的个数
            }
            //cout<<modify<<endl;
            modify>>=1;//一次修改可以把两个奇数次 变成两个偶数次
            if(modify<=queries[i][2])ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
```

