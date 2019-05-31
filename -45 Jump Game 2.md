# -45 Jump Game 2 

执行用时 : 52 ms, 在Jump Game II的C++提交中击败了11.38% 的用户

内存消耗 : 41.3 MB, 在Jump Game II的C++提交中击败了5.08% 的用户

```c++
class Solution {
public:
    vector<int> num;
    map<int,int> vis;
    int len;
    int func(int index){
        if(vis.find(index)!=vis.end())
            return vis[index];
        if(num[index]>=len-index-1){
            return 1;
        }else if(num[index]==0){
            return len;
        }else{
            int c=func(index+num[index]);
            if(c!=1)
                for(int i=num[index]-1;i>=1;i--){
                    int x=func(index+i);
                    c=c<x?c:x;
                    if(c==1)break;
            }
            vis.insert(pair<int,int>(index,1+c));
            return 1+c;
        }
        
    }
    int jump(vector<int>& nums) {
        len=nums.size();
        if(len<=1)return 0;
        num=nums;
        return func(0);
        
    }
};
```

执行用时 : 44 ms, 在Jump Game II的C++提交中击败了11.68% 的用户

内存消耗 : 42.2 MB, 在Jump Game II的C++提交中击败了5.08% 的用户

```c++
class Solution {
public:
    vector<int> num;
    map<int,int> vis;
    int len;
    int func(int index){
        if(vis.find(index)!=vis.end())
            return vis[index];
        if(num[index]>=len-index-1){
            return 1;
        }else if(num[index]==0){
            return len;
        }else{
            int c=func(index+num[index]);
            if(c!=1)
                for(int i=num[index]-1;i>=1;i--){
                    if(num[index+i]<=num[index]-i)continue;
                    int x=func(index+i);
                    c=c<x?c:x;
                    if(c==1)break;
            }
            vis.insert(pair<int,int>(index,1+c));
            //cout<<index<<endl;
            return 1+c;
        }
        
    }
    int jump(vector<int>& nums) {
        len=nums.size();
        if(len<=1)return 0;
        num=nums;
        return func(0);
        
    }
};
```

