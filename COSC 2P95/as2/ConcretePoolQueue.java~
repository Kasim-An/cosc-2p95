package assignment1;
import java.util.LinkedList;
import java.util.List;
//Xinan Wang,5535802

public class ConcretePoolQueue<E> implements PoolQueue<E>{

    private LinkedList<LinkedList<E>> groups = new LinkedList<LinkedList<E>>();
    private LinkedList<E> ppl = new LinkedList<E>();

    public void addSingle(E item) {
        ppl.add(item);
        groups.add(ppl);
   
    }
    public void addPair(E first, E second) { 
        LinkedList<E> ppl = new LinkedList<E>();
        ppl.add(first);
        ppl.add(second);
        groups.add(ppl);
    }
    public void addTriple(E first, E second, E third) {//addTriple's big-O is n because it just go through all the list.   
        LinkedList<E> ppl = new LinkedList<E>();
        ppl.add(first);
        ppl.add(second);
        ppl.add(third);
        groups.add(ppl);
    }
    public void addQuartet(E first, E second, E third, E fourth) {           
        LinkedList<E> ppl = new LinkedList<E>();  
        ppl.add(first);
        ppl.add(second);
        ppl.add(third);
        ppl.add(fourth);
        groups.add(ppl);
    }
    public E removeSingle() {         
        E returnValue = removeSingle(0);
        if (returnValue == null)
            throw new InsufficientElementsException();
        return returnValue;
    }
    private E removeSingle(int c){   
        for ( int i = c; i < groups.size(); ++i)
            if ( groups.get(i).size() == 1 )
            {
                E returnValue = groups.get(i).get(0);
                groups.remove(i);
                return returnValue; 
            }
        return null;
    }
    public List<E> removePair() {   
        List<E> returnValue = removePair(0);
        if (returnValue == null)
            throw new InsufficientElementsException();
        return returnValue;
    }
    private List<E> removePair(int c){
        for ( int i = c; i < groups.size(); ++i)       
            if ( groups.get(i).size() == 2)
            {
                List<E> returnValue = groups.get(i);
                groups.remove(i);
                return returnValue; 
            }
            else
                if ( groups.get(i).size() == 1)
                {
                    E single = removeSingle(i+1);
                    if ( single != null )
                    {
                        List<E> returnValue = groups.get(i);
                        groups.remove(i);
                        returnValue.add(single);
                        return returnValue; 
                    }
                }
        return null;
    }
    public List<E> removeTriple(){
        List<E> returnValue = removeTriple(0);
        if (returnValue == null)
            throw new InsufficientElementsException();   
        return returnValue;
    }
    private List<E> removeTriple(int c){//removeTriple's big-O is n/3+(n/3)*((n/2)+(n/2)*n)+(n/3)*n is O(n^3)
        for ( int i = c; i < groups.size(); i++)
            if ( groups.get(i).size() == 3)
            {
                List<E> returnValue = groups.get(i);
                groups.remove(i);
                return returnValue; 
            }
            else
                if ( groups.get(i).size() == 2){
                    E single = removeSingle(i+1);
                    if ( single != null )
                    {
                        List<E> returnValue = groups.get(i);
                        groups.remove(i);
                        returnValue.add(single);
                        return returnValue; 
                    }
                }
                else
                    if ( groups.get(i).size() == 1)
                    {
                        List<E> pair = removePair(i+1);
                        if ( pair != null )
                        {
                            List<E> returnValue = groups.get(i);
                            groups.remove(i);
                            returnValue.addAll(pair);
                            return returnValue; 
                        }       
                    }
        return null;
    }
    public List<E> removeQuartet() {
        List<E> returnValue = removeQuartet(0);
        if (returnValue == null)
            throw new InsufficientElementsException();
        return returnValue;
    }
    public List<E> removeQuartet(int subHead) {
        for ( int i = subHead; i < groups.size();i++)
            if ( groups.get(i).size() == 4)
            {
                List<E> returnValue = groups.get(i);
                groups.remove(i);
                return returnValue; 
            }
            else                
            if ( groups.get(i).size() == 3)
            {
                E single = removeSingle(i+1);
                if ( single != null )
                {
                    List<E> returnValue = groups.get(i);
                    groups.remove(i);
                    returnValue.add(single);
                    return returnValue; 
                }                   
            }
            else
                if ( groups.get(i).size() == 2){
                    List<E> pair = removePair(i+1);
                    if ( pair != null )
                    {
                        List<E> returnValue = groups.get(i);
                        groups.remove(i);
                        returnValue.addAll(pair);
                        return returnValue; 
                    }
                }
                else
                    if ( groups.get(i).size() == 1)
                    {
                        List<E> triple = removeTriple(i+1);
                        if ( triple != null )
                        {
                            List<E> returnValue = groups.get(i);
                            groups.remove(i);
                            returnValue.addAll(triple);
                            return returnValue; 
                        }
                }
        return null;
    }
    public boolean hasSingle() {    
        return hasSingle(0);
    }
    private boolean hasSingle(int c){
        for ( int i = c; i < groups.size(); ++i)
            if ( groups.get(i).size() == 1 )
                return true;
        return false;        
    }
    public boolean hasPair() {   
        return hasPair(0);
    }
    private boolean hasPair(int c){   
        for ( int i = c; i < groups.size(); ++i)
            if ( groups.get(i).size() == 2)
                return true;
            else
                if ( groups.get(i).size() == 1 && hasSingle(i+1))
                    return true;                
        return false;
    }
    public boolean hasTriple() {
        return hasTriple(0);
    }
    private boolean hasTriple(int c) {//hasTriple's big-O is n/3+(n/3)*((n/2)+(n/2)*n)+(n/3)*n is O(n^3)
        for ( int i = c; i < groups.size(); ++i)
            if ( groups.get(i).size() == 3)
                return true;
            else
                if ( groups.get(i).size() == 2 && hasSingle(i+1))
                    return true;                
                else
                    if ( groups.get(i).size() == 1 && hasPair(i+1))
                        return true;                      
        return false;    
    }
    public boolean hasQuartet() {
        return hasQuartet(0);
    }
    private boolean hasQuartet(int c) {
        for ( int i = c; i < groups.size(); ++i)
            if ( groups.get(i).size() == 4)
                return true;
            else
                if ( groups.get(i).size() == 3 && hasSingle(i+1))
                    return true;  
                else
                    if ( groups.get(i).size() == 2 && hasPair(i+1))
                        return true; 
                    else
                        if ( groups.get(i).size() == 1 && hasTriple(i+1))
                            return true;             
        return false;  
    }
    public int count() {
      int c=0;
      for(int a=0;a<groups.size();a++)
      {c=groups.get(a).size()+c;}
        return c;
    }
}