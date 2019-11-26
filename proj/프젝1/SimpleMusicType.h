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
	*	기본 생성자.
	*/
	SimpleMusicType() {
		s_PK = -1;
		s_Name = "";
		s_Artist = "";
		s_Played_Time = 0;
	}

	/**
	*	기본 소멸자.
	*/
	~SimpleMusicType() {}

	/**
	*	@brief	음악 고유번호를 가져온다.
	*	@pre	음악 고유번호가 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	s_PK.
	*/
	int GetSongPK();

	/**
	*	@brief	음악 이름을 가져온다.
	*	@pre	음악 이름이 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	s_Name.
	*/
	string GetSongName();

	/**
	*	@brief	가수 이름을 가져온다.
	*	@pre	가수 이름이 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	s_Artist.
	*/
	string GetSongArtist();

	/**
	*	@brief	곡 PrimaryKey를 설정한다.
	*	@pre	없음.
	*	@post	곡명이 설정된다.
	*	@param	inPK	설정할 곡 PrimaryKey.
	*/
	void SetSongPK(int inPK);

	/**
	*	@brief	곡명을 설정한다.
	*	@pre	없음.
	*	@post	곡명이 설정된다.
	*	@param	inName	설정할 곡명.
	*/
	void SetSongName(string inName);

	/**
	*	@brief	가수명을 설정한다.
	*	@pre	없음.
	*	@post	가수명이 설정된다.
	*	@param	inArtist 설정할 가수명.
	*/
	void SetSongArtist(string inArtist);

	/**
	*	@brief  음악을 재생한 횟수가 설정된다.
	*	@pre	없음.
	*	@post	음악을 재생한 횟수가 설정된다.
	*/
	void SetSongPlayedTime(int inPlayedTime);

	/**
	*	@brief	간단한 곡정보를 설정한다.
	*	@pre	없음.
	*	@post	곡정보가 설정된다.
	*	@param	inPK		설정할 곡 고유번호.
	*	@param	inName		설정할 곡명.
	*	@param	inArtist	설정할 가수명.
	*/
	void SetSongRecord(int inPK, string inName, string inArtist);

	/**
	*	@brief	곡 PrimaryKey를 키보드로 입력받아 설정한다.
	*	@pre	없음.
	*	@post	곡 PrimaryKey가 설정된다.
	*/
	void SetSongPKFromKB();

	/**
	*	@brief	곡명을 키보드로 입력받아 설정한다.
	*	@pre	없음.
	*	@post	곡명이 설정된다.
	*/
	void SetSongNameFromKB();

	/**
	*	@brief	가수명을 키보드로 입력받아 설정한다.
	*	@pre	없음.
	*	@post	가수명이 설정된다.
	*/
	void SetSongArtistFromKB();

	/**
	*	@brief	간단한 곡정보를 키보드로 입력받아 설정한다.
	*	@pre	없음.
	*	@post	곡정보가 설정된다.
	*/
	void SetSongRecordFromKB();

	/**
	*	@brief	곡 고유번호를 출력한다.
	*	@pre	곡 고유번호가 설정되어 있어야 한다.
	*	@post	곡 고유번호가 출력된다.
	*/
	void DisplaySimpleSongPK();

	/**
	*	@brief	곡 이름을 출력한다.
	*	@pre	곡 이름이 설정되어 있어야 한다.
	*	@post	곡 이름이 출력된다.
	*/
	void DisplaySimpleSongName();

	/**
	*	@brief	가수 이름을 출력한다.
	*	@pre	가수 이름이 설정되어 있어야 한다.
	*	@post	가수 이름이 출력된다.
	*/
	void DisplaySimpleSongArtist();

	/**
	*	@brief	곡 정보를 출력한다.
	*	@pre	곡 정보가 설정되어 있어야 한다.
	*	@post	곡 정보가 출력된다.
	*/
	void DisplaySimpleSongRecord();

	/**
	*	@brief	곡 재생횟수를 출력한다.
	*	@pre	곡 재생횟수가 설정되어 있어야 한다.
	*	@post	곡 재생횟수가 출력된다.
	*/
	void DisplaySimpleSongPlayedTime();

	/**
	*	@brief	데이터 비교를 위한 operator 오버로딩.
	*	@pre	리스트가 초기화 되어 있어야 한다.
	*	@post	데이터가 비교된다.
	*	@param	data	비교할 데이터.
	*	@return	data의 Num이 크면 1반환, 그렇지 않으면 0 반환.
	*/
	bool operator>(SimpleMusicType data);

	/**
	*	@brief	두 PrimaryKey를 비교한다.
	*	@pre	두 개의 SimpleMusicType이 초기화 되어있어야 한다.
	*	@post	두 Type이 비교된다.
	*	@param	data	비교를 위한 아이템이다.
	*	@return	this.s_PK < data.s_PK 이면 LESS 반환,
	*			this.s_PK > data.s_PK 이면 GREATER 반환,
	*			그렇지 않으면 EQUAL 반환.
	*/
	RelationType2 Compares_PK(const SimpleMusicType &data);

	/**
	*	@brief	두 곡의 재생횟수를 비교한다.
	*	@pre	두 개의 SimpleMusicType이 초기화 되어있어야 한다.
	*	@post	두 Type이 비교된다.
	*	@param	data	비교를 위한 아이템이다.
	*	@return	this.s_Played_Time < data.s_Played_Time 이면 LESS 반환,
	*			this.s_Played_Time > data.s_Played_Time 이면 GREATER 반환,
	*			그렇지 않으면 EQUAL 반환.
	*/
	RelationType2 ComparePlayed_Time(const SimpleMusicType &data);

	/**
	*	@brief	데이터 비교를 위한 operator 오버로딩.
	*	@pre	리스트가 초기화 되어 있어야 한다.
	*	@post	데이터가 비교된다.
	*	@param	data	비교할 데이터.
	*	@return	data의 Num이 같으면 1반환, 그렇지 않으면 0 반환.
	*/
	bool operator==(SimpleMusicType data);

private:
	int s_PK;
	string s_Name;
	string s_Artist;
	int s_Played_Time;
};

#endif