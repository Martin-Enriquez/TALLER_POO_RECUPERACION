#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Jugador {
private:
    string nombre;
    int monedas;

public:
    Jugador(string n) {
        nombre = n;
        monedas = 100;
    }

    string getNombre() { return nombre; }
    int getMonedas() { return monedas; }

    void apostar(int cantidad) {
        monedas -= cantidad;
    }

    void ganar(int premio) {
        monedas += premio;
    }

    void mostrarSaldo() {
        cout << nombre << " tiene " << monedas << " monedas." << endl;
    }
};

char simbolos[4] = {'@','#','$','%'};

void jugarTurno(Jugador &j) {

    if(j.getMonedas() < 10) {
        cout << j.getNombre() << " ya no tiene monedas... el casino ha ganado." << endl;
        return;
    }

    char op;
    cout << "\n" << j.getNombre() << ", deseas tentar a la suerte? (s/n): ";
    cin >> op;

    if(op == 'n') {
        cout << "Te retiras... una decision prudente." << endl;
        return;
    }

    cout << "La maquina comienza a girar..." << endl;

    j.apostar(10);

    char r1 = simbolos[rand() % 4];
    char r2 = simbolos[rand() % 4];
    char r3 = simbolos[rand() % 4];

    cout << "[ " << r1 << " ] [ " << r2 << " ] [ " << r3 << " ]" << endl;

    if(r1 == r2 && r2 == r3) {
        cout << "INCREIBLE... 3 iguales. El casino tiembla." << endl;
        j.ganar(50);
    }
    else if(r1 == r2 || r1 == r3 || r2 == r3) {
        cout << "Nada mal... 2 iguales. Sigues en juego." << endl;
        j.ganar(20);
    }
    else {
        cout << "Nada... el destino no estuvo de tu lado." << endl;
    }

    j.mostrarSaldo();
}

int main() {
    srand(time(0));

    string n1, n2;

    cout << "--------------------------------" << endl;
    cout << "  BIENVENIDO A LA MAQUINA DEL DESTINO  " << endl;
    cout << "--------------------------------" << endl;

    cout << "Jugador 1: ";
    cin >> n1;

    cout << "Jugador 2: ";
    cin >> n2;

    Jugador j1(n1);
    Jugador j2(n2);

    cout << "\nCada tirada puede cambiarlo todo..." << endl;

    bool jugando = true;

    while(jugando) {
        jugarTurno(j1);
        jugarTurno(j2);

        if(j1.getMonedas() < 10 && j2.getMonedas() < 10) {
            cout << "Ambos jugadores han caido... el casino gana." << endl;
            break;
        }

        char seguir;
        cout << "\nDesean continuar o retirarse mientras puedan? (s/n): ";
        cin >> seguir;

        if(seguir == 'n') jugando = false;
    }

    cout << "\nRESULTADO FINAL:" << endl;
    j1.mostrarSaldo();
    j2.mostrarSaldo();

    if(j1.getMonedas() > j2.getMonedas())
        cout << "El ganador es " << j1.getNombre() << endl;
    else if(j2.getMonedas() > j1.getMonedas())
        cout << "El ganador es " << j2.getNombre() << endl;
    else
        cout << "Empate... ninguno logro imponerse." << endl;

    cout << "\nGracias por jugar. El casino siempre estara esperando..." << endl;

    return 0;
}