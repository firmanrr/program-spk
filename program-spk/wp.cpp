#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>
#include <algorithm>

using namespace std;

class Spk
{
private:
	double jKriteria, jAlternatif, AB[10][10], tb, pilih;
	double tw[10], bobot[10], vektorS[10], vektorV[10], ts[10], total;
	string kriteria[10], alternatif[10];

public:
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
};

int main()
{
	Spk tubes;

	tubes.metodeWp();
}
