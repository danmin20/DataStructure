#include "Account.h"

void Account::Run() {
	while (1) {
		m_Command = GetCommand();

		switch (m_Command) {
		case 1:
			AddMusic();
			break;
		case 2:
			DeleteMusic();
			break;
		case 3:
			MakeMusicListEmpty();
			break;
		case 4:
			SearchByPK();
			break;
		case 5:
			SearchByName();
			break;
		case 6:
			DisplayMusicByArtist();
			break;
		case 7:
			DisplayMusicByAlbum();
			break;
		case 8:
			DisplayMusicByGenre();
			break;
		case 9:
			DisplayRecentAddMusic();
			break;
		case 10:
			DisplayAllMusic();
			break;
		case 11:
			PlayMusic();
			break;
		case 12:
			DisplayAllMusicInPlayList();
			break;
		case 13:
			MakePlayListEmpty();
			break;
		case 14:
			ReadDataFromFile();
			break;
		case 15:
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Account::GetCommand() {
	int command;
	cout << '\n' << '\n';
	cout << "\t---------- 음악목록 관리 ----------\n";
	cout << "\t   1 : Add Music\n";
	cout << "\t   2 : Delete Music\n";
	cout << "\t   3 : Make Music List Empty\n";
	cout << "\t-----------------------------------\n";
	cout << "\t------ 음악목록 내 음악 검색 ------\n";
	cout << "\t   4 : Search Music By Primary Key\n";
	cout << "\t   5 : Search Music By Name\n";
	cout << "\t   6 : Display Music By Artist\n";
	cout << "\t   7 : Display Music By Album\n";
	cout << "\t   8 : Display Music By Genre\n";
	cout << "\t   9 : Display Recently Added Music\n";
	cout << "\t  10 : Display All Music\n";
	cout << "\t-----------------------------------\n";
	cout << "\t------------ 음악 재생 ------------\n";
	cout << "\t  11 : Play Music\n";
	cout << "\t-----------------------------------\n";
	cout << "\t---------- 재생목록 관리 ----------\n";
	cout << "\t  12 : Display All Music In Play List\n";
	cout << "\t  13 : Make Play List Empty\n";
	cout << "\t-----------------------------------\n";
	cout << "\t----------- 파일 입출력 -----------\n";
	cout << "\t  14 : Read Data From File\n";
	cout << "\t  15 : Write Data To File\n";
	cout << "\t   0 : LogOut\n";
	cout << "\t-----------------------------------\n";

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << '\n';

	return command;
}

int Account::AddMusic() {
	if (MusicList.IsFull()) {
		cout << "\n\tList is full\n";
		return 0;
	}

	MusicType item;
	item.SetRecordFromKB();
	item.SetAddedNum(MusicList.GetLength() + 1);
	MusicList.Add(item);

	cout << "\n\t음악이 추가되었습니다.\n";
	return 1;
}

int Account::DeleteMusic() {
	if (MusicList.IsEmpty()) {
		cout << "\n\tList is empty\n";
		return 0;
	}

	int len = MusicList.GetLength();
	MusicType item;
	cout << "\n\t삭제할 곡의 고유번호를 입력하십시오.\n";
	item.SetPKFromKB();
	MusicList.Delete(item);

	if (len > MusicList.GetLength()) {
		cout << "\n\t<======== DELETE SUCCESS! =========>" << endl;
		return 1;
	}

	cout << "\n\t<========== DELETE FAIL! ==========>" << endl;
	return 0;
}

void Account::SearchByPK() {
	cout << "\n\t찾는 곡의 고유번호를 입력하십시오.\n";
	MusicType item;
	item.SetPKFromKB();

	int n = MusicList.RetrieveBS(item);
	if (n) {
		cout << "\n\t<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "\t<====================================>" << endl;
	}
	else
		cout << "\n\t<======== ITEM Not Found!==========>" << endl;
}

void Account::SearchByName() {
	MusicType item;
	item.SetNameFromKB();

	int n = MusicList.RetrieveName(item);
	if (n) {
		cout << "\n\t<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "\t<===================================>" << endl;
	}
	else
		cout << "\n\t<======== ITEM Not Found!==========>" << endl;
}

void Account::DisplayMusicByArtist() {
	cout << "\n\t가수 이름을 입력하십시오.\n";
	MusicType artist, item;
	item.SetArtistFromKB();

	MusicList.ResetList();
	int curIdx = MusicList.GetNextItem(artist);

	cout << "\n\t<===================================>" << endl;
	while (curIdx != -1) {
		if (item.GetArtist() == artist.GetArtist()) {
			cout << '\n';
			artist.DisplayPKOnScreen();
			artist.DisplayNameOnScreen();
			artist.DisplayAlbumOnScreen();
		}
		curIdx = MusicList.GetNextItem(artist);
	}
	cout << "\t<===================================>" << endl;
}

void Account::DisplayMusicByAlbum() {
	cout << "\n\t앨범 제목을 입력하십시오.\n";
	MusicType album, item;
	item.SetAlbumFromKB();

	MusicList.ResetList();
	int curIdx = MusicList.GetNextItem(album);

	cout << "\n\t<===================================>" << endl;
	while (curIdx != -1) {
		if (item.GetAlbum() == album.GetAlbum()) {
			cout << '\n';
			album.DisplayPKOnScreen();
			album.DisplayNameOnScreen();
			album.DisplayArtistOnScreen();
		}
		curIdx = MusicList.GetNextItem(album);
	}
	cout << "\t<===================================>" << endl;
}

void Account::DisplayMusicByGenre() {
	cout << "\n\t장르 이름을 입력하십시오.\n";
	MusicType genre, item;
	item.SetGenreFromKB();

	MusicList.ResetList();
	int curIdx = MusicList.GetNextItem(genre);

	cout << "\n\t<===================================>" << endl;
	while (curIdx != -1) {
		if (item.GetGenre() == genre.GetGenre()) {
			cout << '\n';
			genre.DisplayPKOnScreen();
			genre.DisplayNameOnScreen();
			genre.DisplayArtistOnScreen();
			genre.DisplayAlbumOnScreen();
		}
		curIdx = MusicList.GetNextItem(genre);
	}
	cout << "\t<===================================>" << endl;
}

void Account::DisplayRecentAddMusic() {
	MusicType item;

	cout << "\n\t<====== RECENTLY ADDED MUSIC ======>\n\n";

	MusicList.ResetList();
	int curIdx = MusicList.GetNextItem(item);
	int len = MusicList.GetLength();

	while (curIdx != -1) {
		if (item.GetAddedNum() >= len) {
			item.DisplayRecordOnScreen();
			break;
		}
		curIdx = MusicList.GetNextItem(item);
	}
	cout << "\t<==================================>" << endl;
}

void Account::DisplayAllMusic() {
	MusicType item;

	cout << "\n\t<========== CURRENT LIST ==========>\n\n";

	MusicList.ResetList();
	int curIdx = MusicList.GetNextItem(item);

	while (curIdx != -1) {
		item.DisplayRecordOnScreen();
		cout << '\n';
		curIdx = MusicList.GetNextItem(item);
	}

	cout << "\t<==================================>" << endl;
}

void Account::PlayMusic() {
	MusicType music, item;
	item.SetNameFromKB();

	MusicList.ResetList();
	int curIdx = MusicList.GetNextItem(music);

	bool f = true;
	while (curIdx != -1) {
		if (item.GetName() == music.GetName()) {
			f = false;
			break;
		}
		curIdx = MusicList.GetNextItem(music);
	}
	
	if (f) {
		cout << "\n\t재생할 음악을 찾지 못하였습니다. 음악을 추가해 주세요.\n";
		return;
	}

	SimpleMusicType s_music;
	s_music.SetSongRecord(music.GetPK(), music.GetName(), music.GetArtist());
	s_music.SetSongPlayedTime(1);

	if (!PlayList.FindNPlus(s_music))
		PlayList.AddToPlayList(s_music);

	cout << "\n\t[ " << item.GetName() << " ] Playing..." << endl;
	cout << "\t<==================================>" << endl;

	//favoriteslist 추가 구현
}

int Account::OpenInFile(char *fileName) {
	m_iFile.open(fileName);

	if (!m_iFile)
		return 0;
	else return 1;
}

int Account::OpenOutFile(char *fileName) {
	m_oFile.open(fileName);

	if (!m_oFile)
		return 0;
	else return 1;
}

int Account::ReadDataFromFile() {
	int idx = 0;
	MusicType item;

	char filename[FILENAMESIZE];
	cout << "\n\tInput File Name : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while (!m_iFile.eof() && idx < MusicList.GetLength()) {
		item.ReadDataFromFile(m_iFile);
		MusicList.Add(item);

		idx++;
	}

	m_iFile.close();
	DisplayAllMusic();

	return 1;
}

int Account::WriteDataToFile() {
	MusicType item;

	char filename[FILENAMESIZE];
	cout << "\n\tInput File Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	MusicList.ResetList();

	int curIdx = MusicList.GetNextItem(item);

	while (curIdx != -1) {
		item.WriteDataToFile(m_oFile);
		curIdx = MusicList.GetNextItem(item);
	}

	m_oFile.close();
	return 1;
}

void Account::MakeMusicListEmpty() {
	MusicList.MakeEmpty();
}

void Account::DisplayAllMusicInPlayList() {
	PlayList.Print();
}

void Account::MakePlayListEmpty() {
	PlayList.MakeEmpty();
}