#include "Band.h"
#include <exception>

void Band::SetBandTitle(std::wstring title)
{
	if (size(title) < 1)
	{
		throw std::exception("Ââåäèòå íàçâàíèå");
	}
	this->_title = title;
}

void Band::SetBandDescription(std::wstring description)
{
	if (size(description) < 1)
	{
		throw std::exception("Ââåäèòå îïèñàíèå");
	}
	this->_description = description;
}


std::wstring Band::GetBandTitle()
{
	return this->_title;
}

std::wstring Band::GetBandDescription()
{
	return this->_description;
}

uint16_t Band::GetBandAlbumsCount()
{
	return this->_albums.size();
}

Album Band::GetBandAlbum(uint16_t index)
{
	return this->_albums[index];
}

Band::Band(std::wstring title, std::wstring description, std::vector<Album>& albums)
{
	this->SetBandTitle(title);
	this->SetBandDescription(description);
	std::copy(albums.begin(), albums.end(), std::back_inserter(this->_albums));
}


bool Band::FindSong(std::wstring songTitle, Song& find)
{

	for (Album& i: this->_albums)
	{
		for (Song& j: i.GetAlbumSongs())
		{
			if (j.GetSongTitle() == songTitle)
			{
				find = j;
				return true;
			}
		}
	}
	return false;
}

bool Band::FindAlbum(Song song, Album& album)
{
	for (Album& i : this->_albums)
	{
		for (Song& j : i.GetAlbumSongs())
		{
			if (j.GetSongTitle() == song.GetSongTitle())
			{
				album  = i;
				return true;
			}
		}
	}
	return false;
}

void Band::GetAllSongs(std::vector<Song>& allSongs)
{

	for (auto i : this->_albums)
	{
		for (auto j : i.GetAlbumSongs())
		{
			allSongs.emplace_back(j);
		}
	}
}

void Band::GetAllGenreSongs(GenreMusic findingGenre,
	std::vector<Song>& allSongs)
{
	for (auto i : this->_albums)
	{
		for (auto j : i.GetAlbumSongs())
		{
			if(j.GetGenre() == findingGenre)
				allSongs.emplace_back(j);
		}
	}
}

void DemoBand()
{
	std::vector<Song> songsOne;
	songsOne.emplace_back(Song(L"Ëÿëÿëÿ", 3, 5));
	songsOne.emplace_back(Song(L"Îîîî", 3, 4));
	songsOne.emplace_back(Song(L"Ãðóñòü", 10, 5));
	songsOne.emplace_back(Song(L"Áîëü", 10, 3));
	std::vector<Song> songsTwo;
	songsTwo.emplace_back(Song(L"Î÷åíü", 11, 5));
	songsTwo.emplace_back(Song(L"Õîðîøàÿ", 0, 6));
	songsTwo.emplace_back(Song(L"ëàáîðàòîðíàÿ", 5, 5));
	songsTwo.emplace_back(Song(L"ïîëó÷èëàñü", 2, 2));
	songsTwo.emplace_back(Song(L"Óðàà", 8, 6));
	std::vector<Song> songsThree;
	songsThree.emplace_back(Song(L"Ïåñåíêà", 6, 4));
	songsThree.emplace_back(Song(L"Î ñ÷àñòüå", 7, 3));
	songsThree.emplace_back(Song(L"ïåñíÿ", 8, 4));
	songsThree.emplace_back(Song(L"áîìáà", 7, 5));
	songsThree.emplace_back(Song(L"îãîíü", 10, 6)); 
	std::vector<Album> albums;
	albums.emplace_back(Album(L"Ïå÷àëüíàÿ ïå÷àëü", 1998, songsOne));
	albums.emplace_back(Album(L"Ïåcíè ïðî ÎÎÏ", 2020, songsTwo));
	albums.emplace_back(Album(L"Ïîñëå ñäà÷è", 2020, songsThree));
	Band anyaKar(L"Àíå4êà", L"îñíîâàíà ëó÷øèì ñòóäåíòîì òóñóðà;)", albums);
	std::vector<Song> allSongs;
	Song bu;
	Album alb;
	
	std::wcout << anyaKar << std::endl;

	if (anyaKar.FindSong(L"Ãðóñòü", bu))
		std::wcout << L"Èñêîìàÿ ïåñíÿ: " << bu << std::endl;
	else
		std::wcout << L"Òàêîé ïåñíè íåò" << std::endl;

	if (anyaKar.FindAlbum(Song(L"ëàáîðàòîðíàÿ", 5, 5), alb))
		std::wcout << L"Ïåñíÿ ëàáîðàòîðíàÿ áûëà âûïóùåíà â àëüáîìå " << alb.GetAlbumTitle() << std::endl;
	else
		std::wcout << L"Òàêîãî àëüáîìà íåò." << std::endl;

	std::wcout << L"Âñå ïåñíè Àíè â æàíðå øàíñîí:" << std::endl;
	anyaKar.GetAllGenreSongs((GenreMusic)10, allSongs);
	std::copy(allSongs.begin(), allSongs.end(), 
		std::ostream_iterator<Song, wchar_t>(std::wcout, L"\n"));

}
//TODO: во всем проекте зашакаленная кириллица (видно даже через github). Разобраться с кодировками файлов исходного кода + поправить текст