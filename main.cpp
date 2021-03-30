/*
-> Domínguez Martínez Edder Emmanuel
-> Esqueda Rodríguez, Fabián Alejandro.
-> Godoy Rodríguez, Berenice.
-> Gómez Jiménez, Ángel Armando.
-> Gómez Ramírez, Eduardo Fabián.

Sección: D05
Calendario: 2021-A
*/ 

#include <iostream>
#include <fstream>
#include<iomanip>

#include "cliente.h"

using namespace std;

int main(){
    system("cls");
    
    system("color F1");
    
    //Atributos que tenemos en la clase
    int numeroCuenta;
    char apellido[15];
    char primerNombre[10];
    double saldo;

    //Este objeto me va a servir para escribir datos en el archivo
    ofstream creditoSalida("credito.dat", ios:: out | ios::binary);//Se abre en modo binario para la salida de los datos
                                                                            //Esto es requerido para escribir registros de longitud fija
    
    if(!creditoSalida){
        cerr<<"EL ARCHIVO NO SE PUDO ABRIR DE FORMA CORRECTA\n";
        exit(1);
    }

    Cliente cliente;//Objeto de tipo cliente
    size_t i = 0;

    cout<<"Escriba el numero de cuenta (de 1 a 100, 0 para terminar la entrada)\n? ";
    cin>>numeroCuenta;

    while(numeroCuenta > 0 && numeroCuenta <= 100){
        cout<<"Ingrese su apellido: ";
        cin>>setw(15)>>apellido;//En el setw tiene 15 porque ese es el tamaño del arreglo apellido

        cout<<"Ingrese su primer nombre: ";
        cin>>setw(10)>>primerNombre;//En el setw tiene 10 porque ese es el tamaño del arreglo primerNombre

        cout<<"Ingrese su saldo: ";
        cin>>saldo;

        //Establecer los valores de los atributos
        cliente.establecerNumeroCuenta(numeroCuenta);
        cliente.establecerApellido(apellido);
        cliente.establecerPrimerNombre(primerNombre);
        cliente.establecerSaldo(saldo);

        //busca la posición en el archivo del registro especificado por el usuario
        //Busca en que posicion del archivo voy a escribir cliente
        creditoSalida.seekp((cliente.obtenerNumeroCuenta() - 1) * sizeof(Cliente));

        //escribe la información especificada por el usuario en el archivo
        creditoSalida.write(reinterpret_cast < const char * > (&cliente), sizeof(Cliente));

        //Hacer otro registro
        cout<<"\nEscriba el numero de cuenta (de 1 a 100, 0 para terminar la entrada)\n?";
        cin>>numeroCuenta;
    }

    creditoSalida.close();

    return 0;
    
}//fin del main