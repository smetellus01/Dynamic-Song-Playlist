#include <iostream>
#include <cstring>
#include <iomanip>
#include "playlist.h"

using namespace std;

Playlist::Playlist()
{
    maxSize = 5; // max amount of entries
    currentSize = 0; // current size of entry
    songList = new Song[maxSize]; // sets up entries
} 

Playlist::~Playlist()
// This destructor function for class Playlist
// deallocates the directory's list of Entry objects
{
   delete [] songList;
}

void Playlist::Insert(Song &s1)
// Insert a new playlist into the directory
{
    if(currentSize==maxSize)
    Grow();
    songList[currentSize++] = s1;
}

void Playlist::Grow()
{
  maxSize = currentSize + 5; // Determine a new size
  
  Song* newList = new Song[maxSize]; // Allocate a new array
  
  for(int i = 0; i < currentSize; i++) // Copy into each array
    newList[i] = songList[i]; // new array

  delete [] songList; // Remove the old array
 
  songList = newList; // Point to the old array
}


void Playlist::Lookup(const char* aTitle, const char* aArtist) const
{
   int thisSong = FindTitle(aTitle); // Locate the title in the directory.
   int thisSong2 = FindArtist(aArtist); // Locate the artist in the directory
	
   if (thisSong == -1) // Return if not found
	cout << aTitle << " not found in current directory\n";
   else
   {
	cout << "\nEntry found: ";
	cout << songList[thisSong]; // Display
   }
   
   if (thisSong2 == -1) // Return if not found
	cout << aArtist << " not found in current directory\n";
   else
   {
	cout << "\nEntry found: ";
	cout << songList[thisSong2]; // Display
   }
}

void Playlist::Remove(const char* aTitle)
{
    int thisSong = FindTitle(aTitle);
    
    if (thisSong == -1)
	cout << aTitle << " not found in directory";
   else
   {
	// Shift each succeding element "down" one position in the
	// Entry array, thereby deleting the desired entry.
	for (int j = thisSong + 1; j < currentSize; j++)
		songList[j - 1] = songList[j];
			
	currentSize--;		// Decrement the current number of entries.
	cout << "Entry removed.\n";
   }
}

void Playlist::DisplayPlaylist() const
{
   if (currentSize == 0)
   {
	cout << "\nCurrent directory is empty.\n";
	return;
   }
	
   // Display a header.
   cout << "\n\t***TILE***\t\t  ***ARTIST***\t\t***CATEGORY***\t***SIZE***\n\n";
	
   for (int i = 0; i < currentSize; i++)	// For each entry,
	cout << songList[i];			// send it to output
}

void Playlist::CategorySearch(char temp)
{
    int numSongs = 0; // Start number of Songs
    
    double NumSize = 0; // Start Size 
    
    if(currentSize == 0) // Check for empty playlist
    {
        cout<<"Current playlist is empty."<<endl;
    }
    
    // Display a header.
   cout << "\n\t***TILE***\t\t  ***ARTIST***\t\t***CATEGORY***\t***SIZE***\n\n";
   
   for(int i = 0; i < currentSize; i++) // Iterates playlist for category
   {
       Style test = songList[i].GetCategory(); // Allows for matching
       
       cout<<songList[test];
       
       NumSize += songList[i].GetCategory();
       
       NumSize++; // Increments variables
       numSongs++;
   }
   
   cout<<"Total Size of Playlist: "<<(NumSize / 1000)<<endl; // Outputs counts of variables
   
   cout<<"Total Amount of Songs in Category: "<<numSongs<<endl;
}

void Playlist::DisplayStorage() const
{
    double sum = 0; // Initialize to zero
    
    for(int i = 0; i < currentSize; i++) // Iterates for size
    {
     sum = sum + songList[i].GetSize(); // Calculates sum by array
    }
    
    cout<<"Total Playlist Size: "<<fixed<<setprecision(2)<<sum<<endl; // Send it to output
    
    
}

int Playlist::FindTitle(const char* aTitle) const
{
    for(int i = 0; i < currentSize; i++) // Look at each entry
        if(strcmp(songList[i].GetTitle(), aTitle) == 0)
            return i; // If found, return position and exit
    
    return -1; // Never found
}

int Playlist::FindArtist(const char* aArtist) const
{
    for(int i = 0; i < currentSize; i++) // Look at each entry
        if(strcmp(songList[i].GetArtist(), aArtist) == 0)
            return i; // If found, return position and exit
    
    return -1; // Never found
}
