#include <iostream>
using namespace std;

int main()
{
    // Defininimos nuestro personaje inicial con sus atributos
    string nombre = "Cachupin";
    bool estaVivo = true;
    float velocidad = 4.5;
    int monedas = 0;
    int vida = 10;

    cout << "Bienvenido a las aventuras de..."<<endl;
    cout << "Vida: " << vida << endl;
    cout << "Velocidad: " << velocidad << endl;
    cout << "Monedas: " << monedas << endl;
    
    cout << "Atacaron a Cachupin con 2 de daño..." << endl;
    vida = vida - 2;
    cout << "Vida restante: " << vida << endl;
    return 0;
}
