#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Serie.hpp"
#include "Episodio.hpp"
using namespace std;

class Series{
    
    
    public:
        Series();
        
        // Constructor que inicializa iCant = 0
        Series(int iCant);

        // Lee las Series desde un archivo cvs y las carga en el arreglo y lee el archivo de Episodios
        // arrSeries[100];
        void leerArchivo();

        // Reporte de todas las Series -
        // al final del mismo muestra la calificacion promedio de todas las Series (ver casos de prueba)
        void reporteTodasSeries();

        // Reporte de Series que tienen cierta calificacion -
        // Despliega en pantalla todas las series del arreglo que tienen la calificacion recibida en el parametro de entrada
        // Si la serie tiene episodios los despliega(si los tiene)
        void reporteConCalificacion(double);

        // Reporte de Series que tienen cierto genero -
        // Despliega en pantalla todas las series que tienen el genero recibido como parametro de entrada
        // con todos sus episodios(si los tiene)
        void reporteGenero(string);

        // Calcula la calificacion promedio de todas las series en base a sus episodios y despliega su titulo y su calificacion promedio
        // Si la serie no tiene episodios, se le asigna 0 como calificacion
        void calculaCalPromedioSerie();

        // Retorna el objeto Serie que esta en la posicion iS del arreglo de series
        // que recibio como parametro de entrada, si no existe retorna la serie 0 de arreglo
        Serie getSerie(int iS);

        // Actualiza la serie que esta en la posicion iSerie del arreglo de series, validar que existe
        // si no existe NO actualiza el arreglo
        void setSerie(int iSerie, Serie s);

        // Retorna la cantidad de series que tenemos en existencia - iCant
        int getCantidadSeries();

        void setCantidadSeries(int);

        // Desplegar todas las series con los episodios que tienen calificacion especificada en el parametro de entrada
        // si la serie no tiene episodios con esa calificacion no despliega nada de esa serie
        void consultaEpisodiosConCalificacion(double dCal);

        void consultarTemporadaXSerie(int temporada);

    private:
        //Arreglo de objetos de la clase Serie
        Serie arrSeries[100];
        int iCant; //cantidad de Series dadas de alta
};

Series::Series(){
    iCant = 0;

}

void Series::leerArchivo(){
    string sId, sTitulo, sGenero, linea, dato;
    int iR;

    fstream lectura;

    lectura.open("Series.csv", ios::in);
    iR = 0;
    int renglon1 = 1;
    while ( getline(lectura, linea))
    {
        stringstream registro(linea);

        int columna = 0;
        while(getline(registro, dato, ','))
        {
            switch (columna++)
            {
                case 0: // iD
                    arrSeries[iR].setId(dato);
                break;
                case 1: // titulo
                    arrSeries[iR].setTitulo(dato);
                break;
                case 2: // duracion
                    arrSeries[iR].setDuracion(stoi(dato));
                break;
                case 3: // genero
                    arrSeries[iR].setGenero(dato);
                break;
                case 4: // calificacion promedio
                    arrSeries[iR].setCalificacion(stod(dato));
                break;
                case 5: //cant episodios
                    arrSeries[iR].setCantidadEpisodios(0);
                break;
            }
        }
            iR++;
    }
    iCant = iR;
    lectura.close();

    Episodio ep;
    lectura.open("Episodios.txt", ios::in);
    int cantEp, iS;
    renglon1 = 1;
    while (getline(lectura, linea))
    {
        stringstream registro(linea);
        int columna = 0;

        while(getline(registro, dato, ','))
        {
            switch (columna++)
            {
                case 0: // iD
                    iS = stoi(dato)-100;
                break;
                case 1: // titulo
                   ep.setTitulo(dato);
                break;
                case 2: // temporada
                    ep.setTemporada(stoi(dato));
                break;
                case 3: // calificacion
                    ep.setCalificacion(stod(dato));
                break;
                
            }
        } 

        cantEp = arrSeries[iS].getCantidadEpisodios();
        if (cantEp < 5){
            arrSeries[iS].setEpisodio(cantEp, ep);
            arrSeries[iS].setCantidadEpisodios(cantEp + 1);
        }
    }
    lectura.close();
}

void Series::reporteTodasSeries(){
    cout << "ReporteSeries" << endl;
    double dPromedio;
    dPromedio = 0;


    for(int iR = 0, iCont = 1; iR < iCant; iR++){
        arrSeries[iR].imprimir();
        cout << endl;
        dPromedio = dPromedio + arrSeries[iR].getCalificacion();
    }

    if (iCant > 0)
    {
        cout << "Promedio Series :" << dPromedio / iCant << endl;
    }
}

void Series::reporteConCalificacion(double calificacion){
    cout << "ReporteSeriesConCalificacion:" << calificacion << endl;
    for (int iR = 0, iCont = 1; iR < iCant; iR++){
        if (arrSeries[iR].getCalificacion() == calificacion){
            arrSeries[iR].imprimir();
            cout << endl;
        }

    }
}

void Series::reporteGenero(string genero){
    cout << "ReporteGenero:Ciencia ficcion" << endl;
    for (int iR = 0, iCont = 1; iR < iCant; iR++){
        if (arrSeries[iR].getGenero() == genero){
            arrSeries[iR].imprimir();
            cout << endl;
        }
        
    }
}

void Series::calculaCalPromedioSerie(){
    for (int iR = 0, iCont = 1; iR < iCant; iR++){
        arrSeries[iR].calculaCalificacionPromedio();
    }
}

Serie Series::getSerie(int iS){
    if (iS >= 0 && iS < iCant)
    {
        return arrSeries[iS];
    }
    else
    {
        return arrSeries[0];
    }
    
}

void Series::setSerie(int iSerie, Serie s){
    if (iSerie >= 0 && iSerie < iCant)
    {
        arrSeries[iSerie] = s;
    }
}

int Series::getCantidadSeries(){
    return iCant;
}

void Series::setCantidadSeries(int _iCant){
    iCant = _iCant;
}


void Series::consultaEpisodiosConCalificacion(double dCal){
    cout << "ReporteEpisodiosConCalificacion:9.5" << endl;
    for (int iS = 0; iS < iCant; iS++){
        arrSeries[iS].imprimir(dCal);
    }

}