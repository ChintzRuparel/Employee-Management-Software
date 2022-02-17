#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
class staff
{
    long long int code;
    string name;
public:
    staff()
    {
        code=0;
        name="xyz";
    }
    void get_staff()
    {
        cout<<"Enter your name: ";
        getline(cin,name);
        getline(cin,name);
        cout<<"\nEnter your code: ";
        cin>>code;
    }
    void display_staff()
    {
        cout<<"\nHello "<<name<<"\nID: "<<code;

    }
};
class qualification
{
    string edu_qualification;
    string pro_qualification;
public:
    qualification()
    {
        edu_qualification="Null";
        pro_qualification="null";
    }
    void get_qualification()
    {
        cout<<"\nEnter your highest educational qualification: ";
        getline(cin,edu_qualification);
        getline(cin,edu_qualification);
        cout<<"\nEnter your highest professional qualification: ";
        getline(cin,pro_qualification);
    }
    void display_qualification()
    {
        cout<<"\nHighest Educational Qualification: "<<edu_qualification;
        cout<<"\nHighest Professional Qualification: "<<pro_qualification<<endl;
    }
};
class teacher:public staff,public qualification
{
 //   char subject[100];
    int publication;
    string subject;
public:
    teacher()
    {
        subject="";
        publication=0;
    }
    void get_teacher()
    {
        get_staff();
        get_qualification();
        cout<<"\nEnter your subject: ";
        getline(cin,subject);
        cout<<"\nEnter the number of publications by you: ";
        cin>>publication;
    }
    void display_teacher()
    {
        cout<<"Details -"<<endl;
        display_staff();
        display_qualification();
        cout<<"\nSubject: "<<subject<<"\nPublications: "<<publication<<endl;
    }
};
class officer:public staff,public qualification
{
    char grade;
public:
    officer()
    {
        grade='A';
    }
    void get_officer()
    {
        get_staff();
        get_qualification();
        cout<<"\nEnter your grade: ";
        cin>>grade;
    }
    void display_officer()
    {
        cout<<"Details -"<<endl;
        display_staff();
        display_qualification();
        cout<<"\nYour grade is: "<<grade<<endl;
    }
};
class typist:public staff
{
    float speed;
public:
    typist()
    {
        speed=0.0;
    }
    void get_typist()
    {
        get_staff();
        cout<<"\nEnter your typing speed(words/min): ";
        cin>>speed;
    }
    void display_typist()
    {
        cout<<"\n\nDetails -"<<endl;
        display_staff();
        cout<<"\nTyping speed(words/min): "<<speed<<endl;
    }
};

class regular_typist:public typist
{
    double salary;
public:
    regular_typist()
    {
        salary=0.0;
    }
    void get_regular()
    {
        get_typist();
    }
    void display_regular()
    {
        display_typist();
        cout<<"\nYour monthly wage is: Rs. 5000/-"<<endl;
    }
};
class casual_typist:public typist
{
    double daily_wage;
public:
    casual_typist()
    {
        daily_wage=0.0;
    }
    void get_casual()
    {
        get_typist();
    }
    void display_casual()
    {
        display_typist();
        cout<<"\nYour daily wage is: Rs. 200/-"<<endl;
    }
};
int main()
{
     teacher t[100];
     int a=0,b1=0,b2=0,c=0;
     int ta=0,tb1=0,tb2=0,tc=0;
     regular_typist rt[100];
     casual_typist ct[100];
     officer o[100];
   while(true)
   {
     cout<<"Hello User!\nEnter your selection-\n1.Add data\n2.Show data\n3.Exit\n";
     int choice;
     cin>>choice;
     switch(choice)
     {
     case 1:
        {
            cout<<"Select your profession:"<<endl;
            int choice2;
            cout<<"1. Teacher\n2. Typist\n3. Officer\nSelection: ";
            cin>>choice2;
            switch(choice2)
            {
            case 1:
                {   teach:
                    t[a].get_teacher();
                    a++;
                    cout<<"\nAdd more records for teacher?\nSelection(Y/N): ";
                    char tmore;
                    cin>>tmore;
                    if(tmore=='Y')
                        goto teach;
                    else
                        break;
                }
            case 2:
                {
                    cout<<"Select your type:\n1.Regular\n2.Casual\nSelection: ";
                    int choice3;
                    cin>>choice3;
                    switch(choice3)
                    {
                    case 1:
                        {
                            reg:
                            rt[b1].get_regular();
                            b1++;
                            cout<<"\nAdd more records for regular typist?\nSelection(Y/N): ";
                            char tmore;
                            cin>>tmore;
                            if(tmore=='Y')
                                goto reg;
                            else
                                break;
                        }
                    case 2:
                        {
                            cas:
                            ct[b2].get_casual();
                            b2++;
                            cout<<"\nAdd more records for casual typist?\nSelection(Y/N): ";
                            char tmore;
                            cin>>tmore;
                            if(tmore=='Y')
                                goto cas;
                            else
                                break;
                        }
                        default:cout<<"\nInvalid input!"<<endl;
                    }
                    break;
                }
            case 3:
                {
                    off:
                    o[c].get_officer();
                    c++;
                    cout<<"\nAdd more records for officer?\nSelection(Y/N): ";
                    char tmore;
                    cin>>tmore;
                    if(tmore=='Y')
                        goto off;
                    else
                        break;
                }
            default:cout<<"Invalid input!";

            }
          break;
        }
    case 2:
        {
            cout<<"Select profession:"<<endl;
            int choice4;
            cout<<"1. Teacher\n2. Typist\n3. Officer\nSelection: ";
            cin>>choice4;
            switch(choice4)
            {
            case 1:
                {
                    while(ta<a)
                    {
                        t[ta].display_teacher();
                        ta++;
                    }
                    break;
                }
            case 2:
                {
                    cout<<"Select your type:\n1.Regular\n2.Casual\nSelection: ";
                    int choice5;
                    cin>>choice5;
                    switch(choice5)
                    {
                    case 1:
                        {   tb1=0;
                            while(tb1<b1)
                            {   rt[tb1].display_regular();
                                tb1++;
                            }
                            break;
                        }
                    case 2:
                        {tb2=0;
                            while(tb2<b2)
                           {
                             ct[tb2].display_casual();
                             tb2++;
                           }
                            break;
                        }
                        default:cout<<"\nInvalid input!"<<endl;
                    }
                    break;
                }
            case 3:
                {tc=0;
                    while(tc<c)
                    {
                    o[tc].display_officer();
                    tc++;
                    }
                    break;
                }
            default:cout<<"Invalid input!";

            }
          break;
        }

    case 3:break;
    default:cout<<"Invalid input!";

     }

   }
return 0;
}
