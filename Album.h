﻿#pragma once
//TODO: папка файлов заголовков в проекте не должна лежать внутри папки "Исходные файлы"
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
public:
	void SetAlbumTitle(std::wstring title); //TODO: не надо слово Album в названиях методов и полей. Иначе получаются конструкции типа Album.AlbumTitle
	void SetAlbumYear(uint16_t year);

	std::wstring GetAlbumTitle();
	uint16_t GetAlbumYear();
	std::vector<Song> GetAlbumSongs();
	Song GetSongFromAlbum(uint16_t index);

	Album(std::wstring title, uint16_t year, std::vector<Song>& songs);
	Album() = default;
	friend std::wostream& operator<<(std::wostream& os, const Album& album);
};

inline std::wostream& operator<<(std::wostream& os, const Album& album)
{
	 os <<L"	" <<album._title << L"(" << album._year << L") :"<<std::endl;
	 std::copy(album._songs.begin(), album._songs.end(),
		 std::ostream_iterator<Song, wchar_t>(os, L"\n"));
	 return os;
}

