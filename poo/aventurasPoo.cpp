#include <iostream>
#include <windows.h>
using namespace std;

// Variables GLOBALES, están disponibles en cualquier parte del código
string nombre = "";
int vida = 100;
bool vivo = true;

// Una función VOID (vacío) no deberá retornar ningún tipo de dato, sólo debe hacer una tarea
void avanzar(){
    cout << nombre << " avanza..." << endl;
}

void saltar(){
    cout << nombre << " salta..." << endl;
}

void recibirDanio(int danioJugador){
    // Modo clásico de realizar una sustracción
    // vida = vida - danio;
    vida -= danioJugador;

    cout << nombre << " fue atacado con " << danioJugador << " de daño." << endl;
    cout << nombre << " tiene " << vida << " de vida restante." << endl;

    if(vida <= 0){
        vivo = false;
        vida = 0;
        cout << "GAME OVER!" << endl;
    }
}

void verEstado(){
    cout << "Estado de " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Está vivo?: " << (vivo ? "Si" : "No") << endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int opcion = 0;
    int danio = 0;

    cout << "Cuál es el nombre de su personaje?: " << endl;
    cin >> nombre;

    cout << "Aventuras de " << nombre << endl;
    while (opcion != 5 && vivo)
    {
        opcion = 0;
        cout << "[1] Avanzar" << endl;
        cout << "[2] Saltar" << endl;
        cout << "[3] Recibir Daño" << endl;
        cout << "[4] Ver estado del personaje" << endl;
        cout << "[5] Salir" << endl;
        cout << "\nSeleccione su opción [1-5]:" << endl;
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                avanzar();
                break;
            case 2:
                saltar();
                break;
            case 3:
                cout << "Ingrese el daño a recibir: " << endl;
                cin >> danio;
                recibirDanio(danio);
                break;
            case 4:
                verEstado();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Opción igresada NO corresponde...\nIntente nuevamente..." << endl;
        }
    }

    return 0;
}