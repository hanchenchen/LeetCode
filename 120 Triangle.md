# 120 Triangle

#### Python3

执行用时：48 ms, 在所有 Python3 提交中击败了71.45%的用户

内存消耗：14.1 MB, 在所有 Python3 提交中击败了9.09%的用户

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        arr = [triangle[0][0]]
        for i in range(1,len(triangle)):
            # print(arr)
            arr.append(arr[i-1]+triangle[i][i])
            for j in range(i-1,0,-1):
                arr[j]=min(arr[j],arr[j-1])+triangle[i][j]
            arr[0]+=triangle[i][0]
        # print(arr)
        return min(arr)
```

##### C++

1. dp [ ] [ ]

   执行用时 :8 ms, 在所有 C++ 提交中击败了82.13%的用户

   内存消耗 :9.8 MB, 在所有 C++ 提交中击败了63.42%的用户

   ```c++
   class Solution {
   public:
       int minimumTotal(vector<vector<int>>& triangle) {
           int n=triangle.size();
           int arr[n][n]={0};
           memset(arr,0,sizeof(arr));
           for(int i=0;i<n;i++){
               arr[n-1][i]=triangle[n-1][i];
           }
           for(int i=n-1;i>0;i--){
               for(int j=0;j<i;j++){
                   arr[i-1][j]=min(arr[i][j],arr[i][j+1])+triangle[i-1][j];
                   //cout<<arr[i-1][j]<<" ";
               }
               //cout<<endl;
           }
           return arr[0][0];
       }
   };
   ```

2. dp [ ] 

   执行用时 :4 ms, 在所有 C++ 提交中击败了97.69%的用户

   内存消耗 :9.7 MB, 在所有 C++ 提交中击败了90.00%的用户

   ```c++
   class Solution {
   public:
       int minimumTotal(vector<vector<int>>& triangle) {
           int n=triangle.size();
           int arr[n]={0};
           memset(arr,0,sizeof(arr));
           for(int i=0;i<n;i++){
               arr[i]=triangle[n-1][i];
           }
           for(int i=n-1;i>0;i--){
               for(int j=0;j<i;j++){
                   arr[j]=min(arr[j],arr[j+1])+triangle[i-1][j];
                   //cout<<arr[i-1][j]<<" ";
               }
               //cout<<endl;
           }
           return arr[0];
       }
   };
   ```

   