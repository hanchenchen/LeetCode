# 60 Permutation Sequence

执行用时 : 4 ms, 在Permutation Sequence的C++提交中击败了95.83% 的用户

内存消耗 : 8.1 MB, 在Permutation Sequence的C++提交中击败了76.49% 的

```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        int vis[n+1]={0};
        int x=1,m,j;
        for(int i=1;i<n;i++){
            x*=i;
        }
        for(int i=n-1;i>=1;i--){
            m=k/x;
            k=k%x;
            if(k)m++;
            else k=x;
            for(j=1;j<n+1;j++){
                if(vis[j]==0)m--;
                if(0==m)break;
            }
            ans+=('0'+j);
            vis[j]=1;
            x/=i;
        }
        for(int i=1;i<n+1;i++){
            if(vis[i]==0)ans+='0'+i;
        }
        return ans;
    }
};
```

1. 解答错误*2：逻辑错误
2. 执行出错：逻辑错误