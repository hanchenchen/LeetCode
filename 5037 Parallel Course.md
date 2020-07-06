# 5037 Parallel Course

https://leetcode-cn.com/contest/biweekly-contest-5/problems/parallel-courses/

```c++
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        int degree[N+1]={0};
        for(int i=0;i<relations.size();i++){
            degree[relations[i][0]]++;
        }
        int ans=0;
        int flag=1;
        int vis[N+1]={0};
        while(flag){
            stack<int> st;
            flag=0;
            int i=1;
            for(;i<N+1;i++){
                if(!vis[i]&&degree[i]==0)st.push(i);
            }
            if(st.empty())break;
            ans++;
            flag=1;
            while(!st.empty()){
                i=st.top();
                st.pop();
                vis[i]=1;
                for(int j=0;j<relations.size();j++){
                if(relations[j][1]==i)degree[relations[j][0]]--;
            }
            }
        }
        for(int i=1;i<=N;i++){
            //cout<<vis[i]<<" ";
            //cout<<degree[i]<<endl;
            if(vis[i]!=1)return -1;
        }
        return ans;
    }
};
```

