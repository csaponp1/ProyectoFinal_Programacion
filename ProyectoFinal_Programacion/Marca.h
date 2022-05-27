#pragma once
#include<iostream>
using namespace std;

class Marca{
private: int idmarca=0;
public: string marca;

public: 
	Marca() {
	}
	Marca(int idma, string mar) {
			 idmarca = idma;
			 marca = mar;
	}
};

