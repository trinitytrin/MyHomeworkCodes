/* Fundamental of Programming Language HOMEWORK#2 PROBLEM#1  */
/* Submitted By: Tanzila Choudhury ; Student ID:P21274808 */

#include<iostream>
#include<stack>
#include<string.h>
#include<sstream>
using namespace std;

int main()
{
    char s[100];
    cout<<"Please enter an arithmetic expression: ";

    cin.get(s,100);

    //cout<<"\nyour input string is: "<<s<<endl;

    string token_table[100];
    string variables[50];
    string numbers[50];
    int tokenc=0;
    int vcount=0;
    int ncount=0;
    int i =0;

    while(i<char_traits<char>::length(s))
    {
        if(s[i]==' '){
            //cout<<"white space\n";
            i++;
        }
        else if(s[i]=='\t'){
            //cout<<"white space tab\n";
            i++;
        }
        else if(s[i]=='+'){
            //cout<<"plus\n";
            token_table[tokenc]="plus";
            tokenc++;
            i++;
        }
        else if(s[i]=='-'){
            //cout<<"minus\n";
            token_table[tokenc]="minus";
            tokenc++;
            i++;
        }
         else if(s[i]=='*'){
            //cout<<"times\n";
            token_table[tokenc]="times";
            tokenc++;
            i++;
         }
         else if(s[i]=='/'){
            //cout<<"divide\n";
            token_table[tokenc]="divide";
            tokenc++;
            i++;
         }
         else if(s[i]==':'){
            //cout<<"kolon\n";
            if(s[i+1]=='='){
                    //cout<<"assign\n";
                    token_table[tokenc]="equals";
                    tokenc++;
                    i=i+2;
            }
            else{
                //cout<<"error\n";
            token_table[tokenc]="ERROR";
            tokenc++;
            i++;
            }
         }
         else if(s[i]=='('){
            //cout<<"lparen\n";
            token_table[tokenc]="lparen";
            tokenc++;
            i++;
         }
        else if(s[i]==')'){
            //cout<<"rparen\n";
            token_table[tokenc]="rparen";
            tokenc++;
            i++;
        }
        else if((s[i]>=97 && s[i]<=122) ||(s[i]>=65 && s[i]<=90) ){
            //cout<<"letter\n";
            variables[vcount]=s[i];
            int varlen=1;
            int j=i+1;
            do{
                    if((s[j]>=97 && s[j]<=122) ||(s[j]>=65 && s[j]<=90) || (s[j]>=48 && s[j]<=57)){
                        //cout<<"more letter or digit\n";
                        variables[vcount]=variables[vcount]+s[j];
                        varlen++;
                        j++;
                    }
                    else
                        goto label1;

            }while(s[j]!= ' ' || s[j] != '\t');

            label1: token_table[tokenc]="variable: ";
            token_table[tokenc]=token_table[tokenc]+variables[vcount];
            tokenc++;
            //cout<<varlen<<endl;
            //cout<<"variable name: "<<variables[vcount]<<endl;
            vcount++;
            i=i+varlen;
        }

        else if(s[i]>=48 && s[i]<=57){
            //cout<<"digit\n";
            numbers[ncount]=s[i];
            int numlen=1;
            int j=i+1;
            do{
                    if(s[j]=='.'){
                        //cout<<"decimal point\n";
                        numbers[ncount]=numbers[ncount]+s[j];
                        numlen++;
                        j++;
                        goto label4;

                    }
                    else if((s[j]>=48 && s[j]<=57)){
                        //cout<<"more letter or digit\n";
                        numbers[ncount]=numbers[ncount]+s[j];
                        numlen++;
                        j++;
                    }
                    else
                        goto label2;

            }while(s[j]!= ' ' || s[j] != '\t');

            label4:do{
                    if((s[j]>=48 && s[j]<=57)){
                        //cout<<"more letter or digit\n";
                        numbers[ncount]=numbers[ncount]+s[j];
                        numlen++;
                        j++;
                    }
                    else
                        goto label2;

            }while(s[j]!= ' ' || s[j] != '\t');

            label2: token_table[tokenc]="number: ";
            token_table[tokenc]=token_table[tokenc]+numbers[ncount];
            tokenc++;
            //cout<<numlen<<endl;
            //cout<<"number: "<<variables[vcount]<<endl;
            ncount++;
            i=i+numlen;
        }

        else if(s[i]=='.'){
            //cout<<"digit\n";
            numbers[ncount]=s[i];
            int numlen=1;
            int j=i+1;
            do{
                    if((s[j]>=48 && s[j]<=57)){
                        //cout<<"more letter or digit\n";
                        numbers[ncount]=numbers[ncount]+s[j];
                        numlen++;
                        j++;
                    }
                    else
                        goto label3;

            }while(s[j]!= ' ' || s[j] != '\t');
            label3: token_table[tokenc]="number: ";
            token_table[tokenc]=token_table[tokenc]+numbers[ncount];
            tokenc++;
            //cout<<numlen<<endl;
            //cout<<"number: "<<variables[vcount]<<endl;
            ncount++;
            i=i+numlen;
        }

        else{
            //cout<<"ERROR\n";
            token_table[tokenc]="ERROR";
            tokenc++;
            i++;
        }
    }

    token_table[tokenc]="EOL";
    tokenc++;

    for (int i=0; i<tokenc; i++){
        //cout<<"token table entry "<<i<<": "<<token_table[i]<<endl;
        cout<<token_table[i]<<endl;
    }


    return 0;
}
