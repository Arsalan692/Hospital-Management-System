#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <random>

using namespace std;

int get_lines_count(string file_name)
{
    fstream fp1;
    string line;
    int total_lines = 0;
    fp1.open(file_name, ios ::in);
    if (!fp1.is_open())
    {
        cout << "Cannot open file!" << endl;
    }
    while (getline(fp1, line))
    {
        total_lines++;
    }

    fp1.close();
    return total_lines;
}

template <class T>
class Test
{
private:
    T test_id;
    string test_name;
    string test_result;
    float price;

public:
    Test() {}
    Test(T test_id, string test_name, string test_result, float price) : test_id(test_id), test_name(test_name), test_result(test_result), price(price)
    {
    }
    string get_test_name() { return test_name; }
    string get_test_result() { return test_result; }
    float get_price() { return price; }
    T get_test_id() { return test_id; }
};

class Report
{
private:
    vector<Test<string>> all_tests;

public:
    void add_new_test(string id, string name, string result, float price)
    {
        Test<string> loc_test(id, name, result, price);
        all_tests.push_back(loc_test);
    }

    vector<Test<string>> get_all_test()
    {
        return all_tests;
    }
};

Report tests_Initializer()
{
    string test_names[] = {"Blood Pressure Test", "Cholesterol Test", "Blood Glucose Test", "Complete Blood Count (CBC)", "Urinalysis", "Electrocardiogram (ECG)"};
    string test_results[] = {"120/80 mmHg", "\nTotal Cholesterol: 200 mg/dL, \nLDL: 130 mg/dL, \nHDL: 50 mg/dL, \nTriglycerides: 150 mg/dL", "Fasting Blood Sugar: 90 mg/dL", "Hemoglobin: 14 g/dL, White Blood Cells: 8,000/μL, Platelets: 250,000/μL", "Normal, no abnormalities detected", "Normal sinus rhythm"};
    float price[] = {1200, 2200, 5000, 4000, 500, 1000};
    Report R1;
    for (int i = 0; i < 6; i++)
    {
        R1.add_new_test(to_string(i + 1), test_names[i], test_results[i], price[i]);
    }
    return R1;
}

class Feedback
{
private:
    string patientName;
    string feedbackText;
    int rating; // Assuming rating is out of 10

public:
    // Constructor
    Feedback(string name, string feedback, int rate) : patientName(name), feedbackText(feedback), rating(rate) {}

    // Setters
    void setPatientName(string name)
    {
        patientName = name;
    }

    void setFeedbackText(string feedback)
    {
        feedbackText = feedback;
    }

    void setRating(int rate)
    {
        rating = rate;
    }

    // Getters
    string getPatientName() const
    {
        return patientName;
    }

    string getFeedbackText() const
    {
        return feedbackText;
    }

    int getRating() const
    {
        return rating;
    }

    // Function to display feedback
    void displayFeedback() const
    {
        cout << "Patient Name: " << patientName << endl;
        cout << "Feedback: " << feedbackText << endl;
        cout << "Rating: " << rating << endl;
    }
};

class Bill
{
private:
    static int bill_id;
    float bill_amount;

public:
    Bill()
    {
        bill_amount = 0.0;
    }

    void add_to_bill(float amount)
    {
        bill_amount += amount;
    }

    void idIncrementor()
    {
        bill_id++;
    }

    int get_bill_id() { return bill_id; }
    float get_bill_amount() { return bill_amount; }
};

int Bill ::bill_id = 1;

class Medicine
{
    string name;
    string forCuringDisease;
    int quantity;
    float price;

public:
    Medicine(string n, string fCD, int q, float p) : name(n), forCuringDisease(fCD), quantity(q), price(p) {}

    string get_name() { return name; }
    string get_forCuringDisease() { return forCuringDisease; }
    int get_quantity() { return quantity; }
    float get_price() { return price; }
};

class Policy
{
    int policyID;
    string insuranceCompany;
    int policyNumber;
    bool coverageStatus;

public:
    Policy(int pID, string iC, int pN, bool cS) : policyID(pID), insuranceCompany(iC), policyNumber(pN), coverageStatus(cS) {}

    void show_policies()
    {
        system("cls");

        cout << "Hospital Policy\n\n";

        cout << "1. Patient Care:\n"
             << "- The hospital is committed to providing high-quality care to all patients regardless of their race, gender, religion, or financial status.\n"
             << "- Patients will be treated with dignity, respect, and compassion at all times.\n\n";

        cout << "2. Appointment Scheduling:\n"
             << "- Patients are encouraged to schedule appointments for medical consultations and procedures in advance whenever possible.\n"
             << "- Walk-in appointments will be accommodated based on availability, with priority given to emergency cases.\n\n";

        cout << "3. Visiting Hours:\n"
             << "- Visiting hours for patients are from [insert visiting hours here]. Visitors are kindly requested to adhere to these hours to ensure patients' rest and recovery.\n\n";

        cout << "4. Medical Records:\n"
             << "- Patient medical records are confidential and will only be accessed by authorized medical personnel.\n"
             << "- Patients have the right to access their medical records upon request, in accordance with hospital policies and regulations.\n\n";

        cout << "5. Billing and Payment:\n"
             << "- Patients will receive itemized bills detailing the cost of medical services rendered. Payment is due upon receipt of the bill.\n"
             << "- Financial assistance programs may be available for eligible patients. Please inquire at the billing department for more information.\n\n";

        cout << "6. Safety and Security:\n"
             << "- The hospital maintains a safe and secure environment for patients, visitors, and staff.\n"
             << "- Security personnel are stationed throughout the hospital premises to ensure the safety of all individuals.\n\n";

        cout << "7. Infection Control:\n"
             << "- Strict infection control measures are in place to prevent the spread of diseases within the hospital.\n"
             << "- Patients, visitors, and staff are required to adhere to proper hand hygiene and other infection control protocols.\n\n";

        cout << "8. Complaints and Feedback:\n"
             << "- The hospital welcomes feedback and suggestions from patients and their families to improve the quality of services provided.\n"
             << "- Patients have the right to file complaints or grievances regarding their care. Complaints will be addressed promptly and professionally.\n\n";

        cout << "9. Ethical Standards:\n"
             << "- The hospital upholds ethical standards in all medical practices and procedures.\n"
             << "- Patients have the right to refuse treatment, and their wishes will be respected in accordance with legal and ethical guidelines.\n\n";

        cout << "10. Staff Conduct:\n"
             << "- Hospital staff are expected to conduct themselves professionally and courteously at all times.\n"
             << "- Discrimination, harassment, or disrespectful behavior towards patients, visitors, or colleagues will not be tolerated.\n\n";

        cout << "11. Emergency Response:\n"
             << "- The hospital is equipped to handle medical emergencies 24 hours a day, 7 days a week.\n"
             << "- Emergency response teams are trained and ready to respond swiftly to any medical crisis.\n\n";

        cout << "12. Discharge Process:\n"
             << "- Patients will be discharged from the hospital upon the recommendation of their attending physician.\n"
             << "- Discharge instructions, including medication schedules and follow-up appointments, will be provided to patients prior to discharge.\n\n";

        cout << "13. End-of-Life Care:\n"
             << "- The hospital provides compassionate end-of-life care to patients and support to their families during difficult times.\n"
             << "- Palliative care services are available to manage pain and improve the quality of life for patients with terminal illnesses.\n\n";

        cout << "14. Research and Education:\n"
             << "- The hospital may engage in medical research and educational activities to advance the field of healthcare.\n"
             << "- Patient participation in research studies is voluntary and requires informed consent.\n\n";

        cout << "15. Community Engagement:\n"
             << "- The hospital is committed to serving the needs of the local community through outreach programs, health education initiatives, and partnerships with other organizations.\n\n";

        cout << endl
             << endl
             << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
    }
};

class Pharmacy
{
    // friend void Doctor::recommendMedicine();
    int numberOfPharmacists;
    vector<Medicine> basic_Medicines_array;

public:
    Pharmacy()
    {
        numberOfPharmacists = 4;
    }

    vector<Medicine> get_basic_Medicines_array() { return basic_Medicines_array; }

    void addMedicine(string n, string fCD, int q, float p)
    {
        Medicine tempMed(n, fCD, q, p);
        basic_Medicines_array.push_back(tempMed);
    }

    float medicinesToBuy(string arr[], int size)
    {
        float totalBill = 0.00;
        int counter;
        for (int i = 0; i < size; i++)
        {
            counter = 0;
            for (int j = 0; j < basic_Medicines_array.size(); j++)
            {
                if (arr[i] == basic_Medicines_array[j].get_name())
                {
                    totalBill += basic_Medicines_array[j].get_price();
                    counter++;
                    break;
                }
            }
            if (counter == 0)
            {
                cout << arr[i] << " is not available!" << endl;
                system("pause");
            }
        }
        cout << "Your Total Bill is: ";
        return totalBill;
    }
};

Pharmacy inventoryInitializer()
{
    string diseases[] = {"Headache", "Common cold", "Fever", "Stomach ache", "Back pain", "Allergies"};
    string medicines[] = {"Paracetamol", "Ibuprofen", "Aspirin", "Pepto-Bismol", "Naproxen", "Claritin"};
    int quantity[] = {100, 75, 150, 200, 50, 130};
    float price[] = {120.5, 275.25, 329.99, 79.89, 247.25, 523.29};
    Pharmacy p1;
    for (int i = 0; i < 6; i++)
    {
        p1.addMedicine(medicines[i], diseases[i], quantity[i], price[i]);
    }
    return p1;
}

class Person
{
protected:
    string full_name;
    string gender;
    int age;

public:
    Person() {}
    Person(string full_name, string gender, int age) : full_name(full_name), gender(gender), age(age) {}

    virtual void displayBasicDetails() = 0;
};

class Patient : public Person
{
private:
    int MR_Number;
    string disease;
    int height;
    float weight;
    string blood_group;

public:
    Patient() = default;
    Patient(int MR_Number, string full_name, string gender,
            int age, string disease, int height, float weight, string blood_group)
        : Person(full_name, gender, age), MR_Number(MR_Number),
          disease(disease), height(height), weight(weight), blood_group(blood_group)
    {
    }

    // getters
    int get_MR_Number() { return MR_Number; }
    string get_full_name() { return full_name; }
    string get_gender() { return gender; }
    int get_age() { return age; }
    string get_disease() { return disease; }
    int get_height() { return height; }
    float get_weight() { return weight; }
    string get_blood_group() { return blood_group; }

    // setters
    void set_MR_Number(const int MR_Number) { this->MR_Number = MR_Number; }
    void set_full_name(const string full_name) { this->full_name = full_name; }
    void set_gender(const string gender) { this->gender = gender; }
    void set_age(const int age) { this->age = age; }
    void set_disease(const string disease) { this->disease = disease; }
    void set_height(const int height) { this->height = height; }
    void set_weight(const float weight) { this->weight = weight; }
    void set_blood_group(const string blood_group) { this->blood_group = blood_group; }

    void buyMedicines()
    {
        system("cls");
        int size;
        cout << "Enter the number of medicines to buy: ";
        cin >> size;
        string NamesofmedicinesTObuy[size];
        cout << endl
             << "Enter the name of medicines you want to buy: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the name of medicine # " << i + 1 << ": ";
            cin >> NamesofmedicinesTObuy[i];
        }

        Pharmacy tempPharma = inventoryInitializer();
        cout << endl
             << tempPharma.medicinesToBuy(NamesofmedicinesTObuy, size) << endl
             << endl;
        system("pause");
    }

    void seeAllDoctors()
    {
        system("cls");
        cout << "Showing the list of all available doctors..." << endl;
        Sleep(2000);

        system("cls");

        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;
        cout << "|   Doctor's ID   |         Name         |       Specialization       |      Gender      |    Room Number     |  Fee Per Patient  |  Experience  |" << endl;
        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;

        string line;
        fstream fp;
        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {

            fp >> id;                    // for id
            for (int j = 0; j < 10; j++) // for name
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    full_name += loc;
                    full_name += " ";
                }
            }

            room_number = stoi(loc);
            fp >> gender;
            fp >> age;
            for (int j = 0; j < 10; j++) // for specialization
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    specialization += loc;
                    specialization += " ";
                }
            }

            years_of_experience = stoi(loc);
            fp >> salary;
            fp >> fee_per_patient;

            // cout << endl;
            int padding = (18 - (to_string(id)).length());
            cout << "| " << id << setw(padding) << setfill(' ');

            padding = (23 - (full_name.length()));
            cout << "| " << full_name << setw(padding) << setfill(' ');

            padding = (29 - specialization.length());
            cout << "| " << specialization << setw(padding) << setfill(' ');

            padding = (19 - gender.length());
            cout << "| " << gender << setw(padding) << setfill(' ');

            padding = (21 - (to_string(room_number)).length());
            cout << "| " << room_number << setw(padding) << setfill(' ');

            padding = (27 - (to_string(fee_per_patient)).length());
            cout << "| " << fee_per_patient << setw(padding) << setfill(' ');

            padding = (14 - (to_string(years_of_experience)).length());
            cout << "| " << years_of_experience << setw(padding) << setfill(' ');

            cout << "|" << endl;

            full_name = "";
            specialization = "";
        }
        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
        fp.close();
    }

    void displayBasicDetails() override
    {
        cout << "Patient's Name: " << full_name << endl;
        cout << "Patient's Age: " << age << endl;
        cout << "Patient's Gender: " << gender << endl;
    }

    void showPatientCredentials()
    {
        system("cls");

        cout << endl;
        cout << "Patient's MR_Number: " << MR_Number << endl;
        displayBasicDetails();
        cout << "Patient's Disease: " << disease << endl;
        cout << "Patient's Height: " << height << "cm" << endl;
        cout << "Patient's Weight: " << weight << "kg" << endl;
        cout << "Patient's Blood Group: " << blood_group << endl
             << endl;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
    }

    void book_an_appointment()
    {
        system("cls");
        cout << "Showing the list of all available doctors..." << endl;
        Sleep(2000);

        label21:
        system("cls");

        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;
        cout << "|       S.No      |         Name         |       Specialization       |      Gender      |    Room Number     |  Fee Per Patient  |  Experience  |" << endl;
        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;

        string line;
        fstream fp;
        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        vector<string> names_of_doctors;
        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;
        int s_number = 1;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {

            fp >> id;                    // for id
            for (int j = 0; j < 10; j++) // for name
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    full_name += loc;
                    full_name += " ";
                }
            }

            room_number = stoi(loc);
            fp >> gender;
            fp >> age;
            for (int j = 0; j < 10; j++) // for specialization
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    specialization += loc;
                    specialization += " ";
                }
            }

            years_of_experience = stoi(loc);
            fp >> salary;
            fp >> fee_per_patient;

            // cout << endl;

            int padding = (18 - (to_string(s_number)).length());
            cout << "| " << s_number++ << setw(padding) << setfill(' ');

            padding = (23 - (full_name.length()));
            cout << "| " << full_name << setw(padding) << setfill(' ');
            names_of_doctors.push_back(full_name);

            padding = (29 - specialization.length());
            cout << "| " << specialization << setw(padding) << setfill(' ');

            padding = (19 - gender.length());
            cout << "| " << gender << setw(padding) << setfill(' ');

            padding = (21 - (to_string(room_number)).length());
            cout << "| " << room_number << setw(padding) << setfill(' ');

            padding = (27 - (to_string(fee_per_patient)).length());
            cout << "| " << fee_per_patient << setw(padding) << setfill(' ');

            padding = (14 - (to_string(years_of_experience)).length());
            cout << "| " << years_of_experience << setw(padding) << setfill(' ');

            cout << "|" << endl;

            full_name = "";
            specialization = "";
        }
        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;

        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dist(1, 12);
        uniform_int_distribution<> dist2(0, 1);
        int random = dist(gen);
        int random2 = dist2(gen);
        string am_or_pm = random2 ? "AM" : "PM";
        int l;
        cout << "Enter the S.No of the doctor from the list you want to book an appointment with : ";
        cin >> l;
        if (l>names_of_doctors.size())
        {
            cout<<"Invalid S. No! Please Try Again!"<<endl;
            Sleep(2000);
            goto label21;
        }
        
        cout << "Your appointment with Dr." << names_of_doctors[l - 1] << "has been scheduled for today at " << random << ":00 " << am_or_pm << endl;
        fp.close();
        system("pause");
    }

    void do_a_test()
    {
        system("cls");
        string test_name;
        Bill total_bill;

        cout << "Please state the name of the test you would like to undergo : ";
        cin.ignore();
        getline(cin, test_name);
        Report report = tests_Initializer();
        int counter = 0;
        int temp;
        int l;
        for (Test<string> i : report.get_all_test())
        {
            if (i.get_test_name() == test_name)
            {
                total_bill.add_to_bill(i.get_price());
                cout << endl
                     << "Your total bill is : $" << total_bill.get_bill_amount() << endl;
                total_bill.idIncrementor();
                cout << "Press 1 to pay the bill : ";
                cin >> temp;
                cout << "\nBill paid succesfully!!\n"
                     << endl;
                cout << "Generating your test report..." << endl;
                Sleep(2000);
                cout << endl
                     << "Result:- " << i.get_test_result() << endl;

                cout << endl
                     << "press 0 to return to the main menu : ";
                cin >> l;
                counter++;
                break;
            }
        }
        if (counter == 0)
        {
            cout << "Sorry!, this test is not currently offered at our hospital." << endl;
            system("pause");
        }
    }

    void giveFeedback()
    {
        system("cls");

        string feedback;
        int rating;

        cin.ignore();
        cout << "Enter you feedback: ";
        getline(cin, feedback);

        cout << "Enter the rating (Out of 10): ";
        cin >> rating;

        Feedback f1(full_name, feedback, rating);

        cout << endl
             << "Your Feedback has been recorded successfully!" << endl
             << endl;
        f1.displayFeedback();

        system("pause");
    }

    void patientMenu()
    {

        int choice;
        while (choice != 9)
        {
            label20:
            system("cls");
            cout << endl;
            cout << "################ Patient's Menu ################" << endl;
            cout << "1) Show Credentials" << endl;
            cout << "2) Buy medicines from Pharmacy" << endl;
            cout << "3) See all Available Doctors" << endl;
            cout << "4) Book an appointment" << endl;
            cout << "5) Do a test" << endl;
            cout << "6) Give Feedback" << endl;
            cout << "7) Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                showPatientCredentials();
                break;
            case 2:
                buyMedicines();
                break;
            case 3:
                seeAllDoctors();
                break;
            case 4:
                book_an_appointment();
                break;
            case 5:
                do_a_test();
                break;
            case 6:
                giveFeedback();
                break;
            case 7:
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                            HOSPITAL MANAGEMENT SYSTEM                                 |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
                cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
                exit(0);
            default:
            cout << "Invalid input! Please try again!" << endl;
            Sleep(2000);
            goto label20;
            break;
            }
        }
    }
};

class Doctor : public Person
{
    friend ostream &operator<<(ostream &out, Doctor &doc1);

private:
    int id;
    int room_number;
    string specialization;
    int years_of_experience;
    float salary;
    float fee_per_patient;

public:
    Doctor() {}
    Doctor(int id, int room_number, string full_name, string gender,
           int age, string specialization, int years_of_experience,
           float salary, float fee_per_patient) : Person(full_name, gender, age), id(id), room_number(room_number), specialization(specialization),
                                                  years_of_experience(years_of_experience), salary(salary),
                                                  fee_per_patient(fee_per_patient)
    {
    }

    // getters
    int get_id() { return id; }
    int get_room_number() { return room_number; }
    string get_full_name() { return full_name; }
    string get_gender() { return gender; }
    int get_age() { return age; }
    string get_specialization() { return specialization; }
    int get_years_of_experience() { return years_of_experience; }
    float get_salary() { return salary; }
    float get_fee_per_patient() { return fee_per_patient; }

    // setters
    void set_id(const int id) { this->id = id; }
    void set_room_number(const int room_number) { this->room_number = room_number; }
    void set_full_name(const string full_name) { this->full_name = full_name; }
    void set_gender(const string gender) { this->gender = gender; }
    void set_age(const int age) { this->age = age; }
    void set_specialization(const string specialization) { this->specialization = specialization; }
    void set_years_of_experience(const int years_of_experience) { this->years_of_experience = years_of_experience; }
    void set_salary(const float salary) { this->salary = salary; }
    void set_fee_per_patient(const float fee_per_patient) { this->fee_per_patient = fee_per_patient; }

    void recommendMedicine()
    {
        system("cls");

        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dist(0, 5);
        int random = dist(gen);

        Pharmacy tempPharma = inventoryInitializer();

        cout << "Diagnosing the disease of the patient..." << endl;
        Sleep(3000);
        cout << "From the report, the following has been diagnosed:" << endl;
        cout << "Unfortunately, the patient has " << (tempPharma.get_basic_Medicines_array())[random].get_forCuringDisease() << " and the recommended medicine for this disease is: " << (tempPharma.get_basic_Medicines_array())[random].get_name() << endl;
        system("pause");
    }

    void displayBasicDetails() override
    {
        cout << "Doctor's Name: " << full_name << endl;
        cout << "Doctor's Age: " << age << endl;
        cout << "Doctor's Gender: " << gender << endl;
    }

    void showSalary()
    {
        system("cls");

        cout << "Doctor's Salary: $" << salary << endl
             << endl;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
    }

    void updateSpecialization()
    {
        system("cls");

        string value;
        cout << "Enter the updated Specialization: ";
        cin.ignore();
        getline(cin, value);

        fstream fp;
        fstream fp1;

        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp1.open("temp.txt", ios ::out);
        if (!fp1.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_edit;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {
            getline(fp, line);
            if (this->id == stoi(line.substr(0, 3)))
            {
                line_to_edit = i;
                break;
            }
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;

        for (int i = 0; i < get_lines_count("Doctors.txt") + 1; i++)
        {

            if (i == line_to_edit)
            {
                fp >> id;                    // for id
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                room_number = stoi(loc);
                fp >> gender;
                fp >> age;
                for (int j = 0; j < 10; j++) // for specialization
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        specialization += loc;
                        specialization += " ";
                    }
                }

                years_of_experience = stoi(loc);
                fp >> salary;
                fp >> fee_per_patient;

                fp1 << id;
                fp1 << " " << full_name;
                fp1 << room_number;
                fp1 << " " << gender;
                fp1 << " " << age;
                fp1 << " " << value;
                fp1 << " " << years_of_experience;
                fp1 << " " << salary;
                fp1 << " " << fee_per_patient;
            }
            else
            {
                getline(fp, line);
                fp1 << line << endl;
            }
        }

        fp.close();
        fp1.close();
        remove("Doctors.txt");
        rename("temp.txt", "Doctors.txt");
    }

    void updateExperience()
    {
        system("cls");

        string value;
        cout << "Enter the updated Experience: ";
        cin.ignore();
        getline(cin, value);

        fstream fp;
        fstream fp1;

        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp1.open("temp.txt", ios ::out);
        if (!fp1.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_edit;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {
            getline(fp, line);
            if (this->id == stoi(line.substr(0, 3)))
            {
                line_to_edit = i;
                break;
            }
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;

        for (int i = 0; i < get_lines_count("Doctors.txt") + 1; i++)
        {

            if (i == line_to_edit)
            {
                fp >> id;                    // for id
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                room_number = stoi(loc);
                fp >> gender;
                fp >> age;
                for (int j = 0; j < 10; j++) // for specialization
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        specialization += loc;
                        specialization += " ";
                    }
                }

                years_of_experience = stoi(loc);
                fp >> salary;
                fp >> fee_per_patient;

                fp1 << id;
                fp1 << " " << full_name;
                fp1 << room_number;
                fp1 << " " << gender;
                fp1 << " " << age;
                fp1 << " " << specialization;
                fp1 << value;
                fp1 << " " << salary;
                fp1 << " " << fee_per_patient;
            }
            else
            {
                getline(fp, line);
                fp1 << line << endl;
            }
        }

        fp.close();
        fp1.close();
        remove("Doctors.txt");
        rename("temp.txt", "Doctors.txt");
    }

    void changeRoomNumber()
    {
        system("cls");

        string value;
        cout << "Enter the new room number: ";
        cin.ignore();
        getline(cin, value);

        fstream fp;
        fstream fp1;

        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp1.open("temp.txt", ios ::out);
        if (!fp1.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_edit;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {
            getline(fp, line);
            if (this->id == stoi(line.substr(0, 3)))
            {
                line_to_edit = i;
                break;
            }
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;

        for (int i = 0; i < get_lines_count("Doctors.txt") + 1; i++)
        {

            if (i == line_to_edit)
            {
                fp >> id;                    // for id
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                room_number = stoi(loc);
                fp >> gender;
                fp >> age;
                for (int j = 0; j < 10; j++) // for specialization
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        specialization += loc;
                        specialization += " ";
                    }
                }

                years_of_experience = stoi(loc);
                fp >> salary;
                fp >> fee_per_patient;

                fp1 << id;
                fp1 << " " << full_name;
                fp1 << value;
                fp1 << " " << gender;
                fp1 << " " << age;
                fp1 << " " << specialization;
                fp1 << years_of_experience;
                fp1 << " " << salary;
                fp1 << " " << fee_per_patient;
            }
            else
            {
                getline(fp, line);
                fp1 << line << endl;
            }
        }

        fp.close();
        fp1.close();
        remove("Doctors.txt");
        rename("temp.txt", "Doctors.txt");
    }

    void showPatientRecords()
    {

    label19:
        system("cls");
        int patient_to_show;
        cout << "Enter the MR Number of the patient you want to see the credentials of: ";
        cin >> patient_to_show;

        fstream fp;

        fp.open("Patients.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_show;
        int check = 0;
        for (int i = 0; i < get_lines_count("Patients.txt"); i++)
        {
            getline(fp, line);
            if (patient_to_show == stoi(line.substr(0, 3)))
            {
                check++;
                line_to_show = i;
                break;
            }
        }
        if (check == 0)
        {
            cout << "MR number not found! Please Try again..." << endl;
            Sleep(2000);
            fp.close();
            goto label19;
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        int MR_Number;
        string full_name;
        int age;
        string gender;
        int height;
        string disease;
        float weight;
        string blood_group;
        string loc;

        for (int i = 0; i < get_lines_count("patients.txt"); i++)
        {
            if (i == line_to_show)
            {
                fp >> MR_Number;             // for MR_Number
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                age = stoi(loc);
                fp >> gender;
                fp >> height;
                for (int j = 0; j < 10; j++) // for disease
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        disease += loc;
                        disease += " ";
                    }
                }

                weight = stof(loc);
                fp >> blood_group;
            }
            else
            {
                getline(fp, line);
            }
        }

        fp.close();

        cout << endl;
        cout << "Patient's MR_Number: " << MR_Number << endl;
        cout << "Patient's Name: " << full_name << endl;
        cout << "Patient's Age: " << age << " years" << endl;
        cout << "Patient's Gender: " << gender << endl;
        cout << "Patient's Disease: " << disease << endl;
        cout << "Patient's Height: " << height << "cm" << endl;
        cout << "Patient's Weight: " << weight << "kg" << endl;
        cout << "Patient's Blood Group: " << blood_group << endl
             << endl;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
    }

    void showDoctorCredentials()
    {
        system("cls");

        cout << *this;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
    }

    void doctor_menu()
    {
        int choice;
        while (choice != 8)
        {
            label18:
            system("cls");
            cout << endl;
            cout << "################ Doctor's Menu ################" << endl;
            cout << "1) Show Credentials" << endl;
            cout << "2) Show Salary" << endl;
            cout << "3) Recommend medicines" << endl;
            cout << "4) Update Specialization" << endl;
            cout << "5) Update Experience" << endl;
            cout << "6) Request to change room number" << endl;
            cout << "7) View Patient Records" << endl;
            cout << "8) Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                showDoctorCredentials();
                break;
            case 2:
                showSalary();
                break;
            case 3:
                recommendMedicine();
                break;
            case 4:
                updateSpecialization();
                break;
            case 5:
                updateExperience();
                break;
            case 6:
                changeRoomNumber();
                break;
            case 7:
                showPatientRecords();
                break;
            case 8:
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                            HOSPITAL MANAGEMENT SYSTEM                                 |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
                cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
                exit(0);
            default:
            cout << "Invalid input! Please try again!" << endl;
            Sleep(2000);
            goto label18;
            break;
            }
        }
    }
};
ostream &operator<<(ostream &out, Doctor &doc1)
{
    cout << "Doctor's ID: " << doc1.id << endl;
    cout << "Doctor's Name: " << doc1.full_name << endl;
    cout << "Doctor's Room Number: " << doc1.room_number << endl;
    cout << "Doctor's Gender: " << doc1.gender << endl;
    cout << "Doctor's Age: " << doc1.age << " years" << endl;
    cout << "Doctor's Specialization: " << doc1.specialization << endl;
    cout << "Doctor's Experience: " << doc1.years_of_experience << " years" << endl;
    cout << "Doctor's Salary: $" << doc1.salary << endl;
    cout << "Doctor's Fee per Patient: $" << doc1.fee_per_patient << endl
         << endl;
    return out;
}

class Admin : public Person // Assuming there will be only 1 admin
{
    friend void admin_menu(Admin &admin);

private:
    string id;
    string password;

    vector<Doctor> all_doctors;
    vector<Patient> all_patients;

    void doctor_filler(int index, int doctor_to_edit)
    {
    label14:
        string value;
        cout << "Enter the new value for the selected attribute : ";
        cin.ignore();
        getline(cin, value);

        fstream fp;
        fstream fp1;

        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp1.open("temp.txt", ios ::out);
        if (!fp1.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_edit, check = 0;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {
            getline(fp, line);
            if (doctor_to_edit == stoi(line.substr(0, 3)))
            {
                check++;
                line_to_edit = i;
                break;
            }
        }
        if (check == 0)
        {
            cout << "ID not found! Please Try again..." << endl;
            Sleep(2000);
            fp.close();
            goto label14;
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;

        for (int i = 0; i < get_lines_count("Doctors.txt") + 1; i++)
        {

            if (i == line_to_edit)
            {
                fp >> id;                    // for id
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                room_number = stoi(loc);
                fp >> gender;
                fp >> age;
                for (int j = 0; j < 10; j++) // for specialization
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        specialization += loc;
                        specialization += " ";
                    }
                }

                years_of_experience = stoi(loc);
                fp >> salary;
                fp >> fee_per_patient;

                if (index == 1)
                {
                    full_name = value + " ";
                }
                else if (index == 2)
                {
                    room_number = stoi(value);
                }
                else if (index == 3)
                {
                    gender = value;
                }
                else if (index == 4)
                {
                    age = stoi(value);
                }
                else if (index == 5)
                {
                    specialization = value + " ";
                }
                else if (index == 6)
                {
                    years_of_experience = stoi(value);
                }
                else if (index == 7)
                {
                    salary = stof(value);
                }
                else if (index == 8)
                {
                    fee_per_patient = stof(value);
                }

                fp1 << id;
                fp1 << " " << full_name;
                fp1 << room_number;
                fp1 << " " << gender;
                fp1 << " " << age;
                fp1 << " " << specialization;
                fp1 << years_of_experience;
                fp1 << " " << salary;
                fp1 << " " << fee_per_patient;
            }
            else
            {
                getline(fp, line);
                fp1 << line << endl;
            }
        }

        fp.close();
        fp1.close();
        remove("Doctors.txt");
        rename("temp.txt", "Doctors.txt");
    }

    void patient_filler(int index, int patient_to_edit)
    {
    label13:
        string value;
        cout << "Enter the new value for the selected attribute: ";
        cin.ignore();
        getline(cin, value);

        fstream fp;
        fstream fp1;

        fp.open("Patients.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp1.open("temp.txt", ios ::out);
        if (!fp1.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_edit;
        int check = 0;
        for (int i = 0; i < get_lines_count("Patients.txt"); i++)
        {
            getline(fp, line);
            if (patient_to_edit == stoi(line.substr(0, 3)))
            {
                check++;
                line_to_edit = i;
                break;
            }
        }
        if (check == 0)
        {
            cout << "MR number not found! Please Try again..." << endl;
            Sleep(2000);
            fp.close();
            goto label13;
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        int MR_Number;
        string full_name;
        int age;
        string gender;
        int height;
        string disease;
        float weight;
        string blood_group;
        string loc;

        for (int i = 0; i < get_lines_count("patients.txt") + 1; i++)
        {
            if (i == line_to_edit)
            {
                fp >> MR_Number;             // for MR_Number
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                age = stoi(loc);
                fp >> gender;
                fp >> height;
                for (int j = 0; j < 10; j++) // for disease
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        disease += loc;
                        disease += " ";
                    }
                }

                weight = stof(loc);
                fp >> blood_group;

                if (index == 1)
                {
                    full_name = value + " ";
                }
                else if (index == 2)
                {
                    age = stoi(value);
                }
                else if (index == 3)
                {
                    gender = value;
                }
                else if (index == 4)
                {
                    height = stoi(value);
                }
                else if (index == 5)
                {
                    disease = value + " ";
                }
                else if (index == 6)
                {
                    weight = stof(value);
                }
                else if (index == 7)
                {
                    blood_group = value;
                }

                fp1 << MR_Number;
                fp1 << " " << full_name;
                fp1 << age;
                fp1 << " " << gender;
                fp1 << " " << height;
                fp1 << " " << disease;
                fp1 << weight;
                fp1 << " " << blood_group;
            }
            else
            {
                getline(fp, line);
                fp1 << line << endl;
            }
        }

        fp.close();
        fp1.close();
        remove("Patients.txt");
        rename("temp.txt", "Patients.txt");
    }

    void id_room_assigner(int &room_number, int &id)
    {
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;

        string line4;

        fstream fp4;
        fp4.open("Doctors.txt", ios ::in);
        if (!fp4.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string loc;

        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {

            if (i == get_lines_count("Doctors.txt") - 1)
            {
                fp4 >> id;
                id++;                        // for id
                for (int j = 0; j < 10; j++) // for name
                {
                    fp4 >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                room_number = stoi(loc) + 1;
                fp4 >> gender;
                fp4 >> age;
                for (int j = 0; j < 10; j++) // for specialization
                {
                    fp4 >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        specialization += loc;
                        specialization += " ";
                    }
                }

                years_of_experience = stoi(loc);
                fp4 >> salary;
                fp4 >> fee_per_patient;
            }
            else
            {
                getline(fp4, line4);
            }
        }
    }

    void MR_number_assigner(int &MR_Number)
    {
        fstream fp;

        fp.open("Patients.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;

        string full_name;
        int age;
        string gender;
        int height;
        string disease;
        float weight;
        string blood_group;
        string loc;

        for (int i = 0; i < get_lines_count("patients.txt"); i++)
        {
            if (i == get_lines_count("patients.txt") - 1)
            {
                fp >> MR_Number;
                MR_Number++;                 // for MR_Number
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                age = stoi(loc);
                fp >> gender;
                fp >> height;
                for (int j = 0; j < 10; j++) // for disease
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        disease += loc;
                        disease += " ";
                    }
                }

                weight = stof(loc);
                fp >> blood_group;
            }
            else
            {
                getline(fp, line);
            }
        }

        fp.close();
    }

    void Doctor_fetcher()
    {
        string line;
        fstream fp;
        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {

            fp >> id;                    // for id
            for (int j = 0; j < 10; j++) // for name
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    full_name += loc;
                    full_name += " ";
                }
            }

            room_number = stoi(loc);
            fp >> gender;
            fp >> age;
            for (int j = 0; j < 10; j++) // for specialization
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    specialization += loc;
                    specialization += " ";
                }
            }

            years_of_experience = stoi(loc);
            fp >> salary;
            fp >> fee_per_patient;

            Doctor doctor(id, room_number, full_name,
                          gender, age, specialization, years_of_experience, salary, fee_per_patient);
            all_doctors.push_back(doctor);

            full_name = "";
            specialization = "";
        }

        fp.close();
    }

    void patient_fetcher()
    {
        string line;
        fstream fp;
        fp.open("Patients.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        int MR_Number;
        string full_name;
        int age;
        string gender;
        int height;
        string disease;
        float weight;
        string blood_group;
        string loc;

        for (int i = 0; i < get_lines_count("Patients.txt"); i++)
        {
            fp >> MR_Number;             // for MR_Number
            for (int j = 0; j < 10; j++) // for name
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    full_name += loc;
                    full_name += " ";
                }
            }

            age = stoi(loc);
            fp >> gender;
            fp >> height;
            for (int j = 0; j < 10; j++) // for disease
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {
                    break;
                }
                else
                {
                    disease += loc;
                    disease += " ";
                }
            }

            weight = stof(loc);
            fp >> blood_group;

            Patient loc_patient(MR_Number, full_name, gender, age, disease, height, weight, blood_group);
            all_patients.push_back(loc_patient);

            full_name = "";
            disease = "";
        }
        fp.close();
    }

public:
    string get_id()
    {
        return id;
    }
    string get_password()
    {
        return password;
    }
    vector<Doctor> get_all_doctors()
    {
        return all_doctors;
    }
    vector<Patient> get_all_patients()
    {
        return all_patients;
    }

    Admin(string full_name, string gender, int age) : Person(full_name, gender, age), id("admin"), password("123")
    {

        // DOCTOR
        Doctor_fetcher();
        // Patient
        patient_fetcher();
    }

    void displayBasicDetails() override
    {
        cout << "Admin's Name: " << full_name << endl;
        cout << "Admin's Age: " << age << endl;
        cout << "Admin's Gender: " << gender << endl;
    }

    void show_all_patients()
    {
        system("cls");

        cout << "|=======================|======================|=====================|================|=========|===============|" << endl;
        cout << "|  Patient's MR Number  |         Name         |       Disease       |     Gender     |   Age   |  Blood Group  |" << endl;
        cout << "|=======================|======================|=====================|================|=========|===============|" << endl;

        string line;
        fstream fp;
        fp.open("Patients.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        int MR_Number;
        string full_name;
        int age;
        string gender;
        int height;
        string disease;
        float weight;
        string blood_group;
        string loc;

        for (int i = 0; i < get_lines_count("Patients.txt"); i++)
        {
            fp >> MR_Number;             // for MR_Number
            for (int j = 0; j < 10; j++) // for name
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    full_name += loc;
                    full_name += " ";
                }
            }

            age = stoi(loc);
            fp >> gender;
            fp >> height;
            for (int j = 0; j < 10; j++) // for disease
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {
                    break;
                }
                else
                {
                    disease += loc;
                    disease += " ";
                }
            }

            weight = stof(loc);
            fp >> blood_group;

            // cout << endl;
            int padding = (24 - (to_string(MR_Number)).length());
            cout << "| " << MR_Number << setw(padding) << setfill(' ');

            padding = (23 - (full_name.length()));
            cout << "| " << full_name << setw(padding) << setfill(' ');

            padding = (22 - disease.length());
            cout << "| " << disease << setw(padding) << setfill(' ');

            padding = (17 - gender.length());
            cout << "| " << gender << setw(padding) << setfill(' ');

            padding = (10 - (to_string(age)).length());
            cout << "| " << age << setw(padding) << setfill(' ');

            padding = (15 - (blood_group).length());
            cout << "| " << blood_group << setw(padding) << setfill(' ');

            cout << "|" << endl;

            full_name = "";
            disease = "";
        }

        cout << "|=======================|======================|=====================|================|=========|===============|" << endl;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
        fp.close();
    }

    void edit_patient()
    {
        system("cls");
        int patient_to_edit;
        cout << "Enter the MR Number of the patient you want to change the attribute of: ";
        cin >> patient_to_edit;

        int choice;
        cout << "Choose the attribute to change: " << endl;
        cout << "1) Name" << endl;
        cout << "2) Age" << endl;
        cout << "3) Gender" << endl;
        cout << "4) Height" << endl;
        cout << "5) Disease" << endl;
        cout << "6) Weight" << endl;
        cout << "7) Blood Group" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        patient_filler(choice, patient_to_edit);
    }

    void show_specific_patient_credentials()
    {
    label12:
        system("cls");
        int patient_to_show;
        cout << "Enter the MR Number of the patient you want to see the credentials of: ";
        cin >> patient_to_show;

        fstream fp;

        fp.open("Patients.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_show;
        int check = 0;
        for (int i = 0; i < get_lines_count("Patients.txt"); i++)
        {
            getline(fp, line);
            if (patient_to_show == stoi(line.substr(0, 3)))
            {
                check++;
                line_to_show = i;
                break;
            }
        }
        if (check == 0)
        {
            cout << "MR number not found! Please Try again..." << endl;
            Sleep(2000);
            fp.close();
            goto label12;
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        int MR_Number;
        string full_name;
        int age;
        string gender;
        int height;
        string disease;
        float weight;
        string blood_group;
        string loc;

        for (int i = 0; i < get_lines_count("patients.txt"); i++)
        {
            if (i == line_to_show)
            {
                fp >> MR_Number;             // for MR_Number
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                age = stoi(loc);
                fp >> gender;
                fp >> height;
                for (int j = 0; j < 10; j++) // for disease
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        disease += loc;
                        disease += " ";
                    }
                }

                weight = stof(loc);
                fp >> blood_group;
            }
            else
            {
                getline(fp, line);
            }
        }

        fp.close();

        system("cls");
        cout << endl;
        cout << "Patient's MR_Number: " << MR_Number << endl;
        cout << "Patient's Name: " << full_name << endl;
        cout << "Patient's Age: " << age << " years" << endl;
        cout << "Patient's Gender: " << gender << endl;
        cout << "Patient's Disease: " << disease << endl;
        cout << "Patient's Height: " << height << "cm" << endl;
        cout << "Patient's Weight: " << weight << "kg" << endl;
        cout << "Patient's Blood Group: " << blood_group << endl
             << endl;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
    }

    void remove_patient()
    {
    label16:
        system("cls");
        int patient_to_fire;
        cout << "Enter the MR Number of the patient : ";
        cin >> patient_to_fire;

        fstream fp;
        fstream fp1;

        fp.open("Patients.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp1.open("temp.txt", ios ::out);
        if (!fp1.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_show, check = 0;
        for (int i = 0; i < get_lines_count("Patients.txt"); i++)
        {
            getline(fp, line);
            if (patient_to_fire == stoi(line.substr(0, 3)))
            {
                check++;
                line_to_show = i;
                break;
            }
        }
        if (check == 0)
        {
            cout << "MR number not found! Please Try again..." << endl;
            Sleep(2000);
            fp.close();
            goto label16;
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        for (int i = 0; i < get_lines_count("Patients.txt"); i++)
        {
            if (i == line_to_show)
            {
                getline(fp, line);
                continue;
            }
            else
            {
                getline(fp, line);
                fp1 << line << endl;
            }
        }

        fp.close();
        fp1.close();
        remove("Patients.txt");
        rename("temp.txt", "Patients.txt");
    }

    void register_patient()
    {

        string full_name;
        int age;
        string gender;
        string disease;
        int height;
        float weight;
        string blood_group;

        // Registering a patient!
        system("cls");
        cin.ignore();
        cout << "Enter the name of patient: ";
        getline(cin, full_name);

        cout << "Enter the age of patient: ";
        cin >> age;

        cout << "Enter the gender of patient: ";
        cin >> gender;

        cin.ignore();
        cout << "Enter the disease of patient: ";
        getline(cin, disease);

        cout << "Enter the height of patient (in cm): ";
        cin >> height;

        cout << "Enter the weight of patient (in kg): ";
        cin >> weight;

        cin.ignore();
        cout << "Enter the Blood Group of patient : ";
        getline(cin, blood_group);

        // Counting lines of Patients.txt

        int total_lines = get_lines_count("Patients.txt");
        int MR_Number;
        MR_number_assigner(MR_Number);

        Patient patient(MR_Number, full_name,
                        gender, age, disease, height, weight, blood_group);

        all_patients.push_back(patient);

        fstream fp;

        fp.open("Patients.txt", ios ::app);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp << MR_Number << " "
           << full_name << " "
           << age << " "
           << gender << " "
           << height << " "
           << disease << " "
           << weight << " "
           << blood_group << endl;

        fp.close();
    }

    void edit_doctor()
    {
        system("cls");
        int doctor_to_edit;
        cout << "Enter the ID of the doctor you want to change the attribute of : ";
        cin >> doctor_to_edit;

        int choice;
        cout << "Choose the attribute to change : " << endl;
        cout << "1) Name " << endl;
        cout << "2) Room Number " << endl;
        cout << "3) Gender" << endl;
        cout << "4) Age" << endl;
        cout << "5) Specialization" << endl;
        cout << "6) Years Of Experience " << endl;
        cout << "7) Salary" << endl;
        cout << "8) Fee per patient" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        doctor_filler(choice, doctor_to_edit);
    }

    void show_specific_doctor_credentials()
    {
    label11:
        system("cls");
        int doctor_to_show;
        cout << "Enter the ID of the doctor you want to see the credentials of : ";
        cin >> doctor_to_show;

        fstream fp;

        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_show;
        int check = 0;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {
            getline(fp, line);
            if (doctor_to_show == stoi(line.substr(0, 3)))
            {
                check++;
                line_to_show = i;
                break;
            }
        }
        if (check == 0)
        {
            cout << "ID not found! Please Try again..." << endl;
            Sleep(2000);
            fp.close();
            goto label11;
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;

        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {
            if (i == line_to_show)
            {
                fp >> id;                    // for id
                for (int j = 0; j < 10; j++) // for name
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {

                        break;
                    }
                    else
                    {
                        full_name += loc;
                        full_name += " ";
                    }
                }

                room_number = stoi(loc);
                fp >> gender;
                fp >> age;
                for (int j = 0; j < 10; j++) // for specialization
                {
                    fp >> loc;
                    if (loc[0] >= 48 && loc[0] <= 57)
                    {
                        break;
                    }
                    else
                    {
                        specialization += loc;
                        specialization += " ";
                    }
                }

                years_of_experience = stoi(loc);
                fp >> salary;
                fp >> fee_per_patient;
            }
            else
            {
                getline(fp, line);
            }
        }

        fp.close();

        system("cls");
        cout << "Doctor's ID: " << id << endl;
        cout << "Doctor's Name: " << full_name << endl;
        cout << "Doctor's Room Number: " << room_number << endl;
        cout << "Doctor's Gender: " << gender << endl;
        cout << "Doctor's Age: " << age << " years" << endl;
        cout << "Doctor's Specialization: " << specialization << endl;
        cout << "Doctor's Experience: " << years_of_experience << " years" << endl;
        cout << "Doctor's Salary: $" << salary << endl;
        cout << "Doctor's Fee per Patient: $" << fee_per_patient << endl
             << endl;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
    }

    void show_all_doctors()
    {
        system("cls");

        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;
        cout << "|   Doctor's ID   |         Name         |       Specialization       |      Gender      |    Room Number     |  Fee Per Patient  |  Experience  |" << endl;
        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;

        string line;
        fstream fp;
        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        int id;
        int room_number;
        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string loc;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {

            fp >> id;                    // for id
            for (int j = 0; j < 10; j++) // for name
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    full_name += loc;
                    full_name += " ";
                }
            }

            room_number = stoi(loc);
            fp >> gender;
            fp >> age;
            for (int j = 0; j < 10; j++) // for specialization
            {
                fp >> loc;
                if (loc[0] >= 48 && loc[0] <= 57)
                {

                    break;
                }
                else
                {
                    specialization += loc;
                    specialization += " ";
                }
            }

            years_of_experience = stoi(loc);
            fp >> salary;
            fp >> fee_per_patient;

            // cout << endl;
            int padding = (18 - (to_string(id)).length());
            cout << "| " << id << setw(padding) << setfill(' ');

            padding = (23 - (full_name.length()));
            cout << "| " << full_name << setw(padding) << setfill(' ');

            padding = (29 - specialization.length());
            cout << "| " << specialization << setw(padding) << setfill(' ');

            padding = (19 - gender.length());
            cout << "| " << gender << setw(padding) << setfill(' ');

            padding = (21 - (to_string(room_number)).length());
            cout << "| " << room_number << setw(padding) << setfill(' ');

            padding = (27 - (to_string(fee_per_patient)).length());
            cout << "| " << fee_per_patient << setw(padding) << setfill(' ');

            padding = (14 - (to_string(years_of_experience)).length());
            cout << "| " << years_of_experience << setw(padding) << setfill(' ');

            cout << "|" << endl;

            full_name = "";
            specialization = "";
        }
        cout << "|=================|======================|============================|==================|====================|===================|==============|" << endl;

        cout << "Press 0 to return to the main menu: ";
        int l;
        cin >> l;
        fp.close();
    }

    void fire_doctor()
    {
    label15:
        system("cls");
        int doctor_to_fire;
        cout << "Enter the ID of the doctor : ";
        cin >> doctor_to_fire;

        fstream fp;
        fstream fp1;

        fp.open("Doctors.txt", ios ::in);
        if (!fp.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp1.open("temp.txt", ios ::out);
        if (!fp1.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string line;
        int line_to_show, check = 0;
        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {
            getline(fp, line);
            if (doctor_to_fire == stoi(line.substr(0, 3)))
            {
                check++;
                line_to_show = i;
                break;
            }
        }
        if (check == 0)
        {
            cout << "ID not found! Please Try again..." << endl;
            Sleep(2000);
            fp.close();
            goto label15;
        }

        // move the pointer to initial position
        fp.clear();
        fp.seekg(0);

        for (int i = 0; i < get_lines_count("Doctors.txt"); i++)
        {
            if (i == line_to_show)
            {
                getline(fp, line);
                continue;
            }
            else
            {
                getline(fp, line);
                fp1 << line << endl;
            }
        }

        fp.close();
        fp1.close();
        remove("Doctors.txt");
        rename("temp.txt", "Doctors.txt");

        fstream fp7;
        fstream fp8;
        fp7.open("passwords.txt", ios ::in);
        if (!fp7.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp8.open("p.txt", ios ::out);
        if (!fp8.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        string l_id;
        string l_pass;
        for (int i = 0; i < get_lines_count("passwords.txt"); i++)
        {
            if (i == line_to_show)
            {
                getline(fp7, line);
                continue;
            }
            else
            {
                getline(fp7, line);
                fp8 << line << endl;
            }
        }

        fp7.close();
        fp8.close();
        remove("passwords.txt");
        rename("p.txt", "passwords.txt");
    }

    void hire_doctor()
    {

        string full_name;
        string gender;
        int age;
        string specialization;
        int years_of_experience;
        float salary;
        float fee_per_patient;
        string password;

        int id;
        int room_number;

        id_room_assigner(room_number, id);

        // Hiring a doctor!
        system("cls");
        cin.ignore();
        cout << "Enter the name of doctor : ";
        getline(cin, full_name);

        cout << "Enter the age of doctor : ";
        cin >> age;

        cin.ignore();
        cout << "Enter the specialization of doctor : ";
        getline(cin, specialization);

        cout << "Enter the gender of doctor : ";
        cin >> gender;

        cout << "Enter the experience of doctor (years): ";
        cin >> years_of_experience;

        cout << "Enter the salary of doctor : ";
        cin >> salary;

        cout << "Enter the fee per patient which is charged by doctor : ";
        cin >> fee_per_patient;

        cin.ignore();
        cout << "Enter the password for doctor: ";
        getline(cin, password);

        fstream fp6;
        fp6.open("passwords.txt", ios ::app);
        if (!fp6.is_open())
        {
            cout << "Cannot open file !" << endl;
        }
        fp6 << id << " " << password << endl;
        fp6.close();

        // Counting lines of doctors.txt

        int total_lines = get_lines_count("Doctors.txt");

        Doctor doctor(id, room_number, full_name,
                      gender, age, specialization, years_of_experience, salary, fee_per_patient);

        all_doctors.push_back(doctor);

        fstream fp;

        fp.open("Doctors.txt", ios ::app);
        fp << id << " "
           << full_name << " "
           << room_number << " " << gender << " "
           << age << " " << specialization << " "
           << years_of_experience << " "
           << salary << " " << fee_per_patient << endl;

        fp.close();
    }

    void show_policies()
    {
        system("cls");

        Policy p1(101, "The Care Centre", 54, 1);
        p1.show_policies();
    }
};

void admin_menu(Admin &admin)
{

    int choice;
    while (choice != 14)
    {
    label9:
        system("cls");
        cout << endl;
        cout << "-------------- Admin Menu -----------" << endl;
        cout << "1) Show all doctors" << endl;
        cout << "2) Hire a doctor" << endl;
        cout << "3) Fire a doctor" << endl;
        cout << "4) Edit doctor" << endl;
        cout << "5) Show specific doctor credentials" << endl;
        cout << "6) Show all patients" << endl;
        cout << "7) Register a patient" << endl;
        cout << "8) Remove a patient" << endl;
        cout << "9) Edit patient" << endl;
        cout << "10) Show specific patient credentials" << endl;
        cout << "11) Show policies" << endl;
        cout << "12) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            admin.show_all_doctors();
            break;
        case 2:
            admin.hire_doctor();
            break;
        case 3:
            admin.fire_doctor();
            break;
        case 4:
            admin.edit_doctor();
            break;
        case 5:
            admin.show_specific_doctor_credentials();
            break;
        case 6:
            admin.show_all_patients();
            break;
        case 7:
            admin.register_patient();
            break;
        case 8:
            admin.remove_patient();
            break;
        case 9:
            admin.edit_patient();
            break;
        case 10:
            admin.show_specific_patient_credentials();
            break;
        case 11:
            admin.show_policies();
            break;
        case 12:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
            cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
            cout << "\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                            HOSPITAL MANAGEMENT SYSTEM                                 |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
            cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
            cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
            Sleep(3000);
            exit(0);
        default:
            cout << "Invalid input! Please try again!" << endl;
            Sleep(2000);
            goto label9;
            break;
        }
    }
}

void Main_Menu()
{
    Admin admin("Akuma", "Male", 29);

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    Sleep(3000);
label10:
    system("cls");

    int choice;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\n\n\t\t\t\t\t\tChoose your occupation: \n\n";
    cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
    cout << "\t\t\t\t\t\t|                                          	                  |\n";
    cout << "\t\t\t\t\t\t|             1  >> Admin                                         |\n";
    cout << "\t\t\t\t\t\t|             2  >> Doctor                                        |\n";
    cout << "\t\t\t\t\t\t|             3  >> Patient                                       |\n";
    cout << "\t\t\t\t\t\t|             4  >> Exit the Program                              |\n";
    cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
    cout << "\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        // admin and pass
        string user_name;
        string password;
    label1:
        password = "";

        cout << "Enter username : ";
        cin >> user_name;

        cout << "Enter password : ";

        char ch;

        ch = _getch();
        while (ch != 13)
        { // character 13 is enter
            if (ch == 8)
            { // character 8 is backspace
                if (!password.empty())
                {
                    password.pop_back();
                    cout << "\b \b"; // move cursor back, print space, move cursor back again
                }
            }
            else
            {
                password.push_back(ch);
                cout << '*';
            }
            ch = _getch();
        }

        if (password == admin.get_password() && user_name == admin.get_id())
        {
            cout << "\nAccess Granted! \n";
            system("PAUSE");
            system("CLS");
        }
        else
        {
            cout << "\nAccess Aborted...\nPlease Try Again!!\n";
            system("PAUSE");
            system("CLS");
            goto label1;
        }

        admin_menu(admin);
    }
    else if (choice == 2)
    {
    label2:
        try
        {
            Doctor loc_doctor;
            int ID;
            string password;

        label42:

            system("cls");
            password = "";
            int counter = 0;
            int loc_counter = 0;

            cout << "Enter your ID : ";
            cin >> ID;

            cout << "Enter password : ";

            char ch;

            ch = _getch();
            while (ch != 13)
            { // character 13 is enter
                if (ch == 8)
                { // character 8 is backspace
                    if (!password.empty())
                    {
                        password.pop_back();
                        cout << "\b \b"; // move cursor back, print space, move cursor back again
                    }
                }
                else
                {
                    password.push_back(ch);
                    cout << '*';
                }
                ch = _getch();
            }

            fstream fp6;
            string loc_id;
            string loc_pass;

            fp6.open("passwords.txt", ios ::in);
            if (!fp6.is_open())
            {
                cout << "Cannot open file !" << endl;
            }
            while (!fp6.eof())
            {
                fp6 >> loc_id;
                fp6 >> loc_pass;
                if (ID == stoi(loc_id) && password == loc_pass)
                {

                    loc_counter++;
                }
            }

            fp6.close();
            if (loc_counter == 0)
            {
                cout << "\nAccess Aborted...\nPlease Try Again!!\n";
                system("PAUSE");
                system("CLS");
                goto label42;
            }

            for (Doctor i : admin.get_all_doctors())
            {
                if (i.get_id() == ID)
                {
                    counter++;
                    cout << "\nWelcome " << i.get_full_name() << endl;
                    system("PAUSE");
                    system("CLS");
                    loc_doctor = i;
                    break;
                }
            }

            if (counter == 0)
            {
                throw "Sorry You are not registered yet!!!\nPlease Try Again.....";
            }
            else
            {
                loc_doctor.doctor_menu();
            }
        }
        catch (const char *error)
        {
            cout << endl
                 << error << endl;
            system("PAUSE");
            system("CLS");
            goto label2;
        }
    }
    else if (choice == 3)
    {
        system("cls");

    label3:
        try
        {
            Patient loc_patient;
            int MR_Number;
            int counter = 0;
            cout << "Enter your MR Number: ";
            cin >> MR_Number;

            for (Patient i : admin.get_all_patients())
            {
                if (i.get_MR_Number() == MR_Number)
                {
                    counter++;
                    cout << "\nWelcome " << i.get_full_name() << endl;
                    system("PAUSE");
                    system("CLS");
                    loc_patient = i;
                    break;
                }
            }

            if (counter == 0)
            {
                throw "Sorry You are not registered yet!!!\nPlease Try Again.....";
            }
            else
            {
                loc_patient.patientMenu();
            }
        }
        catch (const char *error)
        {
            cout << error << endl;
            system("PAUSE");
            system("CLS");
            goto label3;
        }
    }
    else if (choice == 4)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
        cout << "\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                            HOSPITAL MANAGEMENT SYSTEM                                 |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
        cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
        Sleep(3000);
        exit(0);
    }
    else
    {
        cout << "\t\t\t\t\t\tInvalid input! Please try again! " << endl;
        Sleep(2000);
        goto label10;
    }
}

int main()
{

    system("color 06");
    Main_Menu();

    return 0;
}
