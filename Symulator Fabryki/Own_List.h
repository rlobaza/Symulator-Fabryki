#pragma once


#include <memory>
#include <iostream>
#include <mutex>

#include "List_Element.h"


template <typename T>
class Own_List
{

private:

	int Size;
	std::unique_ptr<List_Element<T>> Head;
	List_Element<T>* Tail;

	void Set_Size(int);
	void Set_Head(std::unique_ptr<List_Element<T>>);
	void Set_Tail(List_Element<T>*);

	List_Element<T>* Get_Head();
	List_Element<T>* Get_Tail();

public:

	Own_List();
	~Own_List();

	int Get_Size();
	void Push_Back(T);
	T operator[](int);
	void Erase(int);


};

template <typename T>
void Own_List<T>::Set_Size(int param)
{
	Size = param;
}

template <typename T>
void Own_List<T>::Set_Head(std::unique_ptr<List_Element<T>> smrt_ptr)
{
	Head = std::move(smrt_ptr);
}

template <typename T>
void Own_List<T>::Set_Tail(List_Element<T>* ptr)
{
	Tail = ptr;
}

template <typename T>
List_Element<T>* Own_List<T>::Get_Head()
{
	return Head.get();
}

template <typename T>
List_Element<T>* Own_List<T>::Get_Tail()
{
	return Tail;
}

template <typename T>
Own_List<T>::Own_List() : Size(0), Head(nullptr), Tail(nullptr)
{

}

template <typename T>
Own_List<T>::~Own_List()
{

}

template <typename T>
int Own_List<T>::Get_Size()
{
	return Size;
}

template <typename T>
void Own_List<T>::Push_Back(T param)
{

	std::unique_ptr<List_Element<T>> smrt_ptr = std::make_unique<List_Element<T>>(param);

	if (Head == nullptr)
	{
		//std::cout << "dodano element na: " << smrt_ptr.get() << " " << param << std::endl;
		Head = std::move(smrt_ptr);
		Tail = Head.get();
		Size++;
		return;
	}



	List_Element<T>* current = Head.get();

	while (current->Get_Next() != nullptr)
	{
		current = current->Get_Next();
	}

	//std::cout << "dodano element na: " << smrt_ptr.get() << " " << param << std::endl;

	current->Set_Next(std::move(smrt_ptr));

	current->Get_Next()->Set_Prev(current);

	Tail = current->Get_Next();


	Size++;
}

template <typename T>
T Own_List<T>::operator[](int index)
{

	List_Element<T>* current = Head.get();

	for (int i = 0; i < index; i++)
	{
		current = current->Get_Next();
	}

	return current->Get_Data();


}

template <typename T>
void Own_List<T>::Erase(int index)
{

	if (index == 0)
	{
		Set_Head(Get_Head()->Get_Next_Smrt());
		Size--;
		return;
	}


	List_Element<T>* current = Head.get();



	for (int i = 0; i < index - 1; i++)
	{
		current = current->Get_Next();
	}



	current->Set_Next(current->Get_Next()->Get_Next_Smrt());

	if (index != Get_Size() - 1)
	{
		current->Get_Next()->Set_Prev(current);
	}

	Size--;


}