#include <iostream>
#include <string>
using namespace std;

char** generarTablero(char**, int);
void imprimirTablero();
void atacar(string, char**, int***, int**);
string generarNombre(int);
void bienvenida(string, string, int***, int***);
int*** posicionesBarcos(int);
int** llenarMatrizPA();
char** generarTablero();

int main(){

	//Arreglos con las posiciones de los barcos
	int*** posicionesBarcos1;
	int*** posicionesBarcos2;
	posicionesBarcos1 = posicionarBarcos(1);
	posicionesBarcos2 = posicionarBarcos(2);

	//Arreglos con las posiciones que han sido atacadas
	int** posicionesAtacadas1;
	int** posicionesAtacadas2;
	posicionesAtacadas1 = llenarMatrizPA();
	posicionesAtacadas2 = llenarMatrizPA();


	//Tableros que se usaran para marcar las posiciones atacadas
	char** tableroJuego1;
	char** tableroJuego2;
	tableroJuego1 = generarTablero();
	tableroJuego2 = generarTablero();
		
	//Booleans para ver si el juego termino y determinar el jugador ganador
	bool termino = false;
	bool gano1 = false;
	bool gano2 = false;

	int barcosRestantes1 = 4;
	int barcosRestantes2 = 4;

	int shotsTomados1 = 0;
	int shotsTomados2 = 0;

	int codigoNombre1;
	int codigoNombre2;

	string nombreJugador1 = generarNombre(codigoNombre1);
	string nombreJugador2 = generarNombre(codigoNombre2);

	int turno = 1;

	bienvenida(nombreJugador1, nombreJugador2, posicionesBarcos1, posicionesBarcos2);

	while(!termino){
		if(turno == 1){
			cout << "Es el turno de " << nombreJugador1 << "!" << endl; 
			cout << "Barcos enemigos restantes: " << barcosRestantes2 << endl
				<< "Barcos propios restantes: " << barcosRestantes1 << "------------------------------" << endl;

			bool hit = atacar(nombreJugador1, tableroJuego1, posicionesBarcos2);
			if(hit){
				cout << nombreJugador2 << "bebe un shot!" << endl;
				shotsTomados2 ++;
			}else{
				cout << nombreJugador2 << "está a salvo." << endl;
			}

			barcosRestantes2 = verificarBarcosRestantes(posicionesAtacadas2, posicionesBarcos2);
			cout << nombreJugador2 << "tiene " << barcosRestantes2 
				<< "barcos restantes." << endl;
		}else{
			cout << "Es el turno de " << nombreJugador2 << "!" << endl; 
			cout << "Barcos enemigos restantes: " << barcosRestantes1 << endl
				<< "Barcos propios restantes: " << barcosRestantes2 << "------------------------------" << endl;

			bool hit = atacar(nombreJugador2, tableroJuego2, posicionesBarcos1);
			if(hit){
				cout << nombreJugador1 << "bebe un shot!" << endl;
				shotsTomados1 ++;
			}else{
				cout << nombreJugador1 << "está a salvo." << endl;
			}

			barcosRestantes1 = verificarBarcosRestantes(posicionesAtacadas1, posicionesBarcos1);
			cout << nombreJugador1 << "tiene " << barcosRestantes1 
				<< "barcos restantes." << endl;

		}
	}

	if(gano1){
		terminarJuego(1);
	}else{
		terminarJuego(2);
	}

	return 0;

}

bool atacar(string nombreJugador, char** tablero, int*** posicionesBarcos, int** posicionesAtacadas){
	int x, y;
	bool continuar;

	do{
		continuar = true;
		imprimirTablero(tablero);
		cout << endl << "Ingrese las coordenadas a atacar" << endl;
		cout << "X: ";

		cin >> x;

		cout << "Y: ";
		cin >> y;

		bool hit = false;

		if(x < 0 || x > 7 || y < 0 || y > 7){
			cout << "[ERROR] Las coordenadas proporionadas superan el tamaño del tablero" << endl;
			continuar = false;
		}

	}while(!continuar);

	cout << endl;


	for(int w = 0; w < 4; w++){

		for(int i = 0; i < 3; i++){

			if(posicionesBarcos[w][i][0] == x && posicionesBarcos[w][i][1] == y){

				for(int j = 0; j < 65; j++){
					if(posicionesAtacadas[j][0] == x && posicionesAtacadas[j][1] == y){
						cout << nombreJugador << "ha disparado de nuevo en (" << x
							<< "," << y << ")!" << endl;
					}else{
						cout << nombreJugador << "ha disparado en (" << x
							<< "," << y << ") y le ha atinado a un barco enemigo!"
							<< endl;
						hit = true;
						tablero[x][y] == 'X';
					}
				}
			}
		}

	}

	if(!hit){
		cout << nombreJugador << " ha disparado en (" << x << "," << y << "), pero ha fallado el tiro." << endl;
	}

	cout << "------------------------------" << endl;
	return hit;
}

int verificarBarcosRestantes(int** posicionesAtacadas, int*** posicionesBarcos){
	int barcos = 0;
	int hits;

	for(int i = 0; i < 4; i++){
		hits = 0;
		for(int j = 0; j < 3; j++){
			for(int w = 0; w < 65; w++){
				if(posicionesBarcos[i][j][0] == posicionesAtacadas[w][0] && posicionesBarcos[i][j][1] == posicionesAtacadas[w][1]){
					hits++;
				}
			}
		}

		if(hits < 3){
			barcos++;
		}
	}

	return barcos;
}

void bienvenida(string nombreJugador1, string nombreJugador2, int*** posicionesBarcos1, int*** posicionesBarcos2){
	cout << "¡Bienvenidos a BATTLESHOTS!" << endl << endl;
	cout << "Las reglas con simples, es un juego para dos jugadores con el objetivo de dejar a" << endl
		<< endl << "cualquiera de los jugadores con la menor cantidad de barcos posible. Cada vez que uno de los" << endl
		<< endl "barcos sea atacado, el jugador atacado deberá de beber un shot que será elegido de manera" << endl
		<< endl << "aleatoria por el sistema. Hay 7 posibilidades de shots en total." << endl << endl;


	cout << "Jugador 1, voltea la computadora y presiona ENTER" << endl;
	string a;
	cin >> a;
	mostrarTablero(posicionesBarcos1);
	cout << "Presiona ENTER para borrar esta pantalla y continuar" << endl;
	cin >> a;

	cout << "Jugador 2, voltea la computadora y presiona ENTER" << endl;
	string a;
	cin >> a;
	mostrarTablero(posicionesBarcos2);
	cout << "Presiona ENTER para borrar esta pantalla y continuar" << endl;
	cin >> a;
	
}
