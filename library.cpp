#include "library.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void print_movie(movie to_print);

library::library() {
  
}

library::~library() {

}

// TODO: make it actually sort things.
void library::insert_sorted(movie new_movie) {
  movies.push_back(new_movie);
}

void library::find_movie(std::string title) {
  for (movie& m : movies) {
    if(m.title.find(title) != std::string::npos) {
      print_movie(m);
    }
  }
}

void library::director_search(std::string director) {
  for (movie& m : movies) {
    if(m.director == director) {
      print_movie(m);
    }
  }
}

void library::remove(std::string title) {
  movies.remove_if([&](movie m){return m.title == title;});
}

void library::read_from_file(std::string path_to_file) {
  std::ifstream file;
  file.open(path_to_file);
  std::string title, director, format, runtime, year, price;

  std::getline(file, title, ',');
  while(file){
    std::getline(file, director, ',');
    std::getline(file, runtime, ',');
    std::getline(file, format, ',');
    std::getline(file, price, ',');
    std::getline(file, year, ',');

    movie m = {title, director, std::stoi(runtime), format, std::stof(price), std::stoi(year)};
    insert_sorted(m);

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
