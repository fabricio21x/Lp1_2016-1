#include <cstdlib>
#include "Universidad.h"

using namespace std;

int main() {
    
    void *cursos, *alumnos;
    
    leerDatos(cursos, alumnos);
    agregarNotas(alumnos);
        
    return 0;
}

