# Hospital Management System (Console-Based)

A simple console-based Emergency Room patient queue management system implemented in C++ using a singly linked list data structure. Designed to help hospital staff manage patient flow efficiently, streamline workflows, and prioritize care.

## Features

- **Add Patient:** Add new patients with detailed information (ID, name, age, gender, contact number, blood group, doctor assigned) to the queue.
- **Remove Patient:** Remove the patient at the front of the queue once examined.
- **Move Patient Up:** Increase priority by moving a patient from any position to the front of the queue.
- **Display Queue:** View the list of patients currently waiting in arrival order.
- **Search Patient:** Search for patients by their ID.
- **Update Patient:** Update patient details as needed.
- **Simple Console Interaction:** Menu-driven interface for easy operation.

## Data Structure Used

- Singly Linked List for efficient queue management.

## Sample Usage

```plaintext
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
...
Current Patient Queue:
[ID:11 | Name:Ari | Age:30] -> END
```

## Requirements

- C++ compiler (g++, clang, Visual Studio)
- Basic C++ Standard Library usage

## Installation & Usage

1. Compile the source code:
   ```
   g++ HospitalManagement.cpp -o HospitalManagement
   ```
2. Run the executable:
   ```
   ./HospitalManagement
   ```
3. Follow the in-console menu prompts to operate.

## Future Enhancements

- GUI interface for easier interaction.
- Database integration for persistent storage.
- Web interface for remote access.

***

*“Efficient care, one patient at a time.”*

