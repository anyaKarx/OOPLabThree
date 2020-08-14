#pragma once
#include <iostream>
#include <array>

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
	END
};

inline std::wstring CityNameForConsole(Citys city)
{
	std::array <std::wstring, (size_t)Citys::END> NameCity{ L" \"Томск\" ",
		L" \"Москва\"", L"\"Лондон\"", L"\"Минск\"", L"\"Киев\"",
		L"\"Новосибирск\"",L"\"Барселона\"", L"\"Казань\"", L"\"Санкт-Петербург\"",
		L"\"Крым\"", L"\"Анкара\"", L"\"Нью-Йорк\"", L"\"Лос-Анджелес\"", };

	return NameCity[(int)city];
}