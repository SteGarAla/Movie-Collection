/**
 * @file library.h
 * @author Steven Garcia-Alamilla & Curt Lynch
 * @date 2022-10-20
 * @brief movie struct and library class definition 
 * 
 * Struct and class definition that will allow user to add info to their movie collection
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>



/**
 * struct that holds the info of a movie
 *
 * @class movie library.h "Movie-Collection/library.h"
 * @brief movie struct
 *
 */
struct movie {
  std::string title;
  std::string director;
  int runtime;
  std::string format;
  float price;
  int year;
};



/**
 * Library class which will allows for insertion/removal of data in/out of the movie collection
 *
 * @class library library.h "Movie-Collection/library.h"
 * @brief library class
 *
 */
class library {
 private:
  std::list<movie> movies; //a list of structs named "movies"


  
 public:

/**
 * Inserts the movies in alphabetical order based on directors last name
 *
 * @param movie new_movie The struct which holds the information on the movie that is going to be added
 * @pre
 * @return void 
 * @post new_movie is added in alphabetical order
 * 
 */
  void insert_sorted(movie new_movie);

/**
 * Prints all movies which contain the searched string as a substring 
 *
 * @param std::string title The movie that is being searched for
 * @pre 
 * @return void 
 * @post Movie info printed to console
 * 
 */
  void find_movie(std::string title);

/**
 * Prints information on all the movies by a given director
 *
 * @param std::string director The Director whose movies are being searched for
 * @pre 
 * @return void 
 * @post Movie info regarding the director who was searched for
 * 
 */
  void director_search(std::string director);

/**
 * Removes movie from the movie collection
 *
 * @param std::string title The movie we are wanting to remove from our collection
 * @pre 
 * @return void 
 * @post Updated List that does not contain the movie that was deleted 
 * 
 */
  void remove(std::string title);

/**
 * Reads in info regarding movies from the file and adds it into the movie collection
 *
 * @param std::string path_to_file The file which contains movie info
 * @pre 
 * @return void 
 * @post Updated list with movie info
 * 
 */
  void read_from_file(std::string path_to_file);

/**
 * tranfers the current movie collection into an output file 
 *
 * @param std::string path_to_file The file in which the current movie collection will be sent to
 * @pre 
 * @return void 
 * @post newly created output file
 * 
 */
  void write_to_file(std::string path_to_file);

/**
 * Adds in movie info to the front of the list
 *
 * @param movie new_movie Struct which holds movie info being added in
 * @pre 
 * @return void 
 * @post Movie information is at the front of the list
 * 
 */
  void push_front(movie new_movie);

/**
 * Adds in movie info to the end of the list
 *
 * @param movie new_movie struct which holds the movie info being added in
 * @pre 
 * @return void 
 * @post Movie information is at the end of the list
 * 
 */
  void push_back(movie new_movie);

/**
 * Prints movie collection to the user
 *
 * @param  
 * @pre movie info inside of the list
 * @return void 
 * @post movie collection printed to user
 * 
 */
  void print();

/**
 * Helper function which allows the printing of a SINGLE movie (helpful when we need info on one movie and not the whole list)
 *
 * @param movie& m The  struct address containing the information of the movie to be printed
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void print_movie(movie& m);
};
#endif //LIBRARY_H
