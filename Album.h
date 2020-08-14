#pragma once
#include <iostream>
#include <array>
#include <vector>

#include "Song.h"

class Album
{
private:
	std::wstring _title;
	uint16_t _year;
	std::vector <Song> _songs;
	size_t _countSongs= _songs.size();
public:
	void SetAlbumTitle(std::wstring title);
	void SetAlbumYear(uint16_t year);

	std::wstring GetAlbumTitle();
	uint16_t GetAlbumYear();
	std::vector<Song> GetAlbumSongs();
	Song GetSongFromAlbum(uint16_t index);

	Album(std::wstring title, uint16_t year, std::vector<Song>& songs);
	Album() {}
	friend std::wostream& operator<<(std::wostream& os, const Album& album);
};

inline std::wostream& operator<<(std::wostream& os, const Album& album)
{
	 os <<L"	" <<album._title << L"(" << album._year << L") :"<<std::endl;
	 std::copy(album._songs.begin(), album._songs.end(),
		 std::ostream_iterator<Song, wchar_t>(os, L"\n"));
	 return os;
}

