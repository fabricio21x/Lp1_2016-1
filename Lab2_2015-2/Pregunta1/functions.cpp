#include "functions.h"
#include "quicksort.h"
#include <iostream>
#include <iomanip>

using namespace std;

void impLinea(char c, int n){
    for (int i = 0; i < n; i++)
        cout << c;
    cout <<endl;
}

char pasarPalabra(){
    char c;
    int count=0;//numero de caracteres que se leeran
    
    cin >> c; //se lee el primer caracter diferente de  ' '
    while( c != ' ' && c != '\t' && c != '\n'){
        cout.put(c);
        cin.get(c);
        count++;
    }
    if (count!=0) count++; //significa que si leyo una palabra
    return c;
}

void leerFecha(int &dia, int fechas[600], int i){
    int mes, anio;
    
    cin.clear();
    if (dia == 0){ //solo cuando sea la primera fecha que se va a leer
        cin >> fechas[i];
    }else fechas[i] = dia;
    cin.ignore(); //ignoro el caracter /
    cin >> fechas[i + 1];
    mes = fechas[i + 1];
    cin.ignore(); //ignoro el caracter /
    cin >> fechas[i + 2];
    anio = fechas[i + 2];
}

int leerTiempos(double &totalTiempos, int &dia, int &hayLlamadas,
        double tiempos[100], int &numTiempos,  int &finArchivo){
    double tiempo;
    
    while((!cin.eof()) && (cin.peek()!='\n') && cin >> tiempo){ //leera tambien el dia de la fecha que sigue
        totalTiempos += tiempo;
        tiempos[numTiempos] = tiempo;
        numTiempos++;
    }
    if (!cin.eof() && cin.peek()!='\n'){
        dia = tiempos[numTiempos - 1];
        totalTiempos -= tiempos[numTiempos-1]; //le quito el dia de la fecha siguiente
        numTiempos--;
    }else{
        hayLlamadas = 0;
        if(cin.eof()) finArchivo=1;
    }
    return 0;
}

void convertirSegundos(double total, int &hor, int &min, double &seg){
    int aux = total;
    
    hor = aux/3600;
    min = (aux%3600)/60;
    seg = total - hor*3600 - min*60;
}

int procesarEmpleado(double tiemposTotales[200], int codigos[200],
        int n, double &final, int &llamadas){
    int fechas[300]={0}, hor, min, finArchivo=0;
    int anexo, dia=0, hayLlamadas=1, totDias=0;
    double tiempos[100]={0}, totalTiempos[100]={0}, total=0, prom, seg, tiemposTot;
    int numTiempos, iFech;
    
    if (cin.eof()) return 0;
    
    impLinea('=', 115);
    cout << "Codigo\t\t\t\t" << "Empleado\t\t\t\t" << "Anexo\n";
    impLinea('-',115);
    
    cin >> codigos[n];//leer codigo y almacenarlo
    
    cout << codigos[n] << "\t\t"; 
    
    while(!(cin >> anexo)){     //leer nombre
        cin.clear();
        pasarPalabra(); 
        cout.put(' ');
    }
    cout << "\t\t";
    cout << anexo << endl;
    impLinea('-',115);
    
    cout << "RESUMEN POR FECHA:\n";
    while(hayLlamadas){
        tiemposTot = 0;
        numTiempos=0;
        iFech = totDias*3;
        
        cout << "\t\t\t\t\t\tFECHA\t\tTIEMPOS" << endl;
        leerFecha(dia,fechas,iFech);
        while(leerTiempos(tiemposTot, dia, hayLlamadas, tiempos, numTiempos, finArchivo));
        totalTiempos[totDias] = tiemposTot;
        cout << "\t\t\t\t\t\t" << setfill('0') << setw(2)<< fechas[iFech]
                << '/' << setfill('0') << setw(2)<< fechas[iFech+1]
                << '/' << fechas[iFech+2];
        
        for (int i=0; i<numTiempos; i++){
            if (i==0)
                cout <<"\t" << tiempos[i] << endl;
            else 
                cout <<"\t\t\t\t\t\t\t\t" << tiempos[i] << endl;
        }
        total += totalTiempos[totDias];
        cout << "\t\t\t\t\t\t";
        impLinea('-',40);
        cout << "\t\t\t\t\t\tTotal:\t\t\t" << tiemposTot << endl;
        cout << "\t\t\t\t\t\t";
        impLinea('-',40);
        llamadas += numTiempos;
        totDias++;
    }
    
    impLinea('-',115);
    cout << "RESUMEN POR TOTALES:\t\t\t\t\t\tFECHA\t\tTIEMPOS" << endl;
    
    quicksort(fechas,totalTiempos,0,totDias-1);
   
    for(int i=totDias-1; i >= 0; i--){
        cout << "\t\t\t\t\t\t\t\t" << setfill('0') << setw(2)<< fechas[i*3]
                << '/' << setfill('0') << setw(2)<< fechas[i*3+1]
                << '/' << fechas[i*3+2] << "\t\t" << totalTiempos[i]<<endl;
    }
    
    impLinea('*',115);
    cout << "Resumen:" << endl;
    convertirSegundos(total, hor, min, seg);
    cout << "  Tiempo total de llamadas:  " << fixed << setprecision(2) << total
            << " segundos (" << hor << " h " << min << " m " << seg << " s)\n";
    cout << "  Dias contabilizados:  " << totDias << endl;
    prom = total/totDias;
    convertirSegundos(prom, hor, min, seg);
    cout << "  Promedio:  " << fixed << setprecision(2) << prom
            <<" ("<< hor << " h " << min << " m " << seg << " s)\n";
    
    tiemposTotales[n]=total;
    final += total;
    
    if(finArchivo) return 0;
    
    return 1;
}