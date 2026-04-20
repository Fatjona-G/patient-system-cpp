#include <iostream>
#include <vector>
#include <string>
using namespace std;

//PATIENT CLASS

class Patient {
public:
    int id;
    string name;
    int age;

    Patient(int id, string name, int age) {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << "ID: " << id << " | Name: " << name << " | Age: " << age << endl;
    }
};

// APPOINTMENT CLASS

class Appointment {
public:
    int patientId;
    string date;
    string description;

    Appointment(int pid, string date, string desc) {
        this->patientId = pid;
        this->date = date;
        this->description = desc;
    }

    void display() {
        cout << "Patient ID: " << patientId 
             << " | Date: " << date 
             << " | Description: " << description << endl;
    }
};

// SYSTEM CLASS

class System {
private:
    vector<Patient> patients;
    vector<Appointment> appointments;

public:

    // ADD PATIENT
    void addPatient() {
        int id, age;
        string name;

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;

        patients.push_back(Patient(id, name, age));
        cout << "Patient added successfully!\n";
    }

    // SHOW PATIENTS
    void showPatients() {
        if (patients.empty()) {
            cout << "No patients found.\n";
            return;
        }

        cout << "\n--- Patients List ---\n";
        for (auto &p : patients) {
            p.display();
        }
    }

    // DELETE PATIENT
    void deletePatient() {
        int id;
        cout << "Enter Patient ID to delete: ";
        cin >> id;

        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].id == id) {
                patients.erase(patients.begin() + i);
                cout << "Patient deleted!\n";
                return;
            }
        }

        cout << "Patient not found!\n";
    }

    // ADD APPOINTMENT
    void addAppointment() {
        int pid;
        string date, desc;

        cout << "Enter Patient ID: ";
        cin >> pid;
        cin.ignore();
        cout << "Enter Date: ";
        getline(cin, date);
        cout << "Enter Description: ";
        getline(cin, desc);

        appointments.push_back(Appointment(pid, date, desc));
        cout << "Appointment added!\n";
    }

    // SHOW APPOINTMENTS
    void showAppointments() {
        if (appointments.empty()) {
            cout << "No appointments found.\n";
            return;
        }

        cout << "\n--- Appointments ---\n";
        for (auto &a : appointments) {
            a.display();
        }
    }

    // MENU
    void menu() {
        int choice;

        do {
            cout << "\n===== PATIENT SYSTEM =====\n";
            cout << "1. Add Patient\n";
            cout << "2. Show Patients\n";
            cout << "3. Delete Patient\n";
            cout << "4. Add Appointment\n";
            cout << "5. Show Appointments\n";
            cout << "0. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addPatient(); break;
                case 2: showPatients(); break;
                case 3: deletePatient(); break;
                case 4: addAppointment(); break;
                case 5: showAppointments(); break;
                case 0: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice!\n";
            }

        } while (choice != 0);
    }
};

// MAIN
int main() {
    System sys;
    sys.menu();
    return 0;
}

