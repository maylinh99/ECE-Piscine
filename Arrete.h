#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Arrete
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Arrete(std::string,double,double);

        void ajouterVoisin(const Sommet*);

        ~Arrete();

    protected:

    private:

        Sommet origine;
        Sommet destination;
        /// Donn�es sp�cifiques du sommet
        std::string m_id; // Identifiant
        float poid1;
        float poid2;


#endif // ARRETE_H_INCLUDED
