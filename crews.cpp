#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include <string>
#include <vector>
#include "crew.h"
#include "crews.h"
#include <iterator>

void crews::AddCrew(){
	crew *add;//object
	string addName;
	int addID;
	int addType;
	int addStatus;
	
	//prompting the user for all necessary data
	cout << "Enter the name of the crew member: ";
	getline(cin,addName);
	getline(cin,addName,'\n');
	cout << "Enter the ID of the crew member: ";
	cin >> addID;
	cout << "Enter the type of the crew member" << endl;
	cout << "1 for Cabin Crew" << endl;
	cout << "2 for Co-Pilot" << endl;
	cout << "3 for Pilot" << endl;
	cin >> addType;
	cout << "Enter the status of the crew" << endl;
	cout << "1 for Available, 2 for On Leave and 3 for Sick: " ;
	cin >> addStatus;

	string addRate,addPos;
	int addflightHrs;

	//Checking for the type
	if (addType == 1)
	{
		cout << "Enter the Position of the Cabin Crew: ";
		cin.ignore();
		getline(cin,addPos,'\n');
		add = new CabinCrew(addPos,addName,addID,addStatus);
	}
	if (addType == 2)
	{
		cout << "Enter 5 character rating code for CoPilot: ";
		cin >> addRate;
		cout << "Enter the total flight hours of the CoPilot: ";
		cin >> addflightHrs;
		add = new CoPilot(addRate,addflightHrs,addName,addID,addStatus);
	}
	if (addType == 3)
	{
		cout << "Enter 5 character rating code for Pilot: ";
		cin >> addRate;
		cout << "Enter the total flight hours of the Pilot: ";
		cin >> addflightHrs;
		add = new Pilot(addRate,addflightHrs,addName,addID,addStatus);
	}

	/*
	   add.SetName(addName);
	   add.SetID(addID);
	   add.SetType(addType);
	   add.SetStatus(addStatus);
	   */
	crewsList.push_back(add);
	crewCount++;
	cout << "Crew Member Added!" << endl;
}

void crews::EditCrew(){
	int editStatus;
	int editID;
	cout << "Enter the id of the crew member you want to edit: " ;
	cin >> editID;
	for (int i = 0; i < crewCount; i++){
		if (crewsList[i]->GetID()== editID){
			cout << "Enter the new status of the crew" << endl;
			cout << "1 for Available" << endl;
			cout << "2 for On Leave" << endl;
			cout << "3 for Sick" << endl;
			cin >> editStatus;
			crewsList[i]->SetStatus(editStatus);
			return;
		}
	
	}
	cout << "CREW NOT FOUND" << endl;
	return;
}

void crews::DeleteCrew(){
	int id;
	cout << "Enter the ID of crew member you want to delete: ";
	cin >> id;
	for (int i = 0; i < crewCount; i++){
		if (crewsList[i]->GetID() == id){
			crewsList.erase(crewsList.begin()+i);
			crewCount--;
			cout << "Crew Member Deleted" << endl;
		}
		else {
			cout << "INVALID CREW ID!" << endl;
		}
	}
}

void crews::SearchCrew(){
	int searchID;
	string searchType,searchStatus;
	cout << "Enter the ID of the Crew you want to Search: ";
	cin >> searchID;
	for (int i = 0; i < crewCount ;i++){
		if (crewsList[i]->GetID() == searchID)
		{
			cout << "**********CREW FOUND**********" << endl;
			cout << "Name: " << crewsList[i]->GetName() << endl;
			cout << "ID: " << searchID << endl;
			if (crewsList[i]->GetStatus() == 1) {searchStatus = "Available";}
			if (crewsList[i]->GetStatus() == 2) {searchStatus = "On Leave";}
			if (crewsList[i]->GetStatus() == 3) {searchStatus = "Sick";}
			cout << "Status: " << searchStatus << endl;
			
			//using dynamic cast to change base class to derived class
			crew *crewtype = crewsList[i];
			Pilot *pilotType;
			pilotType = dynamic_cast <Pilot*> (crewtype);

			CoPilot *copilotType;
			copilotType = dynamic_cast <CoPilot*> (crewtype);

			CabinCrew *cabincrewType;
			cabincrewType = dynamic_cast <CabinCrew*> (crewtype);

			if (pilotType){cout << "Type: " << "Pilot" << endl;}
			if (copilotType) {cout << "Type: " << "CoPilot" << endl;}
			if (cabincrewType) {cout << "Type: " << "CabinCrew" << endl;}

			/*
			   if (crewsList[i].GetType() == 1) {searchType = "Cabin Crew";}
			   if (crewsList[i].GetType() == 2) {searchType = "Co-Pilot";}
			   if (crewsList[i].GetType() == 3) {searchType = "Pilot";}
			   cout << "Type: " << searchType << endl;
			   */
			return;
		}
	}
	cout << "INVALID ID. CREW NOT FOUND!" << endl;
	return;
}



void crews::PrintCrew(){
	for (int i = 0; i < crewCount ; i++){
		//using dynamic cast to change base class to derived class
	 		crew *crewtype = crewsList[i];
                        Pilot *pilotType;
                        pilotType = dynamic_cast <Pilot*> (crewtype);

                        CoPilot *copilotType;
                        copilotType = dynamic_cast <CoPilot*> (crewtype);

                        CabinCrew *cabincrewType;
                        cabincrewType = dynamic_cast <CabinCrew*> (crewtype);

                        if (pilotType){pilotType->PrintFunction();}
                        if (copilotType) {copilotType->PrintFunction();}
                        if (cabincrewType) {cabincrewType->PrintFunction();}
			cout << endl;
	
	}
}

void crews::LoadCrew(){
	//crew load;
	ifstream fin;
	string loadName;
	int loadID;
	int loadType;
	int loadStatus;
	string loadPosition,loadRating;
	int loadflightHrs;
	fin.open("crews.dat");
	if(!fin.is_open()){
		cout << "The file did not open." << endl;
		return;
	}
	fin >> crewCount; fin.ignore();

	for (int i = 0; i < crewCount; i++){
		crew *load;
		fin >> loadType;

		if (loadType == 1)
		{
			getline(fin,loadName,'\n');
			fin >> loadID >> loadStatus;
			getline(fin,loadPosition,'\n');
			CabinCrew *cabindata = new CabinCrew(loadPosition,loadName,loadID,loadStatus);
			crewsList.push_back(cabindata);
		}
		if (loadType == 2)
		{
			getline(fin,loadName,'\n');
			fin >> loadID >> loadStatus >> loadRating >> loadflightHrs;
			CoPilot *copilotdata = new CoPilot(loadRating,loadflightHrs,loadName,loadID,loadStatus);
			crewsList.push_back(copilotdata);
		}
		if (loadType == 3)
		{
                        getline(fin,loadName,'\n');
                        fin >> loadID >> loadStatus >> loadRating >> loadflightHrs;
                        Pilot *pilotdata = new Pilot(loadRating,loadflightHrs,loadName,loadID,loadStatus);
                        crewsList.push_back(pilotdata);
                }

}
	fin.close();
}

void crews::StoreCrew(){
	ofstream fout;
	fout.open("crews.dat");
	if(!fout.is_open()){
		cout << "The file did not open." << endl;
		return;
	}
	fout << crewCount << endl;
	 
for (int i = 0;i < crewCount; i++){
	//using dynamic cast to change base class to derived class
			crew *crewtype = crewsList[i];
                        Pilot *pilotType;
                        pilotType = dynamic_cast <Pilot*> (crewtype);

                        CoPilot *copilotType;
                        copilotType = dynamic_cast <CoPilot*> (crewtype);

                        CabinCrew *cabincrewType;
                        cabincrewType = dynamic_cast <CabinCrew*> (crewtype);

		if (pilotType){
		fout << crewsList[i]->GetID() << endl;
		fout << crewsList[i]->GetName() << endl;
		fout << crewsList[i]->GetStatus() << endl;
		fout << pilotType->GetPilotRating() << endl;
		fout << pilotType->GetPFH() << endl;
		}

		if (copilotType){
                fout << crewsList[i]->GetID() << endl;
                fout << crewsList[i]->GetName() << endl;
                fout << crewsList[i]->GetStatus() << endl;
                fout << copilotType->GetCoPilotRating() << endl;
                fout << copilotType->GetCPFH() << endl;
                }

		if (cabincrewType){
                fout << crewsList[i]->GetID() << endl;
                fout << crewsList[i]->GetName() << endl;
                fout << crewsList[i]->GetStatus() << endl;
		fout << cabincrewType->GetPosition() << endl;
		}

}
	fout.close();
}

int crews::findType(int x){
	//to return the type in flights.cpp
	for (int i = 0; i < crewCount; i++){
		if (crewsList[i]->GetID()== x){
			crew *crewtype = crewsList[i];
                        Pilot *pilotType;
                        pilotType = dynamic_cast <Pilot*> (crewtype);

                        CoPilot *copilotType;
                        copilotType = dynamic_cast <CoPilot*> (crewtype);

                        CabinCrew *cabincrewType;
                        cabincrewType = dynamic_cast <CabinCrew*> (crewtype);
			
			if (pilotType){return 3;}
			if (copilotType){return 2;}
			if (cabincrewType){return 1;}
		}
		
	}
	return -1;
}

int crews::findStatus(int y){
	//to return the status in flights.cpp
	for (int i = 0; i < crewCount; i++){
		if (crewsList[i]->GetID()==y){return crewsList[i]->GetStatus();}
	}
	return -1;
}

string crews::findName(int z){
	//to return the name in flights.cpp
	for (int i = 0; i > crewCount; i++){
		if(crewsList[i]->GetID() == z){return crewsList[i]->GetName();}
	}
	return NULL;
}
