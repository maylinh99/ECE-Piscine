#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Sommet
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Sommet(std::string,double,double);
        void ajouterVoisin(const Sommet*);

        ~Sommet();

    protected:

    private:
        /// Voisinage : liste d'adjacence
        std::vector<const Sommet*> m_voisins;

        /// Donn�es sp�cifiques du sommet
        std::string m_id; // Identifiant
        double m_x, m_y; // Position


};

#endif // SOMMET_H_INCLUDED
