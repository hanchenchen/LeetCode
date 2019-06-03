# 48 Rotate Image

- 1

执行用时 : 8 ms, 在Rotate Image的C++提交中击败了94.44% 的用户

内存消耗 : 9 MB, 在Rotate Image的C++提交中击败了70.11% 的用户

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int len=m.size()-1;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<len-i;j++){
                int mid=m[i][j];
                m[i][j]=m[len-j][len-i];
                m[len-j][len-i]=mid;
            }
        }
        for(int i=0;i<m.size()/2;i++){
            vector<int> mid=m[i];
            m[i]=m[len-i];
            m[len-i]=mid;
        }
    }
};
```

- 2

执行用时 : 8 ms, 在Rotate Image的C++提交中击败了94.44% 的用户

内存消耗 : 9.2 MB, 在Rotate Image的C++提交中击败了13.65% 的用户

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int len=m.size()-1;
        for(int i=0;i<=len/2;i++){
            for(int j=i;j<len&&j<len-i;j++){
                int mid=m[i][j];
                m[i][j]=m[len-j][i];
                m[len-j][i]=m[len-i][len-j];
                m[len-i][len-j]=m[j][len-i];
                m[j][len-i]=mid;
            }
        }
    }
};
```

