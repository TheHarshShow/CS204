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

		return 1;


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


	while(temp!=NULL){

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

void Search(long double d, struct node *start){

	struct node *temp=start;
	while(temp!=NULL){


		if(sqrt((long long)temp->x*(long long )temp->x + (long long)temp->y*(long long )temp->y) <= d){

			cout<<"("<<temp->x<<","<<temp->y<<") ";


		}
		temp=temp->next;

	}
	cout<<endl;

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

			DelFirst(&start);

		} else if(q==3){

			long long a,b;
			cin>>a>>b;
			Del(a, b, &start);


		} else if(q==4){

			long double d;
			cin>>d;
			Search(d, start);
			
			
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
