#ifndef PERSON_H //checks whether HEADERFILE_H is not declared.
#define PERSON_H //will declare HEADERFILE_H once #ifndef generates true.

#include <iostream>
using namespace std;

class Person
{

	public:
	    string firstName;
	    string lastName;
	    string gender;
	    string dateOfBirth;
	    string phoneNumber;
	    string id;
	    
	    //constructor
	    Person()
	    {
	        this->firstName = " ";
	        this->lastName = " ";
	        this->gender = " ";
	        this->dateOfBirth = " ";
	        this->phoneNumber = " ";
	    }
	    
	    Person(string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber, string id)
	    {
	        this->firstName = firstName;
	        this->lastName = lastName;
	        this->gender = gender;
	        this->dateOfBirth = dateOfBirth;
	        this->phoneNumber = phoneNumber;
	        this->id = id;
	    }
	    
	    //mutator
	    ~Person()
	    {
	    	
	    }
	    
	    //accessor
	    string getFirstName() const
	    {
	        return this->firstName;
	    }
	    
	    string getLastName() const
	    {
	        return this->lastName;
	    }
	    
	    string getGender() const
	    {
	        return this->gender;
	    }
	    
	    string getDateOfBirth() const
	    {
	        return this->dateOfBirth;
	    }
	
	    string getPhoneNumber() const
	    {
	        return this->phoneNumber;
	    }
	    
	    string getId() const
	    {
	        return this->id;
	    }
	    
	    
	    //mutator
	    void setFirstName(string firstName)
	    {
	        this->firstName = firstName;
	    }
	    
	    void setLastName(string lastName)
	    {
	        this->lastName = lastName;
	    }
	    
	    void setGender(string gender)
	    {
	        this->gender = gender;
	    }
	    
	    void setDateOfBirth(string dateOfBirth)
	    {
	        this->dateOfBirth = dateOfBirth;
	    }
	
	    void setPhoneNumber(string phoneNumber)
	    {
	        this->phoneNumber = phoneNumber;
	    }
	    
	    void setId(string id)
	    {
	        this->id = id;
	    }
	    
};

#endif //is to know the scope of #ifndef i.e end of #ifndef
