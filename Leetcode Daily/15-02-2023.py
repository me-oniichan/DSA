class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        sum=0
        for i in num: sum= sum*10+i
        sum+=k
        arr=[]
        for i in str(sum): arr.append(int(i))
        return arr