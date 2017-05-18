#include "UnorderedSet.h"
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <sstream>

using namespace std;

// Given the filename for a file that contains person data,
// loads that data onto the end of a given vector.
void loadPersonData(string, vector<Person>&);
// Splits a string into a vector by spaces.
vector<string> split(string s);

// Right now all main does is load the person data.
int main() {
    vector<Person> persons;
    loadPersonData("persondata.txt", persons);
    // Do some stuff here
    return 0;
}

// You don't need to worry about the code below here
void loadPersonData(string filename, vector<Person>& persons) {
    ifstream inputFile;
    inputFile.open(filename);
    if (!inputFile.is_open())
        throw invalid_argument("Error loading file"); 
    string personData;
    while (getline(inputFile, personData)) {
        vector<string> data = split(personData);
        Person p(data.at(0), stoi(data.at(1)), stoi(data.at(2)));
        persons.push_back(p);
    }
}

vector<string> split(string s) {
    vector<string> results;
    stringstream ss;
    ss.str(s);
    string item;
    while(getline(ss, item, ' ')) {
        results.push_back(item);
    }
    return results;
}
