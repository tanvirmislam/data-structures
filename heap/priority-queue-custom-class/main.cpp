#include <queue>
#include <iostream>
#include <string.h>

using namespace std;

class Person {
public:
	char *name;
	int age;

    Person(int a) : name(nullptr), age(a) {}
    Person(char* n, int a) : name(n), age(a) {}
    Person(const char* n, int a) {
    	name = new char[strlen(n)];
		strcpy(name, n);
		age = a;
    }
};


bool operator<(const Person& a, const Person& b) {
    return a.age < b.age;
}

class Compare {
public:
	bool operator()(const Person& a, const Person& b) {
    	return a.age < b.age;
	}
};

int main() {
	/*
	Person p1(strdup("Rogers"), 1);
    Person p2(strdup("Tony"), 4);
    Person p3(strdup("Mithrandir"), 90);
    Person p4(strdup("Peter"), 16);
	*/
	Person p1("Rogers", 1);
    Person p2("Tony", 4);
    Person p3("Mithrandir", 90);
    Person p4("Peter", 16);
	
    priority_queue<Person, std::vector<Person>, Compare> pq;
   	pq.push(p1);
   	pq.push(p2);
   	pq.push(p3);
   	pq.push(p4);

    while (!pq.empty()) {
        Person p = pq.top();
        pq.pop();
        cout << p.age << " ";
    }
    cout << endl;
    
    // if (p1 < p2) {
    //     cout << "p1 < p2" << endl;
    // }

    return 0;
}