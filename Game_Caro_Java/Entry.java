package TicTac;

import java.util.*;
/*Game not finished when neither side has three in a row but the grid still has empty cells.
Draw when no side has a three in a row and the grid has no empty cells.
X wins when the grid has three X’s in a row.
O wins when the grid has three O’s in a row.
Impossible when the grid has three X’s in a row as well as three O’s in a row, or there are a lot more X's than O's or vice versa (the difference should be 1 or 0; if the difference is 2 or more, then the game state is impossible).
In this stage, we will assume that either X or O can start the game.*/
public class Entry {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = "_________";
        char[][] arr = new char[3][3];
        printedS(arr,s);
        int endGame = 0;
        int luot = 0;
        while(endGame == 0)
        {
            printedArr(arr);
            if(condition(arr)==1)
                endGame = 1;
            else
            {
                playerMove(arr,luot);
                luot++;
            }
        }
    }
    public static int condition(char [][]arr)
    {
        if((kiemtradieukienthangX(arr) == 1 && kiemtradieukienthangO(arr) == 1) || kiemtradieukienImpossible(arr)== 1)
        {
            System.out.println("Impossible");
            return 1;
        }
        else if(kiemtradieukienthangX(arr) == 1)
        {
            System.out.println("X wins");
            return 1;
        }
        else if(kiemtradieukienthangO(arr) == 1)
        {
            System.out.println("O wins");
            return 1;
        }
//        else if(kiemtradieukiendouble(arr) == 1) {
//            System.out.println("Game not finished");
//            return 1;
//        }
        else if(kiemtradieukienDraw(arr) == 1)
        {
            System.out.println("Draw");
            return 1;
        }
        return 0;
    }
    public static void printedS(char[][] arr, String s)
    {
        int pos = 0;
        for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i][j] = s.charAt(pos);
                pos++;
            }
        }
    }
    public static void printedArr(char[][] arr)
    {
        System.out.println("---------");
        for(int i = 0; i < 3; i++)
        {
            System.out.print("| ");
            for (int j = 0; j < 3; j++)
            {
                System.out.print(arr[i][j]);
                System.out.print(" ");
            }
            System.out.println("|");
        }
        System.out.println("---------");
    }
    public static void playerMove(char[][] board,int luot) {
        Scanner input = new Scanner(System.in);
        int validMove = 0;
        while (validMove == 0) {
            System.out.print("Enter the coordinates: ");
            try {
                int x = input.nextInt() - 1;
                int y = input.nextInt() - 1;
                if (x > 2|| x < 0 || y > 2 || y < 0) {
                    System.out.println("Coordinates should be from 1 to 3!");
                } else if (board[x][y] != '_') {
                    System.out.println("This cell is occupied! Choose another one!");
                } else {
                    if(luot % 2 == 0)
                        board[x][y] = 'X';
                    else
                        board[x][y] = 'O';
                    validMove = 1;
                }
            } catch (Exception NumberFormatException) {
                System.out.println("You should enter numbers!");
                input.nextLine();
            }
        }
    }
//    public static boolean isNumeric(String str) {
//        return str.matches("-?\\d+(\\.\\d+)?");  //match a number with optional '-' and decimal.
//    }
    public static int kiemtradieukienImpossible(char d[][])
    {
        int x = 0;
        int o = 0;
        for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(d[i][j] == 'X' )
                    x++;
                else if(d[i][j] == 'O')
                    o++;
            }
        }
        if(x > (o + 1) || o >(x + 1))
            return 1;
        return 0;
    }
    public static int kiemtradieukienDraw(char d[][])
    {
        int x = 0;
        int o = 0;
        int count = 0;
        for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(d[i][j] == '_' )
                    count++;
            }
        }
        if(count==0 && (kiemtradieukienthangX(d)!=1 || kiemtradieukienthangO(d)!=1))
            return 1;
        return 0;
    }
//    public static int kiemtradieukiendouble(char d[][])
//    {
//        int x = 0;
//        int o = 0;
//        int count = 0;
//        for(int i = 0; i < 3; i++)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                if(d[i][j] == '_')
//                    count++;
//            }
//        }
//        if(count == 0)
//            return 0;
//        return 1;
//    }
    public static int kiemtradieukienthangX(char d[][])
    {
        int x[] = { 1,2,3,4 };
        int y[] = { 1,2,3,4 };
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                if (d[i][j] == 'X')
                {
                    int dem1 = 1;
                    int dem2 = 1;
                    int dem3 = 1;
                    int dem4 = 1;
                    for (int k = 0; k < 4; k++)
                    {
                        if(i+x[k] < 3)
                            if (d[i + x[k]][j] == 'X')
                                dem1++;
                        if(j + y[k] < 3)
                            if (d[i][j + y[k]] == 'X')
                                dem2++;
                        if((i+x[k]) < 3 && (j + y[k]) < 3)
                            if (d[i + x[k]][j + y[k]] == 'X')
                                dem3++;
                        if((i - x[k]) >= 0 && (j + y[k]) < 3)
                            if (d[i - x[k]][j + y[k]] == 'X')
                                dem4++;
                    }
                    if (dem1 == 3 || dem2 == 3 || dem3 == 3 || dem4 == 3)
                        return 1;
                }
        }
        return 0;
    }
    public static int kiemtradieukienthangO(char d[][])
    {
        int x[] = { 1,2,3,4 };
        int y[] = { 1,2,3,4 };
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                if (d[i][j] == 'O')
                {
                    int dem1 = 1;
                    int dem2 = 1;
                    int dem3 = 1;
                    int dem4 = 1;
                    for (int k = 0; k < 4; k++)
                    {
                        if(i+x[k] < 3)
                            if (d[i + x[k]][j] == 'O')
                                dem1++;
                        if(j + y[k] < 3)
                            if (d[i][j + y[k]] == 'O')
                                dem2++;
                        if((i+x[k]) < 3 && (j + y[k]) < 3)
                            if (d[i + x[k]][j + y[k]] == 'O')
                                dem3++;
                        if(i - x[k] > 3 && j + y[k] < 3)
                            if (d[i - x[k]][j + y[k]] == 'O')
                                dem4++;
                    }
                    if (dem1 == 3 || dem2 == 3 || dem3 == 3 || dem4 == 3)
                        return 1;
                }
        }
        return 0;
    }

}
