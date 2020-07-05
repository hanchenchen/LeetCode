## Python3-Dictionary

==dictionary==

1. 取`key`列表：

   ```python
   list(dic.keys())
   ```

2. 取`value`列表：

   ```python
   list(dic.values())
   ```

3. 取`key-value pairs`列表

   ```python
   list(dic.items())
   ```

4. 按`key`排序

   ```python
   dic=dict(sorted(dic.items(),key=lambda x:x[0]))
   ```

5. 按`value`排序

   ```python
   dic=dict(sorted(dic.items(),key=lambda x:x[1]))
   ```

   