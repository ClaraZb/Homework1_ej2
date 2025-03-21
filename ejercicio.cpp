#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

/* 
2.a)
Al principio iba a usar diccionarios para asignarle a cada numero un mensaje (ej: 1: CRITICAL). Hasta que
se dijo que no se podia asi que use enums. Lo importante era que la funcion logmessage pedida en el punto 2a tuviera
como parametros un string y un int, y no dos strings, ya que en ese caso se confundiria con lo que pedian en la
consigna 2b. 

2.b)
Para esta parte use sobrecarga de funciones, ya que piden que todos los mensajes sean escritos usando logmessage. 
La unica diferencia son los parametros, que agregan mas contenido al mensaje que se tiene que escribir en el
archivo. Para mayor claridad y evitar repetir codigo, decidi transformar esa informacion extra en un nuevo
string y llamar con ese nuevo mensaje a la primer funcion logmessage(string, int). 
*/

enum varios {CRITICAL = 1, ERROR, WARNING, INFO, DEBUG, SECURITY}; //le asigno a cada etiqueta un numero

string prioridad_string(int prioridad) { //para cada caso devuelvo lo mismo pero en string
    switch (prioridad) {
        case CRITICAL: return "CRITICAL";
        case ERROR: return "ERROR";
        case WARNING: return "WARNING";
        case INFO: return "INFO";
        case DEBUG: return "DEBUG";
        case SECURITY: return "SECURITY";
    }
} 

void logMessage(string mensaje, int prioridad){
    ofstream outFile("logreport", ios :: app); //abro o modifico un archivo
    if (outFile.is_open()){
        outFile << "[" + prioridad_string(prioridad) + "] " + mensaje << endl; 
        outFile.close();
    }
    else cerr << "Error al abrir el archivo"; 
}

//las siguientes funciones corresponden al ejercicio 2b
void logMessage(string mensaje, string archivo, int linea){
    string nuevo_mensaje = mensaje + " (" + archivo + " - l" + to_string(linea) + ")"; //defino un nuevo mensaje
    logMessage(nuevo_mensaje, varios::ERROR);
}

void logMessage(string mensaje, string usuario){
    string nuevo_mensaje = mensaje + " to " + usuario; //defino un nuevo mensaje
    logMessage(nuevo_mensaje, varios::SECURITY);
}

int main(){
    //pruebas para la parte 2a
    logMessage("Printeamos variables", varios::DEBUG);
    logMessage("Todo ok", varios::INFO);
    logMessage("Tiempo de espera superior al esperado", varios::WARNING);
    logMessage("Mal resultado", varios::ERROR);
    logMessage("Multiples errores acumulados", varios::CRITICAL);
    
    //pruebas para la parte 2b
    logMessage("Resultado no es correcto", "Potencias", 23);
    logMessage("Access granted", "Harry Potter");

    try{
        throw runtime_error("Error"); //fuerzo un runtime error
    } 
    catch (const runtime_error& e) { 
        logMessage("Runtime Error", varios::ERROR);
        return 1; //retorno que hubo un error
    } 
    catch (...) {
        logMessage("Error desconocido", varios::ERROR);
        return 1; //retorno que hubo un error
    }
    return 0;
}
