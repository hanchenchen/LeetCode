# 27 Remove Element

执行用时 : 16 ms, 在Remove Element的C++提交中击败了37.65% 的用户

内存消耗 : 8.8 MB, 在Remove Element的C++提交中击败了71.75% 的用户

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(val!=nums[i])nums[ans++]=nums[i];
        }
        return ans;
    }
};
```

