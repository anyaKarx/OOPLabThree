#pragma once
#include <iostream>
#include <array>

struct Route
{
	uint16_t RouteNumber;
	uint16_t AverageTravelTime;
	uint16_t RepetitionRate;
	size_t NumberOfStops;
	std::array <std::wstring, 10> StopName;
};

Route ReadRouteFromConsole();
template <typename Conteiner>
int16_t FindRouteTo(Conteiner var, std::wstring stop);
void DemoRoute();

inline std::wostream& operator<<(std::wostream& os, const Route& route)
{
	os << L"������� �" << route.RouteNumber << L" ����� � �������� "
		<< route.RepetitionRate << L"���.. ������� ����������������� �������� "
		<< route.AverageTravelTime << L"���.." << std::endl
		<< L" ������� ���������:";
	for (size_t i = 0; i < route.NumberOfStops; i++)
	{
		os << route.StopName[i];
		if (i != route.NumberOfStops - 1)
		{
			os << L", ";
		}
		else
		{
			os << L".";
		}
	}
	return os;
}