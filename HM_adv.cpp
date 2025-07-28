#include <iostream>
using namespace std;

struct Node {
    int patientid;
    string patientname;
    int patientage;
    string gender;
    string contactnumber;
    string bloodgroup;
    string doctorassigned;
    Node* next;
};

Node* CreatePatient(int id, const string& name, int age, const string& gender, const string& contact, const string& blood, const string& doctor) {
    Node* patient = new Node;
    patient->patientid = id;
    patient->patientname = name;
    patient->patientage = age;
    patient->gender = gender;
    patient->contactnumber = contact;
    patient->bloodgroup = blood;
    patient->doctorassigned = doctor;
    patient->next = nullptr;
    return patient;
}

Node* InsertPatientAtEnd(Node* Head, int id, const string& name, int age, const string& gender, const string& contact, const string& blood, const string& doctor) {
    Node* newPatient = CreatePatient(id, name, age, gender, contact, blood, doctor);
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

    Node* curr = Head;
    while (curr->next && curr->next->patientid != id) {
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
        cout << "[ID:" << temp->patientid
             << " | Name:" << temp->patientname
             << " | Age:" << temp->patientage
             << " | Gender:" << temp->gender
             << " | Contact:" << temp->contactnumber
             << " | Blood Group:" << temp->bloodgroup
             << " | Doctor Assigned:" << temp->doctorassigned << "] -> ";
        temp = temp->next;
    }
    cout << "END\n";
}

Node* SearchPatient(Node* Head, int id) {
    Node* temp = Head;
    while (temp) {
        if (temp->patientid == id) {
            cout << "Found patient:\n";
            cout << "ID: " << temp->patientid << "\n";
            cout << "Name: " << temp->patientname << "\n";
            cout << "Age: " << temp->patientage << "\n";
            cout << "Gender: " << temp->gender << "\n";
            cout << "Contact: " << temp->contactnumber << "\n";
            cout << "Blood Group: " << temp->bloodgroup << "\n";
            cout << "Doctor Assigned: " << temp->doctorassigned << "\n";
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
    cin.ignore(); // clear leftover newline
    getline(cin, patient->patientname);

    cout << "Enter new age (current: " << patient->patientage << "): ";
    cin >> patient->patientage;
    cin.ignore();

    cout << "Enter new gender (current: " << patient->gender << "): ";
    getline(cin, patient->gender);

    cout << "Enter new contact number (current: " << patient->contactnumber << "): ";
    getline(cin, patient->contactnumber);

    cout << "Enter new blood group (current: " << patient->bloodgroup << "): ";
    getline(cin, patient->bloodgroup);

    cout << "Enter new doctor assigned (current: " << patient->doctorassigned << "): ";
    getline(cin, patient->doctorassigned);

    cout << "Patient info updated.\n";
}

int main() {
    Node* Head = nullptr;

    int choice, id, age;
    string name, gender, contact, blood, doctor;

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
                cin.ignore();
                cout << "Name: ";
                getline(cin, name);
                cout << "Age: ";
                cin >> age;
                cin.ignore();
                cout << "Gender: ";
                getline(cin, gender);
                cout << "Contact Number: ";
                getline(cin, contact);
                cout << "Blood Group: ";
                getline(cin, blood);
                cout << "Doctor Assigned: ";
                getline(cin, doctor);

                Head = InsertPatientAtEnd(Head, id, name, age, gender, contact, blood, doctor);
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
