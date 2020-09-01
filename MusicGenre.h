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
	END //TODO: не надо таких значений в перечислении
};

inline std::wstring GenreNameForConsole(GenreMusic genre)
{
	std::array <std::wstring, (size_t)GenreMusic::END> NameGenre{ L" \"áëþç\" ",
		L" \"âîêàë\"", L"\"ãðàíäæ\"", L"\"äæàç\"", L"\"èíñòðóìåíòàëüíàÿ ìóçûêà\"",
		L"\"êëàññè÷åñêàÿ ìóçûêà\"",L"\"ðîê\"", L"\"òåõíî\"", L"\"ïàíê\"",
		L"\"õèï-õîï\"", L"\"øàíñîí\"", L"\"ýëåêòðîííàÿ ìóçûêà\"" };

	return NameGenre[(int)genre];
}