#include "Album.h"
#include <cassert>

void Album::SetAlbumTitle(std::wstring title)
{
	assert(size(title) > 1);
	this->_title = title;
}

void Album::SetAlbumYear(uint16_t year)
{
	assert(year > 0 || year < 2020);
	this->_year = year;
}


std::wstring Album::GetAlbumTitle()
{
	return this->_title;
}

uint16_t Album::GetAlbumYear()
{
	return this->_year;
}

std::vector<Song> Album::GetAlbumSongs()
{
	return this->_songs;
}

Song Album::GetSongFromAlbum(uint16_t index)
{
	return this->_songs[index];
}

Album::Album(std::wstring title, uint16_t year, std::vector<Song>& songs)
{
	this->SetAlbumTitle(title);
	this->SetAlbumYear(year);
	this->_songs.reserve(songs.size());
	std::copy(songs.begin(), songs.end(), std::back_inserter(this->_songs));
}
