#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

//PREGUNTAS
//vale la pena usar enum?

enum varios {CRITICAL = 1, ERROR, WARNING, INFO, DEBUG, SECURITY};

string prioridad_a_string(int prioridad) {
    switch (prioridad) {
        case CRITICAL: return "CRITICAL";
        case ERROR: return "ERROR";
        case WARNING: return "WARNING";
        case INFO: return "INFO";
        case DEBUG: return "DEBUG";
        case SECURITY: return "SECURITY";
        default: return "UNKNOWN"; 
    }
} //vale la pena usar enum?

void logMessage(string mensaje, int prioridad){

    ofstream outFile("logreport", ios :: app);
    if (outFile.is_open()){
        outFile << "[" + prioridad_a_string(prioridad) + "] " + mensaje << endl; 
        outFile.close();
    }
    else cerr << "Error al abrir el archivo"; 
}

//las siguientes funciones corresponden al ejercicio 2b
void logMessage(string mensaje, string archivo, int linea){
    string nuevo_mensaje = mensaje + " (" + archivo + " - l" + to_string(linea) + ")";
    logMessage(nuevo_mensaje, varios::ERROR);
}

void logMessage(string mensaje, string usuario){
    string nuevo_mensaje = mensaje + " to " + usuario;
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
        throw runtime_error("Fallo en la ejecución");
    } 
    catch (const std::runtime_error& e) {
        logMessage("Runtime Error", varios::ERROR);
        return 1;
    } 
    catch (...) {
        logMessage("Error desconocido", varios::ERROR);
        return 1;
    }
    return 0;
}
