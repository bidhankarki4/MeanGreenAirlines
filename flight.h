#ifndef FLIGHT_H_
#define FLIGHT_H_

class flight{
	private:
		int FlightID;
		string PlaneID;
		int NumPilots; //not needed since for >8 hours we need 2 pilot and 2 co pilot so less than that will be 1 amd 1
		int NumCrews;
		int PilotID;
		int CopilotID;
		int CrewID;
		int StartDate;
		int EndDate;
		string sAirport;
		string eAirport;
		int NumPassengers;
		int Status;
		int Range;

	public:
		flight();
		int GetFlightID();
		void SetFlightID(int);
		string GetPlaneID();
		void SetPlaneID(string pID);
		int GetNumPilots();
		void SetNumPilots(int nPilots);
		int GetNumCrews();
		void SetNumCrews(int nCrews);
		int GetPilotID();
		void SetPilotID(int pilotID);
		int GetCopilotID();
		void SetCopilotID(int copilotID);
		int GetCrewID();
		void SetCrewID(int cID);
		int GetStartDate();
		void SetStartDate(int sDate);
		int GetEndDate();
		void SetEndDate(int eDate);
		string GetsAirport();
		void SetsAirport(string stAirport);
		string GeteAirport();
		void SeteAirport(string enAirport);
		int GetNumPassengers();
		void SetNumPassengers(int pPassengers);
		int GetStatus();
		void SetStatus(int pStatus);
		int GetRange();
		void SetRange(int fRange);
};

#endif
