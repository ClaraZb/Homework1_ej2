#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;


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
    ofstream outFile("logreport", ios::app);
    if (outFile.is_open()){
        outFile << mensaje +" (" + archivo + " - l" + to_string(linea) + ")" << endl; //deberia contener la etiqueta [ERROR]?
        outFile.close();
    }
    else cerr << "Error al abrir el archivo";
}

void logMessage(string mensaje, string usuario){
    ofstream outFile("logreport", ios::app);
    if (outFile.is_open()){
        outFile << "[SECURITY] " + mensaje +" to " + usuario << endl; //deberia contener la etiqueta [ERROR]?
        outFile.close();
    }
    else cerr << "Error al abrir el archivo";
}

int main(){
    logMessage("Printeamos variables", varios::DEBUG);
    logMessage("Todo ok", varios::INFO);
    logMessage("Tiempo de espera superior al esperado", varios::WARNING);
    logMessage("Mal resultado", varios::ERROR);
    logMessage("Multiples errores acumulados", varios::CRITICAL);
    
    //comandos para la parte 2b
    logMessage("Resultado no es correcto", "Potencias", 23);
    logMessage("Access granted", "Harry Potter");
    return 0;
}
