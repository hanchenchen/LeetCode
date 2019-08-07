# map

1. find

   ```c++
   if(m.count(key)>0)
   {
     m[key];//若key不存在则插入一个默认值作为该key的value。
   }
   
   iter = m.find(key);
   if(iter!=m.end())
   {
     iter->second;//一次查找
   }
   ```

2. erase

   ```c++
   m.erase(键);
   m.erase(迭代器);
   m.erase(迭代器,迭代器);
   ```

3. 1