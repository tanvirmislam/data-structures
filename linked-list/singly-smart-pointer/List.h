#ifndef __LIST_H_
#define __LIST_H_

#include "Node.h"
#include <functional>

template <class T>
struct List
{
private:
    std::unique_ptr<Node<T>> headNode;
    Node<T>* tailNodePtr;

    void forEach(std::function<void (const T&)> func, std::unique_ptr<Node<T>>& currentNode)
    {
        if (currentNode->nextNode == nullptr)
            func(currentNode->data);
        else
        {
            func(currentNode->data);
            forEach(func, currentNode->nextNode);
        }
    }

public:
    List() : headNode(), tailNodePtr() {}
    ~List() { std::cout << "\nDeleting List\n" << std::endl; }


    void add_front(const T& d)
    {
        if (headNode == nullptr)
        {
            headNode.reset(new Node<T>(d));
            tailNodePtr = headNode.get();
        }
        else
        {
            std::unique_ptr<Node<T>> newNode (new Node<T>(d));
            newNode->setNextNode(std::move(headNode));
            headNode = std::move(newNode);
        }

    }
    
    void add_front(T&& d)
    {
        if (headNode == nullptr)
        {
            headNode.reset(new Node<T>(std::move(d)));
            tailNodePtr = headNode.get();
        }
        else
        {
            std::unique_ptr<Node<T>> newNode (new Node<T>(std::move(d)));
            newNode->setNextNode(std::move(headNode));
            headNode = std::move(newNode);
        }
    }
    

    void add_back(const T& d)
    {
        if (headNode == nullptr)
        {
            headNode.reset(new Node<T>(d));
            tailNodePtr = headNode.get();
        }
        else
        {
            std::unique_ptr<Node<T>> newNode (new Node<T>(d));
            tailNodePtr->setNextNode(std::move(newNode));
            tailNodePtr = (tailNodePtr->nextNode).get();
        }
    }
    
    void add_back(T&& d)
    {
        if (headNode == nullptr)
        {
            headNode.reset(new Node<T>(std::move(d)));
            tailNodePtr = headNode.get();
        }
        else
        {
            std::unique_ptr<Node<T>> newNode (new Node<T>(std::move(d)));
            tailNodePtr->setNextNode(std::move(newNode));
            tailNodePtr = (tailNodePtr->nextNode).get();
        }
    }

    void forEach(std::function<void (const T&)> func)
    {
        if (headNode != nullptr)
            forEach(func, headNode);
    }

};


#endif
