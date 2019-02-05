#ifndef __HASMAP_CHAIN__
#define __HASMAP_CHAIN__

#include <iostream>

#define BUCKETS 16

template <typename K, typename V>
class HashNode {
private:
	K key;
	V value;
	HashNode<K, V>* next;

public:
	HashNode(const K& _key, const V& _value) : key(_key), value(_value), next(nullptr) {}

	K getKey() 				{ return key; }
	V getValue() 			{ return value; }
	HashNode* getNext() 	{ return next; }

	void setValue(V _value) 			{ value = _value; }
	void setNext(HashNode<K, V>* _next) { next = _next; }
};

template <typename K, typename V>
class HashMap {
private:
	HashNode<K, V>** nodeArray;			// Array of pointers to nodes
	
	// Return an index for a key
	unsigned long hashCode(K key) {
		return static_cast<unsigned long>(key) % BUCKETS;
	}

public:
	HashMap() {
		// Initialize
		nodeArray	= new HashNode<K, V>*[BUCKETS];

		for (unsigned long i = 0; i < BUCKETS; i++) {
			nodeArray[i] = nullptr;
		}
	}

	~HashMap() {
		for (unsigned long i = 0; i < BUCKETS; i++) {
			if (nodeArray[i] != nullptr) {
				HashNode<K, V>* entry = nodeArray[i];
		    	while (entry != nullptr) {
		    		HashNode<K, V>* prev = entry;
		    		entry = entry->getNext();
		    		delete prev;
		    	}
		    	nodeArray[i] = nullptr;
		    }
		}

		delete[] nodeArray;
	}

	void insert(K key, V value) {
		// Create a new hashnode
		HashNode<K, V>* newNode = new HashNode<K,V>(key, value);

		// Get the index for the node with the given key usign hashCode() function
		unsigned long hashIndex = hashCode(key);

		HashNode<K, V>* prev    = nullptr;
		HashNode<K, V>* current = nodeArray[hashIndex];

		// ** CHAINING **
		// Get hashIndex, then keep chaining, like a linked list
		// No duplicates
		while (current != nullptr && current->getKey() != key) {
			prev    = current;
			current = current->getNext();
		}

		// New key
		if (current == nullptr) {
			current = new HashNode<K, V>(key, value);

			if (prev == nullptr) {
				// New entry to the hashIndex
				nodeArray[hashIndex] = current;
			} 
			else {
				// Chain
				prev->setNext(current);
			}
		} 
		else {	
			// Key exists, update value
			current->setValue(value);
		}
	}

	V remove(K key) {
		V removedVal;

		unsigned long hashIndex = hashCode(key);
		HashNode<K, V> *prev    = nullptr;
        HashNode<K, V> *current = nodeArray[hashIndex];

		while (current != nullptr && current->getKey() != key) {
			prev    = current;
			current = current->getNext();
		}

		if (current != nullptr) {
            // key found
            removedVal = current->getValue();

			if (prev == nullptr) {
				// remove first bucket of the list
				// but check if there are elements after it
				if (current->getNext() != nullptr) {
					nodeArray[hashIndex] = current->getNext();
				}
				else {
					nodeArray[hashIndex] = nullptr;
				}
			} 
			else {
				prev->setNext(nullptr);
			}

            delete current;
        }
		
		// return val
		return removedVal;
	}

	V get(K key) {
		V val;

		unsigned long hashIndex = hashCode(key);
		HashNode<K, V>* entry   = nodeArray[hashIndex];

		while (entry != nullptr) {
			if (entry->getKey() == key) {
				// found
				val = entry->getValue();
			}
			entry = entry->getNext();
		}

		return val;
	}

	void display() const {
		for(unsigned long i = 0 ; i < BUCKETS; i++) {
			if (nodeArray[i] != nullptr) {
				HashNode<K, V>* entry = nodeArray[i];
		    	while (entry != nullptr) { 
	    			std::cout << " <" << entry->getKey() << ", " << entry->getValue() << ">  -> ";
	    			entry = entry->getNext();
	        	}
		    	std::cout << " x" << std::endl;	
	        	
	        	entry = nullptr;
	        	delete entry;
			}
        }
	}

	std::string toString() const {
		std::string str = "";
		
		for(unsigned long i = 0 ; i < BUCKETS; i++) {
			if (nodeArray[i] != nullptr) {
				HashNode<K, V>* entry = nodeArray[i];
		    	while (entry != nullptr) { 
	    			str += " <" + std::to_string(entry->getKey()) + ", " + std::to_string(entry->getValue()) + ">  -> ";
	    			entry = entry->getNext();
	        	}
		    	str += " x\n";	
	        	
	        	entry = nullptr;
	        	delete entry;
			}
        }

        return str;
	}

};

#endif