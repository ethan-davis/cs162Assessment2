#pragma once
#include <iomanip>
#include <fstream>
using namespace std;

// Constants
const int MAX_ENTRIES = 100;

// For Class definition
#include "game.h"

// Function Prototypes
void DisplayMenu();
void ExecuteChoice(int& menuChoice, Game aGame[], int& count);
void AddEntry(Game aGame[], int& count);
void GetStringInput(char varName[]);
int GetIntInput(int min, int max);
double GetDoubleInput(double min, double max);
void Confirm(char& addAnother);
void DisplayEntries(Game aGame[], int count);
void DeleteEntry(Game aGame[], int& count);
void writeFile(Game aGame[], int count);
void readFile(Game aGame[], int& count);
