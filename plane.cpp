#include <iostream>

using namespace std;

#include <string>
#include "plane.h"

plane::plane(){
	Make = "none";
	TailNum = "none";
	Model = 0;
	NumSeats = 0;
	Range = 0;
	MinimumCrew = 0;
	Status = 0;
}

string plane::GetMake(){return Make;}
void plane::SetMake(string pMake) {Make = pMake;}
string plane::GetTailNum(){return TailNum;}
void plane::SetTailNum(string pTailNum){TailNum = pTailNum;}
int plane::GetModel(){return Model;}
void plane::SetModel(int pModel){Model = pModel;}
int plane::GetNumSeats(){return NumSeats;}
void plane::SetNumSeats(int pNumSeats){NumSeats = pNumSeats;}
int plane::GetRange(){return Range;}
void plane::SetRange(int pRange){Range = pRange;}
int plane::GetMinimumCrew(){return MinimumCrew;}
void plane::SetMinimumCrew(int pMinimumCrew){MinimumCrew = pMinimumCrew;}
int plane::GetStatus(){return Status;}
void plane::SetStatus(int pStatus){Status = pStatus;} 
