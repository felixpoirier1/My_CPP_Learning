#include "Movies.h"
#include <vector>
#include <string>
//Constructor
Movies::Movies(){
    movies = new std::vector<Movie>;
}

//Copy constructor
Movies::Movies(const Movies &source){
    movies = new std::vector<Movie> (*source.movies);
}

//Move constructor
Movies::Movies(Movies &&source) 
    : movies {source.movies}{
    source.movies = nullptr;
}

//Destructor
Movies::~Movies(){
    delete movies;
}

bool Movies::add_movie(std::string name, std::string rating, int watched){
    for(Movie &movie: *movies){
        if (movie.get_name()==name)
            return false;
    }
    Movie new_movie{name, rating, watched};
    movies->push_back(new_movie);
    return true;
}

bool Movies::increment_watched(std::string name){
    for(Movie &movie: *movies){
        if (movie.get_name()==name)
            return true;
    }
    return false;
}

void Movies::display(){
    if(movies->size() != 0){
        std::cout << "\n==========================" << std::endl;
        for(const Movie &movie: *movies){
            movie.display();
        }
        std::cout << "\n==========================" << std::endl;
    }
    else std::cout << "Sorry no movie found"<<std::endl;
}