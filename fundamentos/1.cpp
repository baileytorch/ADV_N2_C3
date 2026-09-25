#include <iostream>
#include <Windows.h> // Incluimos esta librería para usar otro set de caracteres
using namespace std;

string evaluarLlave(bool llave)
{
    string tieneLlave = "";
    if (llave == true)
    {
        tieneLlave = "Tiene la llave";
    }
    else
    {
        tieneLlave = "No tiene llave";
    }
    return tieneLlave;
}

string fichaTecnica(string name, int life, float damage, float armor, bool key)
{
    string respuesta = "";

    cout << "\n"
         << endl;
    cout << "Ficha Técnica" << endl;
    cout << "=============" << endl;
    cout << "Nombre: " << name << endl;
    cout << "Vida: " << life << endl;
    cout << "Daño: " << damage << endl;
    cout << "Armadura: " << armor << endl;
    cout << "Llave: " << evaluarLlave(key) << endl;

    return respuesta;
}

int recibirDanio(int life, float damage)
{
    int respuesta = 0;

    cout << "\n"
         << endl;
    cout << "Recibimos " << damage << " daño!" << endl;
    respuesta = life - damage;

    return respuesta;
}

int main()
{
    // Defino el set de caracteres UTF-8 (latino) para la salida de la consola
    SetConsoleOutputCP(CP_UTF8);

    string nombre = "Torch";
    int vida = 500;
    float danio = 50;
    float armadura = 60;
    bool llave = false;

    // Comentario de 1 línea

    /*
        Comentario
        de múltiples
        líneas
    */

    /*
        Sin tener un entorno gráfico,
        el programa escrito mostrará todos sus resultados
        mediante el TERMINAL
    */

    fichaTecnica(nombre, vida, danio, armadura, llave);

    // while (vida > 0)
    // {
    //     float danioIngresado = 0.0;
    //     cout << "Ingrese Daño a Recibir: " << endl;
    //     cin >> danioIngresado;

    //     vida = recibirDanio(vida, danioIngresado);
    // }

    for (int contador = 1; contador < 5; contador++)
    {
        float danioIngresado = 0.0;
        cout << "Ingrese Daño a Recibir: " << endl;
        cin >> danioIngresado;

        vida = recibirDanio(vida, danioIngresado);
    }    

    llave = true;

    fichaTecnica(nombre, vida, danio, armadura, llave);

    return 0;
}