#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main()
{

    list<long double> bobot, temp, rr;
    list<string> kriteria;

    int jumlahkriteria, jumlahAlternatif, isiBobot;
    string isiKriteria;

    double Alternatif[10][10], jenis[10], minmax[10], hs[10][10], wr[10][10], result[10];
	cout << "================================" << endl;
	cout << "=  SISTEM PENDUKUNG KEPUTUSAN  =" << endl;
	cout << "=          METODE SAW          =" << endl;
	cout << "================================" << endl;
	cout << endl;
    cout << "MASUKKAN JUMLAH KRITERIA  : ";
    cin >> jumlahkriteria;
    cout << endl;
    for (int i = 0; i < jumlahkriteria; ++i)
    {
        cout << "MASUKKAN KRITERIA     : ";
        cin >> isiKriteria;
        kriteria.push_back(isiKriteria);
        cout << "MASUKKAN BOBOT (%)    : ";
        cin >> isiBobot;
        bobot.push_back(isiBobot);
        cout << "1.BENEFIT / 2.COST    : ";
        cin >> jenis[i];
        cout << endl;
    }

    auto ik = kriteria.begin();
    auto ib = bobot.begin();
    int i = 1;
    cout << "+------------------------------------+" << endl;
    cout << "|             KRITERIA               |" << endl;
    cout << "+------------------------------------+" << endl;
    while (ik != kriteria.end() && ib != bobot.end())
    {
        cout << "    K" << i << "\t" << (*ik) << "\t" << (*ib) << "\t" << (*ib / 100) << endl;
        ik++;
        ib++;
        i++;
    }
	cout << endl;
    cout << "MASUKKAN JUMLAH ALTERNATIF : ";
    cin >> jumlahAlternatif;
    for (int i = 0; i < jumlahkriteria; i++)
    {
        for (int k = 0; k < jumlahAlternatif; k++)
        {
			cout << endl;
            cout << "MASUKKAN NILAI A" << k + 1 << " C" << i + 1 << " : ";
            cin >> Alternatif[k][i];
            temp.push_back(Alternatif[k][i]);
            if (jenis[i] == 2)
            {
                temp.sort();
            }
            else
            {
                temp.sort([](int a, int b)
                          { return a > b; });
            }
            minmax[i] = temp.front();
        }
        temp.clear();
    }

    cout << endl;
    for (int s = 0; s < jumlahkriteria; s++)
    {
        cout << minmax[s] << endl;
    }
    cout << endl;

    cout << "+------------------------------------+" << endl;
    cout << "|                DATA                |" << endl;
    cout << "+------------------------------------+" << endl;
    for (int i = 0; i < jumlahAlternatif; i++)
    {
        cout << "\tA" << i + 1 << "\t";
        for (int k = 0; k < jumlahkriteria; k++)
        {
            cout << "\t" << Alternatif[i][k] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < jumlahkriteria; i++)
    {
        for (int k = 0; k < jumlahAlternatif; k++)
        {
            if (jenis[i] == 1)
            {
                hs[k][i] = Alternatif[k][i] / minmax[i];
            }
            else
            {
                hs[k][i] = minmax[i] / Alternatif[k][i];
            }
        }
    }

    cout << "+------------------------------------+" << endl;
    cout << "|         NORMALISASI DATA           |" << endl;
    cout << "+------------------------------------+" << endl;
    for (int i = 0; i < jumlahAlternatif; i++)
    {
        cout << "\tA" << i + 1 << "\t";
        for (int k = 0; k < jumlahkriteria; k++)
        {
            cout << hs[i][k] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < jumlahkriteria; i++)
    {
        for (int k = 0; k < jumlahAlternatif; k++)
        {
            wr[k][i] = hs[k][i] * (bobot.front() / 100);
        }
        bobot.pop_front();
    }

    cout << "+------------------------------------+" << endl;
    cout << "|         WEIGHTING RESULT           |" << endl;
    cout << "+------------------------------------+" << endl;
    for (int i = 0; i < jumlahAlternatif; i++)
    {
        cout << "\tA" << i + 1 << "\t";
        for (int k = 0; k < jumlahkriteria; k++)
        {
            cout << wr[i][k] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < jumlahAlternatif; i++)
    {
        for (int k = 0; k < jumlahkriteria; k++)
        {
            result[i] = result[i] + wr[i][k];
        }
    }

    for (int i = 0; i < jumlahAlternatif; i++)
    {
        rr.push_back(result[i]);
    }

    
    int j = jumlahAlternatif;
    cout << "+------------------------------------+" << endl;
    cout << "|          RANKING RESULT            |" << endl;
    cout << "+------------------------------------+" << endl;
    rr.sort();
    for (auto it = rr.begin(); it != rr.end(); ++it)
    {
        cout << '\t' << *it << "\t" << j << endl;
    	j--;
	}
}
