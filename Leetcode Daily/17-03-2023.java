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

class Trie {
    TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode node = root;
        for(char c : word.toCharArray()){
            if(node.find(c)==null){
                node.insert(c, new TrieNode());
            }
            node = node.find(c);
        }
        node.end = true;
    }
    
    public boolean search(String word) {
        TrieNode node = root;
        for(char c : word.toCharArray()){
            node = node.find(c);
            if(node!=null) continue;
            else return false;
        }
        return node.end && node!=null;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for(char c : prefix.toCharArray()){
            node = node.find(c);
            if(node!=null) continue;
            else return false;
        }
        return node!=null;
    }
}