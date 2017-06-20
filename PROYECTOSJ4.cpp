#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

const string NOMBRE_ARCHIVO = "posiciones.csv";

class posicion{
    public: 
        string descripcion;
        float x;
        float y;
        char estado;

        void agregarNuevaPosicion(posicion p){
            ofstream salida(NOMBRE_ARCHIVO,ios::app);
            salida << p.descripcion << "," << p.x << "," << p.y << "," << p.estado << endl;
            cout << "La nueva ubicación se ha guardado satisfactoriamente" << endl;
            salida.close();
        }

        void eliminarPosicionNombre(string d){
            string aux;
            vector<posicion> vp;
            posicion p;
            int cont=0,t=0;
            fstream entrada(NOMBRE_ARCHIVO,ios::in);
            while(!entrada.eof()){
                getline(entrada,aux);
                if(aux.size()>4){
                    p.descripcion = aux.substr(0,aux.find(","));
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.x = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.y = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    if(aux.length() >= 1){
                        p.estado = aux.at(0);
                    }
                    vp.push_back(p);
                }
            }
            entrada.close();
            fstream salida(NOMBRE_ARCHIVO,ios::out|ios::trunc);
            for(int i=0;i<vp.size();i++){
                if(vp[i].descripcion == d){
                    vp.erase(vp.begin()+i);
                }
            }
            for(int i=0;i<vp.size();i++){
                salida << vp[i].descripcion << "," << vp[i].x << "," << vp[i].y << "," << vp[i].estado << endl;
            }
            cout << "La posición se eliminó exitosamente" << endl;
            salida.close();
        }

        void listar100Primeros(){
            string aux;
            int cont=0,t=0;
            fstream entrada(NOMBRE_ARCHIVO,ios::in);
            cout << "DESCRIPCION\tX\t\tY\t\tESTADO" << endl;
            while(!entrada.eof() && cont <= 100){
                getline(entrada,aux);
                t=0;
                while(t<=3){
                    cout << aux.substr(0,aux.find(",")) << "\t\t";
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    t++;
                }
                cont++;
                cout << endl;
            }
            entrada.close();
        }

        void listarDistanciaMenor10(){
            string aux;
            vector<posicion> vp;
            posicion p;
            int cont=0,t=0;
            fstream entrada(NOMBRE_ARCHIVO,ios::in);
            cout << "DESCRIPCION1\t\tDESCRIPCION2" << endl;
            while(!entrada.eof()){
                getline(entrada,aux);
                if(aux.size()>4){
                    p.descripcion = aux.substr(0,aux.find(","));
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.x = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.y = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    if(aux.length() >= 1){
                        p.estado = aux.at(0);
                    }
                    vp.push_back(p);
                }
            }
            for(int i=0;i<vp.size()-1;i++){
                for(int j=i+1;j<vp.size();j++){
                    if(sqrt(pow(vp[i].x - vp[j].x,2)+pow(vp[j].y - vp[i].y,2))<10){
                        cout << "DISTANCIA: " << sqrt(pow(vp[i].x - vp[j].x,2)+pow(vp[j].y - vp[i].y,2)) << endl;
                        cout << vp[i].descripcion << "\t\t\t" << vp[j].descripcion << endl;
                    }
                    cout << endl;
                }
            }
            entrada.close();
        }

        void hallarDistanciaPromedio(){
            string aux;
            vector<posicion> vp;
            posicion p;
            int cont=0;
            fstream entrada(NOMBRE_ARCHIVO,ios::in);
            while(!entrada.eof()){
                getline(entrada,aux);
                if(aux.size()>4){
                    p.descripcion = aux.substr(0,aux.find(","));
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.x = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.y = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    if(aux.length() >= 1){
                        p.estado = aux.at(0);
                    }
                    vp.push_back(p);
                }
            }
            double sum = 0;
            float d_prom = 0;
            for(int i=0;i<vp.size()-1;i++){
                for(int j=i+1;j<vp.size();j++){
                    sum += sqrt(pow(vp[i].x - vp[j].x,2)+pow(vp[j].y - vp[i].y,2));
                    cont ++;
                }
            }
            d_prom = sum / cont;
            cout << "DISTANCIA PROMEDIO: " << d_prom;
            entrada.close();
        }

        void hallarDistanciaMinima(){
            string aux;
            vector<posicion> vp;
            posicion p;
            int cont=0;
            double d_min;
            fstream entrada(NOMBRE_ARCHIVO,ios::in);
            while(!entrada.eof()){
                getline(entrada,aux);
                if(aux.size()>4){
                    p.descripcion = aux.substr(0,aux.find(","));
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.x = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.y = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    if(aux.length() >= 1){
                        p.estado = aux.at(0);
                    }
                    vp.push_back(p);
                }
            }
            d_min = 1000000;
            for(int i=0;i<vp.size()-1;i++){
                for(int j=i+1;j<vp.size();j++){
                    d_min = min(sqrt(pow(vp[i].x - vp[j].x,2)+pow(vp[j].y - vp[i].y,2)),d_min);
                    cont ++;
                }
            }

            cout << "DISTANCIA MÍNIMA: " << d_min;
            entrada.close();
        }

        void hallarDistanciaMaxima(){
            string aux;
            vector<posicion> vp;
            posicion p;
            int cont=0;
            double d_max;
            fstream entrada(NOMBRE_ARCHIVO,ios::in);
            while(!entrada.eof()){
                getline(entrada,aux);
                if(aux.size()>4){
                    p.descripcion = aux.substr(0,aux.find(","));
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.x = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.y = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    if(aux.length() >= 1){
                        p.estado = aux.at(0);
                    }
                    vp.push_back(p);
                }
            }
            d_max = 0;
            for(int i=0;i<vp.size()-1;i++){
                for(int j=i+1;j<vp.size();j++){
                    d_max = max(sqrt(pow(vp[i].x - vp[j].x,2)+pow(vp[j].y - vp[i].y,2)),d_max);
                    cont ++;
                }
            }

            cout << "DISTANCIA MÁXIMA: " << d_max;
            entrada.close();
        }

        void hallarDistanciaEntrePuntos(string d1, string d2){
            string aux;
            vector<posicion> vp;
            posicion p;
            int cont=0;
            double d_max;
            fstream entrada(NOMBRE_ARCHIVO,ios::in);
            while(!entrada.eof()){
                getline(entrada,aux);
                if(aux.size()>4){
                    p.descripcion = aux.substr(0,aux.find(","));
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.x = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    p.y = atof(aux.substr(0,aux.find(",")).c_str());
                    aux = aux.substr(aux.find(",")+1,aux.length()-aux.find(","));
                    if(aux.length() >= 1){
                        p.estado = aux.at(0);
                    }
                    vp.push_back(p);
                }
            }
            posicion p1, p2;
            for(int i=0;i<vp.size();i++){
                if(vp[i].descripcion == d1){
                    p1.descripcion = vp[i].descripcion;
                    p1.x = vp[i].x;
                    p1.y = vp[i].y;
                    p1.estado = vp[i].estado;
                }else if(vp[i].descripcion == d2){
                    p2.descripcion = vp[i].descripcion;
                    p2.x = vp[i].x;
                    p2.y = vp[i].y;
                    p2.estado = vp[i].estado;
                }
            }
            cout << "DISTANCIA: " << sqrt(pow(p1.x - p2.x,2)+pow(p1.y - p2.y,2));
            entrada.close();
        }

        void mostrarCantidadPosiciones(){
            int cont=0;
            string aux;
            fstream entrada(NOMBRE_ARCHIVO,ios::in);
            while(!entrada.eof()){
                getline(entrada,aux);
                cont++;
            }
            cout << "CANTIDAD DE POSICIONES: " << cont << endl;
            entrada.close();
        }

};


int main(){
    
    int opc = -1;
    while(opc != 0){
        cout << "\t\tMENU DE ENTRADA" << "\n\n";
        cout << "<1> Agregar nueva posición" << endl;
        cout << "<2> Eliminar una posición por nombre" << endl;
        cout << "<3> Listar 100 primeras posiciones" << endl;
        cout << "<4> Mostrar posiciones cuya distancia es menor que 10" << endl;
        cout << "<5> Hallar distancia promedio" << endl;
        cout << "<6> Hallar distancia mínima" << endl;
        cout << "<7> Hallar distancia máxima" << endl;
        cout << "<8> Hallar distancia entre puntos" << endl;
        cout << "<9> Mostrar cantidad de posiciones" << endl;
        cout << "<0> Salir" << endl;
        cout << "Ingrese la opcion que desea: "; cin >> opc;
        if(opc == 1){
            posicion p;
            cout << "Ingrese nombre o identificador: "; cin >> p.descripcion;
            cout << "Ingrese X: "; cin >> p.x;
            cout << "Ingrese Y: "; cin >> p.y;
            cout << "Ingrese estado: "; cin >> p.estado;
            p.agregarNuevaPosicion(p);
        }else if(opc == 2){
            posicion p;
            string nombre;
            cout << "Ingrese el nombre de la posicion que quiere eliminar: "; cin >> nombre;
            p.eliminarPosicionNombre(nombre);
        }else if(opc == 3){
            posicion p;
            p.listar100Primeros();
        }else if(opc == 4){
            posicion p;
            p.listarDistanciaMenor10();
        }else if(opc == 5){
            posicion p;
            p.hallarDistanciaPromedio();
        }else if(opc == 6){
            posicion p;
            p.hallarDistanciaMinima();
        }else if(opc == 7){
            posicion p;
            p.hallarDistanciaMaxima();
        }else if(opc == 8){
            posicion p;
            string nombre1, nombre2;
            cout << "Ingrese nombre de la posición 1: "; cin >> nombre1;
            cout << "Ingrese nombre de la posición 2: "; cin >> nombre2;
            p.hallarDistanciaEntrePuntos(nombre1, nombre2);
        }else if(opc == 9){
            posicion p;
            p.mostrarCantidadPosiciones();
        }else if(opc == 0){
            cout << "Gracias, vaquero. :v" << endl;
            return 0;
        }else{
            cout << "Esa opción no existe, pruebe otro" << endl;
        }
    }
    return 0;
}