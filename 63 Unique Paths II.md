# 63 Unique Paths II

#### 方法一：动态规划

##### C++

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        unsigned long long arr[m][n]={0};
        memset(arr,0, sizeof(arr));
        int i=0;
        for(;i<m;i++){
            if(obstacleGrid[i][0]==1)break;
            arr[i][0]=1;
        }
        for(i=0;i<n;i++){
            if(obstacleGrid[0][i]==1)break;
            arr[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0)
                    arr[i][j]=arr[i-1][j]+arr[i][j-1];
                else
                    arr[i][j]=0;
            }
        }
        return arr[m-1][n-1];
    }
};
```

##### Python

执行用时：36 ms, 在所有 Python3 提交中击败了93.44%的用户

内存消耗：13.7 MB, 在所有 Python3 提交中击败了14.29%的用户

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not len(obstacleGrid) or not len(obstacleGrid[0]) or obstacleGrid[0][0] or obstacleGrid[len(obstacleGrid)-1][len(obstacleGrid[0])-1]:
            return 0
        arr = [[0 for j in range(len(obstacleGrid[0])+1)] for i in range(len(obstacleGrid)+1)]
        arr[0][1]=1
        #print (arr)
        for i in range(len(obstacleGrid)):
            for j in range(len(obstacleGrid[0])):
                if obstacleGrid[i][j]:
                    arr[i+1][j+1]=0
                else:
                    arr[i+1][j+1]=arr[i][j+1]+arr[i+1][j]
        return arr[len(obstacleGrid)][len(obstacleGrid[0])]
```

