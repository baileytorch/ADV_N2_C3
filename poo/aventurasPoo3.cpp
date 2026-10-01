#include <iostream>
#include <windows.h>
using namespace std;

// Clase PADRE o SUPERCLASE
class Personaje
{
private:
    string nombre;
    int vida;
    bool vivo;

public:
    Personaje(string nombrePersonaje, int vidaPersonaje, bool personajeVivo) : nombre(nombrePersonaje), vida(vidaPersonaje), vivo(personajeVivo) {}

    void avanzar()
    {
        cout << nombre << " avanza..." << endl;
    }

    void saltar()
    {
        cout << nombre << " salta..." << endl;
    }

    void recibirDanio(int danioJugador)
    {
        // Modo clásico de realizar una sustracción
        // vida = vida - danio;
        vida -= danioJugador;

        cout << nombre << " fue atacado con " << danioJugador << " de daño." << endl;
        cout << nombre << " tiene " << vida << " de vida restante." << endl;

        if (vida <= 0)
        {
            vivo = false;
            vida = 0;
            cout << "GAME OVER!" << endl;
        }
    }

    void verEstado()
    {
        cout << "Estado de " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Está vivo?: " << (vivo ? "Si" : "No") << endl;
    }
};

// Clases HIJA o SUBCLASE
class Guerrero : public Personaje
{
private:
    string arma;

public:
    Guerrero(string nombrePersonaje, int vidaPersonaje, bool personajeVivo, string nombreArma) : Personaje(nombrePersonaje, vidaPersonaje, personajeVivo), arma(nombreArma) {}
};

class Mago : public Personaje
{
private:
    string arma;

public:
    Mago(string nombrePersonaje, int vidaPersonaje, bool personajeVivo, string nombreArma) : Personaje(nombrePersonaje, vidaPersonaje, personajeVivo), arma(nombreArma) {}
};

class Arquero : public Personaje
{
private:
    string arma;

public:
    Arquero(string nombrePersonaje, int vidaPersonaje, bool personajeVivo, string nombreArma) : Personaje(nombrePersonaje, vidaPersonaje, personajeVivo), arma(nombreArma) {}
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int opcion = 0;
    int danio = 0;
    int vida;
    int tipoPersonaje;
    string nombre;
    bool vivo = true;

    cout << "Cuál es el nombre de su personaje?: " << endl;
    getline(cin, nombre);

    cout << "Cuál será la vida de " << nombre << "?:" << endl;
    cin >> vida;

    Personaje jugador(nombre,vida,vivo);

    cout << "Qué tipo de personaje constriremos?:" << endl;
    cout << "[1] Guerrero" << endl;
    cout << "[2] Mago" << endl;
    cout << "[3] Arquero" << endl;
    cin >> tipoPersonaje;

    switch (tipoPersonaje)
    {
        case 1:
            Guerrero guerrero(jugador,"Espada");
            break;
        case 2:
            Mago jugador(nombre,vida,vivo,"Báculo");
            break;
        case 3:
            Arquero jugador(nombre,vida,vivo,"Arco");
            break;
        
        default:
            break;
    }

    cout << "\nAventuras de " << nombre << endl;
    while (opcion != 5 && vivo)
    {
        cout << "[1] Avanzar" << endl;
        cout << "[2] Saltar" << endl;
        cout << "[3] Recibir Daño" << endl;
        cout << "[4] Ver estado del personaje" << endl;
        cout << "[5] Salir" << endl;
        cout << "\nSeleccione su opción [1-5]:" << endl;
        cin >> opcion;

        // OPCION espera el ingreso de un número, de lo contrario entra en un estado de error
        if (cin.fail())
        {
            cin.clear();             // Limpia el estado de error
            cin.ignore(10000, '\n'); // Descarta el texto inválido/búfer
            opcion = 0;              // Reinicia la variable
            cout << "Entrada inválida. Por favor, ingrese un número.\n"
                 << endl;
            continue; // Salta directamente al inicio del ciclo while
        }

        switch (opcion)
        {
        case 1:
            jugador.avanzar();
            break;
        case 2:
            jugador.saltar();
            break;
        case 3:
            cout << "Ingrese el daño a recibir: " << endl;
            cin >> danio;
            jugador.recibirDanio(danio);
            break;
        case 4:
            jugador.verEstado();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Opción igresada NO corresponde...\nIntente nuevamente...\n"
                 << endl;
            opcion = 0;
            break;
        }
    }

    return 0;
}