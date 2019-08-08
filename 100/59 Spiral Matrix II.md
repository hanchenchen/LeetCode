# 59 Spiral Matrix II

执行用时 : 4 ms\8ms\12ms， 在Spiral Matrix II的C++提交中击败了98.35% 的用户

内存消耗 : 9.3 MB, 在Spiral Matrix II的C++提交中击败了5.17% 的用户

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        vector<int> mid1;
        for(int i=1;i<=n;i++){
            mid1.push_back(i);
        }
        ans.push_back(mid1);
        int i=1;
        for(;i<n/2+1;i++){
            vector<int> mid;
            int j=0;                
            for(;j<i-1;j++){
                mid.push_back(ans[i-1][j]-1);
            }
            int x=4*(n-2*j)-4;
            mid.push_back(ans[j][j]+x+j-i);
            j++;
            x=mid[j-1]+1;
            for(;j<n-i;j++){
                mid.push_back(x++);
            }
            for(;j<n;j++){
                mid.push_back(ans[i-1][j]+1);
            }
            ans.push_back(mid);
        }
        for(;i<n;i++){
            vector<int> mid;
            int j=0;                
            for(;j<n-i;j++){
                mid.push_back(ans[i-1][j]-1);
            }
            int x=mid[n-i-1]-1;
            for(;j<i;j++){
                mid.push_back(x--);
            }
            for(;j<n;j++){
                mid.push_back(ans[i-1][j]+1);
            }
            ans.push_back(mid);
        }
        return ans;
    }
};


```

1. 执行出错：逻辑错误