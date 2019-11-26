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
	Account() {		// 기본 생성자
		m_Command = 0;
	}
	~Account() {}	// 기본 소멸자

	/**
	*	@brief	프로그램을 실행시킨다.
	*	@pre	프로그램이 시작되어야 한다.
	*	@post	프로그램이 끝난다.
	*/
	void Run();

	/**
	*	@brief	명령어들을 화면에 출력하고 키보드로부터 입력받는다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	사용자가 입력한 명령을 리턴한다.
	*/
	int GetCommand();

	/**
	*	@brief	리스트에 새로운 음악을 추가한다.
	*	@pre	리스트가 초기화 되어있어야 한다.
	*	@post	리스트에 새로운 음악이 추가된다.
	*	@return	잘 작동 되었으면 1을 리턴, 그렇지 않으면 0을 리턴한다.
	*/
	int AddMusic();

	/**
	*	@brief	리스트에 있는 기존 음악을 삭제한다.
	*	@pre	리스트에 사용자가 삭제할 음악이 있어야 한다.
	*	@post	리스트에서 기존 음악이 삭제된다.
	*/
	int DeleteMusic();

	/**
	*	@brief	PrimaryKey를 기준으로 음악을 검색하기 위해 사용자로부터 검색할 PrimaryKey를 입력받는다.
	*	@pre	입력받을 리스트가 존재해야 한다.
	*	@post	RetreiveRecordByPK을 호출하고 입력받은 데이터를 넘긴다.
	*/
	void SearchByPK();

	/**
	*	@brief	Name을 기준으로 음악을 검색하기 위해 사용자로부터 검색할 곡명을 입력받는다.
	*	@pre	입력받을 리스트가 존재해야 한다.
	*	@post	RetreiveRecordByName을 호출하고 입력받은 데이터를 넘긴다.
	*/
	void SearchByName();

	/**
	*	@brief	리스트에 있는 모든 음악들을 출력한다.
	*	@pre	리스트가 존재해야 한다.
	*	@post	화면에 모든 음악이 출력된다.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	파일 디스크립터를 이용하여 읽을 파일을 연다.
	*	@pre	읽을 파일이 존재해야 한다.
	*	@post	읽을 파일을 연다.
	*	@param	fileName	읽을 파일을 여는 descriptor.
	*	@return	함수가 제대로 작동 되었으면 1을, 그렇지 않으면 0을 반환한다.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	파일 디스크립터를 이용하여 쓸 파일을 연다.
	*	@pre	쓸 파일이 존재해야 한다.
	*	@post	쓸 파일을 연다.
	*	@param	fileName	쓸 파일을 여는 descriptor.
	*	@return	함수가 제대로 작동 되었으면 1을, 그렇지 않으면 0을 반환한다.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	파일을 읽기 모드로 열고, 파일의 모든 내용을 읽어오고, 데이터를 리스트에 넣는다.
	*	@pre	읽을 파일이 열려있지 않다.
	*	@post	리스트가 파일의 내용을 모두 담게된다.
	*	@return	함수가 제대로 작동 되었으면 1을, 그렇지 않으면 0을 반환한다.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	파일을 쓰기 모드로 열고, 파일에 리스트의 내용을 모두 쓴다.
	*	@pre	읽을 파일이 열려있지 않다.
	*	@post	파일이 리스트의 내용을 모두 담게된다.
	*	@return	함수가 제대로 작동 되었으면 1을, 그렇지 않으면 0을 반환한다.
	*/
	int WriteDataToFile();

	/**
	*	@brief	곡명을 받아 음악을 재생한다.
	*	@pre	곡명 비교 후 재생횟수 증가한다.
	*	@post	곡의 Played_Time 증가한다.
	*/
	void PlayMusic();

	/**
	*	@brief	가수별로 분류된 음악 정보를 출력한다.
	*	@pre	음악이 있는 경우 출력된다.
	*	@post	가수별로 간단한 정보와 자세한 정보가 출력된다.
	*/
	void DisplayMusicByArtist();

	/**
	*	@brief	앨범별로 분류된 음악 정보를 출력한다.
	*	@pre	음악이 있는 경우 출력된다.
	*	@post	앨범별로 간단한 정보와 자세한 정보가 출력된다.
	*/
	void DisplayMusicByAlbum();

	/**
	*	@brief	장르별로 분류된 음악 정보를 출력한다.
	*	@pre	음악이 있는 경우 출력된다.
	*	@post	장르별로 간단한 정보와 자세한 정보가 출력된다.
	*/
	void DisplayMusicByGenre();

	/**
	*	@brief	제일 최근 추가된 음악 정보를 출력한다.
	*	@pre	음악이 있는 경우 출력된다.
	*	@post	화면에 해당 음악이 출력된다.
	*/
	void DisplayRecentAddMusic();

	/**
	*	@brief	playlist에 있는 모든 음악들을 출력한다.
	*	@pre	리스트가 존재해야 한다.
	*	@post	화면에 모든 음악이 출력된다.
	*/
	void DisplayAllMusicInPlayList();

	/**
	*	@brief	playlist 비운다.
	*	@pre	초기화할 리스트가 존재해야 한다.
	*	@post	리스트의 모든 항목이 삭제된다.
	*/
	void MakePlayListEmpty();

	/**
	*	@brief	리스트를 비운다.
	*	@pre	리스트가 존재해야 한다.
	*	@post	리스트의 모든 항목이 삭제된다.
	*/
	void MakeMusicListEmpty();

private:
	int m_Command;
	ifstream m_iFile;
	ofstream m_oFile;
	SortedList<MusicType> MusicList;			//PK로 sort
	CircularQueue<SimpleMusicType> PlayList;	//최근 재생목록
};

#endif