//
// Created by zhang on 2018/12/4.
//
#include<iostream>
#include<string>
#include"SLList.h"
using namespace std;

template<typename T>
SLList<T>::~SLList()
{
    //delete until only one node left, so that head->next won't ne nullptr
    for (Node<T>* p;  head != tail ;)
    {
        p = head->next;             //problems here, but solved
        //delete[] reinterpret_cast<char*>(head);
        delete head;
        head = p;
    }
    //now only one node left
    delete head;
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
SLList<T>& SLList<T>::operator=(const SLList &s)
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
    return *this;
}

template<typename T>
void SLList<T>::addToHead(T el)
{
    insert(el, 0);
}

template<typename T>
void SLList<T>::addToTail(T el)
{
    insert(el, length);
}

template<typename T>
void SLList<T>::insert(T el, int index)
{
    if (index < 0)
    {
        std::cout << "index must be positive!" << endl;
        return;
    }
    else if (index == 0)            //add to head
    {
        head = new Node<T>(el, head);
        if (tail == nullptr)           //empty list
            tail = head;
        length++;
        return;
    }
    else
    {
        if (index == length)        //add to tail
        {
            if (tail != nullptr)
            {
                tail->next = new Node<T>(el);
                tail = tail->next;
            }
            else                 //empty list
            {
                tail = new Node<T>(el);
                head = tail;
            }
            length++;
            return;
        }

        if (index < length)
        {
            int i = 0;
            Node<T>* p = head;
            for (; i != index-1; i++, p = p->next);
            p->next = new Node<T>(el, p->next);
            length++;
            return;
        }
        else
        {
            std::cout << "the index you want to insert is beyond the length." << endl;
            return;
        }
    }
}

template<typename T>
T SLList<T>::deleteFromHead()
{
    if (head ==nullptr && tail == nullptr)
    {
        cout << "No node can be deleted!" << endl;
        return 0;
    }
    else
    {
        T el = head->info;
        Node<T>* p = head;
        if (head == tail)
            head = tail = nullptr;
        else head = head->next;
        delete p;
        length--;
        return el;
    }
}

template<typename T>
T SLList<T>::deleteFromTail()
{
    if (head == nullptr && tail == nullptr)
    {
        cout << "No node can be deleted!" << endl;
        return 0;
    }
    else
    {
        T el = tail->info;
        if (head == tail)                  //only one node
        {
            delete head;
            head = tail = nullptr;
            length--;
            return el;
        }
        else                                      //more than one node
        {
            Node<T>* p = head;
            for (; p->next != tail; p = p->next);       //p finally points to the last but one node
            delete tail;
            tail = p;
            tail->next = nullptr;

            length--;
            return el;
        }
    }
}

/*
 * delete all the node whose info is el
 */
template<typename T>
void SLList<T>::deleteNode(T el)
{
    if ( isEmpty() )
    {
        cout << "No node can be deleted!" << endl;
        return;
    }
    else
    {
        if (head == tail)      //only one node
        {
            if (el == head->info)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                length--;
                return;
            }
            else
                return;
        }
        else
        {
            Node<T>* prev = nullptr;
            Node<T>* curr = head;
            while (curr)
            {
                if (curr->info == el)
                {
                    if (prev)
                        prev->next = curr->next;
                    Node<T> *p = curr;
                    curr = curr->next;

                    if (prev == nullptr)
                        head = curr;
                    else if (prev->next == nullptr)
                        tail = prev;
                    delete p;
                    length--;
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            return;
        }
    }
}

template <typename T>
void SLList<T>::deleteIth(int i)
{
    if (i < 0 || i >= length)           //include empty list
    {
        cout << "Index Error." << endl;
        return;
    }
    if (!isEmpty())
    {
        Node<T> *prev = nullptr;
        Node<T> *curr = head;
        for (int j = 0; j < i; j++)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev)
        {
            prev->next = curr->next;
        }
        if (i == length - 1)       //delete the tail node
            tail = prev;           //if only one node,tail = prev makes tail = nullptr
        if (i == 0)                //delete the head node
            head = head->next;     // if only one node, head = nullptr
        delete curr;
        length--;
    }
}

template<typename T>
void SLList<T>::reverse()
{
    if (head == nullptr)
        return;
    else
    {
        Node<T>* prev = head;
        Node<T>* curr = head->next;
        Node<T>* tmp;
        while (curr != nullptr)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        tail = head;
        head = prev;
        tail->next = nullptr;
        return;
    }
}

template<typename T>
void SLList<T>::printAll()
{
    if ( isEmpty() )
    {
        cout << "Empty list." << endl;
        cout << "length: " << getLength() << endl;
        return;
    }
    else
    {
        Node<T>* p = head;
        int n = length;
        for (; n-- > 0; p = p->next)
            cout << p->info << '\t';
        cout << endl;
        cout << "length: " << getLength() << endl;
        return;
    }
}


template <typename fuck>
SLList<fuck> mergeTwoSortedList(SLList<fuck>& l1, SLList<fuck>& l2)
{
    if ( (!l1.isEmpty()) && (!l2.isEmpty()) )
    {
        static SLList<fuck> L;
        Node<fuck>* pl1 = l1.head;
        Node<fuck>* pl2 = l2.head;
        while (pl1 || pl2)
        {
            if ( pl1 != nullptr && ( (pl2 == nullptr) || (pl1->info <= pl2->info) ) )
            {
                L.addToTail(pl1->info);
                pl1 = pl1->next;
            }
            if ( pl2 != nullptr && ( (pl1 == nullptr) || (pl2->info < pl1->info) ) )
            {
                L.addToTail(pl2->info);
                pl2 = pl2->next;
            }
        }
        //L.printAll();
        return L;
    }
    else if (l1.isEmpty())
    {
        //l2.printAll();
        return l2;
    }
    else
    {
        //l1.printAll();
        return l1;
    }
}