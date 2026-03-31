#ifndef HUFFMAN_COMMON_H
#define HUFFMAN_COMMON_H

#include <iostream>

/**
 * Node structure for the Huffman Tree.
 */
struct Node {
    char ch;        // The character (only valid for leaf nodes)
    int freq;       // Frequency of the character
    Node* left;     // Left child (represents bit '0')
    Node* right;    // Right child (represents bit '1')

    // Constructor for a leaf node
    Node(char character, int frequency)
        : ch(character), freq(frequency), left(nullptr), right(nullptr) {
    }

    // Constructor for an internal node
    Node(int frequency, Node* l, Node* r)
        : ch('\0'), freq(frequency), left(l), right(r) {
    }

    // Destructor to recursively clean up the tree and prevent memory leaks
    ~Node() {
        delete left;
        delete right;
    }
};

/**
 * Comparator for the priority queue.
 * Returns true if the first node has a higher frequency than the second.
 * This ensures the priority queue acts as a "Min-Heap" (smallest frequency on top).
 */
struct CompareNodes {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

#endif
