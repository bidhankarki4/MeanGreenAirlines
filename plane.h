#ifndef PLANE_H_
#define PLANE_H_

class plane{
	private:
		string Make;
		int Model;
		string TailNum;
		int NumSeats;
		int Range;
		int MinimumCrew;
		int Status;
	public:
		plane();
		string GetMake();
		void SetMake(string pMake);
		int GetModel();
		void SetModel(int pModel);
		string GetTailNum();
		void SetTailNum(string pTailNum);
		int GetNumSeats();
		void SetNumSeats(int pNumSeats);
		int GetRange();
		void SetRange(int pRange);
		int GetMinimumCrew();
		void SetMinimumCrew(int pMinimumCrew);
		int GetStatus();
		void SetStatus(int pStatus);
};

#endif
