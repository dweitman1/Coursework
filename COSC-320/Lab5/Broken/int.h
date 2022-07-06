#ifndef Integer_H
#define Integer_H

using namespace std;

class integer
{
	public:
		// constructor. initialize intValue and set count = 1
		integer(int n);

		// return intValue
		int getInt();
		

		// return count
		int getCount();
		

		// increment count
		void incCount();
		

		// compare integer objects by intValue
		friend bool operator< (const integer& lhs, const integer& rhs);

		friend bool operator== (const integer& lhs, const integer& rhs);
		
		// output object in format intValue (count)
		friend ostream& operator<< (ostream& ostr, const integer& obj);
		
	private:
		// the integer and its count
		int intValue;
		int count;
};

integer::integer(int n){
    intValue = n;
    count = 0;
    
}

int integer::getInt(){
    return intValue;
    
}

int integer::getCount(){
    return count;
    
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
