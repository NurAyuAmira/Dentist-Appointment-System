#include "windows.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include "person.h"
#include "schedule.h"
#include "dentist.h"
#include "client.h"
#include "appointment.h"
#include "admin.h"
#include "menusAndHeaders.h"
using namespace std;

int main()
{
    List schudele;
    DentistList dentist;
    ClientList client;
    Client p;
    AppointmentList *appointment = new AppointmentList();

	//A combination of ofstream and ifstream: creates, reads, and writes to files
    fstream file, file2, file3;
    
    // Create and open a text file
    file.open("clients.txt");
    file2.open("dentist_list.txt");
    file3.open("dentist_schedule.txt");

    string id, firstName, lastName, gender, dateOfBirth, phoneNumber;
    string day, startTime, endTime, status;
    int choice, user;
    int isClient = 1;
    int isDentist = 2;
    int isAdmin = 3;
    int i = 6;

    // reading Client data from file
    while (getline(file, id, '\n'))
    {
        file >> id >> firstName >> lastName >> gender >> dateOfBirth >> phoneNumber;
        client.InsertNode(id, firstName, lastName, gender, dateOfBirth, phoneNumber);
    }

    while (getline(file3, id, '\n'))
    {

        file3 >> id >> day >> startTime >> endTime >> status;
        schudele.InsertNode(id, day, startTime, endTime, status);
    }

    // reading dentist data from file
    while (getline(file2, id, '\n'))
    {

        file2 >> id >> firstName >> lastName >> gender >> dateOfBirth >> phoneNumber;
        dentist.InsertNode(schudele, i, id, firstName, lastName, gender, dateOfBirth, phoneNumber);
    }

    do
    {
        mainMenu();
        cin >> user;
        do
        {
            if (user == isClient)
            {

                clientMenu();
                cin >> choice;
            }
            else if (user == isDentist)
            {
                dentistMenu();
                cin >> choice;
            }
            else if (user == isAdmin)
            {
                adminMenu();
                cin >> choice;
            }
            else if (user == 4)
            {
                Sleep(1000); //based on milisecond 
                cout <<endl<< "\t\t\t ** Thank You For Using The System :) ** "<<endl<<endl;
                Sleep(2000);

                return 0;
            }
            else
            {
            	cout <<endl<< " ** Sorry This Option Is Not Available ** " <<endl;
			}
                

            switch (choice)
            {
            	//New Record
	            case 1: 
	                if (user == isClient)
	                {
	                    dentistTable2Headers();
	                    dentist.displaySchedul();
	                    cout << "----------------------------------------------------------------------------------------------------------"<<endl;
	                    cout <<endl<< "Enter The Schedule ID : ";
	                    cin >> id;
	                    int index;
	                    Dentist *d = dentist.findNode(id, index);
	                    Schedule *s;
	                    if (d != NULL)
	                    {
	                        s = d->schedule[index];
	
	                        p.setClientInfo();
	                        client.InsertNode(p.getId(), p.getFirstName(), p.getLastName(), p.getGender(), p.getDateOfBirth(), p.getPhoneNumber());
	                        appointment->InsertNode(&p, d, s);
	                        cout <<endl;
	                        
	                        Sleep(500);
	                        cout <<endl<< " ** Booked Successfully ** "<<endl;
	                        cout <<endl<< " -- Your Booking Information -- "<<endl<<endl<<endl;
	                        
	                        clientBookingTableHeaders();
	
	                        appointment->displayAppointments();
	
	                        Sleep(2000);
	                    }
	                    else
	                        cout <<endl<< " ** Sorry The Appointment You Choose Is Not Avaliable ** "<< endl;
	
	                    break;
	                }
	                
	
	                else if (user == isDentist)
	                {
	                    clientBookingTableHeaders();
	                    if (appointment != NULL)
	                    {
	                        appointment->displayAppointments();
	                    }
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl;
	                    Sleep(2000);
	                }
	
	                else if (user == isAdmin) 
	                {
	
	                    client.displayList();
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
	                    Sleep(2000);
	                }
	                break;
	
				//Display All Records
	            case 2: 
	                if (user == isClient)
	                {
	                    int pos;
	                    Sleep(500);
	                    dentistTableHeaders();
	                    dentist.displaySchedul();
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl;
	
	                    Sleep(2000);
	                }
	                if (user == isDentist)
	                {
	                    cout << endl<<endl
	                         << "Enter Client First Name : ";
	                    cin >> firstName;
	                    cout << endl<< endl;
	                    Sleep(500);
	                    client.searchClientInfoByName(firstName);
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
	                    Sleep(2000);
	                }
	                if (user == isAdmin)
	                {
						cout<<endl<<endl;
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl;
	                    dentistInfoTableHeaders();
	
	                    dentist.displayList();
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl;
	                    Sleep(2000);
	                }
	
	                break;
	
	            case 3: 
	                if (user == isClient) //search dentist by name
	                {
	                    int pos1;
	                    int pos2;
	                    cout << endl
	                         << "Enter the Dentist First Name : ";
	                    cin >> firstName;
	                    Sleep(500);
	                    dentistTableHeaders2();
	                    dentist.findByFirstName(firstName);
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl;
	                    Sleep(2000);
	                }
	                if (user == isDentist) //search dentist by id
	                {
	                    cout <<endl<<endl
	                         << "Enter Client ID : ";
	                    cin >> id;
	
	                    Sleep(500);
	                    
	                    client.searchClientInfoById(id);
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
	                    Sleep(2000);
	                }
	                if (user == isAdmin) //search dentist by name
	                {
	                	cout<<endl;
	                    cout << "Enter the Dentist First Name : ";
	                    cin >> firstName;
	                    Sleep(500);
	                    dentistInfoTableHeaders();
	
	                    dentist.searchDentistInfoByName(firstName);
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
	                    Sleep(2000);
	                }
	
	                break;
	
	            case 4: 
	                if (user == isClient || user == isAdmin) //Search available doctor 
	                {
	                    Sleep(500);
	                    dentistTableHeaders();
	                    dentist.findAvialableDentist();
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
	                    Sleep(2000);
	                }
	                if (user == isDentist) //Update Schedule 
	                {
	                    Sleep(500);
	                    cout <<endl<< "Fill In Your Schedule Details"<<endl;
	
	                    cout <<endl<< "Enter Your First Name : ";
	                    cin >> firstName;
	                    Dentist *d = dentist.getDentist(firstName);
	                    Schedule s;
	                    if (d)
	                    {
	                        s.getdata();
	                        dentist.getDentist(firstName)->updateSchduel(&s);
	                        dentistTableHeaders();
	
	                        dentist.findByFirstName(firstName);
	                        cout <<endl<< "----------------------------------------------------------------------------------------------------------";
	                        cout<<endl;
	                    }
	
	                    Sleep(2000);
	                }
	
	                break;
	
	            case 5: // Sort Clients List By Their First Name
	                if (user == isAdmin)
	                {
	                	cout<<endl;
	                    cout << "************************* BEFORE SORTING **********************";
	                    cout<<endl<<endl;
	                    Sleep(500);
	                    clientInfoTableHeaders();
	                    client.displayList();
	                    Sleep(3000);
	
	                    client.insertionSort();
	
	                    cout<<endl;
	                    cout<<endl<<endl;
	                    cout << "The Client List After Sorting In Ascending Order";
	                    cout<<endl<<endl;
	                    Sleep(500);
	                    clientInfoTableHeaders();
	                    client.displayList();
	                    Sleep(3000);
	                }
	                break;
	                
	            case 6: //Update Clients By Phone Number
	                if (user == isAdmin)
	                {
	                    Sleep(500);
	                    clientInfoTableHeaders();
	
	                    client.displayList();
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
						
						cout<<endl;
	                    cout << "Enter The Client ID : ";
	                    cin >> id;
	                    cout<<endl;
	                    cout << "Enter The New Phone Number (0123456789) : ";
	                    cin >> phoneNumber;
	
	                    client.findNode(id, phoneNumber);
	                    Sleep(500);
	                    clientInfoTableHeaders();
	
	                    client.displayList();
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
	                    Sleep(2000);
	                }
	                break;
	
	            case 7: //delete clients by record
	                if (user == isAdmin)
	                {
	                    Sleep(500);
	                    clientInfoTableHeaders();
	
	                    client.displayList();
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl;
	
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
	                    cout <<endl<< "Enter The Client ID : ";
	                    cin >> id;
	
	                    client.deleteNode(id);
	                    clientInfoTableHeaders();
	
	                    client.displayList();
	                    cout << "----------------------------------------------------------------------------------------------------------";
	                    cout<<endl<<endl;
	                    Sleep(2000);
	                }
	
	                break;
	
	            case 8:
	            	//return to main interface
	            	cout<<endl;
	                cout << "Returning To The Main Interface";
	                cout<<endl;
	                Sleep(1000);
	                break;
	
				//Exit
	            case 9: 
	                system("cls");
	                cout << endl<< "\t\t\t ** Thank You For Using The System :) ** ";
	                cout<<endl<<endl;
	                Sleep(2000);
	                return 0;
	
	                break;
	            }
        } while (choice != 8);

    } while (choice != 9);
}
