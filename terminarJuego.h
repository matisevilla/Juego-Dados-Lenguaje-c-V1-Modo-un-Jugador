#ifndef TERMINARJUEGO_H_INCLUDED
#define TERMINARJUEGO_H_INCLUDED

int terminarJuego ();

int terminarJuego ()
{
    int num;
    int sigueJugando = 1;


    rlutil::locate (29,20);
    cout << "INGRESE UNO SI QUIERE SEGUIR JUGANDO, CASO CONTRARIO INGRESE DOS" << endl;
    rlutil::locate (59,21);
    cin >> num;

    if (num==1)
    {
        sigueJugando = 1;
        system ("cls");
    }
    else if (num==2)
    {
        sigueJugando = 2;

        system ("cls");

        rlutil::locate (48,13);
        cout << "<<<JUEGO FINALIZADO>>>" << endl;
    }

    return num;
}

#endif // TERMINARJUEGO_H_INCLUDED
