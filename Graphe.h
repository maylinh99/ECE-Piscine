#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <string>
#include <unordered_map>
#include "Sommet.h"

class graphe
{
    public:
        ///constructeur qui charge le graphe en m�moire
        graphe(std::string);
        ~graphe();
        void afficher() const;
        void enumsolu() const;

    protected:

    private:
        /// Le r�seau est constitu� d'une collection de sommets
        std::unordered_map<std::string,Sommet*> m_sommets;//stock�e dans une map (cl�=id du sommet, valeur= pointeur sur le sommet)
        std::vector<std::vector<Arrete>>allsolu;
        std::vector<std::vector<Arrete>>soluadmiss;


};

#endif
