#pragma once
#include <iostream>
#include <cstring>

// Constants
const int MAX_CHAR = 60;

/*  Class:  Information for video game entry
    Members:
    *   variables:
    *      title: c-string: Title of video game
    *      platform: c-string: system the game
    *	   	is played on.
    *      genre: c-string: genre of game
    *	   year: int: relase year of game
    *      raiting: double: user rating of game 
    *	   	on a 5.0 scale
    *   functions:
    *      Game(): default constructor
    *      Game(parameters): parameterized constructor
    */
class Game
{
	public:
		// Constructors
		// Default:
		Game();
		// Parameterized:
		Game(char sTitle[], char sPlatform[], char sGenre[], int sYear, double sRating);

		// Getters
		char * getTitle();
		char * getPlatform();
		char * getGenre();
		int getYear();
		double getRating();

		// Setters
		void setTitle(char sTitle[]);
		void setPlatform(char sPlatform[]);
		void setGenre(char sGenre[]);
		void setYear(int sYear);
		void setRating(double sRating);

	private:
		char title[MAX_CHAR];
		char platform[MAX_CHAR];
		char genre[MAX_CHAR];
		int year = 0;
		double rating = 0;
};

