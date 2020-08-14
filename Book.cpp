#include "Book.h"
#include "CinInputValidation.h"

#include <array>
#include <vector>
#include <functional>
 
Book ReadBookFromConsol()
{
	Book book;
	std::wcout << L"������� �������� �����: ";
	book.Title = tools::GetValidStringFromUser();
	std::wcout << std::endl;
	book.YearOfIssue = tools::GetValidValueFromUser<uint16_t>(L"������� ��� ������� �����: ",
		[](auto const& val) {return val > 0 && val < 2021; });
	book.Pages = tools::GetValidValueFromUser<uint16_t>(L"\n������� ���������� �������:",
		[](auto const& val) { return val > 0; });
	book.NumberOfAuthors = tools::GetValidValueFromUser<size_t>(L"\n������� ������� � �����? ", 
		[](auto const& val) { return val > 0 && val < 11; });
	std::wcout << std::endl << L"������� ������� �����(������� � ��������) ����� enter.";
	for (size_t i = 0; i < book.NumberOfAuthors; i++)
	{
		std::wcout << std::endl << L"������� ������ �"<< i+1 << L": ";
		book.Authors[i] = tools::GetValidStringFromUser();
	}
	return book;
}

template < typename Conteiner>
int16_t FindBookByAuthor( Conteiner var, std::wstring author)
{
	int16_t count = 0;
	for (auto i : var)
	{
		count++;
		for (size_t j = 0; j < i.NumberOfAuthors; j++)
		{
			if (i.Authors[j] == author)
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

void DemoBook()
{
	std::vector <Book> books;
	for (size_t i = 0; i < 5; i++)
	{
		books.push_back(ReadBookFromConsol());
	}
	std::copy(books.begin(), books.end(), std::ostream_iterator<Book, wchar_t>(std::wcout, L"\n"));
	std::wcout << L" ����� ������ ������ �� ������ �����? " << std::endl;
	std::wstring author = tools::GetValidStringFromUser();
	int16_t index = FindBookByAuthor(books, author);
	index != -1
		? std::wcout << L" ����� ������ " << author << L":" << std::endl << books[index - 1]
	    : std::wcout << L" ���� ����� ������ ��� � ���������. "<< std::endl;
	
}