#include <iostream>
#include <fstream>
#include <cstdlib>
#include <omp.h>
#include <sstream>
#include <string>

using namespace std;

int getprom(string texto, string separador);
string getrut(string texto, string separador);
void participante();

int main(){
    std::string pyc(";");
    std::string rut;
    int prom;
    std::string salida;
    std::ofstream archivoSalida("promedios.csv");//Se crea archivo para guardar promedios
    std::ifstream archivoEntrada("puntajes.csv");//Se abre archivo para crear promedios
    
#pragma omp parallel 
    {
#pragma omp if
        if (archivoEntrada){
            std::string linea;

#pragma omp while
            while (getline(archivoEntrada,linea)){
                {
                    rut=getrut(linea,pyc);
                    prom=getprom(linea,pyc);
                }
                salida= rut + pyc + to_string(prom);
#pragma omp critical
                archivoSalida << salida << std::endl; 
            }
        }
    }
    archivoEntrada.close();
    archivoSalida.close();
    return EXIT_SUCCESS;
}

int getprom(string texto, string separador){ //Función que obtiene y retorna el promedio 
    int inicio=0;
    int suma=0;
    int puntj;
    size_t pos = 0; //variable de tipo size_t tipo integral sin signo
    string token;

#pragma omp while
        while ((pos = texto.find(separador)) != std::string::npos) { //npos es el valor máximo para size_t
            token = texto.substr(0, pos); //Guarda primer valor del string hasta encontrar el puntoycoma
#pragma omp if
            if (inicio!=0){
                std::istringstream(token)>>puntj;

                suma = suma + puntj;
            }

            inicio+=1;
            texto.erase(0, pos + separador.length()); //Borra ese valor encontrado
        }
        std::istringstream(texto)>>puntj;

        suma = suma + puntj;
        int promedio = (suma / 6);
    return (promedio);
} 

string getrut(string texto, string separador){ //Función que obtiene y retorna el rut
    int inicio=0;
    std::string rut;
    size_t pos = 0; //variable de tipo size_t tipo integral sin signo
    string token;

#pragma omp while
        while ((pos = texto.find(separador)) != std::string::npos) { //npos es el valor máximo para size_t
            token = texto.substr(0, pos); //Guarda primer valor del string hasta encontrar el puntoycoma
#pragma omp if
            if (inicio==0){
                rut=token;
            }
            inicio+=1;
            texto.erase(0, pos + separador.length()); //Borra ese valor encontrado
        }

    return (rut);
}

void participante() {
    std::cout << std::endl << "=== Taller 1 ===" << std::endl;
    std::cout << std::endl << "Gina Geinse Garrido Cabezas" << std::endl; 
}
