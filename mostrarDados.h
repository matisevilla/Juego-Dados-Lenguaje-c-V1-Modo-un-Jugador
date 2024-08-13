#ifndef MOSTRARDADOS_H_INCLUDED
#define MOSTRARDADOS_H_INCLUDED

void mostrarDados (int dados[], int numDados);

void mostrarDados (int dados[], int numDados){
    for (int i=0; i<numDados; i++){
        cout << dados[i] << endl;
    }
}

#endif // MOSTRARDADOS_H_INCLUDED
