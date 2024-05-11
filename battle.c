#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


typedef struct EntityData
{
    int LVL;
    int Attk;
    int Def;
    int HP;

}Entity_info;

Entity_info Player1,Enemy;





int ChanceCalc(int max){
    return rand()% max;
}

//Function to initialize player data
void InitPlayer(){
    Player1.LVL=5;
    Player1.Attk=5;
    Player1.Def=5;
    Player1.HP=Player1.LVL*10;
}

//Function to initialize enemy data
void InitEnemy(){
    Enemy.LVL=1;
    Enemy.Attk=1;
    Enemy.Def=1;
    Enemy.HP=Enemy.LVL*10;
}

//Function to display battle stats
void DisplayBattle(int pHP, int eHP){
    printf("Player HP:%d\n",pHP);
    printf("Enemy HP:%d\n",eHP);
}

//The Player Turn
int PlayerTurn(int Attk,int Def){
    int choice;
    printf("(1)Attack or (2)Defend\n");
    scanf("%d",&choice);
    if(choice==1){
        return ChanceCalc(Attk-Def);
    }else{
        return 0;
    }
}

//The Enemy Turn
int EnemyTurn(int Attk,int Def){
    if(Attk<Def) return 0;
    else
    return ChanceCalc(Attk-Def);
}


/*
The battle function returns 0 if the player lost and 1 if the player wins.
the parameters that the function takes is: [Player Level], [Player Base Attack], [Player Base Defense]
and vice-versa for the enemy.
basically the structure Entity_info applied twice;

for now let the battle be turn based with only an attack and block mechanic.
the attack value will be from the value of Attk to HP of the opponent.
*/
int battle(Entity_info Player, Entity_info Enemy){
    int dmg;

    while(Player.HP>0&&Enemy.HP>0){
        DisplayBattle(Player.HP,Enemy.HP);

        dmg=PlayerTurn(Player.Attk,Enemy.Def);
        printf("Player dealt: %d dmg\n",dmg);
        Enemy.HP-=dmg;
        dmg=EnemyTurn(Enemy.Attk,Player.Def);
        printf("Enemy dealt: %d dmg\n",dmg);
        Player.HP-=dmg;

        sleep(3);
        system("clear");
    }
    if(Player.HP>0){
        return 1;
    }else{
        return 0;
    }
    
}



int main(){

    InitPlayer();
    InitEnemy();
    if(battle(Player1,Enemy)==1){
        printf("Player Won!!!\n");
    }else{
        printf("Player Lost!!!\n");
    }
    return 0;
}