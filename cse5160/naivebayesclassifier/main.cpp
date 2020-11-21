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
void calcWind(string[],string[],int);
void calcMagnitude(string[],string[],int);
void calcVisibility(string[],string[],int);




/*
 * 
 */


//Global Variable for Storing Probabilities.
//For Category
    float probXyes,probXno = 0;
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
    float pSignPPYes;//2-1
    float pSignNNYes;//2-2
    float pSignPPNo;//1-1
    float pSignNNNo;//1-2
    
//wind
    float pWindHeadYes;//2-1
    float pWindTailYes;//2-2
    float pWindHeadNo;//1-1
    float pWindTailNo;//1-2
    
//Magnitude
    float pMagLowNo;//1-1
    float pMagMedNo;//1-2
    float pMagStrongNo;//1-3
    float pMagOutRangeNo;//1-4
    float pMagLowYes;//2-1
    float pMagMedYes;//2-2
    float pMagStrongYes;//2-3
    float pMagOutRangeYes;//2-4

//Visibility
    float pVisYesYes;//2-1
    float pVisNoYes;//2-1
    float pVisYesNo;//1-1
    float pVisNoNo;//1-2  
    
    

//Need a Zero Checker for probabilities since we cannot ever get 0. need to add
//additive Smoothing






int main(int argc, char** argv) {
    
    string trainingArray[] = {"2", "*", "*", "*", "*", "*", "2",
                      "1", "2", "*", "*", "*", "*", "1",
                      "1", "1", "2", "*", "*", "*", "1",
                      "1", "1", "1", "*", "*", "*", "1",
                      "1", "1", "3", "2", "2", "*", "1",
                      "1", "*", "*", "*", "*", "4", "1",
                      "2", "1", "4", "*", "*", "1", "1",
                      "2", "1", "4", "*", "*", "2", "1",
    
    
                                                        };
    
      string testSetArray[]={"2", "1", "3", "1", "1", "1", "1"};
/*    string testSetArray[]={"2", "1", "4", "*", "*", "3", "1",
                             "2", "1", "3", "1", "1", "1", "1",
                             "2", "1", "3", "1", "1", "2", "1",
                             "2", "1", "3", "1", "2", "1", "1",
                             "2", "1", "3", "1", "2", "2", "1",
                             "1", "1", "3", "1", "1", "3", "1",
                             "2", "1", "3", "1", "2", "3", "1",
    
    
                                                        };
*/    
    // Class: NOAUTO, AUTO-> 1,2
    // STABILITY: stab, xstab->1,2
    // ERROR: XL,LX,MM,SS-> 1,2,3,4
    // SIGN: PP,NN-> 1,2
    // WIND: HEAD,TAIL->1,2
    // MAGNITUDE: LOW, MEDIUM, STRONG, OUTOFRANGE->1,2,3,4
    // VISIBILITY: YES,NO->1,2
    // * = dont care condition handles missing values by ignoring during probability
    const int MAX_SIZE = 8;
    
    //float probXyes,probXno = 0;//holds are probabilities of the test
    

    
    //training set array
    int len1 = sizeof(trainingArray)/sizeof(trainingArray[0]);
    
    //test set array
    int len2 = sizeof(testSetArray)/sizeof(testSetArray[0]);
    
    cout<<"length of array ->"<<len1<<endl;
    //cout<<"length of array ->"<<len2<<endl;

    string catArr[MAX_SIZE] = {};//array that holds category array
    string stabArr[MAX_SIZE] = {};//arrat that holds stability array
    string errorArr[MAX_SIZE] = {};//array that holds error array
    string signArr[MAX_SIZE] = {};//array that holds sign array
    string windArr[MAX_SIZE] = {};//array that holds wind array
    string magArr[MAX_SIZE] = {};//array that holds magnitude array
    string visArr[MAX_SIZE] = {};//array that holds visibility array
    int incr1,incr2,incr3,incr4,incr5,incr6,incr7 = 0;
    
   
    //splitting the array in half for training set and test set
    for(int i=0;i<len1-1;i++){
        
        if (i == 0 || i==7 || i==14 || i==21 || i==28 || i==35 || i==42 || i==49 
                || i==56){
            cout<<"We are inside the function category"<<endl;
            catArr[incr1] = trainingArray[i];
            
            
            incr1++;
        }
        if (i == 1 || i==8 || i==15 || i==22 || i==29 || i==36 || i==43 || i==50 
                || i==57){
            cout<<"We are inside the function stability"<<endl;
            stabArr[incr2] = trainingArray[i];
            
            
            incr2++;
        }
        if (i == 2 || i==9 || i==16 || i==23 || i==30 || i==37 || i==44 || i==51 
                || i==58){
            cout<<"We are inside the function error"<<endl;
            errorArr[incr3] = trainingArray[i];
            
            
            incr3++;
        }
        if (i == 3 || i==10 || i==17 || i==24 || i==31 || i==38 || i==45 || i==52 
                || i==59){
            cout<<"We are inside the function sign"<<endl;
            signArr[incr4] = trainingArray[i];
            
            
            incr4++;
        }
        if (i == 4 || i==11 || i==18 || i==25 || i==32 || i==39 || i==46 || i==53 
                || i==60){
            cout<<"We are inside the function wind"<<endl;
            windArr[incr5] = trainingArray[i];
            
            
            incr5++;
        }
        if (i == 5 || i==12 || i==19 || i==26 || i==33 || i==40 || i==47 || i==54 
                || i==61){
            cout<<"We are inside the function magnitude"<<endl;
            magArr[incr6] = trainingArray[i];
            
            
            incr6++;
        }
        if (i == 6 || i==13 || i==20 || i==27 || i==34 || i==41 || i==48 || i==55 
                || i==62){
            cout<<"We are inside the function visibility"<<endl;
            visArr[incr7] = trainingArray[i];
            
            
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
    calcWind(catArr,windArr,incr5);
    calcMagnitude(catArr,magArr,incr6);
    calcVisibility(catArr,visArr,incr7);
    


    //doing the test cases.
    for(int j=0;j<len2-1;j++){
    //float probXyes,probXno = 0;
        if(j>=0 && j<=7){
            if(j==1){
                if(testSetArray[j] == "1"){
                    //stab
                    //update probabilities
                    probXyes*=pStabYes;
                    probXno*=pStabNo;
                }
                if(testSetArray[j] == "2"){
                    //xstab
                    probXyes*=pXStabYes;
                    probXno*=pXStabNo;
                }
                   
            }
            if(j==2){
                //error
                //xl,lx,mm,ss
                //error
                if(testSetArray[j] == "1"){
                    //xl
                    //update probabilities
                    probXyes*=pErrorXlYes;
                    probXno*=pErrorXlNo;
                }
                if(testSetArray[j] == "2"){
                    //lx
                    probXyes*=pErrorLxYes;
                    probXno*=pErrorLxNo;
                }
                if(testSetArray[j] == "3"){
                    //mm
                    probXyes*=pErrorMmYes;
                    probXno*=pErrorMmNo;
                }
                if(testSetArray[j] == "4"){
                    //ss
                    probXyes*=pErrorSsYes;
                    probXno*=pErrorSsNo;
                }

                
            }
            if(j==3){
                if(testSetArray[j] == "1"){
                    //PP
                    //update probabilities
                    probXyes*=pSignPPYes;
                    probXno*=pSignPPNo;
                }
                if(testSetArray[j] == "2"){
                    //NN
                    probXyes*=pSignNNYes;
                    probXno*=pSignNNNo;
                }
            }
            if(j==4){
                if(testSetArray[j] == "1"){
                    //PP
                    //update probabilities
                    probXyes*=pWindHeadYes;
                    probXno*=pWindHeadNo;
                }
                if(testSetArray[j] == "2"){
                    //NN
                    probXyes*=pWindTailYes;
                    probXno*=pWindTailNo;
                }
            }
            if(j==5){
                //error
                //xl,lx,mm,ss
                //error
                if(testSetArray[j] == "1"){
                    //xl
                    //update probabilities
                    probXyes*=pMagLowYes;
                    probXno*=pMagLowNo;
                }
                if(testSetArray[j] == "2"){
                    //lx
                    probXyes*=pMagMedYes;
                    probXno*=pMagMedNo;
                }
                if(testSetArray[j] == "3"){
                    //mm
                    probXyes*=pMagStrongYes;
                    probXno*=pMagStrongNo;
                }
                if(testSetArray[j] == "4"){
                    //ss
                    probXyes*=pMagOutRangeYes;
                    probXno*=pMagOutRangeNo;
                }

                
            }
            if(j==6){
                if(testSetArray[j] == "1"){
                    //PP
                    //update probabilities
                    probXyes*=pVisYesYes;
                    probXno*=pVisYesNo;
                }
                if(testSetArray[j] == "2"){
                    //NN
                    probXyes*=pVisNoYes;
                    probXno*=pVisNoNo;
                }
            }
           

        }

        
        
    } 
     
    cout<<"Probability of YES - 2 P(X | Auto): "<<probXyes<<endl;
    cout<<"Probability of NO - 1 P(X | NoAuto): "<<probXno<<endl;
    
    
    return 0;
}

void calcClass(string x[], int length){
    int totalProb = 0;
    float probA = 0;
    float probB = 0;
    float totalAB = 0;
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
    probXno = probA/totalAB;
    probXyes = probB/totalAB;
    totalProb = probA + probB;
    
        cout<<"Probability of A(NOAUTO) "<<probA<<"/"<<totalProb<<" - "<<probXno<<endl;
        cout<<"Probability of B(AUTO) "<<probB<<"/"<<totalProb<<" - "<<probXyes<<endl;
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
    
//additive condition if we have one probability = 0 it messes up the
//algorithm
    if(probAyes == 0 || probByes == 0 || probAno == 0 || probBno == 0){
        probAyes+=1;
        probByes+=1;
        probAno+=1;
        probBno+=1;
        probBtot+=2;
        probAtot+=2;
        
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
        //additive condition if we have one probability = 0 it messes up the
        //algorithm
        if(probAyes == 0 || probByes == 0 || probCyes ==0 || probDyes == 0 ||
        probAno == 0 || probBno == 0 ||probCno == 0 || probDno == 0){
            
            probAyes+=1;
            probByes+=1;
            probCyes+=1;
            probDyes+=1;
            probAno+=1;
            probBno+=1;
            probCno+=1;
            probDno+=1;
            probBtot+=4;
            probAtot+=4;
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
    //additive condition if we have one probability = 0 it messes up the
//algorithm
    if(probAyes == 0 || probByes == 0 || probAno == 0 || probBno == 0){
        probAyes+=1;
        probByes+=1;
        probAno+=1;
        probBno+=1;
        probBtot+=2;
        probAtot+=2;
        
    }

    cout<<"PP / yes - "<<probAyes<<"/"<<probBtot<<endl;// 2-1
    pSignPPYes = probAyes/probBtot;
    
    cout<<"NN / yes - " <<probByes<<"/"<<probBtot<<endl;//2-2
    pSignNNYes = probByes/probBtot;

    cout<<"PP / no - "<<probAno<<"/"<<probAtot<<endl;//1-1
    pSignPPNo = probAno/probAtot;

    cout<<"NN / no - " <<probBno<<"/"<<probAtot<<endl;//1-2   
    pSignNNNo = probBno/probAtot;
    
}

void calcWind(string x[],string y[], int length){
    //category Stability
    
    
    float probAyes = 0;
    float probAno = 0;
    float probAtot = 0;
    
    
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
    //additive condition if we have one probability = 0 it messes up the
//algorithm
    if(probAyes == 0 || probByes == 0 || probAno == 0 || probBno == 0){
        probAyes+=1;
        probByes+=1;
        probAno+=1;
        probBno+=1;
        probBtot+=2;
        probAtot+=2;
        
    }
    

    cout<<"head / yes - "<<probAyes<<"/"<<probBtot<<endl;// 2-1
    pWindHeadYes = probAyes/probBtot;
    
    cout<<"tail / yes - " <<probByes<<"/"<<probBtot<<endl;//2-2
    pWindTailYes = probByes/probBtot;

    cout<<"head / no - "<<probAno<<"/"<<probAtot<<endl;//1-1
    pWindHeadNo = probAno/probAtot;

    cout<<"tail / no - " <<probBno<<"/"<<probAtot<<endl;//1-2   
    pWindTailNo = probBno/probAtot;
    
}

void calcMagnitude(string x[],string y[], int length){
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
    
            //additive condition if we have one probability = 0 it messes up the
        //algorithm
        if(probAyes == 0 || probByes == 0 || probCyes ==0 || probDyes == 0 ||
        probAno == 0 || probBno == 0 ||probCno == 0 || probDno == 0){
        probAyes+=1;
        probByes+=1;
        probCyes+=1;
        probDyes+=1;
        probAno+=1;
        probBno+=1;
        probCno+=1;
        probDno+=1;
        probBtot+=4;
        probAtot+=4;
        
    }
    

    cout<<"mag low / yes - "<<probAyes<<"/"<<probBtot<<endl;// 2-1
    pMagLowYes = probAyes/probBtot;
    
    cout<<"mag med / yes - " <<probByes<<"/"<<probBtot<<endl;//2-2
    pMagMedYes = probByes/probBtot;
    
    cout<<"mag strong / yes - "<<probCyes<<"/"<<probBtot<<endl;// 2-3
    pMagStrongYes = probCyes/probBtot;
    
    cout<<"mag OOR / yes - " <<probDyes<<"/"<<probBtot<<endl;//2-4
    pMagOutRangeYes = probDyes/probBtot;

    cout<<"mag low / no - "<<probAno<<"/"<<probAtot<<endl;//1-1
    pMagLowNo = probAno/probAtot;

    cout<<"mag med / no - " <<probBno<<"/"<<probAtot<<endl;//1-2   
    pMagMedNo = probBno/probAtot;
    
    cout<<"mag strong / no - "<<probCno<<"/"<<probAtot<<endl;//1-3
    pMagStrongNo = probCno/probAtot;

    cout<<"mag OOR / no - " <<probDno<<"/"<<probAtot<<endl;//1-4   
    pMagOutRangeNo = probDno/probAtot;
  
}

void calcVisibility(string x[],string y[], int length){
    //category Stability
    
    
    float probAyes = 0;
    float probAno = 0;
    float probAtot = 0;
    
    
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
    //additive condition if we have one probability = 0 it messes up the
//algorithm
    if(probAyes == 0 || probByes == 0 || probAno == 0 || probBno == 0){
        probAyes+=1;
        probByes+=1;
        probAno+=1;
        probBno+=1;
        probBtot+=2;
        probAtot+=2;
        
    }
 



    cout<<"yes / yes - "<<probAyes<<"/"<<probBtot<<endl;// 2-1
    pVisYesYes = probAyes/probBtot;
    
    cout<<"no / yes - " <<probByes<<"/"<<probBtot<<endl;//2-2
    pVisNoYes = probByes/probBtot;

    cout<<"yes / no - "<<probAno<<"/"<<probAtot<<endl;//1-1
    pVisYesNo = probAno/probAtot;

    cout<<"no / no - " <<probBno<<"/"<<probAtot<<endl;//1-2   
    pVisNoNo = probBno/probAtot;
    
}


