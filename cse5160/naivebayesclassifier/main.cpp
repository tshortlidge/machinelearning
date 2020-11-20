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
void calcStab(string[],string[],int);
void calcError(string[],string[],int);
void calcSign(string[],string[],int);

/*
 * 
 */


//Global Variable for Storing Probabilities.

//for Stability
    float pStabYes;//2-1
    float pStabNo;//1-1
    float pXStabYes;//2-2
    float pXStabNo;//2-1
    
//error
    float pErrorXlNo;//1-1
    float pErrorLxNo;//1-2
    float pErrorMmNo;//1-3
    float pErrorSsNo;//1-4
    float pErrorXlYes;//2-1
    float pErrorLxYes;//2-2
    float pErrorMmYes;//2-3
    float pErrorSsYes;//2-4
    
//sign 
    float pSignPPYes;
    float pSignNNYes;
    float pSignPPNo;
    float pSignNNNo;






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
    // STABILITY: stab, xstab->1,2
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
    calcStab(catArr,stabArr,incr2);
    calcError(catArr,errorArr,incr3);
    calcSign(catArr,signArr,incr4);
    
   cout<< pErrorXlNo<<endl;//1-1
   cout<< pErrorLxNo<<endl;//1-2
   cout<< pErrorMmNo<<endl;//1-3
   cout<< pErrorSsNo<<endl;//1-4
   cout<< pErrorXlYes<<endl;//2-1
   cout<< pErrorLxYes<<endl;//2-2
   cout<< pErrorMmYes<<endl;//2-3
   cout<< pErrorSsYes<<endl;//2-4
    return 0;
}

void calcClass(string x[], int length){
    int totalProb = 0;
    float probA = 0;
    float probB = 0;
    float totalAB = 0;
    float probNO, probYES = 0;
    for(int i=0;i<length;i++){
        cout<<x[i]<<endl;
        if(x[i] == "1"){
            probA++;
            totalAB++;
        }
        if(x[i] == "2"){
            probB++;
            totalAB++;
        }
        

        
    }
    probNO = probA/totalAB;
    probYES = probB/totalAB;
    totalProb = probA + probB;
    
        cout<<"Probability of A(NOAUTO) "<<probA<<"/"<<totalProb<<" - "<<probNO<<endl;
        cout<<"Probability of B(AUTO) "<<probB<<"/"<<totalProb<<" - "<<probYES<<endl;
}
void calcStab(string x[],string y[], int length){
    //category Stability
    
    
    float probAyes = 0;
    float probAno = 0;
    float probAtot = 0;
    
    float noauto = 0;
    
    float probByes = 0;
    float probBno = 0;
    float probBtot = 0;
    
    float autopilot = 0;
    
    for(int i=0;i<length;i++){
        cout<<x[i]<<" - "<<y[i]<<endl;
        
        if(x[i] == "1"){ //noauto - NO for no auto 
            if(y[i]== "1"){ //stab
                probAno++;
                probAtot++;
            }
            if(y[i]== "2"){ //xstab
                probBno++;
                probAtot++;
            }
          noauto++;  
        }
        
        else if(x[i] == "2"){//auto - YES for AUTO
            if(y[i]== "1"){ //stab
                probAyes++;
                probBtot++;
            }
            if(y[i]== "2"){ //xstab
                probByes++;
                probBtot++;
            }
          autopilot++;
        }
        
    }
    cout<<"stab / yes - "<<probAyes<<"/"<<probBtot<<endl;// 2-1
    pStabYes = probAyes/probBtot;
    
    cout<<"Xstab / yes - " <<probByes<<"/"<<probBtot<<endl;//2-2
    pXStabYes = probByes/probBtot;

    cout<<"stab / no - "<<probAno<<"/"<<probAtot<<endl;//1-1
    pStabNo = probAno/probAtot;

    cout<<"Xstab / no - " <<probBno<<"/"<<probAtot<<endl;//1-2   
    pXStabNo = probBno/probAtot;
    
}

void calcError(string x[],string y[], int length){
    //category Stability

    
    float probAtot = 0;//probAtot = NOAUTO
    float probBtot = 0;//probBtot = AUTO
    
    
    float probAyes = 0;
    float probAno = 0;
    
    
    float probByes = 0;
    float probBno = 0;

    
    float probCyes = 0;
    float probCno = 0;
    
    float probDyes = 0;
    float probDno = 0;
    
    
    for(int i=0;i<length;i++){
        cout<<x[i]<<" - "<<y[i]<<endl;
        
        if(x[i] == "1"){ //noauto - NO for no auto 
            if(y[i]== "1"){ //stab
                probAno++;
                probAtot++;
            }
            if(y[i]== "2"){ //xstab
                probBno++;
                probAtot++;
            }
            if(y[i]== "3"){ //stab
                probCno++;
                probAtot++;
            }
            if(y[i]== "4"){ //xstab
                probDno++;
                probAtot++;
            }
        }
        
        else if(x[i] == "2"){//auto - YES for AUTO
            if(y[i]== "1"){ //stab
                probAyes++;
                probBtot++;
            }
            if(y[i]== "2"){ //xstab
                probByes++;
                probBtot++;
            }
           if(y[i]== "3"){ //stab
                probCyes++;
                probBtot++;
            }
            if(y[i]== "4"){ //xstab
                probDyes++;
                probBtot++;
            }
        }
        
    }
        // ERROR: XL,LX,MM,SS-> 1,2,3,4

    cout<<"xl / yes - "<<probAyes<<"/"<<probBtot<<endl;// 2-1
    pErrorXlYes = probAyes/probBtot;
    
    cout<<"lx / yes - " <<probByes<<"/"<<probBtot<<endl;//2-2
    pErrorLxYes = probByes/probBtot;
    
    cout<<"mm / yes - "<<probCyes<<"/"<<probBtot<<endl;// 2-3
    pErrorMmYes = probCyes/probBtot;
    
    cout<<"ss / yes - " <<probDyes<<"/"<<probBtot<<endl;//2-4
    pErrorSsYes = probDyes/probBtot;

    cout<<"xl / no - "<<probAno<<"/"<<probAtot<<endl;//1-1
    pErrorXlNo = probAno/probAtot;

    cout<<"lx / no - " <<probBno<<"/"<<probAtot<<endl;//1-2   
    pErrorLxNo = probBno/probAtot;
    
        cout<<"mm / no - "<<probCno<<"/"<<probAtot<<endl;//1-3
    pErrorMmNo = probCno/probAtot;

    cout<<"ss / no - " <<probDno<<"/"<<probAtot<<endl;//1-4   
    pErrorSsNo = probDno/probAtot;
    
}
void calcSign(string x[],string y[], int length){
    //category Stability
    
    
    float probAyes = 0;
    float probAno = 0;
    float probAtot = 0;
    
    float noauto = 0;
    
    float probByes = 0;
    float probBno = 0;
    float probBtot = 0;
    
    
    for(int i=0;i<length;i++){
        cout<<x[i]<<" - "<<y[i]<<endl;
        
        if(x[i] == "1"){ //noauto - NO for no auto 
            if(y[i]== "1"){ //stab
                probAno++;
                probAtot++;
            }
            if(y[i]== "2"){ //xstab
                probBno++;
                probAtot++;
            }
        }
        
        else if(x[i] == "2"){//auto - YES for AUTO
            if(y[i]== "1"){ //stab
                probAyes++;
                probBtot++;
            }
            if(y[i]== "2"){ //xstab
                probByes++;
                probBtot++;
            }
        }
        
    }
        float pSignPPYes;
    float pSignNNYes;
    float pSignPPNo;
    float pSignNNNo;
    cout<<"PP / yes - "<<probAyes<<"/"<<probBtot<<endl;// 2-1
    pSignPPYes = probAyes/probBtot;
    
    cout<<"NN / yes - " <<probByes<<"/"<<probBtot<<endl;//2-2
    pSignNNYes = probByes/probBtot;

    cout<<"PP / no - "<<probAno<<"/"<<probAtot<<endl;//1-1
    pSignPPNo = probAno/probAtot;

    cout<<"NN / no - " <<probBno<<"/"<<probAtot<<endl;//1-2   
    pSignNNNo = probBno/probAtot;
    
}

