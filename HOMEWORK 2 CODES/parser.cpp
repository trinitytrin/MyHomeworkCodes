#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

static int tokenc;
char token_table[20];

static int tokeni=0;
static int nec=0;

void evalC(void);
void evalB(void);
void evalA(void);
bool evalS(void);

void match(char c){
    if (token_table[tokeni]==c){
        tokeni++;
    }
    else
        //cout << "parsing error! \n";
        return;
}

bool firstofS(char c){
    if(c=='a')
        return true;
    else
        return false;
}

bool firstofA(char c){
    if(c=='a')
        return true;
    else
        return false;
}

bool firstofB(char c){
    if(c=='-' || c=='*')
        return true;
    else
        return false;
}

bool firstofC(char c){
    if(c=='+')
        return true;
    else
        return false;
}

bool followofA(char c){
    if(c=='-' || c=='*')
        return true;
    else
        return false;
}

bool followofB(char c){
    if(c==')' )
        return true;
    else
        return false;
}

bool followofC(char c){
    if(c=='-' || c=='*')
        return true;
    else
        return false;
}

char expect(char c){
    if(c=='-')
        return 'b';
    else if(c=='*')
        return '(';
    else if(c=='+')
        return 'a';
    else if(c=='(')
        return 'a';
}

void evalC(){
    char cc= token_table[tokeni];
    if(firstofC(cc)){
            match(cc);
            //cout<<"\n consumed "<<cc<<endl;
            char nc = token_table[tokeni];

            if (nc==expect(cc)){
                match(nc);
               // cout<<"\n consumed "<<nc<<endl;

                  evalC();
            }

            else{
                cout<<"\n parsing error \n";
                nec++;
                return;
            }
    }

    else if(followofC(cc)){
        return;
    }

    else{
        cout<<"\n parsing error \n";
        nec++;
        return;
    }
}


void evalA(){
    char cc = token_table[tokeni];

    if(firstofA(cc)){
            match(cc);
            //cout<<"\n consumed "<<cc<<endl;
            evalC();
    }

    else{
        cout<<"\n parsing error \n";
        nec++;
        return;
    }

}


void evalB(){

    char cc = token_table[tokeni];

    if(firstofB(cc)){
        match(cc);
        //cout<<"\n consumed "<<cc<<endl;

        char nc = token_table[tokeni];

        if(cc == '-' && nc == expect(cc)){
            match(nc);
            //cout<<"\n consumed "<<nc<<endl;
        }

        else if(cc=='*' && nc==expect(cc)){
            match(nc);
            //cout<<"\n consumed "<<nc<<endl;

            evalA();
            evalB();
        }

        else{
            cout<<"\n parsing error \n";
            nec++;
            return;
        }
    }

    else if(followofB(cc))
    {
        char pc = token_table[tokeni-1];
        if(pc == 'b' || pc ==')'){
            match(cc);
           // cout<<"\n consumed "<<cc<<endl;
        }
        else{
            cout<<"\n parsing error \n";
            nec++;
            return;
        }
    }

    else {
        cout<<"\n parsing error \n";
        nec++;
        return;
    }
}

bool evalS(){
    char cc = token_table[tokeni];

    if(firstofS(cc)){
            if(tokenc<3){
                //cout<<"incorrect syntex! \n";
                return false;
            }

            evalA();
            evalB();

        if(nec==0){
            return true;
        }
        else{
            return false;
        }
    }

    else{
        cout<<"\n parsing error \n";
        return false;
    }
}

void tokenize(char s[])
{
    tokenc=0;

    int i=0;
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
            token_table[tokenc]='+';
            tokenc++;
            i++;
        }
        else if(s[i]=='-'){
            //cout<<"minus\n";
            token_table[tokenc]='-';
            tokenc++;
            i++;
        }
         else if(s[i]=='*'){
            //cout<<"times\n";
            token_table[tokenc]='*';
            tokenc++;
            i++;
         }
         else if(s[i]=='('){
            //cout<<"lparen\n";
            token_table[tokenc]='(';
            tokenc++;
            i++;
         }
        else if(s[i]==')'){
            //cout<<"rparen\n";
            token_table[tokenc]=')';
            tokenc++;
            i++;
        }
        else if(s[i]=='a'){
            //cout<<"lparen\n";
            token_table[tokenc]='a';
            tokenc++;
            i++;
         }
        else if(s[i]=='b'){
            //cout<<"rparen\n";
            token_table[tokenc]='b';
            tokenc++;
            i++;
        }

        else{
            cout<<"ERROR (invalid token)\n";
            return;
        }
    }
}


int main()
{
    char s[100];
    cout<<"Please enter a program: ";

    cin.get(s,100);

    tokenize(s);

    if(evalS()){
        cout<<"Syntactically Correct! \n";
    }

    else{
        cout<<"Incorrect Syntax! \n";
    }

    return 0;
}
