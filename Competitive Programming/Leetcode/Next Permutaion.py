class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        pivot = -1
        cliff = 0
        for i in range(len(nums), 0, -1):
            if nums[i-1] < nums[i]:
                cliff = i
                pivot = i-1
                break

        if cliff == 0:
            return
        
        low = cliff
        for i in range(cliff, len(nums)):
            if nums[i] > nums[pivot] and nums[i] < nums[low]:
                low = i
        
        nums[pivot], nums[low] = nums[low], nums[pivot]

        nums[cliff:] = sorted(nums[cliff:])
