#include <cctype>			// for toupper
#include <iostream>		// for cin, cout
#include "playlist.h"

using namespace std;

void ShowMenu()
// Display the main program menu.
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

char GetAChar(const char* promptString)
// Prompt the user and get a single character,
// discarding the Return character.
// Used in GetCommand.
{
   char response;			// the char to be returned
	
   cout << promptString;		// Prompt the user
   cin >> response;			// Get a char,
   response = toupper(response);	// and convert it to uppercase
   cin.get();				// Discard newline char from input.
   return response;
}

bool Legal(char c)
// Determine if a particular character, c, corresponds
// to a legal menu command.  Returns true if legal, false if not.
// Used in GetCommand.
{
	return	((c == 'A') || (c == 'F') || (c == 'D') || (c == 'S') ||
			 (c == 'C') || (c == 'Z') || (c == 'M') || (c == 'X') || (c == 'x'));
}

char GetCommand()
// Prompts the user for a menu command until a legal 
// command character is entered.  Return the command character.
// Calls GetAChar, Legal, ShowMenu.
{
   char cmd = GetAChar("\n\n>");	// Get a command character.

   while (!Legal(cmd))		// As long as it's not a legal command,
   {				// display menu and try again.
	cout << "\nIllegal command, please try again . . .";
	ShowMenu();
	cmd = GetAChar("\n\n>");
   }
   return cmd;
}

int main()
{

    Playlist z;
    
    ShowMenu();
    
    char command;
    
   do
   {
	
	command = GetCommand();		// Retrieve a command.
	
	switch (command)
	{
    case 'A': 
    {
    // Sets up song object
    Song s1; 
    
    char t[35];
    char a[20];
    
    char st;
    Style q;
    double sz;
    
    cout<<"Enter a title\n";
    cin.getline (t, 35);
    
    cout<<"Enter a artist\n";
    cin.getline (a, 20);
    
    cout<<"Enter Category\n";
    cin >> st;
    
    if (st == 'P') // Checks for st and letters
    {
        q = POP;
    }
    else if (st == 'R' || st == 'r')
    {
        q = ROCK;
    }
    else if (st == 'A' || st == 'a')
    {
        q = ALTERNATIVE;
    }
    else if (st == 'C' || st == 'c')
    {
        q = COUNTRY;
    }
    else if (st == 'H' || st == 'h')
    {
        q = HIPHOP;
    }
    else if (st == 'Y' || st =='y')
    {
        q = PARODY;
    }
    else
    {
        cout<<"Please Try Again..";
        cin>>st;
    }
    
    cout<<"Enter Size\n";
    
    cin>>sz;
    
    if(sz < 0)
    {
        cout<<"Please Try Again.. Only Positive Numbers";
        cin>>sz;
    }
    
    s1.Set(t, a, q, sz); // Utilizes setter function
    
    z.Insert(s1); // Calls for insert in playlist
    
    }
        
    break;
		
	case 'F': 
		
	    char aTitle[35];
	    char aArtist[20];
	    
	    cout << "\tType the name to be looked up, followed by <Enter>: ";
        cin.getline(aTitle, 35);
        
        cout<<"\tType the artist to be looked up, followed by <Enter>:\n";
        cin.getline(aArtist, 20);
		
	    z.Lookup(aTitle, aArtist);           	
		
	break;
		
	case 'D': 
		
	    aTitle[35];
		
	    cout << "\nType name to be removed, followed by <Enter>: ";
        cin.getline(aTitle, 35);
		
	    z.Remove(aTitle);           	
		
	break;
		
	case 'S': z.DisplayPlaylist();          break;
	
	case 'C': 
        
	    char temp;
	    
	    cout<<"\nType a category, followed by <Enter>: ";
	    cin>>temp;
	    
	    // Checks for error checking in temp
	    if(temp == 'P' || temp == 'p' || temp == 'R' || temp == 'r' || temp == 'A' || temp == 'a' || 
	    temp == 'C' || temp == 'c' || temp == 'H' || temp == 'h' || temp == 'Y' || temp == 'y')
	    {
	        z.CategorySearch(temp);
	    }
	    else
	    {
	     	cout<<"Incorrect Category Given"<<endl;
	        cin>>temp;   
	    }
		
	break;
		
	case 'Z': 
		
	    z.DisplayStorage();		
		
	break;
		
		case 'M': ShowMenu();		        break;
		case 'X':       				    break;
	
	}
   } while (command != 'X' && command != 'x'); // Error checks exit key command

   return 0;
} 
