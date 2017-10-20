#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;




struct note{

	float data;
	note * next;


};

class listNote{

private:
	note * pt_debut;
	note * pt_fin;
	public:
	listNote(){

		pt_debut=NULL;
		pt_fin=NULL;

	}

	void addEnd(float note_classe){

		note * tmp=new note;
		tmp->data=note_classe;
		tmp->next=NULL;
		if(pt_debut==NULL)
		{
			pt_debut=tmp;
			pt_fin=tmp;
			tmp=NULL;

		}
                else{


			pt_fin->next=tmp;
			pt_fin=tmp;
		}

	}
	void addPosition(int pos,float nb){

		note * tmp=new note();
		note * prev=new note();
		note * curr=new note();
		curr=pt_debut;

		for(int i=1;i<pos;i++){

			prev=curr;
			curr=curr->next;
		}


		tmp->data=nb;
		prev->next=tmp;
		tmp->next=curr;





	}
	void addBegining(float nb){
		note * tmp=new note();
		tmp->data=nb;
		tmp->next=pt_debut;
		pt_debut=tmp;







	}
	void display(){
		note * tmp= new note;
		tmp=pt_debut;
		while(tmp!=NULL){
			cout<<tmp->data<<"\t";
			tmp=tmp->next;

		}


	}

void deleteBegining(){


	note* tmp=new note();
	tmp=pt_debut;
	pt_debut=pt_debut->next;
	delete tmp;



}
void deleteEnd(){


	note* curr=new note();
	note* prev=new note();
	curr=pt_debut;
	while(curr->next!=NULL){


		prev=curr;
		curr=curr->next;
	}
	pt_fin=prev;
	prev->next=NULL;
	delete curr;

}
void deletePos(int pos){
	note* curr=new note();
	note* prev=new note();
	curr=pt_debut;
	while(curr->next!=NULL){


		prev=curr;
		curr=curr->next;
	}

	prev->next=curr->next;


}
};
int main()
{
    listNote obj;
	obj.addEnd(15);
    obj.addEnd(10);
	obj.addEnd(17);
	obj.addEnd(11);
cout<<"\n-----------------------------------------------------------------\n";
cout<<"\n---------------Displaying all item in the list ------------------\n";
cout<<"\n-----------------------------------------------------------------\n";
obj.display();
obj.addPosition(3,13);
cout<<"\n-----------------------------------------------------------------\n";
cout<<"\n------------ add an item to the third rank  --------------\n";
cout<<"\n-----------------------------------------------------------------\n";
obj.display();
obj.deleteBegining();
cout<<"\n-----------------------------------------------------------------\n";
cout<<"\n--------------- Deletting the first item  -----------------\n";
cout<<"\n-----------------------------------------------------------------\n";
obj.display();
obj.deleteEnd();
cout<<"\n-----------------------------------------------------------------\n";
cout<<"\n----------------- Deletting the last item  ----------------------\n";
cout<<"\n-----------------------------------------------------------------\n";
obj.display();

return 0;
}
