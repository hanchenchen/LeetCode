# 33 Search in Rotated Sorted Array

执行用时 : 0 ms, 在Search in Rotated Sorted Array的C++提交中击败了100.00% 的用户

内存消耗 : 8.9 MB, 在Search in Rotated Sorted Array的C++提交中击败了73.63% 的用户

执行用时 : 8 ms, 在Search in Rotated Sorted Array的C++提交中击败了97.61% 的用户

内存消耗 : 8.9 MB, 在Search in Rotated Sorted Array的C++提交中击败了71.85% 的用户

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size()-1;
        if(len<0)return -1;
        int left=0,right=len;int mid;
        while(left<right){
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
        if(nums[left]==target)return left;
        //if(nums[right]==target)return right;
        return -1;
    }
};
```

