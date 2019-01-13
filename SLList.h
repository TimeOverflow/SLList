//
// Created by zhang on 2018/12/4.
//

#ifndef ANOTHER_SL_LIST
#define ANOTHER_SL_LIST
#include<iostream>

template<typename T>class Node
{
public:
	Node()
	{
		next = nullptr;
	}
	explicit Node(T el, Node<T>* p = nullptr)
	{
		info = el;
		next = p;
	}
/*
	~Node()
	{
		delete next;
	}
*/
public:
	T info;
	Node<T>* next;
};

template<typename T>class SLList
{
public:
	SLList()
	{
		head = nullptr;
		tail = nullptr;
		length = 0;
	}
	SLList(int n, T el)
    {
	    head = nullptr;
	    tail = nullptr;
	    length = 0;
	    for (int i = 0; i < n; i++)
	        addToTail(el);
    }
    /*
     * shallow copy, not work
    SLList(const SLList& s)
	{
		head = new Node<T> (*s.head);
		tail = new Node<T> (*s.tail);
		length = s.length;
	}
     */
    //must be deep copy, just like create a new list
    SLList(const SLList& s)
    {
        //initialization is necessary
        head = nullptr;
        tail = nullptr;
        length = 0;

        Node<T>* p = s.head;
        for (int i = 0; i < s.length; ++i)
        {
            addToTail(p->info);
            p = p->next;
        }
    }

	~SLList();
    SLList<T>& operator=(const SLList& s);
	int getLength()
	{
		return this->length;
	}
	bool isEmpty() const
	{
		return length == 0;
	}
	void addToHead(T el);
	void addToTail(T el);
	void insert(T el, int index);
	T deleteFromHead();
	T deleteFromTail();
	void deleteNode(T el);
	void deleteIth(int i);
	void reverse();
	void printAll();

	template <typename fuck>
	friend SLList<fuck> mergeTwoSortedList(SLList<fuck>& l1, SLList<fuck>& l2);

private:
	Node<T>* head;
	Node<T>* tail;
	int length;
};



#endif // !ANOTHER_SL_LIST

