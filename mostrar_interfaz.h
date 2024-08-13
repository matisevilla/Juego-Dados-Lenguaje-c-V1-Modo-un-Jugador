#ifndef MOSTRAR_INTERFAZ_H_INCLUDED
#define MOSTRAR_INTERFAZ_H_INCLUDED

void mostrarInterfaz ();

void mostrarInterfaz ()
{

    int nombJ1;
    int rond;
    int nrond;
    int acu;

    for (int i=0; i<3; i++)
    {
        rlutil::locate (39,2);
        cout << "TURNO DE: " << nombJ1 << " | " << "RONDA " << rond << " DE " << nrond << " | " << "PUNTAJE TOTAL: " << acu << " PUNTOS " << endl;
        rlutil::locate (39,3);
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        rlutil::locate (39,4);
        cout << "TIRADA NUMERO: " << i+1 << endl;
        rlutil::locate (39,5);
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        rlutil::locate (39,6);
        cout << "PRESIONA UNA TECLA PARA LANZAR LOS DADOS" << endl << endl;
        rlutil::locate (39,8);
        rlutil::anykey ();
    }


}

#endif // MOSTRAR_INTERFAZ_H_INCLUDED
