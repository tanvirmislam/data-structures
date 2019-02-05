#ifndef __HASMAP_LP__
#define __HASMAP_LP__

#include <iostream>

#define CAPACITY 16

template <typename K, typename V>
class HashNode {
private:
	K key;
	V value;

public:
	HashNode(const K& _key, const V& _value) : key(_key), value(_value) {}

	K getKey() { return key; }
	V getValue() { return value; }
};

template <typename K, typename V>
class HashMap {
private:
	HashNode<K, V>** nodeArray;			// Array of pointers to nodes
	unsigned long size;					// Current Size

	// Return an index for a key
	unsigned long hashCode(K key) {
		return static_cast<unsigned long>(key) % CAPACITY;
	}

public:
	HashMap() {
		// Initialize
		size 		= 0;
		nodeArray	= new HashNode<K, V>*[CAPACITY];

		for (unsigned long i = 0; i < CAPACITY; i++) {
			nodeArray[i] = nullptr;
		}
	}

	~HashMap() {
		if (size != 0) {
			for(unsigned long i = 0 ; i < CAPACITY; i++) { 
	            if(nodeArray[i] != nullptr) { 
	            	delete nodeArray[i];
	            	nodeArray[i] = nullptr; 
        		}
        	}
		}
		delete[] nodeArray;
	}

	void insert(K key, V value) {
		// Create a new hashnode
		HashNode<K, V>* newNode = new HashNode<K,V>(key, value);

		// Get the index for the node with the given key usign hashCode() function
		unsigned long hashIndex = hashCode(key);

		// ** LINEAR PROBING **
		// Find the "next" free space, starting from hashIndex
		// No duplicates
		unsigned int haveSearched = 0;
		while (nodeArray[hashIndex] != nullptr && nodeArray[hashIndex]->getKey() != key) {
			hashIndex++;
			hashIndex = hashIndex % CAPACITY;
			haveSearched++;

			if (haveSearched == CAPACITY) {
				std::cout << "insert error: maximum capacity reached" << std::endl;
				delete newNode;
				return;
			}
		}

		// Ready to insert
		nodeArray[hashIndex] = newNode;

		// Increase current size
		size++;
	}

	V remove(K key) {
		V removedVal;

		unsigned long hashIndex = hashCode(key);

		while (nodeArray[hashIndex] != nullptr) {
			// Found
			if (nodeArray[hashIndex]->getKey() == key) {
				removedVal = nodeArray[hashIndex]->getValue();
				delete nodeArray[hashIndex];
				nodeArray[hashIndex] = nullptr;
				size--;
				break;
			}

			// Keep looking
			hashIndex++;
			hashIndex = hashIndex % CAPACITY;
		}
		// Not found
		
		// return val
		return removedVal;
	}

	V get(K key) {
		V val;

		unsigned long hashIndex = hashCode(key);
		unsigned long haveSearched = 0;

		while (nodeArray[hashIndex] != nullptr) {
			if (haveSearched > CAPACITY) {
				break;
			}

			if(nodeArray[hashIndex]->getKey() == key) {
                val = nodeArray[hashIndex]->getValue(); 
				break;
			}

            hashIndex++; 
            hashIndex = hashIndex % CAPACITY;
            haveSearched++;
		}

		return val;
	}

	unsigned long getSize() const {
		return size;
	}

	bool isEmpty() const {
		return size == 0;
	}

	void display() const {
		if (size != 0) {
			for(unsigned long i = 0 ; i < CAPACITY; i++) { 
	            if(nodeArray[i] != nullptr) { 
	            	std::cout << "<" << nodeArray[i]->getKey() << ", " << nodeArray[i]->getValue() << ">" << std::endl; 
        		}
        	}
		}
	}

	std::string toString() const {
		std::string str = "";
		if (size != 0) {
			for(unsigned long i = 0 ; i < CAPACITY; i++) { 
	            if(nodeArray[i] != nullptr) { 
	            	str += " <" + std::to_string(nodeArray[i]->getKey()) + "," + std::to_string(nodeArray[i]->getValue()) + ">\n"; 
        		}
        	}
		}
		return str;
	}
};

#endif