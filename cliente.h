#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string.h>
using namespace std;

class Cliente{

public:
    //Constructor parametrizado
    Cliente(int = 0, string = " ", string = " ", double = 0.0);

    //Metodos Getters y Setters
    void establecerNumeroCuenta(int);
    int obtenerNumeroCuenta() const;

    void establecerApellido(string);
    string obtenerApellido() const;

    void establecerPrimerNombre(string);
    string obtenerPrimerNombre() const;

    void establecerSaldo(double);
    double obtenerSaldo() const;
    
private: //Atributos
    int numeroCuenta;
    char apellido[15];
    char primerNombre[10];
    double saldo;
};

#endif //CLIENTE_H
