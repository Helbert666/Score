#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

string trim(string);

struct student
{	
	string name;
	string sex;
	double score;
};

int main()
{
	string line;
	int studentnumber=0;
	int currentnumber=0;
	int malenumber=0;
	int femalenumber=0;
	string a,b,c;
	double sum_of_all=0;
	double sum_of_male=0;
	double sum_of_female=0;

	ifstream fin;
	fin.open("score.csv");
	if(!fin.is_open())
	{
		cout<<"The file cannot open."<<endl;
		return 1;
	}
	getline(fin,line);
	while(getline(fin,line))
	{
		studentnumber++;
	}
	fin.close();
	fin.open("score.csv");
	if(!fin.is_open())
	{
		cout<<"The file is not exist"<<endl;
		return 1;
	}
	student students[studentnumber];
	getline(fin,line);
	while(getline(fin,line))
	{
		stringstream ss(line);
		getline(ss,a,',');
		students[currentnumber].name=trim(a);
		getline(ss,b,',');
		students[currentnumber].sex=trim(b);
		getline(ss,c,',');
		students[currentnumber].score=stof(trim(c));
		currentnumber++;
	}
	for(int i=0;i<studentnumber;i++)
	{
		sum_of_all+=students[i].score;
		if(students[i].sex[0]== 'F')
		{
			sum_of_female+=students[i].score;
			femalenumber++;
		}
		else
		{
			sum_of_male+=students[i].score;
			malenumber++;
		}
	}

	for(int i=1;i<studentnumber;i++)
	{
		student temp;
		for(int j=i;j>=0;j--)
		{
			if(students[j].score<students[j-1].score)
			{
				temp=students[j-1];
				students[j-1]=students[j];
				students[j]=temp;
			}
			else
			{
				if(students[j].score==students[j-1].score&&students[j].name<students[j-1].name)
				{
					temp=students[j-1];
					students[j-1]=students[j];
					students[j]=temp;
				}
				else
				{
					break;
				}
			}
		}
	
}
	cout<<"Average of all students: "<<sum_of_all/studentnumber<<endl;
	cout<<"Average of all boys: "<<sum_of_male/malenumber<<endl;
	cout<<"Average of all girls: "<<sum_of_female/femalenumber<<endl;
	cout<<"The ranking of all students is: "<<endl;
	for(int i=0;i<studentnumber;i++)
	{
		cout<<students[i].name<<" "<<students[i].sex<<" "<<students[i].score<<endl;
	}
	
	return 0;
}

string trim(string n)
{
	int length=n.size();
	int begin=0;
	int end=0;
	for(int i=0;i<length;i++)
	{
		if(n[i]!=' ')
		{
			begin=i;
			break;
		}
	}
	for(int i=length;i>=0;i--)
	{
		if(n[i]!=' ')
		{
			end=i;
			break;
		}
	}
	string temp(&n[begin],&n[end+1]);
	return temp;
}











































































