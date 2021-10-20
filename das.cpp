#include<bits/stdc++.h> using namespace std; 
class salary{
public:
int basic_salary,exp_f,exp_d,inc,gross_inc,bonus_f,bonus_d;
};
class Faculty; class Dean;

class Faculty: public salary{ private:
int gross_salary;
public:
void calculate_salary_faculty(){
cout<<"Enter basic salary of Faculty : "; cin>>basic_salary;
cout<<"Enter experience and bonus of Faculty : "; cin>>exp_f>>bonus_f;

inc=0.005*basic_salary; gross_inc=inc*(exp_f/4); gross_salary=gross_inc+basic_salary+bonus_f;
cout<<"Gross salary of Faculty : "<<gross_salary<<endl;
}
friend double average(Faculty fac,Dean de );
};
class Dean: public salary{ private:
int gross_salary;
public:
void calculate_salary_dean(){
cout<<"Enter basic salary of Dean : "; cin>>basic_salary;
cout<<"Enter experience and bonus of Dean : "; cin>>exp_d>>bonus_d;
 

inc=0.02*basic_salary; gross_inc=inc*(exp_d/2); gross_salary=gross_inc+basic_salary+bonus_d;
cout<<"Gross salary of Dean : "<<gross_salary<<endl;
}
friend double average(Faculty fac,Dean de );
};
double average(Faculty f,Dean d){
double sum=d.gross_salary+f.gross_salary; return sum/2;
}
int main()
{
Faculty f; f.calculate_salary_faculty(); Dean d; d.calculate_salary_dean();
cout<<"Average gross salary : "<<average(f,d)<<endl;

return 0;
}

