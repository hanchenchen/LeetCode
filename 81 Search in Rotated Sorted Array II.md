# 81 Search in Rotated Sorted Array II

1. 在leetcode 33 的基础上添加

   ```c++
   while(left<right&&nums[left]==nums[left+1])left++;
               while(left<right&&nums[right]==nums[left])right--;
               while(left<right&&nums[right]==nums[right-1])right--;
               if(left>=right)break;
   ```

   执行用时 :12 ms, 在所有 C++ 提交中击败了69.98%的用户

   内存消耗 :8.5 MB, 在所有 C++ 提交中击败了92.93%的用户

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size()-1;
        if(len<0)return false;
        int left=0,right=len;int mid;
        while(left<right){
            while(left<right&&nums[left]==nums[left+1])left++;
            while(left<right&&nums[right]==nums[left])right--;
            while(left<right&&nums[right]==nums[right-1])right--;
            if(left>=right)break;
            mid=(left+right)/2;
            if(nums[left]<nums[right]){
                
                if(nums[mid]<target){
                    left=mid+1;
                }else{
                    right=mid;
                }
            }else{
                if(nums[left]<=nums[mid]){
                    if(nums[left]<=target
                       &&target<=nums[mid]){
                        right=mid;
                    }
                    else{
                        left=mid+1;
                    }
                }else{
                    if(nums[mid]<=target
                       &&target<=nums[right]){
                        left=mid;
                    }
                    else{
                        right=mid-1;
                    }
                }
            }
        }
        if(nums[left]==target)return true;
        //if(nums[right]==target)return right;
        return false;
    }
};
```



