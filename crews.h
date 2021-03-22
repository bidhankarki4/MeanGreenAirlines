#ifndef CREWS_H_
#define CREWS_H_

class crews {
	private: //
		int crewCount;
		vector<crew*> crewsList;//vector to hold all the crews data
	public:
		crews(){crewCount = 0;}
		int GetCount();
		void AddCrew();
		void EditCrew();
		void DeleteCrew();
		void SearchCrew();
		void PrintCrew();
		void LoadCrew();
		void StoreCrew();
		int FindAvailCrew(time_t, time_t, int);
		int findType(int x);
		int findStatus(int y);
		string findName(int z);
};

#endif
