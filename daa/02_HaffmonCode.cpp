#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// Node structure for the Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to calculate the frequency of each character
unordered_map<char, int> calculateFrequency(const string& s) {
    unordered_map<char, int> frequency;
    for (char c : s) {
        frequency[c]++;
    }
    return frequency;
}

// Recursively traverse the Huffman tree to assign binary codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If this is a leaf node, assign the code to the character
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman Tree and return the codes
unordered_map<char, string> huffmanEncode(const unordered_map<char, int>& frequency) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create a leaf node for each character and add it to the min-heap
    for (auto& pair : frequency) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman Tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        // Create a new internal node with the combined frequency
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    // Generate Huffman codes by traversing the tree
    unordered_map<char, string> huffmanCodes;
    generateCodes(minHeap.top(), "", huffmanCodes);

    return huffmanCodes;
}

int main() {
    string s;
    cout << "Enter the string or words to generate their Huffman encoding: ";
    getline(cin, s);

    unordered_map<char, int> frequency = calculateFrequency(s);
    unordered_map<char, string> huffmanCodes = huffmanEncode(frequency);

    cout << "Frequency of the characters in the given string:\n";
    for (const auto& pair : frequency) {
        cout << pair.first << " : " << pair.second << endl;
    }

    cout << "\nChar | Huffman Code\n";
    cout << "---------------------\n";
    for (const auto& pair : huffmanCodes) {
        cout << "  " << pair.first << "  | " << pair.second << endl;
    }

    return 0;
}
