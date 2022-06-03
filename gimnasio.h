//ARCHIVO HEADER DE LA CLASE GIMNASIO//

#ifndef GIMNASIO_H
#define GIMNASIO_H

//INCLUIR CLIENTE Y EMPLEADO//
#include "cliente.h"
#include "empleado.h"

const int MAX = 1000; //INICIALIZAR VARIABLE//

//CLASE GIMNASIO//
class Gimnasio{
    //ATRIBUTOS//
    private: 
        Cliente clientes[MAX]; //LISTA DE CLIENTES//
        Empleado *empleados[MAX]; //LISTA TIPO POINTER DE EMPLEADOS (POLIMORFISMO)//
        int nomina; //NUMERO DE EMPLEADOS//
        int usuario; //NUMERO DE CLIENTES//

    public:
        //CONSTRUCTORES//
        Gimnasio(){nomina=0;usuario=0;};
        Gimnasio(int _nomina, int _usuario){nomina=_nomina; usuario=_usuario;};
        
        //GETTERS//
        int get_nomina(){return nomina;};
        int get_usuario(){return usuario;};
        void get_clientes(int _id){
            cout << clientes[_id-1].to_string();
        }

        //FUNCIONES//
        void crea_ejemplo(); //CREAR EJEMPLO PARA EL MAIN//
        void muesta_clientes(); //MOSTRAR TODOS LOS CLIENTES//
        void muestra_empleados(); //MOSTRAR TODOS LOS EMPLEADOS//
        void muestra_empleados(string tipo); //MOSTRAR EMPLEADOS DE ALGUN TIPO EN ESPECIAL//
        void calc_paga_empleados(); //CALCULAR EL SALARIO TOTAL DE TODOS LOS EMPLEADOS//
        void agrega_cliente(Cliente c); //AGREGAR CLIENTE AL GYM CON CLIENTE CREADO EN EL MAIN//
        void agrega_cliente(string nom, int edad, double kg, double m,string g, double estado, Rutina r, Dieta d); //AGREGAR CLIENTE DESDE CONSTRUCTOR//
        void agrega_Fijo(string nom, double salario); //AGREGA EMPLEADO FIJO DESDE CONSTRUCTOR//
        void agrega_PorHora(string nom, double horas, double pago); //AGREGA EMPLEADO POR HORA DESDE CONSTRUCTOR//
        
        //DUDAS PARA ASESORIA//
            //void agrega_Fijo(Fijo e);
            //void agrega_PorHora(PorHora e);
            //void agrega_empleado(Empleado e);
};

//DEFINIR FUNCIONES//
void Gimnasio::crea_ejemplo(){
    //2 OBJETOS DE CLASE CLIENTE EN LA STACK//
    clientes[usuario] = Cliente("Mauricio", 65, usuario, 89.2, 1.77, "M", 1, Rutina(1), Dieta(1)); usuario++;
    clientes[usuario] = Cliente("Juan", 18, usuario, 88.5, 1.90, "M", 3, Rutina(3), Dieta(3)); usuario++;
    //2 OBJETOS DE CLASE EMPLEADO EN LA HEAP//
    empleados[nomina] = new Fijo("Jose", nomina, 5000); nomina++;
    empleados[nomina] = new PorHora("Natalia", nomina, 80, 120); nomina++;
};

void Gimnasio::muesta_clientes(){
    cout << "-----------------------------------------\n";
    cout << "Lista de Clientes:" << endl << endl;
    for (int i=0; i < usuario; i++)//TODOS LOS CLIENTES QUE SE TIENEN REGISTRADOS//
        cout << clientes[i].to_string() << endl; //FUNCION to_string() DE CLASE CLIENTE//
        cout << "-------------------------------------------\n\n";
};

void Gimnasio::muestra_empleados(){
    cout << "-----------------------------------------\n";
    cout << "Lista de Empleados:" << endl << endl;
    for (int i=0; i< nomina; i++) //TODOS LOS EMPLEADOS QUE SE TIENEN REGISTRADOS//
        cout << empleados[i] -> to_string() << endl; //FUNCION to_string() CAMBIA SI ES POR HORA O FIJO//
    cout << "-------------------------------------------\n";
};

void Gimnasio::muestra_empleados(string tipo){
    cout << "Lista de Empleados de Tipo: " << tipo << "\n\n";
    for (int i=0; i<nomina; i++) //BUSCA EN TODOS LOS EMPLEADOS REGISTRADOS//
        if (empleados[i] -> get_tipo() == tipo) //TODOS LOS EMPLEADOS DEL TIPO ESPECIFICADO//
            cout << empleados[i] -> to_string() << endl;
};

void Gimnasio::calc_paga_empleados(){
    double total = 0; //INICIALIZAR VARIABLE//
    for(int i=0; i<nomina; i++)
        total = total + empleados[i] ->pago_mensual(); //pago_mensual() CAMBIA DEPENDIENDO DEL TIPO DE EMPLEADO//
        cout << "La paga total de " << nomina << " empleados es de: $" << total;
};

void Gimnasio::agrega_cliente(string nom, int age, double peso, double altura, string g, double estado, Rutina r, Dieta d){
    //AGREGA A NUESTRO ARREGLO "CLIENTES" CON CONSTRUCTOR//
    clientes[usuario] = Cliente(nom,age, usuario, peso, altura, g, estado, r, d); usuario++;
};

void Gimnasio::agrega_cliente(Cliente c){
    //AGREGA A NUESTRO ARREGLO "CLIENTES" CON OBJETO//
    clientes[usuario] = c; usuario++;
}

void Gimnasio::agrega_Fijo(string nom, double salario){
    //AGREGA A NUESTRO ARREGLO DE PUNTEROS "EMPLEADOS" CON CONSTRUCTOR//
    empleados[nomina] = new Fijo(nom, nomina, salario); nomina++; //SE USA NEW PARA CREARLO EN EL HEAP//
};

void Gimnasio::agrega_PorHora(string nom, double horas, double pago){
    //AGREGA A NUESTRO ARREGLO DE PUNTEROS "EMPLEADOS" CON CONSTRUCTOR//
    empleados[nomina] = new PorHora(nom, nomina, pago, horas); nomina++; //SE USA NEW PARA CREARLO EN EL HEAP//
};

#endif