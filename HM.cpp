#include <iostream>
using namespace std;

struct Node {
    int patientid;
    string patientname;
    int patientage;
    Node* next;
};

Node* CreatePatient(int id, string name, int age) {
    Node* patient = new Node;
    patient->patientid = id;
    patient->patientname = name;
    patient->patientage = age;
    patient->next = nullptr;

    return patient; 
}

Node* InsertPatientAtEnd(Node* Head, int id, string name, int age) {
    Node* newPatient = CreatePatient(id, name, age);
    if (Head == nullptr) {
        return newPatient;
    }
    Node* temp = Head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newPatient;

    return Head;
}

Node* DeletePatientAtStart(Node* Head) {
    if (Head == nullptr) {
        cout << "Queue is empty.\n";
        return nullptr;
    }
    Node* temp = Head;
    Head = Head->next;
    cout << "Patient examined and removed: " << temp->patientname << "\n";
    delete temp;

    return Head;
}

Node* MovePatientUp(Node* Head, int id) {
    if (!Head || !Head->next) {
        return Head;
    }

    Node* temp = nullptr;
    Node* curr = Head;

    while (curr->next && curr->next->patientid != id) {
        temp = curr;
        curr = curr->next;
    }
    
    if (!(curr->next) || curr->next->patientid != id) {
        cout << "Patient not found or already at front!\n";
        return Head;
    }

    Node* toMove = curr->next;
    curr->next = toMove->next;  

    toMove->next = Head;
    Head = toMove;

    cout << "Patient " << toMove->patientname << " moved to front of queue!\n";

    return Head;
}

void DisplayQueue(Node* Head) {
    if (!Head) { 
        cout << "Queue empty!\n"; 
        return; 
    }

    Node* temp = Head;
    cout << "Current Patient Queue:\n";

    while (temp) {
        cout << "[ID:" << temp->patientid << " | Name:" << temp->patientname << " | Age:" << temp->patientage << "] -> ";
        temp = temp->next;
    }
    cout << "END\n";
}

Node* SearchPatient(Node* Head, int id) {
    Node* temp = Head;

    while (temp) {
        if (temp->patientid == id) {
            cout << "Found patient: " << temp->patientname << " (age " << temp->patientage << ")\n";
            return temp;
        }
        temp = temp->next;
    }
    cout << "Patient ID " << id << " not found.\n";

    return nullptr;
}

void UpdatePatient(Node* Head, int id) {
    Node* patient = SearchPatient(Head, id);
    if (!patient) {
        return;
    }
    cout << "Enter new name (current: " << patient->patientname << "): ";
    cin >> patient->patientname;
    cout << "Enter new age (current: " << patient->patientage << "): ";
    cin >> patient->patientage;
    cout << endl;
    cout << "Patient info updated." << endl;
}

int main() {
    Node* Head = nullptr;

    int choice, id, age;
    string name;

    while (true) {
        cout << "\n----- Menu -----\n";
        cout << "1. Add patient\n";
        cout << "2. Remove patient (doctor examines)\n";
        cout << "3. Move patient up (priority)\n";
        cout << "4. Display queue\n";
        cout << "5. Search patient\n";
        cout << "6. Update patient\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Patient ID: "; 
                cin >> id;
                cout << "Name: "; 
                cin >> name;
                cout << "Age: ";
                cin >> age;

                Head = InsertPatientAtEnd(Head, id, name, age);
                break;
            case 2:
                Head = DeletePatientAtStart(Head);
                break;
            case 3:
                cout << "Enter patient ID to move up: ";
                cin >> id;
                Head = MovePatientUp(Head, id);
                break;
            case 4:
                DisplayQueue(Head);
                break;
            case 5:
                cout << "Enter patient ID to search: ";
                cin >> id;
                SearchPatient(Head, id);
                break;
            case 6:
                cout << "Enter patient ID to update: ";
                cin >> id;
                UpdatePatient(Head, id);
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
