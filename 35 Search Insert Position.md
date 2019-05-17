# 35 Search Insert Position

执行用时 : 4 ms, 在Search Insert Position的C++提交中击败了99.97% 的用户

内存消耗 : 8.8 MB, 在Search Insert Position的C++提交中击败了83.39% 的用户

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)return 0;
        int ans=0;
        while(ans<nums.size()&&nums[ans]<target){
            ans++;
        }
        return ans;
    }
};
```

