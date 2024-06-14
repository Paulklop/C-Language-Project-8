////////////////////////////////////////////////////////////////////////////////
//
//  File Name  : Program8.c
//
//  Programmer : Paul Klopfenstein
//
//  Instructor : Jonathan Ormiston
//
//  Course     : ECET 264
//
//  Date Due   : December 3, 2021
//
//  Platform   : IBM PC (Windows 10)
//
//  Compiler   : Microsoft Visual C++ 16
//
////////////////////////////////////////////////////////////////////////////////

// Eliminate deprecation warnings for the older, less secure functions
// Needed for Microsoft Visual Studio 2005 (MSVC++ version 8) or later
#define _CRT_SECURE_NO_DEPRECATE

// Compiler Includes
#include <stdio.h>
#include <string.h>

// Using Directives & Declarations

// Project Includes 

// Constants
#define MAX_STRING_LENGTH 81
#define AMOUNT_OF_VEICHELES_IN_LIST 4 


// User Defined Types
typedef struct {
    char Month[MAX_STRING_LENGTH];
    char Day[MAX_STRING_LENGTH];
    char Year[MAX_STRING_LENGTH];
}DATE_TYPE;

typedef struct {
    double Gallons;
    double level;
 
}TANK_TYPE;

typedef struct {
    char   Make[MAX_STRING_LENGTH];
    char   Model[MAX_STRING_LENGTH];
    int    Odometer;
    DATE_TYPE Manufactured;
    DATE_TYPE Purchased;
    TANK_TYPE fuelTank;
    
} AUTO_TYPE;

// Function Prototypes 
void PrintAuto(AUTO_TYPE autoToPrint);
int ScanAuto(AUTO_TYPE* inputAuto,FILE* FileHandle);
void PrintDate(DATE_TYPE dateToPrint);
int ScanDate(DATE_TYPE* inputDate, FILE* FileHandle);
void PrintTank(TANK_TYPE tankToPrint);
int ScanTank(TANK_TYPE* inputTank, FILE* FileHandle);

//////////////////////////////////////////////////////////////////////////////// 
// 
//  Function Name : main 
// 
//  Originated    : December 3, 2021 
// 
//  Abstract      : Introduction to user defined data types (UDDTs)
// 
//  Parameters    : None
// 
//  Return Value  : error code - zero means program terminated without errors
// 
//  Misc. I/O     : na
// 
//  Revisions     :  
// 
//////////////////////////////////////////////////////////////////////////////// 

int main(void) {

    // Local Variables
    AUTO_TYPE Automoblie1 = {0};
    DATE_TYPE Manufactured = {0};
    DATE_TYPE Purchased = {0};
    TANK_TYPE Capacity ={ 0.0 };
    TANK_TYPE Level = { 0.0 }; 
    int y = 0;
    int x = 0; 

    
    
    char FileName[MAX_STRING_LENGTH] = { 0 };
    FILE* FileHandle = NULL;
    char currentChar = '\0';
    // Begin

    printf("Enter File Name:");
    scanf("%s", FileName);
    FileHandle = fopen(FileName, "r");
     
    if (FileHandle != NULL) {
       for(x=AMOUNT_OF_VEICHELES_IN_LIST-2;x>=EOF;x--)
        {
            y = ScanAuto(&Automoblie1, FileHandle);
            PrintAuto(Automoblie1);
        }
    }// end if file opened
    else {
        printf("The File Didn't Open");
    }// end if file did not open

       
    
          
      
    return 0;

} // end function main

//////////////////////////////////////////////////////////////////////////////// 
// 
//  Function Name : PrintAuto 
// 
//  Originated    : Decmeber 3, 2021 
// 
//  Abstract      : Print AUTO_TYPE to the terminal screen
// 
//  Parameters    : autoToPrint
// 
//  Return Value  : None
// 
//  Misc. I/O     : na
// 
//  Revisions     :  
// 
//////////////////////////////////////////////////////////////////////////////// 

void PrintAuto(AUTO_TYPE autoToPrint) {

    // Local Variables

    // Begin 
    printf("================================================================\n");
    printf("Make: %s    Model: %s     Odometer: %d\n", autoToPrint.Make,
        autoToPrint.Model, autoToPrint.Odometer);
    printf("----------------------------------------------------------------\n");

    printf("Manufactured on: ");
    PrintDate(autoToPrint.Manufactured);

    printf("Purchased on: ");
    PrintDate(autoToPrint.Purchased);
    printf("\n");
    printf("Fuel capacity is ");
    PrintTank(autoToPrint.fuelTank);
    printf("================================================================\n");
    
        
} // end function PrintAuto


//////////////////////////////////////////////////////////////////////////////// 
// 
//  Function Name : PrintTank 
// 
//  Originated    : Decmeber 4, 2021 
// 
//  Abstract      : Print TANK_TYPE to the terminal screen
// 
//  Parameters    : tankToPrint
// 
//  Return Value  : None
// 
//  Misc. I/O     : na
// 
//  Revisions     :  
// 
//////////////////////////////////////////////////////////////////////////////// 

void PrintTank(TANK_TYPE tankToPrint) {

    // Local Variables
    double level = ((tankToPrint.level / tankToPrint.Gallons) * 100);

    // Begin 
    printf("%.1lf gallons   ", tankToPrint.Gallons);

    printf("Current level is %.1lf %%\n",level);
         
     

} // end function PrintTank
//////////////////////////////////////////////////////////////////////////////// 
// 
//  Function Name : PrintDate 
// 
//  Originated    : Decmeber 3, 2021 
// 
//  Abstract      : Print DATE_TYPE to the terminal screen
// 
//  Parameters    : dateToPrint
// 
//  Return Value  : None
// 
//  Misc. I/O     : na
// 
//  Revisions     :  
// 
//////////////////////////////////////////////////////////////////////////////// 

void PrintDate(DATE_TYPE dateToPrint) {

    // Local Variables
    // Begin 
    switch (*dateToPrint.Month) {
    case '1':
        printf("January");
        break;
    case '2':
        printf("Feburay");
        break;
    case '3':
        printf("March");
        break;
    case '4':
        printf("Apirl");
        break;
    case '5':
        printf("May");
        break;
    case '6':
        printf("June");
        break;
    case '7':
        printf("July");
        break;
    case '8':
        printf("August");
        break;
    case '9':
        printf("September");
        break;
    case '10':
        printf("October");
        break;
    case '11':
        printf("November");
        break;
    case '12':
        printf("December");
        break;
    }

    printf( " %s, %s    ", dateToPrint.Day, dateToPrint.Year);
    
} // end function PrintDate
//////////////////////////////////////////////////////////////////////////////// 
// 
//  Function Name : ScanAuto
// 
//  Originated    : December 3, 2021 
// 
//  Abstract      : Scan AUTO_TYPE from keyboard input (using reference)
// 
//  Parameters    : *inputAuto
// 
//  Return Value  : None
// 
//  Misc. I/O     : na
// 
//  Revisions     :  
// 
//////////////////////////////////////////////////////////////////////////////// 

int ScanAuto(AUTO_TYPE* inputAuto,FILE* FileHandle) {

    // Local Variables
    int EndOfFileResult=0 ; 
    
    // Begin

    
    
        
       
         EndOfFileResult=fscanf(FileHandle, "%s", &(*inputAuto).Make);
         EndOfFileResult=fscanf(FileHandle, "%s", &(*inputAuto).Model);
         EndOfFileResult=fscanf(FileHandle, "%d", &inputAuto->Odometer);

           EndOfFileResult= ScanDate(&(*inputAuto).Manufactured, FileHandle);

           EndOfFileResult=  ScanDate(&inputAuto->Purchased, FileHandle);

           EndOfFileResult=  ScanTank(&inputAuto->fuelTank, FileHandle);

           
        
    
    
    return EndOfFileResult; 

} // end function ScanAuto
//////////////////////////////////////////////////////////////////////////////// 
// 
//  Function Name : ScanTank
// 
//  Originated    : December 4, 2021 
// 
//  Abstract      : Scan TANK_TYPE from keyboard input (using reference)
// 
//  Parameters    : *inputTank
// 
//  Return Value  : None
// 
//  Misc. I/O     : na
// 
//  Revisions     :  
// 
//////////////////////////////////////////////////////////////////////////////// 
    int ScanTank(TANK_TYPE * inputTank, FILE * FileHandle) {

        // Local Variables
        int EndOfFileResult=0; 

        // Begin

         EndOfFileResult = fscanf(FileHandle, "%lf", &inputTank->Gallons);
         EndOfFileResult = fscanf(FileHandle, "%lf", &inputTank->level);
         return EndOfFileResult; 


    }
    
//////////////////////////////////////////////////////////////////////////////// 
// 
//  Function Name : ScanDate
// 
//  Originated    : December 3, 2021 
// 
//  Abstract      : Scan DATE_TYPE from keyboard input (using reference)
// 
//  Parameters    : *inputDate
// 
//  Return Value  : None
// 
//  Misc. I/O     : na
// 
//  Revisions     :  
// 
//////////////////////////////////////////////////////////////////////////////// 

int ScanDate(DATE_TYPE* inputDate,FILE* FileHandle) {

    // Local Variables
    int EndOfFileResult=0; 
    // Begin
    
        EndOfFileResult= fscanf(FileHandle,"%s", inputDate->Month);


        EndOfFileResult= fscanf(FileHandle,"%s", inputDate->Day);


       EndOfFileResult=  fscanf(FileHandle,"%s", &inputDate->Year);
       return EndOfFileResult;
     
} // end function ScanDate


// end file Program8.c
