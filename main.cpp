#include "HuffmanBuilder.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./huffman_tool <filename.txt>" << std::endl;
        return 1;
    }

    try {
        std::string filename = argv[1];

        // Step 1: Count frequencies
        std::map<char, int> freqs = countFrequencies(filename);
        std::cout << "Character frequencies calculated successfully." << std::endl;

        // Step 2: Build the tree
        Node* root = buildHuffmanTree(freqs);
        if (root) {
            std::cout << "Huffman Tree built successfully. Root frequency: " << root->freq << std::endl;
        }

        // Clean up memory (optional here, but good practice)
        // delete root; 

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}