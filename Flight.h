#pragma once
#include <iostream>

#include "Citys.h"
#include "TIme.h"


class Flight
{
private:
	uint16_t _number;
	Citys _departure;
	Citys _arrival;
	Time _departureTime;
	Time _arrivalTime;

public:
	void SetFlightNumber(uint16_t number);
	void SetDeparture(uint16_t departure);
	void SetArrival(uint16_t arrival);
	void SetFlightTime(uint16_t departureYear, uint16_t departureMonth, 
		uint16_t departureDay, uint16_t departureHour, uint16_t departureMinute,
		uint16_t arrivalYear, uint16_t arrivalMonth, uint16_t arrivalDay,
		uint16_t arrivalHour, uint16_t arrivalMinute);

	uint16_t GetFlightNumber();
	std::wstring GetDeparature();
	std::wstring GetArrival();
	Time GetArrivalTime();
	Time GetDepartureTime();
	uint16_t GetFlightTimeMinutes();

	Flight() {};
	Flight(uint16_t number, uint16_t departure,
		uint16_t arrival, uint16_t departureYear, uint16_t departureMonth,
		uint16_t departureDay, uint16_t departureHour, uint16_t departureMinute,
		uint16_t arrivalYear, uint16_t arrivalMonth, uint16_t arrivalDay,
		uint16_t arrivalHour, uint16_t arrivalMinute);
	friend std::wostream& operator<<(std::wostream& os, const Flight& flight);
};


inline std::wostream& operator<<(std::wostream& os, const Flight& flight)
{
	return os << L"Рейс №" << flight._number << L" " << CityNameForConsole(flight._departure)
		<< L"-" << CityNameForConsole(flight._arrival)
		<< L". Время отправления: " << flight._departureTime
		<< L" Время прибытия:" << flight._arrivalTime;
}

void DemoFlightWithTime();