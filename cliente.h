// ARCHIVO HEADER DE LA CLASE CLIENTE//

#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include<fstream>

#include <string>
#include <sstream>

using namespace std;

//CLASE RUTINA QUE SE VA A AGREGAR A CLIENTE//
class Rutina{
    private:
        //TIPOS DE RUTINA QUE EXISTEN//
        string tipo;
    public:
        //CONSTRUCTORES//
        Rutina(){
            tipo = "";
        }
        //OPCIONES QUE EXISTEN//
        Rutina(int opc){
            if (opc == 1){
                tipo = "Perder Grasa";
            }else if(opc ==2){
                tipo = "Ganar Musuclo";
            }else if(opc==3){
                tipo="Ganar Fuerza";
            }
        }
        //GETTER DEL TIPO RUTINA//
        string get_rutina(){
            return tipo;
        }
};

//CLASE DIETA QUE SE A A ARGEGAR A CLIENTE//
class Dieta{
    //TIPO DE DIETA//
    private:
        string tipo;
    //CONSTRUCTORES//
    public:
        Dieta(){
            tipo = "";
        }
        //TIPOS DE DIETA QUE EXISTEN//
        Dieta(int opc){
            if (opc == 1){
                tipo = "Hipocalorica";
            }else if(opc ==2){
                tipo = "Hipercalorica";
            }else if(opc==3){
                tipo="Mantenimiento";
            }else if(opc==4){
                tipo="Vegetariana";
            }else if(opc==5){
                tipo="Vegana";
            }else if(opc==6){
                tipo="Sin Gluten";
            }else if(opc==7){
                tipo="Otro";
            }
        }
        //GETER DEL TIPO DE DIETA//
        string get_dieta(){
            return tipo;
        }
};

//CLASE PRINCIPAL "CLIENTE"//
class Cliente{
    //ATRIBUTOS//
    private:
        Rutina rutina; //AGREGAR RUTINA//
        Dieta dieta; //AGREGAR DIETA//
        string nombre, genero; //NOMBRE Y GENERO//
        int id, edad; //ID de cliente y EDAD//
        double peso, altura, estado; //PESO, ALTURA, ESTADO FISICO//
        double IMC = peso/(altura*altura); // FORMULA DEL INDICE DE MASA CORPORAL//

    public:
        void crea_cliente(); //SE DEFINE LUEGO//
        //CONSTRUCTORES//
        Cliente(){
            nombre = "";
            estado = 0;
            id = 0;
            edad = 0;
            peso = 0.0;
            altura = 0.0;
            genero = "";
        };
        Cliente(string nom, int age, int ID, double kg, double alt, string gen, double act, Rutina r, Dieta d){
            nombre = nom;
            edad = age;
            id = ID;
            peso = kg;
            altura = alt;
            genero = gen;
            estado = act;
            rutina = r;
            dieta = d;
            
        }
        
        //GETTERS//
        string get_nombre(){return nombre;}
        string get_genero(){return genero;}
        string get_rutina(){return rutina.get_rutina();}
        string get_dieta(){return dieta.get_dieta();}
        double get_imc(double peso, double altura){
            IMC = peso/(altura*altura);
            return IMC;
            }
        double get_peso(){return peso;}
        double get_altura(){return altura;}
        double get_estado(){return estado;}
        int get_id(){return id;}
        int get_edad(){return edad;}

        //FUNCIONES//
        string calc_imc(double imc){
            //TABLAS DE IMC//
            stringstream aux;
            if (imc < 18.5){
                aux<<"Nivel de Peso: Bajo Peso";
            }else if (imc > 18.5 & imc < 24.9){
                aux<<"Nivel de Peso: Normal";
            }else if(imc > 25 & imc < 29.9){
                aux<<"Nivel de Peso: Sobrepeso";
            }else if(imc >30){
                aux<<"Nivel de Peso: Obesidad";
            }
            return aux.str();
        }
        double niv_act=0; //INICIALIZAR VARIABLE//
        double nivel_actividad(){ //PARAMETRO ESTADO FISICO PARA CALCULAR CALORIAS//
            if (estado == 1){
                niv_act = 1.2;
            }else if(estado == 2){
                niv_act = 1.375;
            }else if(estado == 3){
                niv_act = 1.55;
            }else if(estado == 4){
                niv_act = 1.725;
            }else if(estado == 5){
                niv_act = 1.9;
            }
            return niv_act;
        }

        double calorias_mantenimiento=0; //INICIALIZAR VARIABLE//
        double calc_cal_mant(){
            //FORMULA DE HARRIS-BENEDICT//
            if (genero == "M" || genero == "m"){
                calorias_mantenimiento = (10*get_peso()) + (625 *get_altura()) -(5 * get_edad()) + 5;
                calorias_mantenimiento = calorias_mantenimiento * nivel_actividad();
            }else if(genero == "F" || genero == "f"){
                calorias_mantenimiento = (10*peso) + (625 * altura) -(5 * edad) - 161;
                calorias_mantenimiento = calorias_mantenimiento * niv_act;
            }
            return calorias_mantenimiento;
        }
        double cals_mas_menos=0, calorias_dieta=0;//INICIALIZAR VARIABLES//
        double calc_cal_dieta(){
            //CALCULAR CALORIAS DEPENDIENDO DE LA DIETA//
            cals_mas_menos = calc_cal_mant() * .15;
            if (get_dieta() == "Hipocalorica"){
                calorias_dieta = calc_cal_mant() - cals_mas_menos;
            }else if(get_dieta() == "Hipercalorica"){
                calorias_dieta = calc_cal_mant() + cals_mas_menos;
            }else if(get_dieta() == "Mantenimiento"){
                calorias_dieta = calc_cal_mant();
            }else if(get_dieta() == "Vegetariana"){
                calorias_dieta = calc_cal_mant();
            }else if(get_dieta() == "Vegana"){
                calorias_dieta = calc_cal_mant();
            }else if(get_dieta() == "Sin Gluten"){
                calorias_dieta = calc_cal_mant();
            }else if(get_dieta() == "Otro"){
                calorias_dieta = calc_cal_mant();
            }
            return calorias_dieta;
        }

        string to_string(){
            //SE CREA UN STRING PARA QUE SEA MAS SENCILLO IMPRIMIR//
            stringstream aux;
            aux << "ID: " << id+1 << endl << "Nombre: " << nombre << endl << "Genero: " << genero << endl << "Edad: " << edad << endl <<
            "Peso: " << peso << " kg" << endl << "Altura: " << altura << " m" << endl << "IMC: " << get_imc(peso, altura) << endl << 
            calc_imc(get_imc(peso,altura)) << endl <<
            "Rutina: " << get_rutina() << endl << 
            "Dieta: " << get_dieta() << endl << "Calorias Diarias a consumir: " << calc_cal_dieta() << "\n...................................\n";
            
            return aux.str();
        }

};

#endif