# 88 Merge Sorted Array

执行用时 :8 ms, 在所有 C++ 提交中击败了90.49%的用户

内存消耗 :8.6 MB, 在所有 C++ 提交中击败了91.09%的用户

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int p=m+n-1;
        for(;p>=0;p--){
            //cout<<p<<i<<j<<endl;
            if(i>=0&&j>=0)nums1[p]=nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
            else if(j<0)nums1[p]=nums1[i--];
            else if(i<0)nums1[p]=nums2[j--];
        }
    }
};
```

