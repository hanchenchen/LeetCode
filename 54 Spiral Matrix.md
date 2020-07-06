# 54 Spiral Matrix

执行用时 : 4 ms, 在Spiral Matrix的C++提交中击败了95.60% 的用户

内存消耗 : 8.6 MB, 在Spiral Matrix的C++提交中击败了48.25% 的用户

执行用时 : 12 ms, 在Spiral Matrix的C++提交中击败了29.40% 的用户

内存消耗 : 8.6 MB, 在Spiral Matrix的C++提交中击败了50.54% 的用户

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();if(m==0)return ans;
        int n=matrix[0].size();
        int i=0;
        for(;i<m/2&&i<n/2;i++){
            int x=i,y=i;
            for(int j=0;j<n-2*i;j++){
                ans.push_back(matrix[x][y++]);
            }y--;x++;
            for(int j=1;j<m-2*i;j++){
                ans.push_back(matrix[x++][y]);
            }x--;y--;
            for(int j=1;j<n-2*i;j++){
                ans.push_back(matrix[x][y--]);
            }y++;x--;
            for(int j=2;j<m-2*i;j++){
                ans.push_back(matrix[x--][y]);
            }
        }
        if(ans.size()==m*n)return ans;
        if(m>n){
            for(int j=0;j<m-2*i;j++){
                ans.push_back(matrix[i+j][i]);
            }
        }else if(m<n){
            for(int j=0;j<n-2*i;j++){
                ans.push_back(matrix[i][i+j]);
            }
        }else{
            if(m%2==1)ans.push_back(matrix[i][i]);
        }
        return ans;
    }
};
```

