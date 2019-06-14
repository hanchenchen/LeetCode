# 64 Minimum Path Sum

执行用时 :8 ms, 在所有C++提交中击败了98.81%的用户

内存消耗 :10.6 MB, 在所有C++提交中击败了89.54%的用户

*和62、63一样的解法*

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(!m)return 0;
        int n=grid[0].size();
        if(!n)return 0;
        for(int i=1;i<m;i++){
            grid[i][0]+=grid[i-1][0];
        }
        for(int j=1;j<n;j++){
            grid[0][j]+=grid[0][j-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i-1][j]>grid[i][j-1])grid[i][j]+=grid[i][j-1];
                else grid[i][j]+=grid[i-1][j];
            }
        }
        return grid[m-1][n-1];
    }
};
```

