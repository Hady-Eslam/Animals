#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

struct Indix{
	char key[15];
	long long ofset;
};

vector<Indix>indix;
vector<long long>avail_list;
long count_record;
long number_of_records;


class Animal{
public :
	char name[15],picture[50],environment[20],food_picture[60],type[15],Predatory[13],bring_up[12],Endangered[14];
	
	void Adding_animal(){
			
		cout<<endl<<endl
		<<"enter the name = ";
		cin>>name;
		cout<<"__________"
			<<endl<<"enter the picture = ";
		cin>>picture;
		cout<<"__________"
			<<endl<<"enter the environment = ";
		cin>>environment;
		cout<<"__________"
			<<endl<<"enter the food picture path = ";
		cin>>food_picture;
		cout<<"__________"
			<<endl<<"enter the type = ";
		cin>>type;
		cout<<"__________"
			<<endl<<"enter the Predatory = ";
		cin>>Predatory;
		cout<<"__________"
			<<endl<<"enter the bring up = ";
		cin>>bring_up;
		cout<<"__________"
			<<endl<<"enter the Endangered = ";
		cin>>Endangered;
	}

	void set_data(){
		
		//cout<<endl<<"`````````````````````````````````"<<endl
		//	<<" name = "<<name<<endl
		//	<<"   *"<<endl
		//	<<"   *"<<endl/*
		//	<<" picture = "<<picture<<endl
		//	<<"   *"<<endl
		//	<<"   *"<<endl*/
		//	<<" environment = "<<environment<<endl
		//	<<"   *"<<endl
		//	<<"   *"<<endl/*
		//	<<" food_picture = "<<food_picture<<endl
		//	<<"   *"<<endl
		//	<<"   *"<<endl*/
		//	<<" type = "<<type<<endl
		//	<<"   *"<<endl
		//	<<"   *"<<endl
		//	<<" Predatory = "<<Predatory<<endl
		//	<<"   *"<<endl
		//	<<"   *"<<endl
		//	<<" bring_up = "<<bring_up<<endl
		//	<<"   *"<<endl
		//	<<"   *"<<endl
		//	<<" Endangered = "<<Endangered<<endl<<endl
		//	<<"```````````````````````````````````````"<<endl<<endl;

		fstream file("cv.hta",ios::out);
		stringstream s;
		s <<"<h3>"<<name
		  <<"<h3/>"<<"<img src=\""<<picture<<"\"/>"
		  <<"<h3>"<<"environment"
		  <<"<h3>"<<environment
		  <<"<h3>"<<"<img src=\""<<food_picture<<"\"/>"
		  <<"<h3>"<<" Tybe"
		  <<"<h3>"<<type
		  <<"<h3>"<<Predatory
		  <<"<h3>"<<"  Predatory"
		  <<"<h3>"<<bring_up
		  <<"<h3>"<<"  bring_up"
		  <<"<h3>"<<Endangered
		  <<"<h3>"<<"  Endangered";
		
		file<<s.str().c_str();
		file.close();
		system("cv.hta");
	}

	char * pack (char delim ,int & pack_length){
		stringstream str;
		str<<name;
		int l=15-strlen(name);
		for (int i=0;i<l;i++)
			str<<".";
		str<<delim<<picture;
		l=50-strlen(picture);
		for (int i=0;i<l;i++)
			str<<".";
		str<<delim<<environment;
		l=20-strlen(environment);
		for (int i=0;i<l;i++)
			str<<".";
		str<<delim<<food_picture;
		l=60-strlen(food_picture);
		for (int i=0;i<l;i++)
			str<<".";
		str<<delim<<type;
		l=15-strlen(type);
		for (int i=0;i<l;i++)
			str<<".";
		str<<delim<<Predatory;
		l=13-strlen(Predatory);
		for (int i=0;i<l;i++)
			str<<".";
		str<<delim<<bring_up;
		l=12-strlen(bring_up);
		for (int i=0;i<l;i++)
			str<<".";
		str<<delim<<Endangered;
		l=14-strlen(Endangered);
		for (int i=0;i<l;i++)
			str<<".";
		pack_length = strlen( str.str().c_str());
		char * data =new char [pack_length];
		strcpy(data,str.str().c_str());
		return data ;
	}

	void unpack(char delim,char * packed_record){
		stringstream str;
		str<<packed_record;
		str.getline(name,15,'.');
		str.ignore(15-strlen(name));
		str.getline(picture,50,'.');
		str.ignore(50-strlen(picture));
		str.getline(environment,20,'.');
		str.ignore(20-strlen(environment));
		str.getline(food_picture,60,'.');
		str.ignore(60-strlen(food_picture));
		str.getline(type,15,'.');
		str.ignore(15-strlen(type));
		str.getline(Predatory,13,'.');
		str.ignore(13-strlen(Predatory));
		str.getline(bring_up,12,'.');
		str.ignore(12-strlen(bring_up));
		str.getline(Endangered,14,'.');
		str.ignore(14-strlen(Endangered)-1);
	}

	/*void get_data(){
		cin>>name>>picture>>environment>>food_picture>>type>>Predatory>>bring_up>>Endangered;
		
	}
	
	void print_data(char * name){

	}*/
};


//ostream&operator<<(ostream&out,Animal s){
//	int actual_obj_length;
//	char * packet =s.pack('|',actual_obj_length);
//	out.write(packet,actual_obj_length);
//	return out;
//}

ostream&operator<<(ostream & out,Animal &s){
	out.write((char *)&s,sizeof(s));
	return out;
}

istream&operator>>(istream&in,Animal &s){
	in.read((char *)&s,sizeof(s));
	return in;
}

ostream&operator<<(ostream & out,Indix &s){
	out.write((char *)&s,sizeof(s));
	return out;
}

istream&operator>>(istream&in,Indix &s){
	in.read((char *)&s,sizeof(s));
	return in;
}



void Sort_Indix(){

	vector<Indix >::iterator i;
	vector<Indix >::iterator j;

	for (i=indix.begin();i!=indix.end();i++)

		for (j=i+1;j!=indix.end();j++)

			if ((i->ofset)>(j->ofset))
				
				swap(*i,*j);

}

void open_indix(){

	Indix item;
	vector<Indix>::iterator i;
	fstream indix_file("indix.txt",ios::out|ios::in);
	
	indix_file.seekg(0);
	
	while(indix_file>>item){
		indix.push_back(item);
	}

	count_record=indix.size();
	
	Sort_Indix();
	indix_file.close();

}

void load_indix(char *old_name,char *new_name,long long ofset){

	Indix item;
	vector<Indix>::iterator x;
	bool stop=0;

	if (ofset>-1){

		strcpy(item.key,old_name);
		item.ofset=ofset;
		indix.push_back(item);
	}
	else if (ofset<=-1){

		for (x=indix.begin();x!=indix.end();x++){
			
			if (strlen(old_name)==strlen(x->key)){
				int count=0;
				for (int j=0;j<strlen(old_name);j++){
					
					if (old_name[j]==x->key[j])
						count++;
				}
				if (ofset==-1){
					if (count==strlen(old_name)){
						strcpy(x->key,new_name);
						stop=1;
					}
				}
				else if (ofset==-2)
					if (count==strlen(old_name))
						indix.erase(x),stop=1;
			}
			if (stop==1)
				break;
		}
	}

	Sort_Indix();
	
}

//istream&operator>>(istream&in,Animal &s){
//	char * rawdata =new char [sizeof(s)];
//	in.read(rawdata,sizeof(s));
//	s.unpack('|',rawdata);
//	return in;
//}




//istream&operator>>(istream&in,Indix & s){
//	char * rawdata =new char [sizeof(s)];
//	in.read(rawdata,sizeof(s));
//	stringstream str;
//	str<<rawdata;
//	str.getline(s.key,15,'.');
//	str.ignore(15-strlen(s.key));
//	str>>s.ofset;
//	str.ignore(1);
//	return in;
//}


//ostream&operator<<(ostream&out,Indix s){
//	int actual_obj_length;
//	stringstream str;
//	str<<s.key;
//	for (int i=0;i<15-strlen(s.key);i++)
//		str<<".";
//	str<<"="<<s.ofset<<"|";
//	char * data =new char [strlen( str.str().c_str())];
//	strcpy(data,str.str().c_str());
//	out.write(data,strlen(data));
//	return out;
//}

void save_indix(){

	Indix item;
	vector<Indix>::iterator i;
	fstream indix_file("indix.txt",ios::out|ios::in|ios::trunc);
	
	Sort_Indix();

	for (i=indix.begin();i!=indix.end();i++)
		indix_file<<*i;

	indix_file.close();
}


void Open_Avail_List(){

	long i;
	fstream f("Avail_list and number of records.txt",ios::in|ios::out);

	f>>number_of_records;

	while(f>>i){
		avail_list.push_back(i);
	}

}

void Sort_Avail_List(){

	vector<long long >::iterator i;
	vector<long long >::iterator j;

	for (i=avail_list.begin();i!=avail_list.end();i++)

		for (j=i+1;j!=avail_list.end();j++)

			if (*i>*j)
				
				swap(*i,*j);


}

void Load_Avail_List(long long offset){

	avail_list.push_back(offset);
	Sort_Avail_List();

}

void Save_Avail_List(bool SR){

	vector<long long>::iterator i;
	fstream f("Avail_list and number of records.txt",ios::in|ios::out|ios::trunc);

	f<<number_of_records;
	Sort_Avail_List();

	if (SR==0)
		for (i=avail_list.begin();i!=avail_list.end();i++){
			f<<*i;
		}

	f.close();
}



bool Break_Loob(int num){
	
	char chose;

	do{
		cout<<"*******"<<endl;

		if (num==1)
			cout<<"If you want to Add Record again Enter y for yes and Enter n for no"<<endl;
		else if (num==2)
			cout<<"If you want to Update Record again Enter y for yes and Enter n for no"<<endl;
		else if (num==3)
			cout<<"If you want to Revave Record again Enter y for yes and Enter n for no"<<endl;
		else if (num==4)
		cout<<"If you want to Search for Record again Enter y for yes and Enter n for no"<<endl;

		cin>>chose;
		cout<<"*******"<<endl;
			
		if (chose=='y'||chose=='Y');
		else if (chose=='n'||chose=='N');
		else
			cout<<"----"<<endl
			<<"enter y for yes and enter n for no"<<endl
			<<"-----"<<endl;

		}while(chose!='y'&&chose!='Y'&&chose!='n'&&chose!='N');
	
	if (chose=='Y'||chose=='y')
		return 1;
	else if (chose=='N'||chose=='n')
		return 0;

}

void Add_Animal(){
	
	fstream f("Animals.txt",ios::in|ios::out);
	Animal s;
	bool stop=1;
	char chose;

	while(stop){

		vector<long long>::iterator i;
		i=avail_list.begin();

		if (avail_list.size()!=0)
			f.seekp(*i),avail_list.erase(i);
		else
			f.seekp(0,ios::end),number_of_records++;

		s.Adding_animal();
		f<<s;
		count_record++;

		load_indix(s.name,"1",(long long)f.tellg()-199);
		stop=Break_Loob(1);

		cout<<endl<<endl;
	}

	f.close();
}

long long search_Animal(char * word){
	
	int count=0;
	int x=strlen(word);
	vector<Indix>::iterator i;
	fstream f("Animals.txt",ios::in|ios::out);
	
	for (i=indix.begin();i!=indix.end();i++){
		
		for (int j=0;j<x;j++){
			if (x==strlen(i->key))
				if (word[j]==i->key[j])
					count++;
		}
		if (count==x){
			
			f.close();
			return i->ofset;
		}
	}
	f.close();

	return -1;
}

void Update_Menu(){

	cout<<"enter 1 to update the name"<<endl<<endl
		<<"enter 2 to update the pass of the picture"<<endl<<endl
		<<"enter 3 to update the environment"<<endl<<endl
		<<"enter 4 to update the pass of the food picture"<<endl<<endl
		<<"enter 5 to update the tybe"<<endl<<endl
		<<"enter 6 to update the predatory"<<endl<<endl
		<<"enter 7 to update the bring up"<<endl<<endl
		<<"enter 8 to update the endangered"<<endl<<endl;
}

void Enter_Update(Animal &s,char *word){

	char num;

	cin>>num;
	if (num=='1')
		cout<<"enter the name to Update = ",strcpy(word,s.name),cin>>s.name,cout<<endl;
	else if (num=='2')
		cout<<"enter the path of the Picture to Update = ",cin>>s.picture,cout<<endl;
	else if (num=='3')
		cout<<"enter the environment to Update = ",cin>>s.environment,cout<<endl;
	else if (num=='4')
		cout<<"enter the path of food Picture to Update = ",cin>>s.food_picture,cout<<endl;
	else if (num=='5')
		cout<<"enter the tybe of the Animal to Update = ",cin>>s.type,cout<<endl;
	else if (num=='6')
		cout<<"write the word predatory if the animal is predatory and not predatory if the Animal is not predatory to Update = ",cin>>s.Predatory,cout<<endl;
	else if (num=='7')
		cout<<"write the word bring up if the animal is bring up and not bring up if the Animal is not bring up to Update = ",cin>>s.bring_up,cout<<endl;
	else if (num=='8')
		cout<<"write the word endangered if the animal is endangered and not endangered if the Animal is not endangered to Update = ",cin>>s.Endangered,cout<<endl;

}

void Update_information(){
	
	char stop=1;
	
	while (stop){
	
		Animal s;
		char word[15];
		fstream f("Animals.txt",ios::in|ios::out);

		cout<<endl
			<<"enter the name of Animal that you want to Update :::: "<<endl<<endl;
		cin>>word;

		long long offset=search_Animal(word);

		if (offset==-1)
			cout<<endl<<"*******not found*********"<<endl<<endl;
		else{
			cout<<endl;

			f.seekg(offset);
			f>>s;

			s.set_data();
			Update_Menu();
			Enter_Update(s,word);
			
			f.seekp(offset);
			f<<s;
			f.close();

			load_indix(word,s.name,-1);

		}
		stop=Break_Loob(2);
	}

}

void Search(){
	
	bool stop=1;

	while(stop){
	
		char word[15];
		bool coun=0;
		Animal s;
		vector<Indix>::iterator i;
		fstream f("Animals.txt",ios::in|ios::out);
		
		cout<<"enter the name of Animal that you want to search ::::"<<endl;
		cin>>word;

		int x=strlen(word);
		f.seekg(0,ios::beg);

		for (i=indix.begin();i!=indix.end();i++){
		
			int count=0;
			if (x<=strlen(i->key)){
				
				for (int j=0;j<x;j++){
					if (word[j]==i->key[j])
						count++;
				}
				if (count==x){
					f.seekg(i->ofset),coun=1;
					f>>s,s.set_data();
				}
			}
		}

		f.close();
		
		if (coun==0)
			cout<<"******** not found*********"<<endl;
		
		stop=Break_Loob(4);
	}
}

void Delete_record(){

	bool stop=1;

	while(stop){
	
		fstream f("Animals.txt",ios::in|ios::out);
		Animal s;
		char word[15];

		cout<<endl<<"enter the name of Animal that you want to Delete :::: "<<endl<<endl;
		cin>>word;
	
		long long offset = search_Animal(word);
	
		if (offset==-1)
			cout<<"********** not found *************"<<endl;
		else{
			cout<<endl;
			
			f.seekg(offset);
			f>>s;
			f.seekp(offset);
			f<<"*";
			f.close();
			
			load_indix(word,"1",-2);
			Load_Avail_List(offset);
			
			if (count_record>0)
				count_record--;
		}

		stop=Break_Loob(3);
	}
}

void Show_All_Records(){

	vector<Indix>::iterator i;
	fstream f("Animals.txt",ios::in|ios::out);
	Animal s;

	for (i=indix.begin();i!=indix.end();i++){
		
		f.seekg(i->ofset);
		f>>s;
		s.set_data();

	}
	f.close();
}

void List_Victms(){

	cout<<"enter number 1 if you want which eats meat"<<endl
		<<"enter number 2 if you want which eats grass"<<endl
		<<"enter number 3 if you want which eats corn"<<endl
		<<"enter number 4 if you want which eats small fish"<<endl
		<<"enter number 5 if you want which eats bones"<<endl;

	int num;
	cin>>num;
	if (num==1)
		cout<<"lions  and  leopard   and   tigers   and   crocodiles   and   big snaks"<<endl<<endl;
	else if (num==2)
		cout<<"chicken  and rabbits  and  sheep  and cow  and duck  tortoise"<<endl<<endl;
	else if (num==3)
		cout<<"dove  and  sparrow  and  ostrich"<<endl<<endl;
	else if (num==4)
		cout<<"cats  and  duck  and penguin"<<endl<<endl;
	else if (num==5)
		cout<<"dog"<<endl<<endl;
}


bool Space_Reclaming(){

	if (number_of_records/2>count_record){

		vector<Indix>::iterator i;
		Animal s[100];
		fstream f("Animals.txt",ios::in|ios::out);
		
		f.seekg(0);
		int j=0;
		i=indix.begin();

		for (;i!=indix.end();i++,j++){
			
			f.seekg(i->ofset);
			f>>s[j];
		}
		f.close();

		i=indix.begin();

		fstream z("Animals.txt",ios::in|ios::out|ios::trunc);
		z.seekp(0);
		
		for (int k=0;k<j;k++,i++){
			
			z<<s[k];
			i->ofset=long long(z.tellp())-199;
			cout<<"i->ofset<<endl;"<<i->ofset<<endl;
		}
		number_of_records=j;
		z.close();
		return 1;
	}
	return 0;
}




void Menu_List(){

	cout<<"***************  Menu Options  *****************"<<endl
		<<"________________________________________________"<<endl
		<<"Press 1 for Adding a new animal into the encyclopedia"<<endl
		<<"                      |||"<<endl
		<<"press 2 for updating an animal information"<<endl
		<<"                      |||"<<endl
		<<"press 3 for removing an animal from encyclopedia"<<endl
		<<"                      |||"<<endl
		<<"press 4 for serching for an animal by name or part of the name"<<endl
		<<"                      |||"<<endl
		<<"press 5 for listing all the animal which have specific victims"<<endl
		<<"                      |||"<<endl
		<<"press 6 To show all records in the file"<<endl
		<<"                      |||"<<endl
		<<"press 7 for exit the program"<<endl
		<<"________________________________________________"<<endl<<endl;

}

int main()
{
	char num;
	bool SR;

	open_indix();
	Open_Avail_List();

	for (;;){

		Menu_List();

		cin>>num;
		if (num=='1')
			Add_Animal();
		else if (num=='2')
			Update_information();
		else if (num=='3')
			Delete_record();
		else if (num=='4')
			Search ();
		else if (num=='5')
			List_Victms();
		else if (num=='6')
			Show_All_Records();
		else if (num=='7')
			break;
		else cout<<"you should enter number from 1 to 7 if you want"<<endl<<endl;
	}

	SR=Space_Reclaming();
	save_indix();
	Save_Avail_List(SR);

	return 0;
}
