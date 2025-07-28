## Overview

This is a simple console-based program written in C++ to manage a queue of patients waiting in the emergency room **using a singly linked list** data structure.

The system organizes patients in order of arrival, allowing hospital staff to:

- Add patients to the end of the queue (Receptionist)
- Remove patients from the front of the queue when examined by doctors
- Move patients up to the front of the queue to increase priority (Nurses)
- Display the current queue of patients
- Search for specific patients by their ID
- Update patient information as needed

This program helps streamline emergency room workflows and ensures efficient and timely patient care.

## Features

- **Add Patient:** Enqueue a new patient to the end of the queue with details including patient ID, name, and age.
- **Remove Patient:** Dequeue the patient at the front of the queue after examination.
- **Move Patient Up:** Increase a patient's priority by moving them to the front of the queue based on their patient ID.
- **Display Queue:** Show all patients currently waiting in order.
- **Search Patient:** Search for a patient by their ID and display their details.
- **Update Patient:** Update a patient's name and age by searching with their ID.

## Data Structure Used
- **Singly Linked List**  
Each patient is represented as a node containing patient ID, name, age, and a pointer to the next node in the list. The head of the list represents the front of the queue.


Use the menu displayed to perform various operations:
   - Input `1` to add a patient
   - Input `2` to remove a patient
   - Input `3` to move a patient up in priority
   - Input `4` to display the current queue
   - Input `5` to search for a patient
   - Input `6` to update patient information
   - Input `0` to exit the program

Follow on-screen prompts to enter patient details or choose patients by their ID.

## Functions Description

| Function Name          | Purpose                                                       |
|------------------------|---------------------------------------------------------------|
| `CreatePatient`        | Creates a new patient node                                    |
| `InsertPatientAtEnd`   | Inserts a patient node at the end of the queue                |
| `DeletePatientAtStart` | Removes the patient node from the front (examined patient)    |
| `MovePatientUp`        | Moves a patient from any position (except front) to the front |
| `DisplayQueue`         | Prints the entire patient queue in order                      |
| `SearchPatient`        | Finds and displays patient details by ID                      |
| `UpdatePatient`        | Updates patient name and age given their ID                   |

## Notes

- This implementation uses a singly linked list and manipulates node pointers to manage the queue.
- Input validation is minimal; incorrect inputs may cause unexpected behavior.
- Patient IDs should be unique to ensure correct operations.
- Moving a patient up moves them instantly to the front of the queue.
- The program uses simple console input/output for interaction.

## Sample Output

```
----- Menu -----
1. Add patient
2. Remove patient (doctor examines)
3. Move patient up (priority)
4. Display queue
5. Search patient
6. Update patient
0. Exit
Enter choice: 1
Patient ID: 11
Name: Ari
Age: 30

----- Menu -----
1. Add patient
2. Remove patient (doctor examines)
3. Move patient up (priority)
4. Display queue
5. Search patient
6. Update patient
0. Exit
Enter choice: 4
Current Patient Queue:
[ID:11 | Name:Ari | Age:30] -> END
```

## New Updated Changes in HM_adv.cpp

### Extended Patient Information

The patient node now includes extra fields to capture more comprehensive patient details:

- Gender
- Contact Number
- Blood Group
- Doctor Assigned

### Updated Features

- Add patients with full details: ID, Name, Age, Gender, Contact Number, Blood Group, and Doctor Assigned.
- Display and search show all patient information.
- Update patient details including the new fields.
- Inputs for all patient fields use simple `cin` extraction (note that only single-word inputs can be handled with this approach).

### Updated Patient Node Structure

```cpp
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
```
