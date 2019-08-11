# 1152 Analyze User Website Visit Pattern

You are given three arrays `username`, `timestamp` and `website` of the same length `N` where the `ith` tuple means that the user with name `username[i]` visited the website `website[i]` at time `timestamp[i]`.

A *3-sequence* is a list of **not necessarily different** websites of length 3 sorted in ascending order by the time of their visits.

Find the 3-sequence visited **at least once** by the largest number of **users**(!!). If there is more than one solution, return the lexicographically minimum solution.

A 3-sequence `X` is lexicographically smaller than a 3-sequence `Y` if `X[0] < Y[0] `or `X[0] == Y[0] and (X[1] < Y[1] or X[1] == Y[1] and X[2] < Y[2])`. 

It is guaranteed that there is at least one user who visited at least 3 websites. No user visits two websites at the same time.

 

**Example 1:**

```
Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: 
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.
```

**Note:**

1. `3 <= N = username.length = timestamp.length = website.length <= 50`
2. `1 <= username[i].length <= 10`
3. `0 <= timestamp[i] <= 10^9`
4. `1 <= website[i].length <= 10`
5. Both `username[i]` and `website[i]` contain only lowercase characters.

```c++
class Solution {
public:
    map<string,int> m;
    struct Vis{
        string user;
        int times;
        int web;
    }vis[100];
    int arr[55][55][55];
    void func(vector<int> v){
        int vs[55][55][55];
        memset(vs,0,sizeof(vs));
        int n=v.size();
        if(n<3)return;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(vs[v[i]][v[j]][v[k]]==0)arr[v[i]][v[j]][v[k]]++;
                    vs[v[i]][v[j]][v[k]]=1;
                }
            }
        }
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        map<string,int>::iterator iter;
        int n=website.size();
        memset(arr,0,sizeof(arr));
        string webname[55];
        for(int i=0;i<n;i++){
            iter=m.find(website[i]);
            if(iter==m.end()){
                m.insert(pair<string,int>(website[i],i));
                webname[i]=website[i];
            }
        }
        for(int i=0;i<n;i++){
            vis[i].user=username[i];
            vis[i].times=timestamp[i];
            vis[i].web=m[website[i]];
        }
        sort(vis,vis+n,[](Vis a,Vis b){
            if(a.user!=b.user)return a.user<b.user;
            return a.times<b.times;
        });
        string name;
        for(int i=0;i<n;){
            name=vis[i].user;
            vector<int> v;
            while(i<n&&name==vis[i].user){
                v.push_back(vis[i].web);
                i++;
            }
            func(v);
        }
        vector<string> ans;ans.push_back("");ans.push_back("");ans.push_back("");
        int cc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(cc<arr[i][j][k]){
                        cc=arr[i][j][k];
                        ans[0]=webname[i];ans[1]=webname[j];ans[2]=webname[k];
                    }
                    if(cc==arr[i][j][k]){
                        if(ans[0]<webname[i]){
                            continue;
                        }
                        if(ans[0]==webname[i]&&ans[1]<webname[j]){
                            continue;
                        }
                        if(ans[0]==webname[i]&&ans[2]<webname[k]&&ans[1]==webname[j]){
                            continue;
                        }
                        ans[0]=webname[i];ans[1]=webname[j];ans[2]=webname[k];
                    }
                }
            }
        }
        return ans;
    }
};
```

