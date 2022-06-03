//ARCHIVO HEADER DE LA CLASE EMPLEADO E HIJAS//

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<iostream>
#include<fstream>

#include <string>
#include <sstream>

using namespace std;

//CLASE EMPLEADO//
class Empleado{
    protected:
        //ATRIBUTOS//
        string nombre; //NOMBRE EMPLEADO//
        string tipo; //TIPO DE EMPLEADO (2 TIPOS)//
        int id; //ID DE EMPLEADO//

    public:
        //CONSTRUCTORES//
        Empleado(): nombre(""), tipo(""), id(0){};
        Empleado(string nom, string tip, int id_num): nombre(nom), tipo(tip), id(id_num){};

        //GETTERS//
        string get_nombre(){return nombre;};
        string get_tipo(){return tipo;};
        int get_id(){return id;};

        //FUNCIONES VIRTUALES PARA POLIMORFISMO//
        virtual double pago_mensual() = 0;
        virtual string to_string() = 0;
};

//CLASE FIJO, DERIVADA DE EMPLEADO//
class Fijo: public Empleado{
    private:
        //ATRIBUTOS//
        double salario_mensual; //SALARIO MENSUAL TOTAL//

    public:
        //CONSTRUCTORES//
        Fijo(): Empleado(), salario_mensual(0){};
        Fijo(string nom, int id, double salario): Empleado(nom,"Fijo",id), salario_mensual(salario){};

        //FUNCIONES//
        double pago_mensual(){return salario_mensual;};

        string to_string(){
            stringstream aux;
            aux <<  "ID: " << id+1 << endl << "Nombre: " << nombre << endl << "Tipo de Empleado: " << tipo << endl
            << "Salario Mensual: $" << pago_mensual() << endl;
            return aux.str();
        };
};

//CLASE POR HORA, DERIVADA DE EMPLEADO//
class PorHora: public Empleado{
    private:
        //ATRIBUTOS//
        double pago_x_hora; //SALARIO POR HORA//
        double horas_trabajadas; //HORAS TRABAJADAS AL MES//

    public:
        //CONSTRUCTORES//
        PorHora(): Empleado(), pago_x_hora(0), horas_trabajadas(0){};
        PorHora(string nom, int id, double x_hora, double h_trbj): Empleado(nom, "Por Hora", id), pago_x_hora(x_hora), 
            horas_trabajadas(h_trbj){};

        //GETTERS//
        double get_pago_x_hora(){return pago_x_hora;};
        double get_horas_trabajadas(){return horas_trabajadas;};

        //FUNCIONES//
        double pago_mensual(){return pago_x_hora*horas_trabajadas;}; //SALARIO POR HORA * HORAS TRABAJADAS AL MES = SALARIO TOTAL//
        
        string to_string(){
            stringstream aux;
            aux  << "ID: " << id+1 << endl << "Nombre: " << nombre << endl << "Tipo de Empleado: " << tipo << endl 
            << "Horas Trabajadas: " << horas_trabajadas << endl << "Pago Por Hora: $" << pago_x_hora << endl
            << "Salario Mensual: $" << pago_mensual() << endl;
            return aux.str();
        };
};
#endif