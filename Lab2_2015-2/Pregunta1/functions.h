#ifndef FUNCTIONS_H
#define FUNCTIONS_H


void impLinea(char c, int n);
int procesarEmpleado(double tiemposTotales[200], int codigos[200],
        int n, double &final, int &llamadas);
void convertirSegundos(double total, int &hor, int &min, double &seg);


#endif /* FUNCTIONS_H */

