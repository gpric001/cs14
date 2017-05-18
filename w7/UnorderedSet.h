#ifndef __UNORDEREDSET_H
#define __UNORDEREDSET_H

#include "Person.h"
#include <list>
#include <vector>

class UnorderedSet {
public:
    // Construct an empty unordered set
    UnorderedSet();

    // Construct an ordered set where we know how many values are given
    UnorderedSet(std::vector<Person>& persons);

    // Free the memory used by the unordered set
    ~UnorderedSet();

    // Count the number of persons in the unordered set that map to the given
    // person parameter
    int count(const Person& person);

    // Remove the given person from the unordered set
    void remove(const Person& person);

    // Insert an person into the unordered set
    void insert(const Person& person);

private:
    // The total number of buckets for your set
    // (Note: This is similar to the capacity of a vector)
    int buckets;

    // The load factor for the unordered set
    double loadFactor;

    // The internal data structure for the unordered set
    std::list<Person>* set; 
    
    // This will resize the internal data structure if necessary
    void resize();

    // This hashes an person
    int hashFunction(const Person& person);
};
#endif
