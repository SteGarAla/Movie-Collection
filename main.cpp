/**
 * @file main.cpp
 * @author Steven Garcia-Alamilla & Curt Lynch
 * @date 2022-10-20
 * @brief Testing Movie Collletion
 *
 * Testing how well the movie collection performs
 */

#include "library.h"
#include <iostream>

using namespace std;

int main()
{
	library l;
	std::cout << "Welcome to Movie dude's Movie Collection! You may select one of the following options: \n";

	while (true)
	{
		int input = 0;
		std::cout << "\n1 Read Movie collection from file\n"
							<< "2 Write Movie collection to file\n"
							<< "3 Print the Movie collection\n"
							<< "4 Search for a movie by title\n"
							<< "5 Search for a movie by director\n"
							<< "6 Add a movie to the Movie Collection\n"
							<< "7 Remove a movie from the Movie Collection\n"
							<< "8 Exit Movie dude's Movie Collection\n"
							<< "\nPlease enter your choice now: \n";
		std::cin >> input;
		std::cin.get();

		switch (input)
		{
		case 1: // Read from file
		{
			std::string PathToFile;
			std::cout << "Read Movies from file. \nEnter path to file:\n";
			std::getline(std::cin, PathToFile);
			std::cout << "Reading from file: " << PathToFile << std::endl;
			l.read_from_file(PathToFile);

			break;
		}
		case 2: // Write to file
		{
			std::string PathToFile;
			std::cout << "Write Movie Collection to a file. \nEnter path to file:\n";
			std::getline(std::cin, PathToFile);
			std::cout << "Writing to file: " << PathToFile << std::endl;
			l.write_to_file(PathToFile);

			break;
		}
		case 3: // print
		{
			std::cout << "Printing to stdout.\n";
			l.print();

			break;
		}
		case 4: // Search by title
		{
			std::string title;
			std::cout << "Movie Search: \nEnter movie title: \n";
			std::getline(std::cin, title);
			l.find_movie(title);

			break;
		}
		case 5: // Search by director
		{
			std::string director;
			std::cout << "Director Search: \nEnter a Director's name:\n";
			std::getline(std::cin, director);
			l.director_search(director);

			break;
		}
		case 6: // add a movie
		{
			std::string title, director, runtime, format, price, year;

			std::cout << "Add a movie:\nEnter movie Title:\n";
			std::getline(std::cin, title);
			std::cout << "Enter movie director's name:\n";
			std::getline(std::cin, director);
			std::cout << "Enter movie runtime:\n";
			std::getline(std::cin, runtime);
			std::cout << "Enter movie format:\n";
			std::getline(std::cin, format);
			std::cout << "Enter movie price:\n";
			std::getline(std::cin, price);
			std::cout << "Enter movie release year:\n";
			std::getline(std::cin, year);

			movie new_movie = {title, director, std::stoi(runtime), format, std::stof(price), std::stoi(year)};
			std::cout << "Adding movie to Collection:\n";
			l.print_movie(new_movie);
			l.insert_sorted(new_movie);

			break;
		}
		case 7: // remove a movie
		{
			std::string title;
			std::cout << "Remove movie from collection: Enter movie title:\n";
			std::getline(std::cin, title);
			std::cout << "Removing Movie:\n";
			l.remove(title);

			break;
		}
		case 8: // exit
		{
			return 0;
			break;
		}
		default:
		{
			// fix cin, try again
			std::cout << "Invalid input, try again.\n";
			std::cin.clear();
			std::cin.ignore(10, '\n');
			break;
		}
		}
		// wait to re-print menu
		std::cout << "Press enter to continue: ";
		std::cin.get();
	}
	return 0;
}
