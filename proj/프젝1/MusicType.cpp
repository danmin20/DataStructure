#include "MusicType.h"

int MusicType::GetPK() {
	return PK;
}

string MusicType::GetName() {
	return Name;
}

string MusicType::GetArtist() {
	return Artist;
}

string MusicType::GetAlbum() {
	return Album;
}

string MusicType::GetGenre() {
	return Genre;
}

int MusicType::GetAddedNum() {
	return Added_Num;
}

void MusicType::SetPK(int inPK) {
	PK = inPK;
}

void MusicType::SetName(string inName) {
	Name = inName;
}

void MusicType::SetArtist(string inArtist) {
	Artist = inArtist;
}

void MusicType::SetAlbum(string inAlbum) {
	Album = inAlbum;
}

void MusicType::SetGenre(string inGenre) {
	Genre = inGenre;
}

void MusicType::SetAddedNum(int inAddedNum) {
	Added_Num = inAddedNum;
}

void MusicType::SetRecord(int inPK, string inName, string inArtist, string inAlbum, string inGenre) {
	SetPK(inPK);
	SetName(inName);
	SetArtist(inArtist);
	SetAlbum(inAlbum);
	SetGenre(inGenre);
}

void MusicType::DisplayPKOnScreen() {
	cout << "\tPrimary Key : " << PK << '\n';
}

void MusicType::DisplayNameOnScreen() {
	cout << "\tMusic Name  : " << Name << '\n';
}

void MusicType::DisplayArtistOnScreen() {
	cout << "\tArtist Name : " << Artist << '\n';
}

void MusicType::DisplayAlbumOnScreen() {
	cout << "\tAlbum Name  : " << Album << '\n';
}

void MusicType::DisplayGenreOnScreen() {
	cout << "\tGenre Name  : " << Genre << '\n';
}

void MusicType::DisplayRecordOnScreen() {
	DisplayPKOnScreen();
	DisplayNameOnScreen();
	DisplayArtistOnScreen();
	DisplayAlbumOnScreen();
	DisplayGenreOnScreen();
}

void MusicType::SetPKFromKB() {
	cout << "\tPrimary Key : ";
	cin >> PK;
}

void MusicType::SetNameFromKB() {
	cout << "\tMusic Name  : ";
	cin >> Name;
}

void MusicType::SetArtistFromKB() {
	cout << "\tArtist Name : ";
	cin >> Artist;
}

void MusicType::SetAlbumFromKB() {
	cout << "\tAlbum Name  : ";
	cin >> Album;
}

void MusicType::SetGenreFromKB() {
	cout << "\tGenre Name  : ";
	cin >> Genre;
}

void MusicType::SetRecordFromKB() {
	SetPKFromKB();
	SetNameFromKB();
	SetArtistFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
}

int MusicType::ReadDataFromFile(ifstream& fin) {
	fin >> PK;
	fin >> Name;
	fin >> Artist;
	fin >> Album;
	fin >> Genre;

	return 1;
}

int MusicType::WriteDataToFile(ofstream& fout) {
	fout << '\n';
	fout << PK << ' ';
	fout << Name << ' ';
	fout << Artist << ' ';
	fout << Album << ' ';
	fout << Genre << ' ';

	return 1;
}

RelationType MusicType::Compares_PK(const MusicType& data) {
	if (this->PK > data.PK)
		return GREATER;
	else if (this->PK < data.PK)
		return LESS;
	else
		return EQUAL;
}

DifferentType MusicType::CompareName(const MusicType& data) {
	if (this->Name != data.Name)
		return DIFFERENT;
	else
		return SAME;
}