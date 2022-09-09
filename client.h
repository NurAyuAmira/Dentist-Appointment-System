#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "person.h"
using namespace std;

class Client : public Person
{

		public:
	
			    Client *next;
			    
			    Client() : Person()
			    {
			    	
			    }
			    Client(string clientId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber) : Person(firstName, lastName, gender, dateOfBirth, phoneNumber, clientId)
			    {
			    	
			    }
			    ~Client()
			    {
			    	
			    }
			
			    void setClientInfo()
			    {
			    	cout<<endl;
			        cout << "Enter Your First Name : ";
			        cin >> this->firstName;
			        cout << "Enter Your Last Name : ";
			        cin >> lastName;
			        cout << "Enter Your Gender In Small Alphabet (male , female) : ";
			        cin >> this->gender;
			        cout << "Enter Your Date Of Birth  (00-00-0000) : ";
			        cin >> this->dateOfBirth;
			        cout << "Enter Your Phone Number   (0123456789): ";
			        cin >> this->phoneNumber;
			
												//substring
			        this->setId("C" + firstName.substr(0, 1) + lastName.substr(0, 1) + gender.substr(0, 1) + phoneNumber.substr(0, 2));
			        this->update(id, firstName, lastName, gender, dateOfBirth, phoneNumber);
			    }
			    
			    void update(string ClientId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber)
			    {
			        this->id = "C" + firstName.substr(0, 1) + lastName.substr(0, 1) + gender.substr(0, 1) + phoneNumber.substr(0, 2);
			        this->firstName = firstName;
			        this->lastName = lastName;
			        this->gender = gender;
			        this->dateOfBirth = dateOfBirth;
			        this->phoneNumber = phoneNumber;
			    }
			    
			    void printClientList()
			    {
			    	 cout << "----------------------------------------------------------------------------------------------------------"<<endl;
					 cout<<"Client ID\t Client Name\t\tGender \t\tBirth Of Date \t\tPhone Number "<<endl;
			        cout << this->id << "\t\t" << this->firstName + " " + this->lastName << "\t\t" << this->gender << "\t\t" << this->dateOfBirth << "\t\t" << this->phoneNumber<<endl;
			         cout << "----------------------------------------------------------------------------------------------------------"<<endl<<endl;
			    }
			};
			
			
			class ClientList
			{
				private:
				    Client *head;
				
				public:
					
				    ClientList() 
					{ 
						head = NULL; 
					}
					
					
				    ~ClientList()
					{
						
					};
					
					
				    bool isEmpty() 
					{ 
						return head == NULL; 
					}
					
					
				    void InsertNode(string clientId, string firstName, string lastName, string gender, string dateOfBirth, string phoneNumber)
				    {
				        int currentIndex = 0;
				        Client *currNode = head;
				        Client *prevNode = NULL;
				        
					        while (currNode)
					        {
					            prevNode = currNode;
					            currNode = currNode->next;
					        }
					        Client *newNode = new Client;
					        newNode->update(clientId, firstName, lastName, gender, dateOfBirth, phoneNumber);
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
			   		
			   
			   	 	void *findNode(string id, string phone)
				    {
				        Client *currNode = head;
					        while (currNode && currNode->getId() != id)
					        {
					            currNode = currNode->next;
					        }
						        if (currNode)
						        {
						            currNode->setPhoneNumber(phone);
						            cout <<endl<< " ** Phone Number Is Updated Successfully ** "<<endl;
						        }
						        else
						        {
						        	cout << " ** Record Is Not Found ** ";
								}
			   		}
			   		
			   		
			   		// delete contacts from menu
			   		 int deleteNode(string id) 
				    {
				        Client *prevNode = NULL;
				        Client *currNode = head;
				        int currIndex = 1;
				
					        while (currNode && currNode->getId() != id)
					        {
					            prevNode = currNode;
					            currNode = currNode->next;
					            currIndex++;
					        }
						        if (currNode)
						        {
						            if (prevNode)
						            {
						                prevNode->next = currNode->next;
						                delete currNode;
						                cout << " ** Record Is Deleted Successfully ** " << endl;
						            }
						            else
						            {
						                head = currNode->next;
						                delete currNode;
						                cout << " ** Record Is Deleted Successfully ** " << endl;
						            }
						
						            return currIndex;
						        }
						        
				      	 cout << " ** Record Is Not Found ** " << endl;
				        return 0;
				    }
				    
				    
				    void searchClientInfoByName(string firstName)
				    {
				        Client *currNode = head;
					        while (currNode && currNode->getFirstName() != firstName)
					        {
					            currNode = currNode->next;
					        }
						        if (currNode)
						        {
						      	    currNode->printClientList();	
								}
						        else
						        {
						            cout << " ** Record Is Not Found ** " << endl;
						        }
				    }
				    
				    
				    void searchClientInfoById(string id)
				    {
				        Client *currNode = head;
					        while (currNode && currNode->getId() != id)
					        {
					            currNode = currNode->next;
					        }
					        if (currNode)
					        {
					            currNode->printClientList();	
							}
					        else
					        { 
					            cout << " ** Record Is Not Found ** " << endl;
					        }
				    }
				    
				    
				    void insertionSort()
				    {
				        // Initialize sorted linked list
				        Client *sorted = NULL;
				
				        // Traverse the given linked list and insert every node to sorted
				        Client *current = head;
				        
				        while (current != NULL)
				        {
				            // Store next for next iteration
				            Client *next = current->next;
				
				            // insert current in sorted linked list
				            sortedInsert(&sorted, current);
				
				            // Update current
				            current = next;
				        }
				
				        // Update head_ref to point to sorted linked list
				        head = sorted;
				    }
				    
				    void sortedInsert(Client **head_ref, Client *new_node)
				    {
				        Client *current;
				        
				        //Special case for the head end 
				        if (*head_ref == NULL || (*head_ref)->getFirstName() >= new_node->getFirstName())
				        {
				            new_node->next = *head_ref;
				            *head_ref = new_node;
				        }
				        else
				        {
				           // Locate the node before the point of insertion 
				            current = *head_ref;
				            
				            while (current->next != NULL && current->next->getFirstName() < new_node->getFirstName())
				            {
				                current = current->next;
				            }
				            
				            new_node->next = current->next;
				            current->next = new_node;
				        }
				    }
				
				    void displayList()
				    {
				
				        Client *currNode = head;
				        
				        if (currNode == NULL)
				        {
				            cout << "Empty ";
				            cout<<endl;
				        }
				
				        while (currNode)
				        {
				
				            currNode->printClientList();
				            currNode = currNode->next;
				        }
			    }
};

#endif
