#include "Detail.h"
#include "Route.h"

#include <array>
#include <vector>
#include <functional>

Route ReadRouteFromConsole()
{
	Route route;
	route.RouteNumber = tools::GetValidValueFromUser<uint16_t>(L"Введите номер маршрута: ",
		[](auto const& val) {return val > 0 && val < 1000; });
	std::wcout << std::endl;
	route.RepetitionRate = tools::GetValidValueFromUser<uint16_t>(L"Введите частоту маршрута: ",
		[](auto const& val) {return val > 0 && val < 1440; });
	route.AverageTravelTime = tools::GetValidValueFromUser<uint16_t>(L"\nВведите продолжительность маршрута:",
		[](auto const& val) { return val > 0; });
	route.NumberOfStops = tools::GetValidValueFromUser<size_t>(L"\nСколько остановок у маршрута? ",
		[](auto const& val) { return val > 0 && val < 11; });
	std::wcout << std::endl << L"Введите остановки.";
	for (size_t i = 0; i < route.NumberOfStops; i++)
	{
		std::wcout << std::endl << L"Введите остановку №" << i + 1 << L": ";
		route.StopName[i] = tools::GetValidStringFromUser();
	}
	return route;
}


template < typename Conteiner>
int16_t FindRouteTo(Conteiner var, std::wstring stop)
{
	int16_t count = 0;
	for (auto i : var)
	{
		count++;
		for (size_t j = 0; j < i.NumberOfStops; j++)
		{
			if (i.StopName[j] == stop)
			{
				return count;
			}
		}
	}
	if (count == (int16_t)var.size())
	{
		return count = -1;
	}
}

void DemoRoute()
{
	std::vector <Route> routes;
	for (size_t i = 0; i < 3; i++)
	{
		routes.push_back(ReadRouteFromConsole());
	}
	std::copy(routes.begin(), routes.end(), std::ostream_iterator<Route, wchar_t>(std::wcout, L"\n"));
	std::wcout << L" Какая вам нужна остановка?" << std::endl;
	std::wstring stop = tools::GetValidStringFromUser();
	int16_t index = FindRouteTo(routes, stop);
	index != -1
		? std::wcout << L" Маршрут с остановкой  " << stop << L":" << std::endl << routes[index - 1]
		: std::wcout << L" Маршрутов до этой остановки пока нет." << std::endl;

}