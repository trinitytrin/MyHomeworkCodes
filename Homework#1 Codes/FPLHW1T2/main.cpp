#include <iostream>


using namespace std;


void findpair(int a[], int limit, int target)
{
    cout <<"in the function\n";

    for(int i=0; i<limit; i++){
            //cout<<a[i]<<" ";

            for(int j=i+1; j<limit; j++ ){
                    if((a[i]+a[j])==target){
                        cout<<"Matched Pair \("<<a[i]<<", "<<a[j]<<"\)"<<" Index: \("<<i<<", "<<j<<"\)"<<endl;
                    }

            }


    }



}

int main()
{
   // cout << "Hello world!" << endl;

    int target;

    cout<<"target number? : ";
    cin >> target;

    int a[50];

    cout<<"";

    cout<<"please input the numbers of array: \n";

    int i=0;


    cout << "Input positive numbers (between 0 to 100)or 'x' to stop: \n";

    while ( true )
    {
        int input;

        if ( !( cin >> input ) ) break;
        if(input<0 || input>100){
            cout<<"invalid input! please enter number between 0 to 100\n";
        }

        else
        {
            a[i]=input;
            i++;
        }

    }

    int total_input=i;

    //int arraysize = sizeof(a)/sizeof(int);
    //cout<<"size of the array is: "<<arraysize<<endl;



    /*for(int j=0; j<total_input ; j++)
    {
        cout<<a[j]<<endl;

    }*/

    findpair(a, total_input, target);



    return 0;
}
