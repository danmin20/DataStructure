#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

enum RelationType { LESS, EQUAL, GREATER };
enum DifferentType { SAME, DIFFERENT };

class MusicType
{
public:
	/**
	*	�⺻ ������.
	*/
	MusicType() {
		PK = -1;
		Name = "";
		Artist = "";
		Album = "";
		Genre = "";
		Added_Num = 0;
	}

	/**
	*	�⺻ �Ҹ���.
	*/
	~MusicType() {}

	/**
	*	@brief	������ PrimaryKey�� �����´�.
	*	@pre	������ PrimaryKey�� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	PK.
	*/
	int GetPK();

	/**
	*	@brief	���� �̸��� �����´�.
	*	@pre	���� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	Name.
	*/
	string GetName();

	/**
	*	@brief	���� �̸��� �����´�.
	*	@pre	���� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	Artist.
	*/
	string GetArtist();

	/**
	*	@brief	�ٹ� �̸��� �����´�.
	*	@pre	�ٹ� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	Album.
	*/
	string GetAlbum();

	/**
	*	@brief	�帣�� �����´�.
	*	@pre	�帣�� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	Genre.
	*/
	string GetGenre();

	/**
	*	@brief	������ ����� Ƚ���� �����´�.
	*	@pre	������ ����� Ƚ���� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	Played_Time.
	*/
	int GetPlayedTime();

	/**
	*	@brief	������ �߰��� ������ �����´�.
	*	@pre	������ �߰��� ������ �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	Added_Time.
	*/
	int GetAddedNum();

	/**
	*	@brief  ������ PrimaryKey�� �����ȴ�.
	*	@pre	����.
	*	@post	������ PrimaryKey�� �����ȴ�.
	*/
	void SetPK(int inPK);

	/**
	*	@brief  ���� �̸��� �����ȴ�.
	*	@pre	����.
	*	@post	���� �̸��� �����ȴ�.
	*/
	void SetName(string inName);

	/**
	*	@brief  ���� �̸��� �����ȴ�.
	*	@pre	����.
	*	@post	���� �̸��� �����ȴ�.
	*/
	void SetArtist(string inArtist);

	/**
	*	@brief  �ٹ� �̸��� �����ȴ�.
	*	@pre	����.
	*	@post	�ٹ� �̸��� �����ȴ�.
	*/
	void SetAlbum(string inAlbum);

	/**
	*	@brief  �帣�� �����ȴ�.
	*	@pre	����.
	*	@post	�帣�� �����ȴ�.
	*/
	void SetGenre(string inGenre);

	/**
	*	@brief  ������ �߰��� ������ �����ȴ�.
	*	@pre	����.
	*	@post	������ �߰��� ������ �����ȴ�.
	*/
	void SetAddedNum(int inAddedNum);

	/**
	*	@brief	���� ������ �����Ѵ�.
	*	@pre	����.
	*	@post	���� ������ �����ȴ�.
	*	@param	inPK		�� ������ȣ.
	*	@param	inName		���.
	*	@param	inArtist	����.
	*	@param	inAlbum		�ٹ�.
	*	@param	inGenre		�帣.
	*/
	void SetRecord(int inPK, string inName, string inArtist, string inAlbum, string inGenre);

	/**
	*	@brief	�� PrimaryKey�� ����Ѵ�.
	*	@pre	�� PrimaryKey�� �����Ǿ� �־�� �Ѵ�.
	*	@post	�� PrimaryKey�� ��µȴ�.
	*/
	void DisplayPKOnScreen();

	/**
	*	@brief	�� ������ ����Ѵ�.
	*	@pre	�� ������ �����Ǿ� �־�� �Ѵ�.
	*	@post	�� ������ ��µȴ�.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	���� �̸��� ����Ѵ�.
	*	@pre	���� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	���� �̸��� ��µȴ�.
	*/
	void DisplayArtistOnScreen();

	/**
	*	@brief	�ٹ� �̸��� ����Ѵ�.
	*	@pre	�ٹ� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	�ٹ� �̸��� ��µȴ�.
	*/
	void DisplayAlbumOnScreen();

	/**
	*	@brief	�帣�� ����Ѵ�.
	*	@pre	�帣�� �����Ǿ� �־�� �Ѵ�.
	*	@post	�帣 ��ȣ�� ��µȴ�.
	*/
	void DisplayGenreOnScreen();

	/**
	*	@brief	���� ������ ����Ѵ�.
	*	@pre	���� ������ �����Ǿ� �־�� �Ѵ�.
	*	@post	���� ������ ��µȴ�.
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief  Ű����� PrimaryKey�� �Է¹޴´�.
	*	@pre	����.
	*	@post	������ PrimaryKey�� �����ȴ�.
	*/
	void SetPKFromKB();

	/**
	*	@brief  Ű����� Name�� �Է¹޴´�.
	*	@pre	����.
	*	@post	���� �̸��� �����ȴ�.
	*/
	void SetNameFromKB();

	/**
	*	@brief  Ű����� Artist�� �Է¹޴´�.
	*	@pre	����.
	*	@post	���� �̸��� �����ȴ�.
	*/
	void SetArtistFromKB();

	/**
	*	@brief  Ű����� Album�� �Է¹޴´�.
	*	@pre	����.
	*	@post	�ٹ� �̸��� �����ȴ�.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Ű����� Genre�� �Է¹޴´�.
	*	@pre	����.
	*	@post	�帣���� ����ȴ�.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Ű����� �������� �Է¹޴´�.
	*	@pre	����.
	*	@post	�������� ����ȴ�.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	������ ��� �����͸� �д´�.
	*	@pre	������ �����־�� �Ѵ�.
	*	@post	����Ʈ�� ��� �������� ����.
	*	@param	fin	���� ��ũ����.
	*	@return �Լ��� �� �۵��Ǿ����� 1�� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	��� �����͸� ���Ͽ� ����.
	*	@pre	������ �����־�� �ϰ� ����Ʈ�� �ʱ�ȭ�Ǿ� �־�� �Ѵ�.
	*	@post	���Ͽ� ��� ���������� ����ȴ�.
	*	@param	fout	���� ��ũ����.
	*	@return �Լ��� �� �۵��Ǿ����� 1�� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	�� PrimaryKey�� ���Ѵ�.
	*	@pre	�� ���� MusicType�� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	�� Type�� �񱳵ȴ�.
	*	@param	data	�񱳸� ���� �������̴�.
	*	@return	this.PK < data.PK �̸� LESS ��ȯ,
	*			this.PK > data.PK �̸� GREATER ��ȯ,
	*			�׷��� ������ EQUAL ��ȯ.
	*/
	RelationType Compares_PK(const MusicType &data);

	/**
	*	@brief	�� Name�� ���Ѵ�.
	*	@pre	�� ���� MusicType�� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	�� Name�� �񱳵ȴ�.
	*	@param	data	�񱳸� ���� �������̴�.
	*	@return	this.Name != data.Name �̸� DIFFERENT ��ȯ,
	*			this.Name == data.Name �̸� SAME ��ȯ,
	*/
	DifferentType CompareName(const MusicType &data);
	/**
	*	@brief	�� ������ȣ�� ū�� �ƴ��� ���ϱ� ���� operator �����ε�.
	*	@pre	�ʱ�ȭ �Ǿ� �־�� �Ѵ�.
	*	@post	�� ������ȣ�� �񱳵ȴ�.
	*	@param	item	���� item.
	*	@return �������� ũ�� 1�� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	bool operator>(MusicType item) {
		return  PK > item.PK;
	}

	/**
	*	@brief	�� ������ȣ�� ������ �ƴ��� ���ϱ� ���� operator �����ε�.
	*	@pre	�ʱ�ȭ �Ǿ� �־�� �Ѵ�.
	*	@post	�� ������ȣ�� �񱳵ȴ�.
	*	@param	item	���� item.
	*	@return �������� ������ 1�� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	bool operator==(MusicType item) {
		return PK == item.PK;
	}

	void displayadd() {
		cout << Added_Num;
	}

private:
	int PK;			// PrimaryKey
	string Name;	// �� ��
	string Artist;	// ���� �̸�
	string Album;	// �ٹ� �̸�
	string Genre;	// �帣
	int Added_Num;	// �߰��� ����
};

#endif