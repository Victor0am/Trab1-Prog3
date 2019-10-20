#ifndef _PODCASTER_HPP
#define _PODCASTER_HPP
#include "Produtor.hpp"
#include "Podcast.hpp"
#include <vector>
using namespace std;

class Podcaster: public Produtor{
    private:
        vector<Podcast*> PodcastsLancados;
    public:
        Podcaster(string nome, int codigo);
        void imprimirNoArquivo(ofstream &outfile);
};

#endif