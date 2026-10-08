#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

class Item
{
    private:
        string nombre;
        string accion;
        int cantidadUsos;
    public:
    // Al asignarle valores por defecto a un atributo, podemos crear objetos vacíos
    // para luego asignarle valores a sus tributos.
        Item(string nomIt = "", string accIt = "", int cantUs = 0):
            nombre(nomIt),accion(accIt),cantidadUsos(cantUs){}
        
        string mostrarNombre() const { return nombre; }
};

class Personaje
{
    protected:
        string nombre;
        int vida;
        bool vivo;
        vector<Item> inventario;

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

        void agregarItem(const Item& item){
            inventario.push_back(item);
            cout << "agregado el item: " << item.mostrarNombre() << endl;
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

Item recogerItem(){
    string nombreItem;
    string accionItem;
    int usos;
    int itemSeleccionado;

    cout << "Has encontrado un cofre con algunos objetos...\nEscoge uno de ellos..." << endl;
    cout << "[1] Flecha Espectral" << endl;
    cout << "[2] Poción del Ether" << endl;
    cout << "[3] Menta de Resurrección" << endl;
    cin >> itemSeleccionado;

    switch (itemSeleccionado)
    {
    case 1:
        nombreItem = "Flecha Espectral";
        accionItem = "Lanza una flecha que ataca a un enemigo cualquiera con una bomba.";
        usos = 1;
        break;
        
    case 2:
        nombreItem = "Poción del Ether";
        accionItem = "Crea un aura que daña a los enemigos cercanos por 5 segundos.";
        usos = 3;
        break;
        
    case 3:
        nombreItem = "Menta de Resurrección";
        accionItem = "Vuelves a la vida con 100% de HP.";
        usos = 1;
        break;
    
    default:
        nombreItem = "Anillo de Bronce";
        accionItem = "Aumenta la vida en 10%.";
        usos = 1;
        break;
    }
    Item item(nombreItem,accionItem,usos);
    return item;
}

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
    Item itemRecibido;

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
    while (opcion != 7 && vivo)
    {
        cout << "[1] Avanzar" << endl;
        cout << "[2] Saltar" << endl;
        cout << "[3] Recibir Daño" << endl;
        cout << "[4] Ver estado del personaje" << endl;
        cout << "[5] Atacar" << endl;
        cout << "[6] Abrir cofe" << endl;
        cout << "[7] Salir" << endl;
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
            itemRecibido = recogerItem();
            jugador->agregarItem(itemRecibido);
            break;
        case 7:
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