#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <list>

using namespace std;

class Spk
{
private:
	//WP
	double jKriteria, jAlternatif, AB[10][10], tb, pilih;
	double tw[10], bobot[10], vektorS[10], vektorV[10], ts[10], total;
	string kriteria[10], alternatif[10];
	//SAW
	list<long double> bobot, temp, rr;
    list<string> kriteria;
    int jumlahkriteria, jumlahAlternatif, isiBobot;
    string isiKriteria;
    //AHP
    int jumlahKriteria, jumlahAlternatif, skip = 0;
    double kriteria[10][10], totalKriteria[10], alternatif[10][10][10], totalAlternatif[10][10];
    double normalisasiKriteria[10][10], totalnormalisasiKriteria[10], ci[10];
    double totalcm, lamdaMax, ci2, ri, cr, tbp[10][10], peregnkingan[10];
    double rasioIndeks[14] = {0, 0, 0.58, 0.9, 1.12, 1.24, 1.32, 1.41, 1.45, 1.49, 1.51, 1.48, 1.56, 1.59};
    
public:
	void metodeSaw()
	{
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
	
	
	void metodeWp()
	{
		cout << "================================" << endl;
		cout << "=  SISTEM PENDUKUNG KEPUTUSAN  =" << endl;
		cout << "=    METODE WAIGHTED PRODUCT   =" << endl;
		cout << "================================" << endl;
		cout << endl;
		cout << "MASUKKAN JUMLAH ALTERNATIF : ";
		cin >> jAlternatif;
		for (int i = 0; i < jAlternatif; i++)
		{
			cout << "MASUKAN ALTERNATIF " << i + 1 << "       : ";
			cin >> alternatif[i];
		}
		cout <<endl;
		cout << "============================" << endl;
		cout << "MASUKKAN JUMLAH KRITERIA   : ";
		cin >> jKriteria;
		for (int i = 0; i < jKriteria; i++)
		{
			cout <<endl;
			cout << "MASUKKAN KRITERIA " << i+1 << "        : ";
			cin >> kriteria[i];
			cout << "MASUKKAN BOBOT " << i+1 << "           : ";
			cin >> bobot[i];
		}

		for (int i = 0; i < jKriteria; i++)
		{
			tb = tb + bobot[i];
		}
		cout <<endl;
		for (int i = 0; i < jKriteria; i++)
		{
			tw[i] = bobot[i] / tb;
			cout << "C" << i+1 << "? 1.BENEFIT / 2.COST " <<  "    : "; cin >> pilih;
			if (pilih == 2)
			{
				 tw[i] = -tw[i];
			}
		}
		cout <<endl;
		for (int i = 0; i < jAlternatif; i++)
		{
			for (int s = 0; s < jKriteria; s++)
			{
				cout << "MASUKKAN NILAI A" << i+1 << " C" << s+1 <<  "       : ";
				cin >> AB[i][s];
			}
		}

		cout <<endl;
		cout << "+-------------------------+" << endl;
		cout << "| ALTERNATIF |    NAMA    |" << endl;
		cout << "+-------------------------+" << endl;
		for (int i = 0; i < jAlternatif; i++)
		{
			cout << "|     A" << i + 1 << "     |    " << alternatif[i] << endl;
		}
		cout << endl;
		cout << "+-----------------------------------------------------------+" << endl;
		cout << "|    |\tKRITERIA\t|\tBOBOT\t|\tTB\t" << endl;
		cout << "+-----------------------------------------------------------+" << endl;
		for (int i = 0; i < jKriteria; i++)
		{ 
			cout << "| C" << i + 1 << " |\t" << kriteria[i] << "\t\t|\t" << bobot[i] << "\t|\t"  << fixed << setprecision(3) << tw[i] << fixed << setprecision(0)  << endl;
		}

		cout << endl;
		cout << "+---------------+";
		for (int i = 0; i < jKriteria; i++)
		{
			cout << "+----------------+";
		}
		cout << endl;
		cout <<"\t\t";
		for (int i = 0; i < jKriteria; i++)
		{
			cout << "\tC" << i + 1 << "\t";
		}
		cout << endl;
		cout << "+---------------+";
		for (int i = 0; i < jKriteria; i++)
		{
			cout << "+----------------+";
		}
		cout << endl;
		for (int i = 0; i < jAlternatif; i++)
		{
			cout << "|\tA" << i + 1 << "\t|\t";
			for (int k = 0; k < jKriteria; k++)
			{
				cout << AB[i][k] << "\t\t";
			}
			cout << endl;
		}

		for (int i = 0; i < jAlternatif; i++)
		{
			vektorS[i] = 1;
			for (int k = 0; k < jKriteria; k++)
			{
				vektorS[i] = vektorS[i] * (pow(AB[i][k], tw[k]));
				
			}			
		}

		cout << endl;
		cout << "HASIL VEKTOR S" << endl;
		cout << "+---------------------------------------+" << endl;
		cout << "|\tAlternatif\t|\tS\t|" << endl;
		cout << "+---------------------------------------+"	<< endl;
		for (int i = 0; i < jAlternatif; i++)
		{
			ts[i] = ts[i] + vektorS[i];
			cout << "|\tA" << i+1 << "\t\t|\t" << fixed << setprecision(3) << ts[i] << fixed << setprecision(0) << endl;
		}

		for (int i = 0; i < jAlternatif; i++)
		{
			total = ts[i] + total;
		}
		

		for (int i = 0; i < jAlternatif; i++)
		{
			vektorV[i] = vektorS[i] / total; 
		}

		cout << endl;
		cout << "HASIL VEKTOR V" << endl;
		cout << "+---------------------------------------+" << endl;
		cout << "|\tAlternatif\t|\tV\t|" << endl;
		cout << "+---------------------------------------+"	<< endl;
		for (int i = 0; i < jAlternatif; i++)
		{
			cout << "|\tA" << i+1 << "\t\t|\t" << fixed << setprecision(3) << vektorV[i]   << fixed << setprecision(0) << endl;
		}
	}
	
	void meotodeAhp(){
		
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
    	}
		
	}
};

int main()
{
	Spk tubes;
	int pilihan;

	cout << " -------------------------------------------" << endl;
	cout << " |      PILIH METODE       |" << endl;
	cout << " -------------------------------------------" << endl;
	cout << " |[1]. Metode AHP          |" << endl;
	cout << " |[2]. Metode SAW          |" << endl;
	cout << " |[3]. Metode WP           |" << endl;
	cout << " -------------------------------------------" << endl;
	cout << " PILIH[1-3] = "; cin >> pilihan;
	
	if(pilihan == 1){
		tubes.meotodeAhp();
	}else if( pilihan == 2){
		tubes.metodeSaw();
	}else if( pilihan == 3){
		tubes.metodeWp()
	}
}
