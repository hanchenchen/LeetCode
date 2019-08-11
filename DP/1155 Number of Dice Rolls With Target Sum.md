# 1155 Number of Dice Rolls With Target Sum

执行用时 :56 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :8.4 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
class Solution {
public:
    const int ma=1000000007;
    int arr[33][1005]={0};
    int numRollsToTarget(int d, int f, int target) {
        memset(arr,0,sizeof(arr));
        arr[0][0]=1;
        for(int i=0;i<=d;i++){
            for(int j=0;j<=target;j++){
                for(int k=1;k<=f&&j+k<=target;k++){
                    arr[i+1][j+k]=(arr[i+1][j+k]+arr[i][j])%ma;
                }
            }
        }
        return arr[d][target];
    }
};
```