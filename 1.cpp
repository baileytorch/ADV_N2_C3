#include <iostream>
#include <Windows.h> // Incluimos esta librería para usar otro set de caracteres
using namespace std;

string evaluarLlave(bool llave){
    string tieneLlave = "";
    if(llave==true){
        tieneLlave = "Tiene la llave";
    }else{
        tieneLlave = "No tiene llave";
    }
    return tieneLlave;
}


int main(){
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

    cout << "\n" << endl;
    cout << "Ficha Técnica" << endl;
    cout << "=============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Daño: " << danio << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Llave: " << evaluarLlave(llave) << endl;

    cout << "\n" << endl;
    cout << "Recibimos 100 daño!" << endl;
    vida = vida - 100;
    llave = true;

    cout << "\n" << endl;
    cout << "Ficha Técnica" << endl;
    cout << "=============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Daño: " << danio << endl;
    cout << "Armadura: " << armadura << endl;
    cout << "Llave: " << evaluarLlave(llave) << endl;

    return 0;
}