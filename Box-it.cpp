#include<bits/stdc++.h>

using namespace std;

class Box{
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
private:
    int length;
    int breadth;
    int height;
// The class should have the following functions : 
public:
// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);
    void Box(){};
    void Box(int length, int breadth, int height)
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }
    void Box(Box& box)
    {
        this->length = box->length;
        this->breadth = box->breadth;
        this->height = box->height;
    }
// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box
    int getLength()
    {
        return this->length;
    }
    int getBreadth()
    {
        return this->breadth;
    }
    int getHeight()
    {
        return this->height;
    }
    long long CalculateVolume()
    {
        return this->length * this->breadth * this->height;
    }
//Overload operator < as specified
//bool operator<(Box& b)
    bool operator < (Box& b)
    {
        bool flag;
        if(this->length < b->length)
            flag = true;
        else if((this->breadth < b->breadth) && (this->length == b->length))
            flag = true;
        else if((this->height < b->height) &&(this->breadth == b->breadth) && (this->length == b->length))
            flag = true;
        else
            flag = false;
        
        return flag;
    }
//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
    ostream& operator<<(ostream& out, Box& B)
    {
        cout << B->height << " " << B->breadth << " " << B->length << endl;
    }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}

class Box {
	int l, b, h;
public:
	Box() : l(0), b(0), h(0) { BoxesCreated++; }
	Box(int length, int breadth, int height) : l(length), b(breadth), h(height) { BoxesCreated++; }
	Box(const Box& b) : l(b.l), b(b.b), h(b.h) { BoxesCreated++; }
	int getLength() const {
		return l;
	}
	int getBreadth() const {
		return b;
	}
	int getHeight() const {
		return h;
	}
	long long CalculateVolume() const {
		return 1LL * l * b * h;
	}
	~Box() {
		BoxesDestroyed++;
	}
	bool operator<(const Box& another) const {
		if (l != another.l) {
			return l < another.l;
		}
		if (b != another.b) {
			return b < another.b;
		}
		return h < another.h;
	}
	void output(ostream& out) const {
		out << l << " " << b << " " << h;
	}
};

ostream& operator<<(ostream& out, Box b) {
	b.output(out);
	return out;
}