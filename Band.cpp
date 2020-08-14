#include "Band.h"
#include <exception>

void Band::SetBandTitle(std::wstring title)
{
	if (size(title) < 1)
	{
		throw std::exception("������� ��������");
	}
	this->_title = title;
}

void Band::SetBandDescription(std::wstring description)
{
	if (size(description) < 1)
	{
		throw std::exception("������� ��������");
	}
	this->_description = description;
}

void Band::SetBandAlbumsCount(uint16_t albumsCount)
{
	if (albumsCount <= 0)
	{
		throw std::exception("����� ������ ���� ������ 0");
	}
	this->_albumsCount = albumsCount;
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
	return this->_albumsCount;
}

Album Band::GetBandAlbum(uint16_t index)
{
	return this->_albums[index];
}

Band::Band(std::wstring title, std::wstring description, std::vector<Album>& albums)
{
	this->SetBandTitle(title);
	this->SetBandDescription(description);
	this->SetBandAlbumsCount(albums.size());
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
	songsOne.emplace_back(Song(L"������", 3, 5));
	songsOne.emplace_back(Song(L"����", 3, 4));
	songsOne.emplace_back(Song(L"������", 10, 5));
	songsOne.emplace_back(Song(L"����", 10, 3));
	std::vector<Song> songsTwo;
	songsTwo.emplace_back(Song(L"�����", 11, 5));
	songsTwo.emplace_back(Song(L"�������", 0, 6));
	songsTwo.emplace_back(Song(L"������������", 5, 5));
	songsTwo.emplace_back(Song(L"����������", 2, 2));
	songsTwo.emplace_back(Song(L"����", 8, 6));
	std::vector<Song> songsThree;
	songsThree.emplace_back(Song(L"�������", 6, 4));
	songsThree.emplace_back(Song(L"� �������", 7, 3));
	songsThree.emplace_back(Song(L"�����", 8, 4));
	songsThree.emplace_back(Song(L"�����", 7, 5));
	songsThree.emplace_back(Song(L"�����", 10, 6)); 
	std::vector<Album> albums;
	albums.emplace_back(Album(L"��������� ������", 1998, songsOne));
	albums.emplace_back(Album(L"��c�� ��� ���", 2020, songsTwo));
	albums.emplace_back(Album(L"����� �����", 2020, songsThree));
	Band anyaKar(L"���4��", L"�������� ������ ��������� ������;)", albums);
	std::vector<Song> allSongs;
	Song bu;
	Album alb;
	
	std::wcout << anyaKar << std::endl;

	if (anyaKar.FindSong(L"������", bu))
		std::wcout << L"������� �����: " << bu << std::endl;
	else
		std::wcout << L"����� ����� ���" << std::endl;

	if (anyaKar.FindAlbum(Song(L"������������", 5, 5), alb))
		std::wcout << L"����� ������������ ���� �������� � ������� " << alb.GetAlbumTitle() << std::endl;
	else
		std::wcout << L"������ ������� ���." << std::endl;

	std::wcout << L"��� ����� ��� � ����� ������:" << std::endl;
	anyaKar.GetAllGenreSongs((GenreMusic)10, allSongs);
	std::copy(allSongs.begin(), allSongs.end(), 
		std::ostream_iterator<Song, wchar_t>(std::wcout, L"\n"));

}