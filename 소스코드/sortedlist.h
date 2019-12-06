#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#define MAXSIZE 10
#include"MusicType.h"
using namespace std;

template<typename T>
class SortedList {
public:
    /**
    *	default constructor.
    */
    SortedList();
    /**
    *	constructor.
    */
    SortedList(int max);

    /**
    *	destructor.
    */
    ~SortedList();


    /**
    *	@brief	Make list empty.
    *	@pre	none.
    *	@post	clear list.
    */
    void MakeEmpty();

    /**
    *	@brief	Get a number of records in current list.
    *	@pre	none.
    *	@post	none.
    *	@return	number of records in current list.
    */
    int GetLength();

    /**
    *	@brief	get the item which list iterator points.
    *	@pre	list and list iterator should not be initialized.
    *	@post	iterator points current item.
    *	@param	data	get current iterator's item. it does not need to be initialized.
    *	@return	return 1 if brought data isn't NULL, otherwise 0.
    */
    int Get(T& data);

    /**
    *	@brief	add a new data into list.
    *	@pre	list should be initialized.
    *	@post	added the new record into the list.
    *	@param	data	new data.
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int Add(T item);

    /**
    *	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
    *	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
    *	@post	list 내에 해당 item이 제거된다.
    *	@param	data	제거하고자 하는 id가 입력된 ItemType값.
    *	@return	성공시 1, 실패시 0을 리턴한다.
    */
    int Delete(T item);

    /**
    *	@brief	item을 찾아서 해당 item을 반환한다.
    *	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
    *	@post	list 내에서 찾은 item이 data에 입력된다.
    *	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
    *	@return	성공(발견)시 1, 실패시 0을 리턴한다.
    */
    int RetrieveBS(T& item);

    /**
    *	@brief	item을 찾아서 해당 item을 반환한다.
    *	@pre	인수 data에 있는 name이 list 내에 존재하는 값이어야 한다.
    *	@post	list 내에서 찾은 item이 data에 입력된다.
    *	@param	data	찾고자 하는 name이 입력된 ItemType값. 발견한 item이 리턴된다.
    *	@return	성공(발견)시 1, 실패시 0을 리턴한다.
    */
    int RetrieveName(T& item);

    /**
    *	@brief	Check capacity of list is full.
    *	@pre	none.
    *	@post	none.
    *	@return	return true if list capacity reached to the upper bound, otherwise return false.
    */
    bool IsFull();

    /**
    *	@brief	Check capacity of list is empty.
    *	@pre	none.
    *	@post	none.
    *	@return	return true if list capacity reached to the lower bound, otherwise return false.
    */
    bool IsEmpty();

    /**
    *	@brief	Initialize list iterator.
    *	@pre	list should be initialized.
    *	@post	iterator is reset.
    */
    void ResetList();

    /**
    *	@brief	move list iterator to the next item in list and get that item.
    *	@pre	list and list iterator should not be initialized.
    *	@post	iterator is moved to next item.
    *	@param	data	get current iterator's item. it does not need to be initialized.
    *	@return	index of current iterator's item if is not end of list, oterwise return -1.
    */
    int GetNextItem(T& item);

private:
    T * m_Array;
    int m_length;
    int m_Curpointer;
};

template<typename T>
SortedList<T>::SortedList() {
    m_Array = new T[MAXSIZE];
    m_length = 0;
    ResetList();
}

template<typename T>
SortedList<T>::SortedList(int max) {
    m_Array = new T[max];
    m_length = 0;
    ResetList();
}

template<typename T>
SortedList<T>::~SortedList() {
    delete[] m_Array;
}

template<typename T>
void SortedList<T>::MakeEmpty() {
    m_length = 0;
}

template<typename T>
int SortedList<T>::GetLength() {
    return m_length;
}

template<typename T>
bool SortedList<T>::IsFull() {
    return m_length > MAXSIZE - 1;
}

template<typename T>
bool SortedList<T>::IsEmpty() {
    return m_length == 0;
}

template<typename T>
int SortedList<T>::Add(T item) {
    if (!IsFull()) {
        T CurItem;
        ResetList();
        GetNextItem(CurItem);

        while (m_Curpointer <= m_length) {
            if (CurItem.Compares_PK(item) == GREATER || m_Curpointer == m_length) {
                for (int i = m_length;i > m_Curpointer;i--)
                    m_Array[i] = m_Array[i - 1];
                m_Array[m_Curpointer] = item;
                m_length++;
                return 1;
            }
            GetNextItem(CurItem);
        }
    }
    return 0;
}

template<typename T>
int SortedList<T>::Get(T& data) {
    T item = m_Array[m_Curpointer];

    data.SetRecord(item.GetPK(), item.GetName(), item.GetArtist(), item.GetAlbum(), item.GetGenre());

    if (data.GetName() != "")
        return 1;
    else
        return 0;
}

template<typename T>
int SortedList<T>::Delete(T item) {
    if (RetrieveBS(item)) {
        for (int i = m_Curpointer;i < m_length;i++)
            m_Array[i] = m_Array[i + 1];
        m_length--;
        return 1;
    }
    return 0;
}

template<typename T>
int SortedList<T>::RetrieveBS(T& item) {
    int first = 0, last = m_length - 1, mid;

    while (first <= last) {
        mid = (first + last) / 2;
        if (m_Array[mid].Compares_PK(item) == GREATER)
            last = mid - 1;
        else if (m_Array[mid].Compares_PK(item) == LESS)
            first = mid + 1;
        else {
            m_Curpointer = mid;
            Get(item);
            return 1;
        }
    }
    return 0;
}

template<typename T>
int SortedList<T>::RetrieveName(T& item) {
    T data;
    ResetList();
    int idx = GetNextItem(data);

    while (idx != -1) {
        if (data.CompareName(item) == SAME) {
            Get(item);
            return 1;
        }
        idx = GetNextItem(data);
    }
    return 0;
}

template<typename T>
void SortedList<T>::ResetList() {
    m_Curpointer = -1;
}

template<typename T>
int SortedList<T>::GetNextItem(T& item) {
    m_Curpointer++;
    if (m_Curpointer == GetLength())
        return -1;
    item = m_Array[m_Curpointer];
    return m_Curpointer;
}


#endif
