#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

typedef struct {  //un carton de boites de chaussures
    int id_carton;
    int nb_places_libres;
} carton;

void afficheCarton(carton c);

#endif // TYPES_H_INCLUDED
