#include <fstream>
#include <iostream>
#include "Graphe.h"

graphe::graphe(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    //lecture des aretes
    for (int i=0; i<taille; ++i)
    {
        //lecture des ids des deux extrémités
        ifs>>id;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin;
        if(ifs.fail())
            throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extrémité à la liste des voisins de l'autre (graphe non orienté)
        (m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        (m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orienté
    }
}

void graphe::afficher() const
{
    std::cout<<"graphe : "<<std::endl;
    std::cout<<"  coder l'affichage ! "<<std::endl;
}


void graphe::enumsolu() const
{
    std::vector<std::vector<bool>>tab; /// Vecteur qui va stocker des vecteur de booleens
    std::vector<bool> cas; ///Sous vecteur qui va dans tab
    std::vector<arrete>vectemp; ///Sous vecteur qui va dans all solution

    int nb_solution; ///Nombre total de solution
    int choix ///Choix de l'utilisateur
    bool b = false; ///Booleen pour boucle while

    nb_solution = nb_ponderation^nb_arrete; ///Calcul nombre de solutions

    ///INITIALISATION DU VECTEUR A 0 0 0 0 0
    for (int k=0; k<=nb_arrete; k++)
    {
        cas.push_back(false); /// On met le 1er cas a 0 0 0 0 0
    }
    tab.begin()=cas; /// On met cette premiere solution dans l'ensemble des solutions

    ///CAS PARTICULIER OU IL NY A PAS DARRETE
    vectemp.push_back(0);
    allsolu.push_back(vectemp); ///On met le cas 0 dans l'ensemble de solu
    vectemp.erase();

    ///DEMANDE A LUTILISATEUR CE QUIL VEUT
    std::cout<<"Voir :"<<std::end;
    std::cout<<"0 - Toutes les solutions"<<std::endl;
    std::cout<<"1 - Les solutions admissibles"<<std::endl;
    std::cin>>choix>>std::endl;

    ///CAS PARTICULIER OU IL NY A PAS DARRETE ON AFFICHE LE VECTEUR 0 0 0 0 0 /// A VERIFIER SI IL SAFFICHE PAS 2 FOIS
    if (choix==0)
        std::cout<<allsolu.begin()<<std::endl;

    for (int i=0; i<=nb_solution; i++)
    {
        int cpt=0; ///Compteur
        int j=0;

        ///Compteur en binaire (dans le sens inverse : 0000/1000/0100
        while (b==false)
        {
            if (cas.begin()+j==false)
            {
                cas.push_back(true);
                b=true; ///passer booleen a 1
            }

            else if (cas.begin()+j==true)
            {
                cas.push_back(false);
            }
            j++;
        }

        tab.push_back(cas);

        /// PERMET DE RENTRER LES INDICSES DES ARRETES DANS MON VECTEUR ALL SOLUTION
        for (int n=0; n<=nb_arrete; n++)
        {
            if (cas.begin()+n == true)
            {
                vectemp.push_back(n);
                allsolu.push_back(vectemp);

                if (cpt == nb_sommet-1) /// CONDITION SOLUTION ADMISSIBLE
                {
                    ///Place uniquement les solutions admissibles dans le vecteur
                    soluadmiss.push_back(vectemp);
                }
            }

            ///Affichage de toutes les solutions
            if (choix==0)
            {
                std::cout<<allsolu.begin()+j<<std::endl;
            }


            ///Affichage solutio nadmissible
            else if (choix==1)
            {
                for (int g=0; g<=nb_arrete; g++)
                {
                    if (cas.begin()+g == true)
                        cpt++;
                }
                if (cpt == nb_sommet-1)
                {
                    ///Affiche les solution admissibles
                    std::cout<<soluadmiss.begin()+i<<std::endl;
                }
            }

            b=false;
            cas.erase();
            vectemp.erase();
        }
    }


    graphe::~graphe()
    {
    }
