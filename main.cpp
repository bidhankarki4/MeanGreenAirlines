//Bidhan Karki
//Homework 4
#include <iostream>
#include <fstream>

using namespace std;

#include <string>
#include <vector>
#include <cstdlib>
#include "crew.h"
#include "plane.h"
#include "flight.h"
#include "crews.h"
#include "planes.h"
#include "flights.h"

crews crewlist;
planes planelist;
flights flightlist;

int main(){
	cout << "+------------------------------------------------------+" << endl;
	cout << "|            Computer Science and Engineering          |" << endl;
	cout << "|             CSCE 1040 - Computer Science II          |" << endl;
	cout << "|        Bidhan Karki   bk0273  bk0273@my.unt.edu      |" << endl;
	cout << "+------------------------------------------------------+" << endl;

	
	int options;
	int crewMenu,planeMenu,flightMenu;
	do{
		cout << "************WELCOME TO MEAN GREEN AIRLINES*************" << endl;
		cout << "************************M E N U************************" << endl;
		cout << "1. CREW MENU" << endl;
		cout << "2. PLANE MENU" << endl;
		cout << "3. FLIGHT MENU" << endl;
		cout << "4. QUIT" << endl;
		cout << endl;
		cin >> options;
		switch(options){
			case 1:
				do{
				cout << "**********CREW MENU**********" << endl;
				cout << "1. ADD CREW" << endl;
				cout << "2. EDIT CREW" << endl;
				cout << "3. DELETE CREW" << endl;
				cout << "4. SEARCH CREW" << endl;
				cout << "5. PRINT CREW" << endl;
				cout << "6. STORE CREW" << endl;
				cout << "7. LOAD CREW" << endl;
				cout << "8. QUIT CREW MENU" << endl;
				cin >> crewMenu;
				if (crewMenu == 1){crewlist.AddCrew();}
				if (crewMenu == 2){crewlist.EditCrew();}
				if (crewMenu == 3){crewlist.DeleteCrew();}
				if (crewMenu == 4){crewlist.SearchCrew();}
				if (crewMenu == 5){crewlist.PrintCrew();}
				if (crewMenu == 6){crewlist.StoreCrew();}
				if (crewMenu == 7){crewlist.LoadCrew();}
				} while (crewMenu != 8);
				break;

			case 2:
				do{
                                cout << "**********PLANE MENU**********" << endl;
                                cout << "1. ADD PLANE" << endl;
                                cout << "2. EDIT PLANE" << endl;
                                cout << "3. DELETE PLANE" << endl;
                                cout << "4. SEARCH PLANE" << endl;
                                cout << "5. PRINT PLANE" << endl;
                                cout << "6. STORE PLANE" << endl;
                                cout << "7. LOAD PLANE" << endl;
                                cout << "8. QUIT PLANE MENU" << endl;
                                cin >> planeMenu;
                                if (planeMenu == 1){planelist.AddPlane();}
                                if (planeMenu == 2){planelist.EditPlane();}
                                if (planeMenu == 3){planelist.DeletePlane();}
                                if (planeMenu == 4){planelist.SearchPlane();}
                                if (planeMenu == 5){planelist.PrintPlane();}
                                if (planeMenu == 6){planelist.StorePlane();}
                                if (planeMenu == 7){planelist.LoadPlane();}
                                } while (planeMenu != 8);
                                break;

			case 3:
				  do{
                                cout << "**********FLIGHT MENU**********" << endl;
                                cout << "NOTE: ONLY ADD FLIGHT WORKS FOR NOW SINCE PROGRAM IS INCOMPLETE" << endl;
				cout << "1. ADD FLIGHT" << endl;
                                cout << "2. EDIT FLIGHT" << endl;
                                cout << "3. DELETE FLIGHT" << endl;
                                cout << "4. SEARCH FLIGHT" << endl;
                                cout << "5. PRINT FLIGHT" << endl;
                                cout << "6. STORE FLIGHT" << endl;
                                cout << "7. LOAD FLIGHT" << endl;
				cout << "8. UPDATE FLIGHT" << endl;
				cout << "9. PLANE SCHEDULE" << endl;
				//cout << "10. CREW SCHEDULE" << endl;
                                cout << "10. QUIT FLIGHT MENU" << endl;
                                cin >> flightMenu;
                                if (flightMenu == 1){flightlist.AddFlight();}
                                if (flightMenu == 2){flightlist.EditFlight();}
                                if (flightMenu == 3){flightlist.DeleteFlight();}
                                if (flightMenu == 4){flightlist.SearchFlight();}
                                if (flightMenu == 5){flightlist.PrintFlight();}
                                if (flightMenu == 6){flightlist.StoreFlight();}
                                if (flightMenu == 7){flightlist.LoadFlight();}
				if (flightMenu == 8){flightlist.UpdateFlight();}
				if (flightMenu == 9){flightlist.PlaneSchedule();}
				//if (flightMenu == 10){flightlist.CrewSchedule();}
				
                                } while (flightMenu != 10);
                                break;


		

		}

	}while (options != 4);

	return 0;
}
