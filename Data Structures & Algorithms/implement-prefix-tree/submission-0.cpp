// 1. Define the individual node structure
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c :word){
            int index = c-'a';
            if(curr->children[index]==nullptr){
                curr->children[index]= new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c: word){
            int index = c - 'a';
            if(curr->children[index] == nullptr){
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEnd;//checks if the words ends there and not keep going more
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix){
            int index = c - 'a';
            if(curr->children[index] == nullptr){
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
};
