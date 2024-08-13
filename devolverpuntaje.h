#ifndef DEVOLVERPUNTAJE_H_INCLUDED
#define DEVOLVERPUNTAJE_H_INCLUDED

int devolverpuntaje (int a);

int devolverpuntaje (int calcularpuntaje, int a)
{

    switch (calcularpuntaje)
    {
    case 1:
        rlutil::locate (45,17);
        cout << "ESCALERA, ERES EL GANADOR" << endl;
        puntaje = 500;
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;

    default:
        break;
    }

}
#endif // DEVOLVERPUNTAJE_H_INCLUDED
