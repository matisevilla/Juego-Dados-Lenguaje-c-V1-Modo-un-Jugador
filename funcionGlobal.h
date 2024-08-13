#ifndef FUNCIONGLOBAL_H_INCLUDED
#define FUNCIONGLOBAL_H_INCLUDED

#include "funcionMostrarMenu.h"
#include "funcionesPuntaje.h"
#include "terminarJuego.h"

int funcionGlobal ();

int funcionGlobal()
{

    srand(time(0));

    const int numDados = 6;
    int numJugadores;
    int puntajeJugador1 = 0, puntajeJugador2 = 0;
    int maxPuntaje = 0;
    int ronda = 1;
    int seguirJugando = 1;
    string ganador;
    string nombreJugador1, nombreJugador2;

    while (seguirJugando==1)
    {
        int puntajeJugador1 = 0, puntajeJugador2 = 0;
        int ronda = 1;

        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        rlutil::setColor(rlutil::BLACK);

        rlutil::cls();

        int opcionSeleccionada;
        opcionSeleccionada = mostrarMenu();

        system ("cls");

        switch (opcionSeleccionada)
        {
        case 1:
            rlutil::locate (45,10);
            cout << "||MODO DE JUEGO UN JUGADOR||" << endl;
            cout << endl;
            rlutil::locate (42,12);
            cout << ">>>INGRESE EL NOMBRE DEL JUGADOR<<<" << endl;
            rlutil::locate (57,13);
            cin >> nombreJugador1;
            numJugadores = 1;

            break;

        case 2:

            rlutil::locate (45,10);
            cout << "MODO DE JUEGO DOS JUGADORES" << endl;
            cout << endl;
            rlutil::locate (40,12);
            cout << "INGRESE EL NOMBRE DEL PRIMER JUGADOR" << endl;
            rlutil::locate (57,13);
            cin >> nombreJugador1;
            rlutil::locate (40,14);
            cout << "INGRESE EL NOMBRE DEL SEGUNDO JUGADOR" << endl;
            rlutil::locate (57,15);
            cin >> nombreJugador2;
            numJugadores = 2;

            break;

        case 3:
            rlutil::locate (39,15);
            cout << "---JUEGO INICIALIZADO DE FORMA INCORRECTA---" << endl;
            return 0;
            break;
        }


        int numrondas;

        rlutil::locate (38,18);
        cout << "<<<INGRESE UN NUMERO DE RONDAS A JUGAR>>>" << endl;
        rlutil::locate (58,19);
        cin >> numrondas;
        cout << endl;

        system ("cls");

        int acumulador = 0;
        int acumulador1 = 0;
        int acumulador2 = 0;
        int dados[6];
        while (ronda <= numrondas)
        {
            if (numJugadores==1)
            {
                int puntosronda = 0;

                for (int i=0; i<3 ; i++)
                {

                    rlutil::locate (39,2);
                    cout << "TURNO DE: " << nombreJugador1 << " | " << "RONDA " << ronda << " DE " << numrondas << " | " << "PUNTAJE TOTAL: " << acumulador << " PUNTOS " << endl;
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




                    cargarDados(dados, 6);


                    int puntaje = calcularpuntaje(dados,6);
                    rlutil::locate (90,20);
                    cout << "PUNTAJE DE LA TIRADA" << ": " << puntaje <<endl;

                    if (puntaje==0)
                    {
                        puntosronda=0;
                    }

                    if (puntaje==500)
                    {
                        i+=3;
                        ronda+=numrondas;
                    }

                    if(puntaje>puntosronda)
                    {
                        puntosronda=puntaje;
                    }

                    acumulador += puntaje;
                    rlutil::locate (90,26);
                    cout<<"Valor del acumulador: " << acumulador << endl;

                }



                puntajeJugador1+=puntosronda;

                if(puntajeJugador1>=500)
                {
                    ronda+=numrondas;
                }


                rlutil::locate (39,25);
                cout << "FIN DE LA RONDA " << ronda << endl;
                rlutil::locate (39,26);
                cout << "EL PUNTAJE MAXIMO DE LA RONDA FUE DE " << puntosronda << endl;

                rlutil::anykey ();
                system("cls");

                ganador = nombreJugador1;
                maxPuntaje = max(maxPuntaje, puntajeJugador1);

            }



            else if (numJugadores==2)
            {

                int puntajeronda1 = 0;

                for (int i=0; i<3 ; i++)
                {
                    rlutil::locate (39,2);
                    cout << "TURNO DE: " << nombreJugador1 << " | " << "RONDA " << ronda << " DE " << numrondas << " | " << "PUNTAJE TOTAL: " << acumulador1 << " PUNTOS " << endl;
                    rlutil::locate (39,3);
                    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                    rlutil::locate (39,4);
                    cout << "TIRADA NUMERO: " << i+1 << endl;
                    rlutil::locate (39,5);
                    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
                    rlutil::locate (39,6);
                    if (i<3)
                    {
                        cout << "PRESIONA UNA TECLA PARA LANZAR LOS DADOS" << endl << endl;
                        rlutil::locate (39,8);
                        rlutil::anykey ();
                    }

                    int dadosJugador1[6];
                    cargarDados(dadosJugador1, 6);

                    int puntajetiro1 = calcularpuntaje(dadosJugador1, 6);
                    rlutil::locate (90,27);
                    cout << "PUNTAJE DE LA TIRADA" << ": " << puntajetiro1 << endl;

                    if(puntajetiro1==0)
                    {
                        puntajeronda1=0;
                        i+=3;
                    }
                    if(puntajetiro1==500)
                    {
                        i+=3;
                        ronda+=numrondas;
                    }

                    if(puntajetiro1>puntajeronda1)
                    {
                        puntajeronda1=puntajetiro1;
                    }
                    acumulador1 += puntajetiro1;
                    rlutil::locate (46,27);
                    cout << "valor del acumulador1 " << acumulador1 << endl;

                }



                int puntajeronda2=0;

                for(int i=0; i<3; i++)
                {

                    rlutil::locate (39,2);
                    cout << "TURNO DE: " << nombreJugador2 << " | " << "RONDA " << ronda << " DE " << numrondas << " | " << "PUNTAJE TOTAL: " << acumulador2 << " PUNTOS " << endl;
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


                    int dadosJugador2[6];
                    cargarDados(dadosJugador2, 6);

                    int puntajetiro2 = calcularpuntaje(dadosJugador2, 6);
                    rlutil::locate (90,27);
                    cout << "PUNTAJE DE LA TIRADA" << ": " << puntajetiro2 << endl;



                    if(puntajetiro2==0)
                    {
                        puntajeronda2=0;
                    }
                    if(puntajetiro2==500)
                    {
                        i+=3;
                        ronda+=numrondas;
                    }

                    if(puntajetiro2>puntajeronda2)
                    {
                        puntajeronda2=puntajetiro2;
                    }

                    acumulador2 += puntajetiro2;
                    rlutil::locate (46,27);
                    cout << "valor del acumulador2 " << acumulador2 << endl;
                }

                puntajeJugador1+=acumulador1;
                puntajeJugador2+=acumulador2;

                rlutil::locate (16,40);
                cout<<"FIN DE LA RONDA " <<ronda <<endl;
                rlutil::locate (16,40);
                cout<<"PUNTAJE DE " <<nombreJugador1 <<puntajeJugador1 <<endl;
                rlutil::locate (16,40);
                cout<<"PUNTAJE DE " <<nombreJugador2 <<puntajeJugador2 <<endl;

                if (puntajeJugador1 >= 500 && puntajeJugador1 > puntajeJugador2)
                {
                    ganador = nombreJugador1;
                    maxPuntaje = max(maxPuntaje, puntajeJugador1);
                    break;

                }
                else if (puntajeJugador2 >= 500 && puntajeJugador2 > puntajeJugador1)
                {
                    ganador = nombreJugador2;
                    maxPuntaje = max(maxPuntaje, puntajeJugador2);
                    break;
                }
            }

            system ("cls");
            ronda++;
        }

        rlutil::locate (48,6);
        cout<<"------FIN DEL JUEGO------";
        if(numJugadores==1)
        {
            rlutil::locate (53,13);
            cout<<"JUGADOR: " <<nombreJugador1 <<endl;
            rlutil::locate (48,14);
            cout<<"PUNTAJE TOTAL OBTENIDO: " <<puntajeJugador1 <<endl;
            rlutil::locate (50,15);
            cout<<"PUNTAJE MAXIMO: " <<maxPuntaje;
        }
        else if (numJugadores == 2)
        {
            rlutil::locate (48,13);
            cout << "JUGADOR 1 (" << nombreJugador1 << "): " << puntajeJugador1 << " PUNTOS" << endl;
            rlutil::locate (48,14);
            cout << "JUGADOR 2 (" << nombreJugador2 << "): " << puntajeJugador2 << " PUNTOS" << endl;

            if(puntajeJugador1>maxPuntaje)
            {
                maxPuntaje=puntajeJugador1;
            }
            if(puntajeJugador2>maxPuntaje)
            {
                maxPuntaje=puntajeJugador2;
            }
            if(puntajeJugador1>puntajeJugador2)
            {
                ganador=nombreJugador1;
            }
            if(puntajeJugador2>puntajeJugador1)
            {
                ganador=nombreJugador2;
            }
            if(puntajeJugador1==puntajeJugador2)
            {
                cout << "AMBOS SACARON LA MISMA PUNTUACION" << endl;
            }

            rlutil::locate (48,15);
            cout << "PUNTAJE MAXIMO: " << maxPuntaje <<endl;
            rlutil::locate (48,16);
            cout << "GANADOR: " << ganador <<endl;
        }

        seguirJugando = terminarJuego();
    }
}

#endif // FUNCIONGLOBAL_H_INCLUDED
