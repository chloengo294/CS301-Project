#include "HuffmanBuilder.h"
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>

// Chloe's functions
std::string encodeText(const std::string& text, std::map<char, std::string>& codes);
std::string decodeText(const std::string& binary, Node* root);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./huffman_tool <filename.txt>" << std::endl;
        return 1;
    }

    try {
        std::string filename = argv[1];

        // Step 1: Count frequencies
        std::map<char, int> freqs = countFrequencies(filename);

        // Step 2: Build tree
        Node* root = buildHuffmanTree(freqs);

        // Step 3: Generate codes
        std::map<char, std::string> codes;
        generateCodes(root, "", codes);

        std::cout << "\nHuffman Codes:\n";
        for (auto& p : codes) {
            std::cout << p.first << ": " << p.second << std::endl;
        }

        // Step 4: Read full file
        std::ifstream input(filename, std::ios::binary);
        if (!input.is_open()) {
            throw std::runtime_error("Could not open file for reading text.");
        }

        std::string text((std::istreambuf_iterator<char>(input)),
            std::istreambuf_iterator<char>());

        // Step 5: Encode
        std::string encoded = encodeText(text, codes);
        std::cout << "\nEncoded:\n" << encoded << std::endl;

        // Step 6: Decode (test)
        std::string decoded = decodeText(encoded, root);
        std::cout << "\nDecoded:\n" << decoded << std::endl;

        delete root; // clean memory
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// ==========================
// Chloe's Encoding Function
// ==========================
std::string encodeText(const std::string& text, std::map<char, std::string>& codes) {
    std::string result = "";
    for (char c : text) {
        result += codes[c];
    }
    return result;
}

// ==========================
// Chloe's Decoding Function
// ==========================
std::string decodeText(const std::string& binary, Node* root) {
    std::string result = "";

    if (!root) return result;

    // Edge case: only one unique character
    if (!root->left && !root->right) {
        return std::string(binary.size(), root->ch);
    }

    Node* current = root;

    for (char bit : binary) {
        if (bit == '0') current = current->left;
        else current = current->right;

        if (!current->left && !current->right) {
            result += current->ch;
            current = root;
        }
    }

    return result;
}
