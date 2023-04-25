#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename, text;

    cout << "Vnesi go imeto na fajlot: ";
    cin >> filename;

    cout << "Vnesi tekst: ";
    cin.ignore();
    getline(cin, text);

    ofstream outfile;
    outfile.open(filename, ios::app);

    if (outfile.is_open())
    {
        outfile << text << endl;
        outfile.close();
        cout << "Tekstot e zapisan vo fajlot" << endl;
    }
    else
    {
        cout << "Ne moze da se otvori fajlot" << endl;
    }

    return 0;
}
