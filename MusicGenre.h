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
	std::array <std::wstring, (size_t)GenreMusic::END> NameGenre{ L" \"блюз\" ",
		L" \"вокал\"", L"\"грандж\"", L"\"джаз\"", L"\"инструментальная музыка\"",
		L"\"классическая музыка\"",L"\"рок\"", L"\"техно\"", L"\"панк\"",
		L"\"хип-хоп\"", L"\"шансон\"", L"\"электронная музыка\"" };

	return NameGenre[(int)genre];
}