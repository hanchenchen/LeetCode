# LeetCode 第 210 场周赛题解



![image-20201012104555655](/Users/cc/Desktop/image-20201012104555655.png)



### [𝟙 括号的最大嵌套深度](https://leetcode-cn.com/problems/maximum-nesting-depth-of-the-parentheses/)

#### 方法一：

栈

##### Code：

> 执行用时：60 ms, 在所有 Python3 提交中击败了100.00%的用户
>
> 内存消耗：13.5 MB, 在所有 Python3 提交中击败了100.00%的用户

```python
class Solution:
    def maxDepth(self, s: str) -> int:
        stack = []
        ans = 0
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(1)
            elif s[i] == ')':
                stack.pop()
            ans = max(ans,len(stack))
        return ans
```

**时间复杂度：O(N)**

**空间复杂度：O(N)**



### [𝟚 最大网络秩](https://leetcode-cn.com/problems/maximal-network-rank/)

#### 方法一：

记最大值为`first`，次大值为`second`

`first` > `second` > `other`

`first`+`first` - 1>= `first`+`second` 

`first`+`second` - 1 >= `first ` + `other`

所以求得`firstList`和`secondList`后，计算`first`+`first` 和`first`+`second` 即可得到`ans`

##### Code:

> 执行用时：76 ms, 在所有 Python3 提交中击败了100.00%的用户
>
> 内存消耗：14 MB, 在所有 Python3 提交中击败了100.00%的用户

```python
class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        # 记录每个点的秩
        r = [0 for i in range(n)] 
        # 邻接矩阵 0:不相邻 1:相邻
        ifCon = [[0 for j in range(n)] for i in range(n)] 
        for i,j in roads:
            r[i]+=1
            r[j]+=1
            ifCon[i][j] = 1
            ifCon[j][i] = 1

        first = 0
        second = 1
        if r[first]<r[second]:
            first, second = second, first
        '''
        first: 值最大的秩的下标的list
        second: 值次大的秩的下标的list
        当输入为 n = 5, roads = [[2,3],[0,3],[0,4],[4,1]]
        r = [2, 1, 1, 2, 2]
        first = [0, 3, 4]
        second = [1, 2]
        '''
        first = [first]
        second = [second]
        for i in range(2,n):
            if r[i]==r[first[0]]:
                first.append(i)
            elif r[i]>r[first[0]]:
                second = first
                first = [i]
            elif r[i]==r[second[0]]:
                second.append(i)
            elif r[i]>r[second[0]]:
                second = [i]
        # print(r,first,second)
        # 计算 `first`+`first` 和`first`+`second` 
        ans = 0
        if len(first)>1:
            for i in range(len(first)):
                for j in range(i+1,len(first)):
                    ans = max(ans,r[first[i]]+r[first[j]]-ifCon[first[i]][first[j]])
            return ans
        for j in second:
            ans = max(ans,r[first[0]]+r[j]-ifCon[first[0]][j])
        return ans
```

**时间复杂度：O(N+M)**

**空间复杂度：O(N^2^)**

参考：https://leetcode-cn.com/problems/maximal-network-rank/solution/onm-mei-ju-fa-by-zerotrac2/



#### 方法二：

二重循环

##### Code：

> 执行用时：116 ms, 在所有 Python3 提交中击败了100.00%的用户
>
> 内存消耗：14 MB, 在所有 Python3 提交中击败了100.00%的用户

```python
class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        # 记录每个点的秩
        r = [0 for i in range(n)] 
        # 邻接矩阵 0:不相邻 1:相邻
        ifCon = [[0 for j in range(n)] for i in range(n)] 
        for i,j in roads:
            r[i]+=1
            r[j]+=1
            ifCon[i][j] = 1
            ifCon[j][i] = 1
        ans = 0
        for i in range(n):
            for j in range(i+1,n):
                ans = max(ans,r[i]+r[j]-ifCon[i][j])
        return ans
```

**时间复杂度：O(N^2^)**

**空间复杂度：O(N^2^)**



### [𝟛 分割两个字符串得到回文串](https://leetcode-cn.com/problems/split-two-strings-to-make-palindrome/)

#### 方法一：

a~prefix~ + b~suffix~ = `a[0:i] `+ (`a[i:n-i]` or `b[i:n-i]` ) + `b[-i:-1]`

`a[0:i]`：a的第0位到第i-1位组成的子字符串（左闭右开）

``b[-i:-1]``：b的倒数第i位到最后一位组成的子字符串

要使a~prefix~ + b~suffix~为回文串，则 `a[0:i] `+ `b[-i:-1]`为回文串，`a[i:n-i]`或`b[i:n-i]`为回文串

b~prefix~ + a~suffix~ 同理

##### Code：

> 执行用时：204 ms, 在所有 Python3 提交中击败了100.00%的用户
>
> 内存消耗：15.2 MB, 在所有 Python3 提交中击败了100.00%的用户

```python
class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        n = len(a)
        '''
        i<mid时
        ifPalin[i] == 1 则 a[i:n-i]为回文串
        i>mid时
        ifPalin[i] == 1 则 b[i:n-i]为回文串
        '''
        ifPalin = [0 for i in range(n)]
        # ifPalin_b = [0 for i in range(n)]
        mid = n//2
        left = mid - 1
        if n%2:
            right = mid + 1
        else:
            right = mid
        while left>=0:
            if a[left] == a[right]:
                ifPalin[left] = 1
            else:
                break
            left -= 1
            right += 1

        left = mid - 1
        if n%2:
            right = mid + 1
        else:
            right = mid
        while left>=0:
            if b[left] == b[right]:
                ifPalin[right]= 1
            else:
                break
            left -= 1
            right += 1
        # a为回文串或者b为回文串
        if ifPalin[0] or ifPalin[n-1]:
            return True
        i = 0
        j = n - 1
        while i<j:
            if a[i] == b[j]:
                i+=1
                j-=1
            else:
                break
        # `a[0:i] `+ (`a[i:n-i]` or `b[i:n-i]` ) + `b[-i:-1]`
        if ifPalin[i] or ifPalin[j] or i>=j:
            return True
        i = 0
        j = len(a) - 1
        while i<j:
            if b[i] == a[j]:
                i+=1
                j-=1
            else:
                break
        # `b[0:i] `+ (`a[i:n-i]` or `b[i:n-i]` ) + `a[-i:-1]`
        if ifPalin[i] or ifPalin[j] or i>=j:
            return True
        return False
```



#### [𝟜 1617. Count Subtrees With Max Distance Between Cities](https://leetcode-cn.com/problems/count-subtrees-with-max-distance-between-cities/)

#### 方法一：Floyd+状态压缩

##### Code：

> 执行用时：1588 ms, 在所有 Python3 提交中击败了100.00%的用户
>
> 内存消耗：13.4 MB, 在所有 Python3 提交中击败了100.00%的用户

```python
class Solution:        
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
      	# 邻接矩阵
        arr = [[1e9 for i in range(n+1)] for i in range(n+1)]
        for i,j in edges:
            arr[i][j] = arr[j][i] = 1
        # 记录路径，path[i][j]记录了从i到j必须经过的结点
        path = [[0 for i in range(n+1)] for i in range(n+1)]
        #Floyd
        for k in range(1,n+1):
            for i in range(1,n+1):
                for j in range(1,n+1):
                    if arr[i][k] + arr[k][j]<arr[i][j]:
                        arr[i][j] = arr[j][i] = arr[i][k] + arr[k][j]
                        path[i][j] = path[j][i] = k
        ans = [0 for i in range(n)]
        t = 0
        #二进制枚举组合
        for t in range(2**n):
            temp = 0
            loc = [] #选择的结点，用这些结点构成子树
            for i in range(n):
                if 1<<i&t:
                    loc.append(i+1)
            if len(loc)<2:
                continue
            flag = 0
            for i in range(len(loc)):
                for j in range(i+1,len(loc)):
                  	# 如果loc[i]和loc[j]在完整的树中不可到达，退出循环，可以省略以下两行代码
                    if arr[loc[i]][loc[j]]>=1e9:
                        break
                    # 如果loc[i]和loc[j]在之间的路径没有包含在子树中，退出循环
                    if arr[loc[i]][loc[j]]>1 and not path[loc[i]][loc[j]] in loc:
                        break
                    # 保存最大的路径长度
                    temp = max(temp,arr[loc[i]][loc[j]])
                else:
                    continue
                break
            else:
                if temp<n:
                    ans[temp]+=1
                    # print(loc,temp)
        return ans[1:]
```

