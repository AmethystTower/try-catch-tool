#include <iostream>
#include <fstream>		//used for handlig files
#include <string>		//used for std::string
#include <conio.h>		//used for _getch()
#include <windows.h>	//used for Sleep()

int main()
{
	//variables
	std::string line;
	std::ifstream file;
	char result;

	//we have to enable exceptions for incase the file cannot be found. the 'exception' member function will take care of that.
	//failbit means that it's a logical error and in this case means that the file couldn't be found.
	file.exceptions(std::ios::failbit);

	for (;;)
	{
		std::cout << "Press any key to print 'example.txt' into the console.";
		_getch();

		try		//this block will likely throw an exception when something's not right.
		{
			file.open("example.txt");
			std::cout << "\n\nFile found!\nLoading text file...\n";
			Sleep(1000);

			//the problem with try-catch is the fact that we can't use file.eof() or while(std::getline(file, line)) otherwise it will throw an exception.
			for (int i = 0; i < 10; i++)
			{
				getline(file, line);
				std::cout << "\n" << line; //print the text of the example.txt to the console.
			}

			file.close();	//close the file as it's not needed anymore.

			std::cout << "\n\nPress any key to restart or press 'Enter' to exit the console.";
		}
		catch (std::ios_base::failure)	//this block will check if any of the fail flags occured and will handle the exception with a notification. 
		{
			std::cout << "\n\nThe file 'example.txt' couldn't be found in the root folder.\nPress any key to restart or press 'Enter' to exit the console.";
		}

		result = _getch();

		if (result == '\r')		//user pressed enter, exit.
			exit(1);
		else					//user pressed any other key, clear and continue loop.
			system("cls");
	}
}