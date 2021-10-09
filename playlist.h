#include "song.h"

class Playlist
{

public:
    Playlist(); // Set up empty directory of entries
   ~Playlist(); // Deallocate the entry list.
   void Insert(Song &s1); // Insert an entry into the directory.
   void Lookup(const char* aTitle, const char* aArtist) const; // Look up a name in the directory.
   void CategorySearch(char temp);  // Search by category
   void Remove(const char* aTitle); // Remove an entry.
   void Update(); // Update an existing entry.
   void DisplayPlaylist() const; // Display the current directory.
   void DisplayStorage() const; // Display the current storage
  
   
   private:
   
   int maxSize, // the maximum allowable number of entries
   currentSize; // the current number of entries
   Song* songList;// pointer to the list of entries
   void Grow();	// Increase maximum size, when required.
   int FindTitle(const char* aTitle) const;	// Return index of an entry, given a title
   int FindArtist(const char* aArtist) const; // Return index of an entry, given a artist
};
