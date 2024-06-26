#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class PhoneBook
{
private:
	string* names;
	string* phones;
	int phoneBookSize;
	

public:
	void setSize(int size)
	{
		phoneBookSize = size;
		names = new string[size];
		phones = new string[size];
		for (int i = 0; i < size; i++)
		{
			names[i] = "";
			phones[i] = "";
		}
	}
	bool addEntry(string name, string phone)
	{
		for (int i = 0; i < phoneBookSize; i++)
		{
			if (names[i] == "" && phones[i] == "")
			{
				if (phone.length() == 11)
				{
					if (phone[i] - '0' < 10)
					{
						names[i] = name;
						phones[i] = phone;
						return true;
					}
				}
			}
		}
		return false;
	}
	void copyPB(const PhoneBook& obj1)
	{
		for (int i = 0; i < phoneBookSize; i++)
		{
			obj1.names[i] = names[i];
			obj1.phones[i] = phones[i];
		}
	}
	bool displayEntryAtIndex(int index)
	{
		if (index <= phoneBookSize && index >= 0)
		{
			cout << "name : " << names[index] << "\nphone : " << phones[index] << "\n \n" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	void displayEntryAtIndices(int* display)
	{
		
		for (int i = 0; i < phoneBookSize; i++)
		{
			if (display[i] == 1)
			{
				cout << names[i] << "\t" << phones[i] << endl;
			}
			cout << "\n \n";
		}
	}
	void displayAll()
	{
		cout << "Phone Book entries : " << endl;
		for (int i = 0; i < phoneBookSize; i++)
		{
			cout << names[i] << "\t" << phones[i] << endl;
		}
		cout << "\n \n";

	}
	int* findByName(string name)
	{
		int* finding = new int[phoneBookSize];
		for (int i = 0; i < phoneBookSize; i++)
		{
			finding[i] = 0;
			if (names[i].find(name) != std:: string::npos)
			{
				finding[i] = 1;
			}
		}
		return finding;
	}
	string findByPhone(string phone)
	{
		for (int i = 0; i < phoneBookSize; i++) {
			if (phone == phones[i])
				return names[i];
		}
		return "";
	}
	bool updateNameAt(string newname, int index)
	{
		if (index <= phoneBookSize)
		{
			names[index] = newname;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool updatePhoneAt(string newphone, int index)
	{
		if (index <= phoneBookSize) {
			phones[index] = newphone;
			return true;
		}
		return false;
	}
	void clear()
	{
		delete [] phones;
		delete [] names;
	}
};

int main()
{
	cout << "Enter the Size of Your Phone Book : ";
	int size;
	cin >> size;
	PhoneBook obj1;
	obj1.setSize(size); // new object
	string name,phone;
	for (int i = 0; i < size; i++)  // get inputs
	{
		cin.ignore();
		cout << "Enter name " << i + 1 << " : ";
		getline(cin, name);
		cout << "Enter phone " << i + 1 << " : ";
		cin >> phone;
		obj1.addEntry(name, phone);
	}
	bool z = true;
	while (z)  // loop on choices
	{
		// structure of choices   
		cout << "Enter your choice : \n";
		cout << "1- display all phone book \n2- search for entry/entries by name \n";
		cout << "3- search for entry/entries by phone \n4- find an entry by index \n";
		cout << "5- update a name by index \n6- update a phone by index\n";
		cout << "7- copy phone book to another and display the entries of the new one \n";
		cout << "8- exit \n choice : ";
		int num;
		cin >> num;
		system("cls");
		switch (num)
		{
		case 1: {
			obj1.displayAll();
			break;
		}
		case 2: {
			cout << "Enter the name you want to find : ";
			cin.ignore();
			getline(cin, name);
			int* find;
			find = new int[size];
			find = obj1.findByName(name);
			for (int i = 0; i < size; i++)
			{
				cout << find[i] << " ";
			}
			cout << "\n \n \n";
			delete[]find;
			break;
		}
		case 3: {
			cout << "Enter the number you want to find : ";
			cin >> phone;
			cout << obj1.findByPhone(phone) << "\n \n \n " << endl;
			break;
		}
		case 4: {
			cout << "Enter the index : ";
			int index;
			cin >> index;
			index -= 1;
			obj1.displayEntryAtIndex(index);
			break;
		}
		case 5: {
			cout << "Please enter the name and the index you want to change : ";
			cin.ignore();
			getline(cin, name);
			int index;
			cin >> index;
			index -= 1;
			obj1.updateNameAt(name, index);
			break;
		}
		case 6: {
			cout << "Please enter the phone and the index you want to change : ";
			cin >> phone;
			int index;
			cin >> index;
			index -= 1;
			obj1.updatePhoneAt(phone, index);
			break;
		}
		case 7: {
			PhoneBook obj2;
			obj2.setSize(size);
			obj1.copyPB(obj2);
			cout << "the new ";
			obj2.displayAll();
			break;
		}
		case 8: {
			obj1.clear();
			z = false;
			break;
		}
		default:
			break;
		}
	}
	
	
	//delete[]display;   in case you would like to use display function;
	return 0;
}
