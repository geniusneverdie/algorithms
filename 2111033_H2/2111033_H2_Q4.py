# Q4
def cmp(a):
    return a[0]

def cmp2(a):
    return a[1]

class distence:
    """
    这里定义一个计算distence的类
    我们创建一个平均复杂度为n的算法，过程如下
    init时，将我们的点的数组优先按照x坐标排序，相同x坐标按照y坐标排序
    """

    def __init__(self, l):
        # 将点的列表进行排序
        l.sort(key=cmp2)
        l.sort(key=cmp)
        self.lis = l

    def getDis(self, i, j):
        # 本函数得到下标为i、j的点对的距离
        dx = self.lis[i][0] - self.lis[j][0]
        dy = self.lis[i][1] - self.lis[j][1]
        return dx * dx + dy * dy

    def getMin(self):
        min = 999999  # 存储最小结果
        idx_i = 0  # 存储最小结果的下标
        idx_j = 0
        for i in range(len(self.lis)):
            d = 999999
            temp_i = i
            temp_j = 0
            for j in range(i + 1, len(self.lis)):
                di = self.getDis(i, j)
                if di < d:
                    d = di
                    temp_j = j
                    temp_i = i
                else:
                    break
            if d < min:
                min = d
                idx_i = temp_i
                idx_j = temp_j

        return self.lis[idx_i], self.lis[idx_j], min


lis = [(1, 3), (4, 2), (3, 2), (8, 8), (6, 4), (6, 2)]
print(lis[2][0])
m = distence(lis)
print(m.getMin())
