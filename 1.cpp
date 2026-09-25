#include <iostream>
#include <Windows.h> // Incluimos esta librería para usar otro set de caracteres
#include <string>
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
 
string mostrarFichaTecnica(string nombre,int vida, float danio, float armadura, bool llave){
    string respuesta = "";
    cout << "\n" << endl;
    cout << "Ficha Técnica" << endl;
    cout << "=============" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << to_string(vida) << endl;
    cout << "Daño: " << to_string(danio) << endl;
    cout << "Armadura: " << to_string(armadura) << endl;
    cout << "Llave: " << evaluarLlave(llave) << endl;
    return respuesta;
}


int main(){
    // Defino el set de caracteres UTF-8 (latino) para la salida de la consola
    SetConsoleOutputCP(CP_UTF8);

    string nombre = "";
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

    mostrarFichaTecnica(nombre,vida,danio,armadura,llave);

    cout << "\n" << endl;
    int danioRecibido = 0;
    cout << "Ingrese el daño..." << endl;
    cin >> danioRecibido;
    cout << "Recibimos "<< danioRecibido <<" de daño!" << endl;
    vida = vida - danioRecibido;
    llave = true;

    mostrarFichaTecnica(nombre,vida,danio,armadura,llave);

    return 0;
}