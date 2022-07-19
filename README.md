# Project: Dynamic Song Playlist
## Introduction
A program consisting of two classes, a Playlist class which will dynamically manage an allocated array of song objects. 

Playlist Class Uses:

- Managing the play list. This includes adding or deleting songs.
- Playing from the specific playlist. This includes keep tracking of playlist progress and size.

Song Class Uses:

- Creates Song objects consisting of song style, artist, category, and size.
- Allows for song searching based on category (abbreviations).

## Program Details
With the role of a dynamically allocated array, the program supports array resizing when unused slots in the array go above five. This will force the array to resize by adding five more slots. A deallocation method is also present for protection against memory leaks and memory management maintenance.

**Functions** 

1. **SongInsert**
- Checks if playlist has enough space and inserts a Song ovject into the directory

2. **Grow**
- Allows for array resizing by increasing by 5 slots and deleting the old array

3. **Lookup**
- Locates the title of songs by using title and artist (const char* parameters) in the songList

4. **Remove**
- Locates the song by iterating through songList and will be removed if the value is found as True

5. **DisplayPlaylist**
- Displays the songList with descriptors such as Title, Artist, Category, Size

6. **CategorySearch**
- Utilizes a getter function (.GetCategory();) and increments NumSize
- Function also keeps track of Playlist size and total amount of songs

7. **FindTitle / FindArtist**
- Iterates through songlist and utilizes .GetTitle / .GetArtist to match with a True value

## Playlist Menu

```
void ShowMenu()
{
   cout << "\n\t\t*** PLAYLIST MENU ***";
   cout << "\n\tA \tAdd a song to the playlist";
   cout << "\n\tF \tFind a song on the playlist";
   cout << "\n\tD \tRemove an entry from the playlist";
   cout << "\n\tS \tShow the entire playlist";
   cout << "\n\tC \tCategory summary";
   cout << "\n\tZ \tShow playlist size";
   cout << "\n\tM \tShow this menu";
   cout << "\n\tX \tExit the program";
}
```
- Created an interactive menu for the Song and Playlist classes that included error checking pathways and allowed for extensive search conditions for the playlist directory.

```
case 'F': 
		
	    char aTitle[35];
	    char aArtist[20];
	    
	    cout << "\tType the name to be looked up, followed by <Enter>: ";
        cin.getline(aTitle, 35);
        
        cout<<"\tType the artist to be looked up, followed by <Enter>:\n";
        cin.getline(aArtist, 20);
		
	    z.Lookup(aTitle, aArtist);           	
		
break;
```
- **Example:** The user would be prompted with messages such as the one above to help guide their search. The program utilizes chars with character limits to store the song traits for Lookup.
