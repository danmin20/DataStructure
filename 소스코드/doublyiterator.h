#pragma once
#ifndef DOUBLYITERATOR_H
#define DOUBLYITERATOR_H

#include "DoublyLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublyLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class DoublyIterator
{
    friend class DoublyLinkedList<T>;
public:
    /**
    *	디폴트 생성자.
    */
    DoublyIterator(const DoublyLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst)
    {} ///< DoublySortedLinkedList와 친구 클래스.


    bool NotNull();
    bool NextNotNull();
    T First();
    T Next();
    DoublyNodeType<T> GetCurrentNode();
private:
    const DoublyLinkedList<T> &m_List;
    DoublyNodeType<T>* m_pCurPointer;
};

template <typename T>
bool DoublyIterator<T> ::NotNull()
{
    if (m_pCurPointer == NULL)
        return false;
    else
        return true;
}

template <typename T>
bool DoublyIterator<T> ::NextNotNull()
{
    if (m_pCurPointer->next == NULL)
        return false;
    else
        return true;
}

template <typename T>
T DoublyIterator<T> ::First()
{
    return m_List.m_pFirst->data;
}

template <typename T>
T DoublyIterator<T> ::Next()
{
    m_pCurPointer = m_pCurPointer->next;
    return m_pCurPointer->data;
}

template <typename T>
DoublyNodeType<T> DoublyIterator<T> ::GetCurrentNode()
{
    return *m_pCurPointer;
}

#endif
