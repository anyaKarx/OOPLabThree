#pragma once
#include <iostream>
#include <array>

enum class GenreMusic
{
	Blues,
	Vocal,
	Grunge,
	Jazz,
	Instrumental,
	Classical,
	Rock,
	Techno,
	Punk,
	HipHop,
	Chanson,
	Electronic, 
	END
};

inline std::wstring GenreNameForConsole(GenreMusic genre)
{
	std::array <std::wstring, (size_t)GenreMusic::END> NameGenre{ L" \"����\" ",
		L" \"�����\"", L"\"������\"", L"\"����\"", L"\"���������������� ������\"",
		L"\"������������ ������\"",L"\"���\"", L"\"�����\"", L"\"����\"",
		L"\"���-���\"", L"\"������\"", L"\"����������� ������\"" };

	return NameGenre[(int)genre];
}