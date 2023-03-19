class TrieNode{
    TrieNode[] edges;
    boolean end = false;
    TrieNode(){
        edges = new TrieNode[26];
    }

    public TrieNode find(char c){
        return edges[c-'a'];
    }

    public void insert(char c, TrieNode node){
        edges[c-'a'] = node;
    }

}

class WordDictionary {
    TrieNode root = new TrieNode();
    public WordDictionary() {
        
    }
    
    public void addWord(String word) {
        TrieNode node = root;
        for(char c : word.toCharArray()){
            if(node.find(c)==null){
                node.insert(c, new TrieNode());
            }
            node = node.find(c);
        }
        node.end = true;
    }
    
    public boolean search(String word, int index, TrieNode node){
        if(index >= word.length() || node==null){
            return node!=null && node.end;
        }
        else if(word.charAt(index)=='.'){
            for(TrieNode c : node.edges){
                if(search(word, index+1, c)) return true;
            }
            return false;
        }
        return search(word, index+1, node.find(word.charAt(index)));
    }

    public boolean search(String word) {
        return search(word, 0, root);
    }
}