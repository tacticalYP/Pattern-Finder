#include<stdio.h>
#include<stdbool.h>
#include<windows.h>

int r1,r2,c1,c2,something;
int count=0, cind=0;
bool pattern;

struct Coordinates{//structure for storing coordinates of patterns' locations
    int x;
    int y;
};

struct reality{ //function for helping in giving background colors to motif
    bool yes;
};

void input(int *motif,int p,int q){ // function for taking input elements in motif
    printf("\033[1;33mEnter the elements in the motif :\033[1;0m \n");
    something=-1;

    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",((motif+i*q)+j));
            if(*((motif+i*q)+j)==0) {printf("\n\033[1;31mYou can't enter 0 here, Read the instructions carefully and RE-RUN the program.\033[1;0m\n\n");
                                    something=10;
                                    break;}
        }
        if(something>0){break;}
        printf("\n");
    }
    return;
}

void check(int mosaic[r1][c1], int motif[r2][c2], int i, int j){ // function for checking pattern in motif

        for(int m=0;m<r1;m++){
                for(int n=0;n<c1;n++){
                    if((i+m>=r2 || j+n>=c2) && mosaic[m][n]==0){
                        pattern = false;
                        break;
                    }
                    if(mosaic[m][n]==0){
                        pattern=true;
                        continue;
                    }
                    if(motif[i+m][j+n]==mosaic[m][n] && i+m<r2 && j+n<c2){
                        pattern=true;
                        continue;
                    }
                    else{pattern=false;
                        break;
                    }
                }
                if(pattern==false){
                    break;
                }
        }
        return;
}

void check_ele(int num){ // function for giving background color in matrix
    if(num==1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
    }
    else if(num==2){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE);

    }
    else if(num == 3){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);
    }
    else if(num==4){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_BLUE);
    }
    else if(num==5){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE);
    }
    else if(num==6){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);
    }
    else if(num==7){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);
    }
    else if(num==8){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_RED);
    }
    else if(num==9){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    }

    return;
}

int main(){
//printing instructions
    printf("\n\n\033[1;32m---------------------------------------------------------------------------------------------------\033[1;0m");
    printf("  \n\n\033[1;32m**Instructions** :\033[1;0m \n");
    printf("  \033[1;32m(i)   You can enter any matrix (size : mxn,  m,n>0) with elements in range 1-9.\033[1;0m\n");
    printf("        \033[1;32m(these numbers are considered as tiles, different element means different tile.)\033[1;0m\n");
    printf("  \033[1;32m(ii)  Only in pattern matrix you can enter '0' as empty tile.\033[1;0m\n");
    printf("        \033[1;32m(empty tile can be considered as any tile in motif.)\033[1;0m\n");
    printf("  \033[1;32m(iii) Dimensions of motif matrix should be greater than pattern matrix.\033[1;0m\n");
    printf("  \033[1;32m(iv)  If you enter any values adjacent to each other, always keep a space between them.\033[1;0m\n");
    printf("  \033[1;32m(v)   If you enter elements <0 or >9, quality of final result may reduce.\033[1;0m\n\n");
    printf("\033[1;32m---------------------------------------------------------------------------------------------------\033[1;0m\n\n");
    
    system("pause");
//taking inputs for pattern
    int r,c;
    printf("\n\033[1;33mFirst enter number of rows then columns of Pattern : \033[1;0m\n");
    scanf("%d %d",&r, &c);
    
    if(r<1 || c<1){ printf("\n\033[1;31mWRONG DIMENSIONS... Read the instructions carefully and RE-RUN the program.\033[1;0m\n");
                    return 0;}

    printf("\033[1;33mEnter the elements in the pattern : \033[1;0m\n");
	
    int PaTTerN[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&PaTTerN[i][j]);
        }
        printf("\n");
    }
//taking inputs for pattern
    printf("\033[1;33mNow enter the number of rows then columns for motif in which you want to find above pattern : \033[1;0m\n");
    int p,q;
    scanf("%d %d",&p,&q);

    if(r>p || c>q){ printf("\n\033[1;31mWRONG DIMENSIONS... Read instructions carefully and RE-RUN the program.\033[1;0m\n");
                    return 0;}

    int motif[p][q];
    input((int*)motif,p,q);
    if(something>0){return 0;}

    r1=r;r2=p;c1=c;c2=q;
    struct Coordinates coord[p*q];
//checking pattern in motif and taking proper coordinates
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(motif[i][j]==PaTTerN[0][0]||PaTTerN[0][0]==0){
                check(PaTTerN,motif,i,j);
                if(pattern==true){
                    count++;
                    coord[cind].x=i;
                    coord[cind].y=j;
                    cind++;
                }
            }
        }
    }
   
    printf("\033[1;33mThis is the given Pattern :\033[1;0m\n");
//printing pattern
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            check_ele(PaTTerN[i][j]);
            printf("%d ",PaTTerN[i][j]);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        printf("\n");
    }
//printing motif
    printf("\n\033[1;33mThis is the given Motif :\033[1;0m\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            check_ele(motif[i][j]);
            printf("%d ",motif[i][j]);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        printf("\n");
    }
        printf("\n");
        system("pause");

    struct reality real[r2][c2];
    if(count==0) printf("\n\n\033[1;31mNo such pattern found in motif\033[1;0m");
    else{
        
        printf("\n\033[1;35mThe number of such patterns in motif is/are : \033[1;36m%d\033[1;0m\n",count);//how many times pattern found
        printf("\n\033[1;35mAt following index/indices required pattern is found :\n");
        
        for(int v=0;v<count;v++){
            printf("\n\033[1;36m%d] (%d, %d)\033[1;0m\t",v+1,coord[v].x + 1,coord[v].y + 1);//printing location coordinates
            for(int l = 0; l<r2;l++){
                for(int m=0;m<c2;m++){
                real[l][m].yes = false;}
            }

            for(int o=coord[v].x; o<coord[v].x+r1;o++){
                for(int z=coord[v].y;z<coord[v].y+c1;z++){
                    real[o][z].yes=true;
                }
            }
            
            for(int i = 0; i<r2;i++){
                for(int j=0;j<c2;j++){//showing location of pattern
                    if(real[i][j].yes == false){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_GREEN);
                        printf(" \033[1;30m%d \033[1;0m",motif[i][j]);
                    }
                    else if (real[i][j].yes == true){
                        check_ele(motif[i][j]);
                        printf(" \033[1;37m%d \033[1;0m",motif[i][j]);
                    }
                }
                printf("\n \t\t");
            }
        }
    }
    return 0;
}
