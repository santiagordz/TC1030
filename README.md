# TC1030
A01704109 - PROYECTO TC1030 


El proyecto va a tratar acerca de un gimnasio, el cual está pensado para que el administrador del lugar lo controle. 
Este programa va a incluir empleados y clientela y cada uno va a tener diferentes atributos y métodos. 

La clase cliente va a tener: Nombre, Edad, Id, Peso, Altura, Género, Actiidad Física, Rutina y Dieta.
Todos estos atributos se van a construir a partir de funciones específicas dentro del main o bien en una función para crear ejemplos. 
La rutina y la dieta son clases extras que estarán agregadas a la clase cliente y que serán específicas para cada objeto cliente, dependiendo de lo que busque cada uno.

La clase de empleados tendrá: Nombre, Tipo e ID. Y se dividirá en dos tipos: Empleados por Hora y Empleados Fijos. La diferencia es que el empleado por hora ganará su sueldo basado en la cantidad de horas que trabaje al mes y el empleado fijo ya tendrá un sueldo definido.

Al final se usarán estas dos clases en una clase superior por medio de agregación, la cuál llevará el nombre de gimnasio. El cual tiene los atributos de: Número de Empleados y Número de Clientes. Esta clase implementará polimorfismo para la creación de nuevos objetos que se puedan usar en el gimnasio. Todos los métodos se explicarán más a fondo en la documentación.

DOCUMENTACION:

cliente.h:

   Lo primero que se observa es la clase Rutina, la cual tiene el atributo "tipo". Lo cúal nos indica el tipo de rutina que deberá seguir el cliente para alcnzar sus objetivos. Como métodos, esta rutina cuenta con un constructor: Rutina(int opc), el cual contiene una serie de ifs que definiran al atributo "tipo". Opc se determinará en el main o en la construcción del objeto.

  Despues se define la clase Dieta, la cual es muy parecida a rutina y cuenta con los mismos atributos y métodos.Y se definirá, igual que rutina, en el main o en la construcción del objeto.

Al final, la clase "Cliente", que tiene los atributos: string(Nombre, Edad), int(id, edad), double(peso, altura, estado, imc), Rutina(Rutina) y Dieta(Dieta). Y que cuenta con los métodos: 
  constructor: cliente(nombre, Edad, Id, Peso, Altura, Género, Actividad Física, Rutina, Dieta)
  getters para todos los atributos, get_imc() que nos regresa el valor de imc con una fórmula
  calc_imc() que nos regresa un string para imprimir en consola dependiendo el valor de imc, 
  nivel_actividad() que nos regresa un double dependiendo de "estado" para definir un valor a multiplicar en calc_cal_mant() lo cual nos da un double con las calorias basales para la dieta del cliente y calc_cal_dieta() nos da el número de calorías que debe consumir el cliente dependiendo de su dieta. 
  y to_string() nos da un string para que sea más sencillo imprimir en consola.


empleado.h:

  Contiene la clase padre Empleado con sus aributos: string(Nombre, Tipo) y int(ID). Y sus métodos: Empleado(Nombre, Tipo, ID), getters de todos los elementos y las funciones virtuales igualadas a 0 para que Empleado sea una clase abstracta: pago_mensual() y to_string(). Le siguen las clases hijas: Fijo y PorHora, cada uno con diferentes atributos y métodos. Fijo tiene como atributos extras: double(salario mensual) y como métodos el constructor Fijo(Nombre, Tipo, ID, Salario); sus métodos se sobreescriben y queda pago_mensual(){return salario} y to_string() como una funcion que devuelve un string específico para empleado Fijo. Mientras que para PorHora, tiene como atributos extras a: double(Pago por Hora, Horas Trabajadas) y los métodos sobreescritos pago_mensual(){return pago por hora * horas trabajadas} y to_string() devuelve un string específico para PorHora.


gimnasio.h:

  Tiene a la clase Gimnasio, la cual tiene los atributos: Cliente(clientes[]), Empleado(*empleados[]), int(nomina, usuario). clientes y *empleados son listas vacías que se van a llenar con objetos de clase cliente o empleado. Empleado es de tipo apuntador, ya que se usará la memoria heap para el polimorfismo de objetos. Nómina y Usuario servirán para llevar la cuenta de cuántos clientes y empleados se han creado. Los métodos son los siguientes:
  constructores: Gimnasio(){nomina=0, usuario=0}
  getters: De todos los atributos
  crea_ejemplo(): Crea dos Clientes y Dos Empleados (1 Fijo, 1 Por Hora). Los define con constructores y los agrega a clientes[] y *empleados[].
  muestra_clientes(): Una funcion que utiliza un ciclo for para recorrer toda la lista clientes[] y con to_strng() muestra los atributos de cada elemento.
  muestra_empleados(): Es una funcion muy similar a muestra_clientes(), solo que esta recorre la lista *empleados[].
  calc_paga_empleados(): Calcula la suma total del salario de todos los empleados usando pago_mensual() y la imprime.
  agrega_cliente(): Agrega un obeto de tipo cliente a la lista, aumenta 1 en usuario (usuario++)
  agrega_Fijo(): Agrega un objeto de tipo Fijo a la lista de empleados con la palabra new ya que se agrega en la heap; aumenta 1 en nomina (nomina++)
  agrega_PorHora(): Agrega un objeto de tipo PorHora a la lista de empleados con la palabra new ya que se agrega en la heap; aumenta 1 en nomina (nomina++)


gym.cpp:

  Es la funcion principal (main) y donde se usarán todas las funciones para demostrar su correcto funcionamiento. 
  Esta incluye dos funciones las cuales van a ser de ayuda para preguntarle al usuario cómo va a querer crear un objeto, estas funciones son:
  crea_cliente(): Esta funcion crea un arreglo de apuntadores "clientes[8]" en la cual almacenará todos los inputs que el usuario vaya proporcionando dependiendo la pregunta que le aparezca en pantalla. Todos estos inputs serán de ayuda para usar el constructor del objeto cliente para poder agregar al cliente con la información que el usuario proporciona. Para usar esta función, se deberá crear una variable=crea_cliente(), en donde variable[0] va a corresponder a un elemento que se va a usar para el constructor, variable[1] y así sucesivamente. 
  crea_empleado(): Es una función muy similar a crea_cliente(), en donde el usuario nos da información que se guarda en una lista de apuntadores "empleado[5]" y esa info es la que devuelve la funcion. Para usar la función se usa un cundicional if, en donde depende de una variable de empleado[] si crea un empleado Fijo o Por Hora.
  Luego el main solo incluye todas las funciones que vimos anteriormente para verificar que todas funcionen de manera correcta con los ejemplos creados y el cliente o empleado que el usuario haya querido agregar.
  
  
