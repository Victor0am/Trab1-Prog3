#ifndef _PODCASTER_HPP
#define _PODCASTER_HPP
#include "Produtor.hpp"
#include "Podcast.hpp"
#include <vector>
using namespace std;

class Podcaster:Produtor{
    private:
        vector<Podcast*> PodcastsLancados;
    public:
        void Podcaster(string nome, int codigo);
        void imprimirNoArquivo(ofstream &outfile);
};

#endif