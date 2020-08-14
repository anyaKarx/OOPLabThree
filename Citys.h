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
	std::array <std::wstring, (size_t)Citys::END> NameCity{ L" \"�����\" ",
		L" \"������\"", L"\"������\"", L"\"�����\"", L"\"����\"",
		L"\"�����������\"",L"\"���������\"", L"\"������\"", L"\"�����-���������\"",
		L"\"����\"", L"\"������\"", L"\"���-����\"", L"\"���-��������\"", };

	return NameCity[(int)city];
}