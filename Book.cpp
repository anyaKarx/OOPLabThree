#include "Book.h"
#include "CinInputValidation.h"

#include <array>
#include <vector>
#include <functional>
 
Book ReadBookFromConsol()
{
	Book book;
	std::wcout << L"¬ведите название книги: ";
	book.Title = tools::GetValidStringFromUser();
	std::wcout << std::endl;
	book.YearOfIssue = tools::GetValidValueFromUser<uint16_t>(L"¬ведите год издани€ книги: ",
		[](auto const& val) {return val > 0 && val < 2021; });
	book.Pages = tools::GetValidValueFromUser<uint16_t>(L"\n¬ведите количество страниц:",
		[](auto const& val) { return val > 0; });
	book.NumberOfAuthors = tools::GetValidValueFromUser<size_t>(L"\n—колько авторов у книги? ", 
		[](auto const& val) { return val > 0 && val < 11; });
	std::wcout << std::endl << L"¬ведите авторов книги(фамилию и инициалы) через enter.";
	for (size_t i = 0; i < book.NumberOfAuthors; i++)
	{
		std::wcout << std::endl << L"¬ведите автора є"<< i+1 << L": ";
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
	std::wcout << L"  нигу какого автора вы хотите найти? " << std::endl;
	std::wstring author = tools::GetValidStringFromUser();
	int16_t index = FindBookByAuthor(books, author);
	index != -1
		? std::wcout << L"  нига автора " << author << L":" << std::endl << books[index - 1]
	    : std::wcout << L"  ниг этого автора нет в коллекции. "<< std::endl;
	
}