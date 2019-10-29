#ifndef _PODCASTER_HPP
#define _PODCASTER_HPP
#include "Produtor.hpp"
#include "Podcast.hpp"
#include <vector>
using namespace std;

class Podcaster: public Produtor{
    public:
        Podcaster(string nome, int codigo, char tipo);
        ~Podcaster();
};

#endif