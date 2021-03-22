#ifndef CREW_H_
#define CREW_H_

class crew
{
	private:
		string Name;
		int ID;
		int Status;
	public:
		crew(); //default Constructor
		crew(string name, int id, int status); //fully specified constructor
		//crew(string name, int id, string type, int status, int hours)
		string GetName();
		int GetID();
		//int GetType();
	        int GetStatus();
		void SetID(int cID);
		//void SetType(int cType);
		void SetName(string cName);
		void SetStatus(int cStatus);
		virtual void PrintFunction(); //virtual print function
		//int GetFlightHours();
		//void SetFlightHours(int cHours);
};	

class Pilot: public crew //child class
{
	private:
		string Rating;
		int flightHrs;
	public:
		Pilot(string rat,int fli,string name,int id,int status); //fully specified constructor
		string GetPilotRating();
		void SetPilotRating(string);
		int GetPFH();
		void SetPFH(int);
		void PrintFunction(); //over riding virtual print function
};

class CoPilot: public crew //child class
{
        private:
                string Rating;
                int flightHrs;
        public:
                CoPilot(string rat,int fli,string name,int id,int status); //fully specified constructor
                string GetCoPilotRating();
                void SetCoPilotRating(string);
                int GetCPFH();
                void SetCPFH(int);
                void PrintFunction(); //over riding virtual print function
};

class CabinCrew: public crew //child class
{
	private:
		string Position;
	public:
		CabinCrew(string pos,string name,int id,int status); //fully specified constructor
		string GetPosition();
		void SetPosition(string);
		void PrintFunction(); //over riding virtual print function
};

#endif
