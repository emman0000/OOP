//cricket program task 4
//Programmer Emman Abrar Ali 23k0051

#include<iostream>
#include<string>
using namespace std;

class CricketScore{
int totalRuns; int totalBalls; int outs;
public:
CricketScore(int r, int b, int o): totalRuns(r),totalBalls(b), outs(o){}//end of constructor 
//getter and setter for total runs
int getTotalRuns(){return totalRuns;}
void setTotalRuns(int r){totalRuns=r;}
//getter and setter for total balls
int getTotalBalls(){return totalBalls;}
void setTotalBalls(int b){totalBalls=b;}

//function to find batting average (inline)
inline float battingavg(){return static_cast<float> (totalRuns)/totalBalls;}//end 


//function to find strike rate
inline float strikerate(){return static_cast<float>((totalRuns)/totalBalls)*100;}//end 

};//end of class cricket score
int main (){
CricketScore player1(100,40,2);
CricketScore player2(200,50,3);

cout<<"Player 1: "<<endl; 
cout<<"Total runs: "<<player1.getTotalRuns()<<endl;
cout<< "Total balls: "<<player1.getTotalBalls()<<endl;
cout<<"Batting average: "<<player1.battingavg()<<endl;
cout<<"Strike Rate:"<<player1.strikerate()<<endl;

cout<<"Player 2: "<<endl; 
cout<<"Total runs: "<<player2.getTotalRuns()<<endl;
cout<< "Total balls: "<<player2.getTotalBalls()<<endl;
cout<<"Batting average: "<<player2.battingavg()<<endl;
cout<<"Strike Rate:"<<player1.strikerate()<<endl;



 return 0; 
}//end main 
