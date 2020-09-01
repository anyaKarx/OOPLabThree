#pragma once
#include <iostream>
#include <array>
//TODO: грам. ошибка
enum class Citys
{
	Tomsk,
	Moscow,
	London,
	Minsk,
	Kyiv,
	Novosibirsk,
	Barcelona,
	Kazan,
	SPB,
	Krim,
	Ankara,
	NewYork,
	LosAngeles,
	END //TODO: не надо таких элементов в перечислении
};

inline std::wstring CityNameForConsole(Citys city)
{
	std::array <std::wstring, (size_t)Citys::END> NameCity{ L" \"Òîìñê\" ",
		L" \"Ìîñêâà\"", L"\"Ëîíäîí\"", L"\"Ìèíñê\"", L"\"Êèåâ\"",
		L"\"Íîâîñèáèðñê\"",L"\"Áàðñåëîíà\"", L"\"Êàçàíü\"", L"\"Ñàíêò-Ïåòåðáóðã\"",
		L"\"Êðûì\"", L"\"Àíêàðà\"", L"\"Íüþ-Éîðê\"", L"\"Ëîñ-Àíäæåëåñ\"", };

	return NameCity[(int)city];
}