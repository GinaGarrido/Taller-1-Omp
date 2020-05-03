# Taller-1-Omp
Promedios en omp

Ejecutar archivo main.cpp, que genera archivo puntajes.csv:

g++ -o ejecutablemain main.cpp 
./ejecutablemain

Luego ejecutar archivo prom-ptjs.cpp, que abre este archivo y genera otro llamado promedios.csv:

g++ -o ejecutableprom prom-ptjs.cpp
./ejecutableprom

Luego ejecutar archivo OpenMP prom--ptjs-omp.cpp, que abre archivo puntajes.csv y genera otro llamado promedios.csv:

g++ -o ejecutablepromomp prom--ptjs-omp.cpp
./ejecutablepromomp

puntajes.csv se genera con un rango de rut y cada uno con un puntaje de nem, ranking, matemáticas, lenguaje, ciencias y de historia. 
Se lee este archivo y se genera por cada rut un promedio de cada puntajes y se guarda en el archivo promedios.csv.
