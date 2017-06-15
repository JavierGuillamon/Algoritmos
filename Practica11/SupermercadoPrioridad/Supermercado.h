#include"ColaPrioridad.h"

class Supermercado
{
private:
	//Array de punteros a objetos de tipo Cola que representan cada una de las cajas
	ColaPrioridad *cajas;
	
	//Número de cjas que hay en el supermercado
	int n_cajas;
public:
	/*
	Constructor que se encarga de reservad memoria para las n cajas que tiene el supermercado e inicializa el atributo n_cajas
	Parametros:
	-n: numero de cajas
	Precondiciones:
	-n >= 0
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	Supermercado(int n);

	/*
	Encola el usuario con el id indicado en la caja que se encuentra en la posicion n del array de cajas
	Parametros:
	-n: posicion de la caja en la que se quiere añadir el nuevo usuario
	-id: id del nuevo usuario
	Precondiciones:
	-n >= 0;
	-n <= n_cajas;
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	void nuevoUsuario(int n, int id);
	
	/*
	Simula el cierre de la cja n y el reparto de los usuarios en las cajas restantes
	Parametros:
	-n: posicion de la caja que se quiere cerrar
	Precondiciones:
	-n >= 0;
	-n <= n_cajas;
	Complejidad:
	-Temporal: O(n)= n
	-Espacial: O(n)= 1
	*/
	void cerrarCaja(int n);
	
	/*
	Atiende al usuario que se encuentra en la caja n y por tanto lo desencola de la cola que representa dicha caja, devuelve el id del usuario atendido.
	Parametros:
	-n: posicion de la caja en la que se quiere atender
	Precondiciones:
	-n >= 0;
	-n <= n_cajas;
	Retorno:
	-int: id del usuario atendido
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	int atenderUsuario(int n);
	
	/*
	Indica si la caja n tiene o no tiene usuarios esperando
	Parametros:
	-n: posicion de la caja a comprobar
	Precondiciones:
	-n >= 0;
	-n <= n_cajas;
	Complejidad:
	-Temporal: O(n)= 1
	-Espacial: O(n)= 1
	*/
	bool cajaVacia(int n);
};
