/*:::::::::::::::::::>>>>   CODED BY RITEK ROUNAK   <<<<::::::::::::::::::

:::::::::::::::::::>>>>   EMPLOYEE MANAGEMENT SYSTEM   <<<<:::::::::::::::::*/

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
class employee
{
	char ename[50];
	int ecode;
	float bsalary;
	char edsg[20];
	char eaddress[50];
	long double netsalary;
	float hra,da,tr,pf,it;
	public:
	employee()
	{
		ecode=0;
		ename[0]='\0';
		bsalary=0;
		edsg[0]='\0';
		eaddress[0]='\0';
	}
	employee(employee&e)
	{
		ecode=e.ecode;
		strcpy(ename,e.ename);
		bsalary=e.bsalary;
		strcpy(edsg,e.edsg);
		strcpy(eaddress,e.eaddress);
	}
	void readdata()
	{
		clrscr();
		cout<<"\n\t\t   Enter the Details :";
		cout<<"\n\n\t\t=> Name of Employee : ";
		gets(ename);
		cout<<"\n\t\t=> Employee Code : ";
		cin>>ecode;
		cout<<"\n\t\t=> Employee Designation : ";
		gets(edsg);
		cout<<"\n\t\t=> Employee Address : ";
		gets(eaddress);
		cout<<"\n\t\t=> Employee Basic Salary : ";
		cin>>bsalary;
		calsalary();
	}
	void printdata()
	{

		cout<<"\n\n\t\t=> Name of Employee : ";
		puts(ename);
		cout<<"\t\t=> Employee Code : ";
		cout<<ecode;
		cout<<"\n\t\t=> Employee Designation : ";
		puts(edsg);
		cout<<"\t\t=> Employee Address : ";
		puts(eaddress);
		cout<<"\t\t=> Employee Basic Salary : ";
		cout<<bsalary;
		cout<<"\n\t\t=> Employee Net Salary : ";
		cout<<netsalary;
	}
	void calsalary()
	{
		hra=bsalary*0.3;
		da=bsalary*0.1;
		tr=bsalary*0.2;
		pf=bsalary*0.2;
		it=bsalary*0.05;
		netsalary=bsalary+hra+da+tr-pf-it;
	}
	long double ret_netsalary()
	{
		return(netsalary);
	}
	float ret_bsalary()
	{
		return(bsalary);
	}
	int ret_ecode()
	{
		return(ecode);
	}
	char*ret_ename()
	{
		return(ename);
	}
	char*ret_edsg()
	{
		return(edsg);
	}
	float ret_hra()
	{
		return(hra);
	}
	float ret_tr()
	{
		return(tr);
	}
	float ret_da()
	{
		return(da);
	}
	float ret_it()
	{
		return(it);
	}
	float ret_pf()
	{
		return(pf);
	}
	void salary()
	{
		cout<<"\n\t----------------------------------------------------------------";
		cout<<"\n\t  > Employee Code : "<<ecode;
		cout<<"\n\t  > Employee Name : "<<ename;
		cout<<"\n\t  > Employee Designation : "<<edsg;
		cout<<"\n\t----------------------------------------------------------------";
		cout<<"\n\t  Earnings          |    Amount   |  Deduction     |   Amount   ";
		cout<<"\n\t----------------------------------------------------------------";
		cout<<"\n\t  Basic \t\t "<<bsalary<<"        PF Employee  \t"<<pf;
		cout<<endl;
		cout<<"\n\t  Allowances \t\t "<<da<<"        Income Tax   \t"<<it;
		cout<<endl;
		cout<<"\n\t  House Rent (HRA)       "<<hra;
		cout<<endl;
		cout<<"\n\t  Transport Allowance    "<<tr;
		cout<<endl;
		cout<<"\n\t  Total                  "<<bsalary+hra+da+tr<<"        Total Deduction     "<<pf+it;
		cout<<"\n\t----------------------------------------------------------------";
		cout<<"\n\t  NET SALARY             "<<netsalary;
	}
	void DisplayRecord()
	{
		cout<<endl;
		cout<<endl<<setw(5)<<ecode<<"\t\t   "<<setw(15)<<ename<<"\t  "<<setw(12)<<""<<edsg<<"   "<<setw(12)<<netsalary;
	}
};
void create()
{
	ofstream fout("employee.dat",ios::out|ios::binary);
	employee e;
	char choice1;
	do
	{
		e.readdata();
		fout.write((char*)&e,sizeof(e));
		cout<<"\n\t\t Do you want to enter more (y/n)";
		cin>>choice1;
	}while((choice1=='Y')||(choice1=='y'));
	fout.close();
}
void display()
{
	ifstream fin("employee.dat",ios::in|ios::binary);
	employee e;
	if(!fin)
	{
		cout<<"\n\t\t !! File Does Not Exist !! ";
		getch();
	}
	int ctr=0;
	while(fin.read((char*)&e,sizeof(e)))
	{
		cout<<"\n\n\t\t\t=> Details of Record : "<<++ctr;
		e.printdata();
		getch();
	}
	fin.close();
}
void display_salary()
{
	ifstream fin("employee.dat",ios::in|ios::binary);
	employee e;
	if(!fin)
	{
		cout<<"\n\t\t !! File Does Not Exist !! ";
		getch();
	}
	int code;
	int flag=0;
	cout<<"\n\t\t=> Enter the Employee Code : ";
	cin>>code;
	while(!fin.eof())
	{
		fin.read((char*)&e,sizeof(e));
		if(e.ret_ecode()==code)
		{
			flag=1;
			clrscr();
			cout<<"\n\t\t\t\t  SALARY SLIP  ";
			e.salary();
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\n\t\tRecord not Found ";
	}

}
void code_search()
{
	clrscr();
	ifstream fin("employee.dat",ios::binary|ios::in);
	employee e;
	int code;
	int flag=0;
	cout<<"\n\t\t=> Enter the Employee Code : ";
	cin>>code;
	while(!fin.eof())
	{
		fin.read((char*)&e,sizeof(e));
		if(e.ret_ecode()==code)
		{
			flag=1;
			e.printdata();
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\n\t\tRecord not Found ";
	}
	fin.close();
}
void name_search()
{
	clrscr();
	ifstream fin("employee.dat",ios::binary|ios::in);
	employee e;
	char name[50];
	int flag=0;
	cout<<"\n\t\t=> Enter the Employee Name : ";
	gets(name);
	while(!fin.eof())
	{
		fin.read((char*)&e,sizeof(e));
		if(strcmpi(e.ret_ename(),name)==0)
		{
			flag=1;
			e.printdata();
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\n\t\tRecord not Found ";
	}
	fin.close();
}
void modify()
{
	fstream f("employee.dat",ios::binary|ios::in|ios::out);
	employee e;
	int code;
	cout<<"\n\t\t=> Enter the Employee Code : ";
	cin>>code;
	int rec_count=0;
	char found='N';
	while(f.read((char*)&e,sizeof(e)))
	{
		if(e.ret_ecode()==code)
		{
			cout<<"\n\t\t\t=> Enter the Details ";
			e.readdata();
			f.seekg(rec_count*sizeof(e),ios::beg);
			f.write((char*)&e,sizeof(e));
			found='Y';
			break;
		}
		rec_count++;

	}

	if(found=='Y')
		cout<<"\n\t\t\t=> Record Updated";
	else
		cout<<"\n\t\t\t=> Record not Found";
	f.close();
}
void delete1()
{
	ifstream fin("employee.dat",ios::binary|ios::in);
	ofstream fout("temp.dat",ios::binary|ios::out);
	employee e;
	int code;
	cout<<"\n\n\t\t=> Enter Employee Code whose record to be Deleted : ";
	cin>>code;
	char found='Y';
	while(fin.read((char*)&e,sizeof(e)))
	{
		if(e.ret_ecode()!=code)
		{
			fout.write((char*)&e,sizeof(e));
		}
		else
			found='N';
	}
	if(found=='Y')
		cout<<"\n\n\t\t=> Record not Found";
	else
		cout<<"\n\t\t\t=> Record Deleted";
	fin.close();
	fout.close();
	remove("employee.dat");
	rename("temp.dat","employee.dat");
}
void dsg_search()
{
	clrscr();
	ifstream fin("employee.dat",ios::binary|ios::in);
	employee e;
	char dsg[50];
	int flag=0;
	cout<<"\n\t\t=> Enter Designation to list employee within it  : ";
	gets(dsg);
	cout<<"\n\n"<<setw(5)<<"Employee Code"<<setw(12)<<" "<<"Employee Name"<<setw(12)<<""<<"Designation"<<setw(12)<<"Salary";
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&e,sizeof(e)))
	{
		fin.read((char*)&e,sizeof(e));
		if(strcmpi(e.ret_edsg(),dsg)==0)
		{
			flag=1;
			e.DisplayRecord();

		}
	}
	if(flag==0)
	{
		cout<<"\n\n\n\t\tData not found for Designation : "<<dsg;
	}
	fin.close();
}
void sal_search()
{
	clrscr();
	ifstream fin("employee.dat",ios::binary|ios::in);
	employee e;
	long double sal;
	int flag=0;
	cout<<"\n\t\t=> Enter Salary to list employee within it  : ";
	cin>>sal;
	cout<<"\n\n"<<setw(5)<<"Employee Code"<<setw(12)<<" "<<"Employee Name"<<setw(12)<<""<<"Designation"<<setw(12)<<"Salary";
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&e,sizeof(e)))
	{
		fin.read((char*)&e,sizeof(e));
		if(e.ret_netsalary()==sal)
		{
			flag=1;
			e.DisplayRecord();

		}
	}
	if(flag==0)
	{
		cout<<"\n\n\n\t\tData not found for Salary :"<<sal;
	}
	fin.close();
}
void intro()
{
char pass[50];
clrscr();
textcolor(LIGHTRED);
textbackground(WHITE);
	gotoxy(24,8);
	cout<<"------------------------------------\n";
	gotoxy(24,10);
	cprintf(">>>> EMPLOYEE MANAGEMENT SYSTEM <<<<");
	gotoxy(24,12);
	cout<<"------------------------------------";

	cout<<"\n\n\t\t\tCODED BY : RITEK ROUNAK";
	cout<<"\n\t\t\tClass: XII-A";
	cout<<"\n\t\t\tSCHOOL : DAV PUBLIC SCHOOL ASHOK VIHAR";
	getch();
}

void main()
{
	employee e;
	int choice2;
	char choice3;
	intro();
	do
	{
		clrscr();
		cout<<"\n\n\t\t   >>>>>>>> EMPLOYEE MANAGEMENT SYSTEM <<<<<<<<\n\n";
		cout<<"\n\t\t****************************************************";
		cout<<"\n\t\t*            MENU                                  *";
		cout<<"\n\t\t*    1. Add New Employee Details                   *";
		cout<<"\n\t\t*    2. View Employee Details                      *";
		cout<<"\n\t\t*    3. Search record by Employee Code             *";
		cout<<"\n\t\t*    4. Search record by Employee Name             *";
		cout<<"\n\t\t*    5. Update Record of an Employee               *";
		cout<<"\n\t\t*    6. Delete Record by Employee Code             *";
		cout<<"\n\t\t*    7. Print Salary Slip                          *";
		cout<<"\n\t\t*    8. List Employees of Particular Designation   *";
		cout<<"\n\t\t*    9. List Employees of Particular Salary        *";
		cout<<"\n\t\t*   10. Exit                                       *";
		cout<<"\n\t\t****************************************************";
		cout<<"\n\n\t\t\t=> Enter Your Choice ";
		cin>>choice2;
		switch(choice2)
		{
			case 1: create();
				break;
			case 2: clrscr();
				display();
				break;
			case 3: code_search();
				break;
			case 4: name_search();
				break;
			case 5: clrscr();
				modify();
				break;
			case 6: clrscr();
				delete1();
				break;
			case 7: clrscr();
				display_salary();
				break;
			case 8: clrscr();
				dsg_search();
				break;
			case 9: clrscr();
				sal_search();
				break;
			case 10: cout<<"\n\n\t\t\tT H A N K S , G O O D  B Y E :)";
				 delay(1000);
				 exit(0);
			default:cout<<"\n\t\t Wrong Choice ";
		}
		cout<<"\n\n\t\t=> Do you want to Return to Menu (y/n) ";
		cin>>choice3;
	}while((choice3=='Y')||(choice3=='y'));
	cout<<"\n\n\t\t\tT H A N K S , G O O D  B Y E :)";
	getch();

}
