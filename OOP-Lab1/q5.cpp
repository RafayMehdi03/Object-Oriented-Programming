#include<iostream>

using namespace std;

struct Date{
    int day;
    string month;
    int year;
};

struct Event{
    string eventName;
    struct Date eventDate;
    string eventVenue;
    string eventOrganizer;
};

int main(){
    int totalEvents, operation;

    cout << "Enter number of events: ";
    cin >> totalEvents;

    struct Event *eventPtr;
    eventPtr = new Event[totalEvents];

    for(int i = 0; i < totalEvents; i++){
        cout << "Enter event name: ";
        cin >> eventPtr[i].eventName;

        cout << "Enter event date (day): ";
        cin >> eventPtr[i].eventDate.day;

        cout << "Enter event date (month): ";
        cin >> eventPtr[i].eventDate.month;

        cout << "Enter event date (year): ";
        cin >> eventPtr[i].eventDate.year;

        cout << "Enter event venue: ";
        cin >> eventPtr[i].eventVenue;

        cout << "Enter event organizer: ";
        cin >> eventPtr[i].eventOrganizer;
    }

    while(true){
        cout << "Enter 0 to show all events" << endl;
        cout << "Enter 1 to search events based on date" << endl;
        cout << "Enter 2 to exit" << endl;
        cin >> operation;

        if(operation == 0){
            cout << "Showing all events:" << endl;
            for(int i = 0; i < totalEvents; i++){
                cout << "Event Name: " << eventPtr[i].eventName << endl;
                cout << "Event Date: " << eventPtr[i].eventDate.day << "/"
                     << eventPtr[i].eventDate.month << "/"
                     << eventPtr[i].eventDate.year << endl;
                cout << "Event Venue: " << eventPtr[i].eventVenue << endl;
                cout << "Event Organizer: " << eventPtr[i].eventOrganizer << endl;
            }
        }
        else if(operation == 1){
            int searchDay, searchYear;
            string searchMonth;
            bool eventFound = false;

            cout << "Enter the day of the event: ";
            cin >> searchDay;

            cout << "Enter the month of the event: ";
            cin >> searchMonth;

            cout << "Enter the year of the event: ";
            cin >> searchYear;

            for(int i = 0; i < totalEvents; i++){
                if(eventPtr[i].eventDate.day == searchDay && 
                   eventPtr[i].eventDate.month == searchMonth && 
                   eventPtr[i].eventDate.year == searchYear){
                    eventFound = true;

                    cout << "Event Name: " << eventPtr[i].eventName << endl;
                    cout << "Event Date: " << eventPtr[i].eventDate.day << "/"
                         << eventPtr[i].eventDate.month << "/"
                         << eventPtr[i].eventDate.year << endl;
                    cout << "Event Venue: " << eventPtr[i].eventVenue << endl;
                    cout << "Event Organizer: " << eventPtr[i].eventOrganizer << endl;
                    break;
                }
            }

            if(!eventFound){
                cout << "Event not found!" << endl;
            }
        }
        else{
            break;
        }
    }

    delete[] eventPtr; // Free dynamically allocated memory
}
