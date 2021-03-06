#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <omp.h>


using namespace std;

/**
 * Función que muestra los participantes del grupo
 */
void participante();

/**
 * 
 * @param inferior límite menor para buscar
 * @param superior límite mayor para buscar
 * @return un número entre dichos límites
 */
int aleatoreo(int inferior, int superior);

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {
    std::string pyc(";");

    std::ofstream archivoSalida("puntajes.csv");

#pragma omp parallel 
    {

#pragma omp for
        for (unsigned long rut = 14916641; rut <= 19932391; rut++) {
            int nem = aleatoreo(475, 750);
            int ranking = aleatoreo(475, 750);
            int matematica = aleatoreo(475, 750);
            int lenguaje = aleatoreo(475, 750);
            int ciencias = aleatoreo(475, 750);
            int historia = aleatoreo(475, 750);

            std::string linea;
            linea = std::to_string(rut) + pyc + std::to_string(nem) + pyc + std::to_string(ranking) + pyc + std::to_string(matematica) + pyc + std::to_string(lenguaje) + pyc + std::to_string(ciencias) + pyc + std::to_string(historia);

#pragma omp critical
            archivoSalida << linea << std::endl;
        }
    }
    archivoSalida.close();

    participante();
    return EXIT_SUCCESS;
}

void participante() {
    std::cout << std::endl << "=== Tarea ===" << std::endl;
    std::cout << std::endl << "Sebastián Salazar Molina" << std::endl; // Reemplazar por su nombre
}

int aleatoreo(int inferior, int superior) {
    return (rand() % (superior - (inferior + 1))) +inferior;
}