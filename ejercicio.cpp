#include <iostream>
#include <fstream>
using namespace std;

void logMessage(string mensaje, string severidad){
    ofstream outFile("logreport", ios::app);
    if (outFile.is_open()){
        outFile << "[" + severidad + "] " + mensaje << endl;
        outFile.close();
    }
    else cerr << "Error al abrir el archivo";
}

int main(){
    logMessage("Printeamos variables", "DEBUG");
    logMessage("Todo ok", "INFO");
    logMessage("Tiempo de espera superior al esperado", "WARNING");
    logMessage("Mal resultado", "ERROR");
    logMessage("Multiples errores acumulados", "CRITICAL");
    return 0;
}
