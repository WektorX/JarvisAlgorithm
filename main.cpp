//============================================================================
// Name        : lab1.cpp
// Author      : Wiktor Jurek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <conio.h>
using namespace std;


void show(int *tab, int n) {
	fstream file;
	file.open("out.txt", ios::out | ios::app);
	if(file.good() == true) {
		for(int i=0; i<n; i++) {
			file<<tab[i]<<" ";
			cout<<tab[i]<<" ";
		}
		file<<"\n";
		cout<<endl;
		file.close();
	}
}

int main() {

	fstream file1;
	file1.open("out.txt", ios::out | ios::trunc);
	file1.close();

	int N;
	cout<<"Podaj ilosc punktow zbior N"<<endl<<"N = ";
	cin>>N;

	int **tab = new int* [N];
	for(int i=0; i<N; i++) {
		tab[i] = new int[2];
		for(int j=0; j<2; j++) {
			tab[i][j] = 0;
		}
	}
	int chose;

	cout<<"Wybierz czy pobrac dane z pliku czy wprowadzic recznie "<<endl<<"0 - recznie"<<endl<<"1- z pliku"<<endl;
	cin>>chose;
	if(chose == 0) {
		cout<<"Wprawadz wspolrzedne kolejnych punktow w zakresie x i y [0,500]:"<<endl;
		for(int i=0; i<N; i++) {
			cout<<"Punkt"<<i<<" :"<<endl;
			cout<<"x = ";
			cin>>tab[i][0];
			cout<<"y = ";
			cin>>tab[i][1];

		}
	}
	else{
		ifstream plik;
		plik.open("data.txt");
		for(int i=0;i<N;i++){
			plik>>tab[i][0];
			plik>>tab[i][1];
		}
		plik.close();
	}


	int pMin,pMax;
	pMin = 0;
	pMax = 0;
	for(int i=0; i<N; i++) {
		if(tab[i][1] >= tab[pMax][1]) {
			pMax = i;
		}
		if(tab[i][1] <= tab[pMin][1]) {
			pMin = i;
		}

	}

	bool right = true;
	int current;
	int rightP, leftP;
	if(tab[pMin][0] >= tab[pMax][0]) {
		rightP = pMax;
		leftP = pMin;
	} else {
		rightP = pMin;
		leftP = pMax;
	}
	cout<<tab[rightP][0]<<endl;

	current = pMin;
	bool end = false;
	cout<<"Otoczka"<<endl;
	cout<<"x"<<pMin<<" "<<tab[pMin][0]<<" "<<tab[pMin][1]<<" "<<endl;

	fstream file;
	file.open("out.txt", ios::out | ios::app);
	file<<tab[pMin][0]<<" "<<tab[pMin][1]<<"\n";
	while(end == false) {
		if(right == true) {
			int sIndex;
			double smallest, rSmallest;
			smallest = 7;
			sIndex = current;
			rSmallest = 0;
			for(int i=0; i<N; i++) {
				if(tab[i][0] >= tab[rightP][0] && current != i ) {

					double r;
					r = sqrt( pow( (double)tab[current][0] - (double)tab[i][0] ,2) + pow( (double)tab[current][1] - (double)tab[i][1],2 ));
					double angle;
					double x,y;
					x = (double)tab[i][0] - (double)tab[current][0];
					y = (double)tab[i][1] - (double)tab[current][1];

					if(x>0 &&y>=0) {
						angle = atan(y/x);
					} else if(x<0 && y>=0) {
						angle = atan(y/x) + M_PI;
					} else if(x==0 && y>0) {
						angle = M_PI /2;
					} else {
						angle = 100;
					}

					if(angle < smallest) {
						smallest = angle;
						rSmallest = r;
						sIndex = i;
					} else if(angle == smallest) {
						if(r > rSmallest) {
							smallest = angle;
							rSmallest = r;
							sIndex = i;
						}
					} else {
//						do nothing
					}
				}
			}
			current = sIndex;


			cout<<"x"<<current<<" "<<tab[current][0]<<" "<<tab[current][1]<<" "<<endl;
			file<<tab[current][0]<<" "<<tab[current][1]<<"\n";
			if(current == pMax) {
				right = false;
			}
		}
		if(right == false) {
			int sIndex;
			double smallest, rSmallest;
			smallest = 7;
			sIndex = current;
			rSmallest = 0;
			for(int i=0; i<N; i++) {
				if(tab[i][0] <= tab[leftP][0] && current != i ) { //&& tab[i][1] <= tab[current][1]) {
					double r;
					r = sqrt( pow( (double)tab[current][0] - (double)tab[i][0] ,2) + pow( (double)tab[current][1] - (double)tab[i][1],2 ));
					double angle;
					double x,y;
					x = (double)tab[i][0] - (double)tab[current][0];
					y = (double)tab[i][1] - (double)tab[current][1];
					//	cout<<i<<" x"<<x<<" y"<<y<<endl;
					x = x*-1;
					y = y * -1;


					if(x>0 &&y>=0) {
						angle = atan(y/x);
					} else if(x<0 && y>=0) {
						angle = atan(y/x) + M_PI;
					} else if(x==0 && y>0) {
						angle = M_PI /2;
					} else {
						angle = 100;
					}
					//	cout<<i<<" angle "<<angle<<endl;;
					if(angle < smallest) {
						smallest = angle;
						rSmallest = r;
						sIndex = i;
					} else if(angle == smallest) {
						if(r > rSmallest) {
							smallest = angle;
							rSmallest = r;
							sIndex = i;
						}
					} else {
//						do nothing
					}
				}
			}
			current = sIndex;

			cout<<"x"<<current<<" "<<tab[current][0]<<" "<<tab[current][1]<<" "<<endl;
			file<<tab[current][0]<<" "<<tab[current][1]<<"\n";
			if(current == pMin) {
				end = true;
			}
		}
	}
	file.close();






	return 0;
}

