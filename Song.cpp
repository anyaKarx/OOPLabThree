#include "Song.h"
#include <cassert>

void Song::SetSongTitle(std::wstring title)
{
	assert(size(title) > 1);
	this->_title = title;
}

void Song::SetGenre(uint16_t number)
{
	this->_genre = (GenreMusic)number;
}

void Song::SetSongDuration(uint16_t duration)
{
	assert(duration >= 0);
	this->_duration = duration;
}

GenreMusic Song::GetGenre()
{
	return this->_genre;
}

std::wstring Song::GetSongTitle()
{
	return this->_title;
}

std::wstring Song::GetMusicGenre()
{
	return GenreNameForConsole(this->_genre);
}

uint16_t Song::GetSongDuration()
{
	return this->_duration;
}

Song::Song(std::wstring title, uint16_t genre, uint16_t duration)
{

	this->SetSongTitle(title);
	this->SetGenre(genre);
	this->SetSongDuration(duration);
	
}