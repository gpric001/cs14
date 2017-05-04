#include <fstream>
#include "HuffmanTree.h"

//-----------------------------------------------------------------------------
// This function should take an argument string and huffman tree and decode
// the string according to the huffman tree given.

std::string decode(const std::string& s, HuffmanTree& ht) {
    std::string result = "";
    //Put your implementation here
    return result;
}

//-----------------------------------------------------------------------------
// The below function should output the bit mapping for each symbol of the
// huffman tree. To see an example of what this should look like try outputting
// the huffman tree through cout. 

std::string outputTree(const HuffmanTree&) {
    std::string result = "";
    //Put your implementation here
    return result;
}

//-----------------------------------------------------------------------------
// Below is a utility function to help you write the outputTree function above.

void outputTreeHelper(const HuffmanNode*, std::string&) {
    //Put your implementation here
    return;
}

//-----------------------------------------------------------------------------
// Below are both functions written for you to help test your code, see the
// details below

void readDataFile(const std::string&, std::vector<char>&, std::vector<uint>&);
void readDecodeFile(const std::string&, std::string&);


int main(){
    // Basic example 
    std::string input;
    std::vector<char> alphabet;
    std::vector<uint> frequencies;
    readDataFile("sometext.txt", alphabet, frequencies);
    HuffmanTree ht(alphabet, frequencies);
    std::cout << ht << std::endl;
    return 0;
}


//-----------------------------------------------------------------------------
// Reads a text file and generates the alphabet and frequencies for each
// character of that file. Stores them in alphabet and frequencies.
void readDataFile(const std::string& path,
                  std::vector<char>& alphabet,
                  std::vector<uint>& frequencies) {
    if (alphabet.size() > 0 || frequencies.size() > 0) 
        throw std::length_error("Excepted empty alphabet and frequency vectors");
    std::ifstream file;
    char c;
    const uint asciiSize = 256;
    uint freqs[asciiSize] = {0};
    file.open(path);
    if (!file.is_open()) 
        throw std::invalid_argument("Path to file was not found");
    while (file >> c)
        freqs[c] += 1; 
    for (int i = 1; i < asciiSize; ++i) {
        if (freqs[i] != 0) {
            alphabet.push_back(static_cast<char>(i));
            frequencies.push_back(freqs[i]);
        }
    }
}

//-----------------------------------------------------------------------------
// Reads in a file of ones and zeros and places them into outputString 
void readDecodeFile(const std::string& path, std::string& outputString) {
    std::ifstream file;
    char c;
    file.open(path);
    if (!file.is_open())
        throw std::invalid_argument("Path to file was not found");
    while (file >> c) {
        if (c != '0' || c != '1')
            throw std::invalid_argument("Decode file has unreadable characters");
        outputString.push_back(c);
    }
}
