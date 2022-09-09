#ifndef Dentist_H
#define DENTIST_H

#include <iostream>
#include "client.h"
#include "appointment.h"

class Admin : public Person
{
	private:
	    Appointment appointment;
	
	public:
		//constructor
	    Admin() : Person()
	    {
	    	
	    }
	    
	    Admin(Appointment appointment, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber, string adminId) : Person(firstName, lastName, gender, dateOfBirth, phoneNumber, adminId)
	    {
	    	//holds the address of current object or this pointer points to the current object of class
	        this->appointment = appointment;
	    }
	    
	    
	    //mutator
	    ~Admin()
	    {
	    	
	    }
	    
	    //accessor
	    Appointment getAppointment() const 
	    {
	        return this->appointment;
	    }
	    string getAdminId() const
	    {
	        return this->getId();
	    }
	    
	    //mutator
	    void setAppointment(Appointment appointment)
	    {
	        this->appointment = appointment;
	    }
	    void printAppointmentInfo()
	    {
	        this->appointment.printAppointment();
	    }
	    void setAdminId(string adminId)
	    {
	        this->setId(adminId);
	    }
	    
};
#endif
