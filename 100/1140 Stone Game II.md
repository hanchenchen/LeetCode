# 1140 Stone Game II

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :8.6 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
class Solution {
public:
    vector<int> p;
    int arr[105]={0};
    int num=0;
    int best[105][100]={{0}};
    int func(int x,int m){
        if(best[x][m])return best[x][m];
        if(x>=num)return 0;
        if(num-x<=2*m)return arr[x];
        int max_stone=0;
        for(int i=1;i<=2*m;i++){
            max_stone=max(max_stone,arr[x]-func(x+i,max(m,i)));
        }
        best[x][m]=max_stone;
        return max_stone;
    }
    int stoneGameII(vector<int>& piles) {
        p=piles;
        num=piles.size();
        for(int i=num-1;i>=0;i--){
            arr[i]=arr[i+1]+p[i];
        }
        return func(0,1);
    }
};
```

