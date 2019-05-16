# 34 Find First and Last Position of Element in Sorted Array

执行用时 : 0 ms, 在Find First and Last Position of Element in Sorted Array的C++提交中击败了100.00% 的用户

内存消耗 : 10.6 MB, 在Find First and Last Position of Element in Sorted Array的C++提交中击败了70.40% 的用户

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if(nums.size()==0){
            vector<int> ans;
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        if(nums.size()==1){
            vector<int> ans;
            if(nums[0]==target){
                ans.push_back(0);
                ans.push_back(0);
                return ans;
            }
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int left=0;int right=nums.size()-1;
        int mid;
        vector<int> ans;
        while(left<right){
            mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid;
            }else{
                left=right=mid;
                while(left>=0&&nums[left]==target)left--;
                while(right<nums.size()&&nums[right]==target)right++;
                ans.push_back(left+1);
                ans.push_back(right-1);
                return ans;
            }
            
        }
        if(nums[left]==target){
            right=left;
            while(left>=0&&nums[left]==target)left--;
            while(right<nums.size()&&nums[right]==target)right++;
            ans.push_back(left+1);
            ans.push_back(right-1);
            return ans;
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;

        cout<<mid<<" "<<nums[mid]<<endl;
        
    }
};
```

1. [] 0
2. [1,4] 4 ；在循环中因left==right直接跳出了，需要在循环后面再加一个判断