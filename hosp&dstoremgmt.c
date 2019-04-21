#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()

{  
	int ans=1,ch,chP,slexno=0,stockno_count=0,chM,ansP=1,ansM=1,step=0,l=0;
	char str[25][25],tempchar[25];
    struct Patientslist
    {
   	 int slno;
   	 char Patientname[50];
   	 char Patientailment[20];
     struct Patientslist *front , *prev;
    }*head;
     head = NULL;
     struct Medicinelist
     {
   	  int stockno;
   	  char Medicinename[50];
      struct Medicinelist *next ;
     }*top;
    top= NULL;
    void PushMedicine()
    {  
        struct Medicinelist *newMedicine;
    	newMedicine=(struct Medicinelist *)malloc(sizeof(struct Medicinelist));
    	newMedicine->stockno=++stockno_count;
    	printf("Enter the name of the new Medicine\n");
    	scanf("%s",&newMedicine->Medicinename);
    	if(top==NULL)
	    {
    	newMedicine->next=NULL;
		top=newMedicine;
 	    }
	    else
	    {
		 newMedicine->next=top;
		 top=newMedicine;
	    }
    }
    void PopMedicine()
    {
      	if(top==NULL)
        printf("Underflow\n");
        else
        {	
          top=top->next;
        }
        printf("Element successfully popped\n");
    }
    void View_medicine()
    {   
        struct Medicinelist *temp;
    	temp=top;
        while(temp!=NULL)
	    {
		 printf("%d\n",temp->stockno);
		 printf("%s\n",temp->Medicinename);
		 temp=temp->next;
	    }

    }

    void patientenq()
    {   
    	struct Patientslist *newPatient;
    	newPatient=(struct Patientslist *)malloc(sizeof(struct Patientslist));
        newPatient->slno=++slexno;
    	printf("Enter the patient's name\n");
    	scanf("%s",&newPatient->Patientname);
    	printf("Enter the patient's ailment\n");
    	scanf("%s",&newPatient->Patientailment);
     if(head==NULL)
     {
     	newPatient->front=newPatient->prev=NULL;
     	head=newPatient;
     }
     else
     {
     	newPatient->front=head;
     	head->prev=newPatient;
     	newPatient->prev=NULL;
     	head=newPatient;
     }
    }
void patientdq()
{
	struct Patientslist *temp,*nxrear;
	temp=head;
	if((head->front==NULL)&&( head->prev==NULL))
	{
		head=NULL;
	}
	else{
	while(temp->front!=NULL)
	{
		temp=temp->front;
	}
   nxrear=temp->prev;
   nxrear->front=NULL;
        }
}

void patientdisplay()
{
struct Patientslist *temp;
	temp=head;
	while(temp!=NULL)
	{   printf("%d\n",temp->slno );
        printf("%s\n",temp->Patientname );
        printf("%s\n",temp->Patientailment );
		temp=temp->front;
	}
}

 while(ans==1)
	{
	 int ch=0;
	 printf("\tHOSPITAL ADMIN\n");
	 printf("MENU\n");
	 printf("Select 1 for Patient details\n");                              //Queue
	 printf("Select 2 for Medical stock details\n");                        //Stack
	 printf("Select 3 to Organize patients in alphabetical order\n");       //Sorting
	 printf("Select 4 to search among patients\n");                         //Searching
	 printf("Select 5 to Quit\n");
     scanf("\n%d",&ch);
     printf("%d\n",ch);
     void Patient()  // queue as a doubly linked list
      {
       while(ansP==1)
       { 
      
         printf("Do you want to \n1 admit \n2 discharge \n3 view");
         scanf("\n%d",&chP);
         switch(chP)
         {
         	 case 1 : patientenq();
         	 break;
          	 case 2 : patientdq();
          	 break;
        	 case 3 : patientdisplay();
        	 break;

         }
     
     printf("Do you want to edit / display Patient records\n");
     scanf("\n%d",&ansP);
       }
     }
   
    void Medicine_record()    // Considering all of the stock gets over before its expiry date we use the data structure STACK
    {  while(ansM==1)
       { 
    	printf("Do you want to \n1. Add stock \n2. Remove stock \n3.View stock");
    	scanf("\n%d",&chM);
    	switch(chM)
    	{
    		case 1:PushMedicine();
    		break;
    		case 2:PopMedicine();
    		break;
    		case 3:View_medicine();
    		break;
    	}

  
   printf("Do you want to edit / display Medicine records");
   scanf("\n%d",&ansM);
    }
    }
    void Arrange_Patients_By_Alph()
    {
    	struct Patientslist *a;
        a=head;
        while(a!=NULL)
        {
        	strcpy(str[l],a->Patientname);
      	    a=a->front;
      	    l++;
        }
         int x,y,o;
         for(x=0;x<=l;x++)
         {
     	   for(y=x+1;y<=l;y++)
     	     {
     		   if(strcmp(str[x],str[y])>0)
     		   {
     			strcpy(tempchar,str[x]);
     			strcpy(str[x],str[y]);
     			strcpy(str[y],tempchar);
     		   }
     	     }
         }
     printf("Order of sorted Strings\n");
     for(o=0;o<=l;o++)
     {
     	puts(str[o]);
     }
    }
void Search_patient()    //Linear search
{  
    char searchpat[50];
    int flag=0;
    struct Patientslist *tempsp,*foundp;
    tempsp=front;
    printf("Enter the name of the patient\n");
    scanf("%s",&searchpat);
    while(tempsp!=NULL)
    {   
        if(strcmp(searchpat,tempsp->Patientname)==0)
        {
          flag=1;
          foundp=tempsp;
        }
        tempsp=tempsp->front;
    }
    if(flag==0)
    {
        printf("Patient with given name is not found\n");
    }
    if(flag==1)
    {
        printf("The details of the patient are:\n");
        printf("Room no.\n");
        printf("%s\n",foundp->slno);
        printf("Patient's name\n");
        printf("%s\n",foundp->Patientname);
        printf("Patient's ailment\n");
        printf("%s\n",foundp->Patientailment);
    }
}

    switch(ch)
    {
    	case 1:Patient();
    	break;
    	case 2:Medicine_record();
    	break;
    	case 3:Arrange_Patients_By_Alph();
    	break;
        case 4:Search_patient();
        break;
    	case 5 : return 0;
    }
    printf("Do you want to continue\n");
    scanf("\n%d",&ans);
}
    return 0;

}



