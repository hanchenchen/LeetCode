# 1135 Connecting Cities With Minimum Cost

https://leetcode-cn.com/contest/biweekly-contest-5/problems/connecting-cities-with-minimum-cost/

```c++
class Solution {
public:

    const int max=10005;
    int v[10005]={0};
    int getroot(int a){
        while(a!=v[a])a=v[a];
        return a;
    }
    int minimumCost(int N, vector<vector<int>>& conections) {
        int i=0;
        int sum=0;
        for(int i=1;i<=N;i++){
            v[i]=i;
        }
        int a,b;
        sort(conections.begin(),conections.end(),[](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; } );
        for(int i=0;i<conections.size();i++){
            a=getroot(conections[i][0]);
            b=getroot(conections[i][1]);
            if(a!=b){
                v[a]=b;
                sum+=conections[i][2];
            }
        }
        int x=getroot(1);
        for(int i=2;i<=N;i++){
            if(getroot(i)!=x)return -1;
        }
        return sum;
    }
};c
```

