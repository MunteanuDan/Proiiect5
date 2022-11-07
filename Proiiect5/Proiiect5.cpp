#include <iostream>
#include <string>
using namespace std;

int main()
{

    // masive unidimensionale (vectori), bidimensionale (matrice)
    int vector[4];
    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;
    vector[3] = 4;

    unsigned int dimensiune = sizeof(vector) / sizeof(int); // unsigned - nu poate fi negativa
    // obtin dimensiunea 4
//  cout << vector << endl; afiseaza adresa primului element

    for (int i = 0; i < dimensiune; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
    // vectorul clasic se dezaloca automat

    // alocam dinamic
    unsigned int d = 4;
    int* v = new int[d];
    cout << v << endl; // ne apare adresa lui v

    for (int i = 0; i < d; i++)
    {
        v[i] = i + 1;
    }
    for (int i = 0; i < d; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    //  delete[] v; // dezalocam vectorul dinamic, reseteaza adresa
    //  cout << v << endl; // ne apare in continuare adresa lui v, se numeste dengling pointer

      // ca sa dezalocam corect:
    delete[] v;
    v = nullptr;
    cout << v << endl;

    //  MATRICE

    float matrice[2][3];
    matrice[1][1] = 99;
    cout << matrice[1][1] << endl; // afiseaza 99
    cout << matrice << endl; // adresa matricei, coincide cu adresa primei linii
    cout << matrice[0] << endl; // adresa de inceput a primei linii din matrice
    cout << matrice[1] << endl; // adresa de inceput a primei linii din matrice

    unsigned int nrLinii = sizeof(matrice) / sizeof(matrice[0]); // impartim matricea la prima linie, asa rezulta nr de linii  
    cout << nrLinii << endl; // afiseaza 2, nr de linii

    unsigned int nrColoane = sizeof(matrice[0]) / sizeof(float); // impartim prima linie la cat ocupa primul element
    cout << nrColoane << endl; // afiseaza 3, nr de coloane

    // MATRICE ALOCATE DINAMIC

    unsigned int l = 2;
    unsigned int c = 3;
    float** m = new float* [2];
    for (int i = 0; i < l; i++)
    {
        m[i] = new float[c]; // fiecare element va salva o adresa de inceput a unui vector de 3 elemente, adica liniile matricei
    }

    // facem o matrice cu 2 linii si 3 coloane
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    // dezalocare matrice
    for (int i = 0; i < l; i++)
    {
        delete[] m[i];
    }
    delete[] m;
    m = nullptr;


    // SIRURI DE CARACTERE
    char sir[10];
    strcpy_s(sir, "ceva");
    cout << sir << endl; // afiseaza "ceva"

    int n = 0;
    cout << "Numarul de caractere = ";
    cin >> n;
    char* vector1 = new char[n + 1];
    cin >> vector1;
    cout << vector1 << endl;
    cout << strcmp(sir, vector1) << endl;
    delete[] vector1;

    // STRINGURI
    string sir1 = "ceva";
    cout << sir1 << endl;
    sir1 += "!"; // pt concatenare
    cout << sir1 << endl;

    string sir2 = sir;
    cout << endl << endl;
    const char* x = sir2.c_str(); //nu pot schimba caracterele din sir prin intermediul lui x
    // x poate salva insa alta adresa
    cout << sir2.length() << endl;


    int a = 3;
    int& r = a;
    a++;
    cout << r; // afiseaza 4



}
