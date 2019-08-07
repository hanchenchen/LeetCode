# vector

1. Initialization

   ```c++
   vector<int> (长度);
   vector<int> (长度,初值);
   vector<vector<int>> v(2,vector<int>(4, 0));
   ```

2. algorithm

   ```c++
   #include<algorithm>
   sort(v.begin(),v.end());
   vector<int>::iterator iter=find(v.begin(),v.end(),x);//int x
   ```

3. unique/erase

   ```c++
   ans.erase(unique(ans.begin(), ans.end()), ans.end());//去除重复元素
   erase(迭代器);//删除单个元素
   erase(迭代器,迭代器);//左闭右开
   ```

4. 1