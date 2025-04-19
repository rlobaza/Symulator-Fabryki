#pragma once

#include <memory>



template <typename T>
class List_Element
{

private:

	T Data;
	std::unique_ptr<List_Element<T>> Next;
	List_Element<T>* Prev;

public:

	List_Element(T);
	~List_Element();

	void Set_Data(T);
	void Set_Next(std::unique_ptr<List_Element<T>>);
	void Set_Prev(List_Element<T>*);

	T Get_Data();
	std::unique_ptr<List_Element<T>> Get_Next_Smrt();
	List_Element<T>* Get_Next();
	List_Element<T>* Get_Prev();
};

template <typename T>
List_Element<T>::List_Element(T Dat) : Data(Dat), Next(nullptr), Prev(nullptr)
{

}

template <typename T>
List_Element<T>::~List_Element()
{

}

template <typename T>
void List_Element<T>::Set_Data(T param)
{
	Data = param;
}

template <typename T>
void List_Element<T>::Set_Next(std::unique_ptr<List_Element<T>> smrt_ptr)
{
	Next = std::move(smrt_ptr);
}

template <typename T>
void List_Element<T>::Set_Prev(List_Element<T>* ptr)
{
	Prev = ptr;
}

template <typename T>
T List_Element<T>::Get_Data()
{
	return Data;
}

template <typename T>
std::unique_ptr<List_Element<T>> List_Element<T>::Get_Next_Smrt()
{
	return std::move(Next);
}

template <typename T>
List_Element<T>* List_Element<T>::Get_Next()
{
	return Next.get();
}

template <typename T>
List_Element<T>* List_Element<T>::Get_Prev()
{
	return Prev;
}