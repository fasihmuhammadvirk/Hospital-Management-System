//libraries 
#include <iostream>
#include <string>
#include <fstream>
//#include <windows.h>
using namespace std;


// global variables
string ch_us, ch_pas, ch_doc, ch_did, ch_ps; int ch_id; 


//global variables to check the authentication of the doctor patient and doctor later in the code
bool ispatient;
bool isadmin; 
bool isdoc; 


//------------------------------------------------------------------------------------------------------------------//

// doctor classs contaning fucntion related to doctor
class Doctor { 

public:


// function for the docotor login athuenction 

	void Doc_Login() 
	{

		string ds, pss, gen, ag, dep, d_id;
		int n;

		//ifstream is used to open the file in the read mode
		//read is an object that we will use to read data from the file to store into variables
		ifstream read;

		cout << "Welcome to Login Info" << endl;
		cout << "Enter Your Name Dr :"; cin >> ch_doc; 
		cout << "Enter your password :"; cin >> ch_ps; 
		cout << "Enter your Department :\n"
		"1. Dental\n"
		"2. Accident & Emergency\n" 
		"3. Orthopaedics\n"
		"4. Psychiatry\n"
		"5. Physiotherapy\n"
		"-->"; cin >> ch_did;

		// if else to declare each docotr department an integer value

		if (ch_did == "Dental")
		{
			n = 1; 
		}
		else if (ch_did == "Accident & Emergency")
		{
			n = 2;
		}
		else if (ch_did == "Orthopaedics") 
		{
			n = 3; }
		else if (ch_did == "Psychiatry")
		{
			n = 4; 
		}
		else if (ch_did == "Physiotherapy") 
		{
			n = 5; 
		}
		else 
		{
			cout << "Invalid Department"; 
		}

		// switch statement to switch using the previous integere value of each depeartment
		//using the previous name and passowrd of the user and check if he is a doctor or not according to his department

		switch (n) 
		
		{

			//Checking Dental Login
			case 1:
			{

				//opening file in read mode 
				read.open("Dental.txt"); 

				//while loop use to read till the end of the file 
				//read.eof (end of file)
				
				while (!read.eof())
				
				{
					//reading each line one by one in the file using read object
					//storing each data in line in a variable

					read >> ds; //name 
					read >> pss;//password
					read >> gen;//gender
					read >> ag; //age 
					read >> dep;//department
					read >> d_id;//doctor id 

					//comparing the given name and password with the name and password in the file
					if (ch_us == ds && ch_pas == pss && ch_did == d_id)
					{
						//declaring the bool isdoc equal to true as the doctor is in the record
						isdoc = true;
						break; 
					}

					else 
					{
						cout << "Wrong Input" << endl;
						isdoc = false; 
					}
				}

				if (isdoc) 
				{
					cout << "You have been successfully logged in!" << endl; 
				}

				else
				{
					cout << "Wrong Input" << endl;
				} 

				read.close();
			}break; 

			//Checking Accident&Emergency Login
			case 2: 
			{

				read.open("Accident&Emergency.txt"); 

				while (!read.eof())
					{
						read >> ds; 
						read >> pss; 
						read >> gen; 
						read >> ag; 
						read >> dep; 
						read >> d_id;

						if (ch_us == ds && ch_pas == pss && ch_did == d_id) 
						{
							isdoc = true;
							break; 
						}

						else 
						{
							cout << "Wrong Input" << endl;
							isdoc = false; 
						}

					}

				if (isdoc) 
				{
					cout << "You have been sucessfully logged in!" << endl; 
				}
				else
				{
					cout << "Wrong Input" << endl; 
				}
				read.close(); 

			}break;

			//Checking Orthopadedic Login
			case 3: 
			{
				read.open("Orthopaedics.txt"); 

				while (!read.eof())
					{
						read >> ds; 
						read >> pss; 
						read >> gen; 
						read >> ag; 
						read >> dep; 
						read >> d_id;

						if (ch_us == ds && ch_pas == pss && ch_did == d_id) 
						{
							isdoc = true;
							break; 
						}

						else 

						{
							cout << "Wrong Input" << endl;
							isdoc = false; 
						}

					}

				if (isdoc) 
				{
					cout << "You have been sucessfully logged in!" << endl; 
				}

				else 
				{
					cout << "Wrong Input" << endl; 
				}

				read.close(); 
			}break;

			//Checking Psychiatry Login
			case 4: 

			{
				read.open("Psychiatry.txt"); 

				while (!read.eof())

					{
						read >> ds; 
						read >> pss; 
						read >> gen; 
						read >> ag; 
						read >> dep; 
						read >> d_id;

						if (ch_us == ds && ch_pas == pss && ch_did == d_id) 
						{
							isdoc = true;
							break;
						}

						else
						{
							cout << "Wrong Input" << endl;
							isdoc = false; 
						}

					}

				if (isdoc) 
				{
					cout << "You have been sucessfully logged in!" << endl; 
				}

				else 
				{
					cout << "Wrong Input" << endl; 
				}

				read.close(); 
			}break;

			//Checking Physiotherapy Login
			case 5: 

			{
				read.open("Physiotherapy.txt"); 

				while (!read.eof())
				{
					read >> ds; 
					read >> pss; 
					read >> gen; 
					read >> ag; 
					read >> dep; 
					read >> d_id;

					if (ch_us == ds && ch_pas == pss && ch_did == d_id) 
					{
						isdoc = true;
						break; 
					}

					else 
					{
						cout << "Wrong Input" << endl;
						isdoc = false; 
					}

				}

				if (isdoc) 
				{
					cout << "You have been sucessfully logged in!" << endl; 
				}

				else 
				{
					cout << "Wrong Input" << endl; 
				}

				read.close(); 
			}break;

			default: 
			{
				cout << "Invalid option."; 
			}
			break; 
		}

	}

	//function to view the apointment of a doctor 
	void view_doctor_appointment() 

	{

		int departmentno;

		cout << "Enter The Department Of Which Doctor Whose Appointment You Want To Check :\n";
		
		cout << "Press 1. Dental\n"
		"Press 2. Accident & Emergency\n" "Press 3. Orthopaedics\n"
		"Press 4. Psychiatry\n"
		"Press 5. Physiotherapy\n";
		
		cout << "-> ";
		cin >> departmentno; 

		//switch statment use to switch to each department doctor to see his appointments
		switch (departmentno) 
		
		{

			//dental 	
			case 1:
			{

				string doc1, doc2; 
				int Named;
				
				//ifstream use to open a file in the read mode 
				// read is an object of ifstream to read the data from the file

				ifstream read;

				//opening the file in the read mode
				read.open("Dental.txt");

				cout << "Doctor(s) Available :" << endl; 

				//while loop use till end of the file 
				while (!read.eof()) 
				{
					//if there is no data in the files it will break 
					if (doc1 == "\0" && doc2 == "\0") 
					{ 
						cout << "No Doctor Now. \n"; 
						break;
					}

					read >> doc1; 
					read >> doc2; 
					cout << endl;
				}

				cout << "Press 1 to check the Appointment of Doctor 1\n And 2 to check the Appointment of 2 Doctor"; 
				cin >> Named;
				
				string username, password, Gender; int Age, Time;
				if (Named == 1) 
				{
					read.open(doc1 + "txt");
				}
				else 
				{
					read.open(doc2 + "txt");
				}

				cout << "Checking the Appointment with Patients :"; read >> username;
				read >> Gender;
				read >> Age;
				read >> Time;
				read.close();
			}

			//Accident&Emergency
			case 2: 
			{
				string doc1, doc2; int Named;
				ifstream read; read.open("Accident&Emergency.txt"); 

				cout << "Doctor(s) Availabe :" << endl; 

				while (!read.eof()) 
				{

					if (doc1 == "\0" && doc2 == "\0") 
					{ 
						cout << "No Doctor Now. \n"; break;
					}

					read >> doc1; read >> doc2; cout << endl;
				}

				cout << "Press 1 to check the Appointment of Doctor 1\n And 2 to check the Appointment of 2 Doctor"; cin >> Named;

				string username, password, Gender; int Age, Time;
				if (Named == 1) 
				{
					read.open(doc1 + "txt");
				}

				else
				{
					read.open(doc2 + "txt");
				}

				cout << "Checking the Appointment with Patients :"; read >> username;
				read >> Gender;
				read >> Age;
				read >> Time;
				read.close();

			}

			//Orthopaedics
			case 3: 
			{
				string doc1, doc2; int Named;
				ifstream read; read.open("Orthopaedics.txt");

				cout << "Doctor(s) Availabe :" << endl; 

				while (!read.eof()) 

					{
					if (doc1 == "\0" && doc2 == "\0") 
					{ 
						cout << "No Doctor Now. \n"; break;
					}

					read >> doc1; read >> doc2; cout << endl;
					}

				cout << "Press 1 to check the Appointment of Doctor 1\n And 2 to check the Appointment of 2 Doctor"; cin >> Named;
				string username, password, Gender; int Age, Time;

				if (Named == 1) 
				{
					read.open(doc1 + "txt"); 
				}

				else 
				{
					read.open(doc2 + "txt");
				}

				cout << "Checking the Appointment with Patients :"; read >> username;
				read >> Gender;
				read >> Age;
				read >> Time;
				read.close();
			}

			//Psychiarty
			case 4: 
			{
				string doc1, doc2; int Named;
				ifstream read; read.open("Psychiatry.txt");

				cout << "Doctor(s) Availabe :" << endl; 

				while (!read.eof()) 
				{
					if (doc1 == "\0" && doc2 == "\0") 
					{ 
						cout << "No Doctor Now. \n"; 
						break;
					}
					read >> doc1; read >> doc2; 
					cout << endl;
				}

				cout << "Press 1 to check the Appointment of Doctor 1\n And 2 to check the Appointment of 2 Doctor"; 
				cin >> Named;
				string username, password, Gender; 
				int Age, Time;

				if (Named == 1) 
				{
					read.open(doc1 + "txt");
				}

				else 
				{
					read.open(doc2 + "txt");
				}

				cout << "Checking the Appointment with Patients :"; read >> username;
				read >> Gender;
				read >> Age;
				read >> Time;
				read.close();
			}

			//Physotherapy 
			case 5: 
			{
				string doc1, doc2; int Named;
				ifstream read; read.open("Physiotherapy.txt");
				cout << "Doctor(s) Availabe :" << endl; 

				while (!read.eof()) 
				{
					if (doc1 == "\0" && doc2 == "\0") 
					{ 
						cout << "No Doctor Now. \n"; break;
					}

					read >> doc1; read >> doc2; 
					cout << endl;
				}

				cout << "Press 1 to check the Appointment of Doctor 1\n And 2 to check the Appointment of 2 Doctor"; 
				cin >> Named;
				string username, password, Gender; int Age, Time;

				if (Named == 1) 
				{
				read.open(doc1 + "txt"); 
				}

				else 
				{
				read.open(doc2 + "txt");
				}

				cout << "Checking the Appointment with Patients :"; read >> username;
				read >> Gender;
				read >> Age;
				read >> Time;
				read.close();
			} 

			// default
			default: 
			{
				cout << "Invalid option."; 
			}

		}
	}
};


//------------------------------------------------------------------------------------------------------------------//

// Patient class contaning all function related to patient
class Patient 

{ 

public:


	//function to athunticated the paitent information to login 
	void Paitient_Login() 

	{

		string us, ps, ge, dep; 
		int id, ag;
		ifstream read;

		read.open("Patient.txt");

		cout << "Welcome to Login Info :" << endl; 
		cout << "Enter Your Name :"; cin >> ch_us; 
		cout << "Enter your password :"; cin >> ch_pas; 
		cout << "Enter your patient ID :"; cin >> ch_id; 

		//read till end of the file 
		while (!read.eof())
			{

				read >> us;//username 
				read >> ps;//password
				read >> ge;//gender
				read >> ag;//age
				read >> dep;//department
				read >> id;//patient id 

				//comparing username, password and patient id that user enter with the data in the file 
				if (ch_us == us && ch_pas == ps && ch_id == id) 
				{
					ispatient = true;
					break; 
				}

				else 
				{
					ispatient = false; 
				}

			}

		if (ispatient) 
		{
			cout << "You Have Been Sucessfully Logged In!" << endl; 
		}

		else 
		{
			cout << "Wrong Input" << endl; 
		}

		read.close();

	}

};

//------------------------------------------------------------------------------------------------------------------//

//main admin classs contain function of admin and aslo inherit function of all other classes e.g patient and doctor

class Administration : public Doctor, public Patient 
{

public:


	//function to authnticate the admin login information
	void Adminstration_Login() 

	{

		//pre defined user password and username
		string adm = "adminadmin";
		string pass = "1234";

		string adm_us, adm_ps;

		cout << "\t\tWelcome to login Info" << endl;

		cout << "Enter Username :"; cin >> adm_us;
		cout << "Enter Your password :"; cin >> adm_ps; 

		if (adm_us == adm && adm_ps == pass)
		{
			cout << "You Have Been Logged in Sucessfully!" << endl; 
			isadmin = true;
		} 

		else 
		{
			cout << "Incorrect Username or Password";
			isadmin = false; 
		}

	}


	//function to add the doctor in the record of the hospital e.g in the file
	void Add_Doctor() 

	{

		string username, password, Gender, Department, D_id;
		int age;
		int departmentno;

		cout << "Note: Add Only Two Doctors Of Each Department\n";
		cout << "Enter The Department of which doctor you want to add:\n"; cout << "Press 1. Dental\n"
		"Press 2. Accident & Emergency\n" "Press 3. Orthopaedics\n"
		"Press 4. Psychiatry\n"
		"Press 5. Physiotherapy\n";
		cout << "-> ";
		cin >> departmentno;

		switch (departmentno) 
		{
			case 1:
			{
				cout << "Add Doctor Info\n"; 
				cout << "Enter His Name :"; cin >> username;
				cout << "Enter His Password :"; cin >> password;
				cout << "Enter His Gender :"; cin >> Gender;
				cout << "Enter His Age :"; cin >> age;
				
				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 
				
				ofstream create; 

				//opening the file in the append
				create.open("Dental.txt", ios::app); 

				//apending the data using variables in the file 
				create << username << " ";
				create << password << " ";
				create << Gender << " ";
				create << age << " ";
				create << Department << endl;
				create.close(); 

			}break;

			case 2: 
			{
				cout << "Add Doctor Info\n"; 
				cout << "Enter His Name :"; cin >> username;
				cout << "Enter His Password :"; cin >> password;
				cout << "Enter His Gender :"; cin >> Gender;
				cout << "Enter His Age :"; cin >> age;

				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 

				ofstream create; 
				create.open("Accident&Emergency.txt", ios::app); 

				create << username << " ";
				create << password << " ";
				create << Gender << " ";
				create << age << " ";
				create << Department << endl;
				create.close();

			}break;

			case 3: 
			{

				cout << "Add Doctor Info\n"; 
				cout << "Enter His Name :"; cin >> username;
				cout << "Enter His Password :";cin >> password;
				cout << "Enter His Gender :"; cin >> Gender;
				cout << "Enter His Age :"; cin >> age;

				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 
				
				ofstream create; 
				create.open("Orthopaedics.txt", ios::app); 
				
				create << username << " ";
				create << password << " ";
				create << Gender << " ";
				create << age << " ";
				create << Department << endl;
				create.close(); 
			}break;

			case 4: 
			{
				cout << "Add Doctor Info\n"; 
				cout << "Enter His Name :"; cin >> username;
				cout << "Enter His Password :"; cin >> password;
				cout << "Enter His Gender :"; cin >> Gender;
				cout << "Enter His Age :"; cin >> age;

				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 

				ofstream create; 
				create.open("Psychiatry.txt", ios::app); 

				create << username << " ";
				create << password << " ";
				create << Gender << " ";
				create << age << " ";
				create << Department << endl;
				create.close(); 
			}break;

			case 5: 
			{
				cout << "Add Doctor Info\n"; cout << "Enter His Name :"; cin >> username;
				cout << "Enter His Password :"; cin >> password;
				cout << "Enter His Gender :"; cin >> Gender;
				cout << "Enter His Age :"; cin >> age;
				
				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 

				ofstream create; 
				create.open("Physiotherapy.txt", ios::app);

				create << username << " "; 
				create << password << " "; 
				create << Gender << " "; 
				create << age << " ";
				create << Department << endl;
				create.close(); 

			}break;
			
			default: 
			{
				cout << "Invalid option."; 
			}break;
		}
	}

	//adding the patient information in the file 
	void Add_patient() 
	{
		string username, password, Gender, patientoff; 
		int ID, Age;

		cout << "Adding patient Info\n";
		cout << "Enter Your Name :"; cin >> username;
		cout << "Enter Your Password :"; cin >> password;
		cout << "Enter Your Gender :"; cin >> Gender;
		cout << "Enter Your Age :"; cin >> Age;

		cout << "You want to concern the doctor of which Department :\n"; 

		cout << "1. Dental\n"
		"2. Accident & Emergency\n" "3. Orthopaedics\n"
		"4. Psychiatry\n"
		"5. Physiotherapy\n";

		cout << "-> ";
		
		cin >> patientoff;
		
		//to generate random id for the patient

		ID = (rand() % 1000) + 1;

		cout << "Your Patient ID is = " << ID << endl; 

		//ofstream to open the file in the write mode
		//create is an object of the file to write the variable data in the file 
				
		ofstream create;
		create.open("Patient.txt", ios::app);

		create << username << " ";
		create << password << " ";
		create << Gender << " ";
		create << Age << " ";
		create << ID << " ";
		create << patientoff << endl;
		create.close();
	}

	//ading the apppointment of the patient with the doctor in the file 
	void Add_Appointment() 
	{
		int departmentno;

		cout << "Enter The Department of which doctor you want to Make an appointment:\n";
		cout << "Press 1. Dental\n"
		"Press 2. Accident & Emergency\n" "Press 3. Orthopaedics\n"
		"Press 4. Psychiatry\n"
		"Press 5. Physiotherapy\n";
		cout << "-> ";
		cin >> departmentno;

		switch (departmentno) 
		{ 
			case 1: 
			{
				string doc1, doc2; 
				int Named;

				//ifstream to open the file in the read mode 
				//read object to read the iformation from the file and storing them in variables using read object

				ifstream read;
				read.open("Dental.txt");


				cout << "Doctor(s) Availabe :" << endl; 

				while (!read.eof()) 
				{
					if (doc1 == "\0" && doc2 == "\0") 
					{
						cout << "No Doctor Availabe Now. \n"; 
						break;
					}
					read >> doc1; 
					read >> doc2; 
					cout << endl;
				}

				cout << "Press 1 to make the Appointment with Doctor 1\n And 2 to make Appointment with Doctor 2"; 
				cin >> Named;

				string username, password, Gender; 
				int Age, Time; 

				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 
				
				ofstream create;

				if (Named == 1)
				{
					create.open(doc1 + "txt"); 
				}
				else 
				{
					create.open(doc2 + "txt");
				}

				cout << "Enter Patient Detail and Time\n";
				cout << "Adding patient Info\n";
				cout << "Enter His Name :"; cin >> username; 
				cout << "Enter His Gender :"; cin >> Gender; 
				cout << "Enter His Age :"; cin >> Age;
				cout << "Enter the Time :"; cin >> Time; 

				create << username << " ";
				create << Gender << " "; create << Age << " "; create << Time << endl; 
				create.close();

			}break; 

			case 2: 
			{
				string doc1, doc2; int Named;


				//ifstream to open the file in the read mode
				//read is an object of the file to read the variable data in the file 
				
				ifstream read; 

				read.open("Accident&Emergency.txt"); 
				cout << "Doctor(s) Availabe :" << endl; 

				while (!read.eof()) 

				{
					if (doc1 == "\0" && doc2 == "\0") 
					{
						cout << "No Doctor Availabe Now. \n"; break;
					}
					read >> doc1; read >> doc2; cout << endl;
				}
				cout << "Press 1 to make the Appointment with Doctor 1\n And 2 to make Appointment with Doctor 2"; cin >> Named;

				string username, password, Gender; 
				int Age, Time; 

				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 
				
				ofstream create;

				if (Named == 1)
				{
					create.open(doc1 + "txt"); 
				}
				else 
				{
					create.open(doc2 + "txt");
				}

				cout << "Enter Patient Detail and Time\n";
				cout << "Adding patient Info\n";
				cout << "Enter His Name :"; cin >> username; 
				cout << "Enter His Gender :"; cin >> Gender; 
				cout << "Enter His Age :"; cin >> Age;
				cout << "Enter the Time :"; cin >> Time; 

				create << username << " ";
				create << Gender << " ";
				create << Age << " ";
				create << Time << endl;
				create.close();
			}break;

			case 3:
			{

				string doc1, doc2; int Named;
				ifstream read; read.open("Orthopaedics.txt");
				cout << "Doctor(s) Availabe are :" << endl; 


				while (!read.eof()) 
				{
					if (doc1 == "\0" && doc2 == "\0") 
					{
						cout << "No Doctor Availabe Now. \n"; break;
					}
					read >> doc1; 
					read >> doc2; 
					cout << endl;
				}


				cout << "Press 1 to make the Appointment with Doctor 1\n And 2 to make Appointment with Doctor 2"; cin >> Named;
				string username, password, Gender;
				int Age, Time; 
				
				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 

				ofstream create;
				if (Named == 1)
				{
					create.open(doc1 + "txt"); 
				}
				else 
				{
					create.open(doc2 + "txt");
				}


				cout << "Enter Patient Detail and Time\n";
				cout << "Adding patient Info\n";
				cout << "Enter His Name :"; cin >> username; 
				cout << "Enter His Gender :"; cin >> Gender; 
				cout << "Enter His Age :"; cin >> Age;
				cout << "Enter the Time :"; cin >> Time; 
				
				create << username << " ";
				create << Gender << " ";
				create << Age << " ";
				create << Time << endl;
				create.close();
			}break;
			
			case 4: 
			{
				string doc1, doc2; int Named;

				ifstream read;
				read.open("Psychiatry.txt");
				
				cout << "Doctor(s) Availabe are :" << endl; 
				
				while (!read.eof()) 
				{
					if (doc1 == "\0" && doc2 == "\0") 
					{
						cout << "No Doctor Availabe Now. \n";
						break; 
					}
					read >> doc1; 
					read >> doc2; 
					cout << endl;
				}
				
				cout << "Press 1 to make the Appointment with Doctor 1\n And 2 to make Appointment with Doctor 2"; cin >> Named;
				string username, password, Gender; 
				int Age, Time; 
				
				//ofstream to open the file in the write mode
				//create is an object of the file to write the variable data in the file 
					
				ofstream create;


				if (Named == 1)
				{
					create.open(doc1 + "txt"); 
				}
				else 
				{
					create.open(doc2 + "txt");
				}


				cout << "Enter Patient Detail and Time\n";
				cout << "Adding patient Info\n";
				cout << "Enter His Name :"; cin >> username; cout << "Enter His Gender :"; cin >> Gender; cout << "Enter His Age :"; cin >> Age;
				cout << "Enter the Time :"; cin >> Time; 
				
				create << username << " ";
				create << Gender << " ";
				create << Age << " ";
				create << Time << endl;
				create.close();


			}break;
			
			case 5: 
			{
				string doc1, doc2; int Named;


				
				ifstream read; 
				
				read.open("Physiotherapy.txt");
				cout << "Doctor(s) Availabe are :" << endl; 


				while (!read.eof()) 
				{
					if (doc1 == "\0" && doc2 == "\0") 
					{
						cout << "No Doctor Availabe Now. \n"; break;
					}

					read >> doc1; 
					read >> doc2;
					cout << endl;
				}

				cout << "Press 1 to make the Appointment with Doctor 1\n And 2 to make Appointment with Doctor 2"; cin >> Named;

				string username, password, Gender; 
				int Age, Time; 
				
				ofstream create;

				if (Named == 1)
				{
					create.open(doc1 + "txt"); 
				}
				else 
				{
					create.open(doc2 + "txt");
				}

				cout << "Enter Patient Detail and Time\n";
				cout << "Adding patient Info\n";
				cout << "Enter His Name :"; cin >> username; 
				cout << "Enter His Gender :"; cin >> Gender; 
				cout << "Enter His Age :"; cin >> Age;
				cout << "Enter the Time :"; cin >> Time; 
				
				create << username << " ";
				create << Gender << " ";
				create << Age << " ";
				create << Time << endl;
				create.close();
			}break;
			
			default: 
			{
				cout << "Invalid option."; 
			}break; 
		}
	}



	//function to view the doctor in the hospital 
	void View_Doctors() 
	{
		ifstream read;

		int departmentno;

		cout << "Enter The Department of which doctor you want to View:\n"; 
		cout << "Press 1. Dental\n"
		"Press 2. Accident & Emergency\n" 
		"Press 3. Orthopaedics\n"
		"Press 4. Psychiatry\n"
		"Press 5. Physiotherapy\n";
		cout << "-> ";
		cin >> departmentno;

		switch (departmentno)
		{
			case 1:
			{ 
				string username, password, Gender, Department, D_id; 
				int age;
				read.open("Dental.txt"); 
				
				while (!read.eof())
				{
					read >> username; 
					read >> password; 
					read >> Gender; 
					read >> age;
					read >> Department;
					read.close(); 
				}
			}break; 
			
			case 2: 
			{
				string username, password, Gender, Department, D_id; 
				int age;
				read.open("Accident&Emergency.txt"); 

				while (!read.eof())
				{
					read >> username; 
					read >> password; 
					read >> Gender; 
					read >> age;
					read >> Department;
					read.close(); 
				}

			}break; 
			
			case 3: 
			{
				string username, password, Gender, Department, D_id; int age;
				read.open("Orthopaedics.txt"); 
				while (!read.eof())
				{
					read >> username; 
					read >> password; 
					read >> Gender; 
					read >> age;
					read >> Department;
					read.close(); 
				}

			}break;

			case 4: 
			{
				string username, password, Gender, Department, D_id; int age;
				read.open("Psychiatry.txt"); 

				while (!read.eof())
				{
					read >> username; 
					read >> password; 
					read >> Gender; 
					read >> age;
					read >> Department;
					read.close(); 
				}

			}break; 
			
			case 5: 
			{
				string username, password, Gender, Department, D_id; int age;
				read.open("Physiotherapy.txt"); 
				
				while (!read.eof())
				{
					read >> username; 
					read >> password; 
					read >> Gender; 
					read >> age;
					read >> Department;
					read.close(); 
				}

			}break; 
			
			default: 
			{
				cout << "Invalid option."; 
			}break;

		}
	}

	//function to view the patients 
	void View_Patient() 
	{
		string username, password, Gender, Age, ID, patientoff; 
		
		ifstream read;
		read.open("Patient.txt");

		while (!read.eof())
			{
				read >> username; 
				read >> password; 
				read >> Gender;
				read >> Age;
				read >> ID;
				read >> patientoff; 
				read.close();

			}
	}

	//function to delete the data in the files
	void del_data() 
	{
		int decision;
		cout << "\t\tWhose Data You Want To Remove?\n"; cout << "\t\tPress 1 to Remove Doctor Data\n"
		"\t\tPress 2 to Remove Patient Data\n"; cout << "-->"; cin >> decision;
		switch (decision)
		{
			case 1: 
			{
				int departmentno;

				cout << "Enter The Department of Which Doctor Data You Want To Remove:\n";
				cout << "Press 1. Dental\n"
				"Press 2. Accident & Emergency\n" "Press 3. Orthopaedics\n"
				"Press 4. Psychiatry\n"
				"Press 5. Physiotherapy\n";
				cout << "-> ";
				cin >> departmentno; 
				
				switch (departmentno) 
				{
					case 1:
					{
						cout << "\t\tRemoving The Dental Doctor's Data.\n";
						remove("Dental"); 
					}break; 
					
					case 2: 
					{
						cout << "\t\tRemoving The Accident&Emergency Doctor's Data.\n";
						remove("Accident&Emergency"); 
					}break; 
					
					case 3: 
					{
						cout << "\t\tRemoving The Orthopaedics Doctor's Data.\n";
						remove("Orthopaedics");
					}break; 
					
					case 4: 
					{
						cout << "\t\tRemoving The Psychaitry Doctor's Data.\n";
						remove("Psychiatry"); 
					}break; 
					
					case 5: 
					{
						cout << "\t\tRemoving The Physiotherapy Doctor's Data.\n";
						remove("Physiotherapy"); 
					}break;

				}

			}break; 

			case 2: 
			{
				cout << "\t\tRemoving Patient Data From Records\n"; 
				remove("Patient.txt");

			}break; 
			
			default: 
			{
				cout << "Wrong Input"; 
			}break;
		}
	}
} Adm;

//------------------------------------------------------------------------------------------------------------------//

//function to call or perform  all the function as an admin 
void adm_fun() 
{
	int decision, choice; 
	
	do 
	{
		cout << "\t\tWelcome To Adminstration Profile\n";
		cout << "\t\tEnter Your Choice, What You Want To Do?\n"; cout << "\t\tPress 1 To Add Doctor's Data In Record\n"
		"\t\tPress 2 TO Add Patient's Data In Record\n" "\t\tPress 3 To Add An Appointment\n" "\t\tPress 4 To View Doctor List\n"
		"\t\tPress 5 To View Patient List\n"
		"\t\tPress 6 To View Appointment\n"
		"\t\tPress 7 To Delete Data\n"; cout << "-->"; cin >> decision; 
		
		switch (decision)
		{
			case 1: 
			{
				Adm.Add_Doctor(); 
			}break;

			case 2: 
			{
				Adm.Add_patient(); 
			}break;

			case 3: 
			{
				Adm.Add_Appointment(); 
			}break;

			case 4: 
			{
				Adm.View_Doctors(); 
			}break;

			case 5: 
			{
				Adm.View_Patient(); 
			}break;

			case 6: 
			{
				Adm.view_doctor_appointment(); 
			}break;

			case 7: 
			{
				Adm.del_data(); 
			}break;

			default: 
			{
				cout << "Invalid option."; 
			}
		}
		cout << "Do You want to do Another Task :\n" "If Yes Press 1\n"
		"If No Press 0\n";
		cout << "->"; cin >> choice; 
	} while (choice != 0);
}

//function to call or perform the function as a patient
void pat_fun() 
{

	int decision, choice; 
	do 
	{
		cout << "\t\tWelcome to Patient Profile\n";
		cout << "\t\tPress 1 To Make an Appointment\n"
		"\t\tPress 2 to View Appointment\n"; cout << "-->"; cin >> decision;

		if (decision == 1)
		{
			Adm.Add_Appointment(); 
		}

		else if (decision == 2) 
		{
			Adm.view_doctor_appointment();
		}
		else 
		{
			cout << "Wrong Input\n"; 
		}

		cout << "Do You want to do Another Task :\n" "If Yes Press 1\n"
		"If No Press 0\n";
		cout << "->"; cin >> choice; 
	} while (choice != 0);
}

//function to perform or call function as a doctor 
void doc_fun() 
{
	int decision, choice; 
	do 
	{
		cout << "\t\tWelcome to Doctor Profile\n"; cout << "\t\tPress 1 To View Patient\n"
		"\t\tPress 2 To View Appointment\n"; cout << "-->"; cin >> decision;

		if (decision == 1) 
		{
			Adm.View_Patient(); 
		}
		else if (decision == 2) 
		{
			Adm.view_doctor_appointment(); 
		}
		else 
		{
			cout << "Wrong Input\n"; 
		}
		cout << "Do You want to do Another Task :\n" "If Yes Press 1\n"
		"If No Press 0\n";
		cout << "->"; 
		cin >> choice; 

	}while (choice != 0);
}

//------------------------------------------------------------------------------------------------------------------//

//main body 
int main() {

	int choice;
	cout << "\n\t\t\tHit: Username:adminadmin Password:1234"; cout << endl;
	cout << "\n\t\t\tWelcome to the IST Medical Centre"; cout << endl;

	//to add color to the text 
	//maywork or maynot depend on your machine and IDE
	system("Color 7C");
	
	//goto statment
	Home:

	cout << "\t\t\t\tWelcome to the Login\n";
	cout << endl;
	cout << "\n\t\tPress 1 to Login as Adminstration\n"
	"\n\t\tPress 2 to Login as Doctor\n"
	"\n\t\tPress 3 to Login as Patient\n"
	"\n\t\tPress 4 to Register if you haven't already\n" 
	"\n\t\tPress 5 To Exit\n" << endl;
	cout << "->"; cin >> choice;

	switch (choice)
	{

		case 1:
		{
			Adm.Adminstration_Login();
		}break; 

		case 2: 
		{
			Adm.Doc_Login(); 
		}break;

		case 3: 
		{
			Adm.Paitient_Login(); 
		}break;

		case 4: 
		{
			Adm.Add_patient(); 
		}break;

		case 5: 
		{
			exit(0); 
		}

		default: 
		{
			cout << "Invalid option."; 
			goto Home;
		}break;

	}


	//checking if the authentication is true the it call the function of doctor, patient and admin
	if (isadmin) 
	{
	adm_fun();
	goto Home; 
	}

	if (isdoc) 
	{
	doc_fun();
	goto Home; 
	}

	if (ispatient) 
	{
	pat_fun();
	goto Home; 
	}

}
