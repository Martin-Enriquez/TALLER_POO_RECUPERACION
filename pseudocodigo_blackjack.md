ALGORITMO Blackjack
    //Configuración inicial
    DEFINIR mazo[13] COMO ENTERO = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}
    DEFINIR opcion COMO CARACTER
    DEFINIR carta_nueva COMO ENTERO
    
    CREAR objeto_jugador COMO Jugador("Usuario")

    // Repartir las 2 cartas iniciales
    REPETIR 2 VECES
        carta_nueva = mazo[ALEATORIO(0, 12)]
        objeto_jugador.sumarPuntos(carta_nueva)
    FIN REPETIR

    // Ciclo de turnos
    MIENTRAS objeto_jugador.getPuntos() < 21 HACER
        objeto_jugador.mostrar()
        ESCRIBIR "¿Deseas pedir carta (p) o plantarte (s)?"
        LEER opcion

        SI opcion == 'p' ENTONCES
            carta_nueva = mazo[ALEATORIO(0, 12)]
            ESCRIBIR "Te salió un: ", carta_nueva
            objeto_jugador.sumarPuntos(carta_nueva)
        SINO
            SALIR MIENTRAS // El jugador decidió plantarse
        FIN SI
    FIN MIENTRAS

    // Evaluación final del resultado
    objeto_jugador.mostrar()
    
    SI objeto_jugador.getPuntos() == 21 ENTONCES
        ESCRIBIR "¡Blackjack! ¡Has ganado!"
    SINO SI objeto_jugador.getPuntos() > 21 ENTONCES
        ESCRIBIR "Te has pasado de 21. ¡Has perdido!"
    SINO
        ESCRIBIR "Te plantaste con ", objeto_jugador.getPuntos(), " puntos."
    FIN SI

FIN ALGORITMO