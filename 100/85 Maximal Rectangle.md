# 85 Maximal Rectangle

1. 报int越界unsigned int的错误不一定是int溢出，可能是数组没有初始化，在计算中产生了越界。

2. max(int,int) || max(unsigned long long,unsigned longl ong)

3. 执行错误 *2+解答错误 *1：

   ```c++
   int arr[ r ] [ c ]={0};//不能确保元素全为零
   ```

4. 解答错误 *3：

    ```c++
    if(arr[k][j]<l)//if(arr[k][j]<arr[i][j]);
    ```

执行用时 :24 ms, 在所有 C++ 提交中击败了94.66%的用户

内存消耗 :10.5 MB, 在所有 C++ 提交中击败了96.58%的用户

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        if(r==0)return 0;
        int c=matrix[0].size();
        int arr[r][c]={0};
        int count=0;
        unsigned long long ans=0;
        for(int i=0;i<r;i++){
            count=0;
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1')count++;
                else count=0;
                arr[i][j]=count;
                if(!count)continue;
                unsigned long long l=arr[i][j];
                ans=max(ans,l);
                for(int k=i-1;k>=0&&arr[k][j];k--){
                    if(arr[k][j]<l)l=arr[k][j];
                    ans=max(ans,l*(i-k+1));
                }
            }
        }
        return ans;
        
    }
};
```



