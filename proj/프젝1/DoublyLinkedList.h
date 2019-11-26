#pragma once
#ifndef _DOUBLYLINKEDLIST_H
#define _DOUBLYLINKEDLIST_H

#include "DoublyIterator.h"

#define min PlayItem()
#define max PlayItem()

template<typename T>
class DoublyIterator;

/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< �� ����� ������.
	DoublyNodeType *prev; ///< ����� ���� ����Ű�� ������.
	DoublyNodeType *next; ///< ����� ������ ����Ű�� ������.
};

/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublyLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyLinkedList();

	/**
	*	�Ҹ���.
	*/
	~DoublyLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	���� á���� �ƴ����� �˷��ش�.
	*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	void Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T &item);

	void Display();
	void DisplayMusic();

private:
	DoublyNodeType<T>* m_pFirst; ///< �ּҰ��� ������ ����Ʈ�� �� ó��.
	DoublyNodeType<T>* m_pLast; ///< �ִ��� ������ ����Ʈ�� �� ��.
	int m_nLength; ///< ����Ʈ�� ����.
};

// ����Ʈ�� �� ó���� ���� ���θ� ����Ű�� �����ϰ� ����Ʈ�� ���̸� 0���� �ʱ�ȭ���ѳ��´�.
template <typename T>
DoublyLinkedList<T> ::DoublyLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->next = m_pLast; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.
	m_pFirst->prev = NULL; // ó��.

	m_pLast->next = NULL; // ��.
	m_pLast->data.SetID("last");
	m_pLast->prev = m_pFirst; // ���� ó���� ���θ� ����Ű�� �ʱ�ȭ.

	m_nLength = 0; // ���̴� 0.
}

// �Ҹ���.
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	delete m_pFirst;
	delete m_pLast;
}

// ����Ʈ�� ������� �˻��Ѵ�.
template <typename T>
bool DoublyLinkedList<T>::IsEmpty()
{
	if (m_nLength == 0)
		return true;
	else
		return false;
}

// ����Ʈ�� �� ���ִ��� �˻��Ѵ�.
template <typename T>
bool DoublyLinkedList<T>::IsFull()
{
	if (m_nLength == 10)
		return true;
	else
		return false;
}

// ����Ʈ�� ����.
template <typename T>
void DoublyLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.NextNotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.Next(); // ���� �����͸� �������� �̵�.
		delete pItem;
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	return;
}

// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
template <typename T>
int DoublyLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// �������� �Է¹޾� ����Ʈ�� �����Ѵ�.
template <typename T>
int DoublyLinkedList<T>::Add(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.
	while (1) {
		if (itor.m_pCurPointer->data.GetID() == "last")
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem->data = item;
			pItem->prev = itor.m_pCurPointer->prev;
			pItem->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev->next = pItem;
			itor.m_pCurPointer->prev = pItem; // �������� ����.
			m_nLength++;
			return 1;
		}
		else if (item.GetID() == itor.m_pCurPointer->data.GetID()) // ���� ������ �������� ������
			return 0; // 0�� ��ȯ.
		else
			itor.Next(); // �������� �̵�.
	}
}

// �Է¹��� �������� �����Ϳ��� ã�Ƴ��� �����Ѵ�.
template <typename T>
void DoublyLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data.GetID() == item.GetID()) // ��ġ�ϴ� �����͸� ã�´�.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			itor.Next();
			pItem->prev->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // �����ϴ� ����� �հ� �ڸ� ���� �̾��ش�.
			delete pItem; // ����.
			return;
		}
		else
			itor.Next();
	}
	m_nLength--; // ���� ����.
	return;
}

// �Է¹��� �������� ������ ��ü�Ѵ�.
template <typename T>
void DoublyLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> itor(*this);
	itor.Next(); // �������� �̵�.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // ������ ��ü.
			return;
		}
		else
			itor.Next();
	}

	return;
}

// �Է¹��� �����۰� ��ġ�ϴ� �������� ����Ʈ���� ã�� �����´�.
template <typename T>
int DoublyLinkedList<T>::Get(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data.GetID() == item.GetID())
		{
			item = itor.m_pCurPointer->data;
			return 1; // ��ġ�ϸ� 1�� ��ȯ.
		}
		else
			itor.Next(); // �������� �̵�.
	}

	return 0; // ��ġ���� ������ 0�� ��ȯ.
}

template <typename T>
void DoublyLinkedList<T>::Display() {

	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast) {
		itor.m_pCurPointer->data.DisplayRecord();
		itor.Next();
	}
}

template <typename T>
void DoublyLinkedList<T>::DisplayMusic() {

	DoublyIterator<T> itor(*this);
	itor.Next();

	while (itor.m_pCurPointer != m_pLast) {
		cout << "\t-----------------------------------\n";
		cout << "\tID : " << itor.m_pCurPointer->data.GetID();
		itor.m_pCurPointer->data.DisplayMusic();
		cout << "\t-----------------------------------\n";

		itor.Next();
	}
}


#endif _DOUBLYLINKEDLIST_H