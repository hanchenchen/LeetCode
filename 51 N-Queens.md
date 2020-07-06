# 51 N-Queens 

执行用时 :12 ms, 在所有 C++ 提交中击败了82.58%的用户

内存消耗 :10.1 MB, 在所有 C++ 提交中击败了76.99%的用户

```c++
class Solution {
public:
    vector<string> v;
    vector<vector<string>> ans;
    int x=0,queen;
    int col[200]={0};
    void func(){
        if(x==queen){
            ans.push_back(v);
            return;
        }
        int ifi;
        for(int i=0;i<queen;i++){
            ifi=1;
            for(int j=0;j<x;j++){
                if(x-j==abs(i-col[j])||col[j]==i){
                    ifi=0;
                    break;
                }
            }
            if(ifi){
                col[x]=i;
                v[x][i]='Q';
                x++;
                func();
                col[x]=0;
                x--;
                v[x][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        queen=n;
        string s="";
        for(int i=0;i<queen;i++){
            s+='.';
        }
        for(int i=0;i<queen;i++){
            v.push_back(s);
        }
        func();
        return ans;
    }
};
```

