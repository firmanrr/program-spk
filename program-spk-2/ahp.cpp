#include <iostream>
#include <list>
#include <conio.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{

    int jumlahKriteria, jumlahAlternatif, skip = 0;
    double kriteria[10][10], totalKriteria[10], alternatif[10][10][10], totalAlternatif[10][10];
    double normalisasiKriteria[10][10], totalnormalisasiKriteria[10], ci[10];
    double totalcm, lamdaMax, ci2, ri, cr, tbp[10][10], peregnkingan[10];
    double rasioIndeks[14] = {0, 0, 0.58, 0.9, 1.12, 1.24, 1.32, 1.41, 1.45, 1.49, 1.51, 1.48, 1.56, 1.59};
	cout << "================================" << endl;
	cout << "=  SISTEM PENDUKUNG KEPUTUSAN  =" << endl;
	cout << "=          METODE AHP          =" << endl;
	cout << "================================" << endl;
	cout << endl;
    cout << "MASUKKAN JUMLAH KRITERIA  : ";
    cin >> jumlahKriteria;

    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {

            if (i == k)
            {
                kriteria[k][i] = 1;
            }
            else if (i < 1)
            {
                cout << "MASUKKAN NILAI KRITERIA C" << k + 1 << " C" << i + 1 << " : ";
                cin >> kriteria[k][i];
            }
            else
            {
                if (k <= skip)
                {
                    kriteria[k][i] = 1 / kriteria[skip][k];
                }
                else
                {
                    cout << "MASUKKAN NILAI KRITERIA C" << k + 1 << " C" << i + 1 << " : ";
                    cin >> kriteria[k][i];
                }
            }
        }
        skip++;
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {
            totalKriteria[i] = totalKriteria[i] + kriteria[k][i];
        }
    }

    cout << endl;
    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {
            cout << "\t" << kriteria[i][k] << "\t";
        }
        cout << endl;
    }
    cout << "==================================================" << endl;
    for (int l = 0; l < jumlahKriteria; l++)
    {
        cout << "\t" << fixed << setprecision(3) << totalKriteria[l] << fixed << setprecision(0) << "\t";
    }

    cout << endl;

    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {
            normalisasiKriteria[k][i] = kriteria[k][i];
        }
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {

        totalnormalisasiKriteria[i] = totalKriteria[i];
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {
        for (int k = 0; k < jumlahKriteria; k++)
        {
            normalisasiKriteria[k][i] = normalisasiKriteria[k][i] / totalnormalisasiKriteria[i];
        }
    }

    cout << endl
         << "NORMALISASI KRITERIA" << endl;
    for (int i = 0; i < jumlahKriteria; i++)
    {

        for (int k = 0; k < jumlahKriteria; k++)
        {
            cout << "\t" << fixed << setprecision(3) << normalisasiKriteria[i][k] << fixed << setprecision(0) << " \t";
        }
        cout << endl;
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {
        totalnormalisasiKriteria[i] = 0;
        for (int k = 0; k < jumlahKriteria; k++)
        {
            totalnormalisasiKriteria[i] = totalnormalisasiKriteria[i] + normalisasiKriteria[i][k];
        }
        totalnormalisasiKriteria[i] = totalnormalisasiKriteria[i] / 3;
    }

    cout << "==================================================" << endl;
    for (int l = 0; l < jumlahKriteria; l++)
    {
        cout << "\t" << fixed << setprecision(3) << totalnormalisasiKriteria[l] << fixed << setprecision(0) << "\t";
    }

    cout << endl
         << endl;

    cout << "MASUKKAN JUMLAH ALTERNAITF : ";
    cin >> jumlahAlternatif;
    for (int s = 0; s < jumlahKriteria; s++)
    {
        skip = 0;
        for (int i = 0; i < jumlahAlternatif; i++)
        {
            for (int k = 0; k < jumlahAlternatif; k++)
            {

                if (i == k)
                {
                    alternatif[s][k][i] = 1;
                }
                else if (i < 1)
                {
                    cout << "MASUKKAN NILAI ALTERNATIF A" << k + 1 << " A" << i + 1 << " : ";
                    cin >> alternatif[s][k][i];
                }
                else
                {
                    if (k <= skip)
                    {
                        alternatif[s][k][i] = 1 / alternatif[s][skip][k];
                    }
                    else
                    {
                        cout << "MASUKKAN NILAI ALTERNATIF A" << k + 1 << " A" << i + 1 << " : ";
                        cin >> alternatif[s][k][i];
                    }
                }
            }
            skip++;
        }
    }

    for (int s = 0; s < jumlahKriteria; s++)
    {
        for (int i = 0; i < jumlahAlternatif; i++)
        {
            for (int k = 0; k < jumlahAlternatif; k++)
            {
                totalAlternatif[s][i] = totalAlternatif[s][i] + alternatif[s][k][i];
            }
        }
    }

    cout << endl;
    for (int s = 0; s < jumlahKriteria; s++)
    {
        cout << endl;
        cout << "KRITERIA " << s + 1 << endl;
        for (int i = 0; i < jumlahAlternatif; i++)
        {
            for (int k = 0; k < jumlahAlternatif; k++)
            {
                cout << "\t" << fixed << setprecision(3) << alternatif[s][i][k] << fixed << setprecision(0) << "\t";
            }
            cout << endl;
        }
        cout << "==================================================" << endl;

        for (int l = 0; l < jumlahAlternatif; l++)
        {
            cout << "\t" << fixed << setprecision(3) << totalAlternatif[s][l] << fixed << setprecision(0) << "\t";
        }
        cout << endl;
    }

    for (int s = 0; s < jumlahKriteria; s++)
    {
        for (int i = 0; i < jumlahAlternatif; i++)
        {
            for (int k = 0; k < jumlahAlternatif; k++)
            {
                alternatif[s][k][i] = alternatif[s][k][i] / totalAlternatif[s][i];
            }
        }
        cout << endl
             << "NORMALISASI ALTERNATIF" << endl;
        for (int i = 0; i < jumlahAlternatif; i++)
        {

            for (int k = 0; k < jumlahAlternatif; k++)
            {
                cout << "\t" << fixed << setprecision(3) << alternatif[s][i][k] << fixed << setprecision(0) << " \t";
            }
            cout << endl;
        }

        for (int i = 0; i < jumlahAlternatif; i++)
        {
            totalAlternatif[s][i] = 0;
            for (int k = 0; k < jumlahAlternatif; k++)
            {
                totalAlternatif[s][i] = totalAlternatif[s][i] + alternatif[s][i][k];
            }
            totalAlternatif[s][i] = totalAlternatif[s][i] / jumlahAlternatif;
            tbp[i][0] = totalAlternatif[s][i];
        }

        cout << "==================================================" << endl;
        for (int l = 0; l < jumlahAlternatif; l++)
        {
            cout << "\t" << fixed << setprecision(3) << totalAlternatif[s][l] << fixed << setprecision(0) << "\t";
        }
    }

    cout << endl;

    totalcm = 0;
    for (int i = 0; i < jumlahKriteria; i++)
    {
        if (jumlahKriteria == 3)
        {
            ci[i] = (kriteria[i][0] * totalnormalisasiKriteria[0]) + (kriteria[i][1] * totalnormalisasiKriteria[1]) + (kriteria[i][2] * totalnormalisasiKriteria[2]) / totalnormalisasiKriteria[i];
        }
        else if (jumlahKriteria == 4)
        {
            ci[i] = (kriteria[i][0] * totalnormalisasiKriteria[0]) + (kriteria[i][1] * totalnormalisasiKriteria[1]) + (kriteria[i][2] * totalnormalisasiKriteria[2]) + (kriteria[i][3] * totalnormalisasiKriteria[3]) / totalnormalisasiKriteria[i];
        }
        else if (jumlahKriteria == 5)
        {
            ci[i] = (kriteria[i][0] * totalnormalisasiKriteria[0]) + (kriteria[i][1] * totalnormalisasiKriteria[1]) + (kriteria[i][2] * totalnormalisasiKriteria[2]) + (kriteria[i][3] * totalnormalisasiKriteria[3]) + (kriteria[i][4] * totalnormalisasiKriteria[4]) / totalnormalisasiKriteria[i];
        }else if (jumlahKriteria == 6)
        {
            ci[i] = (kriteria[i][0] * totalnormalisasiKriteria[0]) + (kriteria[i][1] * totalnormalisasiKriteria[1]) + (kriteria[i][2] * totalnormalisasiKriteria[2]) + (kriteria[i][3] * totalnormalisasiKriteria[3]) + (kriteria[i][4] * totalnormalisasiKriteria[4]) + (kriteria[i][5] * totalnormalisasiKriteria[5])/ totalnormalisasiKriteria[i];
        }

        totalcm = ci[i] + totalcm;
    }

    cout << "CM" << endl;
    for (int i = 0; i < jumlahKriteria; i++)
    {
        cout << "\t" << fixed << setprecision(3) << ci[i] << fixed << setprecision(0) << "\t";
    }

    lamdaMax = totalcm / jumlahKriteria;
    ci2 = lamdaMax - jumlahKriteria / jumlahKriteria - 1;
    ri = rasioIndeks[jumlahKriteria - 1];
    cr = ci2 / ri;

    cout << endl;
    cout << jumlahKriteria << endl;
    cout << "LAMDA MAX   :" << fixed << setprecision(3) << lamdaMax << fixed << setprecision(0) << endl;
    cout << "CI          :" << fixed << setprecision(3) << ci2 << fixed << setprecision(0) << endl;
    cout << "RI          :" << fixed << setprecision(3) << ri << fixed << setprecision(0) << endl;
    cout << "CR          :" << fixed << setprecision(3) << cr << fixed << setprecision(0) << endl;

    for (int i = 0; i < jumlahAlternatif; i++)
    {
        peregnkingan[i] = 0;
        for (int k = 0; k < jumlahKriteria; k++)
        {
            peregnkingan[i] = (totalnormalisasiKriteria[k] * totalAlternatif[i][k]) + peregnkingan[i];
        }
    }

    for (int i = 0; i < jumlahKriteria; i++)
    {
        cout << fixed << setprecision(3) << peregnkingan[i] << fixed << setprecision(0) << endl
             << endl;
        ;
    }

    return 0;
}
