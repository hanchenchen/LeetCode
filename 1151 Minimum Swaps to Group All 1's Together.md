# 1151 Minimum Swaps to Group All 1's Together

```c++
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int num=0;
        for(int i=0;i<data.size();i++){
            if(data[i]==1)num++;
        }
        int num1=0;
        for(int i=0;i<num;i++){
            if(data[i]==1)num1++;
        }
        int ans=num1;
        for(int i=1;i+num<=data.size();i++){
            if(data[i-1]==1)num1--;
            if(data[i+num-1]==1)num1++;
            ans=max(ans,num1);
        }
        return num-ans;
    }
};
```