#ifndef FLIGHTS_H_
#define FLIGHTS_H_

class flights{
	private:
		int flightCount;
		vector<flight> flightsList;
	public:
		flights(){flightCount = 0;}
		void AddFlight();
		void EditFlight();
	        time_t GetDateTime();	
		void DeleteFlight();
		void SearchFlight();
		void PrintFlight();
		void StoreFlight();
		void LoadFlight();
		bool ValidateCrew(int x,long long int tStart,long long int tEnd);
		bool ValidatePlane(string x,long long int tStart,long long int tEnd);
		void PlaneSchedule();
		void CrewSchedule();
		void UpdateFlight();
};	

#endif
