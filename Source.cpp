#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Helper;
class Comment;
class Page;
class Users;
class Date;
class Facebook;
class Helper
{
public:
static	bool findstring(char* str,char* strr)//(from, serchkey)
{
	int j=0;
	bool check=0;
	for(int i=0;str[i]!='\0';)
	{
		if(strr[0]==str[i]&&check==0)
		{
			j=0;check=1;
			while(strr[j]!='\0' && check )
			{
				if(strr[j]==str[i])
				{
					check=1;
					i++;
					j++;
				}
				else
				{	
					check=0;
					j++;
				}
			}
		}
		else
		{
				i++;
		}
		//if(check)
		//	return check;
	}
	return check;
}
};
class Object
{
private:
	char* ID;

public:

	Object()
	{
		ID=0;
	}
	Object(const Object & rhs)
	{
		if(rhs.ID==0)
		{
			int len = strlen(rhs.ID)+1;
			ID=new char[len];
			strcpy_s(ID,len,rhs.ID);
		}
		else
			ID=0;
	}
	virtual char* GetName()=0;
	const Object& operator=(const Object& rhs)
	{
		if(&rhs!=this)
		{
			if(rhs.ID!=0)
			{
				if(ID==0)
					{
						int len = strlen(rhs.ID)+1;
		                ID=new char[len];
			            strcpy_s(ID,len,rhs.ID);
				    }
				else if(strlen(ID)==strlen(rhs.ID))
				{
					strcpy_s(ID,strlen(ID)+1,rhs.ID);
				}
				else
				{
					delete [] ID;
                    int len = strlen(rhs.ID)+1;
		            ID=new char[len];
			        strcpy_s(ID,len,rhs.ID);
				}
			}
			else
				ID=rhs.ID;
		}
		return *this;
	}
	~Object()
	{
		if(ID!=0)
		{
			delete[] ID;
		}
	}
	void SetID(char ch[])
	{
		int len = strlen(ch);
		ID = new char[len + 1];
		strcpy_s(ID,len+1,ch);
	}
	char* GetID()
	{
		return ID;
	}
	virtual void PrintListView() = 0;
};
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date()
	{
		day= 0;
		month=0;
		year=0;
	}
	Date(const Date & rhs)
	{
		day=rhs.day;
		month=rhs.month;
		year=rhs.year;
	}
	bool operator==(const Date & rhs)
	{
		if(day==rhs.day && month==rhs.month && year==rhs.year)
			return true;
		else
			return false;
	}
	bool operator<(const Date &rhs)
	{
		if(day==rhs.day-1&& month==rhs.month && year==rhs.year)
			return true;
		else
			return false;
	}
	int getday()
	{
		return day;
	}
	Date(int day1,int month1,int year1)
	{
		day=day1;
		month=month1;
		year=year1;
	}
	~Date()
	{
		
	}
	void PrintDate()
	{
		cout << day << "/" << month << "/" << year ;
	}
	void SetDate(int day1,int month1,int year1)
	{
		day=day1;
		month=month1;
		year=year1;
	}
};
class Comment 
{
private:
	char* Text;
	Object** Id;
	Object** commentedBy;
public:
	Comment()
	{
		Text=0;
		commentedBy=0;
		Id=0;
	}
	void SetText(char* ch)
	{
		int len = strlen(ch)+1;
		Text=new char[len];
		strcpy_s(Text,len,ch);

	}
	void SetId(char * ch)
	{
		if(Id==0)
			Id=new Object* ;
		
	}
	void SetCommentedBy(Object* obj)
	{
		if(commentedBy==0)
		{
			commentedBy=new Object*;
		}
		(*(commentedBy))=obj;
	}
	void PrintComment()
	{
		if(commentedBy!=0)
		{
			cout <<"\t\t\t\t" << (*(commentedBy))->GetName() << " wrote:\" " << Text  << "\""<< endl;
		}
	}
	~Comment()
	{
		if(Text!=0)
		{
			delete[] Text;
		}
		
		if(commentedBy!=0)
		{
			delete [] commentedBy;
		}
	}
};
class Post : public Object
{
private:
	char* Discription;
	int TotalLikesNo;
	int likedByCount;
	Date SharedDate;
	Object** likes;
	Comment** comments;
	int commentCount;

public:
    Date GetDate()
	{
		return SharedDate;
	}
	void SetDate(Date date)
	{
		SharedDate=date;
	}
	Post()
	{
		likedByCount=0;
		commentCount=0;
		TotalLikesNo=0;
		Discription=0;
		likes=0;
		comments=0;
	}
	Post(const Post & rhs)
	{
		//this->SetID(rhs.GetID());
		int len=strlen(rhs.Discription)+1;
		Discription=new char[len];
		strcpy_s(Discription,len,rhs.Discription);
		TotalLikesNo=rhs.TotalLikesNo;
		SharedDate=rhs.SharedDate;
		likes=new Object*[10];
		for(int i=0;i<10;i++)
		{
			if(rhs.likes!=0)
				likes[i]=rhs.likes[i];
			else
				likes[i]=0;
		}

	}
	const Post &operator = ( Post & rhs)
	{
		if(&rhs!=this)
		{
			this->SetID(rhs.GetID());
		int len=strlen(rhs.Discription)+1;
		Discription=new char[len];
		strcpy_s(Discription,len,rhs.Discription);
		TotalLikesNo=rhs.TotalLikesNo;
		SharedDate=rhs.SharedDate;
		likes=new Object*[10];
		for(int i=0;i<10;i++)
		{
			if(rhs.likes!=0)
				likes[i]=rhs.likes[i];
			else
				likes[i]=0;
		}
		}
		return *this;
	}
	char* GetName()
	{
		return Discription;
	}
	void SetDiscription(char* _Discription)
	{
		int len=strlen(_Discription)+1;
		Discription=new char[len];
		strcpy_s(Discription,len,_Discription);
	}
	void PrintListView()
    {
		cout<<"\"" << Discription <<" \"...( ";
		SharedDate.PrintDate() ;
		cout << ")"<<endl;
    }
	void PrintComments()
	{
		if(comments!=0)
		{
			for(int i=0;i<10;i++)
			{
				if(comments[i]!=0)
				{
					comments[i]->PrintComment();
				}
			}
		}
	}
	void SetTotalLikes(int n)
	{
		TotalLikesNo=n;
	}
	void SetPost(int day,int month,int year,char* _PostId,char* _Discription)
	{
		SharedDate.SetDate(day,month,year);
		int len=strlen(_Discription)+1;
		Discription=new char[len];
		strcpy_s(Discription,len,_Discription);
		this->SetID(_PostId);
	}
	void Print()
	{
		this->PrintListView();
		this->PrintComments();
	}
	void SetPostComments(Comment & comment)
	{
		if(commentCount<10)
		{
			if(comments==0)
			{
				comments=new Comment*[10];
				for(int j=0;j<10;j++)
				{
					comments[j]=0;
				}
			}
		
			comments[commentCount]=&comment;
			commentCount++;
		}
		else
		{
			cout << "\nYou have reached maximum comment limit\n";
		}
	}
	void AddComments(Comment& comment)
	{
		if(comments==0)
		{
			comments=new Comment*[10];
			for(int i=0;i<10;i++)
			{
				comments[i]=0;
			}
		}
		comments[commentCount]=&comment;
		commentCount++;
	}
	 void PrintLikedBy()
    {
        if(likes!=0)
        {
            for(int i = 0; i< likedByCount; i++)
            {
				likes[i]->PrintListView ();
            }
        }
		else
		{
			cout << "\nNo Liked By List Available \n";
		}
    }
	void SetLikes(Object * obj)
	{
		if(likes==0)
		{
			likes=new Object*[10];
			for(int j=0;j<10;j++)
			{
				likes[j]=0;
			}
		}
		likes[likedByCount]=obj;
		likedByCount++;
	}
	void AddLikes(Object * obj)
	{
		if(likedByCount<10)
		{
			likes[likedByCount]=obj;
			likedByCount++;
		}
		else
		{
			cout << "\nYou have Excedded Maximum Likes Limit \n";
		}
	}
	~Post()
	{
		if(Discription!=0)
		{
			delete[] Discription;
		}
	  if(likes!=0)
	   { 
		   for(int i=0;i<likedByCount;i++)
		  {
			  delete likes[i];
		  }
	  }
	  if(comments!=0)
	  {
		  for(int i=0;i<commentCount;i++)
		  {
			  delete comments[i];
		  }
	  }
	}
};
class Page : public Object
{
private:
	char* Title;
	int TotalLikes;
	Post** timeline;
	int Posts;
public:
	Page()
	{
		Posts=0;
		Title=0;
		TotalLikes=0;
		timeline=0;
	}
	void SetPage(char* Title1, char* id)
	{
		Object::SetID(id);
		int len = strlen(Title1);
		Title = new char[len + 1];
		strcpy_s(Title,len+1,Title1);
	} 
	char* GetName()
	{
		return Title;
	}
	void SetTimeLine(Post& post)
	{
		if(timeline==0)
		{
			timeline=new Post*[10];
			for(int j=0;j<10;j++)
			{
				timeline[j]=0;
			}
		}
		
		timeline[Posts]=&post;
		Posts++;
	}
	void PrintTimeLine()
	{
		for(int i=0;i<Posts;i++)
		{
			if(timeline[i]!=0)
			{
				cout << "---";
				timeline[i]->Print();
			}
			cout << endl;
		}
	}
	void PrintTimeLine1();
	char* GetTitle()
	{
		return Title;
	}
    void PrintListView ()
	{
		cout << GetID() << " - " << Title << endl ;
	}

		~Page()
	{
		if(Title!=0)
		{
			delete[] Title;
		}

		if(timeline!=0)
		{
			delete[] timeline;
		}
	}

};
class Users : public Object
{
private:
	char* fname;
	char* lname;
	Users** FriendList;
	Page** LikedList;
	Post** TimeLine;
	int Posts;
public:
	Users()
	{
		Posts=0;
		fname=lname=0;
	    FriendList=0;
		LikedList=0;
		TimeLine=0;
	}
	char* GetName()
	{
		char* ch=new char[100];
		int i;
		for( i=0;i<strlen(fname);i++)
		{
			ch[i]=fname[i];
		}
		ch[i]=' ';
		i++;
		int j=0;
		for(;j<strlen(lname)+1;i++,j++)
		{
			ch[i]=lname[j];
		}
		return ch;
	}
	void SetUser(char* fname1,char* lname1,char* id) 
	{
		Object::SetID(id);
		int len = strlen(fname1);
		fname = new char[len + 1];
		strcpy_s(fname,len+1,fname1);
		 len = strlen(lname1);
		lname = new char[len + 1];
		strcpy_s(lname,len+1,lname1);	
	}
	void SharePost(Post & post);
	void ViewHomePage()
	{
		cout << fname << " " << lname << "-Home Page\n\n";
		if(FriendList!=0)
		{
			for(int i=0;i<10;i++)
			{
				if(FriendList[i]!=0)
				{
					FriendList[i]->PrintTimeLine1();
				}
			}
		}
		if(LikedList!=0)
		{
			for(int i=0;i<10;i++)
			{
				if(LikedList[i]!=0)
				{
					LikedList[i]->PrintTimeLine1();
				}
			}
		}
		cout << "\n\n------------------------------------------------------------------------------------------------------\n\n";
	}
	void PrintTimeLine()
	{
		//cout << fname << " " << lname << "-TimeLine\n\n";
		if(TimeLine!=0)
		{
			for(int i=0;i<Posts;i++)
			{
				if(TimeLine[i]!=0)
				{
					cout << "---";
					TimeLine[i]->Print();
				}
				cout << "\n";
			}
			//cout << "\n------------------------------------------------------------------------------------------------------\n";
		}
	}
	void PrintTimeLine1();
	void SetFriends( Users& user, int i)
	{
		if(i==0)
		{
			FriendList=new Users*[10];
			for(int j=0;j<10;j++)
			{
				FriendList[j]=0;
			}
		}
		FriendList[i]=&user;
	}
	void SetPages(Page& page,int i)
	{
		if(i==0)
		{
			LikedList=new Page*[10];
			for(int j=0;j<10;j++)
			{
				LikedList[j]=0;
			}
		}
		LikedList[i]=&page;
	}
	void SetTimeLine(Post& post)
	{
		if(TimeLine==0)
		{
			TimeLine=new Post*[10];
			for(int j=0;j<10;j++)
			{
				TimeLine[j]=0;
			}
		}
		
		TimeLine[Posts]=&post;
		Posts++;
	}
		~Users()
	{
		if(fname!=0)
		{
			delete[] fname;
		}
		if(lname!=0)
		{
			delete[] lname;
		}
		if(FriendList)
			delete[] FriendList;
		if(LikedList)
			delete[] LikedList;
		if(TimeLine)
			delete[] TimeLine;
		
	}
	char* Getlname()
	{
		return lname;
	}
	char* Getfname()
	{
		return fname;
	}
	virtual void PrintListView ()
	{
		cout << GetID()<< " - " << fname << " " << lname << endl ;
	}
	void viewLikedPages()
	{
		cout << "Comand:\tView Liked Pages" << endl;
		cout << "\n----------------------------------------------------------------------------------------------------------\n";
		cout << this->fname << " " << this->lname << "-Liked Pages \n\n\n";
		if(LikedList==0)
		{
			cout <<"\nThere are no liked pages\n";
		}
		else
		{
			for(int i=0;i<10;i++)
		    {
				if(LikedList[i]!=0)
				{
					LikedList[i]->PrintListView() ;
			    }
		    }
		}
		cout << "\n---------------------------------------------------------------------------------------------------------\n";
	}
	void viewFriendList()
	{
		cout << "Comand:\tView Friend List" << endl;
		cout << "\n----------------------------------------------------------------------------------------------------------\n";
		cout << this->fname << " " << this->lname << "-Friend List \n\n\n";
		if(FriendList==0)
		{
			cout <<"\nThere are no Friends currently available\n";
		}
		else
		{
			for(int i=0;i<10;i++)
			{
				if(FriendList[i]!=0)
				{
					FriendList[i]->PrintListView();
			    }
		    }
		}
		cout << "\n---------------------------------------------------------------------------------------------------------\n";
	}
};
class Facebook
{
private:
	Users** user;
	Page** page;
	Post** post;
	Comment** comments;
	Users*  CurrentUser;
	static Date* CurrentDate;

public:
	Facebook()
	{
		user=0;
		page=0;
		CurrentUser=0;
	}
	static Date GetDate()
	{
		return *CurrentDate;
	}
	void loading()
	{
		int TotalUsers;
		char buffer[100];
		char chFriends[20][80];
		char ch;
		ifstream fin ;
		fin.open("Project-SocialNetworkUers.txt");
		fin >> TotalUsers;
	    user=new Users*[TotalUsers];
		fin.getline(buffer,100);
		int i=0;
		while(!fin.eof())
		{
			user[i]= new Users;
			char Id[50];
			char fname[100];
			char lname[100];
			fin >> Id;
			fin >> fname;
			fin >> lname;
			user[i]->SetUser(fname,lname,Id);
			fin.get(ch);
			fin.getline(chFriends[i],80);
			i++;
		}
		fin.close();
		fin.open("Project-SocialNetworkPages.txt");
		i=0;
		int TotalPages=0;
		fin >> TotalPages;
		page=new Page*[TotalPages];
		fin.getline(buffer,100);
		while(!fin.eof())
		{
			page[i]=new Page;
			char Pageid[50];
			char Pagename[200];
			fin >> Pageid;
			fin.getline( Pagename,200);
			page[i]->SetPage(Pagename,Pageid);
			i++;
		}
		fin.close();
		 i=0;
		for(int j=0;j<20;j++)
		{
			i=0;
			int k=0;
			while(chFriends[j][k]!='-')
			{
				char chr[4];
				int l=0;
				while(chFriends[j][k]!='\t')
				{
					chr[l]=chFriends[j][k];
					k++;l++;
				}
				k++;
				chr[l]='\0';
				for(int m=0;m<20;m++)
			    {
					if(!strcmp(chr,user[m]->GetID()))
					{
						user[j]->SetFriends(*user[m],i);
						i++;
						break;
					}
				}
			}
			k=k+3;
			i=0;
				while(chFriends[j][k]!='-')
				{
					char chr[4];
					int l=0;
				while(chFriends[j][k]!='\t')
				{
					chr[l]=chFriends[j][k];
					k++;l++;
				}

				k++;
				chr[l]='\0';
				for(int m=0;m<12;m++)
			    {
					if(!strcmp(chr,page[m]->GetID()))
					{
						user[j]->SetPages(*page[m],i);
						i++;
						break;
					}
				}
				}
		}
		fin.open("Project-SocialNetworkPosts.txt");
		int TotalPosts;
		fin >> TotalPosts;
		for(int j=0;j<8;j++)
		{
			fin.getline(buffer,100);
		}
		post=new Post*[TotalPosts];
		char PostId[20],PostDiscription[100],SharedID[20],LikedId[20];
		int day,month,year;
		i=0;
		int f=0,g=0;
		while(!fin.eof())
		{
			f=0;g=0;
			post[i]=new Post;
			fin >> PostId;
			fin >> day ;fin >> month; fin >> year;
			fin.getline(buffer,100);
			fin.getline(PostDiscription,100);
			post[i]->SetPost(day,month,year,PostId,PostDiscription);
			fin >> SharedID ;
			for(int j=0;j<20;j++)
			{
				if(!strcmp(SharedID,user[j]->GetID()))
				{
					user[j]->SetTimeLine(*post[i]);
					f++;

				}
			}
			f=0;
			for(int j=0;j<12;j++)
			{
				if(!strcmp(SharedID,page[j]->GetID()))
				{
					page[j]->SetTimeLine(*post[i]);
					f++;
	
				}
			}
		    char ch[3]="-1";
			fin >> LikedId;
			f=0;
			while(strcmp(ch,LikedId))
			{
				f=0;
				for(int j=0;j<20;j++)
			{
				if(!strcmp(LikedId,user[j]->GetID()))
				{
					post[i]->SetLikes(user[j]);
					break;
				}
			}
			f=0;
			for(int j=0;j<12;j++)
			{
				if(!strcmp(LikedId,page[j]->GetID()))
				{
					post[i]->SetLikes(page[j]);
					break;
				}
			}
				fin >> LikedId;
			}
			post[i]->SetTotalLikes(g);
			fin.getline(buffer,100);
			fin.getline(buffer,100);
			i++;
		}
		char bufer[150];
		fin.close();
		int TotalComments;
		comments=new Comment*[10];
		fin.open("Project-SocialNetworkComments.txt");
		fin >> TotalComments;
		fin.getline(bufer,150);
		fin.getline(bufer,150);
		fin.getline(bufer,150);
		fin.getline(bufer,150);
		i=0;
		int k=0;
		char commentID[10],Commentedby[10],Text[100];
		while(!fin.eof())
		{
			comments[i]=new Comment;
			fin >> commentID >> PostId >> Commentedby;
			fin.getline( Text,100) ;
			comments[i]->SetId(commentID);
			comments[i]->SetText(Text);
			for(int j=0;j<20;j++)
			{
				if(!strcmp(Commentedby,user[j]->GetID()))
				{
					comments[i]->SetCommentedBy(user[j]);
				}
			}
			for(int j=0;j<12;j++)
			{
				if(!strcmp(Commentedby,page[j]->GetID()))
				{
					comments[i]->SetCommentedBy(page[j]);
				}
			}
			for(int j=0;j<11;j++)
			{
				if(!strcmp(PostId,post[j]->GetID()))
				{
					post[j]->SetPostComments(*comments[i]);
				}
			}
			i++;
		}
		fin.close();
	}
	void SetCurrentUser(char* ch)
	{
		cout << "Command:\tSet current user \"" << ch <<"\"\n"; 
		for(int i=0;i<20;i++)
		{
			if(!strcmp(user[i]->GetID(),ch))
			{
				CurrentUser=user[i];
				cout << user[i]->Getfname() << " " << user[i]->Getlname() << " successfully set as Current User\n\n" ;
				break;
			}
		}
	}
	void SetCurrentDate(int day1,int month1, int year1)
	{
		cout << "\nCommand :\tSet Current System Date " << day1 << " " << month1 << " " << year1 << endl; 
		CurrentDate=new Date;
		CurrentDate->SetDate(day1,month1,year1);
		cout << "System Date :\t" ;
	    CurrentDate->PrintDate() ;
		cout<< "\n\n\n" ; 
	}
	void ViewPostlikedByList(char* ch)
	{
		cout << "\nCommand:\tViewLikedList(" << ch << ")\n";
		cout << "\nPost Liked By :\n";
		for(int i=0;i<11;i++)
		{
			if(!strcmp(ch,post[i]->GetID()))
			{
				post[i]->PrintLikedBy();
			}
		}
		cout << "\n------------------------------------------------------------------------------------------\n";
	}
	void ViewPageTimeline(char * ch)
	{
		cout <<"\nCommnd:\t ViewPage(" << ch << ") \n\n";
		cout << "----------------------------------------------------------------------------------------------\n\n";
		for(int i=0;i<12;i++)
		{
			if(!strcmp(ch,page[i]->GetID()))
			{
				page[i]->PrintTimeLine();
				break;//----------------------//To avoid extra iterations
			}
		}
		cout << "\n--------------------------------------------------------------------------------------------\n\n";
	}
	static int GetCurrentDay()
	{
		return CurrentDate->getday();
	}
	void PrintTimeline()
	{
		cout <<"\nCommnd:\t View Timeline \n\n";
		cout <<"-----------------------------------------------------------------------------------------------------\n\n";
		cout << CurrentUser->GetName() << "-TimeLine "<< "\n\n";
		CurrentUser->PrintTimeLine();
		cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
	}
	void LikePost(char* ch)
	{
		cout << "\nCommand:\tLikePost(" << ch << ")\n";
		for(int i=0;i<11;i++)
		{
			if(!strcmp(ch,post[i]->GetID()))
			{
				post[i]->AddLikes(CurrentUser);
			    break;
			}
		}
	}
	void PostComment(char * ch, char* Text)
	{
		cout << "\nCommand:\tPostComment(" << ch  << "," << Text << ")\n";
		for(int i=0;i<11;i++)
		{
			if(!strcmp(ch,post[i]->GetID()))
			{
				Comment* temp=new Comment;
				temp->SetId("c13");
				temp->SetText(Text);
				temp->SetCommentedBy(CurrentUser);
				post[i]->AddComments(*temp);
				break;

			}
		}
	}
	void ViewPost(char* ch)
	{
		cout << "\nCommand:\tViewPost(" << ch << ")\n\n";
		for(int i=0;i<11;i++)
		{
			if(!strcmp(ch,post[i]->GetID()))
			{
				post[i]->Print();
				break;
			}
		}
		cout << "\n\n----------------------------------------------------------------------------------------------------------\n\n";
	}
	void SharePost(char* ch)
	{
		cout << "\nCommand:\tSharePost(" << ch << ")\n";
		for(int i=0;i<11;i++)
		{
			if(!strcmp(ch,post[i]->GetID()))
			{
				CurrentUser->SharePost(*post[i]);
				break;
			}
		}
	}
	void Search(char* ch)
	{
		cout << "\nCommand:\tSearch(" << ch << ")\n\n";
		int j=0;
		for(int i=0;i<20;i++)
		{
			if(Helper::findstring(user[i]->GetName(),ch))
			{
				if(j==0)
				{
					cout << "Users:\n";
					j++;
				}
				cout  << "---" <<user[i]->GetID() << "-" << user[i]->GetName() << endl;
			}
		}
		j=0;
		for(int i=0;i<11;i++)
		{
			if(Helper::findstring(post[i]->GetName(),ch))
			{
				if(j==0)
				{
					cout << "Posts:\n";
					j++;
				}
				cout << "---" << post[i]->GetID ()<< "- \""  << post[i]->GetName() << "\"\n";
			}
		}
		j=0;
		for(int i=0;i<12;i++)
		{
			if(Helper::findstring(page[i]->GetName(),ch))
			{
				if(j==0)
				{
					cout << "Pages:\n";
					j++;
				}
				cout << "---" << page[i]->GetID() << "-" << page[i]->GetName() << endl;
			}
		}
		cout << "\n\n------------------------------------------------------------------------------------------------------------\n\n";
	}
	void run()
	{
	    SetCurrentUser("u7");
		SetCurrentDate(15,11,2017);
		CurrentUser->viewFriendList();
		CurrentUser->viewLikedPages();

		ViewPostlikedByList("post5");
		PrintTimeline();
		ViewPageTimeline("p1");
		CurrentUser->ViewHomePage();
		LikePost("post5");
		ViewPostlikedByList("post5");
		PostComment("post4","Good Luck for your Result");
		ViewPost("post4");
		PostComment("post8","Thanks for the wishes");
		ViewPost("post8");
		SharePost("post5");
		PrintTimeline();
		Search("Ali");
		Search("Birthday");
	}
	~Facebook()
	{
		for(int i=0;i<20;i++)
		{
			if(user[i]!=0)
			{
				delete user[i];
			}
		}
		delete [] user;

		for(int i=0;i<12;i++)
		{
			if(page[i]!=0)
			{
				delete page[i];
			}
		}
		delete [] page;

	}
	
};
Date *Facebook::CurrentDate=0;
void Users::SharePost(Post & post)
{
		if(Posts<10)
		{
			if(TimeLine==0)
			{
				TimeLine=new Post*[10];
				for(int i=0;i<10;i++)
				{
					TimeLine[i]=0;
				}
			}
			Post* temp=new Post;
			char ch[5]={Posts};
			temp->SetDiscription(post.GetName());temp->SetID(ch);temp->SetDate(Facebook::GetDate()) ;
			TimeLine[Posts]=temp;
			Posts++;
		}
		else
		{
			cout << "\n Maximum Post limit reached \n";
		}
	}
void Users::PrintTimeLine1()
	{
		
		if(TimeLine!=0)
		{
			for(int i=0;i<Posts;i++)
			{
				if(TimeLine[i]!=0 && ( Facebook::GetDate()==TimeLine[i]->GetDate() || TimeLine[i]->GetDate()<Facebook::GetDate()))
				{
					cout << "---";
					cout << GetName() << " Shared ";
					TimeLine[i]->Print();
				}
				cout << "\n";
			}
		}
	}

void Page::PrintTimeLine1()
	{
		for(int i=0;i<Posts;i++)
		{
			if(timeline[i]!=0)
			{
				if(timeline[i]!=0 && ( Facebook::GetDate()==timeline[i]->GetDate() || timeline[i]->GetDate()<Facebook::GetDate()))
				{
					cout << "---";
					cout << GetName() << " shared " ;
					timeline[i]->Print();
				}
			}
			cout << endl;
		}
	}
int main()
{
	Facebook fb;
	fb.loading();
	fb.run();
	system("pause");
	return 0;
}