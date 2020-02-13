#include <iostream>

using namespace std;

int main()

{

    int N;

    cin>>N;

    //2438번

    for(int row=1; row<=N; row++)

    {

        for(int col=1; col<=row; col++)

        {

            cout<<"*";

        }

        cout<<"\n";

    }

    //2439번

     for(int row=1; row<=N; row++)

    {

        for(int col=1; col<=N; col++)

        {

            if(col>N-row)

                cout<<"*";

            else

                cout<<" ";

        }

        cout<<"\n";

    }

    //2440번 

    for(int row =1; row<=N; row++)

    {

        for(int col=N-row+1; col>0; col--)

        {

            cout<<"*";

        }

        cout<<"\n";

    }

    //2441번

    for(int row=1; row<=N; row++)

    {

        for(int col=1; col<=N; col++)

        {

            if(col>=row)

                cout<<"*";

            else

                cout<<" ";

        }

        cout<<"\n";

    }

}
