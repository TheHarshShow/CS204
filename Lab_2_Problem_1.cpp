#include<bits/stdc++.h>

using namespace std;

struct node{

	long long x,y;
	struct node *next;


};

struct node *createNode(){

	struct node *start=(struct node*)malloc(sizeof(struct node));

	return start;

}

void AddFirst(struct node **start, long long x, long long y){

	if(*start==NULL){

		*start=createNode();
		(*start)->x=x;
		(*start)->y=y;
		(*start)->next=NULL;

	}

	else{
		struct node *temp=createNode();
		struct node *temp2=createNode();
		temp2=*start;
		temp->x=x;
		temp->y=y;
		temp->next=((*start));

		*start=temp;
		
	}

}

int DelFirst(struct node **start){

	if(*start==NULL){


		return -1;

	} else{

		struct node *temp=createNode();
		temp=*start;
		*start=(*start)->next;
		free(temp);

		return 0;


	}

}

int Del(long long x, long long y, struct node **start){

	if((*start)==NULL)return -1;

	struct node *temp=createNode();
	temp=*start;
	struct node *temp2=createNode();
	temp2=*start;
	long long t=0;

	if(temp->x==x && temp->y==y){

		DelFirst(start);
		return 0;

	}


	while(temp->next != NULL){

		temp2=temp;
		temp=temp->next;

		if(temp->x==x && temp->y==y){t=1;break;}




	}

	if(t==1){

		temp2->next=temp->next;
		free(temp);
		return 0;


	} else{

		return -1;	

	}


}

long long Search(long double d, struct node *start){

	long long t=0;
	struct node *temp=start;
	while(temp!=NULL){


		if(sqrt((long long)temp->x*(long long )temp->x + (long long)temp->y*(long long )temp->y) <= d){

			t++;
			//cout<<"("<<temp->x<<","<<temp->y<<") ";


		}
		temp=temp->next;

	}
	//cout<<endl;

	return t;

}

bool Search(long long x, long long y, struct node *start){

	struct node *temp=start;
	while(temp!=NULL){

		if(temp->x==x && temp->y==y){

			return true;

		}

		temp=temp->next;

	}
	return false;

}

long long length(struct node *start){

	struct node *temp=start;
	long long t=0;

	while(temp!=NULL){

		t++;
		temp=temp->next;

	}

	return t;



}

void print(struct node **start){

	struct node *temp=*start;
	while(temp!=NULL){
		cout<<temp->x<<" "<<temp->y<<endl;
		temp=temp->next;


	}


}

int main(){

	long long q;
	long long t;
	cin>>t;

	struct node *start=NULL;

	while(t--){

		cin>>q;
		if(q==1){

			long long a,b;
			cin>>a>>b;
			AddFirst(&start, a, b);


		} else if(q==2){

			int r=DelFirst(&start);
			if(r)cout<<r<<endl;


		} else if(q==3){

			long long a,b;
			cin>>a>>b;
			int r=Del(a, b, &start);
			if(r)cout<<r<<endl;

		} else if(q==4){

			long double d;
			cin>>d;
			if(Search(d, start))cout<<Search(d, start)<<endl;
			else cout<<-1<<endl;
			
			
		} else if(q==5){



			long long a,b;
			cin>>a>>b;
			if(Search(a, b, start))cout<<"True\n";
			else cout<<"False\n";


		} else if(q==6){

			cout<<length(start)<<endl;
			

		}



	}




}
