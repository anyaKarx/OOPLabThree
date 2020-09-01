#pragma once
#include <iostream>
#include <array>
#include <vector>

#include "Album.h"

class Band
{
private:
	std::wstring _title;
	std::wstring _description;
	std::vector <Album> _albums;
public:
	void SetBandTitle(std::wstring title); //TODO: слово Band
	void SetBandDescription(std::wstring description);

	std::wstring GetBandTitle();
	std::wstring GetBandDescription();
	uint16_t GetBandAlbumsCount();
	Album GetBandAlbum(uint16_t index);

	bool FindSong(std::wstring songTitle, Song& find);
	bool FindAlbum(Song song, Album& album);
	void GetAllSongs(std::vector<Song>& allSongs);
	void GetAllGenreSongs(GenreMusic findingGenre,
		std::vector<Song>& allSongs);

	Band(std::wstring title, std::wstring description, std::vector<Album>& albums);
	Band() {};
	friend std::wostream& operator<<(std::wostream& os, const Band& band);
};

inline std::wostream& operator<<(std::wostream& os, const Band& band)
{
	os << L" Ãðóïïà:" <<band._title << std::endl << L". Îïèñàíèå:  "
		<< band._description << std::endl << L". Àëüáîìû:"<<std::endl;
	std::copy(band._albums.begin(), band._albums.end(),
		std::ostream_iterator<Album, wchar_t>(os, L"\n"));
	return os;
}
void DemoBand();