/* a01.cpp - Assesssment 2 - Ethan Davis
 * This program allows the user to catalog
 *   and maintain a collection of video games.
 *   Updated to use Class instead of Struct.
 */

// For constants, includes and function prototypes
#include "main.h"

int main()
{
	int count = 0;
	int menuChoice = 0;
	// declare construct variable as an array
	Game aGame[MAX_ENTRIES];

	cout << "\nWelcome to Ethan's Video Game Catalog Program!\n";
	// loop until user selects 4 (Exit)
	while(menuChoice != 6)
	{
		DisplayMenu();
		ExecuteChoice(menuChoice, aGame, count);
	}
        return 0;
}

// Purpose: Displays the main menu.
void DisplayMenu()
{
	cout << "---------------------------\n";
	cout << "|        Main Menu        |\n";
	cout << "---------------------------\n";
	cout << " 1) Add Game to Collection\n";
	cout << " 2) Show all Games\n";
	cout << " 3) Delete from Collection\n";
	cout << " 4) Write Collection to a File\n";
	cout << " 5) Add Games from a File\n";
	cout << " 6) Exit\n";
	cout << " Please Enter your Choice: ";
}

/* Purpose: Ask user for a choice from the menu.
 *   Validates selection and then calls the
 * corresponding function.
 * Parameters: The menu choice, games array and
 *   the number of games in the array.
 */
void ExecuteChoice(int& menuChoice, Game aGame[], int& count)
{
	// Prompt user and validate input
	menuChoice = GetIntInput(1, 6);
	cout << endl;
	// Call function based on menu choice
	switch(menuChoice)
	{
	case 1:
		// Add games to collection
		AddEntry(aGame, count);
		break;	
	case 2:
		// Show all games in collection
		DisplayEntries(aGame, count);
		break;	
	case 3:
		// Remove game from ocllection
		DeleteEntry(aGame, count);
		break;
	case 4:
		// Write collection to file
		writeFile(aGame, count);
		break;
	case 5:
		// Read collection in from file
		readFile(aGame, count);
		break;
	case 6:
		// Exit program
		cout << "Goodbye!" << endl;
		break;
	}
}

/* Purpose: Allows user to add new entries to
 *   game collection. Validate each input with
 *   variable type specific functions.
 * Parameters: game collection, number of games
 *  in collection.
 */
void AddEntry(Game aGame[], int& count)
{
	// Temporary variables
	char tTitle[MAX_CHAR], tPlatform[MAX_CHAR], tGenre[MAX_CHAR];
	int tYear;
	double tRating;
	char addAnother = 'y';
	// loop until they select n at the prompt
	do
	{
		// Use setter functions to assign temp
		// variables to class members
		cout << "Enter Game Title: ";
		GetStringInput(tTitle);
		aGame[count].setTitle(tTitle);
		cout << "Enter Platform: ";
		GetStringInput(tPlatform);
		aGame[count].setPlatform(tPlatform);
		cout << "Enter Genre: ";
		GetStringInput(tGenre);
		aGame[count].setGenre(tGenre);
		cout << "Enter Release Year (1970-2021): ";
		// get int input with range of 1970 to 2021
		tYear = GetIntInput(1970, 2021);
		aGame[count].setYear(tYear);
		cout << "Enter Rating (5.0 Scale): ";
		// get int input with range of 1.0 to 5.0
		tRating = GetDoubleInput(1.0, 5.0);
		aGame[count].setRating(tRating);
		++count;
		cout << "\n==Entry Saved!==\n";
		// Check if user wants to continue adding to collection
		cout << "Would you like to add another (y/n)? ";
		Confirm(addAnother);
		cout << endl;
	} while(addAnother == 'y');
}

/* Purpose: Get a c-string from user input.
 *   Makes sure input is less than MAX_CHAR.
 * Parameters: variable to assign c-string
 *   to.
 */
void GetStringInput(char varName[])
{
	// load c-string into temp variable
	char tmpStr[MAX_CHAR];
	cin.getline(tmpStr, MAX_CHAR - 1);
	// Show error and prompt again if string is
	// too long.
	while(cin.fail())
	{
		// clear error state and remove \n
		// from buffer.
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Input to long! Limit to " << MAX_CHAR << " letter: ";
		cin.getline(tmpStr, MAX_CHAR - 1);
	}
	// copy c-string to varName
	strcpy(varName, tmpStr);
}

/* Purpose: Get an integer from the user.
 *   Validates input as int and within min/max range.
 * Parameters: the minimum and maximum allowed 
 *   integer input.
 * Return: Valid integer
 */
int GetIntInput(int min, int max)
{
	int num = 0;
	cin >> num;
	// Display error and prompt again if input
	// is not a int or within valid range.
	while(cin.fail() || num < min || num > max)
	{
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Please enter numbers only (";
		cout << min << "-" << max << "). Try again: ";
		cin >> num;
	}
	// Remove leftover newline from buffer
	cin.ignore(200,'\n'); 
	return num;
}

/* Purpose: Gets a double from the user.
 *   Validates input as double and within
 *   min/max range.
 * Parameters: the minimum and maximum allowed 
 *   double input.
 * Return: Valid double
 */
double GetDoubleInput(double min, double max)
{
	double num = 0;
	cin >> num;
	while(cin.fail() || num < min || num > max)
	{
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Please enter a number only (";
		cout << fixed << showpoint << setprecision(1);
		cout << min << "-" << max << "). Try again: ";
		cin >> num;
	}
	cin.ignore(200,'\n'); 
	return num;
}

/* Purpose: Gets a yes/no repsonse from user.
 *   validates input as y or n. 
 * Parameters: users answer variable name.
 */
void Confirm(char& userChar)
{
	cin >> userChar;
	// Makes sure input is a char and either y or n.
	while(cin.fail() || userChar != 'y' && userChar != 'n')
	{
		cin.clear();
		cin.ignore(200,'\n'); 
		cout << "Invalid input! Try again (y/n): ";
		cin >> userChar;
	}
	cin.ignore(200,'\n'); 
}

/* Purpose: Displays a list of all games.
 * Parameters: Game collection, number of games
 *   in collection.
 */
void DisplayEntries(Game aGame[], int count)
{
	cout << "---------------------------\n";
	cout << "|    Showing All Games    |\n";
	cout << "---------------------------\n";
	for(int i = 0; i < count; ++i)
	{
		// Include index for deletion
		cout << "\n=== Index " << i << " ===\n";
		cout << "Title: " << aGame[i].getTitle() << "\n";
		cout << "Platform: " << aGame[i].getPlatform() << "\n";
		cout << "Genre: " << aGame[i].getGenre() << "\n";
		cout << "Release Year: " << aGame[i].getYear() << "\n";
		cout << "Rating: " << aGame[i].getRating() << "\n";
	}
	cout << endl;
}

/* Purpose: Allows user to delete from collection.
 * Parameters: Game collection, number of games
 *   in collection.
 */
void DeleteEntry(Game aGame[], int& count)
{
	int deleteIndex = 0;
	char confirmDelete = 'n';
	// Alert user if there are no games to remove
	if(count == 0)
	{
		cout << "There are no games to delete!" << endl;
		return;
	}
	// Prompt user with valid range of indexes
	cout << "Enter index to delete (0-" << count - 1 << "): ";
	deleteIndex = GetIntInput(0, count - 1);
	// Confirm game title with user before deletion
	cout << "Are you sure you want to delete " << aGame[deleteIndex].getTitle();
	cout << " (y/n)? ";
	Confirm(confirmDelete);
	if(confirmDelete == 'y')
	{
		cout << aGame[deleteIndex].getTitle() << " deleted from Catalog.\n";
		cout << endl;
		// loop from deletion index 
		for(int i = deleteIndex; i < count; ++i)
		{
			// set value at each index to
			// value of index ahead of it.
			aGame[i] = aGame[i + 1];
		}
		// Decrease count by 1 to reflect deletion
		--count;
	}
}

/* Purpose: Allows user to specify a file to write game
 *  collection to.
 * Parameters: Game collection, number of games
 *   in collection.
 */
void writeFile(Game aGame[], int count)
{
        char fileName[MAX_CHAR];
        ofstream outFile;
	// Prompt user for file name
	cout << "Enter a file name to create: ";
	GetStringInput(fileName);
	// Attempt to open file
	outFile.open(fileName);
	// Display error if file did not open
        if(!outFile.is_open())
        {
                cout << "Unable to open file for writing!" << endl;
                return;
        }
	// Loop through array of class objects and write
	// member variables to file.
        for(int i = 0; i < count; ++i)
        {
                outFile << aGame[i].getTitle() << endl;
                outFile << aGame[i].getGenre() << endl;
                outFile << aGame[i].getPlatform() << endl;
                outFile << aGame[i].getYear() << endl;
                outFile << aGame[i].getRating() << endl;
        }
	cout << "== Game collection saved to: " << fileName << " ==\n";
	cout << endl;
        outFile.close();
}

/* Purpose: Allows user to specify a file to load contents
 *  into game collection.
 * Parameters: Game collection, number of games
 *   in collection.
 */
void readFile(Game aGame[], int& count)
{
	char fileName[MAX_CHAR];
        ifstream inFile;
	//Temporary Variables
	char tTitle[MAX_CHAR], tGenre[MAX_CHAR], tPlatform[MAX_CHAR];
	int tYear;
	double tRating;

	cout << "Enter the file name to read in: ";
	GetStringInput(fileName);
	inFile.open(fileName);
	while(!inFile.is_open())
	{
		cout << "Unable to open file! Check the file name and try again.";
		cout << endl;
		return;
	}
	// Loop while first C String Title is found
	while(inFile.getline(tTitle, MAX_CHAR-1)) 
	{
		// Assign contents of file to temp variables
		inFile.getline(tGenre, MAX_CHAR-1);
		inFile.getline(tPlatform, MAX_CHAR-1);
		inFile >> tYear;
		inFile.ignore(100, '\n');
		inFile >> tRating;
		inFile.ignore(100, '\n');
		// Use setter functions to assign temp
		// variables to class members
		aGame[count].setTitle(tTitle);
		aGame[count].setGenre(tGenre);
		aGame[count].setPlatform(tPlatform);
		aGame[count].setYear(tYear);
		aGame[count].setRating(tRating);
		++count;
	}
	cout << "== Games loaded from " << fileName << " into collection! == \n" << endl;
}
