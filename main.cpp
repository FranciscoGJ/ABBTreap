//
// Created by Francisco on 06-06-2015.
//

#include <iostream>
#include "Treap.h"
#include "MyStructure.h"
#include <chrono>
#include <random>
#include "Diccionary.h"
#include <iomanip>
#include <unordered_map>
#include <time.h>
#include <map>

using namespace std;

/*
Random Unique Number generation based on algorithm found at
http://preshing.com/20121224/how-to-generate-a-sequence-of-unique-random-integers/
Jeff Preshing, Dec 24, 2012, Canada.
*/

unsigned long random_unique(unsigned long x, int i) {
    unsigned long primes[10] = {999991,199999,299993,399989,499979,599999,699967,799999,899981,999983};
    unsigned long prime = primes[i];
    if (x >= prime)
        return x;
    unsigned long residue = ((unsigned long long) x * x) % prime;
    return (x <= prime / 2) ? residue : prime - residue;
}

int main(){


    using namespace std::chrono;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, 25);

    double cont = 0;
    double suma = 0;

    // Seccion que promedia los tiepos de insercion en Diccionario Priorida con las dos estructuras implementadas

    for(int i = 100000; i <= 1000000; i = i + 100000){      // Se calcula los tiempos de insercion para MyStructure

        while(cont < 10){
            DiccionarioPrioridad<MyStructure<float,float>,float,float>* DiccionarioMy = new DiccionarioPrioridad<MyStructure<float,float>,float,float>();
            steady_clock::time_point inicio = steady_clock::now();
            for(int j = 0;j < i; j++){
                DiccionarioMy->Insert(dist(mt),j,dist(mt)*2);
            }
            steady_clock::time_point final = steady_clock::now();
            duration<double> tiempo_ocupado = duration_cast<duration<double>>(final-inicio);
            suma = suma + tiempo_ocupado.count();
            cont++;
            delete DiccionarioMy;
        }
        cont = 0;
        cout << suma/10 << endl;
        suma = 0;

    }

    for(int i = 100000; i <= 1000000; i = i + 100000){      // Se calcula los tiempos de insercion para Treap

        while(cont < 10){
            DiccionarioPrioridad<Treap<float,float>,float,float>* DiccionarioTreap = new DiccionarioPrioridad<Treap<float,float>,float,float>();
            steady_clock::time_point inicio = steady_clock::now();
            for(int j = 0;j < i; j++){
                DiccionarioTreap->Insert(dist(mt),j,dist(mt)*2);
            }
            steady_clock::time_point final = steady_clock::now();
            duration<double> tiempo_ocupado = duration_cast<duration<double>>(final-inicio);
            suma = suma + tiempo_ocupado.count();
            cont++;
            delete DiccionarioTreap;
        }
        cont = 0;
        cout << suma/10 << endl;
        suma = 0;
    }

    //----------------------------------------------------------------------------------------------------------------------

    //Seccion que calcula los tiempos de busquedas del Diccionario Priorida con las dos estructuras implementadas

    int cont2 = 0;
    int cont3 = 0;
    int cont4 = 0;
    for(int i = 100000; i <= 1000000; i = i + 100000){      // Se calcula los tiempos de busqueda para Treap

            DiccionarioPrioridad<Treap<float,float>,float,float>* DiccionarioTreap = new DiccionarioPrioridad<Treap<float,float>,float,float>();
            for(int k = 0;k < i; k++){
                DiccionarioTreap->Insert(random_unique(k,cont3) + (-1*(k%2))*(k%5)*random_unique(i-k,cont3),k,dist(mt)*2);
            }
            while(cont4 < 20){
                while(cont2 < i){
                    steady_clock::time_point inicio = steady_clock::now();
                    DiccionarioTreap->Search(random_unique(cont2,cont3) + (-1*(cont2%2))*(cont2%5)*random_unique(i-cont2,cont3));
                    steady_clock::time_point final = steady_clock::now();
                    duration<double> tiempo_ocupado = duration_cast<duration<double>>(final-inicio);
                    suma = suma + tiempo_ocupado.count();
                    cont2++;
                }
                cont4++;
            }

        delete DiccionarioTreap;
        cont2 = 0;
        cont4 = 0;
        cont3++;
        cout << suma/20 << endl;
        suma = 0;
    }


    for(int i = 100000; i <= 1000000; i = i + 100000){      // Se calcula los tiempos de busqueda para MyStructure

        DiccionarioPrioridad<MyStructure<float,float>,float,float>* DiccionarioMy = new DiccionarioPrioridad<MyStructure<float,float>,float,float>();
        for(int k = 0;k < i; k++){
            DiccionarioMy->Insert(random_unique(k,cont3) + (-1*(k%2))*(k%5)*random_unique(i-k,cont3),k,dist(mt)*2);
        }
        while(cont4 < 20){
            while(cont2 < i){
                steady_clock::time_point inicio = steady_clock::now();
                DiccionarioMy->Search(random_unique(cont2,cont3) + (-1*(cont2%2))*(cont2%5)*random_unique(i-cont2,cont3));
                steady_clock::time_point final = steady_clock::now();
                duration<double> tiempo_ocupado = duration_cast<duration<double>>(final-inicio);
                suma = suma + tiempo_ocupado.count();
                cont2++;
            }
            cont4++;
        }

        delete DiccionarioMy;
        cont2 = 0;
        cont4 = 0;
        cont3++;
        cout << setprecision(15);
        cout << suma/10 << endl;
        suma = 0;
    }


    return 0;
}

