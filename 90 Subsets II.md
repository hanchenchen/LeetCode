# 90 Subsets II

1. 迭代

   执行用时 :24 ms, 在所有 C++ 提交中击败了37.88%的用户

   内存消耗 :9.3 MB, 在所有 C++ 提交中击败了65.51%的用户

   ```c++
   class Solution {
   public:
       vector<vector<int>> ans;
       vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           sort(nums.begin(),nums.end());
           vector<int> v;
           ans.push_back(v);
           int k=1;
           for(int i=0;i<nums.size();i++){
               int j=0;
               for(;j<k;j++){
                   ans.push_back(ans[j]);
               }
               int p=j;
               for(;j<ans.size();j++){
                   ans[j].push_back(nums[i]);
               }
               k=j;
               while(i+1<nums.size()&&nums[i+1]==nums[i]){
                   for(j=p;j<k;j++){
                       ans.push_back(ans[j]);
                   }
                   p=j;
                   for(;j<ans.size();j++){
                       ans[j].push_back(nums[i]);
                   }
                   k=j;
                   i++;
               }
           }
           return ans;
       }
   };
   ```

2. index+递归

   执行用时 :20 ms, 在所有 C++ 提交中击败了53.68%的用户

   内存消耗 :10 MB, 在所有 C++ 提交中击败了28.79%的用户

   ```c++
   class Solution {
   public:
       vector<vector<int>> ans;
       vector<int> nums;
       void func(vector<int> v,int index){
           v.push_back(nums[index]);
           ans.push_back(v);
           for(int i=index+1;i<nums.size();i++){
               func(v,i);
               while(i<nums.size()-1&&nums[i]==nums[i+1])i++;//i--;
           }
       }
       vector<vector<int>> subsetsWithDup(vector<int>& num) {
           nums=num;
           sort(nums.begin(),nums.end());
           vector<int> v;
           ans.push_back(v);
           for(int i=0;i<nums.size();i++){
               func(v,i);
               while(i<nums.size()-1&&nums[i]==nums[i+1])i++;//i--;
           }
           return ans;
       }
   };
   ```

3. map+递归

   执行用时 :28 ms, 在所有 C++ 提交中击败了28.10%的用户

   内存消耗 :11.7 MB, 在所有 C++ 提交中击败了18.61%的用户

   ```c++
   class Solution {
   public:
       map<int,int> mii;
       vector<vector<int>> ans;
       void func(map<int,int> m,vector<int> v,int x){
           //cout<<x<<endl;
           v.push_back(x);
           ans.push_back(v);
           m[x]--;
           map<int,int>::iterator iter=m.find(x);
           for(;iter!=m.end();iter++){
               if(iter->second!=0)func(m,v,iter->first);
           }
       }
       vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           map<int,int>::iterator iter;
           sort(nums.begin(),nums.end());
           for(int i=0;i<nums.size();i++){
               iter=mii.find(nums[i]);
               if(iter==mii.end()){
                   mii.insert(pair<int,int>(nums[i],1));
               }else{
                   iter->second++;
               }
           }
           vector<int> v;
           ans.push_back(v);
           iter=mii.begin();
           for(;iter!=mii.end();iter++){
               //cout<<iter->first<<iter->second<<endl;
               func(mii,v,iter->first);
           }
           return ans;
       }
   };
   ```

   