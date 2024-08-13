#ifndef FUNCIONMOSTRARMENU_H_INCLUDED
#define FUNCIONMOSTRARMENU_H_INCLUDED

#include "rlutil.h"
int mostrarMenu ();

//FUNCION PARA MOSTRAR MENU
int mostrarMenu ()
{
    int numJ;

    rlutil::locate (38,9);
    cout << "!!BIENVENIDOS A QUINIENTOS O ESCALERA!!" << endl;
    rlutil::locate (48,10);
    cout << "***MENU PRINCIPAL***" << endl;
    rlutil::locate (42,12);
    cout << "1. MODO DE JUEGO 'UN JUGADOR'" << endl;
    rlutil::locate (42,13);
    cout << "2. MODO DE JUEGO 'DOS JUGADORES'" << endl;
    rlutil::locate (42,14);
    cout << "3. FIN DEL JUEGO - CERRAR PROGRAMA" << endl;
    rlutil::locate (42,15);
    cout << endl;
    cout << endl;
    rlutil::locate (40,16);
    cout << "^^SELECCIONE UNA DE LAS OPCIONES^^" << endl;
    rlutil::locate (57,17);
    cin >> numJ;

    system("cls");

    return numJ;

}

#endif // FUNCIONMOSTRARMENU_H_INCLUDED
