//oop project
// FHM hotelmanagement sytem
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class person
{
protected:
	string name;
	string id;
	string phone_no;
public:
	//parametrized constructor
	person(string n, string i, string  pn)
	{
		name = n;
		id = i;
		phone_no = pn;
	}
	void display() {
	}
};
class employee :public person
{
protected:
	string age;
	string salary;
	string post;
public:
	//paramertized constructor
	employee(string n, string i, string pn) :person(n, i, pn)
	{

	}
	void display() {
		cout << "\n -- You entered employee panel -- \n";
	}

	void emp_search()
	{
		fstream obj;
		obj.open("employee.txt", ios::in);
		cout << "Enter your name: ";

		string namee;
		string iid;
		cin >> namee;
		cout << "Enter your id: ";
		cin >> iid;
		string l;
		string ph;
		int ag;
		string po;
		int sal;
		//n is for searching employee by name in file
		string n;
		getline(obj, n);
		while (!obj.eof())
		{
			getline(obj, n);
			if (namee == n)
			{

				cout << n << endl;
				obj >> l;
				if (iid == l)
				{

					cout << l << endl;
					obj >> ph;
					cout << ph << endl;
					obj >> ag;
					cout << ag << endl;
					obj >> sal;
					cout << sal << endl;
					obj >> po;
					cout << po << endl;
					break;
				}
			}

		}
	}
	//start from here
	void salary_cal()
	{
		char choice;
		cout << "\t\t*********SALARY CALCULATOR**************" << endl;
		cout << " Enter m for manager \nEnter r for reciptionist \nEnter s for sanitary staff \nEnter o for online management staff\nEnter c for chef \nEnter  w for waiter \n";
		cin >> choice;
		int days;
		if (choice == 'm')
		{
			cout << "Enter the no of worked days ";
			cin >> days;
			int s = 15000 * days;
			cout << "your salary : " << s << endl;
		}
		if (choice == 'r')
		{
			cout << "Enter no of days worked ";
			cin >> days;
			int k = 5000 * days;
			cout << "your salary : " << k << endl;
		}
		if (choice == 'o')
		{
			cout << "Enter the no of worked days ";
			cin >> days;
			int n = 10000 * days;
			cout << "your salary : " << n << endl;
		}
		if (choice == 'w')
		{
			cout << "Enter the no of worked days ";
			cin >> days;
			int h = 3000 * days;
			cout << "your salary : " << h << endl;
		}
		if (choice == 'c')
		{
			cout << "Enter the no of worked days ";
			cin >> days;
			int z = 8000 * days;
			cout << "your salary : " << z << endl;
		}
		if (choice == 's')
		{
			cout << "Enter the no of worked days ";
			cin >> days;
			int i = 1000 * days;
			cout << "your salary : " << i << endl;
		}
	}
};
class guest :public person
{
private:
	float bill;
	string fam_mem;
	int  no_days;
	int pack;
public:
	void display() {
		cout << "\n -- You entered guest panel -- \n";
	}
	guest(string n, string i, string pn, int f, int nd, int p) :person(n, i, pn)
	{

		fam_mem = f;
		no_days = nd;
		pack = p;
	}
	void guest_onlinebook()
	{
		fstream gst;
		gst.open("guest.txt", ios::out | ios::app);
		gst << endl;
		cout << "Enter your name : ";
		cin >> name;
		gst << name << endl;
		cout << "Enter your CNIC : ";
		cin >> id;
		gst << id << endl;
		cout << "Enter your phone num : ";
		cin >> phone_no;
		gst << phone_no << endl;
		cout << "Enter no of members : ";
		cin >> fam_mem;
		gst << fam_mem << endl;
		cout << "Enter the num of days you want to stay : ";
		cin >> no_days;
		gst << no_days << endl;
		cout << "Enter your package: Enter 1 for big package and enter 2 for small package : " << endl;
		cin >> pack;
		gst << pack << endl;
		gst.close();
	}
	void bill_payment()
	{
		fstream bp;
		bp.open("guest.txt", ios::in);
		string n;
		string k;
		string i;
		string pn;
		string f;
		int no;
		int p;
		cout << "Enter the name of the guest for which you want to calculate the bill : " << endl;
		cin >> k;
		getline(bp, n);
		while (!bp.eof())
		{
			getline(bp, n);
			if (k == n)
			{

				cout << "Name : " << n << endl;
				bp >> i;
				cout << "CNIC : " << i << endl;
				bp >> pn;
				cout << "Phone no : " << pn << endl;
				bp >> f;
				cout << "Family members : " << f << endl;
				bp >> no;
				cout << "number of days :" << no << endl;
				bp >> p;
				cout << "Package is : ";

				if (p == 1)
				{
					cout << "Big package" << endl;
					int r = no * 40000;
					cout << "bill : " << r << endl;

				}
				if (p == 2)
				{
					cout << "Small package" << endl;
					int re = no * 20000;
					cout << "bill : " << re << endl;
				}
				break;
			}
		}

	}

};
static int table_no = 0;
class restaurant :public person
{
private:
	int no_tables;
	string menu;
	string order;
	long bill;

public:

	void display() {
		cout << "\n You entered Restaurant panel -- \n";
	}
	restaurant(string n, string i, string pn) :person(n, i, pn)
	{


	}
	void r_menu()
	{
		table_no++;
		int a;
		char x;
		bill = 0;
		do {
			cout << "If you want to choose drinks enter 1 \n If you want to choose fast food enter 2 \n if you want to choose Desserts enter 3 : ";
			cin >> a;
			if (a == 1)
			{
				cout << "Drinks : " << endl;
				cout << "Chocolate Shake(Rs 100)" << endl;
				cout << "Pineapple shake(Rs 100)  " << endl;
				cout << "Strawberry shake(Rs 100) " << endl;
				cout << "Pepsi(Rs 100) " << endl;
				cout << "7up(Rs 100)" << endl;
				cout << "Mirinda(Rs 100)" << endl;
				bill = bill + 100;
			}
			char b;
			if (a == 2)
			{
				cout << "\t\tFast Food " << endl;
				cout << " If you want to order zinger press a\n If you want to order vegetable pizza enter b\n If you want to choose french fries enter c\n If you want to choose chicken pizza enter e\n If you want to choose hamburgers enter f\n If you want to choose hot dog enter g" << endl;
				cin >> b;
				if (b == 'a')
				{
					cout << " Zinger(Rs 200)  " << endl;
					bill = bill + 200;

				}
				if (b == 'c')
				{
					cout << " Vegetable pizza(Rs 1000) " << endl;
					bill = bill + 1000;

				}
				if (b == 'd')
				{
					cout << " French fries(Rs 300)" << endl;
					bill = bill + 300;

				}
				if (b == 'e')
				{
					cout << " Chicken pizza(Rs 1000) " << endl;
					bill = bill + 1000;

				}
				if (b == 'f')
				{
					cout << " Hamburgers(Rs 300) " << endl;
					bill = bill + 300;

				}
				if (b == 'g')
				{
					cout << " Hot Dogs(Rs 200)" << endl;
					bill = bill + 200;


				}
			}
			if (a == 3)
			{
				char choice;
				cout << "Desserts : " << endl;
				cout << "If you want to order ice-cream/pastery/apple pie enter a \n If you want to order Fruit Cocktail enter b\n If you want to choose custard enter c \n If you want to choose pudding enter d";
				cin >> choice;
				if (choice == 'a')
				{
					cout << " Ice-cream(Rs 100) " << endl;

					bill = bill + 100;
					menu = "icecream";
				}
				if (choice == 'b')
				{
					cout << " Fruit Cocktail(Rs 150)" << endl;
					bill = bill + 150;
					menu = "Fruit cocktail";
				}
				if (choice == 'c')
				{
					cout << " custard(Rs 200)" << endl;
					bill = bill + 200;
					menu = "custard";
				}
				if (choice == 'd')
				{
					cout << "pudding(Rs 500)" << endl;
					bill = bill + 500;
					menu = "Pudding ";

				}

			}
			cout << "If you want to continue ordering enter y If you are done with your order then enter n : ";
			cin >> x;
		} while (x == 'y');

	}
	void r_bill_cal()
	{
		cout << "BLUE LAGOON Resturant Bill : " << endl;
		cout << "Bill  " << endl;
		cout << "Your bill is : " << bill << endl;
		cout << "Your table no : " << endl;

	}

};
class manager :public employee
{
public:

	manager(string n, string i, string p) :employee(n, i, p)
	{

	}
	void display() {
		cout << "\n -- You entered manager panel -- \n";
	}
	void emp_info()
	{
		cout << "*****you have the authority of adding the employee :******" << endl;
		fstream e;

		e.open("employee.txt", ios::out | ios::app);
		e << endl;
		cout << "Enter name : ";
		cin >> name;
		e << name << endl;
		cout << "Enter id : ";
		cin >> id;
		e << id << endl;
		cout << "Enter phone no : ";
		cin >> phone_no;
		e << phone_no << endl;
		cout << "Enter age : ";
		cin >> age;
		e << age << endl;
		cout << "Enter salary : ";
		cin >> salary;
		e << salary << endl;
		cout << "Enter post : ";
		cin >> post;
		e << post << endl;
	}
	void search_emp()
	{
		fstream h;
		h.open("employee.txt", ios::in);

		//we are getting cin in p
		string p;
		string l;
		string ph;
		int ag;
		string po;
		int sal;
		//n is for searching employe by name in file
		string n;
		int y = 0;
		cout << "ENter the employee name which you want to find in the file : ";
		cin >> p;
		getline(h, n);

		while (!h.eof())
		{

			getline(h, n);
			if (p == n)
			{
				cout << n << endl;
				h >> l;
				cout << l << endl;
				h >> ph;
				cout << ph << endl;
				h >> ag;
				cout << ag << endl;
				h >> sal;
				cout << sal << endl;
				h >> po;
				cout << po << endl;
				break;
			}

		}
	}
	void cancel_book()
	{
		fstream cb("guest.txt", ios::in);
		fstream c("newfile.txt", ios::out);
		string n;
		string input;
		string i;
		string pn;
		string f;
		string no;
		string p;
		cout << "Enter the name of guest who want to cancel their online booking : ";
		cin >> input;
		cb >> n;
		cb >> i;
		cb >> pn;
		cb >> f;
		cb >> no;
		cb >> p;
		while (!cb.eof())
		{
			if (n != input)
			{
				c << n << endl;
				c << i << endl;
				c << pn << endl;
				c << f << endl;
				c << no << endl;
				c << p << endl;
			}
			cb >> n;
			cb >> i;
			cb >> pn;
			cb >> f;
			cb >> no;
			cb >> p;
		}
		c.close();
		cb.close();
		remove("guest.txt");
		rename("newfile.txt", "guest.txt");

	}

};
int main()
{
	cout << "***********WELCOME TO THE FHM HOTEL*************" << endl;
	cout << endl;
	int k;
	int x;
	do
	{
		cout << "Enter 1 if you are an employee\n Enter 2 if you are a guest\n Enter 3 if you are the manager \n Enter 4 for a resturant" << endl;
		cin >> k;
		string n;
		string i;
		string p;
		//we are searching an employee :
		if (k == 1)
		{
			employee e1("null", "null", "null");
			e1.display();

			int s;
			cout << "Enter 1 for searching employee and 2 for salary_calculator : ";
			cin >> s;
			if (s == 1)
			{
				e1.emp_search();
			}
			if (s == 2)
			{
				e1.salary_cal();
			}


		}
		int nd;
		int fm;
		if (k == 2)
		{
			guest g1("null", "nill", "null", 0, 0, 0);
			g1.display();
			cout << "*******PACKAGES*******" << endl;
			cout << endl;
			cout << "WE HAVE TWO PACKAGES: " << endl;
			cout << endl;
			cout << "Big package:    \t\t Small package :\n " << endl;
			cout << "2 floors       \t\t\t 1 floor " << endl;
			cout << "2 rooms on each floor \t\t 2 rooms on 1 floor " << endl;
			cout << "Kitchen with hall \t\t Small Kitchen" << endl;
			cout << "Price:40,000(per day) \t\t  Price:20,000(per day)" << endl;
			cout << endl;


			g1.guest_onlinebook();

		}
		if (k == 3)
		{
			int m;
			manager m1("null", "null", "null");
			m1.display();
			cout << "If you want to add an employee enter 1 :\n If you want to search an employee enter 2 \n If you want to search a guest enter 3\n If you want to cancel the booking of a guest enter 4 " << endl;
			cin >> m;
			if (m == 1)
			{
				m1.emp_info();
			}
			if (m == 2)
			{
				m1.search_emp();
			}
			if (m == 3)
			{
				guest g2("null", "null", "null", 0, 0, 0);
				g2.bill_payment();
			}
			if (m == 4)
			{
				m1.cancel_book();
			}


		}
		if (k == 4)

		{
			string n;
			string a;
			string b;
			string k;
			restaurant r1(n, a, b);
			r1.display();
			cout << "enter your name : ";
			cin >> n;
			cout << "enter CNIC : ";
			cin >> a;
			cout << "enter phone no : ";
			cin >> b;

			r1.r_menu();
			r1.r_bill_cal();
		}

		cout << "If you want to continue enter 1 \n If you want to exist enter 0 : ";
		cin >> x;
	} while (x != 0);
	system("pause");
}

