type Trie struct {
    children [10]*Trie
    char byte
}

func (t *Trie) insert(word string) {
    node := t
    for i := 0; i < len(word); i++ {
        if node.children[word[i] - '0'] == nil {
            node.children[word[i] - '0'] = &Trie{char: word[i]}
        }
        node = node.children[word[i] - '0']
    }
}

func (t *Trie) search(word string) int {
    node := t
    for i := 0; i < len(word); i++ {
        if node.children[word[i] - '0'] == nil {
            return i
        }
        node = node.children[word[i] - '0']
    }
    return len(word)
}

func longestCommonPrefix(arr1 []int, arr2 []int) int {
    trie := &Trie{}
    ans := 0
    
    for i := 0; i < len(arr1); i++ {
        str := fmt.Sprint(arr1[i])
        trie.insert(str)
    }
    for i := 0; i < len(arr2); i++ {
        str := fmt.Sprint(arr2[i])
        ans = max(ans, trie.search(str))
    }
    return ans
}
