#include <iostream>
#include <string>
using namespace std;

char** generarTablero(char**, int);
void imprimirTablero();
void atacar(string, char**, int**);
string generarNombre(int);

int main(){

	//Arreglos con las posiciones de los barcos
	int** posicionesBarcos1;
	int** posicionesBarcos2;

	//Tableros que se usaran para marcar las posiciones atacadas
	char** tableroJuego1;
	char** tableroJuego2;

	//Generar todos los tableros
	generarTablero(tableroJuego1, 1);
	generarTablero(tableroJuego2, 2);

	//Booleans para ver si el juego termino y determinar el jugador ganador
	bool termino = false;
	bool gano1 = false;
	bool gano2 = false;

	int barcosRestantes1 = 4;
	int barcosRestantes2 = 4;

	int codigoNombre1;
	int codigoNombre2;

	string nombreJugador1 = generarNombre(codigoNombre1);
	string nombreJugador2 = generarNombre(codigoNombre2);

	int turno = 1;

	while(!termino){
		if(turno == 1){
			atacar(nombreJugador1, tableroJuego1, posicionesBarcos2);
			barcosRestantes2 = verificarBarcosRestantes(2, posicionesBarcos2):
		}else{
			atacar(nombreJugador2, tableroJuego2, posicionesBarcos1);
			barcosRestantes1 = verificarBarcosRestantes(1, posicionesBarcos1):
		}
	}

	if(gano1){
		terminarJuego(1);
	}else{
		terminarJuego(2);
	}

	return 0;

}

void atacar(){

}
