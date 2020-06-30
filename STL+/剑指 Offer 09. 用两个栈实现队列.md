# [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

##### 代码：

执行用时：560 ms, 在所有 Python3 提交中击败了70.21%的用户

内存消耗：17.1 MB, 在所有 Python3 提交中击败了100.00%的用户

```python
class CQueue:
    list1 = []
    list2 = []
    def __init__(self):
        self.list1 = []
        self.list2 = []
    def appendTail(self, value: int) -> None:
        self.list1.append(value)
        #print(self.list1)

    def deleteHead(self) -> int:
        if not len(self.list2):
            while len(self.list1):
                self.list2.append(self.list1.pop())
        if not len(self.list2):
            return -1
        else:
            return self.list2.pop()



# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
```

##### 注意⚠️：

1. `class`初始化时应该初始化`class`中的属性，否则容易解答错误