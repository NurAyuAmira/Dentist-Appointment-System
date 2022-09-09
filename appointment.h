#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include "dentist.h"
#include "client.h"
using namespace std;

class Appointment
{
	private:
	    string appointmentid;
	    string dateOfAppointment;
	    string timeOfAppointment;
	
	    Client *client;
	    Dentist  *dentist;
	    Schedule *schedule;
	
	public:
	    Appointment *next;
	    
	    Appointment()
	    {
	    	
	    }
	    
	    
	    Appointment(string appointmentid, Client *client, Dentist *dentist, Schedule *schedule, string dateOfAppointment, string timeOfAppointment)
	    {
	        this->appointmentid = appointmentid;
	        this->dateOfAppointment = dateOfAppointment;
	        this->timeOfAppointment = timeOfAppointment;
	        this->client = client;
	        this->dentist = dentist;
	        this->schedule = schedule;
	    }
	
	    ~Appointment()
	    {
	    	
	    }
	    
	    
	    string getAppointmentid() const
	    {
	        return this->appointmentid;
	    }
	    
	    string getDateOfAppointment() const
	    {
	        return this->dateOfAppointment;
	    }
	    
	    string getTimeOfAppointment() const
	    {
	        return this->timeOfAppointment;
	    }
	
	    void setDateOfAppointment(string dateOfAppointment)
	    {
	        this->dateOfAppointment = dateOfAppointment;
	    }
	    
	    void setTimeOfAppointment(string timeOfAppointment)
	    {
	        this->timeOfAppointment = timeOfAppointment;
	    }
	
	    void setAppointmentid(string appointmentid)
	    {
	        this->appointmentid = appointmentid;
	    }
	    
	    void update(Client *client, Dentist *dentist, Schedule *schedule)
	    {
	        this->client = client;
	        this->dentist = dentist;
	        this->schedule = schedule;
	        this->dateOfAppointment = this->schedule->getScheduleDay();
	        this->timeOfAppointment = this->schedule->getScheduleTimeStart() + " to " + this->schedule->getScheduleTimeEnd();
	    }
	    
	    void printAppointment()
	    {
	        if (client && schedule && dentist != NULL)
	            cout << this->client->getId() << "\t\t" << this->client->getFirstName() << "\t\t" << this->dentist->getFirstName() << "\t\t" << dateOfAppointment << "\t\t\t" << timeOfAppointment << endl;
	    }
	    
	};
	
class AppointmentList
{
	private:
	    Appointment *head;
	
	public:
	    AppointmentList() 
		{
		 	head = NULL;
	    }
	    
	    ~AppointmentList()
		{
		
		};
	    
	    bool isEmpty()
		{ 
		 	return head == NULL;
		}
	    
	    void InsertNode(Client *client, Dentist *dentist, Schedule *schedule)
	    {
	        Appointment *currNode=head;
	        Appointment *prevNode = NULL;
	        
	        while (currNode && schedule->getScheduleId() > currNode->getAppointmentid())
	        {
	            prevNode = currNode;
	            currNode = currNode->next;
	        }
	        
	        Appointment *newNode = new Appointment;
	        newNode->update(client, dentist, schedule);
	        
	        if (prevNode == NULL)
	        {
	            newNode->next = head;
	            head = newNode;
	        }
	        else
	        {
	            newNode->next = prevNode->next;
	            prevNode->next = newNode;
	        }
	    }
	
	    void displayAppointments()
	    {
	
	        Appointment *currNode = head;
	        
	        if (currNode == NULL)
	        {
	            cout << "Empty ";
	            cout<<endl;
	        }
	
	        while (currNode)
	        {
	
	            currNode->printAppointment();
	            currNode = currNode->next;
	        }
	    }
};

#endif
