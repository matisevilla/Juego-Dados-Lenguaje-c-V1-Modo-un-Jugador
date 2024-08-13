#ifndef FUNCIONESPUNTAJE_H_INCLUDED
#define FUNCIONESPUNTAJE_H_INCLUDED
//#include <iostream>


//PROTOTIPOS
void cargarDados(int dados[], int numDados);
int calcularpuntaje(int dados[], int numDados);
void cargardadosamano (int dados[], int numDados);

// FUNCION PARA CARGAR LOS DADOS
void cargarDados(int dados[], int numDados)
{
///    cargardadosamano(dados, numDados);

    for (int i=0; i<numDados; i++)
    {
        dados[i] = rand() % 6 + 1;
        cout << dados[i];

        // dibujarDados(dados[0], 32, 12);

        //dibujarDados(dados[1], 42, 12);

        // dibujarDados(dados[2], 52, 12);

        //dibujarDados(dados[3], 62, 12);

        //dibujarDados(dados[4], 72, 12);

        //dibujarDados(dados[5], 82, 12);
    }
    system("pause");
}
/*
void cargardadosamano (int dados[], int numDados)
{

    for (int i=0; i<numDados; i++)
    {
        rlutil::locate (2,15+i);
        cout << "ingrese un valor para el dado: " << i+1 << endl;
        rlutil::locate (35,15+i);
        cin >> dados[i];
    }


}*/

// FUNCION PARA OBTENER PUNTAJE DEL JUGADOR/ES
int calcularpuntaje(int dados[], int numDados)
{
    int puntaje = 0;
    int valor[6] = {0};

    system("cls");

    for (int i=0; i < numDados; i++)
    {
        for (int j=0; j<numDados ; j++ )
        {
            if(dados[j]==i+1)
            {
                valor[i]++;
            }
        }

    }
// VERIFICA EXISTENCIA DE ESCALERA

    bool escalera = true;
    for (int i=1; i<=6; i++)
    {
        if(valor[i-1]!=1)
        {
            escalera = false;
        }
    }
    if (escalera)
    {
        rlutil::locate (45,17);
        cout << "ESCALERA, ERES EL GANADOR" << endl;
        puntaje = 500;
        return puntaje;

    }

// VERIFICA SI HUBO SEXTETO

    bool sexteto = true;

    for (int i=1; i<=5; i++)
    {
        if (valor[i-1] == 6)
        {
            puntaje = i * 50;
            rlutil::locate (52,19);
            cout << "SEXTETO DE " << i << endl;
            return puntaje;


        }
        else if (!valor[i-1] == 6)
        {
            sexteto = false;
        }

    }


// VERIFICA SI HUBO SEXTETO DE 6

    bool sexteto6 = false;
    for (int i=1; i<=6; i++)
    {
        if (valor[i] == 6)
        {
            sexteto6 = true;
            puntaje = 0;
        }

    }
    if (sexteto6==true)
    {
        rlutil::locate (45,17);
        cout << "SEXTETO DE SEIS (6) " << endl;
        return puntaje;

    }


// VERIFICA SI HUBO TRIO

    bool trio = false;

    for (int i=1; i<=6; i++)
    {
        if (valor[i-1] >= 3)
        {
            rlutil::locate (62,18+i);
            cout << "TRIO DE " << i << endl;
            puntaje = i * 10;
            rlutil::locate (90,23+i);
            cout << "Puntaje correspondiente: " << puntaje << endl;
            trio = true;

        }
    }
    if(trio)
    {
        rlutil::locate (90,25);
        cout<<"Valor final del puntaje: "<<puntaje<<endl;
        return puntaje;

    }


// SUMA LOS VALORES DE LOS DADOS

    for (int i=1; i<=6; i++)
    {

        puntaje += dados[i-1];
    }

    rlutil::locate (51,17);
    cout << "SUMA DE DADOS " << endl;
    rlutil::locate (90,24);
    cout << "Puntaje correspondiente: " << puntaje << endl;
    return puntaje;


}

#endif // FUNCIONESPUNTAJE_H_INCLUDED
