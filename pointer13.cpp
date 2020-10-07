#include<iostream>
#include<iomanip>
#define number_of_course 3


using namespace std;
class Course{
    int course_number;
    float course_gp;
    float course_credits;

public:

    void set_course_information(int Course_number,float Course_gp,float Course_credits){
        this->course_number=Course_number;
        this-> course_gp=Course_gp;
        this-> course_credits=Course_credits;
    }
    float get_course_credits(){
        return course_credits;
    }
      float get_course_gp(){
        return course_gp;
    }

    float get_gp_multiplyby_credits(){
        return get_course_gp()*get_course_credits();
    }
};
class Student{
    Course course[number_of_course];
    int student_id;
    void put_student_id(int Student_id){
        student_id = Student_id;
    }
public:
    void get_student_information();
    void print_student_information();
    int get_student_id(){
        return student_id;
    }
    float get_cgpa(){
        float total_gp = 0.0,total_credits = 0.0;
        for(int i=0;i<number_of_course;i++){
            total_gp += course[i].get_gp_multiplyby_credits();
            total_credits += course[i].get_course_credits();
        }
        return (total_gp+0.0)/total_credits;
    }

};
void Student::get_student_information(){
    int student_id;
    cout<<"Enter Student ID: ";
    cin>>student_id;
    put_student_id(student_id);
    float course_gp,course_credits;
    for(int i=0;i<number_of_course;i++){
        cout<<"Enter Course "<<i+1<<" Grad point: ";
        cin>>course_gp;
        cout<<"Enter course "<<i+1<<" Credits: ";
        cin>>course_credits;
        course[i].set_course_information(i+1,course_gp,course_credits);
    }
}
void Student::print_student_information(){
    cout<<"\nstudent id: "<<get_student_id() ;
    cout<<"\nCgpa: "<<setprecision(3)<<get_cgpa();
}
class Calculate{
public:
    void merit_prossting(Student student[],int number_of_student){
        bool swaped;

        for(int i=0;i<number_of_student;i++){
            swaped = false;
            for(int j=0;j<number_of_student-1-i;j++){
                if(student[j].get_cgpa() < student[j+1].get_cgpa()){

                    swaped = true;
                }
            }if(!swaped) break;
        }
    }

    int search_student(Student student[],int student_id,int number_of_student){
        for(int i=0;i<number_of_student;i++){
            if(student[i].get_student_id() == student_id) return i;
        }return -1;
    }
};
int main(){
    cout<<"Enter the number of Student: ";
    int number_of_student;
    cin>>number_of_student;
    Student student[number_of_student];
    for(int i=0;i<number_of_student;i++){
        student[i].get_student_information();
    }
    Calculate calculate;
    calculate.merit_prossting(student,number_of_student);
    cout <<"\n Student Merit Position are : " ;
    for(int i=0;i<number_of_student;i++){
        cout<<" \n Merit: "<<i+1 ;
        student[i].print_student_information();
        cout<<"\n"<<endl;

    }



    return 0;
}
