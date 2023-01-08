import queue
import math

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        q = queue.PriorityQueue()
        for i in nums: q.put(-1*i)
        score = 0
        for j in range(k):
            num = -1*q.get()
            q.put(-1*math.ceil(num/3))
            score+=num
        return score