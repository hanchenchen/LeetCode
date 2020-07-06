# 1130 Minimum Cost Tree Leaf Values

执行用时 :4 ms, 在所有 C++ 提交中击败了94.23%的用户

内存消耗 :8.5 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int len=arr.size();
        int sum[len][len];
        int max_value[len][len];
        memset(sum,0,sizeof(sum));
        memset(max_value,0,sizeof(max_value));
        for(int i=0;i<len;i++){
            max_value[i][i]=arr[i];
        }
        for(int k=2;k<=len;k++){
            for(int i=0;i<=len-k;i++){
                sum[i][k+i-1]=INT_MAX;
                for(int j=i;j<k+i-1;j++){
                    int x=sum[i][j]+sum[j+1][k+i-1]+max_value[i][j]*max_value[j+1][k+i-1];
                    if(x<sum[i][k+i-1]){
                        sum[i][k+i-1]=x;
                        max_value[i][k+i-1]=max(max_value[i][j],max_value[j+1][k+i-1]);
                    }
                }
            }
        }
        return sum[0][len-1];
    }
};
```

