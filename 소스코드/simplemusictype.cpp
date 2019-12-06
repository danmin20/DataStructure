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

string SimpleMusicType::DisplaySimpleSongPK() {
    string str="Primary Key : "+to_string(s_PK)+'\n';
    return str;
}

string SimpleMusicType::DisplaySimpleSongName() {
    string str="Music Name  : "+s_Name+'\n';
    return str;
}

string SimpleMusicType::DisplaySimpleSongArtist() {
    string str="Artist Name : "+s_Artist+'\n';
    return str;
}

string SimpleMusicType::DisplaySimpleSongPlayedTime() {
    string str="Played Time : "+to_string(s_Played_Time)+'\n';
    return str;
}

string SimpleMusicType::DisplaySimpleSongRecord() {
    string str=DisplaySimpleSongPK()
            +DisplaySimpleSongName()
            +DisplaySimpleSongArtist()
            +DisplaySimpleSongPlayedTime();
    return str;
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
