/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Trevor Shortlidge
 * CSE: 5160 Machine Learning NAIVE BAYES Alg. 
 *
 * Created on November 18, 2020, 2:00 PM
 */
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;
void calcClass(string[],int);
void stabClass(string[], int);


/*
 * 
 */
int main(int argc, char** argv) {
    
    string array[] = {"2", "*", "*", "*", "*", "*", "2",
                      "1", "2", "*", "*", "*", "*", "1",
                      "1", "1", "2", "*", "*", "*", "1",
                      "1", "1", "1", "*", "*", "*", "1",
                      "1", "1", "3", "2", "2", "*", "1",
                      "1", "*", "*", "*", "*", "4", "1",
                      "2", "1", "4", "*", "*", "1", "1",
                      "2", "1", "4", "*", "*", "2", "1",
    
    
                                                        };
    
    // Class: NOAUTO, AUTO-> 1,2
    //STABILITY: stab, xstab->1,2
    // ERROR: XL,LX,MM,SS-> 1,2,3,4
    // SIGN: PP,NN-> 1,2
    // WIND: HEAD,TAIL->1,2
    // MAGNITUDE: LOW, MEDIUM, STRONG, OUTOFRANGE->1,2,3,4
    // VISIBILITY: YES,NO->1,2
    // * = dont care condition handles missing values by ignoring during probability
    const int MAX_SIZE = 8;
    int len1 = sizeof(array)/sizeof(array[0]);
    cout<<"length of array ->"<<len1<<endl;
    string catArr[MAX_SIZE] = {};//array that holds category array
    string stabArr[MAX_SIZE] = {};//arrat that holds stability array
    string errorArr[MAX_SIZE] = {};//array that holds error array
    string signArr[MAX_SIZE] = {};//array that holds sign array
    string windArr[MAX_SIZE] = {};//array that holds wind array
    string magArr[MAX_SIZE] = {};//array that holds magnitude array
    string visArr[MAX_SIZE] = {};//array that holds visibility array
    int incr1,incr2,incr3,incr4,incr5,incr6,incr7 = 0;
    for(int i=0;i<len1-1;i++){
        
        if (i == 0 || i==7 || i==14 || i==21 || i==28 || i==35 || i==42 || i==49 
                || i==56){
            cout<<"We are inside the function category"<<endl;
            catArr[incr1] = array[i];
            
            
            incr1++;
        }
        if (i == 1 || i==8 || i==15 || i==22 || i==29 || i==36 || i==43 || i==50 
                || i==57){
            cout<<"We are inside the function stability"<<endl;
            stabArr[incr2] = array[i];
            
            
            incr2++;
        }
        if (i == 2 || i==9 || i==16 || i==23 || i==30 || i==37 || i==44 || i==51 
                || i==58){
            cout<<"We are inside the function error"<<endl;
            errorArr[incr3] = array[i];
            
            
            incr3++;
        }
        if (i == 3 || i==10 || i==17 || i==24 || i==31 || i==38 || i==45 || i==52 
                || i==59){
            cout<<"We are inside the function sign"<<endl;
            signArr[incr4] = array[i];
            
            
            incr4++;
        }
        if (i == 4 || i==11 || i==18 || i==25 || i==32 || i==39 || i==46 || i==53 
                || i==60){
            cout<<"We are inside the function wind"<<endl;
            windArr[incr5] = array[i];
            
            
            incr5++;
        }
        if (i == 5 || i==12 || i==19 || i==26 || i==33 || i==40 || i==47 || i==54 
                || i==61){
            cout<<"We are inside the function magnitude"<<endl;
            magArr[incr6] = array[i];
            
            
            incr6++;
        }
        if (i == 6 || i==13 || i==20 || i==27 || i==34 || i==41 || i==48 || i==55 
                || i==62){
            cout<<"We are inside the function visibility"<<endl;
            visArr[incr7] = array[i];
            
            
            incr7++;
        }

    }
    /*
        for(int i=0;i<len1;i++){
            cout<<"Reading array[]"<<endl;
            cout<<array[i]<<endl;
        }
        for(int i=0;i<incr;i++){
            cout<<"Reading catArray[]"<<endl;
            cout<<catArray[i]<<endl;
        }
    */
    calcClass(catArr,incr1);
    stabClass(stabArr,incr2);
    
    return 0;
}

void calcClass(string x[], int length){
    
    float probA = 0;
    float probB = 0;
    float totalAB = 0;
    for(int i=0;i<length-1;i++){
        cout<<x[i]<<endl;
        if(x[i] == "1"){
            probA++;
            totalAB++;
        }
        if(x[i] == "2"){
            probB++;
            totalAB++;
        }
        else if(x[i]=="*"){
            cout<<"ERROR"<<endl;
            cout<<x[i];
        }

        
    }
    probA = probA/totalAB;
    probB = probB/totalAB;
        cout<<"Probability of A(NOAUTO) "<<probA<<endl;
        cout<<"Probability of B(AUTO) "<<probB<<endl;
}
void stabClass(string x[], int length){
    
    float probA = 0;
    float probB = 0;
    float probC = 0; //dont care condition
    float totalAB = 0;
    for(int i=0;i<length-1;i++){
        cout<<x[i]<<endl;
        if(x[i] == "1"){
            probA++;
            totalAB++;
        }
        if(x[i] == "2"){
            probB++;
            totalAB++;
        }
        else if(x[i]=="*"){
            probC++;
            totalAB++;
        }

        
    }
    probA = probA/totalAB;
    probB = probB/totalAB;
        cout<<"Probability of A(stab) "<<probA<<endl;
        cout<<"Probability of B(xstab) "<<probB<<endl;
}



