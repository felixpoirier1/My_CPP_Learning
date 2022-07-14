#include "Movies.h"

Movies::Movies()
{
    movies = new std::vector<Movie>;
}

Movies::Movies(const Movies &source)
{
    movies = new std::vector<Movie> (*source.movies);
}

Movies::Movies(Movies &&source) noexcept
    :movies {source.movies}{
        source.movies = nullptr;
}

Movies::~Movies()
{
    delete movies;
}

bool Movies::add_movie(std::string name, std::string rating, int watched){
    for(Movie &movie: *movies){
        if(movie.get_name()==name){
            return false;
        }
    }
    Movie new_movie {name, rating, watched};
    movies->push_back(new_movie);
    return true;
}

bool Movies::increment_watched(std::string name){
    for(Movie &movie: *movies){
        if(movie.get_name()==name){
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display(){
    if(movies->size() != 0){
        std::cout<<"\n=========================="<<std::endl;
        for(Movie &movie: *movies){
            std::cout << movie.get_name() << "   " << movie.get_rating() << "   " << movie.get_watched() <<std::endl;
        }
        std::cout <<"=========================="<<std::endl;
    }
    else{
        std::cout<< "There seems to be no movies"<<std::endl;
    }
}