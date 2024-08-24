
#include <iostream>
using namespace std;
struct Vector
{
	int* m_pVect, // Pointer to the buffer
		m_nCount, // Control how many elements are actually used
		m_nMax, // Control how many are allocated as maximum
		m_nDelta; // To control the growing
	Vector(int delta = 10);
};
Vector::Vector(int delta) : m_nCount(0), m_nMax(delta), m_nDelta(delta) {
	m_pVect = new int[m_nMax];
}
void Resize(Vector* pThis)
{
	int* pTemp, i;
	pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; // Alloc a new vector
	for (i = 0; i < pThis->m_nMax; i++) // Transfer the elements
		pTemp[i] = pThis->m_pVect[i]; // we can also use the function memcpy
	delete[]  pThis->m_pVect; // delete the old vector
	pThis->m_pVect = pTemp; // Update the pointer
	pThis->m_nMax += pThis->m_nDelta;
}
void Insert(Vector* pThis, int elem)
{
	if (pThis->m_nCount == pThis->m_nMax) // Verify the overflow
		Resize(pThis); // Resize the vector before inserting elem
	// Insert the element at the end of the sequence
	pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main() {
	Vector p;
	Insert(&p, 30);
}
