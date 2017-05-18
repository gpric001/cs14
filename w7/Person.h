#ifndef __PERSON_H
#define __PERSON_H

#include <string>

struct Person {
    Person(std::string name, double height, double weight)
        : name(name), height(height), weight(weight)
        {};
    std::string name;
    int height; // Height in inches
    int weight; // Weight in pounds
};

#endif
