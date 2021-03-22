#ifndef PLANES_H_
#define PLANES_H_

class planes{
	private:
		int planeCount;
		vector<plane> planesList;
	public:
		planes(){planeCount = 0;}
		void AddPlane();
		void EditPlane();
		void DeletePlane();
		void SearchPlane();
		void PrintPlane();
		void StorePlane();
		void LoadPlane();
		int findStatus(string x);
		int findSeats(string x);
};

#endif
