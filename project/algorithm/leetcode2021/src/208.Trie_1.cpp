#include"leetcode.h"


#define CHARNUMS 26
#define MAXCOUNT 30010
class Trie {
private:
    struct TrieNode{
        bool isHas;
        TrieNode* children[26];
        TrieNode(){
            isHas = false;
            for(int i = 0; i < CHARNUMS; i ++){
                children[i] = nullptr;
            }
        }
    };
    char* memoryptr;
    char* memoryptrindex;
    TrieNode* root;
    void _insert(TrieNode* node,string &word,int index){
        if(word.length() == index){
            node->isHas = true;
            return;
        }
        char charindex = word[index] - 'a';
        if(node->children[charindex] == nullptr){
            node->children[charindex] = new (memoryptrindex)TrieNode();
            memoryptrindex=memoryptrindex + sizeof(TrieNode);
        }
        _insert(node->children[charindex],word,index+1);
    }

    bool _search(TrieNode* node,string &word,int index){
        if(node == nullptr){return false;}
        if(word.length() == index){
            return node->isHas;            
        }
        char charindex = word[index] - 'a';
        return _search(node->children[charindex],word,index+1);
    }

    bool _startsWith(TrieNode* node,string &prefix,int index){
        if(node == nullptr){return false;}
        if(prefix.length() == index){
            return true;
        }
        char charindex = prefix[index] - 'a';
        return _startsWith(node->children[charindex],prefix,index+1);
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        memoryptr = (char*)malloc(MAXCOUNT * sizeof(TrieNode));
        memoryptrindex = memoryptr;
        root = new (memoryptrindex)TrieNode();
        memoryptrindex=memoryptrindex + sizeof(TrieNode);
    }
    ~Trie(){
        free(memoryptr);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        _insert(root,word,0);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return _search(root,word,0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return _startsWith(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// int main(){
//     Trie trietree;
//     trietree.insert("apple");
//     trietree.insert("banana");

//     return 0;
// }