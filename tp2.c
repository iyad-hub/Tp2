#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date
{
    int jour[3];
    int mois[3];
    int annee[5];
} date;

typedef struct Produit
{
    char *Nom_produit;
    char Reference[100];
    float Montant;
    date DateAchat;
} produit;

typedef struct Liste
{
    produit cellule;
    struct Liste *psuiv;
} liste;

liste *creer_liste_produit()
{
    return NULL;
}

int est_vide(liste *tete)
{
    return (tete == NULL);
}

liste *creer_produit()
{
    liste *p = (liste *)malloc(sizeof(liste));
    if (p == NULL)
    {
        printf("Erreur d'allocation de memoire\n");
    }
    else
    {
        printf("Donner le nom du produit: ");
        scanf("%s", p->cellule.Nom_produit);
        printf("Donner la reference du produit: ");
        scanf("%s", p->cellule.Reference);
        printf("Donner le montant du produit: ");
        scanf("%f", &p->cellule.Montant);
        printf("Donner la date d'achat du produit: ");
        printf("Donner le jour: ");
        scanf("%d", &p->cellule.DateAchat.jour);
        printf("Donner le mois: ");
        scanf("%d", &p->cellule.DateAchat.mois);
        printf("Donner l'annee: ");
        scanf("%d", &p->cellule.DateAchat.annee);
        p->psuiv = NULL;
        return p;
    }
}

void afficher_produit(liste *produit)
{
    printf("Nom du produit: %s\n", produit->cellule.Nom_produit);
    printf("Reference du produit: %s\n", produit->cellule.Reference);
    printf("Montant du produit: %f\n", produit->cellule.Montant);
    printf("Date d'achat du produit: %d/%d/%d\n", produit->cellule.DateAchat.jour, produit->cellule.DateAchat.mois, produit->cellule.DateAchat.annee);
}

liste *ajouter_debut(liste *tete)
{
    liste *p = creer_produit();
    if (p == NULL)
    {
        return tete;
    }
    else
    {
        p->psuiv = tete;
        return p;
    }
}

liste *ajouter_fin(liste *tete)
{
    liste *p = creer_produit();
    if (p == NULL)
    {
        return tete;
    }
    else
    {
        if (tete == NULL)
        {
            printf("La liste est vide\n");
        }
        else
        {
            liste *q = tete;
            while (q->psuiv != NULL)
            {
                q = q->psuiv;
            }
            q->psuiv = p;
            return tete;
        }
    }
}

void afficher_produits(liste *tete)
{
    liste *p = creer_produit();
    while (p != NULL)
    {
        afficher_produit(p);
        p = p->psuiv;
    }
}

int longueur(liste *tete)
{
    liste *p = creer_produit();
    int a = 0;
    while (p != NULL)
    {
        a++;
        p = p->psuiv;
    }
    return a;
}

void filtrer_date(liste *tete, date dt)
{
    liste *p = creer_produit();
    while (p != NULL)
    {
        if (p->cellule.DateAchat.jour == dt.jour && p->cellule.DateAchat.mois == dt.mois && p->cellule.DateAchat.annee == dt.annee)
        {
            afficher_produit(p);
        }
        p = p->psuiv;
    }
}

liste *supprimer_debut(liste *tete)
{
    if (tete == NULL)
    {
        printf("La liste est vide\n");
    }
    else
    {
        liste *p = tete;
        tete = tete->psuiv;
        free(p);
    }
    return tete;
}

liste *supprimer_fin(liste *tete)
{
    if (tete == NULL)
    {
        printf("la liste est vide\n");
    }
    else
    {
        liste *p = tete;
        liste *q = tete;
        while (p->psuiv != NULL)
        {
            q = p;
            p = p->psuiv;
        }
        q->psuiv = NULL;
        free(p);
    }
    return tete;
}

liste *rembourser(liste *tete, char *refer)
{
    liste *p = tete;
    liste *q = tete;
    if (tete == NULL)
    {
        printf("la liste est vide");
    }
    else
    {
        while (p != NULL)
        {
            if (strcmp(p->cellule.Reference, refer) == 0)
            {
                if (p == tete)
                {
                    tete = supprimer_debut(tete);
                    return tete;
                }
                else
                {
                    tete = supprimer_fin(tete);
                    return tete;
                }
            }
            q = p;
            p = p->psuiv;
        }
    }
    return tete;
}

void main()
{
    liste *tete = creer_liste_produit();
    int choix;
    date dt;
    char refer[100];
    do
    {
        printf("\n");
        printf("Menu\n");
        printf("1- Ajouter un produit au debut de la liste\n");
        printf("2- Ajouter un produit a la fin de la liste\n");
        printf("3- Afficher la liste des produits\n");
        printf("4- Filtrer les produits par date\n");
        printf("5- Supprimer un produit au debut de la liste\n");
        printf("6- Supprimer un produit a la fin de la liste\n");
        printf("7- Rembourser un produit\n");
        printf("8- Quitter\n");
        printf("Donner votre choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            tete = ajouter_debut(tete);
            break;
        case 2:
            tete = ajouter_fin(tete);
            break;
        case 3:
            afficher_produit(tete);
            break;
        case 4:
            printf("Donner la date a filtrer: ");
            printf("Donner le jour: ");
            scanf("%d", &dt.jour);
            printf("Donner le mois: ");
            scanf("%d", &dt.mois);
            printf("Donner l'annee: ");
            scanf("%d", &dt.annee);
            filtrer_date(tete, dt);
            break;
        case 5:
            tete = supprimer_debut(tete);
            break;
        case 6:
            tete = supprimer_fin(tete);
            break;
        case 7:
            printf("Donner la reference du produit a rembourser: ");
            scanf("%s", refer);
            tete = rembourser(tete, refer);
            break;
        case 8:
            break;
        default:
            printf("Choix invalide\n");
        }
    } while (choix != 8);
}
