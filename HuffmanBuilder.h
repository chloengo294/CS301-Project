#ifndef HUFFMAN_BUILDER_H
#define HUFFMAN_BUILDER_H

#include "HuffmanCommon.h"
#include <map>
#include <string>

/**
 * Reads a text file and counts the frequency of each character.
 * @param filename The path to the input .txt file.
 * @return A map where keys are characters and values are their counts.
 */
std::map<char, int> countFrequencies(const std::string& filename);

/**
 * Builds the Huffman Tree using a priority queue.
 * @param freqMap The map containing character frequencies.
 * @return The root node of the constructed Huffman Tree.
 */
Node* buildHuffmanTree(const std::map<char, int>& freqMap);

#endif