# 1320 Minimum Distance to Type a World Using Two Fingers

执行用时 :48 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :9.5 MB, 在所有 C++ 提交中击败了100.00%的用户

```c++
class Solution {
public:
    struct p{
        int x=0,y=0;
    }pos[26];
    int dp[300][26][26];
    int dis(p a,p b){
        return abs(a.x-b.x)+abs(a.y-b.y);
    }
    int minimumDistance(string word) {
        int x=0,y=0;
        int i=0;
        for(;i<word.size();i++){
            for(int a=0;a<26;a++){
                for(int b=0;b<26;b++){
                    dp[i][a][b]=INT_MAX;
                }
            }
        }
        for(i=0;i<26;i++){
            pos[i].x=x++;
            pos[i].y=y;
            if(x==6){
                x=0;y++;
            }
            dp[0][word[0]-'A'][i]=dp[0][i][word[0]-'A']=0;
        }
       for(i=0;i<word.size()-1;i++){
            for(int a=0;a<26;a++){
                for(int b=0;b<26;b++){
                    if(dp[i][a][b]==INT_MAX)continue;
                    dp[i+1][a][word[i+1]-'A']=min(dp[i+1][a][word[i+1]-'A']
                    ,dp[i][a][b]+dis(pos[word[i+1]-'A'],pos[b]));
                    dp[i+1][word[i+1]-'A'][b]=min(dp[i+1][word[i+1]-'A'][b]
                    ,dp[i][a][b]+dis(pos[word[i+1]-'A'],pos[a]));
                }
            }
        }
        int ans=INT_MAX;
        for(int a=0;a<26;a++){
                for(int b=0;b<26;b++){
                    ans=min(ans,dp[i][a][b]);
                }
            }
        return ans;
    }
};
```

