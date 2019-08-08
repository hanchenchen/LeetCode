# 26 Remove Duplicates from Sorted Array

执行用时 : 36 ms, 在Remove Duplicates from Sorted Array的C++提交中击败了80.59% 的用户

内存消耗 : 10 MB, 在Remove Duplicates from Sorted Array的C++提交中击败了74.02% 的用户

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[ans]!=nums[i])nums[++ans]=nums[i];
        }
        return ans+1;
    }
};
```

