#include "HuffmanBuilder.h"
#include <fstream>
#include <queue>
#include <vector>

std::map<char, int> countFrequencies(const std::string& filename) {
    std::map<char, int> freqMap;
    std::ifstream inputFile(filename, std::ios::binary);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Could not open the source file: " + filename);
    }

    char ch;
    // Read the file byte by byte to ensure all characters (including whitespace) are counted
    while (inputFile.get(ch)) {
        freqMap[ch]++;
    }

    inputFile.close();
    return freqMap;
}

Node* buildHuffmanTree(const std::map<char, int>& freqMap) {
    if (freqMap.empty()) return nullptr;

    // Use a Min-Priority Queue to store tree nodes
    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto const& [character, frequency] : freqMap) {
        pq.push(new Node(character, frequency));
    }

    // Combine nodes until only the root remains
    while (pq.size() > 1) {
        // Remove the two nodes with the lowest frequencies
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children.
        // The frequency of this new node is the sum of the children's frequencies.
        int combinedFreq = left->freq + right->freq;
        Node* parent = new Node(combinedFreq, left, right);

        pq.push(parent);
    }

    // The remaining node is the root of the Huffman Tree
    return pq.top();
}