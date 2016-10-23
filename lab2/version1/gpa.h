#IFNDEF GPA_H
#DEFINE GPA_H

Class GPA {
	private:
		GPA( );
		GPA(double, int, double);
		void setGrade(double);
		void setCredits(int);
		void setInfo(double, int);
		void setLetterGrade(string);
		void inputGrade( );
		void inputCredits( );
		void inputLetterGrade( );
		double getGrade( );
		int getCredits( );
		double getQualityPoints( );
		string getLetterGrade( );
		void display( );
	public:
		string letterGrade;
		double grade;
		int credits;
		double qualityPoints = grade * credits;
};
