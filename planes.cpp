#include <iostream>
#include <fstream>

using namespace std;

#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "plane.h"
#include "planes.h"

int planes::findStatus(string x){
	for (int i = 0; i < planeCount; i++){
		if (planesList[i].GetTailNum()== x){return planesList[i].GetStatus();}
	}
	return -1;
}

int planes::findSeats(string x){for (int i = 0; i < planeCount; i++){
                if (planesList[i].GetTailNum()== x){return planesList[i].GetNumSeats();}
        }
        return -1;
}

void planes::AddPlane(){
	plane add;
	string addMake,addTailNum;
	int addModel,addNumSeats,addRange,addMinimumCrew,addStatus;
	cout << "Enter the make of the plane: ";
	getline(cin,addMake);
	getline(cin,addMake,'\n');
	cout << "Enter the TailNum/Unique ID of the Aircraft: ";
	getline(cin,addTailNum,'\n');
	cout << "Enter the Model of the plane: ";
	cin >> addModel;
	cout << "Enter the number of seats in the plane: ";
	cin >> addNumSeats;
	do{
		if(addNumSeats < 0){
			cout << "INVALID OPTION! PLEASE RE-ENTER" << endl;
			cin >> addNumSeats;
		}
	}	while (addNumSeats < 0);
	cout << "Enter the range of the Plane: ";
	cin >> addRange;
	do{
		if(addRange < 0){
			cout << "INVALID OPTION! PLEASE RE-ENTER" << endl;
			cin >> addRange;
		}
	}	while (addRange < 0);
	cout << "Enter the status of the plane: " ;
	cout << endl;
	cout << "1 for Available" << endl;
	cout << "2 for Busy" << endl;
	cout << "3 for Cancelled" << endl;
	cin >> addStatus;
	do{
		if((addStatus < 1) || (addStatus > 3)){
			cout << "STATUS INVALID!. PLEASE RE-ENTER" << endl;
			cin >> addStatus;
		} 
	}while ((addStatus < 1) || (addStatus > 3));	       
	cout  << "Enter the minimum crew mwber int the plane: ";
	cin >> addMinimumCrew;
	do{
		if(addMinimumCrew < 0){
			cout << "INVALID OPTION! PLEASE RE-ENTER" << endl;
			cin >> addMinimumCrew;
		}
	}	while (addMinimumCrew < 0);

	add.SetMake(addMake);
	add.SetTailNum(addTailNum);
	add.SetModel(addModel);
	add.SetNumSeats(addNumSeats);
	add.SetRange(addRange);
	add.SetStatus(addStatus);
	add.SetMinimumCrew(addMinimumCrew);

	planesList.push_back(add);
	planeCount++;
	cout << "PLANE SUCCESFULLY ADDED" << endl;
}

void planes::EditPlane(){
	string editTailNum;
	int choice;
	int editNumSeats,editRange,editStatus,editMinimumCrew;
	cout << "Enter the TailNum/Unique ID of the Plane: ";
	getline(cin,editTailNum);
	getline(cin,editTailNum,'\n');
	for ( int i = 0; i < planeCount; i++){
		if (planesList[i].GetTailNum() == editTailNum){
			cout << "What would you like to Change?" << endl;
			cout << "1(Number of Seats), 2(Range), 3(Status), 4(Minimum Number of Crew)" << endl;
			cin >> choice;
			switch(choice){
				case 1:
					cout << "Enter the new Number of Seats of the Plane" ;
					cin >> editNumSeats;
					planesList[i].SetNumSeats(editNumSeats);
					return;

				case 2:
					cout << "Enter the new Range of the Plane:";
					cin >> editRange;
					planesList[i].SetRange(editRange);
					return;

				case 3:
					cout << "Enter the new Status of the Plane:";
					cout << "1 for Available" << endl;
					cout << "2 for Busy" << endl;
					cout << "3 for Cancelled" << endl;
					cin >> editStatus;
					planesList[i].SetStatus(editStatus);
					return;

				case 4:
					cout << "Enter the new Minimum number of crew:";
					cin >> editMinimumCrew;
					planesList[i].SetMinimumCrew(editMinimumCrew);
					return;

			}
		}

	}

	cout << "INVALID Tail Number!" << endl;	


}

void planes::DeletePlane(){
	string deleteTailNum;
	cout << "Enter the Tail Number of the Plane to delete: ";
	getline(cin,deleteTailNum);
	getline(cin,deleteTailNum,'\n');
	for (int i = 0; i < planeCount; i++){
		if (planesList[i].GetTailNum() == deleteTailNum){
			planesList.erase(planesList.begin()+i);
			planeCount--;	
			return;
		}

	}
	cout << "INVALID TAIL NUMBER.PLANE NOT FOUND!" << endl;
}

void planes::SearchPlane(){
	string searchTailNum;
	string searchMake;
	string searchStatus;
	int searchModel,findStatus;

	cout << "How do you want to search plane?" << endl;
	cout << "1. Tail Number" << endl;
	cout << "2. Make" << endl;
	cout << "3. Model" << endl;
	cout << "4. Status" << endl;

	int options;
	cin >> options;
	switch(options){

		case 1:
			cout << "Please enter the Tail Number: ";
			getline(cin,searchTailNum);
			getline(cin,searchTailNum,'\n');
			for (int i = 0; i < planeCount; i++){
				if(planesList[i].GetTailNum() == searchTailNum)
				{
					cout << "**********PLANE FOUND**********" << endl;
					cout << "Tail Number: " << searchTailNum << endl;
					cout << "Make: " << planesList[i].GetMake() << endl;
					cout << "Model: " << planesList[i].GetModel() << endl;
					if (planesList[i].GetStatus() == 1) {searchStatus = "Available";}
					if (planesList[i].GetStatus() == 2) {searchStatus = "Busy";}
					if (planesList[i].GetStatus() == 3) {searchStatus = "Cancelled";}
					cout << "Status: " << searchStatus << endl;
					cout << "No. of Seats: " << planesList[i].GetNumSeats() << endl;
					cout << "Range: " << planesList[i].GetRange() << endl;
					cout << "Minimum No. of Crew: " << planesList[i].GetMinimumCrew() << endl;
					cout << endl;
					return;
				}
			}
			cout << "INVALID TAIL NUMBER." << endl;
			break;

		case 2:
			cout << "Please enter the Make of the Plane: ";
			getline(cin,searchMake);
			getline(cin,searchMake,'\n');
			for (int i = 0; i < planeCount; i++){
				if(planesList[i].GetMake() == searchMake)
				{
					cout << "**********PLANE FOUND**********" << endl;
					cout << "Tail Number: " << planesList[i].GetTailNum() << endl;
					cout << "Make: " << searchMake << endl;
					cout << "Model: " << planesList[i].GetModel() << endl;
					if (planesList[i].GetStatus() == 1) {searchStatus = "Available";}
					if (planesList[i].GetStatus() == 2) {searchStatus = "Busy";}
					if (planesList[i].GetStatus() == 3) {searchStatus = "Cancelled";}
					cout << "Status: " << searchStatus << endl;
					cout << "No. of Seats: " << planesList[i].GetNumSeats() << endl;
					cout << "Range: " << planesList[i].GetRange() << endl;
					cout << "Minimum No. of Crew: " << planesList[i].GetMinimumCrew() << endl;
					cout << endl;
					return;
				}
			}
			cout << "INVALID MAKE." << endl;
			break;

		case 3:
			cout << "Please enter the Model Number: ";
			cin >> searchModel;
			for (int i = 0; i < planeCount; i++){
				if(planesList[i].GetModel() == searchModel)
				{
					cout << "**********PLANE FOUND**********" << endl;
					cout << "Tail Number: " << planesList[i].GetTailNum() << endl;
					cout << "Make: " << planesList[i].GetMake() << endl;
					cout << "Model: " << searchModel << endl;
					if (planesList[i].GetStatus() == 1) {searchStatus = "Available";}
					if (planesList[i].GetStatus() == 2) {searchStatus = "Busy";}
					if (planesList[i].GetStatus() == 3) {searchStatus = "Cancelled";}
					cout << "Status: " << searchStatus << endl;
					cout << "No. of Seats: " << planesList[i].GetNumSeats() << endl;
					cout << "Range: " << planesList[i].GetRange() << endl;
					cout << "Minimum No. of Crew: " << planesList[i].GetMinimumCrew() << endl;
					cout << endl;
					return;
				}
			}
			cout << "INVALID MODEL NUMBER." << endl;
			break;

		case 4:
			cout << "Please enter the status of the plane: ";
			cout << "1 for Available Planes" << endl;
			cout << "2 for Busy Planes" << endl;
			cout << "3 for Cancelled Planes" << endl;
			cin >> findStatus;
			for (int i = 0; i < planeCount; i++){
				if((findStatus == 1) && (findStatus == planesList[i].GetStatus())){
					cout << "**********PLANE FOUND**********" << endl;
					cout << "Tail Number: " << planesList[i].GetTailNum() << endl;
					cout << "Make: " << planesList[i].GetMake() << endl;
					cout << "Model: " << planesList[i].GetModel() << endl;
					cout << "Status: " << "Available" << endl;
					cout << "No. of Seats: " << planesList[i].GetNumSeats() << endl;
					cout << "Range: " << planesList[i].GetRange() << endl;
					cout << "Minimum No. of Crew: " << planesList[i].GetMinimumCrew() << endl;
					cout << endl;
					return;
				}

				if((findStatus == 2) && (findStatus == planesList[i].GetStatus())){
					cout << "**********PLANE FOUND**********" << endl;
					cout << "Tail Number: " << planesList[i].GetTailNum() << endl;
					cout << "Make: " << planesList[i].GetMake() << endl;
					cout << "Model: " << searchModel << endl;
					cout << "Status: " << "Busy" << endl;
					cout << "No. of Seats: " << planesList[i].GetNumSeats() << endl;
					cout << "Range: " << planesList[i].GetRange() << endl;
					cout << "Minimum No. of Crew: " << planesList[i].GetMinimumCrew() << endl;
					cout << endl;
					return;
				}

				if((findStatus == 3) && (findStatus == planesList[i].GetStatus())){
					cout << "**********PLANE FOUND**********" << endl;
					cout << "Tail Number: " << planesList[i].GetTailNum() << endl;
					cout << "Make: " << planesList[i].GetMake() << endl;
					cout << "Model: " << searchModel << endl;
					cout << "Status: " << "Cancelled" << endl;
					cout << "No. of Seats: " << planesList[i].GetNumSeats() << endl;
					cout << "Range: " << planesList[i].GetRange() << endl;
					cout << "Minimum No. of Crew: " << planesList[i].GetMinimumCrew() << endl;
					cout << endl;
					return;
				}


			}

	}	

	cout << "PLANE NOT FOUND!" << endl;
}

void planes::PrintPlane(){
	string printStatus;
	for (int i  = 0; i < planeCount; i++){
		cout << "**********PLANES LIST**********" << endl;
		cout << "Tail Number: " << planesList[i].GetTailNum() << endl;
		cout << "Make: " << planesList[i].GetMake() << endl;
		cout << "Model: " << planesList[i].GetModel() << endl;
		if (planesList[i].GetStatus() == 1) {printStatus = "Available";}
		if (planesList[i].GetStatus() == 2) {printStatus = "Busy";}
		if (planesList[i].GetStatus() == 3) {printStatus = "Cancelled";}
		cout << "Status: " << printStatus << endl;
		cout << "No. of Seats: " << planesList[i].GetNumSeats() << endl;
		cout << "Range: " << planesList[i].GetRange() << endl;
		cout << "Minimum No. of Crew: " << planesList[i].GetMinimumCrew() << endl;
		cout << endl;
	}

}


void planes::LoadPlane(){
	plane load;
	ifstream fin;
	string loadTailNum,loadMake;
	int loadModel,loadStatus,loadNumSeats,loadRange,loadMinimumCrew;
	fin.open("planes.dat");
	if(!fin.is_open()){
		cout << "The file did not open." << endl;
		return;
	}
	fin >> planeCount; fin.ignore();

	for (int i = 0; i < planeCount; i++){
		getline(fin,loadTailNum);
		getline(fin,loadMake);
		fin >> loadModel >> loadStatus >> loadNumSeats >> loadRange >> loadMinimumCrew;
		load.SetTailNum(loadTailNum);
		load.SetMake(loadMake);
		load.SetModel(loadModel);
		load.SetStatus(loadStatus);
		load.SetNumSeats(loadNumSeats);
		load.SetRange(loadRange);
		load.SetMinimumCrew(loadMinimumCrew);
		planesList.push_back(load);
	}
	fin.close();
}

void planes::StorePlane(){
	ofstream fout;
	fout.open("planes.dat");
	if(!fout.is_open()){
		cout << "The file did not open." << endl;
		return;
	}
	fout << planeCount << endl;
	for (int i  = 0; i < planeCount; i++){
		fout << "Tail Number: " << planesList[i].GetTailNum() << endl;
		fout << "Make: " << planesList[i].GetMake() << endl;
		fout << "Model: " << planesList[i].GetModel() << endl;
		fout << "Status: " << planesList[i].GetStatus()  << endl;
		fout << "No. of Seats: " << planesList[i].GetNumSeats() << endl;
		fout << "Range: " << planesList[i].GetRange() << endl;
		fout << "Minimum No. of Crew: " << planesList[i].GetMinimumCrew() << endl;
	}
	fout.close();
}





