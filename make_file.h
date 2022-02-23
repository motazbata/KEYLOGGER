#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void MAKE_FILE(string x ){ // how to make file 

	fstream file_1 ; 
	file_1.open("C:\\Users\\user\\Desktop\\dat.txt" , ios::app) ; 
	if (file_1.is_open()){
		file_1<< x << " " ; 
		file_1.close() ; 
	}
}
