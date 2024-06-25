Overview
The code implements a simple phone book application using a class in C++. It allows you to add, display, search, and update entries in the phone book. You can also copy the phone book to another and clear it.

Key Parts
Class Definition: PhoneBook

Attributes:
Arrays to store names and phone numbers.
An integer to store the size of the phone book.
Methods:
setSize(int size): Initializes the phone book with a given size.
addEntry(string name, string phone): Adds a name and phone number to the phone book.
displayAll(): Displays all entries in the phone book.
findByName(string name): Finds entries that contain the specified name.
findByPhone(string phone): Finds the name associated with a given phone number.
displayEntryAtIndex(int index): Displays the entry at a specified index.
updateNameAt(string newname, int index): Updates the name at a specified index.
updatePhoneAt(string newphone, int index): Updates the phone number at a specified index.
copyPB(const PhoneBook& obj1): Copies the current phone book to another.
clear(): Clears the phone book by deallocating memory.
Main Function

Initialization:
Prompts the user to enter the size of the phone book.
Creates a PhoneBook object and sets its size.
Allows the user to input names and phone numbers.
User Interaction Loop:
Provides a menu for the user to choose different actions:
Display all entries.
Search by name.
Search by phone number.
Display an entry by index.
Update a name by index.
Update a phone number by index.
Copy the phone book to a new phone book.
Exit and clear the phone book.
Example Usage
User enters the size of the phone book.
User adds entries: For example, names and phone numbers.
User chooses actions from the menu:
Display all entries to see the entire phone book.
Search for a specific name or phone number.
Update an entry.
Copy the phone book to another and display the new one.
Exit the application.
Summary
The code provides a simple way to manage a phone book using an array-based approach. It includes functionalities to add, search, display, update, and copy phone book entries.





