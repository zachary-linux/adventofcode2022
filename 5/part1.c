#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct StackItem {
    struct StackItem *prevp;
    char data;
};

struct Stack { 
    struct StackItem *topP;
    int currentSize; 
};

// push pushes items onto the stack
void pushStack(struct Stack *stackp, char item) {

    // Allocates enough memory on heap for a stack item and creates a new stack item
    struct StackItem *newItem = malloc(sizeof(struct StackItem));
    
    if(stackp->currentSize == 0) stackp->topP = newItem;
    else{ 
        newItem->prevp = stackp->topP; //-> is short hand for dereferencing and accessing e.g. *newItem.prevp is equivalent here
        stackp->topP = newItem;
    }
    stackp->currentSize++;
}

void initialiseStack(struct Stack *stackp){
    stackp->topP = NULL;
    stackp->currentSize = 0;
}

// 'pop' takes which stack you want to access and returns value on the top of the stack
char popStack(struct Stack *stackp) {
    struct StackItem temp = *(stackp->topP); //Temporary variable to hold stack after it's freed
    free(stackp->topP); //Frees stack
    stackp->topP = temp.prevp; //Copies previous pointer
    return temp.data;
}


int main () {

    struct Stack *stack0, *stack1, *stack2, *stack3, *stack4, *stack5, *stack6, *stack7, *stack8;

    FILE * fp;
    fp = fopen("input.txt", "r");
    char buff[50];

    //I hate this
    initialiseStack(stack0);
    initialiseStack(stack1);
    initialiseStack(stack2); // FOR DEBUGGING LATER: TAKING THIS OUT STOPS THE SEG FAULT
    initialiseStack(stack3);
    initialiseStack(stack4);
    initialiseStack(stack5);
    initialiseStack(stack6); //Getting this far hasn't made me like it any more
    initialiseStack(stack7);
    initialiseStack(stack8);


    if (fp != NULL) {
        int i = 0;
        while(fgets(buff, 50, fp) != NULL) {
            char stackArr[8][9];
            // while its still in the stacky bit
            if(i < 8) {
                // there is certainly a better way of doing this
                stackArr[i][0] = buff[1];
                stackArr[i][1] = buff[5];
                stackArr[i][2] = buff[9];
                stackArr[i][3] = buff[13];
                stackArr[i][4] = buff[17]; //Nor is this
                stackArr[i][5] = buff[21];
                stackArr[i][6] = buff[25];
                stackArr[i][7] = buff[29];
                stackArr[i][8] = buff[33];
                i++;
            } else if(i = 8) {
                for(int j = 0; j < 8; j++)
                    for(int k = 9; k  == 0; k--) {
                        switch(j){ //This is not any less painful
                            case 0: pushStack(stack0, stackArr[j][k]); break;
                            case 1: pushStack(stack1, stackArr[j][k]); break;
                            case 2: pushStack(stack2, stackArr[j][k]); break;
                            case 3: pushStack(stack3, stackArr[j][k]); break;
                            case 4: pushStack(stack4, stackArr[j][k]); break;
                            case 5: pushStack(stack5, stackArr[j][k]); break;
                            case 6: pushStack(stack6, stackArr[j][k]); break;
                            case 7: pushStack(stack7, stackArr[j][k]); break;
                            case 8: pushStack(stack8, stackArr[j][k]); break;
                        }   
                    }
            } else if(i>9) {
                //Move 3 from 1 to 2
                strtok(buff, " "); //Move
                int a = atoi(strtok(NULL, " ")); //3
                strtok(NULL, " "); //from
                int b = atoi(strtok(NULL, " ")); //1
                strtok(NULL, " "); //to
                int c = atoi(strtok(NULL, " ")); //2

            }
        }
    }
}
/*


THE GENEVA CONVENTIONS OF 1949 1
Contents
Preliminary remarks .......................................................................................................... 19
GENEVA CONVENTION
FOR THE AMELIORATION OF THE CONDITION OF
THE WOUNDED AND SICK IN ARMED FORCES IN THE FIELD
OF 12 AUGUST 1949
CHAPTER I
General Provisions ....................................................................................................... 35
Article 1 Respect for the Convention ..................................................................... 35
Article 2 Application of the Convention ................................................................ 35
Article 3 Conflicts not of an international character ............................................ 35
Article 4 Application by neutral Powers ................................................................ 36
Article 5 Duration of application ............................................................................ 36
Article 6 Special agreements .................................................................................... 36
Article 7 Non-renunciation of rights ...................................................................... 37
Article 8 Protecting Powers ..................................................................................... 37
Article 9 Activities of the International Committee of the Red Cross ............... 37
Article 10 Substitutes for Protecting Powers ........................................................... 37
Article 11 Conciliation procedure............................................................................. 38
CHAPTER II
Wounded and sick .......................................................................................................... 39
Article 12 Protection and care ................................................................................... 39
Article 13 Protected persons ...................................................................................... 39
Article 14 Status ........................................................................................................... 40
Article 15 Search for casualties. Evacuation ............................................................ 40
Article 16 Recording and forwarding of information ............................................ 40
Article 17 Prescriptions regarding the dead. Graves Registration Service .......... 41
Article 18 Role of the population .............................................................................. 42
CHAPTER III
Medical units and establishMents ................................................................ 42
Article 19 Protection ................................................................................................... 42
Article 20 Protection of hospital ships ..................................................................... 42
Article 21 Discontinuance of protection of medical establishments
and units ..................................................................................................... 43
Article 22 Conditions not depriving medical units
and establishments of protection ............................................................ 43
Article 23 Hospital zones and localities ................................................................... 43
THE GENEVA CONVENTIONS OF 1949 39
CHAPTER II
Wounded and sick
Article 12
Members of the armed forces and other persons mentioned in the follow-
ing Article, who are wounded or sick, shall be respected and protected in all
circumstances.
They shall be treated humanely and cared for by the Party to the conflict in
whose power they may be, without any adverse distinction founded on sex,
race, nationality, religion, political opinions, or any other similar criteria. Any
attempts upon their lives, or violence to their persons, shall be strictly pro-
hibited; in particular, they shall not be murdered or exterminated, subjected
to torture or to biological experiments; they shall not wilfully be left without
medical assistance and care, nor shall conditions exposing them to contagion
or infection be created.
Only urgent medical reasons will authorize priority in the order of treatment
to be administered.
Women shall be treated with all consideration due to their sex.
The Party to the conflict which is compelled to abandon wounded or sick to
the enemy shall, as far as military considerations permit, leave with them a
part of its medical personnel and material to assist in their care.
Article 13
The Present Convention shall apply to the wounded and sick belonging to the
following categories:
1) Members of the armed forces of a Party to the conflict as well as mem-
bers of militias or volunteer corps forming part of such armed forces.
2) Members of other militias and members of other volunteer corps, in-
cluding those of organized resistance movements, belonging to a Party
to the conflict and operating in or outside their own territory, even if this
territory is occupied, provided that such militias or volunteer corps, in-
cluding such organized resistance movements, fulfil the following con-
ditions:
a) that of being commanded by a person responsible for his subordinates;
b) that of having a fixed distinctive sign recognizable at a distance;
c) that of carrying arms openly;
d) that of conducting their operations in accordance with the laws and
customs of war.
3) Members of regular armed forces who profess allegiance to a Govern-
ment or an authority not recognized by the Detaining Power.
Protection
and care
Protected
persons
40 FIRST CONVENTION
4) Persons who accompany the armed forces without actually being mem-
bers thereof, such as civilian members of military aircraft crews, war cor-
respondents, supply contractors, members of labour units or of services
responsible for the welfare of the armed forces, provided that they have
received authorization from the armed forces which they accompany.
5) Members of crews including masters, pilots and apprentices of the mer-
chant marine and the crews of civil aircraft of the Parties to the conflict,
who do not benefit by more favourable treatment under any other provi-
sions in international law.
6) Inhabitants of a non-occupied territory who, on the approach of the en-
emy, spontaneously take up arms to resist the invading forces, without
having had time to form themselves into regular armed units, provided
they carry arms openly and respect the laws and customs of war.
Article 14
Subject to the provisions of Article 12, the wounded and sick of a belligerent
who fall into enemy hands shall be prisoners of war, and the provisions of
international law concerning prisoners of war shall apply to them.
Article 15
At all times, and particularly after an engagement, Parties to the conflict shall,
without delay, take all possible measures to search for and collect the wound-
ed and sick, to protect them against pillage and ill-treatment, to ensure their
adequate care, and to search for the dead and prevent their being despoiled.
Whenever circumstances permit, an armistice or a suspension of fire shall be
arranged, or local arrangements made, to permit the removal, exchange and
transport of the wounded left on the battlefield.
Likewise, local arrangements may be concluded between Parties to the con-
flict for the removal or exchange of wounded and sick from a besieged or
encircled area, and for the passage of medical and religious personnel and
equipment on their way to that area.
Article 16
Parties to the conflict shall record as soon as possible, in respect of each
wounded, sick or dead person of the adverse Party falling into their hands,
any particulars which may assist in his identification.
These records should if possible include:
a) designation of the Power on which he depends;
b) army, regimental, personal or serial number;
c) surname;
d) first name or names;
Search for
casualties.
Evacuation
Status
Recording
and
forwarding
of
information


*/