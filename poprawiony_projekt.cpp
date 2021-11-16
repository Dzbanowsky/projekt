#include <iostream>

using namespace std;

void zwracanie(int MxN[][5], int PxQ[][2], int pomPxQ[][2], int M, int N, int P, int Q) {
  int maxSuma = 0, pomSuma = 0; // suma maksymalna, suma pomocnicza
  for (int w = 0; w < M - (P - 1); w++) //petla do przechodzenia po wierszach, przechodzimy przez M-1 wierszy
  {
    for (int k = 0; k < N - (Q - 1); k++) //petla do przechodzenia po kolumnach, przechodzimy N-1 kolumn
    {
      //przepisujemy do tablicy PQ kolejne podtablice wybierajac po dwa wierszw i dwie kolumny
      // i zliczanie sumy nowo wypelnionej tablicy
      for (int ww = 0; ww < P; ww++)
        for (int kk = 0; kk < Q; kk++)
        {
          pomPxQ[ww][kk] = MxN[w + ww][k + kk]; //przepisanie z tablicy MxN do pomocniczej pomPxQ
          pomSuma += pomPxQ[ww][kk]; //zwiekszenie sumy

        }
      //jezeli suma pomSuma jest wieksza od maxSuma to podmieniamy wartooci w tablicy PxQ
      if (pomSuma > maxSuma)
      {
        maxSuma = pomSuma;
        for (int wP = 0; wP < P; wP++)
          for (int kQ = 0; kQ < Q; kQ++)
          {
            PxQ[wP][kQ] = pomPxQ[wP][kQ];
          }
      }
      pomSuma = 0; //zerujemy sumy pomocnicze
    }
  }
  //wyswietlamy znalezione tablice
  for (int wP = 0; wP < P; wP++)
  {
    for (int kQ = 0; kQ < Q; kQ++)
    {
      cout << PxQ[wP][kQ] << " ";
    }
    cout << endl;
  }
}

int main() {
  //definiujemy tablice bazowa
  int M = 3, N = 5;
  int MxN[3][5] =
  {
    {0,2,3,4,5},
    {1,3,4,5,3},
    {3,4,5,6,0}
  };
  //gdyby trzeba bylo zmienic rozmiar tablicy bazowej
  //int M = 4, N =5;
  //int MxN[4][5] = { { 0,2,3,4,5},{ 1,3,4,5,3},{3,4,5,6,0} ,{8,9,5,6,0} };

  //definiujemy tablic� PQ
  int P = 2, Q = 2;
  int PxQ[2][2] =
  { {0,0},{0,0}};
  int pomPxQ[2][2] = {{0,0},{0,0}};

  //gdyby trzeba bylo zmienic rozmiar szukanej tablicy
  /*
  int P = 2, Q = 3;
  int  PxQ[2][3] = {{0,0,0},{0,0,0}};
  int  pomPxQ[2][3] = { {0,0,0},{0,0,0} };
  */
  for (int w = 0; w < 3; w++) //ten for jest do wypisywanania tablicy
  {

    for (int k = 0; k < 5; k++)
    {
      cout << MxN[w][k] << "\t";
    }
    cout << endl;
  }

  zwracanie(MxN, PxQ, pomPxQ, M, N, P, Q); //wywolanie funkcji

}
