class Solution:
    def sortTheStudents(self, score, k: int):
        return sorted(score, key=lambda x: x[k], reverse=True)