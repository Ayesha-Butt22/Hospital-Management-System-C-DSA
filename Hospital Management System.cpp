#include<iostream>
#include<string>
#include <cstdlib> //for using exit(0) as exiting option
#include <windows.h> //for using pink text

using namespace std;

void MainModuleMenu();
struct Doctor {
    int id;
    string name;
    string specialty;
    string address;
    string contactNumber;
    string email;
    Doctor* next;
};


struct Patient
 {
    string First_name;
    string Last_name;
    int age;
    string gender;
    string Contact_No;
    string Email;
    string problem;
};

// Node structure for the linked list
struct Node 
{
    Patient data;
    Node* next;
};
/////ayesha department
// Deprt structure
struct Deprt {
    int deprtId;
    string deprtName;
    Deprt* next;
};
////bisma raza staff stuct class
class Staff {
public:
    string name;
    int employeeNumber;
    Staff* next;

    
    Staff(string n, int empNum){
        name = n;
        employeeNumber = empNum;
        next  = NULL; 
        
        }
};
//ZUBAIDA #05
struct Item {
    string name;
    int quantity;
    Item* next;
};
//  #06
// Define structures for linked lists
struct BillingNode {
    int billId;
    string patientName;
    double totalAmount;
    BillingNode* next;

    BillingNode(int id, string name, double amount) {
    	billId=id;
		patientName=name;
		totalAmount=amount;
		next=NULL;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////module#01///////////////////////////////////

// Function to log in as a user (Patient, Doctor, or Staff Member)
bool loginUser(const string& username, const string& password, const int& userId, const string& userType) {
	string enteredUsername, enteredPassword;
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\tLOGIN"<<endl<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\tEnter " << userType << " username: ";
	cin >> enteredUsername;
	cout << "\t\t\t\t\t\t\t\t\t\t\tEnter " << userType << " password: ";
	cin >> enteredPassword;

	// Check if the entered credentials match the registered user
	if (enteredUsername == username && enteredPassword == password) {
		cout << userType << " login successful. Welcome, " << userType << " ID: " << userId << endl;
		return true;
	} else {
		cout << "Invalid username or password. " << userType << " login failed." << endl;
		return false;
	}
}



/////////////////////////////////////////////////////////doctors module///////////////////////////////////////////////////////////
Doctor* createDoctor(int id, string name, string specialty, string address, string contactNumber, string email) {
    Doctor* doctor = new Doctor;
    doctor->id = id;
    doctor->name = name;
    doctor->specialty = specialty;
    doctor->address = address;
    doctor->contactNumber = contactNumber;
    doctor->email = email;
    doctor->next = NULL;
    return doctor;
}

Doctor* addDoctor(Doctor* head, int id, string name, string specialty, string address, string contactNumber, string email) {
    Doctor* doctor = createDoctor(id, name, specialty, address, contactNumber, email);
    if (!head) {
        head = doctor;
    } else {
        Doctor* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = doctor;
    }
    return head;
}

void displayDoctors(Doctor* head) {
    if (!head) {
        cout << "Doctor list is empty." << endl;
        return;
    }
    cout << "List of Doctors: " << endl;
    Doctor* current = head;
    while (current) {
        cout << "Doctor ID: " << current->id << ", Name: " << current->name << ", Specialty: " << current->specialty << endl;
        cout << "Address: " << current->address << ", Contact Number: " << current->contactNumber << ", Email: " << current->email << endl;
        current = current->next;
    }
}

Doctor* updateDoctor(Doctor* head, int id, string name, string specialty, string address, string contactNumber, string email) {
    Doctor* current = head;
    while (current && current->id != id) {
        current = current->next;
    }
    if (current) {
        current->name = name;
        current->specialty = specialty;
        current->address = address;
        current->contactNumber = contactNumber;
        current->email = email;
        cout << "Doctor details updated successfully." << endl;
    } else {
        cout << "Doctor not found with ID: " << id << endl;
    }
    return head;
}

void viewDoctor(Doctor* head, int id) {
    Doctor* current = head;
    while (current && current->id != id) {
        current = current->next;
    }
    if (current) {
        cout << "Details of Doctor ID " << id << ":" << endl;
        cout << "Name: " << current->name << ", Specialty: " << current->specialty << endl;
        cout << "Address: " << current->address << ", Contact Number: " << current->contactNumber << ", Email: " << current->email << endl;
    } else {
        cout << "Doctor not found with ID: " << id << endl;
    }
}
///////////////////////////////////////////////END OF DOCTOR MODULE///////////////////////////////////////////////////////////////////

// Head pointer for the linked list
Node* head = NULL;

void addRecord() {
    cout << "\n\n\n*ADD PATIENT RECORD*\n";
    Patient p;
    cout << "Enter First_Name :" << endl;
    cin >> p.First_name;
    cout << "Enter Last_Name :" << endl;
    cin >> p.Last_name;
    cout << "Enter age :" << endl;
    cin >> p.age;
    cout << "Enter gender :" << endl;
    cin >> p.gender;
    cout << "Enter Contact_Number :" << endl;
    cin >> p.Contact_No;
    cout << "Enter Email : " << endl;
    cin >> p.Email;
    cout << "Enter you Problem :" << endl;
    cin >> p.problem;

    // Create a new node for the linked list
    Node* newNode = new Node{ p, NULL };

    // If the list is empty, set the new node as the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse to the end of the list and append the new node
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void listRecords() {
    cout << "\n\n\n*LIST PATIENT RECORD*\n";

    if (head == NULL) {
        cout << "No patient records available.\n";
    } else {
        cout << "--------------------------------------------------------------------------------------\n";
        cout << "  First Name  |  Last Name  |  Age  |  Gender  |  Contact Number  |  Email  |  Problem\n";
        cout << "--------------------------------------------------------------------------------------\n";

        Node* current = head;
        while (current != NULL) {
            cout << "  " << current->data.First_name << "          " << current->data.Last_name << "          " << current->data.age << "       " << current->data.gender << "          " << current->data.Contact_No << "          " << current->data.Email << "          " << current->data.problem << "\n";
            current = current->next;
        }
    }
}

void searchRecord() {
    if (head == NULL) {
        cout << "No patient records available for searching.\n";
        return;
    }

    string searchName;
    cout << "Enter the First Name to search for: ";
    cin >> searchName;

    bool found = false;

    cout << "\n\n*SEARCH RESULTS*\n";
    cout << "--------------------------------------------------------------\n";
    cout << "  First Name  |  Last Name  |  Age  |  Gender  |  Contact Number  |  Email  |  Problem\n";
    cout << "--------------------------------------------------------------\n";

    Node* current = head;
    while (current != NULL) {
        if (current->data.First_name == searchName) {
            // Display the matching record
            cout << "  " << current->data.First_name << "          " << current->data.Last_name << "          " << current->data.age << "       " << current->data.gender << "          " << current->data.Contact_No << "          " << current->data.Email << "          " << current->data.problem << "\n";
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Patient with the given First Name not found.\n";
    }
}

void updateRecord() {
    if (head == NULL) {
        cout << "No patient records available for updating.\n";
        return;
    }

    string updateName;
    cout << "Enter the First Name of the patient to update: ";
    cin >> updateName;

    bool found = false;

    Node* current = head;
    while (current != NULL) {
        if (current->data.First_name == updateName) {
            // Display the current information of the patient
            cout << "\nCurrent Information for " << current->data.First_name << ":\n";
            cout << "  First Name  |  Last Name  |  Age  |  Gender  |  Contact Number  |  Email  |  Problem\n";
            cout << "  " << current->data.First_name << "          " << current->data.Last_name << "          " << current->data.age << "       " << current->data.gender << "          " << current->data.Contact_No << "          " << current->data.Email << "          " << current->data.problem << "\n";

            // Update patient information
            cout << "\nEnter updated information:\n";
            cout << "Enter Last_Name: ";
            cin >> current->data.Last_name;
            cout << "Enter age: ";
            cin >> current->data.age;
            cout << "Enter gender: ";
            cin >> current->data.gender;
            cout << "Enter Contact_Number: ";
            cin >> current->data.Contact_No;
            cout << "Enter Email: ";
            cin >> current->data.Email;
            cout << "Enter Problem: ";
            cin >> current->data.problem;

            cout << "\nPatient record updated successfully!\n";
            found = true;
            break;  // Stop searching once a match is found
        }
        current = current->next;
    }

    if (!found) {
        cout << "Patient with the given First Name not found.\n";
    }
}

void deleteRecord() {
    if (head == NULL) {
        cout << "No patient records available for deletion.\n";
        return;
    }

    string deleteName;
    cout << "Enter the First Name of the patient to delete: ";
    cin >> deleteName;

    bool found = false;

    // If the matching record is at the head of the list
    if (head->data.First_name == deleteName) {
        Node* temp = head;
        head = head->next;
        delete temp;
        found = true;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            if (current->next->data.First_name == deleteName) {
                // Display the information of the patient to be deleted
                cout << "\nInformation for " << current->next->data.First_name << " to be deleted:\n";
                cout << "  First Name  |  Last Name  |  Age  |  Gender  |  Contact Number  |  Email  |  Problem\n";
                cout << "  " << current->next->data.First_name << "          " << current->next->data.Last_name << "          " << current->next->data.age << "       " << current->next->data.gender << "          " << current->next->data.Contact_No << "          " << current->next->data.Email << "          " << current->next->data.problem << "\n";

                // Confirm deletion with user
                char confirm;
                cout << "Do you want to delete this record? (Y/N): ";
                cin >> confirm;

                if (confirm == 'Y' || confirm == 'y') {
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;

                    cout << "\nPatient record deleted successfully!\n";
                } else {
                    cout << "\nDeletion canceled.\n";
                }

                found = true;
                break;  // Stop searching once a match is found
            }
            current = current->next;
        }
    }

    if (!found) {
        cout << "Patient with the given First Name not found.\n";
    }
}

void exitProgram() {
    // Free memory for all nodes in the linked list
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    exit(0);
}
///////////////////////////////////////////////////////////////////////END OF PATIENT MODULE////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////    MODULE#03   ////////////////////////////////////////////
// Function to display all departments in the linked list
void displayDeprt(const Deprt* head) {
    cout << "\nDepartment List:\n";
    const Deprt* current = head;
    while (current != NULL) {
        cout << "Department ID: " << current->deprtId << "\tName: " << current->deprtName << endl;
        current = current->next;
    }
}

// Function to add a new department to the linked list
void addDeprt(Deprt*& head, int& deprtId) {
    Deprt* newDeprt = new Deprt;
    newDeprt->deprtId = ++deprtId;

    cout << "Enter department name: ";
    cin >> newDeprt->deprtName;

    newDeprt->next = head;
    head = newDeprt;

    cout << "\nDepartment added successfully. Department ID: " << newDeprt->deprtId << endl;
}

// Function to delete a department from the linked list
void deleteDeprt(Deprt*& head) {
    int deprtId;
    cout << "Enter the department ID to delete: ";
    cin >> deprtId;

    Deprt* current = head;
    Deprt* prev = NULL;

    while (current != NULL && current->deprtId != deprtId) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Department not found.\n";
        return;
    }

    if (prev == NULL) {
        // If the department to be deleted is the head
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    cout << "Department deleted successfully. Department ID: " << deprtId << endl;
}

// Function to update a department's information in the linked list
void updateDeprt(Deprt* head) {
    int deprtId;
    cout << "Enter the Department ID to update: ";
    cin >> deprtId;

    Deprt* current = head;
    while (current != NULL && current->deprtId != deprtId) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Department not found.\n";
        return;
    }

    cout << "Enter new Department name: ";
    cin >> current->deprtName;

    cout << "Department updated successfully. Department ID: " << deprtId << endl;
}

// Function to view a department's information in the linked list
void viewDeprt(const Deprt* head) {
    int deprtId;
    cout << "Enter the Department ID to view: ";
    cin >> deprtId;

    const Deprt* current = head;
    while (current != NULL && current->deprtId != deprtId) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Department not found.\n";
        return;
    }

    cout << "Department ID: " << current->deprtId << "\tName: " << current->deprtName << endl;
}

Doctor* deleteDoctor(Doctor* head, int id) {
    Doctor* current = head;
    Doctor* previous = NULL;

    // Search for the doctor to delete
    while (current && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current) {
        // Doctor found, now remove it from the linked list
        if (previous) {
            // If not the first element
            previous->next = current->next;
        } else {
            // If it's the first element, update the head
            head = current->next;
        }

        // Free the memory allocated for the deleted doctor
        delete current;

        cout << "Doctor with ID " << id << " deleted successfully." << endl;
    } else {
        cout << "Doctor not found with ID: " << id << endl;
    }

    return head;
}

///////////////////////////////////////////////////////////////////////   END OF AYESHA ASAD DEPARTMENT MODULE  ////////////////////////////////////////////
class StaffList {
private:
    Staff* head;

public:
   
    StaffList(){
        head = NULL;
    }

  
    ~StaffList() {
        while (head != NULL) {
            Staff* temp = head;
            head = head->next;
            delete temp;
        }
    }

  
    void createStaff(string name, int employeeNumber) {
        Staff* newStaff = new Staff(name, employeeNumber);
        newStaff->next = head;
        head = newStaff;
    }

    
    void displayAllStaff() {
        Staff* current = head;
        cout << "Staff List:" << endl;
        while (current != NULL) {
            cout << "Name: " << current->name << ", Employee Number: " << current->employeeNumber << endl;
            current = current->next;
        }
        cout << endl;
    }

   
    void updateStaff() {
        int empNum;
        cout << "Enter the employee number to update: ";
        cin >> empNum;

        Staff* current = head;
        while (current != NULL) {
            if (current->employeeNumber == empNum) {
                cout << "Enter the new name in replacement for " << current->name << ": ";
                cin >> current->name;
                cout << "Information updated successfully." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Employee number not found." << endl;
    }

   
    void deleteStaff() {
        int empNum;
        cout << "Enter the employee number to delete: ";
        cin >> empNum;

        Staff* current = head;
        Staff* prev = NULL;

        while (current != NULL) {
            if (current->employeeNumber == empNum) {
                if (prev == NULL) {
                    // If the target node is the head
                    head = current->next;
                } else {
                    prev->next = current->next;
                }

                delete current;
                cout << "Staff deleted successfully." << endl;
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "Employee number not found." << endl;
    }
};
///////////////////////////////////////////////////////////////////////   END OF BISMA RAZA Staff MODULE  ////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////    MODULE#05   ////////////////////////////////////////////
class InventoryManagement {
private:
    Item* head;

public:
    InventoryManagement() {
        head = NULL;
    }

    // Function to add an item to the inventory
    void addItem(string name, int quantity) {
        Item* newItem = new Item;
        newItem->name = name;
        newItem->quantity = quantity;
        newItem->next = NULL;

        if (head == NULL) {
            head = newItem;
        } else {
            Item* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newItem;
        }
        cout << "Item added successfully." << endl;
    }

    // Function to check stock levels of an item
    void checkStock(string name) {
        Item* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->name == name) {
                found = true;
                cout << "Item: " << temp->name << " | Quantity in stock: " << temp->quantity << endl;
                if (temp->quantity <= 10) {
                    cout << "Low stock alert! Please consider restocking." << endl;
                }
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Item not found in inventory." << endl;
        }
    }

    // Function to manage orders for an item
    void manageOrder(string name, int quantity) {
        Item* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->name == name) {
                found = true;
                temp->quantity += quantity;
                cout << "Order managed successfully. Updated stock for " << temp->name << ": " << temp->quantity << endl;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Item not found in inventory. Cannot manage order." << endl;
        }
    }

    // Function to display options menu
    void displayMenu() {
       cout << "\nMain Menu: " << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Check Stock" << endl;
        cout << "3. Manage Order" << endl;
        cout << "4. Back" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
    }
};
/////////////////////////////////////////////////////END OF INVENTARY MANAGEMENT//////////////////////////////////////////////////
// Function to add a new billing record
void addBillingRecord(BillingNode*& head, int billId, string patientName, double totalAmount) {
    BillingNode* newNode = new BillingNode(billId, patientName, totalAmount);

    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    cout << "Billing record added successfully." << endl;
}

// Function to display all billing records
void displayBillingRecords(BillingNode* head) {
    BillingNode* current = head;

    if (!current) {
        cout << "No billing records available." << endl;
        return;
    }

    cout << "Billing Records:" << endl;
    while (current) {
        cout << "Bill ID: " << current->billId << ", Patient Name: " << current->patientName
            << ", Total Amount: " << current->totalAmount << endl;
        current = current->next;
    }
}

// Function to find a billing record by Bill ID
BillingNode* findBillingRecord(BillingNode* head, int billId) {
    BillingNode* current = head;
    while (current && current->billId != billId) {
        current = current->next;
    }
    return current;
}

// Function to update a billing record by Bill ID
void updateBillingRecord(BillingNode* head, int billId, string patientName, double totalAmount) {
    BillingNode* recordToUpdate = findBillingRecord(head, billId);

    if (recordToUpdate) {
        recordToUpdate->patientName = patientName;
        recordToUpdate->totalAmount = totalAmount;
        cout << "Billing record updated successfully." << endl;
    } else {
        cout << "Billing record not found." << endl;
    }
}

// Function to delete a billing record by Bill ID
void deleteBillingRecord(BillingNode*& head, int billId) {
    BillingNode* current = head;
    BillingNode* prev = NULL;

    while (current && current->billId != billId) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
        cout << "Billing record deleted successfully." << endl;
    } else {
        cout << "Billing record not found." << endl;
    }
}
///////////////////////////////////////////////////END OF MODULE #6///////////////////////////////////////////////////////

void manageDoctors() {
    // Doctor module
    Doctor* doctorList = NULL;
    int doctorId = 1;

    while (true) {
        cout << "\nMain Menu: " << endl;
        cout << "1. Add Doctor" << endl;
        cout << "2. Display Doctors" << endl;
        cout << "3. Update Doctor" << endl;
        cout << "4. View Doctor" << endl;
        cout << "5. Delete Doctor" << endl;
        cout << "6. Back" << endl;
        cout << "7. Exit" <<endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, specialty, address, contactNumber, email;
                cout << "Enter Doctor Name: ";
                cin >> name;
                cout << "Enter Doctor Specialty: ";
                cin >> specialty;
                cout << "Enter Doctor Address: ";
                cin >> address;
                cout << "Enter Doctor Contact Number: ";
                cin >> contactNumber;
                cout << "Enter Doctor Email: ";
                cin >> email;
                doctorList = addDoctor(doctorList, doctorId++, name, specialty, address, contactNumber, email);
                break;
            }

            case 2: {
                displayDoctors(doctorList);
                break;
            }

            case 3: {
                int id;
                string name, specialty, address, contactNumber, email;
                cout << "Enter Doctor ID to update: ";
                cin >> id;
                cout << "Enter updated Name: ";
                cin >> name;
                cout << "Enter updated Specialty: ";
                cin >> specialty;
                cout << "Enter updated Address: ";
                cin >> address;
                cout << "Enter updated Contact Number: ";
                cin >> contactNumber;
                cout << "Enter updated Email: ";
                cin >> email;
                doctorList = updateDoctor(doctorList, id, name, specialty, address, contactNumber, email);
                break;
            }

            case 4: {
                int id;
                cout << "Enter Doctor ID to view: ";
                cin >> id;
                viewDoctor(doctorList, id);
                break;
            }

            case 5: {
                int id;
                cout << "Enter Doctor ID to delete: ";
                cin >> id;
                doctorList = deleteDoctor(doctorList, id);
                break;
            }

			case 6: {
                MainModuleMenu();
            }
            case 7: {
                cout << "Exiting program." << endl;
                exit(0);
            }

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
}

void managePatients() {
    // Patient module
    int choice;
    do {
        cout << "\nMain Menu: " << endl;
        cout << "1. Add Patient Record" << endl;
        cout << "2. List patient Record" << endl;
        cout << "3. Search Patient Record" << endl;
        cout << "4. Update Patient Record" << endl;
        cout << "5. Delete Patient Record" << endl;
        cout << "6. Back" << endl;
        cout << "7. Exit" << endl;

        cout << "Choose (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord(); // Call the function to add a patient record
                break;

            case 2:
                listRecords(); // Call the function to list patient records
                break;

            case 3:
                searchRecord(); // Call the function to search for a patient record
                break;

            case 4:
                updateRecord(); // Call the function to update a patient record
                break;

            case 5:
                deleteRecord(); // Call the function to delete a patient record
                break;

            case 6:
            	MainModuleMenu();
                break;
			case 7:
				exitProgram();
				break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (true);
}

void manageDepartments() {
    // Department module
    Deprt* deprtList = NULL;
    int deprtId = 0;  // Counter for department IDs

    while (true) {
        int deprtOption;
        cout << "\nMain Menu: " << endl;
        cout << "1. Add Department\n";
        cout << "2. Delete Department\n";
        cout << "3. Update Department\n";
        cout << "4. View Department\n";
        cout << "5. Display All Departments\n";
        cout << "6. Back to Main Menu\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> deprtOption;

        switch (deprtOption) {
            case 1:
                addDeprt(deprtList, deprtId);
                break;
            case 2:
                deleteDeprt(deprtList);
                break;
            case 3:
                updateDeprt(deprtList);
                break;
            case 4:
                viewDeprt(deprtList);
                break;
            case 5:
                displayDeprt(deprtList);
                break;
            
            case 6:
            	MainModuleMenu();
                break;
			case 7:
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }

    // Clean up the allocated memory for the linked list
    Deprt* current = deprtList;
    Deprt* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
}

void manageStaff() {
    // Staff module
    StaffList staffList;

    while (true) {
        cout << "Main Menu\n1. Add Staff\n2. Display Staff Data\n3. Update Staff Information\n4. Delete Staff information\n5. back\n6. Exit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int empNum;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter employee number: ";
                cin >> empNum;
                staffList.createStaff(name, empNum);
                break;
            }
            case 2:
                staffList.displayAllStaff();
                break;
            case 3:
                staffList.updateStaff();
                break;
            case 4:
                staffList.deleteStaff();
                break;
            
            case 5:
            	MainModuleMenu();
            	break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

void manageInventory() {
    // Inventory module
    InventoryManagement inventory;

    char choice;
    do {
        inventory.displayMenu();
        cin >> choice;

        switch (choice) {
            case '1': {
                string itemName;
                int itemQuantity;

                cout << "Enter Item Name: ";
                cin >> itemName;
                cout << "Enter Item Quantity: ";
                cin >> itemQuantity;

                inventory.addItem(itemName, itemQuantity);
                break;
            }
            case '2': {
                string itemName;
                cout << "Enter Item Name to Check Stock: ";
                cin >> itemName;

                inventory.checkStock(itemName);
                break;
            }
            case '3': {
                string itemName;
                int orderQuantity;

                cout << "Enter Item Name for Order: ";
                cin >> itemName;
                cout << "Enter Quantity for Order: ";
                cin >> orderQuantity;

                inventory.manageOrder(itemName, orderQuantity);
                break;
            }
			case '4':
            	MainModuleMenu();
            	break;
            case '5':
                cout << "Exiting Inventory Management System." << endl;
                exit(0);
                break;
            
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != '4');
}

void manageBilling() {
    // Billing and Payment module
    // Initialize linked lists for billing records
    BillingNode* billingRecords = NULL;

    while (true) {
        // Billing and Payment Menu
        cout << "\nMain Menu: " << endl;
        cout << "1. Add Billing Record\n";
        cout << "2. Display Billing Records\n";
        cout << "3. Update Billing Record\n";
        cout << "4. Delete Billing Record\n";
        cout << "5. Back\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Test data
                int billId;
                string patientName;
                double totalAmount;

                // Ask the user for billing record values
                cout << "Enter Billing Record Information:" << endl;
                cout << "Enter Bill ID: ";
                cin >> billId;

                cout << "Enter Patient Name: ";
                cin.ignore(); // Ignore newline left in the buffer
                getline(cin, patientName);

                cout << "Enter Total Amount: ";
                cin >> totalAmount;

                // Add billing record
                addBillingRecord(billingRecords, billId, patientName, totalAmount);

                // Display billing records
                displayBillingRecords(billingRecords);
                break;
            }
            case 2:
                // Display billing records
                displayBillingRecords(billingRecords);
                break;
            case 3: {
                // Update billing record
                int updateId;
                cout << "Enter Bill ID to update: ";
                cin >> updateId;

                string updatedPatientName;
                double updatedTotalAmount;

                cout << "Enter updated Patient Name: ";
                cin.ignore();
                getline(cin, updatedPatientName);

                cout << "Enter updated Total Amount: ";
                cin >> updatedTotalAmount;

                updateBillingRecord(billingRecords, updateId, updatedPatientName, updatedTotalAmount);

                // Display billing records
                displayBillingRecords(billingRecords);
                break;
            }
            case 4: {
                // Delete billing record
                int deleteId;
                cout << "Enter Bill ID to delete: ";
                cin >> deleteId;

                deleteBillingRecord(billingRecords, deleteId);

                // Display billing records
                displayBillingRecords(billingRecords);
                break;
            }
            case 5:
                MainModuleMenu();
                return;
            case 6:
                exit(0);
                return;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }
}

void MainModuleMenu(){
	int AdminModuleChoice;
    //cout << "Admin Modules:\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n";
    cout << "\t\t\t\t\t\t\t\t\t\t1. Manage Doctors\n";
    cout << "\t\t\t\t\t\t\t\t\t\t2. Manage Patients\n";
    cout << "\t\t\t\t\t\t\t\t\t\t3. Manage Departments\n";
    cout << "\t\t\t\t\t\t\t\t\t\t4. Manage Staff\n";
    cout << "\t\t\t\t\t\t\t\t\t\t5. Inventory Management\n";
    cout << "\t\t\t\t\t\t\t\t\t\t6. Billing and Payment\n";
    cout << "\t\t\t\t\t\t\t\t\t\t7. Exit\n";
    cout << "\t\t\t\t\t\t\t\t\t\tEnter your choice: ";
    cin >> AdminModuleChoice;
	system("cls");
    switch (AdminModuleChoice) {
        case 1:
            manageDoctors();
            break;
        case 2:
            managePatients();
            break;
        case 3:
            manageDepartments();
            break;
        case 4:
            manageStaff();
            break;
        case 5:
            manageInventory();
            break;
        case 6:
            manageBilling();
            break;
        case 7:
            cout << "Exiting program.\n";
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
    }
}

int main() {
    system("Color 0D");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("Color 0D"); // 0 is for black and D is for purple color
	cout << "\t\t *       *  * * * * *  *             * * *     * * *    * *      * *  * * * * *  \n";
	cout << "\t\t *       *  *          *           *         *      *   *  *    *  *  *          \n";
	cout << "\t\t *   *   *  * * * *    *          *         *        *  *   *  *   *  * * *      \n";
	cout << "\t\t *  * *  *  *          *           *         *      *   *    *     *  *          \n";
	cout << "\t\t * *   * *  * * * * *  * * * * *     * * *     * * *    *          *  * * * * *  \n";
	cout << "\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
	string Username = "admin";  // Hardcoded doctor username
	string Password = "admin123";  // Hardcoded doctor password
	int Id = 0;  // Counter for doctor IDs
	

    while (true) {
		int mainChoice;		
		system("Color 0D"); // 0 is for black and D is for purple color
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t *       *    * * * *    * * * * *  * * * * *  * * * *  * * * * *   *     *        "<<endl;
		cout << "\t\t\t *       *   *        *  *          *       *     *         *      * *    *        "<<endl;
		cout << "\t\t\t * * * * *  *         *  * * * * *  * * * * *     *         *     *   *   *        "<<endl;
		cout << "\t\t\t *       *   *       *           *  *             *         *    * * * *  *        "<<endl;
		cout << "\t\t\t *       *     * * *     * * * * *  *          * * * *      *   *       * * * * *  "<<endl;
		cout << "\n\n";
		cout << "\t\t\t *       *     *      *     *     *     * * * *   * * * *   *        *   * * * *   *     *  * * * *               choose an option:"<<endl;
		cout << "\t\t\t * *   * *    * *     * *   *    * *    *         *         * *    * *   *         * *   *     *                  1.Login "<<endl;
		cout << "\t\t\t *   *   *   *   *    *  *  *   *   *   *   * *   * * * *   *  *  *  *   * * *     *  *  *     *                  2.Exit "<<endl;
		cout << "\t\t\t *       *  * * * *   *   * *  * * * *  *     *   *         *    *   *   *         *   * *     *                  Enter your choice: "<<endl;
		cout << "\t\t\t *       * *       *  *    ** *       * * * * *   * * * *   *        *   * * * *   *     *     *    ";
		cout << "\n\n";
		cout << "\t\t\t * * * *   *      *   * * * *    *     *  * * * * *     * * * *   * *      * *     \n";
		cout << "\t\t\t *         *      *   *          *     *      *         *         *  *    *  *     \n";
		cout << "\t\t\t  *  * *     *   *    *  *  *      *  *       *         * * * *   *   *  *   *     \n";
		cout << "\t\t\t       *       *             *      *         *         *         *    *     *     \n";
		cout << "\t\t\t *  * *        *      *  *  *       *         *         * * * *   *          *     \n";
		cin >> mainChoice;
		if (mainChoice == 1) {
				bool adminLoggedIn = loginUser("admin", "admin123", Id, "ADMIN");
				if (adminLoggedIn) {
				    while (true) {
				    	system("cls");
				        MainModuleMenu();
				    }
				}
			
			else {
				cout << "Invalid choice. Please enter a valid option.\n";
			}
		} else if (mainChoice == 2) {
			// User chose to exit
			cout << "Exiting program.\n";
			break; // Exit the while loop
		} else {
			cout << "Invalid choice. Please enter a valid option.\n";
		}
	}
    return 0;
}
