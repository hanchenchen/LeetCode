# 2Sum

1. map

   执行用时 :20 ms, 在所有 C++ 提交中击败了69.11%的用户

   内存消耗 :10.2 MB, 在所有 C++ 提交中击败了26.96%的用户

   ```c++
   class Solution {
   public:
       vector<int> twoSum(vector<int>& nums, int target) {
           map<int,int> m;
           map<int,int>::iterator iter;
           vector<int> v;
           v.push_back(0);v.push_back(0);
           for(int i=0;i<nums.size();i++){
               iter=m.find(nums[i]);
               if(iter!=m.end()){
                   v[0]=i;
                   v[1]=iter->second;
                   return v;
               }
               m.insert(pair<int,int>(target-nums[i],i));
           }
           return vector<int>();
       }
   };
   ```

# 3Sum

