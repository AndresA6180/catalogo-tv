#include <iostream>
#include <stdio.h>
#include <string>
#pragma once
using namespace std;

// Clase Episodio
class Episodio{
    // público:
    public:
        // Constructor de omisión
        Episodio();
        
        // Constructor con parámetros
        Episodio(string _titulo, int _temporada, double _calificacion);
    
        // Métodos de modificación
        void setTitulo(string);
        void setTemporada(int);
        void setCalificacion(double);
    
        // Métodos de acceso
        string getTitulo();
        int getTemporada();
        double getCalificacion();
    
        // Método de impresión
        void imprimir();
    
    
    // privado:
    private:
        // Atributo string TITULO
        string titulo;
        // Atributo int TEMPORADA 
        int temporada;
        // Atributo double CALIFICACIÓN
        double calificacion;            
};

// Constructor de omisión
Episodio::Episodio(){
    titulo = "";
    temporada = 0;
    calificacion = 0.0;     
}

// Constructor con parámetros
Episodio::Episodio(string _titulo, int _temporada, double _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// Métodos de modificación
void Episodio::setTitulo(string _titulo){       
    titulo = _titulo;                   
}

void Episodio::setTemporada(int _temporada){       
    temporada = _temporada;                   
}

void Episodio::setCalificacion(double _calificacion){       
    calificacion = _calificacion;                   
}

// Métodos de acceso
string Episodio::getTitulo(){
    return titulo;
}

int Episodio::getTemporada(){
    return temporada;
}

double Episodio::getCalificacion(){
    return calificacion;
}

// Método de impresión
void Episodio::imprimir(){
    cout << titulo << ", " << temporada << ", " << calificacion << endl;
    
}