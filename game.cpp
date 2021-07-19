/* game.cpp - Assessment 2 - Ethan Davis
 * This file is the implementation file for
 *  the Game class.
 */
#include "game.h"

/* Purpose: Default Constructor to load game class.
 *   Initialize member variables.
 */
Game::Game()
{
	title[0] = '\0';
	platform[0] = '\0';
	genre[0] = '\0';
	year = 0;
	rating = 0.0;
}

// Getter and Setter Game Class functions
char * Game::getTitle()
{
	return title;
}

char * Game::getPlatform()
{
	return platform;
}

char * Game::getGenre()
{
	return genre;
}

int Game::getYear()
{
	return year;
}

double Game::getRating()
{
	return rating;
}

void Game::setTitle(char sTitle[])
{
	strcpy(title, sTitle);
}

void Game::setPlatform(char sPlatform[])
{
	strcpy(platform, sPlatform);
}

void Game::setGenre(char sGenre[])
{
	strcpy(genre, sGenre);
}

void Game::setYear(int sYear)
{
	year = sYear;
}

void Game::setRating(double sRating)
{
	rating = sRating;
}
