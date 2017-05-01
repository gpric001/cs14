#include "HuffmanTree.h"

std::string decode(const std::string& s, HuffmanTree& ht) {
    std::string result = "";
    //YOUR CODE HERE
    return result;
}

std::string outputTree(const HuffmanTree&) {
    std::string result = "";
    //YOUR CODE HERE
    return result;
}

void outputTreeHelper(const HuffmanNode*, std::string&) {
    //YOUR CODE HERE
    return;
}

int main(){
    std::vector<char> v;
    std::vector<uint> f;
    v.push_back('h'); f.push_back(20);
    v.push_back('i'); f.push_back(6);
    v.push_back('t'); f.push_back(7);
    v.push_back('h'); f.push_back(12);
    v.push_back('e'); f.push_back(30);
    v.push_back('r'); f.push_back(4);
    HuffmanTree ht(v, f);
    return 0;
}
