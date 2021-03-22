#include <iostream>

using namespace std;

#include <string>
#include "crew.h"



crew::crew(){
	ID = 0;
	Name = "none";
	//Type = 0;
	Status = 0;
	//FlightHours = 0;
}

crew::crew(string name, int id, int status){
	Name = name;
	ID = id;
	//Type = type;
	Status = status;
	//FlightHours = hours;
}

string crew::GetName(){
	return Name;
}

void crew::SetName(string cName){
	Name = cName;
}

int crew::GetID(){
	return ID;
}

void crew::SetID(int cID){
	ID = cID;
}
/*
int crew::GetType(){
	return Type;
}

void crew::SetType(int cType){
	Type = cType;
}
*/

int crew::GetStatus(){
	return Status;
}

void crew::SetStatus(int cStatus){
	Status = cStatus;
}

void crew::PrintFunction()
{
	string status;
	cout << "Name: " << Name << endl;
	cout << "ID: " << ID << endl;
	if (Status == 1){status = "Available";}
	if (Status == 2){status = "On Leave";}
	if (Status == 3){status = "Sick";}
	cout << "Status: " << status << endl;
}

Pilot::Pilot(string rating,int flighthours,string name,int id,int status):crew(name,id,status){
	Rating = rating;
	flightHrs = flighthours;
}

string Pilot::GetPilotRating() {
	return Rating;
}

void Pilot::SetPilotRating(string pRating){
	Rating = pRating;
}

int Pilot::GetPFH(){
	return flightHrs;
}

void Pilot::SetPFH(int pHrs){
	flightHrs = pHrs;
}

void Pilot::PrintFunction(){
	crew::PrintFunction();
	cout << "Rating: " << Rating << endl;
	cout << "Flight Hours: " << flightHrs << endl;
}

CoPilot::CoPilot(string rating,int flighthours,string name,int id,int status):crew(name,id,status){
        Rating = rating;
        flightHrs = flighthours;
}

string CoPilot::GetCoPilotRating() {
        return Rating;
}

void CoPilot::SetCoPilotRating(string pRating){
        Rating = pRating;
}

int CoPilot::GetCPFH(){
        return flightHrs;
}

void CoPilot::SetCPFH(int pHrs){
        flightHrs = pHrs;
}

void CoPilot::PrintFunction(){
        crew::PrintFunction();
        cout << "Rating: " << Rating << endl;
        cout << "Flight Hours: " << flightHrs << endl;
}

CabinCrew::CabinCrew(string pos,string name,int id,int status):crew(name,id,status)
{
	Position = pos;
}

string CabinCrew::GetPosition(){
        return Position;
}

void CabinCrew::SetPosition(string cPos){
	Position = cPos;
}

void CabinCrew::PrintFunction()
{
	crew::PrintFunction();
	cout << "Type: " << "CabinCrew" << endl;
	cout << "Position: " << Position << endl;
}



