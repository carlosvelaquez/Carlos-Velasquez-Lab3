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
			bool hit = atacar(nombreJugador1, tableroJuego1, posicionesBarcos2);
			if(hit){
				cout << nombreJugador2 <<  << endl;	
			}else{

			}

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

bool atacar(string nombreJugador, char** tablero, int** posicionesBarcos, int** posicionesAtacadas){
	int x, y;

	cout << "Es el turno de " << nombreJugador << "!" << endl 
		<< "------------------------------" << endl;
	imprimirTablero(tablero);
	cout << endl << "Ingrese las coordenadas a atacar" << endl;
	cout << "X: ";

	cin >> x;

	cout << "Y: ";
	cin >> y;

	bool hit = false;

	for(int i = 0; i < 8; i++){
		if(posicionesBarcos[i][0] == x && posicionesBarcos[i][1] == y){
			for(int j = 0; j < 65; j++){
				if(posicionesAtacadas[j][0] == x && posicionesAtacadas[j][1] == y){
					cout << nombreJugador << "ha disparado de nuevo en (" << x
						<< "," << y << ")!" << endl;
				}else{
					cout << nombreJugador << "ha disparado en (" << x
						<< "," << y << ") y le ha atinado a un barco enemigo!"
						<< endl;
					hit = true;
				}
			}
		}
	}

	return hit;
}
