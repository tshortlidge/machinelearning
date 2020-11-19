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
    
    // * = dont care condition
    // Class: NOAUTO, AUTO 1,2
    // ERROR: XL,LX,MM,SS
    // SIGN: PP,NN
    // WIND: HEAD,TAIL
    // MAGNITUDE: LOW, MEDIUM, STRONG, OUTOFRANGE
    // VISIBILITY: YES,NO
    //
    int len1 = sizeof(array)/sizeof(array[0]);
    string catArray[12] ={};
    int incr = 0;
    for(int i=0;i<len1;i++){
        
        if (i == 0 || i==7 || i==14 || i==21 || i==28 || i==35 || i==42 || i==49 
                || i==56){
            cout<<"We are inside the function"<<endl;
            catArray[incr] = array[i];
            
            if(catArray[incr] == "1"){
                cout<<"No auto"<<endl;
                
            }else{
                cout<<"Autopilot"<<endl;
            }
            incr++;
        }
      
    }
        for(int i=0;i<len1;i++){
            cout<<"Reading array[]"<<endl;
            cout<<array[i]<<endl;
        }
        for(int i=0;i<incr;i++){
            cout<<"Reading catArray[]"<<endl;
            cout<<catArray[i]<<endl;
        }
    
    calcClass(catArray,incr);
    
    return 0;
}

void calcClass(string cat[], int lengthOfCat){
    int data1 = 0;
    int data2 = 0;
    int totalData = 0;
    int lengthOfArray=sizeof(cat)/sizeof(cat[0]);
    for(int i=0;i<lengthOfCat;i++){
        
        if(cat[i] == "1"){
            data1++;
            totalData++;
        }
        if(cat[i] == "2"){
            data2++;
            totalData++;
        }
        else if(cat[i]=="*"){
            totalData++;
        }

        
    }
        cout<<"Data1 "<<data1<<endl;
        cout<<"Data2 "<<data2<<endl;
        cout<<"Total Data "<<totalData<<endl;
}



