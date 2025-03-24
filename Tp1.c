#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
    int valeur;
    struct Noeud *suivant;
} Noeud;

Noeud *creer(int valeur)
{
    Noeud *p = (Noeud *)malloc(sizeof(Noeud));
    if (p == NULL)
    {
        printf("Erreur d'allocation de mémoire\n");
    }
    else
    {
        p->valeur = valeur;
        p->suivant = NULL;
        return p;
    }
}
void afficher(Noeud *debut)
{
    Noeud *p = debut;
    while (p != NULL)
    {
        printf("%d ", p->valeur);
        p = p->suivant;
    }
    printf("\n");
}
Noeud *ajouterD(Noeud *debut, int _valeur)
{
    Noeud *p = creer(_valeur);
    if (p == NULL)
    {
        printf("Erreur d'allocation de mémoire\n");
    }
    else
    {
        if (debut == NULL)
        {
            debut = p;
        }
        else
        {
            p->suivant = debut;
            debut = p;
        }
    }
    return debut;
}
Noeud *ajouterF(Noeud *debut, int _valeur)
{
    Noeud *p = creer(_valeur);
    if (p == NULL)
    {
        printf("Erreur d'allocation de mémoire\n");
    }
    else
    {
        if (debut == NULL)
        {
            debut = p;
        }
        else
        {
            Noeud *q = debut;
            while (q->suivant != NULL)
            {
                q = q->suivant;
            }
            q->suivant = p;
        }
    }
    return debut;
}
int taille(Noeud *debut)
{
    Noeud *p = debut;
    int taille = 0;
    while (p != NULL)
    {
        taille++;
        p = p->suivant;
    }
    return taille;
}
Noeud *insertion(Noeud *debut, int pos, int _valeur)
{
    Noeud *p = creer(_valeur);
    Noeud *q = debut;
    if (p == NULL)
    {
        printf("Erreur d'allocation de mémoire\n");
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            q = q->suivant;
        }
        p->suivant = q->suivant;
        q->suivant = p;
    }
    return debut;
}
void rechercher(Noeud *debut, int _valeur)
{
    Noeud *p = debut;
    int pos = 1;
    while (p != NULL)
    {
        if (p->valeur == _valeur)
        {
            printf("La valeur %d est trouvee a la position %d\n", _valeur, pos);
            return;
        }
        pos++;
        p = p->suivant;
    }
    printf("La valeur %d n'est pas trouvee\n", _valeur);
}
Noeud *suppressionD(Noeud *debut)
{
    Noeud *p = debut;
    if (debut == NULL)
    {
        printf("La liste est vide\n");
    }
    else
    {
        debut = debut->suivant;
        free(p);
    }
    return debut;
}
Noeud *suppressionF(Noeud *debut)
{
    Noeud *p = debut;
    if (debut == NULL)
    {
        printf("La liste est vide\n");
    }
    else
    {
        if (debut->suivant == NULL)
        {
            free(debut);
            debut = NULL;
        }
        else
        {
            Noeud *q = debut;
            while (p->suivant != NULL)
            {
                q = p;
                p = p->suivant;
            }
            q->suivant = NULL;
            free(p);
        }
        return debut;
    }
}
Noeud *suppressionP(Noeud *debut, int pos)
{
    Noeud *p = debut;
    if (debut == NULL)
    {
        printf("La liste est vide\n");
    }
    else
    {
        if (debut->suivant == NULL)
        {
            free(debut);
            debut = NULL;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                p = p->suivant;
            }
            Noeud *q = p->suivant;
            p->suivant = q->suivant;
            free(q);
        }
    }
}
Noeud *modifierD(Noeud *debut, int _valeur)
{
    Noeud *p = debut;
    if (debut == NULL)
    {
        printf("La liste est vide\n");
    }
    else
    {
        p->valeur = _valeur;
    }
    return debut;
}
Noeud *modifierF(Noeud *debut, int _valeur)
{
    Noeud *p = debut;
    if (debut == NULL)
    {
        printf("la liste est vide\n");
    }
    else
    {
        while (p->suivant != NULL)
        {
            p = p->suivant;
        }
        p->valeur = _valeur;
    }
    return debut;
}
Noeud *modifierP(Noeud *debut, int pos, int _valeur)
{
    Noeud *p = debut;
    if (debut == NULL)
    {
        printf("la liste est vide\n");
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            p = p->suivant;
        }
        p->valeur = _valeur;
    }
    return debut;
}

void main(){
    Noeud *debut=NULL;
    debut=ajouterD(debut, 10);
    debut=ajouterD(debut, 20);
    debut=ajouterD(debut, 30);
    afficher(debut);
    debut=ajouterF(debut, 60);
    afficher(debut);
    printf("La taille de la liste est %d\n", taille(debut));
    debut=insertion(debut, 2, 25);
    afficher(debut);
    rechercher(debut, 60);
    debut=suppressionD(debut);
    afficher(debut);
    debut=suppressionF(debut);
    afficher(debut);
    debut=suppressionP(debut, 2);
    afficher(debut);
    debut=modifierD(debut, 80);
    afficher(debut);
    debut=modifierF(debut, 90);
    afficher(debut);
    debut=modifierP(debut, 2, 100);
    afficher(debut);
}