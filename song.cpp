#include <iostream>
#include <iomanip>
#include <cstring>	
#include "song.h"

Song::Song() 
{
    // Constructor allows for class Song intialization
    strcpy(title, "");
    strcpy(artist, "");
    category = POP;
    size = 0;
}

ostream& operator<<(ostream& os, const Song& s)
{
   int i;
   
   os << '\t' << s.title;		
   // Display remaining blanks, so that data lines up on screen.
   for (i = strlen(s.title) + 1; i < 36; i++)
   os.put(' ');
	
   os << s.artist;		
   // Display remaining blanks, so that data lines up on screen.
   for (i = strlen(s.artist) + 1; i < 21; i++)
   os.put(' ');
   
   os << '\t';
   
    Style l = s.category;
    
    switch(l) // Allows for case searching of category and abbrev.
    {
    case Style::POP:
        cout<<"POP";
        break;
    
    case Style::ROCK:
        cout<<"Rock";
        break;
    
    case Style::ALTERNATIVE:
        cout<<"Alt";
        break;
    
    case Style::COUNTRY:
        cout<<"Ctry";
        break;
    
    case Style::HIPHOP:
        cout<<"HH";
        break;
    
    case Style::PARODY:
        cout<<"Par";
        break;
    }
   
   os <<setw(3)<< s.size;
   
    double megabytes = s.size / 1000;
    cout<<fixed<<setprecision(1);
   
   os << '\n';

	
	return os;

}

void Song::Set(const char* t, const char* a, Style st, int sz)
{
    // Sets the variables for intialization
    strcpy(title, t);
    strcpy(artist, a);
    category = st;
    size = sz;
}

int Song::GetSize() const // Return the size
{
    return size;
}

Style Song::GetCategory() const // Return the name of category
{
    return category;
}

const char* Song::GetTitle() const // Return the name of the title
{
    return title;
}
 const char* Song::GetArtist() const // Return the name of the artist
 {
     return artist;
}
