
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.unique = set()
        self.count = 0
    
    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        self.unique.add(x)
        self.unique.add(y)
        rootx, rooty = self.find(x), self.find(y)
        if rootx == rooty:
            return
        if self.size[rootx] < self.size[rooty]:
            rootx, rooty = rooty, rootx
        self.parent[rooty] = rootx
        self.size[rootx] += self.size[rooty]
        self.count += 1

    def groups(self):
        return len(self.unique) - self.count

def seieve_of_eratosthenes(n):
    primes = []
    is_prime = [True] * (n + 1)
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return primes

class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        if len(nums) == 1: return True
        maxelem = max(nums)
        primes = seieve_of_eratosthenes(int(maxelem ** 0.5) + 1)

        uf = UnionFind(len(primes))

        for num in nums:
            if num == 1:
                return False

            p = []
            for i in range(len(primes)):
                if num % primes[i] == 0:
                    p.append(i)
            
            for i in p:
                uf.union(p[0], i)

        return uf.groups() == 1


