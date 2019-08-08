# 42 Trapping Rain Water

执行用时 : 4 ms, 在Trapping Rain Water的C++提交中击败了99.80% 的用户

内存消耗 : 9.9 MB, 在Trapping Rain Water的C++提交中击败了69.53% 的用户

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1)return 0;
        int ans=0;
        stack<int> q;
        int j=0;
        while(j<height.size()-1&&height[j]<=height[j+1])j++;
        if(j==height.size()-1)return 0;
        for(int i=j+1;i<height.size();i++){
            if(height[j]>height[i]){
                q.push(height[i]);
            }else{
                while(!q.empty()){
                    ans+=height[j];
                    ans-=q.top();
                    q.pop();
                }
                j=i;
            }
        }
        if(q.empty())return ans;

        int len = j;
        j=height.size()-1;
        while(j>1&&height[j]<=height[j-1])j--;
        if(j==1)return 0;
        stack<int> p;
        for(int i=j-1;i>=len;i--){
            if(height[j]>height[i]){
                p.push(height[i]);
            }else{
                while(!p.empty()){
                    ans+=height[j];
                    ans-=p.top();
                    p.pop();
                }
                j=i;
            }
        }
        return ans;
    }
};
```

