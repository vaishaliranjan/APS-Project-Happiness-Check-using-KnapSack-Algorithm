/* Ritika 9920103219, Khushi 9920103025, Sampada 9920103020, Vaishali 9920103013*/
#include <bits/stdc++.h>

using namespace std;


class happinessCheck{
	string questions[10];
	string options[6];
	float factor[6];
	float happiness;
	public:
		happinessCheck(){
			happiness=0;
			questions[0]="I feel luck plays an important role in happiness";
			questions[1]="I rarely wake up feeling rested";
			questions[2]="I feel that life is very rewarding";
			questions[3]="I am always committed and involved";
			questions[4]="There is not a gap between what I would like to do and what I have done";
			questions[5]="I feel that I am not especially in control of my life";
			questions[6]="I find it easy to make decisions";
			questions[7]="I have a particular sense of meaning and purpose in my life";
			questions[8]="I am well satisfied about everything in my life";
			questions[9]="I think that my happiness is directly linked to the amount of material possessions and wealth that I have";
			options[0]="1.strongly disagree";
			options[1]="2. moderately disagree";
			options[2]="3.slightly disagree";
			options[3]="4.slightly agree";
			options[4]="5.moderately agree";
			options[5]="6.strongly agree";
			factor[0]=1;
			factor[1]=2;
			factor[2]=4;
			factor[3]=6;
			factor[4]=8;
			factor[5]=9;
		}
		void display(){
			int choice;
			for(int i=0;i<10;i++){
				cout<<questions[i]<<endl;
				for(int j=0;j<6;j++){
					cout<<options[j]<<"\t";
				}
				cout<<endl;
				cin>>choice;
					happiness+=factor[choice-1];
				cout<<endl;
			}
		}
		int result(){
			cout<<"Your happiness score is "<<(happiness)<<" %\n";
			return happiness;
		}

};

vector<int> v;
void printknapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
   int res = K[n][W];


    w = W;
    for (i = n; i > 0 && res > 0; i--) {


        if (res == K[i - 1][w])
            continue;
        else {

            v.push_back(i);
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }


}

int main(){
    string name;
    cout<<"--------------------------------ENTER YOUR NAME : ";
    cin>>name;
    cout<<"---------------------HELLO " <<name<<" LET US CHECK YOUR HAPPINESS LEVEL--------------------------"<<endl;
	happinessCheck f;
	f.display();
    int p=	f.result();
    int sadnessPercentage=100-p;

     int val[] = { 45, 30, 60,30,25 }; //time period this is what we need to maximize as we want to support the person
    int wt[] = { 1,3,2,3,1}; //these are the percentage associated with each advice according to their effectiveness
    int W = floor(sadnessPercentage/10) ;
    int n = 5;
    string str[5]={
	               "** Regular sleep balance needed \n7-8 hours required for being both mentally and physically healthy.\nAvoid junk food.",
                   "** Better your relationships\nTry to stay connected with your loved ones.\nCalling a friend or going for a walk immediately boosts mood",
				   "** Do things that makes you feel good\nDo this once a week for next 2 months.\nDiscover yourself and your passion and take out time for your favourite thing ",
				   "** Eat healthy\nDonot skip meals .\nBoost vitamin B intake ( deficiency can trigger depression) and get that sunlight every day.",
				   "** Excercise daily\nAim for at least 30 minutes of exercise per day\nA 10-minute walk can improve your mood for two hours" };

    printknapSack(W, wt, val, n);
    cout<<"------------------------------------- HERE ARE SOME ADVICES---------------------------------- \n";
    for(int i=0;i<v.size();i++)
    {
    	cout<<str[v[i]-1];
    	cout<<endl;
    	cout<<"*********************************************************************************************************\n";

	}
    cout<<"------------------------------ HOPE YOUR LEVEL OF HAPPINESS WILL INCREASE SOON  ----------------------------------------------\n";

	return 0;
}
