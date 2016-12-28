/*
* Ordens.cpp
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#include "Utils.h"

void clearScreen() {

	COORD upperLeftCorner = { 0, 0 };
	DWORD charsWritten;
	DWORD conSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO  csbi;

	GetConsoleScreenBufferInfo(hCon, &csbi);
	conSize = csbi.dwSize.X * csbi.dwSize.Y;

	// fill with spaces
	FillConsoleOutputCharacter(hCon, TEXT(' '), conSize, upperLeftCorner, &charsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, conSize, upperLeftCorner, &charsWritten);

	// cursor to upper left corner
	SetConsoleCursorPosition(hCon, upperLeftCorner);
}

void linha(int n)
{
	cout << TAB;
	for (int i = 1; i < n; i++)
		cout << "--";

	cout << "\n";
}


long le_num()
{
	string input;
	long num;

	getline(cin, input);
	stringstream ss(input);
	
	while (!(ss >> num  && ss.eof())) {
		cout << TAB << "Input invalido" << endl;
		cout << TAB << "Introduza um numero valido: ";
		getline(cin, input);
		ss.str("");	ss.clear(); //apagar conteudo da stringsstream
		ss << input;
	}
	return num;
}

float le_float()
{
	string input;
	float num;

	getline(cin, input);
	stringstream ss(input);

	while (!(ss >> num  && ss.eof())) {
		cout << TAB << "Input invalido" << endl;
		cout << TAB << "Introduza um numero valido: ";
		getline(cin, input);
		ss.str("");	ss.clear(); //apagar conteudo da stringsstream
		ss << input;
	}
	return num;
}

int leInteiro(int min, int max){
	int num = le_num();

	while (num < min || num > max)
	{
		cout << endl;
		cout << TAB << "Input Invalido. Introduza um numero entre " << min << " e " << max << " : ";
		num = le_num();
	}
	return num;

}

long leNif() {
	string input;
	long num;

	getline(cin, input);
	stringstream ss(input);

	if (!(ss >> num  && ss.eof())) {
		cout << endl;
		cout << TAB << "Input invalido" << endl;
		return -1;
	}

	if (num >= 0 && num <= 999999999)
		return num;
	return -1;
}


string leTitulo() {
	string input;
	string titulo;

	getline(cin, input);
	stringstream ss(input);

	if (!(ss >> titulo  && ss.eof())) {
		cout << endl;
		cout << TAB << "Input invalido" << endl;
		return "";
	}

	return titulo;
}

void espera_input()
{
	cout << endl;
	cout << TAB << "Pressione Enter para continuar...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

Data getData() {
	time_t t = time(0); 
	struct tm now;
	Data actual;
	localtime_s(&now, &t);
	actual = Data(now.tm_mday, (now.tm_mon + 1), (now.tm_year + 1900));

	return actual;
}




void DatePlusDays(struct tm* date, int days)
{
	const time_t ONE_DAY = 24 * 60 * 60;

	// Seconds since start of epoch
	time_t date_seconds = mktime(date) + (days * ONE_DAY);

	// Update caller's date
	// Use localtime because mktime converts to UTC so may change date
	//*date = *localtime_s(&date_seconds);;
	localtime_s(date, &date_seconds);
}




void dataMaisDias(Data& data ,int dias){

	struct tm date = { 0, 0, 12 };

	date.tm_year = data.getAno() - 1900;
	date.tm_mon = data.getMes() - 1;  // note: zero indexed
	date.tm_mday = data.getDia();       // note: not zero indexed

	DatePlusDays(&date, dias);

	data.setAno(date.tm_year+1900);
	data.setMes(date.tm_mon+1);
	data.setDia(date.tm_mday);


}





















bool fich_vazio(fstream& pFile)
{
	return pFile.peek() == fstream::traits_type::eof();
}

void acabalog(string &str)
{
	string sufixo = ".log";
	if (str.size() < sufixo.size())
		str = str + sufixo;

	if (str.compare(str.size() - sufixo.size(), sufixo.size(), sufixo) != 0)
		str = str + sufixo;
}

