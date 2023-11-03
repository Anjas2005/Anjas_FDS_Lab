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
        {   int slot_num=1;
            cout << "Select your desired slot number from below" << endl;
            Appointment *temp = head;
            while (temp->next != NULL)
            {
                if(temp->Patient_Name=="")
                {   
                    cout<<"Slot "<<slot_num<<" :"<<temp->Appoint_Time<<endl;
                    slot_num++;
                }
                temp = temp->next;
            }
            if(temp->Patient_Name=="")
                {   
                    cout<<"Slot "<<slot_num<<" "<<temp->Appoint_Time<<endl;
                    slot_num++;
                }
        }

    void Book_slots()
    {
        Free_slots();
        int j;
        cin>>j;
    }
    
};
