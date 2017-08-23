/*
This type of class can have abstract methods as well as defined methods, 
but it cannot be instantiated (meaning you cannot create a new instance of it). 
To use an abstract class, you must create and instantiate a subclass that extends the abstract class. 
Any abstract methods declared in an abstract class must be implemented by its subclasses 
(unless the subclass is also abstract).

Canine c = new KleeKai("Lilah", "Grey/White", 5, 'F');
Canine d = new SiberianHusky("Alaska", "Grey/Black/White", 16, 'F');
c.printInfo();
d.printInfo();
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
Because these classes are being written in the same file, 
you must not use an access modifier (e.g.:public) 
when declaring MyBook or your code will not execute.
*/
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};
// Write your MyBook class here
class MyBook : public Book{
    protected://定义为private 编译不通过
        int price;
    //   Class Constructor
    //   
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
    //
    // Write your constructor here
    public:
        MyBook(string title, string author, int price):Book(title, author){
            this->price = price;
        }
    
    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    //
    // Write your method here
    void display(){
        cout<<"Title: "<<this->title<<endl;
        cout<<"Author: "<<this->author<<endl;
        cout<<"Price: "<<this->price<<endl;
    }
    
// End class
};
int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}