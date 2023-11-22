#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int pilihm;
//SAW
string kriteria[99];
float bobot[99];
float r[99][99];

float maxValue;
float minValue;
float rmax[99];
float x[99][99];
string cost[99];

float rangking[99][99];
float totalrangking[99];
int kri = 4;
int alt = 5;
float v[99];
string nalt[99];


void piliMetode(){
	system("cls");
	cout << " -------------------------------------------" << endl;
	cout << " |      PILIH METODE       |" << endl;
	cout << " -------------------------------------------" << endl;
	cout << " |[1]. Metode AHP          |" << endl;
	cout << " |[2]. Metode SAW          |" << endl;
	cout << " |[3]. Metode WP           |" << endl;
	cout << " -------------------------------------------" << endl;
	cout << " PILIH[1-3] = "; cin >> pilihm;
}
void metodeAhp(){
	system("cls");
	cout << " -------------------------------------------" << endl;
	cout << " |       METODE AHP        |" << endl;
	cout << " -------------------------------------------" << endl;
}
void metodeSaw(){
	system("cls");
	cout << " -------------------------------------------" << endl;
	cout << " |       METODE SAW        |" << endl;
	cout << " -------------------------------------------" << endl;
	cout << " | INPUT ALTERNATIF         " << endl; 
	for(int j = 0 ; j <alt; j++){
		cout << " | A" << j+1 << " = "; cin >> nalt[j]; 
	}
	cout << endl;
	cout << " -------------------------------------------" << endl;
	cout << " | INPUT KRITERIA           " << endl;
	for(int i=0 ; i<4 ; i++){
		cout << " | KRITERIA     = "; cin >> kriteria[i];
		cout << " | BOBOT        = "  ; cin >> bobot[i];
		cout << " | BENEFIT/COST = "  ; cin >> cost[i];
		
		cout << endl;
	}
	cout << endl;
	cout << " -------------------------------------------" << endl;
	cout << " | RATING KECOCOKAN         " << endl;
	for(int i=0 ; i<kri ; i++){
		for(int j=0 ; j<alt ; j++){					
			cout << " | Input C " << i+1 << " A" << j+1 << " = "; cin >> r[i][j];
			if(cost[i] == "COST"){
				if(j == 0){
				maxValue = r[i][j];				
				}	
				if (r[i][j] < maxValue) {
				 	maxValue = r[i][j];
				}								
			}else{
			if(j == 0){
				maxValue = r[i][j];				
			}	
			if (r[i][j] > maxValue) {
			 	maxValue = r[i][j];
			}					
			}
			rmax[i] = maxValue;						
		}
		cout << endl;		 
    }	
}
void matriks(){
	cout << " -------------------------------------------" << endl;
	cout << " | MATRIKS TERNORMALISASI   " << endl;
	for(int i=0 ; i<kri ; i++){
		for(int j=0 ; j<alt ; j++){
			if(cost[i] == "COST"){
				x[i][j] = rmax[i] / r[i][j];	
			}else{
				x[i][j] = r[i][j]	/ rmax[i];				
			}		
			cout  << " | "<<	 x[i][j] << endl ;			
		}
		cout << endl;
    }
	system("pause");	
}
void perangkingan(){
	for(int i=0 ; i<=kri ; i++){
		for(int j=0 ; j<=alt ; j++){		
			rangking[j][i] = x[j][i] * (bobot[j] / 100);	
		}
	}	
}
void xperangkingan(){
	cout << " ------------------------------------------------" << endl;
	cout << " | BOBOT * MATRIKS TERNORMALISASI" << endl;
	for(int i=0 ; i<kri ; i++){
		for(int j=0 ; j<alt ; j++){		
			cout  << " | " << rangking[i][j] << endl;
			if(j == (alt-1)){
				cout << endl;
			}
			v[j] = rangking[0][j] + rangking[1][j] +rangking[2][j] +rangking[3][j] ;
		}
	}
	system("pause");	
}
void hasil(){
	cout << " -------------------------------------------" << endl;
	cout << " | PERANGKINGAN             " << endl;
	
	for(int j=0 ;j<alt;j++){
		cout  <<" | [" << j << "] "<< nalt[j] << "\t= "<< v[j] << endl;
	}
	cout << endl;
	system("pause");
}
void sorting()
{
	string tempNama;
	float tempjbarang;

	for (int k = 0; k < alt; k++)	{
		for (int s   = k + 1; s < alt; s++)	{
			if (v[k] < v[s])
			{
				tempNama     = nalt[k];
				tempjbarang  = v[k];

				nalt[k]    = nalt[s];
				v[k]       = v[s];				

				nalt[s] = tempNama;
				v[s]    = tempjbarang;
			}
		}
	}
}

void metodeWp(){
	system("cls");
	cout << " -------------------------------------------" << endl;
	cout << " |        METODE WP        |" << endl;
	cout << " -------------------------------------------" << endl;	
}

int main(){	
	piliMetode();
	switch(pilihm){
		case 1:
			metodeAhp();
			break;
		case 2:
			metodeSaw();
			matriks();
			perangkingan();
			xperangkingan();
			sorting();
			hasil();
			break; 
		case 3:
			metodeWp();
			break;
		default:
			cout << " Anda salah Pilih ";
	}
}
