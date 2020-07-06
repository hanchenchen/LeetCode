# 31 Next Permutation

执行用时 : 16 ms, 在Next Permutation的C++提交中击败了96.48% 的用户

内存消耗 : 8.7 MB, 在Next Permutation的C++提交中击败了81.49% 的用户

执行用时 : 24 ms, 在Next Permutation的C++提交中击败了43.24% 的用户

内存消耗 : 8.6 MB, 在Next Permutation的C++提交中击败了84.99% 的用户

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)return;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                int j=nums.size()-1;
                int cc=nums[i-1];
                int index=0;
                int hh=INT_MAX;
                while(j>=i){
                    if(nums[j]>cc){
                        if(hh>nums[j]){
                            index=j;
                            hh=nums[j];
                        }
                        if(nums[j]==cc+1)break;
                    }
                    j--;
                }
                nums[index]=cc;
                nums[i-1]=hh;
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
        
        sort(nums.begin(),nums.end());
        return;
    }
};
```

