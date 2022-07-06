#ifndef Integer_H
#define Integer_H

using namespace std;

class integer
{
	public:
		
		integer();
		// constructor. initialize intValue and set count = 1
		integer(int n);

		// return intValue
		int getInt();
		
		// set intValue
		void setInt(int);

		// return count
		int getCount();
		
		void setCount(int);
		

		// increment count
		void incCount();
		

		// compare integer objects by intValue
		friend bool operator< (const integer& lhs, const integer& rhs);
		friend bool operator> (const integer& lhs, const integer& rhs);
		friend bool operator== (const integer& lhs, const integer& rhs);
		
		// output object in format intValue (count)
		friend ostream& operator<< (ostream& ostr, const integer& obj);
		
	private:
		// the integer and its count
		int intValue;
		int count;
};

integer::integer(){
  count = 1; 
}
integer::integer(int n){
    intValue = n;
    count = 1;
    
}

int integer::getInt(){
    return intValue;
    
}

void integer::setInt(int x){
    intValue = x;
  
}

int integer::getCount(){
    return count;
    
}

void integer::setCount(int x){
  count = x;
  
}

void integer::incCount(){
    count++;
    return;
    
}

bool operator <(const integer& lhs, const integer& rhs){
    if(lhs.intValue < rhs.intValue){
        return true;
    }
    return false;
}

bool operator >(const integer& lhs, const integer& rhs){
    if(lhs.intValue > rhs.intValue){
        return true;
    }
    return false;
}

bool operator ==(const integer& lhs, const integer& rhs){
    if(lhs.intValue == rhs.intValue){
        return true;
    }
    return false;
}

ostream& operator <<(ostream& ostr, const integer& obj){
    ostr << obj.intValue << " " << "(" << obj.count << ")";
}

#endif 
