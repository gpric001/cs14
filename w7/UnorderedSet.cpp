#include "UnorderedSet.h"

UnorderedSet::UnorderedSet() {
    // How are you going to create the set if there is no input?
    // There is no right answer here, it is a design choice.
    return;
}

UnorderedSet::UnorderedSet(std::vector<Person>& persons) {
    // How are you going to create the set if you know upfront the size of
    // your initial input?
    return;
}

UnorderedSet::~UnorderedSet() {
    // The following implementation makes the assumption that if the set is
    // unallocated it is a nullptr.
    // Please ensure that this implementation works with your code.
    delete[] set;
}

int UnorderedSet::count(const Person& person) {
    // Returns the number of values in the bucket that the hashed value
    // of the given person maps to.
    return 0;
}

void UnorderedSet::remove(const Person& person) {
    // Removes the given person from the set
    return;
}

void UnorderedSet::insert(const Person& person) {
    // Inserts the given person into the set
    return;
}

void UnorderedSet::resize() {
    // Resizes the number of buckets the set holds.
    // This isn't needed until Exercise 3.
    return;
}

int hashFunction(const Person& person) {
    // Hashes the given person to an integer value in the range
    // [0, buckets).
    return 0;
}

