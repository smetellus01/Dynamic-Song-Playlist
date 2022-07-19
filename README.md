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
