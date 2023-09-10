#include <list>
#include <iostream>
#include <complex>
using namespace std;

template <class T>
void push(list<complex<T>> &lst, complex<T> element){
	//норамально добавляет в начало, конец и рандомное место
	typename list<complex<T>>::iterator p = lst.begin();
	while (p != lst.end())
	{
		if (p->real() > element.real())
			break;
		p++;
	}lst.insert(p, element);
}

template <class T>
void pop(list<complex<T>>& lst, int id) {
	// если список уже отсоритрован, то pop не нарушит порядок
	typename list<complex<T>>::iterator p = lst.begin();
	for (int i = 0; i < id; i++) // p+int работает только где есть random access (vector[]) 
		p++;
	lst.erase(p);
}

template <class T>
void print(list<complex<T>>& lst) {
	typename list<complex<T>>::iterator p = lst.begin();
	while (p != lst.end())
	{
		cout << *p << "";
		p++;
	}
	cout << endl;
}

template <class T>
list<complex<T>> filtereven(list<complex<T>>& lst) {
	list<complex<T>> retlist;
	typename list<complex<T>>::iterator p = lst.begin();
	while (p != lst.end())
	{
		if (fmod(p->real(), 2.0) == 0 && fmod(p->imag(),2.0) == 0)
			push<T>(retlist, *p);
		p++;
	}
	return retlist;
}

template <class T>
list<complex<T>> filterodd(list<complex<T>>& lst) {
	list<complex<T>> retlist;
	typename list<complex<T>>::iterator p = lst.begin();
	while (p != lst.end())
	{
		if (fmod(p->real(), 2.0) != 0 && fmod(p->imag(), 2.0) != 0)
			push<T>(retlist, *p);
		p++;
	}
	return retlist;
}

int main()
{
	list<complex<float>> lst;
	for (int i = 0; i < 10; i += 1)
		lst.push_back(complex<float>(1+i,0.5+i/2));
	print(lst);

	push<float>(lst, complex<float>(4,0.7)); //autodetect types?
	print(lst);
	
	pop<float>(lst, 0);
	print(lst);

	push<float>(lst, complex<float>(2, 2)); //четный
	print(lst);
	list<complex<float>> filtered = filtereven(lst);
	print(filtered);
	filtered = filterodd(lst);
	print(filtered);

	return 0;
}