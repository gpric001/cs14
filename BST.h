#include <iostream>
#include <vector>

typedef unsigned int uint;

struct Node {
    uint data; 
    Node* left;
    Node* right;
};

int max(int, int);
void insert(Node*, const uint);
bool search(Node*, const uint);
Node* searchHelper(Node*, Node**, const uint);
int largest(Node*);
Node* largestHelper(Node*);
int smallest(Node*);
Node* smallestHelper(Node*);
int height(Node*, const uint);
int heightHelper(Node*);
int children(Node*);
bool isLeaf(Node*);
void remove(Node*, const uint);
void preOrder(Node*);
void inOrder(Node*);
void postOrder(Node*);
Node* initNode(const uint);
Node* initTree(std::vector<uint>);
void freeTree(Node*);
