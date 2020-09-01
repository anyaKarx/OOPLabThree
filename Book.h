#pragma once
#include <iostream>
#include <array>

struct Book
{
	std::wstring Title;
	uint16_t YearOfIssue;
	uint16_t Pages;
	size_t NumberOfAuthors; //TODO: правильнее будет AuthorsCount - и как оборот родительного падежа, и как использование слова Count вместо Number. Of - нежелательное
	std::array <std::wstring, 10> Authors; //TODO: раз взялась использовать структуры данных вместо простых массивов, тогда меняй array на vector или list. Поле с количеством авторов при этом можно удалять, так как правильное количество авторов будет храниться в самом списке
};

void DemoBook();
Book ReadBookFromConsol(); //TODO: грам. ошибка
template < typename Conteiner> //TODO: грам. ошибка, лишние пробелы
int16_t FindBookByAuthor( Conteiner var, std::wstring author); //TODO: лишние пробелы

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