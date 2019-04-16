#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <string>
#include <unordered_map>
#include "Sommet.h"

class graphe
{
    public:
        ///constructeur qui charge le graphe en mémoire
        graphe(std::string);
        ~graphe();
        void afficher() const;
        void enumsolu() const;

    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::unordered_map<std::string,Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::vector<std::vector<Arrete>>allsolu;
        std::vector<std::vector<Arrete>>soluadmiss;


};

#endif
