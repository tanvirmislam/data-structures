#include <iostream>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

/*

Being able to use unordered_map for user defined class requires 2 things:
-> A comparison function inside the class
-> A hash function to derive the hash for an object of that class. 
The hash function can be written to std namespace, or a seperate class can be used to do that.

*/

class Student {
public:
	std::string name;
	int id;
	Student(std::string str, int n) : name(str), id(n) {}

	// Equality function
	bool operator== (const Student& anotherStudent) const {
		return (name == anotherStudent.name && id == anotherStudent.id);
	}
};


struct StudentHasher {

	std::size_t operator() (const Student& s) const {
		return (std::hash<std::string>()(s.name) ^ (std::hash<int>()(s.id) << 1));
	}
};


int main() {
	Student mith("Mithrandir", 1025);
	Student cap("Roger", 991);
	Student im("Tony", 7001);
	Student cas("Bond", 007);

	std::unordered_map<Student, std::string, StudentHasher> studentMap;
	studentMap.insert(std::make_pair(mith, "Gandalf"));
	studentMap.insert(std::make_pair(cap, "Captain America"));
	studentMap.insert(std::make_pair(im, "Iron Man"));
	studentMap.insert(std::make_pair(cas, "James Bond"));

	std::unordered_map<Student, std::string, StudentHasher>::const_iterator getStudent = studentMap.find(im);
	std::cout << "Got: " << getStudent->second << std::endl;

	for (auto& x : studentMap) {
    	std::cout << x.second << std::endl;
  	}

  	if (studentMap.find(mith) != studentMap.end()) {
		std::cout << "Found Mithrandir" << std::endl;
	}

	return 0;
}