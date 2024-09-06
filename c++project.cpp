#include<iostream>
#include<windows.h>
#include<fstream>
#include<sstream>
#include<String.h>
using namespace std;
class Hostel
{
	private:
	string Name;
	int Rent,Bed;
	public:
	Hostel(string name,int rent,int bed)
	{
		Name=name;
		Rent=rent;
		Bed=bed;
	}
	string getname()
	{
		return Name;
	}
	int getrent()
	{
		return Rent;
	}
	int getbed()
	{
		return Bed;
	}
	reserve()
	{
		ifstream in("Hostel.txt");
		ofstream out("Hostel temp.txt");
		string line;
		while(getline(in,line))
		{
			int pos=line.find("3star");
			if(pos!= string::npos)
			{
				int bed=Bed-1;
				Bed=bed;
				stringstream ss;
				ss<<bed;
				string strBed=ss.str();
				int bedPos = line.find_last_of(':');
				line.replace(bedPos+1,string::npos,strBed);
				
			}
			out<<line<<endl;
		}
	   out.close();
	   in.close();
	   remove("Hostel.txt")	;
	   rename("Hostel temp.txt","Hostel.txt");
	   cout<<"\tBed reserved successfully!"<<endl;
	}
};

class student
{
  private:
  string name,address,rollno;
  public:
  student():name(""),rollno(""),address("")	{}
  
  setName(string Name)
  {
  	name=Name;
  }
  setRollno(string Rollno)
  {
  	rollno=Rollno;
  }
  setAddress(string Address)
  {
  	address=Address;
  }
  string getName()
  {
  	return name;
  }
   string getRollNo()
  {
  	return rollno;
  }
  string getAddress()
  {
  	return address;
  }
};

int main()
{
	Hostel h("3star",5000,2);
	ofstream out("Hostel.txt");
	out<<"\t"<<h.getname()<<" : "<<h.getrent()<<" : "<<h.getbed()<<endl;
	cout<<"Hostel Data Saved"<<endl;
	out.close();
	student s;
	bool exit=false;
	while(!exit)
	{
	   system("cls");
	   int val;
	   cout<<"\tWELCOME TO HOSTEL ACCOMODATION SYSTEM" <<endl;
	   cout<<"\t*************************************"<<endl;
	   cout<<"\t1.Reserve a Bed"<<endl;
	   cout<<"\t2.Exit"<<endl;
	   cout<<"\tEnter a choice"<<endl;
	   cin>>val;
	   if(val==1)
	   {
	   	system("cls");
	   	string name,rollno,address;
	   	cout<<"Enter name of student"<<endl;
	   	cin>>name;
	   	s.setName(name);
	   	cout<<"Enter rollno."<<endl;
	   	cin>>rollno;
	   	s.setRollno(rollno);
	   	cout<<"Enter address"<<endl;
	   	cin>>address;
	   	s.setAddress(address);
	   	
	   	if(h.getbed()>0)
	   	{
	   		h.reserve();
		   }
		else if(h.getbed()==0)
		{
			cout<<"\tSorry! No bed available"<<endl;
		}
	   	
	   	ofstream outfile("Student.txt",ios::app);
	   	outfile<<"\t"<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getAddress()<<endl<<endl;
	   	Sleep(2000);
	   }
	   if(val==2)
	   {
	   	system("cls");
	   	exit=true;
	   	cout<<"\tGood Luck"<<endl;
	   	Sleep(1000);  	   
		}
	}
	return 0;
}
