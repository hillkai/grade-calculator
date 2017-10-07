/**********************
 * Program: assign3.cpp
 * Author: Kaitlin Hill
 * Date: 2/5/17
 * Description: Comes up with a user's grade based on user input
 * Input: Assignments and grades
 * Output: Percentage and overall grade of user. 
 * *******************/
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void what_to_calculate();
float error_check(string s);
float find_the_grade();
float recitation_grade();

/*******************
 * Function: main
 * Description: Starts program
 * Parameters: none
 * Pre-conditions: none
 * Post-condition: none
 * Return: 0
 * ****************/
int main(){
   what_to_calculate();
   return 0;
}

/********************
 * Function: what_to_calcuate
 * Description: Let's user choose what to calculate and does math to figure out overall grade.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * ********************/
void what_to_calculate(){
   float labs_percent;
   float assignments_percent;
   float tests_percent;
   float recitation_percent;
   float lab_weight;
   float assignment_weight;
   float test_weight;
   float recitation_weight;
   float overall_percentage;
   string to_calculate;
   int x = 1;

   do{
     cout<< "Would you like to find your average for labs, assignments, tests, recitation, overall for class or exit the program?"<<endl;
     cin >> to_calculate;
     if (to_calculate == "labs"){
	labs_percent = find_the_grade();
	x = 1;
    }
     else if (to_calculate == "assignments"){
	assignments_percent = find_the_grade();
	x = 1;
     }
     else if (to_calculate == "tests"){
	tests_percent = find_the_grade();
	x = 1;
     }
     else if (to_calculate == "recitation"){
	recitation_percent = recitation_grade();
	x = 1;
     }
     else if (to_calculate == "overall"){
        cout<< "What is the weight of labs?"<< endl;
        cin>> lab_weight;
        cout<< "What is the weight of assignments?"<< endl;
        cin>> assignment_weight;
        cout<< "What is the weight of tests?"<< endl;
        cin>> test_weight;
        cout<< "What is the weight of recitation?"<< endl;
        cin>> recitation_weight;
        overall_percentage = ((labs_percent*lab_weight)+ (assignments_percent*assignment_weight)+ (tests_percent*test_weight)+ 
	     (recitation_percent*recitation_weight))/(lab_weight + assignment_weight + test_weight + recitation_weight);
        cout<< "Your overall grade is: "<< overall_percentage<< '%'<< endl;
	x = 1;
     }
     else if (to_calculate == "exit"){
	  x = 2;
     }
     else {
	  x = 1;
     }
   }while(x == 1);
   return;
}

/*******************
 * Function: error_check
 * Description: check for good input and if not, repromts user for good input.
 * Parameters: string s
 * Pre-Conditions: input must be a string.
 * Post-Conditions: none
 * Return: x or float number that is good input.
 * ******************/
float error_check(string s){
   bool bad_input;
   bad_input = false;
      for (int i = 0; i<s.size(); i++){
	   if(!(s.at(i)>='0' && s.at(i)<='9'))
	      bad_input = true;
	}
   while (bad_input == true){
      cout << "Enter a good int: "<<endl;
      cin >> s;
      bad_input = false;
	for (int i = 0; i<s.size(); i++){
	   if(!(s.at(i)>='0' && s.at(i)<='9'))
	      bad_input = true;
	}
   }
   float x = atof(s.c_str());
   return x; 
}

/*******************
 * Function: find_the_grade
 * Description: finds the grade based on user input.
 * Parameters: none
 * Pre-conditions: user must input numbers
 * Post-conditions: none
 * Return: percentage_point or the percentage for whatever part of the grade the user was finding.
 * ****************/
float find_the_grade(){
   int j = 1;
   string num_of = "";
   float actual_points;
   float total_possible_points;
   float track_possible_points;
   float track_actual_points;
   int x = 0;
   string point_value_vary;
   float percentage_points;
   
   while(j == 1){
      cout<< "Total amount you would like to calculate for?"<<endl;
      cin>> num_of;
      float float_num_of = error_check(num_of);
      cout<<"Do the point values vary?"<<endl;
      cin>> point_value_vary;
      if (point_value_vary == "yes"){
	 for (x = 0; x < float_num_of; x++){
	    cout<<"How many points possible on the "<< x+1 << " one?"<<endl;
	    cin>> total_possible_points;
	    track_possible_points += total_possible_points;
	 }
	 for (x = 0; x < float_num_of; x++){
	    cout<<"How many points did you get on the "<< x+1 << " one?"<<endl;
	    cin>> actual_points;
	    track_actual_points += actual_points;
	 }
	 j = 2;
      }
      else if (point_value_vary == "no"){
	 cout<<"How many points is each one worth?"<<endl;
	 float total_possible_points;
	 cin>> total_possible_points;
	 track_possible_points = total_possible_points * float_num_of;
	 for (int x = 0; x < float_num_of; x++){
	    cout<<"How many point did you get on the "<< x+1 << " one?"<<endl;
	    cin >> actual_points; 
	    track_actual_points += actual_points;
	}
	 j = 2;
      }
      else{
	 j = 1;
      }
   }
   float percentage_point = (track_actual_points/track_possible_points) * 100;
   cout<< "Your percentage is: "<< percentage_point<< '%'<< endl;
   return percentage_point;
}

/**********************
 * Function: recitation_grade
 * Description: finds recitation grade.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: recitation_percentage or percentage of the recitation grade.
 * ******************/
float recitation_grade(){
   float quiz_weight = 0;
   float design_weight = 0;
   float critique_weight = 0;
   string start_with;
   int t = 1;
   float percent_quiz;
   float percent_design;
   float percent_critique;
   float recitation_percentage;

   cout<<"What is the quiz weight?"<< endl;
   cin>> quiz_weight;
   cout<< "What is the design weight?"<< endl;
   cin>> design_weight;
   cout<< "What is the critique weight?"<< endl;
   cin>> critique_weight;
   
   while(t == 1){
      cout<< "Would you like to calculate for quiz, design, or critique, or recitation grade?"<<endl;
      cin>> start_with;
      if(start_with == "quiz"){
         percent_quiz = find_the_grade();
	 t = 1;
      }
      else if(start_with == "design"){
         percent_design = find_the_grade();
	 t = 1;
      }
      else if (start_with == "critique"){
         percent_critique = find_the_grade();
	 t = 1;
      }
      else if(start_with == "recitation"){
         recitation_percentage = ((quiz_weight*percent_quiz) + (design_weight*percent_design) + (critique_weight*percent_critique))
	 /(quiz_weight + design_weight + critique_weight);
	 cout<< "Your percent for the quizzes are: "<< percent_quiz<< endl;
	 cout<< "Your percent for the design is: "<< percent_design<< endl;
	 cout<< "Your percent for the critiques are: "<< percent_critique <<endl;
	 cout<< "Your recitation percentage is: "<< recitation_percentage<< "%"<< endl;
	 t = 2;
      }
      else{
	 t = 1;
      }
   }
   return recitation_percentage;
}
