#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>

struct movie {
  std::string title;
  std::string director;
  int runtime;
  std::string format;
  float price;
  int year;
};

class library {
 private:
  std::list<movie> movies;

 public:
  library();
  ~library();
  void insert_sorted(movie new_movie);
  void find_movie(std::string title);
  void director_search(std::string director);
  void remove(std::string title);
  void read_from_file(std::string path_to_file);
  void write_to_file(std::string path_to_file);
  void push_front(movie new_movie);
  void push_back(movie new_movie);
  void print();
  void print_movie(movie& m);
};
#endif //LIBRARY_H
