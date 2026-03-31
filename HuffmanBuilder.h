#ifndef HUFFMAN_BUILDER_H
#define HUFFMAN_BUILDER_H

#include "HuffmanCommon.h"
#include <map>
#include <string>

std::map<char, int> countFrequencies(const std::string& filename);

Node* buildHuffmanTree(const std::map<char, int>& freqMap);

void generateCodes(Node* root, std::string currentCode, std::map<char, std::string>& codes);

#endif
