# 41 First Missing Positive

执行用时 : 0 ms, 在First Missing Positive的C++提交中击败了100.00% 的用户

内存消耗 : 8.6 MB, 在First Missing Positive的C++提交中击败了81.19% 的用户

```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]==i+1)continue;
            int j = nums[i];
            while(j>=1&&j<=len&&j!=nums[j-1]){
                //cout<<j<<endl;
                int mid=nums[j-1];
                nums[j-1]=j;
                j=mid;
            }
        }
        for(int i=0;i<len;i++){
            //cout<<i<<" "<<nums[i]<<" "<<endl;
            if(i+1!=nums[i])return i+1;
        }
        //cout<<"?";
        return len+1;
    }
};
```

