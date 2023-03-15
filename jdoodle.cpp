#include<bits/stdc++.h>
using namespace std;

void oddEvenSort(int arr[], int n) // sortiranje na nizata so koristenje na  odd-even sort algoritmot za sortiranje
{
    bool isSorted = false; 

    while (!isSorted)
    {
        isSorted = true;

        for (int i=1; i<=n-2; i=i+2) //Se povtoruvaat site elementi so neparen indeks vo nizata i se sporeduvaat so sosedniot element. Ako e pogolem vo sosedniot tie se zamenuvaat, a isSorted e postaveno na false
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }

        for (int i=0; i<=n-2; i=i+2) //istoto se povtoruva so elementite so paren indeks
        {
            if (arr[i] > arr[i+1]) //ako poveke zameni ne se potrebni isSortet se postavuva na true
            {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }

    return;
}

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    string name = "Marija Ognenovska INKI948";//inicijalizacija na stringot na nizata
    const int MAX_ASCII_CODE = 256;
    int arr[MAX_ASCII_CODE];
    memset(arr, 0, sizeof(arr));//inicijalizacija na site elementi od nizata  na 0

    for (int i = 0; i < name.length(); i++) {
        if (isalpha(name[i])) {//proverka dali elementot na nizata e od azbukata
            arr[(int)name[i]] = (int)name[i];
        } else {
            arr[(int)name[i]] = -1; 
        }
    }

    int n = sizeof(arr)/sizeof(arr[0]);

    oddEvenSort(arr, n);
    
    for (int i=0; i < n; i++) {
        if (arr[i] > 0) {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";

    return (0);
}

//Функцијата oddEvenSort го имплементира алгоритамот за сортирање непарни парови, кој ја подредува низата со изведување на сортирање со меурчиња на непарните индексирани елементи, а потоа на елементите со парни индекси додека не се подреди низата.Главната разлика помеѓу bubble sort и OddEvenSort е во тоа како се вршат поминувањата низ низата. Во сbubble, сите соседни елементи се споредуваат и се заменуваат доколку е потребно, без оглед на нивните индекси. Во OddEvenSort, само елементите со непарни индекси се споредуваат и заменуваат при првото поминување, а само елементите со парни индекси се споредуваат и заменуваат во второто поминување. Овој модел на споредување и замена на непарните и парните индексирани елементи наизменично продолжува додека низата не се подреди 