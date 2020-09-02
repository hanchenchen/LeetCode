# [剑指 Offer 20. 表示数值的字符串](https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)

#### 方法一：正则表达式

*没有确定有限状态自动机快*

执行用时：56 ms, 在所有 Python3 提交中击败了18.01%的用户

内存消耗：13.7 MB, 在所有 Python3 提交中击败了63.60%的用户

```python
class Solution:
    def isInteger(self, s:str) -> bool:
        p = re.compile(r'[+-]?\d+')
        m = re.match(p,s)
        if m:
            return re.match(p,s).span() == (0, len(s))
        else:
            return False

    def isFloat(self, s:str) -> bool:
        p = re.compile(r'[+-]?(\d+[.]\d+|\d+[.]|[.]\d+)') 
        m = re.match(p,s)
        # print(m)
        if m:
            return re.match(p,s).span() == (0, len(s))
        else:
            return False

    def isNumber(self, s: str) -> bool:
        '''
        i = 0
        j = len(s) - 1
        while i<=j:
            if s[i] == ' ':
                i += 1 
            elif s[j] == ' ':
                j -= 1
            else:
                break
        if i>j:
            return False
        s = s[i:j+1]
        '''
        arr = s.split()
        # print(arr)
        if len(arr)!=1:
            return False
        s = arr[0]
        
        arr = s.split('e')
        if len(arr) == 1:
            arr = s.split('E')
        if len(arr) == 1:
            return self.isInteger(s) or self.isFloat(s)
        elif len(arr) == 2:
            return (self.isInteger(arr[0]) or self.isFloat(arr[0])) and self.isInteger(arr[1])
        else:
            return False
        

        
```

#### 方法二：确定有限状态自动机

