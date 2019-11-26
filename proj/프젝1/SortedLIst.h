#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#define MAXSIZE 10
#include"MusicType.h"
using namespace std;

template<typename T>
class SortedList {
public:
	SortedList();
	SortedList(int max);
	~SortedList();

	void MakeEmpty();
	int GetLength();
	int Get(T& data);
	int Add(T item);
	int Delete(T item);
	int Replace(T item);
	int RetrieveBS(T& item);
	int RetrieveName(T& item);
	bool IsFull();
	bool IsEmpty();
	void ResetList();
	int GetNextItem(T& item);
	int AddHotList(T item);

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
int SortedList<T>::Replace(T data) {
	if (RetrieveBS(data)) {
		m_Array[m_Curpointer].SetRecordFromKB();
		return 1;
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

template<typename T>
int SortedList<T>::AddHotList(T item) {
	if (!IsFull()) {
		T CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_Curpointer <= m_length) {
			if (CurItem.ComparePlayed_Time(item) == GREATER || m_Curpointer == m_length) {
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


#endif