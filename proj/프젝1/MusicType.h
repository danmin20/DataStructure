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
	*	기본 생성자.
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
	*	기본 소멸자.
	*/
	~MusicType() {}

	/**
	*	@brief	음악의 PrimaryKey를 가져온다.
	*	@pre	음악의 PrimaryKey가 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	PK.
	*/
	int GetPK();

	/**
	*	@brief	음악 이름을 가져온다.
	*	@pre	음악 이름이 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	Name.
	*/
	string GetName();

	/**
	*	@brief	가수 이름을 가져온다.
	*	@pre	가수 이름이 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	Artist.
	*/
	string GetArtist();

	/**
	*	@brief	앨범 이름을 가져온다.
	*	@pre	앨범 이름이 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	Album.
	*/
	string GetAlbum();

	/**
	*	@brief	장르를 가져온다.
	*	@pre	장르가 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	Genre.
	*/
	string GetGenre();

	/**
	*	@brief	음악을 재생한 횟수를 가져온다.
	*	@pre	음악을 재생한 횟수가 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	Played_Time.
	*/
	int GetPlayedTime();

	/**
	*	@brief	음악이 추가된 순서를 가져온다.
	*	@pre	음악이 추가된 순서가 설정되어 있어야 한다.
	*	@post	없음.
	*	@return	Added_Time.
	*/
	int GetAddedNum();

	/**
	*	@brief  음악의 PrimaryKey가 설정된다.
	*	@pre	없음.
	*	@post	음악의 PrimaryKey가 설정된다.
	*/
	void SetPK(int inPK);

	/**
	*	@brief  음악 이름이 설정된다.
	*	@pre	없음.
	*	@post	음악 이름이 설정된다.
	*/
	void SetName(string inName);

	/**
	*	@brief  가수 이름이 설정된다.
	*	@pre	없음.
	*	@post	가수 이름이 설정된다.
	*/
	void SetArtist(string inArtist);

	/**
	*	@brief  앨범 이름이 설정된다.
	*	@pre	없음.
	*	@post	앨범 이름이 설정된다.
	*/
	void SetAlbum(string inAlbum);

	/**
	*	@brief  장르가 설정된다.
	*	@pre	없음.
	*	@post	장르가 설정된다.
	*/
	void SetGenre(string inGenre);

	/**
	*	@brief  음악이 추가된 순서가 설정된다.
	*	@pre	없음.
	*	@post	음악이 추가된 순서가 설정된다.
	*/
	void SetAddedNum(int inAddedNum);

	/**
	*	@brief	음악 정보를 설정한다.
	*	@pre	없음.
	*	@post	음악 정보가 설정된다.
	*	@param	inPK		곡 고유번호.
	*	@param	inName		곡명.
	*	@param	inArtist	가수.
	*	@param	inAlbum		앨범.
	*	@param	inGenre		장르.
	*/
	void SetRecord(int inPK, string inName, string inArtist, string inAlbum, string inGenre);

	/**
	*	@brief	곡 PrimaryKey를 출력한다.
	*	@pre	곡 PrimaryKey가 설정되어 있어야 한다.
	*	@post	곡 PrimaryKey가 출력된다.
	*/
	void DisplayPKOnScreen();

	/**
	*	@brief	곡 제목을 출력한다.
	*	@pre	곡 제목이 설정되어 있어야 한다.
	*	@post	곡 제목이 출력된다.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	가수 이름을 출력한다.
	*	@pre	가수 이름이 설정되어 있어야 한다.
	*	@post	가수 이름이 출력된다.
	*/
	void DisplayArtistOnScreen();

	/**
	*	@brief	앨범 이름을 출력한다.
	*	@pre	앨범 이름이 설정되어 있어야 한다.
	*	@post	앨범 이름이 출력된다.
	*/
	void DisplayAlbumOnScreen();

	/**
	*	@brief	장르를 출력한다.
	*	@pre	장르가 설정되어 있어야 한다.
	*	@post	장르 번호가 출력된다.
	*/
	void DisplayGenreOnScreen();

	/**
	*	@brief	음악 정보를 출력한다.
	*	@pre	음악 정보가 설정되어 있어야 한다.
	*	@post	음악 정보가 출력된다.
	*/
	void DisplayRecordOnScreen();

	/**
	*	@brief  키보드로 PrimaryKey를 입력받는다.
	*	@pre	없음.
	*	@post	음악의 PrimaryKey가 설정된다.
	*/
	void SetPKFromKB();

	/**
	*	@brief  키보드로 Name을 입력받는다.
	*	@pre	없음.
	*	@post	음악 이름이 설정된다.
	*/
	void SetNameFromKB();

	/**
	*	@brief  키보드로 Artist를 입력받는다.
	*	@pre	없음.
	*	@post	가수 이름이 설정된다.
	*/
	void SetArtistFromKB();

	/**
	*	@brief  키보드로 Album을 입력받는다.
	*	@pre	없음.
	*	@post	앨범 이름이 설정된다.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	키보드로 Genre을 입력받는다.
	*	@pre	없음.
	*	@post	장르명이 저장된다.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	키보드로 곡정보를 입력받는다.
	*	@pre	없음.
	*	@post	곡정보가 저장된다.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	파일의 모든 데이터를 읽는다.
	*	@pre	파일이 열려있어야 한다.
	*	@post	리스트에 모든 곡정보가 들어간다.
	*	@param	fin	파일 디스크립터.
	*	@return 함수가 잘 작동되었으면 1을 그렇지 않으면 0을 반환한다.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	모든 데이터를 파일에 쓴다.
	*	@pre	파일이 열려있어야 하고 리스트가 초기화되어 있어야 한다.
	*	@post	파일에 모든 곡정보들이 저장된다.
	*	@param	fout	파일 디스크립터.
	*	@return 함수가 잘 작동되었으면 1을 그렇지 않으면 0을 반환한다.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	두 PrimaryKey를 비교한다.
	*	@pre	두 개의 MusicType이 초기화 되어있어야 한다.
	*	@post	두 Type이 비교된다.
	*	@param	data	비교를 위한 아이템이다.
	*	@return	this.PK < data.PK 이면 LESS 반환,
	*			this.PK > data.PK 이면 GREATER 반환,
	*			그렇지 않으면 EQUAL 반환.
	*/
	RelationType Compares_PK(const MusicType &data);

	/**
	*	@brief	두 Name을 비교한다.
	*	@pre	두 개의 MusicType이 초기화 되어있어야 한다.
	*	@post	두 Name이 비교된다.
	*	@param	data	비교를 위한 아이템이다.
	*	@return	this.Name != data.Name 이면 DIFFERENT 반환,
	*			this.Name == data.Name 이면 SAME 반환,
	*/
	DifferentType CompareName(const MusicType &data);
	/**
	*	@brief	곡 교유번호가 큰지 아닌지 비교하기 위한 operator 오버로딩.
	*	@pre	초기화 되어 있어야 한다.
	*	@post	곡 교유번호가 비교된다.
	*	@param	item	비교할 item.
	*	@return 아이템이 크면 1을 그렇지 않으면 0을 반환한다.
	*/
	bool operator>(MusicType item) {
		return  PK > item.PK;
	}

	/**
	*	@brief	곡 교유번호가 같은지 아닌지 비교하기 위한 operator 오버로딩.
	*	@pre	초기화 되어 있어야 한다.
	*	@post	곡 고유번호가 비교된다.
	*	@param	item	비교할 item.
	*	@return 아이템이 같으면 1을 그렇지 않으면 0을 반환한다.
	*/
	bool operator==(MusicType item) {
		return PK == item.PK;
	}

	void displayadd() {
		cout << Added_Num;
	}

private:
	int PK;			// PrimaryKey
	string Name;	// 곡 명
	string Artist;	// 가수 이름
	string Album;	// 앨범 이름
	string Genre;	// 장르
	int Added_Num;	// 추가된 순서
};

#endif