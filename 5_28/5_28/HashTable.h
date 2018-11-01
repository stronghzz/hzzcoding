#pragma once
typedef int DataType;
#define MAX_SIZE 10;
typedef enum{EMPTY,EXIST,DELETE}State;
typedef struct ELem{
	DataType _data;
	State _state;
}Elem;
struct HashTable
{
	Elem _table[MAX_SIZE];
	int _size;
}HashTable;
