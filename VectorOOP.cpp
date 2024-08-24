#include <iostream>
using namespace std;

class CVector
{
private:
	int* m_pVect, // Pointer to the buffer
		m_nCount, // Control how many elements are actually used
		m_nMax, // Control how many are allocated as maximum
		m_nDelta; // To control the growing
	void Init(int delta); // Init our private variables, etc
	void Resize(); // Resize the vector when occurs an overflow
public:
	CVector(int delta = 10); // Constructor
	void Insert(int elem); // Insert a new element
	// More methods go here
};
CVector::CVector(int delta) : m_nCount(0), m_nDelta(delta), m_nMax(delta) {
	m_pVect = new int[m_nMax];
}
void CVector::Insert(int elem)
{
	if (m_nCount == m_nMax) // Verify the overflow
		Resize(); // Resize the vector before inserting elem
	m_pVect[m_nCount++] = elem; // Insert the element at the end
}
void CVector::Resize() {
	int* pTemp, i;
	pTemp = new int[m_nMax + m_nDelta]; // Alloc a new vector
	for(i = 0 ; i < m_nMax ; i++) // Transfer the elements
		pTemp[i] = m_pVect[i]; // we can also use the function memcpy
	delete [ ] m_pVect; // delete the old vector
	m_pVect = pTemp; // Update the pointer
	m_nMax += m_nDelta;
}

int main() {
	CVector vec(3);
}
