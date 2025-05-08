#pragma once

#include <string>

#include "Screen_Object.h"

class Building : public Screen_Object
{

protected:

	int Lvl;

	int All_Storage;
	int Materials_Storage;
	int Sorted_Materials_Storage;
	int Ready_Products_Storage;
	int Packed_Products_Storage;

	int Materials_Storage_Used;
	int Sorted_Materials_Storage_Used;
	int Ready_Products_Storage_Used;
	int Packed_Products_Storage_Used;

	bool Is_Ready;



public:

	Building();
	virtual ~Building();

	virtual int Get_Lvl();

	virtual int Get_All_Storage();
	virtual int Get_Materials_Storage();
	virtual int Get_Sorted_Materials_Storage();
	virtual int Get_Ready_Products_Storage();
	virtual int Get_Packed_Products_Storage();
	virtual int Get_Materials_Storage_Used();
	virtual int Get_Sorted_Materials_Storage_Used();
	virtual int Get_Ready_Products_Storage_Used();
	virtual int Get_Packed_Products_Storage_Used();
	bool Get_Is_Ready();

	virtual void Set_Lvl(int);

	virtual void Set_All_Storage(int);
	virtual void Set_Materials_Storage(int);
	virtual void Set_Sorted_Materials_Storage(int);
	virtual void Set_Ready_Products_Storage(int);
	virtual void Set_Packed_Products_Storage(int);
	virtual void Set_Materials_Storage_Used(int);
	virtual void Set_Sorted_Materials_Storage_Used(int);
	virtual void Set_Ready_Products_Storage_Used(int);
	virtual void Set_Packed_Products_Storage_Used(int);
	void Set_Is_Ready(bool);

	virtual void Lvl_Up() = 0;
	virtual void Calculate_Storage() = 0;
	virtual std::string Stats_String(int) = 0;
	virtual int Get_Cost() = 0;
	virtual void Check_If_Ready() = 0;
};
