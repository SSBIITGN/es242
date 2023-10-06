// #include <stdio.h>
// /*
//  * The status of a line.
//  */
// enum {
//     NO = 0, /* No line */
//     RED = 1,
//     BLUE = 2
// };

// /*
//  * The board records the colors of the lines.
//  * board[0] = color of 12
//  * board[1] = color of 13
//  * ...
//  * board[14] = color of 56
//  */
// typedef char board_t[15];
// typedef char player_t; /* A player should be RED or BLUE. */

// player_t other ( player_t player){
//         switch (player) {
//         case RED: return 2; break;
//         case BLUE: return 1; break;
//         }
// }
// int has_won(board_t board, player_t player)
// {
//     player_t opp= other(player);
//     int pos[20][3] = {
//         {0,1,5},
//         {0,2,6},
//         {0,3,7},
//         {0,4,8},
//         {1,2,9},
//         {1,3,10},
//         {1,4,11},
//         {2,3,12},
//         {2,4,13},
//         {3,4,14},
//         {5,6,9},
//         {5,7,10},
//         {5,8,11},
//         {6,7,12},
//         {6,8,13},
//         {7,8,14},
//         {9,10,12},
//         {9,11,13},
//         {10,11,14},
//         {12,13,14}
//     };
//     for (int i =0; i<20; i++){
//         if (board[pos[i][0]]==opp && board[pos[i][1]]==opp && board[pos[i][2]]==opp){
//             return 1;
//         }
//     }
//   return 0;
// }

// int is_full(board_t board)
// {   
//     for ( int i=0 ; i < 15 ; i++){
//         if ( board[i] == NO ){
//             return 0;
//         }
//     }
//     return 1;
// }
// void con(val){
//   printf("%d",val);
// }
// typedef struct {
//     int line; /* 0 for 12, 1 for 13, ..., 14 for 56. */
//     int score; /* -1 for loss, 0 for draw, 1 for win. */
// } move_t;

// move_t best_move(board_t board, player_t player)
// {   move_t bm,obm;
    
//     int cnt=10;
//     bm.score=-1;
//     bm.line=-1;
//     for(int i=0; i<15;i++){
//       if (board[i]!=0){
//         continue;
//       }
//       board[i]=player;
//       if (has_won(board,other(player))){
//         board[i]=0;
//         if (bm.line==-1){
//           bm.line=i;
//         }
//         continue;
//       }
//       obm=best_move(board, other(player));
//       if (obm.score<0){
//         bm.line=i;
//         bm.score=1-obm.score;
//         board[i]=0;
//         return bm;
//       }
//       else{
//         int temp=-1-obm.score;
//         if (temp<cnt){
//           bm.score=temp;
//           cnt=temp;
//           bm.line=i;
//         }
//       }
//       board[i]=0;
//     }
//     return bm;
// }

// void print_board(board_t board)
// {   
//     int i, j;
//     for (j=0; j<15; j++){
//        printf("%d ",j);
//     }
//     printf("\n");
//     for (i = 0; i < 10; i++) {
//       if (board[i]==0){
//         printf(". ");
//       }else if(board[i]==1){
//         printf("R ");
//         }
//       else{
//         printf("B ");
//       }
//     }
//     for (i = 10; i < 15; i++) {
//       if (board[i]==0){
//         printf(".  ");
//       }else if(board[i]==1){
//         printf("R  ");
//         }
//       else{
//         printf("B  ");
//       }
//     }
//     printf("\n");
// }

// int main()
// {   
//     /* Your game play logic. */
//     /* The user should have the option to select red or blue player. */
//     board_t board;
//     player_t player;
//     int inp,res,cur;
//     for (int i=0; i<15; i++){
//         board[i]=0;
//     }
//     printf("Select a colour : \nEnter 1 for RED\nEnter 2 for BLUE\n");
//     scanf("%d",&res);
//     if (res==1){
//       player=RED;
//     }else{
//       player=BLUE;
//     }
//     if (res==1){
//       printf("     Your are RED\n");
//     }else{
//       printf("     Your are BLUE\n");
//     }
    
//     printf("    \n");
//     printf("Who should start : \nEnter 1 for Player\nEnter 2 for Computer\n");
//     scanf("%d",&cur);
//     if(cur==2){
//       player=other(player);
//     }
//     printf("    \n");
//     print_board(board);
//     printf("    \n");
//     while(1){
//         if (cur==1){
//             if (is_full(board)){
//                 printf("it is a tie");
//                 break;
//             }
//             while(1){
//               scanf("%d",&inp);
//               if (board[inp]==0){
//                 break;
//               }
//               printf("    \n");
//               printf("Please give vaild input !\n");
              
//             }
            
//             printf("    \n");
//             printf("player chose : ""%d\n",inp);
//             board[inp]=player;
//             // move_t ai1=best_move(board,BLUE);
//             // printf("player chose : ""%d\n",ai1.line);
//             // board[ai1.line]=BLUE;
          
//             print_board(board);
//             printf("    \n");
          
//             if (has_won(board,other(player))){
//                 printf("Computer Has Won");
//                 break;
//             }
//         }else{
//             if (is_full(board)){
//                 printf("it is a tie");
//                 break;
//             }
//             printf("    \n");
//             move_t ai=best_move(board,player);
//             printf("computer chose : ""%d\n",ai.line);
//             board[ai.line]=player;
            
//             print_board(board);
          
//             if (has_won(board,other(player))){
//                 printf("Player Has Won");
//                 break;
//             }
//         }
//     cur=3-cur;
//     player=other(player);  
//     }
//     return 0;
// }


#include <stdio.h>
#include <stdint.h>
#include <assert.h>
/* Implement connect 4 on a 5 (columns) x 4 (rows) board. */
enum {
    EMPTY = 0,
    RED=1,
    BLUE=2,
    Rows=4,
    Cols=5,
};

typedef char board_t[4][5];
typedef char player_t;

player_t other ( player_t player){
        switch (player) {
        case RED: return 2; break;
        case BLUE: return 1; break;
        }
}
void print_board(board_t board) {
    int i, j;
    for (int k=0;k<5;k++){
        printf("%d ",k);   
    }
    printf("\n");
    for (i = 0; i < Rows; i++) {
        for (j = 0; j < Cols; j++) {
            if (board[i][j] == EMPTY) {
                printf(". ");
            } else if (board[i][j] == RED) {
                printf("R ");
            } else {
                printf("B ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
int has_won(board_t board, player_t player){
    int i, j,flag;
    int arr[]={0,0,0,0};
    int dia[4][4][2]={{{0,0},{1,1},{2,2},{3,3}},{{0,1},{1,2},{2,3},{3,4}},{{3,0},{2,1},{1,2},{0,3}},{{3,1},{2,2},{1,3},{0,4}}};
    for (j = 0; j<Cols; j++) {
        flag=1;
        for(i=0;i<Rows;i++){
            if (board[i][j]!=player){
                arr[i]=0;
                flag=0;
            }else{
                arr[i]+=1;
            }
            if(arr[i]==4){
                return 1;
            }
        }
        if (flag){
            return 1;
        }
    } 
    int in1,in2;
    for(i=0;i<4;i++){
        flag=1;
        for(j=0;j<4;j++){
            in1=dia[i][j][0];
            in2=dia[i][j][1];
            if(board[in1][in2]!=player){
                flag=0;
                break;
            }
        }
        if (flag){
            return 1;
        }
    }  
    return 0;
}
int valid(board_t board,int val){
    for (int i=0;i<5;i++){
        if (i==val){
            if (board[0][val]==0){
                return 1;
            }
        }
    }
    return 0;
}
int is_full(board_t board) {
    int i, j;
    for (i = 0; i < Rows; i++) {
        for (j = 0; j < Cols; j++) {
            if (board[i][j] == EMPTY) {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

void fill(board_t board,int pos,player_t player){
    for (int i=3;i>=0;i--){
            if (board[i][pos]==EMPTY){
              board[i][pos]=player;
              break;
            }
        }
}
// void find_row(board_t board,)
void del(board_t board,int pos){
    for (int i=0;i<Rows;i++){
        if (board[i][pos]!=EMPTY){
          board[i][pos]=0;
          break;
        }
    }
}

typedef struct {
    int col;
    int score;
} move_t;

move_t best_move(board_t board, player_t player){
  
    move_t candidate,response;
    int no_can=1;

    for(int i=0; i<5; i++){
        if (board[0][i]!=EMPTY){
            continue;
        }
        fill(board,i,player);
        if (has_won(board,player)){
            del(board,i);
          (candidate = (move_t) {
                        .col=i,
                        .score = 1
                        });
                    return candidate;
        }
        del(board,i);
    }
    for(int i=0;i<5;i++){
        if (board[0][i]!=EMPTY){
            continue;
        }
        fill(board,i,player);
        if (is_full(board)){
            del(board,i);
          (candidate = (move_t) {
                        .col=i,
                        .score = 0
                        });
                    return candidate;
        }
        response=best_move(board,other(player));
        del(board,i);
        if (response.score==-1){
          (candidate = (move_t) {
                        .col=i,
                        .score = 1
                        });
                    return candidate;
        } else if (response.score == 0) {
            candidate=(move_t){
              .col=i,
              .score=0
            };
            no_can = 0;
        } else {
            if (no_can) {
              candidate=(move_t){
                .col=i,
                .score=-1
              };
              no_can= 0;
                }
            }
    }
    return candidate;
}


int main()
{
    /* Your game play logic. */
    /* The user should have the option to select red or blue player. */
    player_t player;
    board_t board;
    int inp,res,cur,ans;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
          board[i][j]=0;
        }
    }
    
    printf("Select a colour : \nEnter 1 for RED\nEnter 2 for BLUE\n");
    scanf("%d",&res);
    if (res==1){
      player=RED;
    }else{
      player=BLUE;
    }
    if (res==1){
      printf("     Your are RED\n");
    }else{
      printf("     Your are BLUE\n");
    }
    
    printf("    \n");
    printf("Who should start : \nEnter 1 for Player\nEnter 2 for Computer\n");
    scanf("%d",&cur);
    printf("    \n");
    print_board(board);
    printf("    \n");

    if (cur==1){
      
              scanf("%d",&inp);
      fill(board,inp,player);
      print_board(board);
        if (inp==0){
           fill(board,1,other(player));
        }
      if (inp==1){
           fill(board,4,other(player));
        }
      if (inp==2){
           fill(board,4,other(player));
        }
      if (inp==3){
           fill(board,0,other(player));
        }
      if (inp==4){
           fill(board,3,other(player));
        }
      print_board(board);
    }
    else{
      player=other(player);
        fill(board,3,player);
        print_board(board);
        scanf("%d", &inp);
        fill(board,inp,other(player));
        print_board(board);
        if (inp==0){
       fill(board,4,player);
        }
      if (inp==1){
       fill(board,1,player);
        }
      if (inp==2){
       fill(board,3,player);
        }
      if (inp==3){
       fill(board,1,player);
        }
      if (inp==4){
       fill(board,4,player);
      }
      print_board(board);
        player=other(player);
      cur=1;
    }
    while(1){
        if (is_full(board)){
            printf("It is a tie");
            break;
        }
        if (cur==1){
            while(1){
              scanf("%d",&inp);
              if (valid(board,inp)){
                break;
              }
              printf("    \n");
              printf("Please give vaild input !\n");
              
            };
            ans=inp;
            printf("    \n");
            printf("player chose : ""%d\n",inp);
        }else{
            printf("    \n");
            move_t ai=best_move(board,player);
            ans=ai.col;
            printf("computer chose : ""%d\n",ai.col);
        }
        fill(board,ans,player);
      
        print_board(board);
        printf("    \n");
        
        if (has_won(board,player)){
            if (player==res){
                printf("Player Has Won");
            }else{
                printf("Conputer Has Won");
            }
            break;
        }
    cur=3-cur;
    player=other(player);  
    }
    return 0;
}
