#pragma once
using namespace std;
template<class T>
class TStack
{
	T *arr;
	int size;
	int num;
public:
	TStack(int _size = 10);          //конструктор инициализации и по умолчанию
	~TStack() {delete [] arr};       //деструктор
	TStack(const TStack<T> &a);      //конструктор копирования 
	TStack& operator=(const TStack &a);
	bool IsEmpty() const;                  //проверка на пустоту
	bool IsFull() const;                  //проверка на полноту
	T Pop();                         //извлечь элемент
	T Top() const;                         //посмотреть на вершину
	void Clear();                    //очистить стек
	void Push(const T& a);           //записать элемент в стек
};


template <class T>
TStack<T>::TStack(int _size)
{
	size = _size;
	arr = new T[size];
	num = -1;
}
template <class T>
TStack<T>::TStack(const TStack &a)
{
	size = a.size;
	num = a.num;
	arr = new T[size];
	for (int i = 0; i < num; i++)
	{
		arr[i] = a.arr[i];
	}
}
template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T> &a)
{
	if ( *this != a)
	{
		size = a.size;
		num = a.num;
		arr = new T[size];
		for (int i = 0; i < num; i++)
		{
			arr[i] = a.arr[i];
		}
		return *this;
	}
	return *this;
}
template <class T>
bool TStack<T>::IsEmpty() const
{
	return num == -1;
}
template <class T>
bool TStack<T>:: IsFull() const
{
	return num == size - 1;
}
template <class T>
T TStack<T> ::Pop()
{
	if (IsEmpty) throw - 2;
	return arr[num--];
}
template <class T>
T TStack<T> ::Top() const
{
	if (IsEmpty) throw - 2;
	return arr[num];
}
template <class T>
void TStack<T> ::Push(const T& a)
{
	if (IsFull()) throw - 1;
	arr[++num] = a;
}
template <class T>
void TStack<T> ::Clear()
{
	num = -1;
	delete[] arr;
	arr = new T[size];
}