#include "musictype.h"

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

string MusicType::DisplayPKOnScreen() {
    string result="";
    result = "Primary Key : " + to_string(PK) + '\n';
    return result;
}

string MusicType::DisplayNameOnScreen() {
    string result="";
    result = "Music Name  : " + Name + '\n';
    return result;
}

string MusicType::DisplayArtistOnScreen() {
    string result="";
    result = "Artist Name : " + Artist + '\n';
    return result;
}

string MusicType::DisplayAlbumOnScreen() {
    string result="";
    result = "Album Name  : " + Album + '\n';
    return result;
}

string MusicType::DisplayGenreOnScreen() {
    string result="";
    result = "Genre Name  : " + Genre + '\n';
    return result;
}

string MusicType::DisplayRecordOnScreen() {
    string result=DisplayPKOnScreen()+ DisplayNameOnScreen()+DisplayArtistOnScreen()+DisplayAlbumOnScreen()+DisplayGenreOnScreen();
    return result;
}

int MusicType::WriteDataToFile(ofstream& fout) {
    fout << '\n';
    fout << "곡 ID : " << PK << '\n';
    fout << "곡명 : " << Name << '\n';
    fout << "가수 : " << Artist << '\n';
    fout << "앨범명 : " << Album << '\n';
    fout << "장르명 : " <<Genre << '\n';

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
