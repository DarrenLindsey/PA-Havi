/* Look for Text To Speech */




#include <iostream>
#include <sapi.h>
#include <string>
#include "ClearScreen.h"
#include <fstream>
/////////////////////////////////////////////////////////////////////////

using std::cout;
using std::string;
using std::cin;
using std::ofstream;
using std::ifstream;

//Global Variables
string UserName;

//Prototyping the functions
void LoadingScreen();
void TellMeAStory();
void Menu();


int main()
{
	//Make a menu
	LoadingScreen();
	Sleep(2000);
	ClearScreen();
	Menu();

	return 0;
}


void LoadingScreen()
{


	cout << "\b What is your name?\n";

	ofstream UserInfo("Config.cfg");
	if (UserInfo.is_open())
	{
		cin >> UserName;
		UserInfo << UserName;
		UserInfo.close();
	}
	else cout << "Unable to locate  Config.cfg";

	//cin >> UserName;
	ClearScreen();

	cout << "Processing new user\n" << ifstream("Config.cfg").rdbuf();
}

void TellMeAStory()
{

	string WordBank[6] = { "NounA","ColorA","ExclamationA","ColorB","NounB","NameA" };

	cout << " Cool, " << ifstream("Config.cfg").rdbuf() << " lets play a quick story game! \n";
	cout << " Give me two nouns\n:";
	cin >> WordBank[0] >> WordBank[4];
	ClearScreen();
	cout << " How about a couple colors as well?\n";
	cin >> WordBank[1] >> WordBank[3];
	ClearScreen();
	cout << " Now give me an exclamation!\n:";
	cin >> WordBank[2];
	ClearScreen();
	cout << " And finally " << ifstream("Config.cfg").rdbuf() << " We have made it to the end!\n "
		<< "I need a name\n:";
	cin >> WordBank[5];
	ClearScreen();
	cout << " \t\tHere is your story\n\n";
	cout << " There once was a " << WordBank[0] << ", who lived in the tree tops.\n"
		<< " One day the " << WordBank[0] << " found other " << WordBank[0] << "'s who were " << WordBank[3] << ".\n"
		<< " All the other " << WordBank[0] << "'s stared and said " << WordBank[2] << "!, you are " << WordBank[1] << "\n"
		<< " and we are " << WordBank[3] << ". You must have stuck in the myterious " << WordBank[4] << " Forest. \n"
		<< " All hail the great " << WordBank[5] << ".";
	Sleep(20000);
	ClearScreen();
	cout << " Bad story right " << ifstream("Config.cfg").rdbuf() << ", I am an infantile Digital Entity.";
	Sleep(5000);
	ClearScreen();
	cout << " For now";




	//Debug Code.display the array to verify that the strings are changing. 
	//for (int i = 0; i < 6; i++)
		//cout << WordBank[i];






}

void Menu()
{
	char Choice;

	cout << " Welcome to my "<< ifstream("Config.cfg").rdbuf() <<", I am Havi.\n\n"
		<< " Please pick from the options below.\n\n";

	do
	{
		//Current options

		cout << "A) Change User Name:\n"
			<< "B) Tell me a story (experimental):\n"
			<< "C) End program:\n:";

		//get choice
		cin >> Choice;

		switch (Choice)
		{
		case 'a':
			ClearScreen();
			cout << "A) What would you like me to call you now\n:";
			cin >> UserName;
			ClearScreen();
			cout << " Processing....\n";
			Sleep(2000);
			cout << " New username " << UserName << " is asigned\n";
			Sleep(1500);
			ClearScreen();
			break;

		case 'b':
			ClearScreen();
			TellMeAStory();
			break;

		case 'c':
			ClearScreen();
			cout << " Shuting down in ";
			Sleep(1500);
			ClearScreen();

			cout << "3";
			Sleep(1500);
			ClearScreen();


			cout << "2";
			Sleep(1500);
			ClearScreen();
			cout << "1";
			ClearScreen();

			break;
		}
	} while (Choice != 'c');






}


