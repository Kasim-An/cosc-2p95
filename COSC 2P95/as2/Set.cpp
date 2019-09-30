#include "Set.h"
#include<iostream>
#include<string>
Set(const bool elements[256], int capacity) {
	for (int i=0; i<capacity; i++) {
		this->elements[i]=elements[i];
	}
	this->capacity=capacity;
};
Set::Set()
{
	this->element=new bool[256]
	for(i=0;i<256;i++)
	{	
		element[i]=0;
	}
	return Set(element[256], 0);
}
Set::Set(short capacity)
{
	this->element[]=new bool[256]
	for(int i=0;i<capacity;i++)
	{
		this->element[i]=0;
	}
	this->capacity=capacity;
	return Set(element[256],capacity);
}
Set Set::operator+(const Set &other)
{
	this->element[]=new bool[256];
	for(int i=0; i<Set.capacity; i++)
	{
		if(Set.element[i]==1)
		{
			this->element[i]=1;
		}
	}
	for(i=0; i<other.capacity; i++)
	{
		if(other.element[i]==1)
		{
			this->element[i]=1;
		}
	}
	if(Set.capacity>other.capacity)
	{
		this->capacity=Set.capacity;
	}
	else
	{
		this->capacity=other.capacity;
	}
	return Set(element[256], this->capacity);
};
Set Set::operator+(const int &other)
{
	this->element[]=new bool[256];
	if(this->capacity<other)
		this->capacity=other;
	this->elements[other]=true;
	return Set(this->element[256],capacity);
};
Set Set::operator-(const Set &other)
{
	this->element=new bool[256];
	for(int i=0; i<Set.capacity; i++)
	{
		if(Set.element[i]==1 && other.element[i]==0)
			this->element[i]=1;
	}
	return Set(element[256], Set.capacity);
};
Set Set::operator-(const int &other)
{
	this->element[]=new bool[256];
	if(other>=this->capacity||this->element[other]==0)
	{
		std::cout<<"this element was not in the union"
	}
	return Set(element[256], this->capacity);
};
Set Set::operator^(const Set &other)
{
	this->element[]=new bool[256];
	for(int i=0; i<Set.capacity; i++)
	{
		if(other.element[i]==1 && Set.element[i]==1)
		{
			this->element[i]=1;
		}
	}
	if(Set.capacity>other.capacity)
		return Set(element[256], other.capacity);
	if(Set.capacity<other.capacity)
		return Set(element[256], Set.capacity);
};
Set Set::operator^(const int &other)
{
	if(this->element[other]==1)
	{
		this->element[]=new bool[256];
		this->element[other]=true;
		return Set(element[256],this->capacity);
	}
	else
	{
		return Set();
	}
};
Set Set::operator~()
{
	for(int i=0; i<this->capacity; i++)
	{
		if(this->element[i]==o)
		{
			this->element[i]=1;
		}
		else
			this->element[i]=0;
	}
	return Set(element[256],this->capacity);
}
Set Set::operator+()
{
	for(int i=0; i<this->capacity; i++)
	{
		this->element[i]=1;
	}
	return Set(element[256],this->capacity);
}
Set Set::operator-()
{
	return Set(this->capacity);
}
bool operator<=(const Set &other)
{
	int count=0;
	for(int i=0; i<Set.capacity; i++)
	{
		if(Set.element[i]==true)
		{
			if(other.element[i]==true)
				count++;
		}
	}
	for(i=0; i<Set.capacity; i++)
	{
		if(Set.element[i]==true)
			count--;
	}
	if(count==0)
	{
		std::cout<<"the former is the subset of the latter"
		return true;
	}
	else
	{
		std::cout<<"the former is not the subset of the latter"
		return false;
	}
};
bool operator<(const Set &other)
{
	int count=0;
	int counts=0
	for(int i=0; i<Set.capacity; i++)
	{
		if(Set.element[i]==true)
		{
			if(other.element[i]==true)
			{
				count++;
				counts=count;
			}
		}
	}
	for(i=0; i<Set.capacity; i++)
	{
		if(Set.element[i]==true)
			count--;
	}
	for(i=0; i<other.capacity; i++)
	{
		if(other.element[i]==true)
			counts--;
	}
	if(count==0 && counts!=0)
	{
		std::cout<<"the former is the strict subset of the latter"
		return true;
	}
	else
	{
		std::cout<<"the former is not the strict subset of the latter"
		return false;
	}
};
bool operator>=(const Set &other)
{
	int count=0;
	for(int i=0; i<other.capacity; i++)
	{
		if(other.element[i]==true)
		{
			if(Set.element[i]==true)
				count++;
		}
	}
	for(i=0; i<other.capacity; i++)
	{
		if(other.element[i]==true)
			count--;
	}
	if(count==0)
	{
		std::cout<<"the former is the superset of the latter"
		return true;
	}
	else
	{
		std::cout<<"the former is not the superset of the latter"
		return false;
	}
};
bool operator>(const Set &other)
{
	int count=0;
	int counts=0;
	for(int i=0; i<other.capacity; i++)
	{
		if(other.element[i]==true)
		{
			if(Set.element[i]==true)
			{
				count++;
				counts=count;
			}
		}
	}
	for(i=0; i<other.capacity; i++)
	{
		if(other.element[i]==true)
			count--;
	}
	for(i=0; i<Set.capacity; i++)
	{
		if(Set.element[i]==true)
			counts--;
	}
	if(count==0 && counts!=0)
	{
		std::cout<<"the former is the strict superset of the latter"<<endl;
		return true;
	}
	else
	{
		std::cout<<"the former is not the strict superset of the latter"<<endl;
		return false;
	}
};
bool operator==(const Set &other)
{
	int count=0;
	short longer;
	if(Set.capacity>=other.capacity)
		longer=Set.capacity;
	else
		longer=other.capacity;
	for(int i=0; i<longer; i++)
	{
		if(Set.element[i]==1)
		{
			if(other.element[i]==1)
			{
				count++;
			}
			else
			{
				std::cout<<"not equal"<<endl;
				return false;
			}
		}
	}
	for(i=0; i<longer; i++)
	{
		if(other.element[i]==1)
			count--;
	}
	if(count==0)
	{
		std::cout<<"they are equal"<<endl;
		return true;
	}
	else
	{
		std::cout<<"not equal"<<endl;
		return false;
	}
};
bool operator!=(const Set &other)
{
	int count=0;
	short longer;
	if(Set.capacity>=other.capacity)
		longer=Set.capacity;
	else
		longer=other.capacity;
	for(int i=0; i<longer; i++)
	{
		if(Set.element[i]==1)
		{
			if(other.element[i]==1)
			{
				count++;
			}
			else
			{
				std::cout<<"not equal"<<endl;
				return true;
			}
		}
	}
	for(i=0; i<longer; i++)
	{
		if(other.element[i]==1)
			count--;
	}
	if(count==0)
	{
		std::cout<<"they are equal"<<endl;
		return false;
	}
	else
	{
		std::cout<<"not equal"<<endl;
		return true;
	}
};
bool operator!()
{
	bool empty=true;
	for(int i=0; i<this->capacity; i++)
	{
		if(this->element[i]==1)
		{
			empty=false;
		}
	}
	if(empty==false)
	{
		std::cout<<"this set is not empty"<<endl;
		return false;
	}
	else
	{
		std::cout<<"this set is empty"<<endl;
		return true;
	}
}
int getCapacity()
{
	return capacity;
}
std::ostream& operator<<(std::ostream &out, const Set &set) 
{
	std::cout<<'{';
	for(int i=0; i < Set.capacity; i++)
	{
		if(Set.element[i]==1)
			std::cout<<i;
	}
	std::cout<<'}';
	std::cout<<""<<endl;
};
std::istream& operator>>(std::istream &in, Set &set) 
{
	bool arr[256];
	int cap=set.capacity;
	char open;
	in>>open;
	if (in.fail() || open!='{') {
		in.setstate(std::ios::failbit);
		return in;
}
	for (int i=0;i<cap;i++)
		arr[i]=false;
	std::string buff;
	std::getline(in,buff,'}');
	std::stringstream ss(buff);
	std::string field;
	while (true) {
		std::getline(ss,field,',');
		if (ss.fail()) break;
		int el;
		std::stringstream se(field);
		se>>el;
		if (el>=0&&el<cap)
			arr[el]=true;
	}
	set=Set(arr,cap);
}