# [LCP 20. 快速公交](https://leetcode-cn.com/problems/meChtZ/)

> 小扣打算去秋日市集，由于游客较多，小扣的移动速度受到了人流影响：
>
> 小扣从 x 号站点移动至 x + 1 号站点需要花费的时间为 inc；
> 小扣从 x 号站点移动至 x - 1 号站点需要花费的时间为 dec。
> 现有 m 辆公交车，编号为 0 到 m-1。小扣也可以通过搭乘编号为 i 的公交车，从 x 号站点移动至 jump[i]*x 号站点，耗时仅为 cost[i]。小扣可以搭乘任意编号的公交车且搭乘公交次数不限。
>
> 假定小扣起始站点记作 0，秋日市集站点记作 target，请返回小扣抵达秋日市集最少需要花费多少时间。由于数字较大，最终答案需要对 1000000007 (1e9 + 7) 取模。
>
> 注意：小扣可在移动过程中到达编号大于 target 的站点。
>

> 提示：
> 1 <= target <= 10^9
> 1 <= jump.length, cost.length <= 10
> 2 <= jump[i] <= 10^6
> 1 <= inc, dec, cost[i] <= 10^6
>
> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com/problems/meChtZ
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

##### 方法：记忆化搜索

将问题看作求从终点$\Rightarrow$起点最少需要花费时间

使站点号 n 减少最快的方法为以下之一：

1. 向左走几个站点使到达站点号正好为 jump[i] 的整数倍，然后花费cost[i]时间移动至 n// jump[i] 站点
2. 向右走几个站点使到达站点号正好为 jump[i] 的整数倍，然后花费cost[i]时间移动至 n// jump[i] +1站点

可以得到：

从站点n回到起点0的最短时间  =  

min( 向左走`n%jump[i]`个站到达`(n-n%jump[i])`+花费`cost[i]`时间移动至 `n// jump[i]` 站点+从站点 `n// jump[i]`回到起点0的最短时间，

向右走`(jump[i] - n%jump[i])`个站到达`(n-n%jump[i]+jump[i])`+花费`cost[i]`时间移动至 `n// jump[i]+1 `站点+从站点 `n// jump[i]`回到起点0的最短时间 )

##### 注意处理以下情况⚠️ 

**n<jump[i]**，此时注意停止递归

**n%jump[i] == 0**，此时不用向左或者向右走，直接花费cost[i]时间移动至 n// jump[i] 站点即可

##### 代码如下：

```python
class Solution:
    def dfs(self, pos: int) -> int:
        # print(pos)
        if pos in self.memo.keys():
            return self.memo[pos]
        ans = self.inc*pos
        for i in range(len(self.jump)):
            if not pos%jump[i]:
                ans = min(ans, cost[i]+self.dfs(pos//jump[i]))
            elif pos < jump[i]:
                ans = min(ans,(self.jump[i] - pos%self.jump[i])*dec+cost[i]+ inc)   else:
                ans = min(ans, (pos%jump[i])*inc+cost[i]+self.dfs(pos//jump[i],inc,dec,jump,cost), (jump[i] - pos%jump[i])*dec+cost[i]+self.dfs(pos//jump[i]+1,inc,dec,jump,cost))
        self.memo[pos] = ans
        return ans
    def busRapidTransit(self, target: int, inc: int, dec: int, jump: List[int], cost: List[int]) -> int:
        self.memo = {0:0,1:inc}
        self.maxTime = inc*target
        self.inc = inc
        self.dec = dec
        self.jump = jump
        self.cost = cost
        return self.dfs(target)%int(1e9+7)
        print(self.memo)
```