#include <iostream>

using namespace std;

#include <string>
#include "flight.h"

flight::flight(){
	FlightID = 0;
	PlaneID = "none";
	NumPilots = 0;
	NumCrews = 0;
	PilotID = 0;
	CopilotID = 0;
	//CrewID[NumCrews] = 0;
	StartDate = 0;
	EndDate = 0;
	sAirport = "none";
	eAirport = "none";
	NumPassengers = 0;
	Status = 0;
	Range = 0;
}

int flight::GetFlightID() {return FlightID;}
void flight::SetFlightID(int fID) {FlightID = fID;}
string flight::GetPlaneID() {return PlaneID;}
void flight::SetPlaneID(string pID){PlaneID = pID;}
int flight::GetNumPilots(){return NumPilots;}
void flight::SetNumPilots(int nPilots){NumPilots = nPilots;}
int flight::GetNumCrews(){return NumCrews;}
void flight::SetNumCrews(int nCrews) {NumCrews = nCrews;}
int flight::GetPilotID(){return PilotID;}
void flight::SetPilotID(int pilotID){PilotID = pilotID;}
int flight::GetCopilotID(){return CopilotID;}
void flight::SetCopilotID(int copilotID){CopilotID = copilotID;}
int flight::GetCrewID(){return CrewID;}
void flight::SetCrewID(int cID){CrewID = cID;}
int flight::GetStartDate(){return StartDate;}
void flight::SetStartDate(int sDate){StartDate = sDate;}
int flight::GetEndDate(){return EndDate;}
void flight::SetEndDate(int eDate){EndDate = eDate;}
string flight::GetsAirport(){return sAirport;}
void flight::SetsAirport(string stAirport){sAirport = stAirport;}
string flight::GeteAirport(){return eAirport;}
void flight::SeteAirport(string enAirport) {eAirport = enAirport;}
int flight::GetNumPassengers(){return NumPassengers;}
void flight::SetNumPassengers(int pPassengers){NumPassengers = pPassengers;}
int flight::GetStatus(){return Status;}
void flight::SetStatus(int pStatus) {Status = pStatus;}
int flight::GetRange(){return Range;}
void flight::SetRange(int fRange) {Range = fRange;}

