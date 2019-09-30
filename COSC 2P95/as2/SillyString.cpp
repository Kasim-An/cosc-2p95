#include "SillyString.h"
#include<iostream>
#include<string.h>
SillyString(const char *data=""){
	return NULL;
};//Default constructor: takes C-style string until terminator ('\0'); defaults to empty string
SillyString(const char *data, int length){
	string str(data);
	this->_length=length;
	return str(data);
};//Lets you take only a portion of a C-style string
SillyString(const SillyString &original){
	_length = strlen( original ) + 1;  
	data = new char[ length ];  
	if( data )  
		return strcpy_s( data, length, original );  
};//Copy constructor
		
~SillyString(){
	if (data)  
		delete[] data; 
};//Destructor
		
SillyString operator+(const SillyString &other) const{
	this->_length=SillyString._length+other._length;
	this->data=SillyString.data+other.string;
	return SillyString(this->data, this->_length);
	
};//Concatenate
		
SillyString operator+() const{
	data=new char[SillyString._length];
	for(i=0;data[i]!=0;i++)
	if(data[i]<=122 && data[i]>=97)
		{data[i]-=32;}
	string result(data);
	return result;
}; //Returns new ALL-UPPERCASE version
SillyString operator-() const{
	data=new char[SillyString._length];
	for(i=0;data[i]!=0;i++)
	if(data[i]<=90 && data[i]>=65)
		{data[i]+=32;}
	string result(data);
	return result;
}; //Returns new all-lowercase version
		
SillyString operator~() const{
	this->_length=SillyString._length;
	char arr[];
	arr[]=SillyString.data;
    int i=0,j=SillyString._length-1;
    while(i<=j)
    {
        char temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
	this->data=arr;
	return SillyString(this->data,this->_length);
}; //noisrev sdrawkcab a snruteR
		
bool operator<=(const SillyString &other) const{
	bool result=false;
	int width=max(SillyString._length,other._length);
	for(int i=0;i<width;i++){
		result=false;
		if(SillyString.data.compare(i+1,0,other.data,i+1,0)<=0)
		{result=true;}
	}
	return result;
}; //Does this have earlier or equal lexicographic priority to other?
bool operator<(const SillyString &other) const{
	bool result=false;
	int width=max(SillyString._length,other._length);
	for(int i=0;i<width;i++){
		result=false;
		if(SillyString.data.compare(i+1,0,other.data,i+1,0)<0)
		{result=true;}
	}
	return result;	
}; //Does this has earlier lexicographic priority to other?
bool operator>=(const SillyString &other) const{
	bool result=false;
	int width=max(SillyString._length,other._length);
	for(int i=0;i<width;i++){
		result=false;
		if(SillyString.data.compare(i+1,0,other.data,i+1,0)>=0)
		{result=true;}
	}
	return result;
}; //Does this is the same string, or comes after other?
bool operator>(const SillyString &other) const{
	bool result=false;
	int width=max(SillyString._length,other._length);
	for(int i=0;i<width;i++){
		result=false;
		if(SillyString.data.compare(i+1,0,other.data,i+1,0)>0)
		{result=true;}
	}
	return result;	
}; //Does this comes after other?
bool operator==(const SillyString &other) const{
	bool result=false;
	int width=max(SillyString._length,other._length);
	for(int i=0;i<width;i++){
		result=false;
		if(SillyString.data.compare(i+1,0,other.data,i+1,0)==0)
		{result=true;}
	}
	return result;
}; //Test for string equality
bool operator!=(const SillyString &other) const; //Test for string inequality
bool operator!() const{
	if(this->_length==0)
		return false;
}; //Test for empty SillyString
		
SillyString operator()(const int from, const int to) const{
	char arr[];
	arr[]=SillyString.data;
	char help[];
	for(int i=from;i<to;i++){
		int count=0;
		help[0]=arr[i];
	}
	string result(data);
	return result;
}; //Returns a slice, from 'from' (inclusive) to 'to' (exclusive)
char operator[](const int &pos) const{
	char arr[];
	arr[]=SillyString.data;
    return arr[pos-1];
}; //Returns character at that position (zero-based); '\0' if outside of bounds
		
int indexOf(char c) const{
	char arr[];
	arr[]=SillyString.data;
	int find;
	for(int i=0;i<arr[].length();i++){
		if(arr[i]==c)
			find=i;
		else
			find=-1;
	}
	return find;
}; //Returns position of first occurrence of c, or -1 if not found
int indexOf(char c, int pos) const{
	char arr[];
	arr[]=SillyString.data;
	int find;
	for(int i=pos;i<arr[].length();i++){
		if(arr[i]==c)
			find=i;
		else
			find=-1;
	}
	return find;	
}; //Same as above, but starting from position pos (zero-based indexing)
int length() const{
	return _length;
}; //Returns the length of the string (the actual number of characters)
		
		//Assignment breaks strict immutability, but is *so* much easier that we may wish to cheat and provide it:
SillyString& operator=(const SillyString &original){
	if (this==&original) //First, check for 'self-assignment'
		return *this;
	
	if (this->_length>0)
		delete[] this->data;
	this->_length=original._length;
	this->data=new char[this->_length];
	for (int i=0;i<this->_length;i++)
		this->data[i]=original.data[i];
	
	return *this; 
	//Assignments typically return a reference to the object, for the sake of cascading/chaining	
	};
	friend std::ostream& operator<<(std::ostream &out, const SillyString &ss);//Stream insertion
	//Note: though a peculiarity, since this string class relies (initially) on C-strings, it's expected that you'll rely on them for any stream extraction
	};
}