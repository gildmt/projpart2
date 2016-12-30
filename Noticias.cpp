/*
* Noticias.cpp
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#include "Noticias.h"

using namespace std;

Noticia::Noticia(int d, int m, int a, string pN, string ttl, int r)
{
	Data newDate(d, m, a);
	date = newDate;
	paperName = pN;
	title = ttl;
	if (r > 10)
		rating = 10;
	else if (r < 0)
		rating = 0;
	else
		rating = r;
}

string Noticia::getTitle()
{
	return title;
}

Data Noticia::getDate()
{
	return date;
}

void Noticia::setRating(int r)
{
	rating = r;
}

ostream& operator<< (ostream& out, const Noticia & noticia) {
	out << TAB << BARRA << " " << setfill(' ') << left
		<< " " << setw(13) << noticia.paperName << " " << BARRA
		<< " " << setw(15) << noticia.title << " " << BARRA
		<< " " << setw(12) << noticia.date << " " << BARRA
		<< " " << right << setw(14) << noticia.rating << " " << BARRA << endl;

	return out;
}

bool Noticia::operator==(const Noticia & nt1) const
{
	if (title == nt1.title && paperName == nt1.paperName &&
		date.getAno() == nt1.date.getAno() && date.getMes() == nt1.date.getMes() &&
		date.getDia() == nt1.date.getDia())
		return true;
	else
		return false;
}

bool Noticia::operator<(const Noticia & nt1) const
{
	if (title < nt1.title)
		return true;
	else if (title == nt1.title)
	{
		if (date.getAno() < nt1.date.getAno())
			return true;
		else if (date.getAno() == nt1.date.getAno())
		{
			if (date.getMes() < nt1.date.getMes())
				return true;
			else if (date.getMes() == nt1.date.getMes())
			{
				if (date.getDia() < nt1.date.getDia())
					return true;
				else if (date.getDia() == nt1.date.getDia())
				{
					if (paperName < nt1.paperName)
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}