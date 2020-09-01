#pragma once
#include <iostream>
#include <array>

struct Route
{
	uint16_t RouteNumber;
	uint16_t AverageTravelTime;
	uint16_t RepetitionRate;
	size_t NumberOfStops; //TODO: от поля избавиться
	std::array <std::wstring, 10> StopName; //TODO: заменить на вектор или список
};

Route ReadRouteFromConsole();
template <typename Conteiner> //TODO: грамошибка
int16_t FindRouteTo(Conteiner var, std::wstring stop);
void DemoRoute();

inline std::wostream& operator<<(std::wostream& os, const Route& route)
{
	os << L"Ìàðøðóò ¹" << route.RouteNumber << L" õîäèò ñ ÷àñòîòîé "
		<< route.RepetitionRate << L"ìèí.. Ñðåäíÿÿ ïðîäîëæèòåëüíîñòü ìàðøðóòà "
		<< route.AverageTravelTime << L"ìèí.." << std::endl
		<< L" Ìàðøðóò ïðîåçæàåò:";
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