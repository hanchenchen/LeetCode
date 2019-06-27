# 75 Sort Colors

1. <!--one-pass-->

   执行用时 :4 ms, 在所有 C++ 提交中击败了95.78%的用户

   内存消耗 :8.8 MB, 在所有 C++ 提交中击败了5.17%的用户

   ```c++
   //荷兰国旗问题
   class Solution {
   public:
       void sortColors(vector<int>& nums) {
           int a=0,b=nums.size()-1;
           for(int i=0;i<=b;i++){
               if(nums[i]==1)continue;
               if(nums[i]==0){
                   nums[i]=nums[a];
                   nums[a]=0;
                   a++;
               }
               if(nums[i]==2){
                   nums[i]=nums[b];
                   nums[b]=2;
                   b--;
                   i--;
               }
           }
       }
   };
   ```

   

   ```c++
   class Solution {
   public:
       void sortColors(vector<int>& nums) {
           int a=0,b=0;//,c=0;
           int p;
           for(int i=0;i<nums.size();i++){
               p=nums[i];
               nums[i]=2;
               if(p==0){
                   nums[b]=1;nums[a]=0;
                   a++;b++;
               }else if(p==1){
                   nums[b]=1;
                   b++;
               }
               
           }
       }
   };
   ```

   

2. <!--two-pass-->

   执行用时 :4 ms, 在所有 C++ 提交中击败了95.78%的用户

   内存消耗 :8.8 MB, 在所有 C++ 提交中击败了5.17%的用户

   ```c++
   class Solution {
   public:
       void sortColors(vector<int>& nums) {
           int a=0,b=0;//,c=0;
           for(int i=0;i<nums.size();i++){
               if(nums[i]==0){
                   a++;
               }else if(nums[i]==1){
                   b++;
               }
           }
           for(int i=0;i<nums.size();i++){
               if(a){
                   nums[i]=0;a--;
               }else if(b){
                   nums[i]=1;b--;
               }else{
                   nums[i]=2;
               }
           }
       }
   };
   ```



