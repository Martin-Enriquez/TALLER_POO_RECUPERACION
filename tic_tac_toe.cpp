#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Jugador {
private:
    string nombre;
    char simbolo;

public:
    Jugador(string n, char s) {
        nombre = n;
        simbolo = s;
    }

    string getNombre() { return nombre; }
    char getSimbolo() { return simbolo; }
};

char tablero[9] = {'1','2','3','4','5','6','7','8','9'};

void mostrarTablero() {
    cout << "\n================================" << endl;
    cout << " TABLERO DE JUEGO" << endl;
    cout << "================================" << endl;

    cout << " " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << endl;
    cout << endl;
}

bool hayGanador() {
    int comb[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for(int i = 0; i < 8; i++) {
        if(tablero[comb[i][0]] == tablero[comb[i][1]] and
           tablero[comb[i][1]] == tablero[comb[i][2]]) {
            return true;
        }
    }
    return false;
}

bool tableroLleno() {
    for(int i = 0; i < 9; i++) {
        if(tablero[i] != 'X' and tablero[i] != 'O') return false;
    }
    return true;
}

void turno(Jugador &j) {
    int pos;
    bool valido = false;

    while(!valido) {
        cout << "\n" << j.getNombre() << ", es tu turno... piensa bien tu jugada: ";

        cin >> pos;

        // 🔹 VALIDACIÓN COMPLETA
        if(cin.fail()) {
            cout << "Eso no es un numero valido... intenta otra vez." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if(pos < 1 or pos > 9) {
            cout << "Ese numero no existe en este tablero..." << endl;
        }
        else if(tablero[pos-1] == 'X' or tablero[pos-1] == 'O') {
            cout << "Esa casilla ya fue tomada... elige otra." << endl;
        }
        else {
            tablero[pos-1] = j.getSimbolo();
            valido = true;
        }
    }
}

int main() {
    string n1, n2;

    cout << "--------------------------------" << endl;
    cout << "  BIENVENIDO AL DUELO DE MENTES  " << endl;
    cout << "--------------------------------" << endl;

    cout << "Jugador 1 (X), ingresa tu nombre: ";
    cin >> n1;

    cout << "Jugador 2 (O), ingresa tu nombre: ";
    cin >> n2;

    Jugador j1(n1, 'X');
    Jugador j2(n2, 'O');

    cout << "\nQue empiece la batalla... solo uno dominara el tablero." << endl;

    int turnos = 0;
    bool ganador = false;

    while(!ganador and !tableroLleno()) {
        mostrarTablero();

        if(turnos % 2 == 0)
            turno(j1);
        else
            turno(j2);

        ganador = hayGanador();
        turnos++;
    }

    cout << "\nREDOBLES DE TAMBORES........" << endl;
    mostrarTablero();

    if(ganador) {
        if((turnos-1) % 2 == 0)
            cout << "VICTORIA PARA " << j1.getNombre() << ". DOMINASTE EL TABLERO." << endl;
        else
            cout << "VICTORIA PARA " << j2.getNombre() << ". DOMINASTE EL TABLERO." << endl;
    } else {
        cout << "Nadie gano... un empate digno de respeto." << endl;
    }

    cout << "\nGracias por jugar. Esto no termina aqui..." << endl;

    return 0;
}