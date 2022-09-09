#ifndef DENTIST_H
#define DENTIST_H
#include "person.h"
#include "schedule.h"
#include <iostream>

using namespace std;

class Dentist : public Person
{
	public:
	    Dentist *next;
	    Schedule *schedule[10];
	    int i = 0;
	
	    Dentist() : Person()
	    {
	    	int k; 
	    	
	        for (k = 0; k < 10; k++)
	        {
	            schedule[k] = NULL;
	        }
	    }
	    
	    
	    Dentist(string dentistId, Schedule schedule, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber) : Person(firstName, lastName, gender, dateOfBirth, phoneNumber, dentistId)
	    {
	    	
	    }
	    
	    ~Dentist()
	    {
	    	
	    }
	
	    void update(string dentistId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber)
	    {
	        this->id = dentistId;
	        this->firstName = firstName;
	        this->lastName = lastName;
	        this->gender = gender;
	        this->dateOfBirth = dateOfBirth;
	        this->phoneNumber = phoneNumber;
	    }
	    
	    
	    void printDentistInfo()
	    {
	        cout << this->id << "\t\t" << this->firstName + " " + this->lastName << "\t\t" << this->gender << "\t\t" << this->dateOfBirth << "\t" << this->phoneNumber <<endl;
	    }
	    
	    void printDentistSchduel()
	    {
			//sizeof is returns the amount of memory (in bytes) that the [schedule] occupies. It has nothing to do with the value of the variable.
	        int size = sizeof(schedule) / sizeof(schedule[0]);
	        for (int k = 0; k < size; k++)
	        {
	            if (schedule[k] != NULL)
	            {
	                cout << " " << firstName << " " << lastName << "\t\t";
	
	                schedule[k]->printScheduleDetail();
	                cout << endl;
	            }
	        }
	    }
	    
	    
	    void updateSchduel(Schedule *schedule)
	    {
	        int pos1, pos2;
	        pos1 = schedule->getScheduleTimeStart().find(":");
	        pos2 = schedule->getScheduleTimeEnd().find(":");
	        schedule->setScheduleId(this->id + "_" + schedule->getScheduleDay().substr(0, 1) +  schedule->getScheduleTimeStart().substr(0, pos1) +  schedule->getScheduleTimeEnd().substr(0, pos2));
	        this->schedule[i] = schedule;
	
	        i++;
	    }
};
class DentistList
{
	private:
	    Dentist *head;
	
	public:
	    DentistList() 
		{
		 	head = NULL;
		}
		
	    ~DentistList()
		{
			
		};
	    
	    bool isEmpty()
		{
			 return head == NULL; 
		}
		
		
	    void InsertNode(List schduel, int i, string dentistId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber)
	    {
	        int currentIndex = 0;
	        Dentist *currNode = head;
	        Dentist *prevNode = NULL;
	        
		        while (currNode && dentistId > currNode->getId())
		        {
		            prevNode = currNode;
		            currNode = currNode->next;
		        }
		        
		        
	        Dentist *newNode = new Dentist;
	        newNode->update(dentistId, firstName, lastName, gender, dateOfBirth, phoneNumber);
	        string scId;
	        int index;
	        Schedule *temp;
	
	        while (i != 0)
	        {
	            temp = schduel.getId();
	            if (temp != NULL)
	            {
	                scId = temp->getScheduleId();
	                index = scId.find("_");
	                scId = scId.substr(0, index);
	
	                if (newNode)
	                {
	                    if (newNode->getId() == scId)
	                    {
	                        newNode->updateSchduel(temp);
	                    }
	                }
	            }
	            i--;
	        }
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
	    
	    
	    Dentist *getDentist(string firstName)
	    {
	        Dentist *currNode = head;
	        while (currNode && currNode->getFirstName() != firstName)
	        {
	            currNode = currNode->next;
	        }
	        if (currNode)
	            return currNode;
	        else
	        {
	            return NULL;
	        }
	    }
	
	    Dentist *findNode(string id, int &index)
	    {
	        Dentist *currNode = head;
	        int size = 0;
	        while (currNode && size < 10)
	        {
	            if (currNode->schedule[size] != NULL)
	            {
	                if (currNode->schedule[size]->getScheduleId() == id)
	                {
	                    if (currNode->schedule[size]->getStatus() == "available")
	                    {
	                        index = size;
	                        currNode->schedule[size]->setStatus("booked");
	                        return currNode;
	                        
	                    }
	                }
	                size++;
	            }
	            else
	            {
	                size = 0;
	                currNode = currNode->next;
	            }
	        }
	        return NULL;
	    }
	    
	    
	    void findByFirstName(string firstName)
	    {
	        Dentist *currNode = head;
	        while (currNode && currNode->getFirstName() != firstName)
	        {
	            currNode = currNode->next;
	        }
	        if (currNode)
	            currNode->printDentistSchduel();
	        else
	        {
	            cout << " ** Record Is Not Found ** " << endl;
	        }
	    }
	    
	    
	    void findAvialableDentist()
	    {
	        Dentist *currNode = head;
	        int size = 0;
	        while (currNode && size < 10)
	        {
	            if (currNode->schedule[size] != NULL)
	            {
	
	                if (currNode->schedule[size]->getStatus() == "available")
	                {
	                    size++;
	
	                    currNode->printDentistSchduel();
	                }
	                currNode = currNode->next;
	            }
	            else
	              {
	              	size = 0;
				  }  
	        }
	    }
	    
	    
	    void searchDentistInfoByName(string firstName)
	    {
	        Dentist *currNode = head;
	        while (currNode && currNode->getFirstName() != firstName)
	        {
	            currNode = currNode->next;
	        }
	        if (currNode)
	            currNode->printDentistInfo();
	        else
	        {
	            cout << " ** Record Is Not Found ** " << endl;
	        }
	    }
	    
	    
	    void displayList()
	    {
	
	        Dentist *currNode = head;
	        if (currNode == NULL)
	        {
	            cout << "Empty ";
	            cout<<endl;
	        }
	
	        while (currNode)
	        {
	
	            currNode->printDentistInfo();
	            currNode = currNode->next;
	        }
	    }
	    
	    
	    void displaySchedul()
	    {
	
	        Dentist *currNode = head;
	        if (currNode == NULL)
	        {
	            cout << "Empty ";
	            cout<<endl;
	        }
	
	        while (currNode)
	        {
	
	            currNode->printDentistSchduel();
	            currNode = currNode->next;
	        }
    	}
    	
};
#endif
