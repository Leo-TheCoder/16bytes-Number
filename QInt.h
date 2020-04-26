#pragma once
#include <iostream>
#include <string>

using namespace std;

class QInt
{
private:
	char val[16] = { 0 };
public:
	bool GetBit(int i);
	void SetBit(int i);	//Ham chi bat bit tu 0 -> 1, muon set bit 0 thi no phai la 0 truoc do

	void Input(string);
	void Output();

	bool* DecToInt();
	void BinToDec(bool* bit);
	QInt();
};

bool GetBitAll(char data, int i, int size);		
void SetBitAll(char& data, int i, int size);	
string DivideByTwo(string number);
string DecToBin(string number);
string MultiplyWithTwo(string number);
void PowOfTwo(string pow[128]);
string PlusNumber(string n1, string n2);
