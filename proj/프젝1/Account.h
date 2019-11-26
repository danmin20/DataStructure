#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include"SortedList.h"
#include"SimpleMusicType.h"
#include"CircularQueue.h"
#include"DoublyLinkedList.h"
using namespace std;

#define FILENAMESIZE 1024

class Account
{
public:
	Account() {		// �⺻ ������
		m_Command = 0;
	}
	~Account() {}	// �⺻ �Ҹ���

	/**
	*	@brief	���α׷��� �����Ų��.
	*	@pre	���α׷��� ���۵Ǿ�� �Ѵ�.
	*	@post	���α׷��� ������.
	*/
	void Run();

	/**
	*	@brief	��ɾ���� ȭ�鿡 ����ϰ� Ű����κ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	����ڰ� �Է��� ����� �����Ѵ�.
	*/
	int GetCommand();

	/**
	*	@brief	����Ʈ�� ���ο� ������ �߰��Ѵ�.
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	����Ʈ�� ���ο� ������ �߰��ȴ�.
	*	@return	�� �۵� �Ǿ����� 1�� ����, �׷��� ������ 0�� �����Ѵ�.
	*/
	int AddMusic();

	/**
	*	@brief	����Ʈ�� �ִ� ���� ������ �����Ѵ�.
	*	@pre	����Ʈ�� ����ڰ� ������ ������ �־�� �Ѵ�.
	*	@post	����Ʈ���� ���� ������ �����ȴ�.
	*/
	int DeleteMusic();

	/**
	*	@brief	PrimaryKey�� �������� ������ �˻��ϱ� ���� ����ڷκ��� �˻��� PrimaryKey�� �Է¹޴´�.
	*	@pre	�Է¹��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	RetreiveRecordByPK�� ȣ���ϰ� �Է¹��� �����͸� �ѱ��.
	*/
	void SearchByPK();

	/**
	*	@brief	Name�� �������� ������ �˻��ϱ� ���� ����ڷκ��� �˻��� ����� �Է¹޴´�.
	*	@pre	�Է¹��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	RetreiveRecordByName�� ȣ���ϰ� �Է¹��� �����͸� �ѱ��.
	*/
	void SearchByName();

	/**
	*	@brief	����Ʈ�� �ִ� ��� ���ǵ��� ����Ѵ�.
	*	@pre	����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	ȭ�鿡 ��� ������ ��µȴ�.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	���� ��ũ���͸� �̿��Ͽ� ���� ������ ����.
	*	@pre	���� ������ �����ؾ� �Ѵ�.
	*	@post	���� ������ ����.
	*	@param	fileName	���� ������ ���� descriptor.
	*	@return	�Լ��� ����� �۵� �Ǿ����� 1��, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	���� ��ũ���͸� �̿��Ͽ� �� ������ ����.
	*	@pre	�� ������ �����ؾ� �Ѵ�.
	*	@post	�� ������ ����.
	*	@param	fileName	�� ������ ���� descriptor.
	*	@return	�Լ��� ����� �۵� �Ǿ����� 1��, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	������ �б� ���� ����, ������ ��� ������ �о����, �����͸� ����Ʈ�� �ִ´�.
	*	@pre	���� ������ �������� �ʴ�.
	*	@post	����Ʈ�� ������ ������ ��� ��Եȴ�.
	*	@return	�Լ��� ����� �۵� �Ǿ����� 1��, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	������ ���� ���� ����, ���Ͽ� ����Ʈ�� ������ ��� ����.
	*	@pre	���� ������ �������� �ʴ�.
	*	@post	������ ����Ʈ�� ������ ��� ��Եȴ�.
	*	@return	�Լ��� ����� �۵� �Ǿ����� 1��, �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int WriteDataToFile();

	/**
	*	@brief	����� �޾� ������ ����Ѵ�.
	*	@pre	��� �� �� ���Ƚ�� �����Ѵ�.
	*	@post	���� Played_Time �����Ѵ�.
	*/
	void PlayMusic();

	/**
	*	@brief	�������� �з��� ���� ������ ����Ѵ�.
	*	@pre	������ �ִ� ��� ��µȴ�.
	*	@post	�������� ������ ������ �ڼ��� ������ ��µȴ�.
	*/
	void DisplayMusicByArtist();

	/**
	*	@brief	�ٹ����� �з��� ���� ������ ����Ѵ�.
	*	@pre	������ �ִ� ��� ��µȴ�.
	*	@post	�ٹ����� ������ ������ �ڼ��� ������ ��µȴ�.
	*/
	void DisplayMusicByAlbum();

	/**
	*	@brief	�帣���� �з��� ���� ������ ����Ѵ�.
	*	@pre	������ �ִ� ��� ��µȴ�.
	*	@post	�帣���� ������ ������ �ڼ��� ������ ��µȴ�.
	*/
	void DisplayMusicByGenre();

	/**
	*	@brief	���� �ֱ� �߰��� ���� ������ ����Ѵ�.
	*	@pre	������ �ִ� ��� ��µȴ�.
	*	@post	ȭ�鿡 �ش� ������ ��µȴ�.
	*/
	void DisplayRecentAddMusic();

	/**
	*	@brief	playlist�� �ִ� ��� ���ǵ��� ����Ѵ�.
	*	@pre	����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	ȭ�鿡 ��� ������ ��µȴ�.
	*/
	void DisplayAllMusicInPlayList();

	/**
	*	@brief	playlist ����.
	*	@pre	�ʱ�ȭ�� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� ��� �׸��� �����ȴ�.
	*/
	void MakePlayListEmpty();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� ��� �׸��� �����ȴ�.
	*/
	void MakeMusicListEmpty();

private:
	int m_Command;
	ifstream m_iFile;
	ofstream m_oFile;
	SortedList<MusicType> MusicList;			//PK�� sort
	CircularQueue<SimpleMusicType> PlayList;	//�ֱ� ������
};

#endif