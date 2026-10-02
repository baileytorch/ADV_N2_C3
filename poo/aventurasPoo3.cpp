#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// Clase PADRE o SUPERCLASE
class Personaje
{
    protected:
        string nombre;
        int vida;
        bool vivo;

    public:
        Personaje(string nombrePersonaje, int vidaPersonaje, bool personajeVivo) : 
            nombre(nombrePersonaje), vida(vidaPersonaje), vivo(personajeVivo) {}

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

        virtual void atacar()
        {
            cout << nombre << " ataca. " << endl;
        }
};

// Clases HIJA o SUBCLASE
class Guerrero : public Personaje
{
    private:
        string arma;

    public:
        Guerrero(string nombrePersonaje, int vidaPersonaje, bool personajeVivo, string nombreArma) : 
            Personaje(nombrePersonaje,vidaPersonaje,personajeVivo), arma(nombreArma) {}
            
        void atacar() override
        {
            cout << nombre << " golpea con su " << arma << endl;
        }
};

class Mago : public Personaje
{
    private:
        string arma;

    public:
        Mago(string nombrePersonaje, int vidaPersonaje, bool personajeVivo, string nombreArma) : 
            Personaje(nombrePersonaje,vidaPersonaje,personajeVivo), arma(nombreArma) {}

        void atacar() override
        {
            cout << nombre << " arroja un hechizo con su " << arma << endl;
        }
};

class Arquero : public Personaje
{
    private:
        string arma;

    public:
        Arquero(string nombrePersonaje, int vidaPersonaje, bool personajeVivo, string nombreArma) : 
            Personaje(nombrePersonaje,vidaPersonaje,personajeVivo), arma(nombreArma) {}
        
        void atacar() override
        {
            cout << nombre << " dispara con su " << arma << endl;
        }
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
    Personaje* jugador = nullptr;

    cout << "Cuál es el nombre de su personaje?: " << endl;
    getline(cin, nombre);

    cout << "Cuál será la vida de " << nombre << "?:" << endl;
    cin >> vida;

    cout << "Qué tipo de personaje construiremos?:" << endl;
    cout << "[1] Guerrero" << endl;
    cout << "[2] Mago" << endl;
    cout << "[3] Arquero" << endl;
    cin >> tipoPersonaje;

    switch (tipoPersonaje)
    {
        case 1:
            jugador = new Guerrero(nombre,vida,vivo,"Espada");
            break;
        case 2:
            jugador = new Mago(nombre,vida,vivo,"Báculo");
            break;
        case 3:
            jugador = new Arquero(nombre,vida,vivo,"Arco");
            break;
        
        default:
            break;
    }

    cout << "\nAventuras de " << nombre << endl;
    while (opcion != 6 && vivo)
    {
        cout << "[1] Avanzar" << endl;
        cout << "[2] Saltar" << endl;
        cout << "[3] Recibir Daño" << endl;
        cout << "[4] Ver estado del personaje" << endl;
        cout << "[5] Atacar" << endl;
        cout << "[6] Salir" << endl;
        cout << "\nSeleccione su opción [1-6]:" << endl;
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
            jugador->avanzar();
            break;
        case 2:
            jugador->saltar();
            break;
        case 3:
            cout << "Ingrese el daño a recibir: " << endl;
            cin >> danio;
            jugador->recibirDanio(danio);
            break;
        case 4:
            jugador->verEstado();
            break;
        case 5:
            jugador->atacar();
            break;
        case 6:
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