# 80 Remove Duplicates from Sorted Array II

执行用时 :16 ms, 在所有 C++ 提交中击败了96.78%的用户

内存消耗 :8.8 MB, 在所有 C++ 提交中击败了79.05%的用户

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int ans=1;
        //int arr[nums.size()]={0};
        int b=1;int a=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                a=1;
            }else{
                a=b+1;
            }
            b=a;
            if(a>2)continue;
            nums[ans++]=nums[i];
        }
        return ans;
    }
};
```



执行用时 :20 ms, 在所有 C++ 提交中击败了89.90%的用户

内存消耗 :8.8 MB, 在所有 C++ 提交中击败了75.14%的用户

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int ans=1;
        int arr[nums.size()]={0};
        arr[0]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                arr[i]=1;
            }else{
                arr[i]=arr[i-1]+1;
            }
            if(arr[i]>2)continue;
            nums[ans++]=nums[i];
        }
        return ans;
    }
};
```

