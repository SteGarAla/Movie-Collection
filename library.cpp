/**
 * @file library.cpp
 * @author Steven Garcia-Alamilla & Curt Lynch
 * @date 2022-10-20
 * @brief library implementation
 * 
 * Implementing library methods
 */

#include "library.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void library::insert_sorted(movie new_movie) {

  //iterator that points to the beginning of the  list
  std::list<movie>::iterator itr = movies.begin();
  //loop that will keep pushing the itr forward until it reaches the end of list or movie being inserted has value is less than itr->title
  while(itr != movies.end() && new_movie.title.compare(itr->title) > 0){
    itr++;
  }
  movies.insert(itr,new_movie);  
}

void library::find_movie(std::string title) {
  //checks all movies
  for (movie& m : movies) {
    //if title is found as a sub-string then print the movie info
    if(m.title.find(title) != std::string::npos) {
      print_movie(m);
    }
  }
}

void library::director_search(std::string director){
  //checks all movies
  for (movie& m : movies) {
    //if director is found then return the movie info
    if(m.director == director) {
      print_movie(m);
    }
  }
}

void library::remove(std::string title) {
  //searches the list from beginning to end, if title is found then it will removed
  movies.remove_if([&](movie m){return m.title == title;});
}

void library::read_from_file(std::string path_to_file) {
  std::ifstream file;
  file.open(path_to_file);
  //will read everything as a string then convert runtime & year to int and price to float 
  std::string title, director, format, runtime, year, price;
  
  std::getline(file, title, ',');
  while(file){
    std::getline(file, director, ',');
    std::getline(file, runtime, ',');
    std::getline(file, format, ',');
    std::getline(file, price, ',');
    std::getline(file, year, ',');
    //puts info into a movie struct 'm' to pass into the inserted_sorteted function
    movie m = {title, director, std::stoi(runtime), format, std::stof(price), std::stoi(year)};
    insert_sorted(m);

    //get will help with newline character so that info is read in correctly
    file.get();
    std::getline(file, title, ',');
  }
  file.close();
}

void library::write_to_file(std::string path_to_file) {
  std::ofstream file;
  file.open(path_to_file);
  for (movie& m : movies) {
    file << m.title << ','
	 << m.director << ','
	 << m.runtime << ','
	 << m.format << ','
	 << m.price << ','
	 << m.year << ",\n";
  }
  file.close();
}

void library::push_front(movie new_movie) {
  movies.push_front(new_movie);
}

void library::push_back(movie new_movie) {
  movies.push_back(new_movie);
}

void library::print_movie(movie& m) {
  std::cout << "Title: " << std::setw(20) << std::left << m.title
	    << "  Director: " << std::setw(15) << std::left << m.director
	    << "  Runtime: " << std::setw(5) << std::left << m.runtime
	    << "  Format: " << std::setw(7) << std::left << m.format
	    << "  Price: " << std::setw(5) << std::left << m.price
	    << "  Year: " << std::setw(4) << std::left << m.year << std::endl;
}

void library::print() {
  for(movie& m : movies) {
    print_movie(m);
  }
}
