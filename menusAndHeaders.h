#ifndef MENUSANDHEADERS_H
#define MENUSANDHEADERS_H

#include <iostream>
using namespace std;

void mainMenu()
{
    cout<<"\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	cout<<"\t\t\t\t * -- Dental Care MMU Appointment Systems -- * "<<endl<<endl;
	cout<<"\t\t -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	cout <<"\t\t\t\t (1) Client \n\t\t\t\t (2) Dentist \n\t\t\t\t (3) Administrator \n\t\t\t\t (4) Exit"<<endl<<endl;
	cout<<"\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	
	cout<<"\t\t Which one are you ? ";
}
void clientMenu()
{
    cout<<endl<<endl;
	cout<<"\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	cout<<"\t\t\t\t 1. Add An Appointment "<<endl;
	cout<<"\t\t\t\t 2. Display Dentist Schedule "<<endl;
	cout<<"\t\t\t\t 3. Search Dentist Name "<<endl;
	cout<<"\t\t\t\t 4. Search Available Dentist "<<endl;
	cout<<"\t\t\t\t 8. Return To Main Menu "<<endl;
	cout<<"\t\t\t\t 9. Exit This System "<<endl<<endl;
	cout<<"\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	
	cout<<"As a client, what would you like to do? : "<<endl;
}

void dentistMenu()
{
    cout<<endl<<endl;
	cout<<"\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	cout<<"\t\t\t\t 1. Display All Clients Details "<<endl;
	cout<<"\t\t\t\t 2. Search Clients By Name "<<endl;
	cout<<"\t\t\t\t 3. Search Clients By ID "<<endl;
	cout<<"\t\t\t\t 4. Update Schedule "<<endl;
	cout<<"\t\t\t\t 8. Return to Main Menu "<<endl;
	cout<<"\t\t\t\t 9. Exit This System "<<endl<<endl;
	cout<<"\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	
	cout<<"As a dentist, what would you like to do? : "<<endl;
}

void adminMenu()
{
 cout<<endl<<endl;
	cout<<"\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	cout<<"\t\t\t\t 1. Display All Clients List "<<endl;
	cout<<"\t\t\t\t 2. Display All Dentist List "<<endl;
	cout<<"\t\t\t\t 3. Search Dentist By Name "<<endl;
	cout<<"\t\t\t\t 4. Search Available Dentist "<<endl;
	cout<<"\t\t\t\t 5. Sort Clients List By Their First Name "<<endl;
	cout<<"\t\t\t\t 6. Edit Clients By Phone Number "<<endl;
	cout<<"\t\t\t\t 7. Delete Clients By Record "<<endl;
	cout<<"\t\t\t\t 8. Return to Main Menu "<<endl;
	cout<<"\t\t\t\t 9. Exit This System "<<endl<<endl;
	cout<<"\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- "<<endl<<endl;
	
	cout<<"As a admin, what would you like to do? : "<<endl;
}



void clientTableHeaders()
{
    cout<<endl;
	cout<<"This is Client details "<<endl<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
	
	cout<<endl;
	cout<<"Client ID\t\t\tClient Name\t\t\tGender\t\t\tBirth Of Date \t Phone Number "<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
}

void dentistInfoTableHeaders()
{
    cout<< "Dentist ID "
		<<"\t\t"
		<< "Dentist Name "
        << "\t\t"
		<< "Gender "
		<< "\t\t"
		<< "Birth of Date "
		<< "\t"
		<< "Phone Number "
		<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
}

void dentistTableHeaders()
{
    cout<<endl;
	cout<<"There are available date and dentist "<<endl<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
	
	cout<<endl;
	cout<<"Dentist Name\t\t Schedule ID\t\t Day\t\t Start Time \t End Time \t Status "<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
}

void dentistTableHeaders2()
{
    cout<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
	
	cout<<endl;
	cout<<"Dentist Name\t\t Schedule ID\t\t Day\t\t Start Time \t End Time \t Status "<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
}

void dentistTable2Headers()
{
    cout<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
	
	cout<<endl;
	cout<<"Dentist Name\t\t Schedule ID\t\t Day\t\t Start Time \t End Time \t Status "<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
}

void clientBookingTableHeaders()
{
    cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
	cout<< "Client ID \t";
	cout<< "Client Name \t";
	cout<< "Dentist Name \t";
	cout<< "Appointment Day \t";
	cout<< "Appointment Time ";
	cout<< endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
}
void clientInfoTableHeaders()
{
   
    cout<<endl<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
	cout<< "Client ID "
		<< "\t"
		<< "Client Name "
		<< "\t\t"
		<< "Gender "
		<< "\t\t"
		<< "Birth of Date "
		<< "\t\t"
		<< "Phone Number "
		<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
}
#endif
