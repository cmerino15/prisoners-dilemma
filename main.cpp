# include <iostream>
# include <iomanip>
# include <string>
# include <cmath>
# include <windows.h>
# include <cstdlib>
# include <ctime>

using namespace std;

int main()
{

	char rosemovenot = ' ', colinmovenot = ' ', playagain;
	string colinstrategyname;

	int rosemove , colinmove , colinstrategy, rosetotal=0, colintotal=0, runs=0, choice;
	unsigned seed = time(0); // get's the system time
	srand(seed); // seeds the random number generator

	HANDLE hConsole;
	hConsole =GetStdHandle(STD_OUTPUT_HANDLE);



	cout<<"\n\n You have been caught robbing a bank!\n\n Your accomplice and you are taken into custody by the police department.\n\n"
		<<" You have a brief second together and your accomplice tells you \n\n to stick with the story pre-agreed upon.\n\n"
		<<" The chief of police separates the two of you. \n\n While apart, he offers you the choice to rat your partner out ( Defect )\n\n"
		<<" or to stick with your story ( Cooperate ).\n\n Oh, one more thing!\n\n The chief of police has offered the same deal to your 'Friend'\n\n"
		<<" The possible outcomes are outlined as follows...\n\n";

	SetConsoleTextAttribute(hConsole,8+4*16);

	cout<<"\n\n\t\tGAME THEORY: THE PRISONER'S DILEMMA\t\t\n\n";

	SetConsoleTextAttribute(hConsole,8+4*16);

	cout<<endl
		<<"\t                                            \t\t\n"
		<<"\t                      Colin                 \t\t\n"
		<<"\t                                            \t\t\n"
		<<"\t         Prison   |  Defect  | Cooperate    \t\t\n"
		<<"\t      ------------------------------------  \t\t\n"
		<<"\t  R    Defect     |  ( 2, 2) | ( 0, 3)      \t\t\n"
		<<"\t  o   ------------|-----------------------  \t\t\n"
		<<"\t  s    Cooperate  |  ( 3, 0) | ( 1, 1)      \t\t\n"
		<<"\t  e               |          |              \t\t\n"
		<<"\t                                            \t\t\n\n\n\n";

	SetConsoleTextAttribute(hConsole,8);


	do
	{

		cout<<"How many runs? ";
		cin>>runs;

		colinstrategy= rand()%3;
		if (colinstrategy == 0)
		{
			colinstrategyname = "Random";
		}
		else if ( colinstrategy == 1 )
		{
			colinstrategyname = "Always Defect";
		}
		else if (colinstrategy == 2)
		{
			colinstrategyname ="Always Cooperate";
		}	



		cout<<"\n\nChoose 1 to play Manually,\n\nChoose 2 to Automatically play Defect,\n"
			<<"\nor Choose 3 to Automatically play Cooperate.\n\n...Choose...\n\n";
		cin>>choice;   // chooose how to play the runs
		

		for (int n=0; n<=runs; n++)
		{
			system("cls");

			SetConsoleTextAttribute(hConsole,8+4*16);

			cout<<"\n\n\t\tGAME THEORY: THE PRISONER'S DILEMMA\t\t\n\n";

			SetConsoleTextAttribute(hConsole,8+4*16);

		cout<<endl
			<<"\t                                            \t\t\n"
			<<"\t                      Colin                 \t\t\n"
			<<"\t                                            \t\t\n"
			<<"\t         Prison   |  Defect  | Cooperate    \t\t\n"
			<<"\t      ------------------------------------  \t\t\n"
			<<"\t  R    Defect     |  ( 2, 2) | ( 0, 3)      \t\t\n"
			<<"\t  o   ------------|-----------------------  \t\t\n"
			<<"\t  s    Cooperate  |  ( 3, 0) | ( 1, 1)      \t\t\n"
			<<"\t  e               |          |              \t\t\n"
			<<"\t                                            \t\t\n\n\n\n";

		SetConsoleTextAttribute(hConsole,8);

		cout<<"Run:   "<<n<<endl<<endl<<endl;

		cout<<"Rose's move: "<<rosemovenot<<"\t Colin's move: "<<colinmovenot<<endl<<endl<<endl<<endl;

		cout<<"Total Years in Prison: Rose "<<rosetotal<<"\t Colin "<<colintotal<<endl<<endl<<endl<<endl;

		cout<<"Please choose a move to play (as Rose): D (Defect) or C (Cooperate)\n\n\n\n";

		//This is the loop for rose's move

		if (choice == 1)
		{
			cin>>rosemovenot;
		}
		else if (choice == 2)
		{
			rosemovenot = 'd';
		}
		else if (choice == 3)
		{
			rosemovenot = 'c';
		}

		if ( (rosemovenot == 'd') || (rosemovenot == 'D'))
	
		{
			rosemove = 0;
			rosemovenot = 'D';
		}
	
		else
		{
			rosemove = 1;
			rosemovenot = 'C';
		}
	
		if (colinstrategy == 0)
		{
			colinmove = rand()%2;  // This is where rand numb generator sets colin's move if want set then set (do not randomize)
		}
		else if (colinstrategy ==1)
		{
			colinmove =0;

		}
		else if (colinstrategy == 2)
		{
			colinmove =1;
		}

		if (colinmove == 1)
		{
			colinmovenot = 'C';
		}
	
		else if (colinmove == 0)
		{
			colinmovenot = 'D';
		}
		
		if ((rosemove == 1) && (colinmove == 1) )
		{
			rosetotal+=1;
			colintotal+=1;
		}
		else if ((rosemove == 0) && (colinmove == 0))
		{
			rosetotal+=2;
			colintotal+=2;
		}
		else if ((rosemove == 0) && (colinmove == 1))
		{
			rosetotal+=0;
			colintotal+=3;
		}
		else
		{
			rosetotal+=3;
			colintotal+=0;
		}

		}

		cout<<"\n\nColin's Strategy:\t"<<colinstrategyname<<endl<<endl;

		cout<<"Would you like to play again? Choose Y or N:\t";
		cin>>playagain;

		system ( "cls" );
		rosetotal = 0;
		colintotal = 0;

		}
		while ( ( playagain == 'Y') || ( playagain == 'y'));

		return (0);
}



