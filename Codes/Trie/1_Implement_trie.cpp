#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    Node* links[26];
    bool flag = false;

    //checks if the reference trie is present or not
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    //creating reference trie
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    //to get the next node for traversal
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    //setting flag to true at the end of the word
    void setEnd() {
        flag = true;
    }

    //checking if the word is completed or not
    bool isEnd() {
        return flag;
    }
};



class Trie {
private:
    Node* root;

public:

    // Initialize your data structure here
    Trie() {
        //creating new obejct
        root = new Node();
    }

    // Inserts a word into the trie
    // TC :- O(length of the word)
    void insert(string word) {
        //initializing dummy node pointing to root initially
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            // moves to the reference trie
            node = node->get(word[i]);
        }

        node->setEnd();
    }


    // Returns if the word is in the trie
    // TC :- O(length of the word)
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }


    // Returns if there is any word in the trie that starts with the given prefix
    // TC :- O(length of the word)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++) {
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};


int main() {

    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;
    for(int i=0; i<n; i++) {
        if(type[i] == 1) {
            trie.insert(value[i]);
        }else if(type[i] == 2) {
            if(trie.search(value[i])) {
                cout << "true" << endl;
            }else {
                cout << "false" << endl;
            }
        }else {
            if(trie.startsWith(value[i])) {
                cout << "true" << endl;
            }else {
                cout << "false" << endl;
            }
        }
    }
    

    return 0;
}