//Reference for Flights.cpp
//http://www.cplusplus.com/reference/ctime/mktime/

#include <iostream>
#include <fstream>

using namespace std;

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "crew.h"
#include "crews.h"
#include "plane.h"
#include "planes.h"
#include "flight.h"
#include "flights.h"

extern crews crewlist;
extern planes planelist;

//checking the crew time
bool flights::ValidateCrew(int x,long long int tStart,long long int tEnd){
	for ( int i =0; i < flightCount;i++){ 
		if((flightsList[i].GetPilotID() == x) || (flightsList[i].GetCopilotID() == x) || (flightsList[i].GetCrewID() == x)){
			if ((flightsList[i].GetStartDate() > tStart) || (flightsList[i].GetEndDate() < tEnd)){ return false;}
		}
	}
	return true;
}

//checking the plane time
bool flights::ValidatePlane(string x,long long int tStart,long long int tEnd){
	for ( int i = 0; i < flightCount ; i++){
		if ((flightsList[i].GetPlaneID() == x)){
			if (((flightsList[i].GetStartDate() > tStart)) || (flightsList[i].GetEndDate() < tEnd)){return false;}
		}

	}
	return true;
}

void flights::AddFlight(){
	flight add;
	bool options; //for all the do while loops
	string addPlaneID;
	//string addflightID;
	//variable to store all the necessary data
	int addNumPilots,addNumCrews,addPilotID1,addCopilotID1,addCrew1,addCrew2,addCrew3;
	int addPilotID2,addCopilotID2; //flight above 8 hrs
	int addYear1,addMonth1,addDay1,addHour1,addMinute1;
	int addYear2,addMonth2,addDay2,addHour2,addMinute2;
	struct tm addStartTime = {0};
	struct tm addEndTime = {0}; 

	cout << "Please enter the year(start) of the flight: ";
	cin >> addYear1;
	cout << "Please enter the month(start) of the flight(1-12): ";
	cin >> addMonth1;
	cout << "Please enter the day(1-31)(start) of the flight: ";
	cin >> addDay1;
	cout << "Please enter the hour(1-24)(start) of the flight:";
	cin >> addHour1;
	cout << "Please enter the minutes(start) as well: ";
	cin >> addMinute1;
	
	//seting time and date
	addStartTime.tm_year = addYear1 - 1900;
	addStartTime.tm_mon = addMonth1 - 1;
	addStartTime.tm_mday = addDay1;
	addStartTime.tm_hour = addHour1;
	addStartTime.tm_min = addMinute1;

	time_t TodaysDate = time(0);
	tm *gmtm = gmtime(&TodaysDate);
	if (mktime(gmtm) < TodaysDate){
		cout << "SORRY! THE DETAILS YOU ENTERED IS BEFORE THE CURRENT DATE AND TIME" << endl;
		return;
	}

	cout << "Please enter the year when flight ends: ";
        cin >> addYear2;
        cout << "Please enter the month(1-12) when flight ends: ";
        cin >> addMonth2;
        cout << "Please enter the day(1-31) when fligtht ends: ";
        cin >> addDay2;
        cout << "Please enter the hour(1-24) when flight ends: ";
        cin >> addHour2;
        cout << "Please enter the minutes when flight ends: ";
        cin >> addMinute2;

	//setting time and date
	addEndTime.tm_year = addYear2 - 1900;
	addEndTime.tm_mon = addMonth2 - 1;
	addEndTime.tm_mday = addDay2;
	addEndTime.tm_hour = addHour2;
	addEndTime.tm_min = addMinute2;

	if (mktime(&addEndTime) < mktime(&addStartTime)) 
	{
		cout<< "TIME CONFLICT.THE END DATE AND TIME OF FLIGHT IS BEFORE THAN START DATE AND TIME.";
		return;
	}
	//check for flight and cabin crew
	do{
		cout << "Enter the pilot ID: ";
		cin >> addPilotID1;
		cout << "Enter the Co-pilot ID: ";
		cin >> addCopilotID1;
		cout << "Enter the first Cabin-Crew ID: ";
		cin >> addCrew1;
		cout << "Enter the second Cabin-Crew ID: ";
		cin >> addCrew2;
		cout << "Enter the third Cabin-Crew ID: ";
		cin >> addCrew3;
		add.SetPilotID(addPilotID1);
		add.SetCopilotID(addCopilotID1);
		add.SetCrewID(addCrew1);
		add.SetCrewID(addCrew2);
		add.SetCrewID(addCrew3);
		options = true;
		
		//checking all the necesssary checks so time type and status does not overlap
		if ((crewlist.findType(addPilotID1) != 3) || (crewlist.findType(addCopilotID1) != 2) || (crewlist.findType(addCrew1) != 1) || (crewlist.findType(addCrew2) != 1) || (crewlist.findType(addCrew3) != 1)){
			cout << "ASSIGNED TYPE MISMATCH!" << endl;
			options = false;

		}

		if((crewlist.findStatus(addPilotID1) != 1) || (crewlist.findStatus(addCopilotID1) != 1) || (crewlist.findStatus(addCrew1) != 1) || (crewlist.findStatus(addCrew2) != 1) || (crewlist.findStatus(addCrew3) != 1)){
			cout << "ALL CREWS ARE NOT FREE!" << endl;
			options = false;
		}

		if((ValidateCrew(addPilotID1,(mktime(&addStartTime)),(mktime(&addEndTime))) == false) || (ValidateCrew(addCopilotID1,(mktime(&addStartTime)),(mktime(&addEndTime))) == false) || (ValidateCrew(addCrew1,(mktime(&addStartTime)),(mktime(&addEndTime))) == false) || (ValidateCrew(addCrew2,(mktime(&addStartTime)),(mktime(&addEndTime))) == false) || (ValidateCrew(addCrew3,(mktime(&addStartTime)),(mktime(&addEndTime))) == false)){
			cout << "SORRY ONE OF THE ENTERED OPTONS CREATE TIME CONFLICTS!" << endl;
			options = false;
		}
	}while (options == false);


	do {
		cout << "Please enter the PLANE ID: ";
		cin >> addPlaneID;
		add.SetPlaneID(addPlaneID);
		options = 1;

		if (planelist.findStatus(addPlaneID) != 1){
			cout << "PLANE IS BUSY OR CANCELLED!" << endl;
			options = 0;
		}

		if (ValidatePlane(addPlaneID,(mktime(&addStartTime)),(mktime(&addEndTime))) == false){
			cout << "SORRY TIME CONFLICT IN ASSIGNED PLANE!" << endl;
			options = 0;
		}

	} while ( options != 1);

	string addSAirport,addEAirport;
	int addStatus;
	int addNumPassenger;
	int addRange;
	cout << "Please enter the 3 leter code for starting airport: ";
	cin >> addSAirport;
	add.SetsAirport(addSAirport);
	cout << "Please enter the 3 letter code for ending airport: ";
	cin >> addEAirport;
	add.SeteAirport(addEAirport);
	cout << "Please enter the status of the flight" << endl;
	cout << "1. Active" << endl;
	cout << "2. Complete" << endl;
	cout << "3. Cancelled" << endl;
	cin >> addStatus;
	add.SetStatus(addStatus);
	cout << "Please enter the range of the flight: ";
	cin >> addRange;
	add.SetRange(addRange);
	do{
		cout << "Please enter the number odf Passengers in the Plane: ";
		cin >> addNumPassenger;
		if (planelist.findSeats(addPlaneID) < addNumPassenger){
			cout << "PASSENGER EXCEEDS NUMBER OF SEATS!" << endl;
		}
	} while ( planelist.findSeats(addPlaneID) < addNumPassenger);
	add.SetNumPassengers(addNumPassenger);
	flightsList.push_back(add);
	cout << "FLIGHT ADDED" << endl;
	flightCount++;
}


void flights::EditFlight(){
	flight edit;
	string editPlaneID,editStPoint,editEnPoint;
	int options,editNumPassenger,editRange,editStatus;
	cout << "Please enter the Plane ID: ";
	cin >> editPlaneID; cin.ignore();

	for (int i = 0; i<flightCount; i++){
		if (flightsList[i].GetPlaneID() == editPlaneID){

			cout << "What do you want to edit?" << endl;
			cout << "1. Starting Point" << endl;
			cout << "2. Ending Point" << endl;
			cout << "3. Number of Passenger" << endl;
			cout << "4. Range" << endl;
			cout << "5. Status" << endl;
			cout << "6. Quit" << endl;

			cin >> options;

			switch(options){
				case 1:
					cout << "Please enter the new Starting Airport Code: ";
					cin >> editStPoint;
					flightsList[i].SetsAirport(editStPoint);
					break;
				case 2:
					cout << "Please enter the new Ending Airport Code: ";
					cin >> editEnPoint;
					flightsList[i].SeteAirport(editEnPoint);
					break;
				case 3:
					cout << "Please enter the new number of passenger: ";
					cin >> editNumPassenger;
					flightsList[i].SetNumPassengers(editNumPassenger);
					break;
				case 4:
					cout << "Please enter the new range: ";
					cin >> editRange;
					flightsList[i].SetRange(editRange);
					break;
				case 5:
					cout << "Please enter the new Status of the Flight: ";
					cout << "1. Active" << endl;
					cout << "2. Complete" << endl;
					cout << "3. Cancelled" << endl;
					cin >> editStatus;
					flightsList[i].SetStatus(editStatus);
					break;
				case 6:
					return;
					break;
				default:
					cout << "INVALID OPTION!" << endl;
					return;
					break;

			}
			return;

		}

		cout << "PlANE NOT FOUND!" << endl;
		return;
	}
}

void flights::DeleteFlight(){
	string deletePlaneID;
	cout << "Enter the Plane ID of the flight to delete: ";
	cin >> deletePlaneID;
	for (int i = 0; i < flightCount; i++){
		if (flightsList[i].GetPlaneID() == deletePlaneID){
			flightsList.erase(flightsList.begin()+i);
			flightCount--;
			return;
		}

	}
	cout << "INVALID PLANE ID.FLIGHT NOT FOUND!" << endl;
}

void flights::SearchFlight(){
	string searchPlaneID,printStatus;
	cout << "Please enter the Plane ID of the flight: ";
	cin >> searchPlaneID;
	for (int i = 0; i < flightCount; i++){
		if (flightsList[i].GetPlaneID() == searchPlaneID){
			cout << "*************FLIGHT FOUND**************" << endl;
			cout << endl;
			cout << "Plane ID: " << searchPlaneID << endl;
			//since time needs to be changed to string
			struct tm* mytm1;
			struct tm* mytm2;
			time_t tm1, tm2;

			tm1 = flightsList[i].GetStartDate();
			mytm1 = gmtime(&tm1);
			cout << "Start time: " << asctime(mytm1) << endl;

			tm2 = flightsList[i].GetEndDate();
			mytm2 = gmtime(&tm2);

			cout << "End Time: " << asctime(mytm2) << endl;

			cout << "Starting Airport Code: " << flightsList[i].GetsAirport() << endl;
			cout << "Ending Airport Code: " << flightsList[i].GeteAirport() << endl;
			cout << "Distance: " << flightsList[i].GetRange() << endl;
			cout << "Number of Passengers: " << flightsList[i].GetNumPassengers() << endl;
			if (flightsList[i].GetStatus() == 1) {printStatus = "Active";}
			if (flightsList[i].GetStatus() == 2) {printStatus = "Complete";}
			if (flightsList[i].GetStatus() == 3) {printStatus = "Cancelled";}
			cout << "Status: " << printStatus << endl;

			cout << endl;
			return;
		}
	}
	cout << "INAVLID PLANE ID!" << endl;
	return;
}

void flights::PrintFlight(){
	string printStatus;
	for (int i = 0; i < flightCount; i++){
		cout << "***********FLIGHTS LIST**********" << endl;
		cout << endl;
		cout << "Plane ID: " << flightsList[i].GetPlaneID() << endl;
		time_t time1 = flightsList[i].GetStartDate();
		time_t time2 = flightsList[i].GetEndDate();
		cout << "Start Time: " << ctime(&time1) << endl;
		cout << "End Time: " << ctime(&time2) << endl;
		cout << "Starting Airport Code: " << flightsList[i].GetsAirport() << endl;
		cout << "Ending Airport Code: " << flightsList[i].GeteAirport() << endl;
		cout << "Distance: " << flightsList[i].GetRange() << endl;
		cout << "Number of Passengers: " << flightsList[i].GetNumPassengers() << endl;
		if (flightsList[i].GetStatus() == 1) {printStatus = "Active";}
		if (flightsList[i].GetStatus() == 2) {printStatus = "Complete";}
		if (flightsList[i].GetStatus() == 3) {printStatus = "Cancelled";}
		cout << "Status: " << printStatus << endl;

		cout << endl;
		return;
	}
}

void flights::StoreFlight(){
	ofstream fout;
	fout.open("flights.dat");

	if (!fout.is_open())
	{
		cout << "unable to open flights file" << endl;
		return;
	}

	fout << flightCount << endl;

	for (int i = 0; i < flightCount; i++)
	{
		fout << "***********FLIGHTS LIST**********" << endl;
		fout << endl; 
		fout << "Plane ID: " << flightsList[i].GetPlaneID() << endl;
		fout << "Starting Time: " << flightsList[i].GetStartDate() << endl;
		fout << "Ending Time: " << flightsList[i].GetEndDate() << endl;
		fout << "Starting Airport: "<< flightsList[i].GetsAirport() << endl;
		fout << "Ending Airport: " << flightsList[i].GeteAirport() << endl;
		fout << "Distance: " << flightsList[i].GetRange() << endl;
		fout << "Number of Passengers: " << flightsList[i].GetNumPassengers() << endl;
		fout << "Status: " << flightsList[i].GetStatus() << endl;
	}

	fout.close();
}

void flights::LoadFlight(){
	flight load;
	ifstream fin;
	long long int loadsTime;
	long long int loadeTime;
	string loadPlaneID,loadsAirport,loadeAirport;
	int loadDistance,loadNumPassengers,loadStatus;

	fin.open("flights.dat");

	if (!fin.is_open())
	{
		cout << "unable to open flights file" << endl;
		return;
	}

	fin >> flightCount; fin.ignore();
	for (int i = 0;i < flightCount; i++){
		fin >> loadsTime >> loadeTime >> loadPlaneID >> loadsAirport >> loadeAirport >> loadDistance >> loadNumPassengers >> loadStatus;
		load.SetStartDate(loadsTime);
		load.SetEndDate(loadeTime);
		load.SetPlaneID(loadPlaneID);
		load.SetsAirport(loadsAirport);
		load.SeteAirport(loadeAirport);
		load.SetRange(loadDistance);
		load.SetNumPassengers(loadNumPassengers);
		flightsList.push_back(load);
	}
	fin.close();
}

void flights::UpdateFlight(){
    time_t currtime;
    currtime = time(NULL);
    
    for (int i = 0; i < flightCount; i++)
    {
        if (flightsList[i].GetEndDate() < currtime)
            flightsList[i].SetStatus(2);
    }
}

void flights::PlaneSchedule()
{
	string id;
	cout << "Please enter the Plane ID: ";
	cin >> id;
  for (int i = 0; i < flightCount; i++)
    	{
        cout << "Flight Schedule for Plane: " << id << endl;
        if (flightsList[i].GetPlaneID() == id)
        {
          
            struct tm* mytm1;
            struct tm* mytm2;
            time_t tm1, tm2;
            
            tm1 = flightsList[i].GetStartDate();
            mytm1 = gmtime(&tm1);
            cout << "Start time: " << asctime(mytm1) << endl;

            tm2 = flightsList[i].GetEndDate();
            mytm2 = gmtime(&tm2);
                
            cout << "End Time: " << asctime(mytm2) << endl;
            
            cout << "Starting Airport: " << flightsList[i].GetsAirport() << endl;
            cout << "Ending Airport: " << flightsList[i].GeteAirport() << endl;
            cout << endl;
        }
    }
}
/*
void flights::CrewSchedule()
{
	int id;
	cout << "Please enter the id of the crew: ";
	cin >> id;

       for (int i = 0; i < flightCount; i++)
       {
           cout << "Flight Schedule for crew member: " << id << endl;
           if (flightsList[i].GetPilotID(1) == id ||
               flightsList[i].GetCoPilotID(1) == id ||
               flightsList[i].GetCabinCrewID(1) == id ||
               flightsList[i].GetCabinCrewID(2) == id ||
               flightsList[i].GetCabinCrewID(3) == id 
               )
           {
               cout << "Flight number: " << myflights[i].getflid() << endl;

             struct tm* mytm1;
              struct tm* mytm2;
              time_t tm1, tm2;

              tm1 = myflights[i].getsttime();
              mytm1 = gmtime(&tm1);
              cout << "Start time: " << asctime(mytm1) << endl;

              tm2 = myflights[i].getendtime();
              mytm2 = gmtime(&tm2);

              cout << "End Time: " << asctime(mytm2) << endl;

               cout << "Starting Airport: " << myflights[i].getsap() << endl;
               cout << "Ending Airport: " << myflights[i].geteap() << endl;
               cout << endl;
           }
       }
}
*/
