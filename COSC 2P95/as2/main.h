#include <iostream>
#include<list>
#include<array>
#include<string>
#include<iterator>
using namespace std;
template<typename E>
class ConcretePoolQueue{
    private:
				E	item;
				list<E> groups;
	public:
		void addSingle(E first);
		void addPair(E first,E second);
		void addTriple(E first,E second,E third);
		void addQuartet(E first,E second,E third,E fourth);
		E removeSingle(int c);
		E removePair(int c);
		E removeTriple(int c);
		E removeQuartet(int c);
		bool hasSingle(int c);
		bool hasPair(int c);
		bool hasTriple(int c);
		bool hasQuartet(int c);
		int count();
	};
template<typename E>
void ConcretePoolQueue<E>::addSingle(E item){
		array<string,4> ppl;
		ppl[0]=item;
		group.push_back(ppl);
}
template<typename E>
void ConcretePoolQueue<E>::addPair(E first, E second) { 
        array<string,4> ppl;
		ppl[0]=first;
		ppl[1]=second;
        groups.push_back(ppl);
}
template<typename E>
void ConcretePoolQueue<E>::addTriple(E first, E second, E third) {  
        array<string,4> ppl;
		ppl[0]=first;
		ppl[1]=second;
		ppl[2]=third;
        groups.push_back(ppl);
}
template<typename E>
void ConcretePoolQueue<E>::addQuartet(E first, E second, E third, E fourth) {           
        array<string,4> ppl;
		ppl[0]=first;
		ppl[1]=second;
		ppl[2]=third;
        ppl[3]=fourth;
        groups.push_back(ppl);
}
template<typename E>
E ConcretePoolQueue<E>::removeSingle(int c){   
        for ( int i = c; i < groups.size(); ++i)
            if ( next(group.begin(),c).size() == 1 )
            {
                E returnValue = next(group.begin(),c).get(0);
                groups.remove(i);
                return returnValue; 
            }
        return NULL;
}
template<typename E>
E ConcretePoolQueue<E>::removePair(int c){
        for ( int i = c; i < groups.size(); ++i)       
            if ( next(group.begin(),c).size() == 2)
            {
                list<E> returnValue = next(group.begin(),c);
                groups.remove(i);
                return returnValue; 
            }
            else
                if ( next(group.begin(),c).size() == 1)
                {
                    E single = removeSingle(i+1);
                    if ( single != NULL )
                    {
                        list<E> returnValue = next(group.begin(),c);
                        groups.remove(i);
                        return returnValue; 
                    }
                }
        return NULL;
}
template<typename E>
E ConcretePoolQueue<E>::removeTriple(int c){
        for ( int i = c; i < groups.size(); i++)
            if ( next(group.begin(),c).size() == 3)
            {
                list< E > returnValue = next(group.begin(),c);
                groups.remove(i);
                return returnValue; 
            }
            else
                if ( next(group.begin(),c).size() == 2){
                    E single = removeSingle(i+1);
                    if ( single != NULL )
                    {
                        list<E> returnValue = next(group.begin(),c);
                        groups.remove(i);
                        return returnValue; 
                    }
                }
                else
                    if ( next(group.begin(),c).size() == 1)
                    {
                        list<E> pair = removePair(i+1);
                        if ( pair != NULL )
                        {
                            list<E> returnValue = next(group.begin(),c);
                            groups.remove(i);
                            return returnValue; 
                        }       
                    }
        return NULL;
}
template<typename E>
E ConcretePoolQueue<E>::removeQuartet(int subHead) {
        for ( int i = subHead; i < groups.size();i++)
            if ( next(group.begin(),c).size() == 4)
            {
                list<E> returnValue = next(group.begin(),c);
                groups.remove(i);
                return returnValue; 
            }
            else                
            if ( next(group.begin(),c).size() == 3)
            {
                E single = removeSingle(i+1);
                if ( single != NULL )
                {
                    list<E> returnValue = next(group.begin(),c);
                    groups.remove(i);
                    return returnValue; 
                }                   
            }
            else
                if ( next(group.begin(),c).size() == 2){
                    list<E> pair = removePair(i+1);
                    if ( pair != NULL )
                    {
                        list<E> returnValue = next(group.begin(),c);
                        groups.remove(i);
                        return returnValue; 
                    }
                }
                else
                    if ( next(group.begin(),c).size() == 1)
                    {
                        list<E> triple = removeTriple(i+1);
                        if ( triple != NULL )
                        {
                            list<E> returnValue = next(group.begin(),c);
                            groups.remove(i);
                            return returnValue; 
                        }
                }
        return NULL;
}
template<typename E>
bool ConcretePoolQueue<E>::hasSingle(int c){
        for ( int i = c; i < groups.size(); ++i)
            if ( next(group.begin(),c).size() == 1 )
                return true;
        return false;        
}
template<typename E>
bool ConcretePoolQueue<E>::hasPair(int c){   
        for ( int i = c; i < groups.size(); ++i)
            if ( next(group.begin(),c).size() == 2)
                return true;
            else
                if ( next(group.begin(),c).size() == 1 && hasSingle(i+1))
                    return true;                
        return false;
}
template<typename E>
bool ConcretePoolQueue<E>::hasTriple(int c) {
        for ( int i = c; i < groups.size(); ++i)
            if ( next(group.begin(),c).size() == 3)
                return true;
            else
                if ( next(group.begin(),c).size() == 2 && hasSingle(i+1))
                    return true;                
                else
                    if ( next(group.begin(),c).size() == 1 && hasPair(i+1))
                        return true;                      
        return false;    
}
template<typename E>
bool ConcretePoolQueue<E>::hasQuartet(int c) {
        for ( int i = c; i < groups.size(); ++i)
            if ( next(group.begin(),c).size() == 4)
                return true;
            else
                if ( next(group.begin(),c).size() == 3 && hasSingle(i+1))
                    return true;  
                else
                    if ( next(group.begin(),c).size() == 2 && hasPair(i+1))
                        return true; 
                    else
                        if ( next(group.begin(),c).size() == 1 && hasTriple(i+1))
                            return true;             
        return false;  
}
template<typename E>
int ConcretePoolQueue<E>::count() {
      int c=0;
      for(int a=0;a<groups.size();a++)
      {c=groups.get(a).size()+c;}
        return c;
}
#endif