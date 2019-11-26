#ifndef _SIMPLEMUSICTYPE_H
#define _SIMPLEMUSICTYPE_H

#include<iostream>
#include<string>
using namespace std;



enum RelationType2 { LESS2, EQUAL2, GREATER2 }; // LESS2 0, EQUAL2 1, GREATER2 2

class SimpleMusicType
{
public:
	/**
	*	�⺻ ������.
	*/
	SimpleMusicType() {
		s_PK = -1;
		s_Name = "";
		s_Artist = "";
		s_Played_Time = 0;
	}

	/**
	*	�⺻ �Ҹ���.
	*/
	~SimpleMusicType() {}

	/**
	*	@brief	���� ������ȣ�� �����´�.
	*	@pre	���� ������ȣ�� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	s_PK.
	*/
	int GetSongPK();

	/**
	*	@brief	���� �̸��� �����´�.
	*	@pre	���� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	s_Name.
	*/
	string GetSongName();

	/**
	*	@brief	���� �̸��� �����´�.
	*	@pre	���� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	����.
	*	@return	s_Artist.
	*/
	string GetSongArtist();

	/**
	*	@brief	�� PrimaryKey�� �����Ѵ�.
	*	@pre	����.
	*	@post	����� �����ȴ�.
	*	@param	inPK	������ �� PrimaryKey.
	*/
	void SetSongPK(int inPK);

	/**
	*	@brief	����� �����Ѵ�.
	*	@pre	����.
	*	@post	����� �����ȴ�.
	*	@param	inName	������ ���.
	*/
	void SetSongName(string inName);

	/**
	*	@brief	�������� �����Ѵ�.
	*	@pre	����.
	*	@post	�������� �����ȴ�.
	*	@param	inArtist ������ ������.
	*/
	void SetSongArtist(string inArtist);

	/**
	*	@brief  ������ ����� Ƚ���� �����ȴ�.
	*	@pre	����.
	*	@post	������ ����� Ƚ���� �����ȴ�.
	*/
	void SetSongPlayedTime(int inPlayedTime);

	/**
	*	@brief	������ �������� �����Ѵ�.
	*	@pre	����.
	*	@post	�������� �����ȴ�.
	*	@param	inPK		������ �� ������ȣ.
	*	@param	inName		������ ���.
	*	@param	inArtist	������ ������.
	*/
	void SetSongRecord(int inPK, string inName, string inArtist);

	/**
	*	@brief	�� PrimaryKey�� Ű����� �Է¹޾� �����Ѵ�.
	*	@pre	����.
	*	@post	�� PrimaryKey�� �����ȴ�.
	*/
	void SetSongPKFromKB();

	/**
	*	@brief	����� Ű����� �Է¹޾� �����Ѵ�.
	*	@pre	����.
	*	@post	����� �����ȴ�.
	*/
	void SetSongNameFromKB();

	/**
	*	@brief	�������� Ű����� �Է¹޾� �����Ѵ�.
	*	@pre	����.
	*	@post	�������� �����ȴ�.
	*/
	void SetSongArtistFromKB();

	/**
	*	@brief	������ �������� Ű����� �Է¹޾� �����Ѵ�.
	*	@pre	����.
	*	@post	�������� �����ȴ�.
	*/
	void SetSongRecordFromKB();

	/**
	*	@brief	�� ������ȣ�� ����Ѵ�.
	*	@pre	�� ������ȣ�� �����Ǿ� �־�� �Ѵ�.
	*	@post	�� ������ȣ�� ��µȴ�.
	*/
	void DisplaySimpleSongPK();

	/**
	*	@brief	�� �̸��� ����Ѵ�.
	*	@pre	�� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	�� �̸��� ��µȴ�.
	*/
	void DisplaySimpleSongName();

	/**
	*	@brief	���� �̸��� ����Ѵ�.
	*	@pre	���� �̸��� �����Ǿ� �־�� �Ѵ�.
	*	@post	���� �̸��� ��µȴ�.
	*/
	void DisplaySimpleSongArtist();

	/**
	*	@brief	�� ������ ����Ѵ�.
	*	@pre	�� ������ �����Ǿ� �־�� �Ѵ�.
	*	@post	�� ������ ��µȴ�.
	*/
	void DisplaySimpleSongRecord();

	/**
	*	@brief	�� ���Ƚ���� ����Ѵ�.
	*	@pre	�� ���Ƚ���� �����Ǿ� �־�� �Ѵ�.
	*	@post	�� ���Ƚ���� ��µȴ�.
	*/
	void DisplaySimpleSongPlayedTime();

	/**
	*	@brief	������ �񱳸� ���� operator �����ε�.
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ� �־�� �Ѵ�.
	*	@post	�����Ͱ� �񱳵ȴ�.
	*	@param	data	���� ������.
	*	@return	data�� Num�� ũ�� 1��ȯ, �׷��� ������ 0 ��ȯ.
	*/
	bool operator>(SimpleMusicType data);

	/**
	*	@brief	�� PrimaryKey�� ���Ѵ�.
	*	@pre	�� ���� SimpleMusicType�� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	�� Type�� �񱳵ȴ�.
	*	@param	data	�񱳸� ���� �������̴�.
	*	@return	this.s_PK < data.s_PK �̸� LESS ��ȯ,
	*			this.s_PK > data.s_PK �̸� GREATER ��ȯ,
	*			�׷��� ������ EQUAL ��ȯ.
	*/
	RelationType2 Compares_PK(const SimpleMusicType &data);

	/**
	*	@brief	�� ���� ���Ƚ���� ���Ѵ�.
	*	@pre	�� ���� SimpleMusicType�� �ʱ�ȭ �Ǿ��־�� �Ѵ�.
	*	@post	�� Type�� �񱳵ȴ�.
	*	@param	data	�񱳸� ���� �������̴�.
	*	@return	this.s_Played_Time < data.s_Played_Time �̸� LESS ��ȯ,
	*			this.s_Played_Time > data.s_Played_Time �̸� GREATER ��ȯ,
	*			�׷��� ������ EQUAL ��ȯ.
	*/
	RelationType2 ComparePlayed_Time(const SimpleMusicType &data);

	/**
	*	@brief	������ �񱳸� ���� operator �����ε�.
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ� �־�� �Ѵ�.
	*	@post	�����Ͱ� �񱳵ȴ�.
	*	@param	data	���� ������.
	*	@return	data�� Num�� ������ 1��ȯ, �׷��� ������ 0 ��ȯ.
	*/
	bool operator==(SimpleMusicType data);

private:
	int s_PK;
	string s_Name;
	string s_Artist;
	int s_Played_Time;
};

#endif