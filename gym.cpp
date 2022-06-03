//Santiago Rodriguez Murialdo
// A01704109

//PROYECTO FINAL: TC1030

#include "gimnasio.h"

//FUNCION PARA PEDIRLE AL USUARIO UN CLIENTE//
string* crea_cliente(){
    //ARRGELO DE PUNTEROS A REGRESAR//
    string* clientes = new string[8]; //NOMBRE: "CLIENTES"//
    
    //VARIABLES//
    string nom, edad, peso, gen, altura, estado, rutina, dieta, objetivos2; 
    int objetivos,a=0,x=0, y=0, z=0, opc_d, objetivos3;
    int b = 0;
    
    //PREGUNTAS INICIALES//
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"Bienvenido al registro de clientes, vamos a crear su perfil\n";
    cout<<"\nCual es su nombre?: "; cin>>nom; //NOMBRE
    cout<<"\nCual es su edad?: "; cin>>edad; //EDAD
    cout<<"\nCual es su genero?: ";
    while (a==0){
        cout<<"[M/F]: "; cin>>gen; //GENERO
        if (gen == "M" || gen =="F"){
            a=1;
        }else{
            cout << "\nOpcion No Valida\n";
        }
    }
    cout<<"\nCual es su peso actual (kg)?: "; cin>>peso; //PESO
    cout<<"\nCual es su altura (m)?: "; cin>>altura; //ALTURA
    cout<<"\nCual es su nivel de actividad fisica?\n" << "\n\t1. Poco o Ningun Ejercicio\n\t2. Ejercicio Ligero (1-3 Veces Por Semana)\n\t3. Ejercicio Moderado (3-5 Veces Por Semana)\n\t4. Ejercicio Fuerte (6-7 Veces Por Semana)\n\t5. Ejercicio Muy Fuerte (2 Veces al Dia)\n";    
    while (b==0){
        cout<<"\nEscoja una opcion [1,2,3,4,5]: "; cin>>objetivos3; //ESTADO
        if (objetivos3 == 1){
            estado = "1";
            b = 1;
        } else if (objetivos3 == 2){
            estado = "2";
            b = 1;
        }else if(objetivos3 == 3){
            estado = "3";
            b = 1;
        }else if(objetivos3 == 4){
            estado = "4";
            b = 1;
        }else if(objetivos3 == 5){
            estado = "5";
            b = 1;
        }
        else{
            cout << "Inserte una opcion valida\n";
        }
    }
    cout<<"\nCuales Son Sus Objetivos en el gym? \n" << "\n\t1. Perder Grasa\n\t2. Ganar Musculo\n\t3. Ganar Fuerza\n"; 
    while (x==0){
        cout<<"\nEscoja una opcion [1,2,3]: "; cin>>objetivos; //RUTINA Y DIETA//
        if (objetivos == 1){
            rutina = "1";
            dieta = "1";
            x = 1;
        } else if (objetivos == 2){
            rutina = "2";
            dieta = "2";
            x = 1;
        }else if(objetivos == 3){
            rutina = "3";
            dieta = "3";
            x = 1;
        }
        else{
            cout << "Inserte una opcion valida\n";
        }
    }
    
    cout<<"\nTiene Alguna Dieta en especial?";
    while(y==0){
        cout << "[S/N]: "; cin>>objetivos2; //DIETA
        if (objetivos2 == "S" || objetivos2 == "s"){
            cout << "Que tipo?: \n" << "\n\t1. Vegetariana\n\t2. Vegana\n\t3. Sin Gluten\n\t4. Otro\n"; 
            while(z==0){
                cout << "\nEscoja una opcion: "; cin >> opc_d;
                if(opc_d == 1){
                    dieta = "4";
                    z = 1;
                }else if(opc_d == 2){
                    dieta = "5";
                    z = 1;
                }else if(opc_d == 3){
                    dieta = "6";
                    z = 1;
                }else if(opc_d ==4){
                    dieta = "7";
                    z = 1;
                }
            y = 1;
            }
        }else if(objetivos2 == "N" || objetivos2 == "n"){
            cout << "\nExelente!";
            y = 1;
        }
        else{
            cout << "\nOpcion No Valida\n";
        }
    }
    cout << "\nGracias Por Registrarse!!\n" << endl;

    //GUARDAR VARIABLES//
    clientes[0] = nom;
    clientes[1] = edad;
    clientes[2] = gen;
    clientes[3] = peso;
    clientes[4] = altura;
    clientes[5] = estado;
    clientes[6] = rutina;
    clientes[7] = dieta;

    //RETURN//
    return clientes;
};

//FUNCION PARA PEDIRLE AL USUARIO UN EMPLEADO//
string* crea_empleado(){
    string* empleados = new string[5]; //ARREGLO POINTER "EMPLEADO"//

    //INICIALIZAR VARIABLES//
    string nom, tipo, salario, horas, pago;
    int x=0, opc1;

    cout << "\n------------------------------------------------------------------\n";
    cout << "Bienvenido al registro de STAFF de trabajo, vamos a registrarlo\n";
    cout <<"\nCual es su nombre?: "; cin>>nom; //NOMBRE
    cout <<"\nQue tipo de STAFF va a ser?: " << "\n\n\t1. Fijo\n\t2. Por Hora\n";
    while(x==0){
        cout<<"\nEscoja una opcion: "; cin>>opc1; //TIPO
        if (opc1 == 1){
            tipo = "1";
            x = 1;
        }else if(opc1 == 2){
            tipo = "2";
            x = 1;
        }else{
            cout<<"\nOpcion Invalida\n";
        }
    }
    if (tipo=="1"){ //FIJO//
        cout << "\nDe cuanto sera el salario?: "; cin>>salario; //SALARIO_MENSUAL//
    }else if (tipo == "2"){ //POR HORA//
        cout << "\nCuantas horas trabajara al mes?: "; cin>>horas; //HORAS TRABAJADAS//
        cout << "\nCuanto sera el pago por hora?: "; cin>>pago; //SALARIO POR HORA//
    }
    //GUARDAR VARIABLES//
    empleados[0] = nom;
    empleados[1] = tipo;
    empleados[2] = salario;
    empleados[3] = horas;
    empleados[4] = pago;

    //RETURN//
    return empleados;

}

//FUNCION MAIN//
int main(){   

    //.......................................................GIMNASIO............................................................//
    
    //CREAR OBJETO GIMNASIO//
    Gimnasio gimnasio; //CONSTRUCTOR POR DEFAULT (Nomina=0, Usuario=0) //
    gimnasio.crea_ejemplo(); //CREAR DATOS PARA TRABAJAR (2 CLIENTES, 2 EMPLEADOS)//
    
    //.......................................................CLIENTES............................................................//

    //CREAR CLIENTE CON crea_cliente()//
    string *datos_cliente; //POINTER DE STRING PARA DATOS DEL CLIENTE//
    datos_cliente = crea_cliente(); //SE GUARDAN LOS DATOS DE crea_cliente() EN datos_cliente[]//

    Cliente cl1(datos_cliente[0], std::stoi(datos_cliente[1]),gimnasio.get_usuario(), std::stod(datos_cliente[3]),
        std::stod(datos_cliente[4]), datos_cliente[2], std::stod(datos_cliente[5]), 
        Rutina(std::stoi(datos_cliente[6])), Dieta(std::stoi(datos_cliente[7])));

    gimnasio.agrega_cliente(cl1);  //agrega_cliente(Cliente e)//

    //CREAR CLIENTE CON agrega_cliente(string, int, double, string, double, Rutina, Dieta)//
    gimnasio.agrega_cliente("Santiago", 19, 78, 1.78, "M", 4, Rutina(1), Dieta(1));

    cout << "----------------------------------------------------------\n"; //SEPARACION PARA VER//

    //......................................................EMPLEADOS............................................................//

    //CREAR CLIENTE CON crea_empleado()//
    string *datos_empleado; //POINTER DE STRING PARA DATOS DEL EMPLEADO//
    datos_empleado = crea_empleado(); //SE GUARDAN LOS DATOS DE crea_emleado() EN datos_empleado[]//
    if (datos_empleado[1] == "1"){ //datos_empleado[1] = tipo de empleado. Tipo = "1": Fijo ->(definido en empleado.h)//
        Fijo emp1(datos_empleado[0], gimnasio.get_nomina(), std::stod(datos_empleado[2]));
        gimnasio.agrega_Fijo(emp1.get_nombre(), emp1.pago_mensual());
    }
    else if(datos_empleado[1] == "2"){ //Tipo = "2": PorHora ->(definido en empleado.h)//
        PorHora emp1(datos_empleado[0], gimnasio.get_nomina(), std::stod(datos_empleado[3]), std::stod(datos_empleado[4]));
        gimnasio.agrega_PorHora(emp1.get_nombre(), emp1.get_horas_trabajadas(), emp1.get_pago_x_hora());
    }
    
    //CREAR EMPLEADO FIJO CON agrega_Fijo(string, double)//
    gimnasio.agrega_Fijo("Marco", 2500);

    //CREAR EMPLEADO POR HORA CON agrega_PorHora(string, double, double)//
    gimnasio.agrega_PorHora("Patricia", 100, 20);
    
    
    //......................................................IMPRIMIR............................................................//
    
    gimnasio.muesta_clientes(); //IMPRIMIR TODOS LOS CLIENTES//
    gimnasio.muestra_empleados(); //IMPRIMIR TODOS LOS EMPLEADOS//
    gimnasio.calc_paga_empleados(); //IMPRIMIR LA PAGA DE TODOS LOS EMPLEADOS//
}