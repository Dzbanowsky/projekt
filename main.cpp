#include <iostream>

using namespace std;

void program(int maxSuma = 0, int pomSuma = 0) // suma maksymalna, suma pomocnicza
{

     int M = 3, N = 5; //definiujemy tablicę bazową
    int MxN[3][5] =
  {
  {0,2,3,4,5},
  {1,3,4,5,3},
  {3,4,5,6,0}
  };
    int P = 2, Q = 2; //definiujemy tablicę PQ
    int  PxQ[2][2] = {{0,0},{0,0}};
    int  pomPxQ[2][2] = { {0,0},{0,0} };

    for(int w=0; w<3; w++) //ten for jest do wypisywanania tablicy
{

    for(int k=0; k<5; k++)
        {
        cout<<MxN[w][k]<<"\t";
        }
cout<<endl;
}



for (int w = 0; w < M-(P-1); w++) //pętla do przechodzenia po wierszach, przechodzimy przez M-1 wierszy
{
for (int k = 0; k < N-(Q-1); k++) //petla do przechodzenia po kolumnach, przechodzimy N-1 kolumn
{

for(int ww = 0; ww < P; ww++)   //przepisujemy do tablicy PQ kolejne podtablice wybierając po
                                //dwa wiersze i dwie kolumny i zliczanie sumy nowo wypełnionej tablicy

for (int kk = 0; kk < Q; kk++)
{
pomPxQ[ww][kk] = MxN[w+ww][k+kk];  //przepisanie z tablicy MxN do pomocniczej pomPxQ
pomSuma += pomPxQ[ww][kk];   //zwiekszanie sumy

}
//jeżeli suma pomSuma jest większa od maxSuma to podmieniamy wartości w tablicy PxQ
if (pomSuma > maxSuma)
{
maxSuma = pomSuma;
for (int wP = 0; wP < P; wP++)
for (int kQ = 0; kQ < Q; kQ++)
{
PxQ[wP][kQ] = pomPxQ[wP][kQ];
}
}
pomSuma = 0; //zerujemy sumę pomocniczą
}
}
//wyswietlamy znalezioną tablicą
for (int wP = 0; wP < P; wP++)
{
for (int kQ = 0; kQ < Q; kQ++)
{
cout <<" "<< PxQ[wP][kQ] << " ";
}
cout << endl;
}
}

int main()
{

program(); //wywolujemy nasza funkcje

    return 0;

}
