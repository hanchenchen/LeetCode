# 55 Jump Game

执行用时 : 16 ms, 在Jump Game的C++提交中击败了90.61% 的用户

内存消耗 : 10 MB, 在Jump Game的C++提交中击败了69.77% 的用户

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>0)continue;
            int j=1;
            for(;j<=i;j++){
                if(nums[i-j]>j)break;
            }
            if(j==i+1)return false;
        }
        return true;
    }
};
```

