#include "SimpleMusicType.h"

int SimpleMusicType::GetSongPK() {
	return s_PK;
}

string SimpleMusicType::GetSongName() {
	return s_Name;
}

string SimpleMusicType::GetSongArtist() {
	return s_Artist;
}

void SimpleMusicType::SetSongPK(int inPK) {
	s_PK = inPK;
}

void SimpleMusicType::SetSongName(string inName) {
	s_Name = inName;
}

void SimpleMusicType::SetSongArtist(string inArtist) {
	s_Artist = inArtist;
}

void SimpleMusicType::SetSongPlayedTime(int inPlayedTime) {
	s_Played_Time += inPlayedTime;
}

void SimpleMusicType::SetSongRecord(int inPK, string inName, string inArtist) {
	SetSongPK(inPK);
	SetSongName(inName);
	SetSongArtist(inArtist);
}

void SimpleMusicType::SetSongPKFromKB() {
	cout << "\tPrimary Key : ";
	cin >> s_PK;
}

void SimpleMusicType::SetSongNameFromKB() {
	cout << "\tMusic Name  : ";
	cin >> s_Name;
}

void SimpleMusicType::SetSongArtistFromKB() {
	cout << "\tArtist Name : ";
	cin >> s_Artist;
}

void SimpleMusicType::SetSongRecordFromKB() {
	SetSongPKFromKB();
	SetSongNameFromKB();
	SetSongArtistFromKB();
}

void SimpleMusicType::DisplaySimpleSongPK() {
	cout << "\tPrimary Key : " << s_PK << '\n';
}

void SimpleMusicType::DisplaySimpleSongName() {
	cout << "\tMusic Name  : " << s_Name << '\n';
}

void SimpleMusicType::DisplaySimpleSongArtist() {
	cout << "\tArtist Name : " << s_Artist << '\n';
}

void SimpleMusicType::DisplaySimpleSongPlayedTime() {
	cout << "\tPlayed Time : " << s_Played_Time << '\n';
}

void SimpleMusicType::DisplaySimpleSongRecord() {
	DisplaySimpleSongPK();
	DisplaySimpleSongName();
	DisplaySimpleSongArtist();
	DisplaySimpleSongPlayedTime();
}

bool SimpleMusicType::operator>(SimpleMusicType data) {
	return s_PK > data.s_PK;
}

bool SimpleMusicType::operator==(SimpleMusicType data) {
	return s_PK == data.s_PK;
}

RelationType2 SimpleMusicType::Compares_PK(const SimpleMusicType& data) {
	if (this->s_PK > data.s_PK)
		return GREATER2;
	else if (this->s_PK < data.s_PK)
		return LESS2;
	else
		return EQUAL2;
}

RelationType2 SimpleMusicType::ComparePlayed_Time(const SimpleMusicType& data) {
	if (this->s_Played_Time > data.s_Played_Time)
		return GREATER2;
	else if (this->s_Played_Time < data.s_Played_Time)
		return LESS2;
	else
		return EQUAL2;
}