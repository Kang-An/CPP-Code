#include <iostream>

using namespace std;
//¸¸Àà: Person
class Person
{
public:
    string name;
    int age;
    virtual void getdata(){};
    virtual void putdata(){};
};

class Professor:public Person
{
public:
    int publications;
    int pro_id;
static int cur_id;

    virtual void getdata()
    {
        cur_id++;
        cin>>name;
        cin>>age;
        cin>>publications;
        pro_id = cur_id;
    }

    virtual void putdata()
    {
        cout<<name<<" "<<age<<" "<<publications<<" "<<pro_id<<" "<<endl;

    }
};
int Professor::cur_id = 0;

class Student:public Person
{
public:
    int marks[6];
    int stu_id;
    int sum = 0;
static int cur_stu_id;

virtual void getdata()
{
    int i;
    cur_stu_id++;
    cin>>name;
    cin>>age;
    for( i = 0; i < 6; i++)
    {
        cin>>marks[i];        sum += marks[i];

    }
    stu_id = cur_stu_id;
}

virtual void putdata()
{
    cout<<name<<" "<<age<<" "<<sum<<" "<<stu_id<<endl;
}

};

int Student::cur_stu_id = 0;
int main()
{
    int n,val;
    cin>>n;
    Person *per[n];

    for(int i= 0; i <n;i++)
    {

        cin>>val;
        if(val == 1)
            per[i] = new Professor;
        else if(val == 2)
            per[i] = new Student;

        per[i]->getdata();
    }

    for(int i = 0; i <n; i++)
    {
        per[i]->putdata();
    }

    return 0;
}
