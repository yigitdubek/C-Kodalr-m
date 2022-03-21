#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

float convertToDecimal(int numberLength,char inputArray[], int inputBi);
int calculatedPositivepow(char inputArray[],int numberLength);
void converToRequestedBase(float decimal ,int outputBi,char *outPutNumber );

int main(){
    int select,inputBi,outputBi;
    char *outPutNumber;
    outPutNumber = (char *) malloc( (100) );
    float decimal,y;
    int inputLength,x;
    char number[100];
    printf("Please enter the number N to be converted: ");     scanf("%s",number);
    inputLength=strlen(number);
    printf("Please enter the input base (the base of the number to be converted): "); scanf("%d",&inputBi);
    printf("\n Please enter the output base (the base into which the number is to be converted): ");   scanf("%d",&outputBi);
    decimal=convertToDecimal(inputLength,number,inputBi);
   if (number[0]=='-')
    {
        outPutNumber[0]='-';
    }
    converToRequestedBase(decimal,outputBi,&outPutNumber[0]);
}
void converToRequestedBase(float rational ,int outputBi,char *outPutNumber )
    {
        double fractional,fRemainder=0,holdFractional;
        int decimalPoint,*arrayDecimalPoint,*arrayFractional,i=0,j=0,remainder,holder;
        arrayDecimalPoint = (int *) malloc( (100) );
        arrayFractional = (int *) malloc( (100) );
        
        decimalPoint=rational;
        fractional=rational-decimalPoint;
        holdFractional=fractional;

        while (1)
        {   
            remainder=decimalPoint%outputBi;
            arrayDecimalPoint[i]=remainder;
            decimalPoint=decimalPoint/outputBi;
            i++;
                if (decimalPoint==0)
            {
                break;
            }
        }
        while (1)
        {
            fRemainder=fractional*outputBi;
            remainder=fRemainder;
            fractional=fRemainder-remainder;
            arrayFractional[j]=remainder;
            if (fRemainder==0.0)
            {
                break;
            }
            
            j++;
            if (fractional==0.0)
            {
              break;
            }
        }
        
        for (int a = 0; a < i; a++)
        {
            if (outPutNumber[0]=='-')
            {
           
                holder=i-a;
            }
            else
            {
                holder=i-a-1;
            }
             switch (arrayDecimalPoint[a])
            {
            case 0:
                outPutNumber[holder]='0';
                break;
            case 1:
                outPutNumber[holder]='1';
                break; 
            case 2:
                outPutNumber[holder]='2';
                break;
             case 3:
                outPutNumber[holder]='3';
                break;
             case 4:
                outPutNumber[holder]='4';
                break;
             case 5:
                outPutNumber[holder]='5';
                break;
             case 6:
                outPutNumber[holder]='6';
                break;
             case 7:
                outPutNumber[holder]='7';
                break;
             case 8:
                outPutNumber[holder]='8';
                break;
             case 9:
                outPutNumber[holder]='9';
                break;
             case 10:
                outPutNumber[holder]='A';
                break;
             case 11:
                outPutNumber[holder]='B';
                break;
             case 12:
                outPutNumber[holder]='C';
                break;
             case 13:
                outPutNumber[holder]='D';
                break;
             case 14:
                outPutNumber[holder]='E';
                break;
             case 15:
                outPutNumber[holder]='F';
                break;                                          
            default:
                break;
            }
        } 
       
        

        if (holdFractional!=0.000000)
    {
            if (outPutNumber[0]=='-')
            {
                i++;
                outPutNumber[i]='.';
                i++;
            }
            else{
                outPutNumber[i]='.';
                i++;
            }
        
        for ( int a=0; a <j; a++,i++) 
         {
             switch (arrayFractional[a])
            {
            case 0:
                outPutNumber[i]='0';
                break;
            case 1:
                outPutNumber[i]='1';
                break; 
            case 2:
                outPutNumber[i]='2';
                break;
             case 3:
                outPutNumber[i]='3';
                break;
             case 4:
                outPutNumber[i]='4';
                break;
             case 5:
                outPutNumber[i]='5';
                break;
             case 6:
                outPutNumber[i]='6';
                break;
             case 7:
                outPutNumber[i]='7';
                break;
             case 8:
                outPutNumber[i]='8';
                break;
             case 9:
                outPutNumber[i]='9';
                break;
             case 10:
                outPutNumber[i]='A';
                break;
             case 11:
                outPutNumber[i]='B';
                break;
             case 12:
                outPutNumber[i]='C';
                break;
             case 13:
                outPutNumber[i]='D';
                break;
             case 14:
                outPutNumber[i]='E';
                break;
             case 15:
                outPutNumber[i]='F';
                break;                                          
            default:
                break;
            }
        } 
    }   
        for (int a = 0; a < i; a++)
         {
             printf("%c",outPutNumber[a]);
         }
        printf("\n");
}
float convertToDecimal(int numberLength, char inputArray [],int inputBi)
{
    char asciLetter;
    char asciStartLetter='0';
    float sum=0;
    int j;
    int negativePow=-1;
    int positivePow=calculatedPositivepow(inputArray,numberLength);
    
        for ( int i=0; i < numberLength; i++)
        {  
             asciLetter=inputArray[i]; 
             
            if (inputArray[i]=='-')
            {
                    continue;
            }
           if ( inputArray[i]=='.')
            {
               continue;
            }
            
            if (asciLetter<'G' && asciLetter>'@')
            {
            sum=sum+(asciLetter-asciStartLetter-7)*pow(inputBi,positivePow); 
            positivePow--;
            continue;
            }
            sum=sum+(asciLetter-asciStartLetter)*pow(inputBi,positivePow);
            positivePow--;
        }
        return sum;   
} 
int calculatedPositivepow(char inputArray[],int numberLength)
{
    int pow=0;
    for (int i=0 ; i < numberLength; i++)
    {
        if(inputArray[i]=='.'){
            pow=pow+i-1;
            break;
        }
        if (inputArray[i]=='-')
        {
            pow=pow-1;
        }
        if (i==numberLength-1)
        {
            pow=pow+i;
        }
}
 return pow;
}
       



