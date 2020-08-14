#include "Flight.h"
#include "CinInputValidation.h"

#include <array>
#include <vector>
#include <cassert>
#include <functional>



void Flight::SetFlightNumber(uint16_t number)
{
	assert(number > 0 || number < 100);
	this->_number = number;
}

void Flight::SetDeparture(uint16_t departure)
{
	assert(departure > 0 || departure < (int)Citys::END);
	this->_departure = (Citys)departure;
}

void Flight::SetArrival(uint16_t arrival)
{
	assert(arrival > 0 || arrival < (int)Citys::END);
	this->_arrival = (Citys)arrival;
}

void Flight::SetFlightTime(uint16_t departureYear, uint16_t departureMonth,
		uint16_t departureDay, uint16_t departureHour, uint16_t departureMinute,
		uint16_t arrivalYear, uint16_t arrivalMonth, uint16_t arrivalDay,
		uint16_t arrivalHour, uint16_t arrivalMinute)
{
	assert(departureYear <= arrivalYear && departureMonth <= arrivalMonth);
	this->_departureTime = Time(departureYear, departureMonth, departureDay, departureHour, departureMinute);
	this->_arrivalTime = Time(arrivalYear, arrivalMonth, arrivalDay, arrivalHour, arrivalMinute);
}

uint16_t Flight::GetFlightNumber()
{
	return this->_number;
}
std::wstring Flight::GetDeparature()
{
	return CityNameForConsole(this->_departure);
}
std::wstring Flight::GetArrival()
{
	return CityNameForConsole(this->_arrival);
}
Time Flight::GetArrivalTime()
{
	return this->_arrivalTime;
}
Time Flight::GetDepartureTime()
{
	return this->_departureTime;
}

Flight::Flight(uint16_t number, uint16_t departure,
	uint16_t arrival, uint16_t departureYear, uint16_t departureMonth,
		uint16_t departureDay, uint16_t departureHour, uint16_t departureMinute,
		uint16_t arrivalYear, uint16_t arrivalMonth, uint16_t arrivalDay,
		uint16_t arrivalHour, uint16_t arrivalMinute)
{
	this->SetFlightNumber(number);
	this->SetDeparture(departure);
	this->SetArrival(arrival);
	this->SetFlightTime(departureYear, departureMonth, departureDay,
		departureHour, departureMinute, arrivalYear,
		arrivalMonth, arrivalDay, arrivalHour, arrivalMinute);
}

uint16_t Flight::GetFlightTimeMinutes()
{
	if ((this->GetArrivalTime().GetHour() > this->GetDepartureTime().GetHour()))
	{
		return((this->GetArrivalTime().GetHour() * 60
			+ this->GetArrivalTime().GetMinute())
			- (this->GetDepartureTime().GetHour() * 60
				+ this->GetDepartureTime().GetMinute()));
	}
	else
	{
		return(1440 - (this->GetDepartureTime().GetHour() * 60
			+ this->GetDepartureTime().GetMinute())
			+ this->GetArrivalTime().GetHour() * 60
			+ this->GetArrivalTime().GetMinute());
	}
}

Flight RandomGenerateInfoFlight()
{
	uint16_t numberFlight = tools::randomUI(110, 235);
	uint16_t departure = tools::randomUI(0, (uint16_t)Citys::END);
	uint16_t arrival = tools::randomUI(0, (uint16_t)Citys::END);
	uint16_t FlightTimeMinute = tools::randomUI(25, 1080);
	uint16_t randomYear = tools::randomUI(2020, 2025);
	uint16_t randomMonth = tools::randomUI(1, 12);
	uint16_t randomDay = tools::randomUI(1, 31);
	uint16_t randomHour = tools::randomUI(0, 23);
	uint16_t randomMinute = tools::randomUI(0, 59);
	uint16_t arrivalRandomYear;
	uint16_t arrivalRandomMonth;
	uint16_t arrivalRandomDay;
	uint16_t arrivalRandomHour = 0;
	uint16_t arrivalRandomMinute;
	if (FlightTimeMinute % 60 != 0)
	{
		if (randomMinute + FlightTimeMinute % 60 > 59)
		{
			arrivalRandomMinute = randomMinute + FlightTimeMinute % 60 - 59;
			arrivalRandomHour = 1;
		}
		else
			arrivalRandomMinute = randomMinute + FlightTimeMinute % 60;
	}
	else
		arrivalRandomMinute = 0;
	uint16_t countHourFlight = FlightTimeMinute / 60;
	if (countHourFlight != 0)
	{
		if (randomHour + countHourFlight > 23)
		{
			arrivalRandomHour += randomHour + countHourFlight - 24;
			arrivalRandomDay = randomDay + 1;
			if (arrivalRandomDay > 31)
			{
				arrivalRandomDay = arrivalRandomDay - 31;
				arrivalRandomMonth = randomMonth + 1;
				if (arrivalRandomMonth > 12)
				{
					arrivalRandomMonth = 1;
					arrivalRandomYear = randomYear + 1;
				}
				else
					arrivalRandomYear = randomYear;
			}
			else
			{
				arrivalRandomYear = randomYear;
				arrivalRandomMonth = randomMonth;
			}
		}
		else
		{
			arrivalRandomHour += randomHour + countHourFlight;
			arrivalRandomYear = randomYear;
			arrivalRandomMonth = randomMonth;
			arrivalRandomDay = randomDay;
		}
	}
	else
	{
		arrivalRandomHour += randomHour;
		arrivalRandomYear = randomYear;
		arrivalRandomMonth = randomMonth;
		arrivalRandomDay = randomDay;
	}
	return Flight(numberFlight, departure, arrival, randomYear,
		randomMonth, randomDay, randomHour, randomMinute,
		arrivalRandomYear, arrivalRandomMonth, arrivalRandomDay,
		arrivalRandomHour, arrivalRandomMinute);
}


void DemoFlightWithTime()
{
	std::vector<Flight> flights;
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < 10; ++i)
	{
		flights.push_back(RandomGenerateInfoFlight());
	}
	
	std::copy(flights.begin(), flights.end(), std::ostream_iterator<Flight, wchar_t>(std::wcout, L"\n"));

	for (auto i : flights)
	{
		std::wcout << L"№ " << i.GetFlightNumber() << L" "
			<< i.GetDeparature()<< L"-" << i.GetArrival()
			<< L" время полета: " << i.GetFlightTimeMinutes() / 60 << L"ч."
			<< i.GetFlightTimeMinutes() % 60 << L"мин."<<std::endl;
	}
	std::wcout << "\n";
}