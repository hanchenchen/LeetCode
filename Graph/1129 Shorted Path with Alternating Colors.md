# 1129 Shorted Path with Alternating Colors

1. BFS

   执行用时 :24 ms, 在所有 C++ 提交中击败了95.81%的用户

   内存消耗 :11.6 MB, 在所有 C++ 提交中击败了100.00%的用户

2. ```c++
   class Solution {
   public:
       vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
           queue<int> r,b;
           int red[n],blue[n],x=0;
           red[0]=blue[0]=0;
           for(int i=1;i<n;i++){
               red[i]=blue[i]=INT_MAX;
           }
           r.push(0);
           b.push(0);
           while(!r.empty()||!b.empty()){
               if(!r.empty()){
                   x=r.front();
                   r.pop();
                   for(int i=0;i<blue_edges.size();i++){
                       if(blue_edges[i][0]==x&&blue[blue_edges[i][1]]-1>red[x]){
                           blue[blue_edges[i][1]]=red[x]+1;
                           b.push(blue_edges[i][1]);
                       }
                   }
               }
               if(!b.empty()){
                   x=b.front();
                   b.pop();
                   for(int i=0;i<red_edges.size();i++){
                       if(red_edges[i][0]==x&&red[red_edges[i][1]]-1>blue[x]){
                           red[red_edges[i][1]]=blue[x]+1;
                           r.push(red_edges[i][1]);
                       }
                   }
               }
           }
           vector<int> ans;
           for(int i=0;i<n;i++){
               ans.push_back(min(red[i],blue[i]));
               if(ans[i]==INT_MAX)ans[i]=-1;
           }
           return ans;
       }
   };
   ```

3. Dijkstra

   执行用时 :44 ms, 在所有 C++ 提交中击败了52.69%的用户

   内存消耗 :11.7 MB, 在所有 C++ 提交中击败了100.00%的用户

   ```c++
   class Solution {
   public:
       vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
           vector<int> ans;
           int red[n]={0},blue[n]={0};
           int vis[n]={0};//red 1/3 blue 2/3
           vis[0]=3;
           int flag=1;
           for(int i=1;i<n;i++){
               blue[i]=red[i]=INT_MAX;
           }
           for(int i=0;i<blue_edges.size();i++){
               if(blue_edges[i][0]==0&&blue_edges[i][1]!=0)blue[blue_edges[i][1]]=1;
           }
           for(int i=0;i<red_edges.size();i++){
               if(red_edges[i][0]==0&&red_edges[i][1]!=0)red[red_edges[i][1]]=1;
           }
           while(flag){
               flag=0;
               int dismin=INT_MAX;
               int node=-1;
               for(int i=0;i<n;i++){
                   if(vis[i]%2==0&&dismin>red[i]){
                       dismin=red[i];
                       node=i;
                   }
               }
               //cout<<node<<endl;
               if(node>=0){
                   flag=1;
                   vis[node]++;
                   for(int i=0;i<blue_edges.size();i++){
                       if(blue_edges[i][0]==node
                          &&vis[blue_edges[i][1]]<2
                          &&blue[blue_edges[i][1]]>dismin+1){
                           blue[blue_edges[i][1]]=dismin+1;
                       }
                   }
               }
               dismin=INT_MAX;
               node=-1;
               for(int i=0;i<n;i++){
                   if(vis[i]<2&&dismin>blue[i]){
                       dismin=blue[i];
                       node=i;
                   }
               }
               //cout<<node<<endl<<endl;
               if(node>=0){
                   flag=1;
                   vis[node]+=2;
                   for(int i=0;i<red_edges.size();i++){
                       if(red_edges[i][0]==node
                          &&vis[red_edges[i][1]]%2==0
                          &&red[red_edges[i][1]]>dismin+1){
                           red[red_edges[i][1]]=dismin+1;
                       }
                   }
               }
           }
           for(int i=0;i<n;i++){
               ans.push_back(min(red[i],blue[i]));
               if(ans[i]==INT_MAX)ans[i]=-1;
           }
           return ans;
       }
   };
   ```

4. recursion

   执行用时 :72 ms, 在所有 C++ 提交中击败了19.16%的用户

   内存消耗 :12.9 MB, 在所有 C++ 提交中击败了100.00%的用户

5. ```c++
   class Solution {
   public:
       vector<int> ans,blue_dis,red_dis;
       vector<vector<int>> red_edges,blue_edges;
       void to_red(int n,int dis,int c){
           if(c){
               if(dis>blue_dis[n])return;
               blue_dis[n]=dis;
               for(int i=0;i<red_edges.size();i++){
                   if(red_edges[i][0]==n&&red_dis[red_edges[i][1]]>dis+1)
                       to_red(red_edges[i][1],dis+1,0);
           }
           }else{
               if(dis>red_dis[n])return;
               red_dis[n]=dis;
               for(int i=0;i<blue_edges.size();i++){
                   if(blue_edges[i][0]==n&&blue_dis[blue_edges[i][1]]>dis+1)
                       to_red(blue_edges[i][1],dis+1,1);
               }
           }
           
       }
   
       vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edge, vector<vector<int>>& blue_edge) {
           for(int i=0;i<n;i++){
               blue_dis.push_back(INT_MAX);
               red_dis.push_back(INT_MAX);
               ans.push_back(INT_MAX);
           }
           red_edges=red_edge;
           blue_edges=blue_edge;
           to_red(0,0,1);
           to_red(0,0,0);
           for(int i=0;i<n;i++){
               ans[i]=min(blue_dis[i],red_dis[i]);
               if(ans[i]==INT_MAX)ans[i]=-1;
           }
           return ans;
       }
   };
   ```