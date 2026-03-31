#include "HuffmanBuilder.h"
#include <fstream>
#include <queue>
#include <vector>
#include <stdexcept>

// ==========================
// Count Frequencies
// ==========================
std::map<char, int> countFrequencies(const std::string& filename) {
    std::map<char, int> freqMap;
    std::ifstream inputFile(filename, std::ios::binary);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Could not open the source file: " + filename);
    }

    char ch;
    while (inputFile.get(ch)) {
        freqMap[ch]++;
    }

    inputFile.close();
    return freqMap;
}

// ==========================
// Build Huffman Tree
// ==========================
Node* buildHuffmanTree(const std::map<char, int>& freqMap) {
    if (freqMap.empty()) return nullptr;

    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;

    for (auto const& [character, frequency] : freqMap) {
        pq.push(new Node(character, frequency));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int combinedFreq = left->freq + right->freq;
        Node* parent = new Node(combinedFreq, left, right);

        pq.push(parent);
    }

    return pq.top();
}

// ==========================
// ==========================
void generateCodes(Node* root, std::string currentCode, std::map<char, std::string>& codes) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        // Edge case: only one unique character
        codes[root->ch] = (currentCode == "") ? "0" : currentCode;
        return;
    }

    generateCodes(root->left, currentCode + "0", codes);
    generateCodes(root->right, currentCode + "1", codes);
}
