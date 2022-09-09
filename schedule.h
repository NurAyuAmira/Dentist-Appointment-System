#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>

using namespace std;

class Schedule
{
	private:
	    string scheduleId;
	    string scheduleDay;
	    string scheduleTimeStart;
	    string scheduleTimeEnd;
	    string status;
	
	public:
	    Schedule *next;
	
	    Schedule()
		{
			
		};
		
	    Schedule(string scheduleId, string scheduleDay, string scheduleTimeStart, string scheduleTimeEnd, string status)
	    {
	        this->scheduleId = scheduleId;
	        this->scheduleDay = scheduleDay;
	        this->scheduleTimeStart = scheduleTimeStart;
	        this->scheduleTimeEnd = scheduleTimeEnd;
	        this->status = status;
	    };
	    
	    ~Schedule()
		{
		
		};
	
	    string getScheduleId() const
	    {
	        return this->scheduleId;
	    }
	    
	    string getScheduleDay() const
	    {
	        return this->scheduleDay;
	    }
	    
	    string getScheduleTimeStart() const
	    {
	        return this->scheduleTimeStart;
	    }
	    
	    string getScheduleTimeEnd() const
	    {
	        return this->scheduleTimeEnd;
	    }
	    
	    string getStatus() const
	    {
	        return this->status;
	    }
	    
	    void setScheduleId(string scheduleId)
	    {
	        this->scheduleId = scheduleId;
	    }
	    
	    void setScheduleDay(string scheduleDay)
	    {
	        this->scheduleDay = scheduleDay;
	    }
	    
	    void setScheduleTimeStart(string scheduleTimeStart)
	    {
	        this->scheduleTimeStart = scheduleTimeStart;
	    }
	    
	    void setScheduleTimeEnd(string scheduleTimeEnd)
	    {
	        this->scheduleTimeEnd = scheduleTimeEnd;
	    }
	    
	    void setStatus(string status)
	    {
	        this->status = status;
	    }
	    
	    void getdata()
	    {
	    	cout<<endl;
	        cout << "Enter Your Free Day : ";
	        cin >> this->scheduleDay;
	        
	        cout <<endl<<" What Time to Start the Appointment -> Open (8:am) : ";
	        cin >> this->scheduleTimeStart;
	        
	        cout <<endl<<" What Time to End the Appointment -> Close (6:pm)  : ";
	        cin >> this->scheduleTimeEnd;
	        this->status = "available";
	    }
	    
	    void update(string scheduleId, string scheduleDay,string scheduleTimeStart,string scheduleTimeEnd, string status)
	    {
	        this->scheduleId = scheduleId;
	        this->scheduleDay = scheduleDay;
	        this->scheduleTimeStart = scheduleTimeStart;
	        this->scheduleTimeEnd = scheduleTimeEnd;
	        this->status = status;
	    }
	
	    void printScheduleDetail()
	    {
	        cout << this->scheduleId << "\t\t" << this->scheduleDay << "\t\t" << this->scheduleTimeStart << "\t\t" << this->scheduleTimeEnd << "        " << this->status << endl;
	    }
};

class List
{
	private:
	    Schedule *head;
	    Schedule *node;
	
	public:
	    List()
	    {
	        head = NULL;
	        node = NULL;
	    }
	    
	    ~List()
		{
			
		};
		
	    bool isEmpty() 
		{
			 return head == NULL;
		}
		
	    
	    void InsertNode(string scheduleId, string scheduleDay, string scheduleTimeStart, string scheduleTimeEnd, string status)
	    {
	        int currentIndex = 0;
	        Schedule *currNode = head;
	        Schedule *prevNode = NULL;
	        
	        while (currNode && scheduleId > currNode->getScheduleId())
	        {
	            prevNode = currNode;
	            currNode = currNode->next;
	        }
	        
	        //allocate memory for New Schedule
	        Schedule *newNode = new Schedule;
	        newNode->update(scheduleId, scheduleDay, scheduleTimeStart, scheduleTimeEnd, status);
	        
	        if (prevNode == NULL)
	        {
	        	//set next of newnode to head
	            newNode->next = head;
	            
	            //head is equal to new node
	            head = newNode;
	            
	        }
	        else
	        {
	        	//set next of newnode to next of prev node
	            newNode->next = prevNode->next;
	            
	            //set next of prev node to newnode
	            prevNode->next = newNode;
	        }
	    }
	
	    Schedule *findNode(string id)
	    {
	        Schedule *currNode = head;
	        
	        while (currNode)
	        {
	            if (currNode->getScheduleId() != id)
	                currNode = currNode->next;
	            else
	                return currNode;
	        }
	
	        return 0;
	    }
	
	    Schedule *getId()
	    {
	
	        Schedule *temp;
	
	        if (node)
	        {
	            temp = node;
	            node = node->next;
	
	            return temp;
	        }
	        else
	            node = head;
	        return NULL;
	    }
	
	    void displayList()
	    {
	
	        Schedule *currNode = head;
	        if (currNode == NULL)
	        {
	            cout << "Empty ";
	            cout<<endl;
	        }
	
	        while (currNode)
	        {
	
	            currNode->printScheduleDetail();
	            currNode = currNode->next;
	        }
	    }
};

#endif
