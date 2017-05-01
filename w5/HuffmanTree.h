#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <utility>
#include <iostream>

typedef unsigned int uint;
typedef std::vector<std::pair<char, std::string> > SymbolMap;
class HuffmanTree;
// ----------------------------------------------------------------------------
// A node that stores the symbol and frequency of the symbol within
// an alphabet.
//
// MEMBER VARIBLES
// frequency: The frequency of the symbol held by the Huffman Node
// symbol: A symbol of the alphabet of a Huffman Tree
// left: The left child of this Huffman Node
// right: The right child of this Huffman Node
//
// MEMBER FUNCTIONS
// N/A
// ----------------------------------------------------------------------------
class HuffmanNode {
    private:
        uint frequency;
        char symbol;
        HuffmanNode* left;
        HuffmanNode* right;
        friend class HuffmanTree;
        friend class NodeSmaller;
        friend std::string decode(const std::string&, HuffmanTree&);
        friend std::string outputTree(const HuffmanTree&);
        friend void outputTreeHelper(const HuffmanNode*, std::string&); 
};

// ----------------------------------------------------------------------------
// A comparator for comparing Huffman Node types.
//
// MEMBER VARIBLES
// N/A
//
// MEMBER FUNCTIONS
// operator(): A node with a lower frequency is considered less than a node
//             with a higher frequency. If frequencies are equal, then the node
//             with the symbol appearing first in the alphabet is considered
//             less than.
// ----------------------------------------------------------------------------
struct NodeSmaller {
    bool operator() (const HuffmanNode* node1, const HuffmanNode* node2) {
        if (node1->frequency == node2->frequency)
            return (node1->symbol < node2->symbol);
        return (node1->frequency < node2->frequency);
    }
};

// ----------------------------------------------------------------------------
// An implementation of a Huffman Tree for lossless compression of an alphabet.
//
// MEMBER VARIBLES
// root: A pointer to the root of this Huffman Tree.
// symbolMap: A vector of pairs that represent a one-to-one mapping between a
//            symbol in the alphabet and a bit encoding.
//
// MEMBER FUNCTIONS
// initNode(...): You can use this to create a new Huffman Node.
//
// takeMin(...): You can use this to get the Huffman Node with the smallest
//               frequency from two queues of Huffman Nodes.
//
// generateNode(...): You can use this to generate an internal node of the
//                    Huffman Tree.
//
// destructorHelper(...): Used be the destructor to recursively remove the
//                        tree.
//
// operator<<(...): You can use this to output the symbolMap member variable.
// ----------------------------------------------------------------------------
class HuffmanTree {
    public:
        HuffmanTree(const std::vector<char>&, const std::vector<uint>&);
        ~HuffmanTree();
    private:
        HuffmanNode* initNode(char, uint) const;
        HuffmanNode* takeMin(std::queue<HuffmanNode*>&,
                             std::queue<HuffmanNode*>&) const;
        HuffmanNode* generateNode(HuffmanNode*, 
                                  HuffmanNode*) const;
        void generateSymbolMap(const HuffmanNode*, std::string&);
        void destructorHelper(HuffmanNode*);
        friend std::ostream& operator<<(std::ostream&, const HuffmanTree&);
        friend std::string decode(const std::string&, HuffmanTree&);
        friend std::string outputTree(const HuffmanTree&);
        friend void outputTreeHelper(const HuffmanNode*, std::string&);
        SymbolMap symbolMap;
        HuffmanNode* root;
};
#endif
