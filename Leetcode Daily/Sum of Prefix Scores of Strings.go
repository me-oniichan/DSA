type Trie struct{
    children [26]*Trie
    isEnd int
    score int
}

func (t *Trie) insert(word string) {
    node := t
    for i := 0; i < len(word); i++ {
        c := word[i] - 'a'
        if node.children[c] == nil {
            node.children[c] = &Trie{isEnd: 0}
        }
        node = node.children[c]
    }
    node.isEnd += 1
}

func sumPrefixScores(words []string) []int {
    trie := &Trie{}
    ans := make([]int, len(words))
    for _, word := range words {
        trie.insert(word)
    }
    
    dfs(trie)

    for ind, word := range words {
        node := trie
        for i := 0; i < len(word); i++ {
            c := word[i] - 'a'
            node = node.children[c]
            if node != nil {
                ans[ind] += node.score
            }   
        }
    }
    return ans
}

func dfs(node *Trie) int {
    if node == nil{
        return 0
    }
    for i := 0; i < 26; i++ {
        node.score += dfs(node.children[i])
    }

    
    node.score+=node.isEnd
    return node.score
}
