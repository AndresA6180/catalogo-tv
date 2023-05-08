#include <iostream>
#include <stdio.h>
#include <string>
#include "Episodio.hpp"
#pragma once
using namespace std;

// Clase Serie
class Serie{
    // público
    public:
        // Constructor de omisión
        Serie();
        
        // Constructor con parámetros incluyendo el arreglo // --> NUEVO
        Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _cantidad, Episodio _Episodios[]);
    
        // Métodos de modificación
        void setId(string);
        void setTitulo(string);
        void setDuracion(int);
        void setGenero(string);
        void setCalificacion(double);
        void setCantidadEpisodios(int);       
    
        // Métodos de acceso
        string getId();
        string getTitulo();
        int getDuracion();
        string getGenero();
        double getCalificacion();
        int getCantidadEpisodios();       
    
        // Método de impresión
        void imprimir();

        // Imprime la informacion de la serie pero solo los episodios que tienen cierta calificacion
        // se imprime la informacion de la serie si existe al menos un episodio con esa calificacion
        void imprimir(double _calificacion);

        // Imprime la informacion de la serie pero solo los episodios que son de la _temporada
        // se imprime la informacion de la serie si existe al menos un episodio de esa temporada
        void imprimir(int _temporada);
    
        // Métodos NUEVOS ---------
        
        // Método getEpisodio
        Episodio getEpisodio(int);
    
        // Método CalificaciónPromedio        
        void calculaCalificacionPromedio();
    
        // Método setEpisodio --> Actualiza la posición iE del aarrEpisodios[], recibe
        // un objeto de la clase Episodio. Validar la posición
        void setEpisodio(int, Episodio);
                    
    
    // privado:
    private:
        // Atributos string
        string iD, titulo, genero;
        // Atributos int
        int duracion, cantEpisodios;
        //Atributos double
        double calificacionPromedio;
        //
        Episodio episodios[5]; 
};

//---------------------- IMPLEMENTACIÓN ---------------------//

// Constructor de omisión
Serie::Serie(){
    iD = "";
    titulo = "";
    duracion = 0;
    genero = "";
    calificacionPromedio = 0;
    cantEpisodios = 0;
}

// Constructor con parámetros
Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacionP, int _cantidadE, Episodio _episodios[]){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacionPromedio = _calificacionP;
    cantEpisodios = _cantidadE;
}

// Métodos de modificación

void Serie::setId(string id){
    iD = id;
}

void Serie::setTitulo(string tittle){
    titulo = tittle;
}

void Serie::setDuracion(int time){
    duracion = time;
}

void Serie::setGenero(string gender){
    genero = gender;
}

void Serie::setCalificacion(double note){
    calificacionPromedio = note;
}

void Serie::setCantidadEpisodios(int cant){
    cantEpisodios = cant;
}

// Métodos de acceso
string Serie::getId(){
    return iD;
}

string Serie::getTitulo(){
    return titulo;
}

int Serie::getDuracion(){
    return duracion;
}

string Serie::getGenero(){
    return genero;
}

double Serie::getCalificacion(){
    return calificacionPromedio;
}

int Serie::getCantidadEpisodios(){
    return cantEpisodios;
}  

// ---------------- COMPOSICIÓN --------------------- //

Episodio Serie::getEpisodio(int _numEpisodios){
    if (_numEpisodios >= 0 && _numEpisodios <= 4){
        return episodios[_numEpisodios];        
    }
    else {
        return episodios[0];
    }
}

void Serie::setEpisodio(int _cantidadE, Episodio _episodio){
    // Verificar que _iNum está entre 1 y 4
    // Si es así, episodios[_numEpisodios]=_episodio
    if (_cantidadE >= 0 && _cantidadE < 5){
        episodios[_cantidadE]=_episodio;
    }
}


// Método CalificaciónPromedio
void Serie::calculaCalificacionPromedio(){
    double acumulador = 0.0;
        
    for (int x = 0; x < cantEpisodios; x++){
        acumulador = acumulador + episodios[x].getCalificacion();
    }
    if (cantEpisodios > 0){
        calificacionPromedio = acumulador / cantEpisodios;
        
    }
    else{
        calificacionPromedio = 0;
    }
}

// Método de impresión
void Serie::imprimir(){
    cout << iD << ", " << titulo << ", " << genero << ", " << duracion << ", " << cantEpisodios << ", " << calificacionPromedio << endl;  
   
    
    for (int iE = 0;iE < cantEpisodios; iE++)
        episodios[iE].imprimir();
}

void Serie::imprimir(double _calificacion){
    int primero = 1;
    double calificacion;

    for (int iE = 0; iE < cantEpisodios; iE++){
        calificacion = episodios[iE].getCalificacion();
        if (_calificacion == calificacion){
            if (primero == 1){
                cout << iD << ", " << titulo << ", " << genero << ", " << duracion << ", " << cantEpisodios << ", " << calificacionPromedio << endl;
                primero = 0;
            }
            episodios[iE].imprimir();
        }
    }
    if (cantEpisodios > 0 && primero == 0){
        cout << endl;
    }

}

void Serie::imprimir(int _temporada){
    int primero = 1;
    int temporada;

    for (int iE = 0; iE < cantEpisodios; iE++){
        temporada = episodios[iE].getCalificacion();
        if (_temporada == temporada){
            if (primero == 1){
                cout << iD << ", " << titulo << ", " << genero << ", " << duracion << ", " << cantEpisodios << ", " << calificacionPromedio << endl;
                primero = 0;
            }
            episodios[iE].imprimir();
        }
    }
    if (cantEpisodios > 0 && primero == 0){
        cout << endl;
    }
}
// // Inclusion de librerias
// #include <iostream>
// using namespace std;
// #include "Episodio.hpp"
// #pragma once

// // Clase Serie
// class Serie
// {
//     // público
//     public:
//         // Constructor de omisión
//         Serie();
//         Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacionPromedio, int _cantEpisodios, Episodio _episodio[]);
  
//         // Métodos de modificación
//         void setId(string);
//         void setTitulo(string);
//         void setDuracion(int);
//         void setGenero(string);
//         void setCalificacion(double);
//         void setCantidadEpisodios(int);
    
//         // Métodos de acceso
//         string getId();
//         string getTitulo();
//         int getDuracion();
//         string getGenero();
//         double getCalificacion();
//         int getCantidadEpisodios();

//         // Método de impresión
//         void imprimir();

//         //Composición
//         Episodio getEpisodio(int);
//         void setEpisodio(int, Episodio);
//         void calculaCalificacionPromedio();
    
    
//         // Método altaEpisodio(para después)            
    
//     // privado:
//     private:
//         // Atributos string
//         string iD, titulo, genero;
//         // Atributos int
//         int duracion, cantEpisodios;
//         //Atributos double
//         double calificacionPromedio;
//         Episodio episodio[5];
        
// };

// // Constructor de omisión
// Serie::Serie(){
//     iD = "";
//     titulo = "";
//     duracion = 0;
//     genero = "";
//     calificacionPromedio = 0;
//     cantEpisodios = 0;
// }

// // Constructor con parámetros
// Serie::Serie(string str_iD, string str_titulo, int int_duracion, string str_genero, double dou_calif, int int_cantE, Episodio _episodio[]){
//     iD = str_iD;
//     titulo = str_titulo;
//     duracion = int_duracion;
//     genero = str_genero;
//     calificacionPromedio = dou_calif;
//     cantEpisodios = int_cantE;
// }

// // Métodos de modificación

// void Serie::setId(string id){
//     iD = id;
// }

// void Serie::setTitulo(string tittle){
//     titulo = tittle;
// }

// void Serie::setDuracion(int time){
//     duracion = time;
// }

// void Serie::setGenero(string gender){
//     genero = gender;
// }

// void Serie::setCalificacion(double note){
//     calificacionPromedio = note;
// }

// void Serie::setCantidadEpisodios(int cant){
//     cantEpisodios = cant;
// }

// // Métodos de acceso
// string Serie::getId(){
//     return iD;
// }

// string Serie::getTitulo(){
//     return titulo;
// }

// int Serie::getDuracion(){
//     return duracion;
// }

// string Serie::getGenero(){
//     return genero;
// }

// double Serie::getCalificacion(){
//     return calificacionPromedio;
// }

// int Serie::getCantidadEpisodios(){
//     return cantEpisodios;
// }

// //Composición
// void Serie::setEpisodio(int _numEpisodio, Episodio _episodio){
//   episodio[_numEpisodio] = _episodio;
// }

// Episodio Serie:: getEpisodio(int _numEpisodio){
//     return episodio[_numEpisodio];
// }

// void Serie::calculaCalificacionPromedio(){
//     double suma = 0;
//     double division = 0;
//     double promedio = 0;
//     if (cantEpisodios > 0){
//     for (int A = 0; A < cantEpisodios; A++){
//         suma = suma + episodio[A].getCalificacion();

//     }
//     promedio = suma/cantEpisodios;
//     calificacionPromedio = promedio;
//     }
//     else{
//         calificacionPromedio = 0;
//     }
// }





// // Método de impresión
// void Serie::imprimir(){
//     cout << iD << ", " << titulo << ", " << duracion << ", " << genero << ", " << calificacionPromedio << ", " <<cantEpisodios << endl;
//     for(int A = 0; A < cantEpisodios; A++) {
//         episodio[A].imprimir();
//     }
// }