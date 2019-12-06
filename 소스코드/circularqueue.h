#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>
#include <QString>
using namespace std;
#define maxQueue 10

/**
*	@brief	Exception class thrown by Enqueue when queue is full.
*/
class FullQueue {
public:
    /**
    *	@brief	Display a message for full queue on screen.
    */
    void print() {
        cout << "Queue is Full" << endl;
    }
};

/**
*	@brief	Exception class thrown by Dequeue when queue is empty.
*/
class EmptyQueue {
public:
    /**
    *	@brief	Display a message for empty queue on screen.
    */
    void print() {
        cout << "Queue is Empty" << endl;
    }
};

/**
*	@brief	Queue class.
*	@details	This class processes as First In, First Out (FIFO), 템플릿을 적용해 다양한 변수 타입을 저장할 수 있다.
*/
template<typename T>
class CircularQueue {
public:
    /**
    *	@brief	Allocate dynamic array whose size is maxQueue.
    *	@pre	The maxQueue is defined
    *	@post	Member of items points the allocated array.
    */
    CircularQueue();

    /**
    *	@brief	Allocate dynamic array whose size is max.
    *	@pre	none.
    *	@post	Member of items points the allocated array.
    */
    CircularQueue(int max);

    /**
    *	@brief	Destruct the object. Free the array dynamically allocated.
    *	@pre	Release memory for queue pointer.
    *	@post	none.
    */
    ~CircularQueue();


    /**
    *	@brief	Determines whether the queue is full.
    *	@pre	Queue has been initialized.
    *	@post	Function value = (queue is full)
    */
    bool IsFull();

    /**
    *	@brief	Determines whether the queue is empty.
    *	@pre	Queue has been initialized.
    *	@post	Function value = (queue is empty)
    */
    bool IsEmpty();

    /**
    *	@brief	Makes the queue empty.
    *	@pre	Queue has been initialized.
    *	@post	m_iFront와 m_iRear is set same value as Constructer.
    */
    void MakeEmpty();

    /**
    *	@brief	Adds newItem to the last of the queue.
    *	@pre	Queue has been initialized.
    *	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
    */
    void Enqueue(T item);

    /*

    */
    void AddToPlayList(T& data);

    /**
    *	@brief	Removes first item from the queue.
    *	@pre	Queue has been initialized.
    *	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
    */
    void Dequeue();

    /**
    *	@brief	Print all the items in the queue on screen
    *	@pre	Queue has been initialized.
    *	@post	None.
    */
    QString Print();

    bool FindNPlus(T& item);

private:
    int front;		//index of one infront of the first element.
    int rear;		//index of the last element.
    int max;		//max size of the queue.
    T* m_Array;		//pointer for dynamic allocation.
};

//Allocate dynamic array whose size is maxQueue.
template<typename T>
CircularQueue<T>::CircularQueue() {
    m_Array = new T[maxQueue];
    max = maxQueue;
    front = max - 1;
    rear = max - 1;
}

//Allocate dynamic array whose size is max.
template<typename T>
CircularQueue<T>::CircularQueue(int m) {
    m_Array = new T[m];
    max = m;
    front = max - 1;
    rear = max - 1;
}

//Destruct the object. Free the array dynamically allocated.
template<typename T>
CircularQueue<T>::~CircularQueue() {
    delete[] m_Array;
}

//Determines whether the queue is empty.
template<typename T>
bool CircularQueue<T>::IsEmpty() {
    if (front == rear)
        return 1;
    return 0;
}

//Determines whether the queue is full.
template<typename T>
bool CircularQueue<T>::IsFull() {
    if ((rear + 1) % max == front)
        return 1;
    return 0;
}

//Makes the queue empty.
template<typename T>
void CircularQueue<T>::MakeEmpty() {
    front = max - 1;
    rear = max - 1;
}

//Adds newItem to the last of the queue.
template<typename T>
void CircularQueue<T>::Enqueue(T item) {
    if (IsFull())
        throw FullQueue();
    rear = (rear + 1) % max;
    m_Array[rear] = item;
}

template<typename T>
void CircularQueue<T>::AddToPlayList(T& item) {
    if (IsFull())
        Dequeue();
    Enqueue(item);
}


//Removes first item from the queue.
template<typename T>
void CircularQueue<T>::Dequeue() {
    if (IsEmpty())
        throw EmptyQueue();
    front = (front + 1) % max;
}

//Print all the items in the queue on screen
template<typename T>
QString CircularQueue<T>::Print() {
    string str="";
    if (front > rear) {
        for (int i = front + 1;i < max;i++)
            str+= m_Array[i].DisplaySimpleSongRecord();
        for (int i = 0;i <= rear;i++)
            str+=m_Array[i].DisplaySimpleSongRecord();
    }
    else {
        for (int i = front + 1;i <= rear;i++)
            str+=m_Array[i].DisplaySimpleSongRecord();
    }
    str+="\n\n";
    QString ans=QString::fromUtf8(str.c_str());

    return ans;
}

template<typename T>
bool CircularQueue<T>::FindNPlus(T& item) {
    int i = 0;
    for (i = 0;i <= rear && m_Array[i].Compares_PK(item) == LESS2;i++);

    if (m_Array[i].Compares_PK(item) == EQUAL2) {
        m_Array[i].SetSongPlayedTime(1);
        return 1;
    }
    else return 0;
}


#endif
