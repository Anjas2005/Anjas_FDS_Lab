#include <iostream>
using namespace std;

class Appointment
{
public:
    string Patient_Name;
    string Appoint_Time;
    Appointment *next;
};
Appointment *head = NULL;
class Create_slots : public Appointment
{
    string *slot_num_name[9];int iterate_name=0;
    string arr_appoint[9] = {"9:00 to 9:50 AM", "10:00 to 10:50 AM", "11:00 to 11:50 AM",
                             "1:00 to 1:50 PM",
                             "2:00 to 2:50 PM", "5:00 to 5:50 PM",
                             "6:00 to 6:50 PM",
                             "7:00 to 7:50 PM", "8:00 to 8:50 PM"};
    int count = 0;

public:
    void Create_All_slots()
    {
        if (count <= 8)
        {

            if (head == NULL)
            {
                while (true)
                {
                    Appointment *new_appointment = new Appointment;
                    new_appointment->Patient_Name = "";
                    new_appointment->Appoint_Time = arr_appoint[count];
                    count++;
                    new_appointment->next = head;
                    head = new_appointment;
                }
            }
            else
            {
                Appointment *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                Appointment *new_appointment = new Appointment;
                new_appointment->Patient_Name = "";
                new_appointment->Appoint_Time = arr_appoint[count];
                count++;
                new_appointment->next = NULL;
                temp->next = new_appointment;
            }
        }
    }
        void Free_slots()
        
        {       slot_num_name[9]=NULL;
               iterate_name=0;
               int slot_count=1;
            cout << "Select your desired slot number from below" << endl;
            Appointment *temp = head;
            while (temp->next != NULL)
            {
                if(temp->Patient_Name=="")
                {   
                    cout<<"Slot "<<slot_count<<" :"<<temp->Appoint_Time<<endl;
                    slot_count++;
                    slot_num_name[iterate_name]=&(temp->Patient_Name);iterate_name++;
                }
                temp = temp->next;
            }
            if(temp->Patient_Name=="")
                {   
                    cout<<"Slot "<<slot_count<<" "<<temp->Appoint_Time<<endl;
                    slot_num_name[iterate_name]=&(temp->Patient_Name);
                }
        }

    void Book_slots()
    {
        Free_slots();
        int j;
        cin>>j;
        --j;
        cout<<"Enter your Name"<<endl;
        cin>>*slot_num_name[j];
    }

    void Display()
    {
        
    }
    
};
