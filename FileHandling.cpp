﻿#include "FileHandling.h"
#include <fstream>
#include <sstream>
#include <vector>

//Chuyển hướng cout qua file
streambuf* CoutRedirect(ofstream& output)
{
	streambuf* coutbuf = std::cout.rdbuf(); //lưu buffer hiện tại
	cout.rdbuf(output.rdbuf()); //chuyển hướng cout qua out (filename)
	return coutbuf;
}

//Chuyển hướng cout về bình thường
void NormalizeCout(streambuf* coutbuf)
{
	cout.rdbuf(coutbuf);
}

//Hàm chuyển string về int
int StringToInt(string str)
{
	int result = 0;
	int exp = 1;
	for (int i = str.length() - 1;i >= 0;i--)
	{
		result += int(str[i] - '0')*exp;
		exp *= 10;
	}
	return result;
}

//Hàm chuyển đổi string về dãy bool* bin 128 bit
bool* StringToBin(string str)
{
	bool* bin = new bool[BIT_RANGE];
	int j = BIT_RANGE - 1;
	for (int i = 0;i < BIT_RANGE;i++)
		bin[i] = 0;
	for (int i = str.length() - 1;i >= 0;i--)
	{
		if (str[i] == '1')
			bin[j] = 1;
		else
			bin[j] = 0;
		j--;
	}
	return bin;
}

//Hàm để chuyển string về char* size 32 (32 + '\0')
char* StringToChar(string str)
{
	char* newstr = new char[HEX_SIZE + 1];
	
	int i;
	//Thêm 0 vào đầu
	for (i = 0;i < HEX_SIZE - str.length();i++)
		newstr[i] = '0';
	int j = 0;
	//Thêm dãy hex
	for (;i < HEX_SIZE;i++)
	{
		newstr[i] = str[j];
		j++;
	}
	newstr[HEX_SIZE] = '\0';
	return newstr;
}


//Gọi hàm chuyển đổi
//Input: Base ban đầu, string chứa số cần chuyển đổi
//Output: QInt kết quả
QInt StringToQInt(string base, string input)
{
	QInt number;
	//chuyển đổi input về QInt number
	if (base.compare("2") == 0) //hệ nhị phân
	{
		bool* binnum = StringToBin(input); //dãy nhị phân 128 bit
		number = BinToDec(binnum);
		delete[] binnum;
	}
	else if (base.compare("10") == 0) //hệ thập phân
	{
		number.Input(input);
	}
	else if (base.compare("16") == 0) //hệ thập lục phân
	{
		char* hexnum = StringToChar(input); //dãy thập lục phân theo string input
		number = HexToDec(hexnum);
		delete[] hexnum;
	}
	return number;
}

//Chuyển QInt theo base và xuất ra file
void ConvertAndPrint(QInt number, string base, string filename)
{
	ofstream output(filename, ios::app); //mở file để ghi
	streambuf* coutbuf = CoutRedirect(output); //lưu buffer của cout

	if (base.compare("2") == 0)
	{
		bool* bin = DecToBin(number);
		OutputBin(bin); //xuất số dạng binary ra file
		delete[] bin;
	}
	else if (base.compare("10") == 0)
	{
		number.Output(); //xuất số dạng decimal ra file
	}
	else if (base.compare("16") == 0)
	{
		char* hex = DecToHex(number);
		OutputHex(hex); //xuất số dạng hex ra file
		delete[] hex;
	}
	cout << endl;
	NormalizeCout(coutbuf); //chuyển về cout bình thường
	if (output.is_open())
		output.close();
}

//Làm các phép so sánh 
bool ComparisonOperations(QInt A, QInt B, string op)
{
	if (op.compare(">") == 0)
	{
		return A > B;
	}
	else if (op.compare("<") == 0)
	{
		return A < B;
	}
	else if (op.compare(">=") == 0)
	{
		return A >= B;
	}
	else if (op.compare("<=") == 0)
	{
		return A <= B;
	}
	else if (op.compare("==") == 0)
	{
		return A == B;
	}
}

//Làm các phép toán + - * / ^ | & trên QInt và xuất ra file
void ArithmeticOperations(QInt A, QInt B, string base, string op, string filename)
{
	if (op.compare("+") == 0)
	{
		ConvertAndPrint(A + B, base, filename);
	}
	else if (op.compare("-") == 0)
	{
		ConvertAndPrint(A - B, base, filename);
	}
	else if (op.compare("*") == 0)
	{
		ConvertAndPrint(A * B, base, filename);
	}
	else if (op.compare("/") == 0)
	{
		ConvertAndPrint(A / B, base, filename);
	}
	else if (op.compare("|") == 0)
	{
		ConvertAndPrint(A | B, base, filename);
	}
	else if (op.compare("&") == 0)
	{
		ConvertAndPrint(A & B, base, filename);
	}
	else if (op.compare("^") == 0)
	{
		ConvertAndPrint(A ^ B, base, filename);
	}
	else
	{
		ofstream output(filename, ios::app); //mở file để ghi
		streambuf* coutbuf = CoutRedirect(output); //lưu buffer của cout
		cout << ComparisonOperations(A, B, op) << endl;
		NormalizeCout(coutbuf); //chuyển về cout bình thường
		if (output.is_open())
			output.close();
	}
}

//Làm các phép << >> 
void ShiftOperation(QInt A, int num, string op, string base, string filename)
{
	if (op.compare("<<") == 0)
	{
		ConvertAndPrint(A << num, base, filename);
	}
	else if (op.compare(">>") == 0)
	{
		ConvertAndPrint(A >> num, base, filename);
	}
}

//Làm các phép ror rol 
void RotateOperation(QInt A, int num, string op, string base, string filename)
{
	if (op.compare("rol") == 0)
	{
		ConvertAndPrint(A.RotateLeft(num), base, filename);
	}
	else if (op.compare("ror") == 0)
	{
		ConvertAndPrint(A.RotateRight(num), base, filename);
	}
}

//Hàm xử lý từng dòng input
void ProcessLine(string line, string output)
{
	vector<string> tokenArr; //mảng chứa các giá trị được tách
	string token;
	stringstream stream(line);
	while (getline(stream, token, ' '))
	{
		tokenArr.push_back(token);
	}
	int length = tokenArr.size();
	if (length == 3)
	{
		QInt number = StringToQInt(tokenArr[0], tokenArr[2]);
		if (tokenArr[1].compare("~") != 0)
		{
			ConvertAndPrint(number, tokenArr[1], output);
		}
		else //nếu là dấu ~
		{
			ConvertAndPrint(~number, tokenArr[0], output);
		}

	}
	if (length == 4)
	{
		string base = tokenArr[0]; //base xử lý
		string op = tokenArr[2]; //toán tử
		QInt firstNum = StringToQInt(base, tokenArr[1]);
		//firstNum.Output();
		if (op.compare("<<") == 0 || op.compare(">>") == 0)
			ShiftOperation(firstNum, StringToInt(tokenArr[3]), op, base, output);
		else if (op.compare("ror") == 0 || op.compare("rol") == 0)
			RotateOperation(firstNum, StringToInt(tokenArr[3]), op, base, output);
		else
		{
			QInt secondNum = StringToQInt(base, tokenArr[3]);
			//secondNum.Output();
			ArithmeticOperations(firstNum, secondNum, base, op, output);
		}
	}

}


//Hàm đọc và xử lý file input, xuất ra file output
void ReadFile(string input, string output)
{
	ofstream out(output, ios::trunc); //xóa file để rewrite
	if (out.is_open())
		out.close();
	ifstream file(input);
	string line; //biến lưu từng dòng
	if (file.is_open())
	{
		while (getline(file, line)) //lưu từng dòng trong file vào line
		{
			ProcessLine(line, output);
		}
		file.close();
	}
}
