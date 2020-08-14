#pragma once
#include <iostream>
#include <array>

struct Book
{
	std::wstring Title;
	uint16_t YearOfIssue;
	uint16_t Pages;
	size_t NumberOfAuthors;
	std::array <std::wstring, 10> Authors;
};

void DemoBook();
Book ReadBookFromConsol();
template < typename Conteiner>
int16_t FindBookByAuthor( Conteiner var, std::wstring author);

inline std::wostream& operator<<(std::wostream& os, const Book& book)
{
	for (size_t i = 0; i < book.NumberOfAuthors; i++)
	{
		std::wcout << book.Authors[i];
		if (i != book.NumberOfAuthors - 1)
		{
			std::wcout << L", ";
		}
		else
		{
			std::wcout << L".";
		}
	}
	return os << L"\"" << book.Title << L"\"." << book.YearOfIssue
		<< L". -" << book.Pages << "c." << std::endl;
}