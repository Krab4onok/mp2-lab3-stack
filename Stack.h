#pragma once
namespace ArrStack
{
	using namespace std;
	template<class T>
	class TStack
	{
		T* arr;
		int size;
		int num;
	public:
		TStack(int _size = 10);          //конструктор инициализации и по умолчанию
		~TStack() { delete[] arr; };       //деструктор
		TStack(const TStack<T>& a);      //конструктор копирования 
		TStack& operator=(const TStack& a);
		bool IsEmpty() const;                  //проверка на пустоту
		bool IsFull() const;                  //проверка на полноту
		T Pop();                         //извлечь элемент
		T Top() const;                         //посмотреть на вершину
		void Clear();                    //очистить стек
		void Push(const T& a);           //записать элемент в стек
		int GetSize() { return size; }
		int GetNum() { return num; }
	};


	template <class T>
	TStack<T>::TStack(int _size)
	{
		if (_size <= 0) throw 1;
		size = _size;
		arr = new T[size];
		num = -1;
	}
	template <class T>
	TStack<T>::TStack(const TStack& a)
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
	TStack<T>& TStack<T>::operator=(const TStack<T>& a)
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
	template <class T>
	bool TStack<T>::IsEmpty() const
	{
		return num == -1;
	}
	template <class T>
	bool TStack<T>::IsFull() const
	{
		return num == size - 1;
	}
	template <class T>
	T TStack<T> ::Pop()
	{
		if (IsEmpty()) throw - 2;
		return arr[num--];
	}
	template <class T>
	T TStack<T> ::Top() const
	{
		if (IsEmpty()) throw - 2;
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
};


namespace ListStack 
{

	using namespace std;
	template <class T>
	struct TNode
	{
		T val;
		TNode <T>* pNext;
	};
	template<class T>
	class TStack
	{
		TNode<T>* pFirst;
	public:
		TStack() { pFirst = NULL; }
		TStack(const TStack<T>& a);
		TStack& operator=(const TStack& a);
		void Clear();
		bool IsEmpty() { return pFirst == NULL; }
		void Push(T a);
		T Top();
		T Pop();
		~TStack();
		bool IsFull();
		int GetNum();
	};
	template<class T>
	TStack<T>::TStack(const TStack<T>& a)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp = a.pFirst;
		while (tmp != 0)
		{
			pFirst = tmp;
			tmp = tmp->pNext;
		}

	}
	template<class T>
	TStack<T>& TStack<T>:: operator=(const TStack& a)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp = a.pFirst;
		while (tmp != 0)
		{
			pFirst = tmp;
			tmp = tmp->pNext;
		}
		return *this;
	}
	template<class T>
	void TStack<T>::Clear()
	{
		TNode <T>* tmp = pFirst;
		while (pFirst != NULL)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	template<class T>
	void TStack<T>::Push(T a)
	{
		TNode <T>* TMP;
		TMP = new TNode<T>;
		TMP->pNext = pFirst;
		TMP->val = a;
		pFirst = TMP;
	}
	template<class T>
	T TStack<T>::Top()
	{
		if (IsEmpty())throw - 1;
		return pFirst->val;
	}
	template<class T>
	T TStack<T>::Pop()
	{
		if (IsEmpty())throw - 1;
		T res = pFirst->val;
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return res;
	}
	template<class T>
	TStack<T>::~TStack()
	{
		TNode <T>* tmp = pFirst;
		while (pFirst != NULL)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	template<class T>
	bool TStack<T>:: IsFull()
	{
		TNode<T>* p = new TNode<T>;
		if(p)
		{
			delete p;
			return true;
		}
		else
		{
			return false;
		}
	}
	template<class T>
	int TStack<T>::GetNum()
	{
		TNode<T>* p = pFirst;
		int i = 0;
		while (p != NULL)
		{
			i++;
			p = (*p).pNext;
		}
		return i;
	}

};