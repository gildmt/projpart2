/**
* insertionSort.h
*
*  Created on: 17/10/2016
*      Author: Gil Teixeira & Paulo Correia
*/

#include <vector>

using namespace std;

/**
 * @fn	template <class Comparable> void insertionSort(vector<Comparable> &v)
 *
 * @brief	Ordenacao de um vetor pelo método insertion Sort.
 *
 * @param 	v	Vetor a ordenar.
 */

template <class Comparable> 
void insertionSort(vector<Comparable> &v)
{
    for (unsigned int p = 1; p < v.size(); p++)
    {
    	Comparable tmp = v[p];
    	int j;
    	for (j = p; j > 0 && tmp < v[j-1]; j--)
    		v[j] = v[j-1];
    	v[j] = tmp;
    } 
}
