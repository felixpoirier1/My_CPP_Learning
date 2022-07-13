#include "Movies.h"

Movies::Movies()
{
}

Movies::~Movies()
{
}

bool Movies::add_movie(std::string name, std::string rating, int watched){
    for(const Movie &movie: movies){
        if (movie.get_name()==name)
            return false;
    }
    return true;
}

bool Movies::increment_watched(std::string name){
    for(Movie &movie: movies){
        if (movie.get_name()==name)
            return true;
    }
    return false;
}

void Movies::display(){
    if(movies.size() != 0){
        std::cout << "\n==========================" << std::endl;
        for(const Movie &movie: movies){
            movie.display();
        }
        std::cout << "\n==========================" << std::endl;
    }
    else std::cout << "Sorry no movie found"<<std::endl;
}