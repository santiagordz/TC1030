//CLIENTE//

#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include<fstream>

using namespace std;

class Rutina{
    private:
        string tipo;
    public:
        Rutina(){
            tipo = "";
        }
        Rutina(string type){
            tipo = type;
        }
        string get_rutina(){
            if (tipo == "Pesas")
                cout << "Hola" << endl;
        }
};

class Dieta{
    private:
        string tipo;
    public:
        Dieta(){
            tipo = "";
        }
        Dieta(string type){
            tipo = type;
        }
        string get_dieta(){
            if (tipo == "Vegetariano")
            cout << "Hola" << endl;
        }
};

class Cliente{
    protected:
        Rutina rutina;
        Dieta dieta;
        string nombre;
        int id;
        double peso;
        double altura;
    public:
        Cliente(){
            nombre = "";
            id = 0;
            peso = 0.0;
            altura = 0.0;
        };
        Cliente(string nom, int ID, int kg, int m){
            nombre = nom;
            id = ID;
            peso = kg;
            altura = m;
        }
        string get_nombre(){return nombre;}
        int get_id(){return id;}
        double get_peso(){return peso;}
        double get_altura(){return altura;}
        Rutina get_rutina(){
            get_rutina();
        }
        Dieta get_dieta(){
            get_dieta();
        }
};

#endif