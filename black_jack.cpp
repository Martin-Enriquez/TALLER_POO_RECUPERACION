#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Mazo {
private:
    int cartas[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
public:
    int generarCartaAleatoria() {
        return cartas[rand() % 13];
    }
};

class Jugador {
private:
    string nombre;
    int puntos;

public:
    Jugador(string n) {
        nombre = n;
        puntos = 0;
    }

    string getNombre() { return nombre; }
    int getPuntos() { return puntos; }

    void sumarPuntos(int valorCarta) {
        puntos += valorCarta;
    }

    void mostrar() {
        cout << "\n================================" << endl;
        cout << " ESTADO FINAL: " << nombre << endl;
        cout << " TOTAL: " << puntos << " PUNTOS" << endl;
        cout << "================================" << endl;
    }
};

// Funcion para turno (misma logica que ya tenias)
void jugarTurno(Jugador &j, Mazo &mazoJuego) {

    cout << "\n--- " << j.getNombre() << ", tus cartas iniciales son ---" << endl;
    int carta;
    for (int i = 0; i < 2; i++) {
        carta = mazoJuego.generarCartaAleatoria();
        j.sumarPuntos(carta);
        cout << ">> Carta " << i+1 << ": " << carta << endl;
    }
    if(carta >= 10){
            cout << "   ¡CORRES CON SUERTE " << j.getNombre() << "! TE HA SALIDO UN " << carta << endl;
            cout<<"\n PERO VEAMOS SI TIENES LA MISMA SUERTE LA PROXIMA VEZ... HAHAHAHA (*risa malevola*)"<<endl;
        }


    char opcion;
    bool plantado = false;

    while (j.getPuntos() < 21 and !plantado) {
        cout << "\nSuma actual: [" << j.getPuntos() << "]" << endl;
        cout << "¿Pedir carta (p) o Plantarse (s)?: ";
        cin >> opcion;

        if (opcion == 'p' or opcion == 'P') {
            int nuevaCarta = mazoJuego.generarCartaAleatoria();
            j.sumarPuntos(nuevaCarta);
            cout << "Te salio un: " << nuevaCarta << endl;
        } 
        else if (opcion == 's' or opcion == 'S') {
            plantado = true;
        } 
        else {
            cout << "(!) Opcion no valida. Digita 'p' o 's'." << endl;
        }
    }

    cout << "\nREDOBLES DE TAMBORES........" << endl;
    j.mostrar();

    if (j.getPuntos() == 21) {
        cout << "¡BLACKJACK! ¡Ganaste! ¡Eres una bestiaaa!!" << endl;
    } 
    else if (j.getPuntos() > 21) {
        cout << "Te pasaste de 21... Perdiste :( Pero el casino gana." << endl;
    } 
    else {
        cout << "Te plantaste con " << j.getPuntos() << " puntos." << endl;
        cout << "OWWW Es una pena :(( no lograste el 21 perfecto." << endl;
    }
}

int main() {
    srand(time(0));
    Mazo mazoJuego;

    string nombre1, nombre2;

    cout << "--------------------------------" << endl;
    cout << "  BIENVENIDO AL CASINO DE MONACO!!   " << endl;
    cout << "--------------------------------" << endl;

    cout << "Jugador 1, ingresa tu nombre: ";
    cin >> nombre1;

    cout << "Jugador 2, ingresa tu nombre: ";
    cin >> nombre2;

    Jugador j1(nombre1);
    Jugador j2(nombre2);

    // Turno jugador 1
    jugarTurno(j1, mazoJuego);

    // Turno jugador 2
    jugarTurno(j2, mazoJuego);

    // Resultado final comparado
    cout << "\n================ RESULTADO FINAL ================" << endl;

    int p1 = j1.getPuntos();
    int p2 = j2.getPuntos();

    if (p1 > 21 && p2 > 21) {
        cout << "Ambos jugadores perdieron. El casino gana." << endl;
    } 
    else if ((p1 <= 21 && (p1 > p2 || p2 > 21))) {
        cout << "El ganador es: " << j1.getNombre() << endl;
        cout << "ES UNA LASTIMA " << j2.getNombre() << ", TE GANO " << j1.getNombre() << "  PIPIPI :("<<endl;
    } 
    else if ((p2 <= 21 && (p2 > p1 || p1 > 21))) {
        cout << "El ganador es: " << j2.getNombre() << endl;
        cout << "ES UNA LASTIMA " << j1.getNombre() << ", TE GANO " << j2.getNombre() << "  PIPIPI :("<<endl;
    } 
    else {
        cout << "Es un empate." << endl;
    }

    cout << "\nGracias por jugar. ¡Vuelve pronto!" << endl;

    return 0;
}