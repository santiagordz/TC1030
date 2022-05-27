//EMPLEADO//

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<iostream>
#include<fstream>

using namespace std;

class Empleado{
    protected:
        string nombre;
        int id;
        double salario;
    public:
        string get_nombre(){return nombre;}
        int get_id(){return id;}
        double get_salario(){return salario;}
        Empleado(){
            nombre = "";
            id = 0;
            salario = 0.0;
        }
        Empleado(string nom, int ID, double salary){
            nombre = nom;
            id = ID;
            salario = salary;
        }
};

class Fijo: public Empleado{
    private:
        double salario_mensual;
    public:
        Fijo(){
            salario_mensual = 0.0;
        }
        Fijo(int salario){
            salario_mensual = salario;
        }
        double get_salario(){return salario_mensual;}
};

class PorHora: public Empleado{
    private:
        double pago_x_hora;
        double horas_trabajadas;
        double salario;
    public:
        PorHora(){
            pago_x_hora = 0;
            horas_trabajadas = 0;
        }
        PorHora(double pago, double horas){
            pago_x_hora = pago;
            horas_trabajadas = horas;
        }
        double get_salario(){
            salario = pago_x_hora * horas_trabajadas;
            return salario;
        }
};
#endif;