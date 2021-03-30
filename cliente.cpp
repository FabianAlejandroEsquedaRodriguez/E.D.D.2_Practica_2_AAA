#include "cliente.h"

Cliente::Cliente(int valorNumeroCuenta, string valorApellido, 
                 string valorPrimernombre, double valorSaldo){
                     
    establecerNumeroCuenta(valorNumeroCuenta);
    establecerApellido(valorApellido);
    establecerPrimerNombre(valorPrimernombre);
    establecerSaldo(valorSaldo);
}

void Cliente::establecerNumeroCuenta(int valorNumeroCuenta){
    numeroCuenta = valorNumeroCuenta;
}
int Cliente::obtenerNumeroCuenta() const{
    return numeroCuenta;
}

void Cliente::establecerApellido(string valorApellido){
    // copia a lo más 15 caracteres de la cadena a apellidoPaterno
    const char *valorApellidoPaterno = valorApellido.data();//Convierte el valor de esa string en un arreglo
    int longitud = valorApellido.size();//Saber cual es el tamaño
    longitud = (longitud < 15)*longitud + (longitud >= 15)*14;//Si tengo caracteres de mas o de menos,
                                                                // solo contará los del tamaño del arreglo
    strncpy( apellido, valorApellidoPaterno, longitud );
    apellido[ longitud ] = '\0'; // adjunta un carácter nulo a apellidoPaterno
}
string Cliente::obtenerApellido() const{
    return apellido;
}

void Cliente::establecerPrimerNombre(string valorPrimernombre){
    // copia a lo más 10 caracteres de la cadena a primerNombre
    const char *valorPrimerNombre = valorPrimernombre.data();//Convierte el valor de esa string en un arreglo
    int longitud = valorPrimernombre.size();//Saber cual es el tamaño
    longitud = (longitud < 10)*longitud + (longitud >= 10)*9;//Si tengo caracteres de mas o de menos,
                                                                // solo contará los del tamaño del arreglo
    strncpy( primerNombre, valorPrimerNombre, longitud );//Copiar el valor del primer nombre al atributo primerNombre
    primerNombre[ longitud ] = '\0'; // adjunta un carácter nulo a primerNombre
}
string Cliente::obtenerPrimerNombre() const{
    return primerNombre;
}

void Cliente::establecerSaldo(double valorSaldo){
    saldo = valorSaldo;
}
double Cliente::obtenerSaldo() const{
    return saldo;
}