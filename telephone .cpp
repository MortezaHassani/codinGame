// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

const int NUMBERS_SIZE = 10;

// trie node
struct TrieNode
{
    struct TrieNode *children[NUMBERS_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < NUMBERS_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
int insert(struct TrieNode *root, string key,int& nodecount)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - '0';
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
        nodecount++;}
        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    return nodecount;
}


int main()
{

	int n;
	cin>>n;cin.ignore();
	string keys[n];
	for (int i=0 ; i< n; i++){
		cin>>keys[i];cin.ignore();
	}
   //--------------------------------

    struct TrieNode *root = getNode();

    // Construct trie
    int NCounter=0;
    for (int i = 0; i < n; i++)
        NCounter=insert(root, keys[i],NCounter);
    cout<<NCounter<<endl;

}

