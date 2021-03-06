﻿#pragma once
#include <iostream>
#include <array>

#include "MusicGenre.h"

class Song
{
private:
	std::wstring _title;
	GenreMusic _genre;
	uint16_t _duration;

public:
	void SetSongTitle(std::wstring title); //TODO: именование
	void SetGenre(uint16_t number);
	void SetSongDuration(uint16_t duration); //TODO: именование - и так понятно, что это продолжительность песни

	std::wstring GetSongTitle(); //TODO: именование
	std::wstring GetMusicGenre();
	GenreMusic GetGenre();
	uint16_t GetSongDuration(); //TODO: именование

	Song(std::wstring title, uint16_t duration, uint16_t number);
	Song() {}
	friend std::wostream& operator<<(std::wostream& os, const Song& song);
};

inline std::wostream& operator<<(std::wostream& os, const Song& song)
{
	return os << song._title << L" (" << GenreNameForConsole(song._genre) << L")"
		<<  L" - " << song._duration << L"ìèí.";
}
