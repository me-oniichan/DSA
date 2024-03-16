class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        table = {0: -1}
        ones, zeros  = 0,0
        max_length = 0
        for idx,i in enumerate(nums):
            if i == 0:
                zeros += 1
            else:
                ones += 1
       
            if zeros - ones in table:
                max_length = max(max_length, idx - table[zeros - ones])
                
            else:
                table[zeros - ones] = idx
        return max_length
