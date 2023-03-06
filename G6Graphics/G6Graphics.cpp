#include <iostream>
#include <string>
#include "tigr.h"
#include "rogueutil.h"

using namespace std;

//HELP FUNCTION//
/*void G6Help()
{
    cout<<"DESCRIPTIONS OF HOW G6 FUNCTIONS ARE CALLED"<<endl<<endl;
    cout<<"---G6arrayDisplay---"<<endl<<"____________________"<<endl;
    cout<<"Function Call: G6arrayDisplay(userArray,arrSize);"<<endl<<endl;
    cout<<"Parameters: userArray: The name of your integer array"<<endl;
    cout<<"            arrSize: The expected size of your array"<<endl;
    cout<<"Result: A display that shows your array values"<<endl;
    cout<<"        and the order they appear in the array"<<endl<<endl<<endl;
}
*/
void G6Help()
{
    cout<<"\n\nG6GRAPHICS HELP MENU\n\nFUNCTION LIST\n-------------\n\nG6Help()\n"
    "G6ArrayDisplay(int userArr, int arrSize\nG6BarGraph(int userAry[], int arySize)"
    "\n\n\nHOW TO USE G6 METHODS\n---------------------\n\n"
    "(1) #include the G6Graphics header file in your project.\n"
    "(2) call desired function from above list (passing in correct data)\n"
    "(3) build and run your project\n"
    "(4) profit\n\n"
    "*SEE USER MANUAL FOR FULL DOCUMENTATION, FUNCTION LIST, AND USER MANUAL*\n\n\n\n\n\n\n";
}

//ARRAY FUNCTION//
int G6ArrayDisplay(int *userArray, int arrSize)
{
    int doneCycle = 0,ycord = 0,nextLine = 0;

    //DYNAMIC VARIABLES//
    string stringArr[arrSize];
    const char* charArr[arrSize];
    string position;
    const char* pos;

    //Populating S&C Arrays//
    for(int a = 0; a < arrSize; a++)
    {  stringArr[a] = to_string(userArray[a]);
       charArr[a] = stringArr[a].c_str();
    }

    //Create Display Screen//
    Tigr *screen = tigrWindow(620, 400, "CS-370 PROJECT", 0);

    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
    {

      ycord = 0;
      nextLine = 0;

      if(doneCycle !=1)
      {
        for(int b = 0; b<arrSize;b++)
        {   //Show Array Elements
            tigrClear(screen, tigrRGB(156,156,168));
            nextLine = 0;
            ycord = 0;
            for(int d = 0; d<=b;d++)
            {

                tigrPrint(screen, tfont, 220,10 , tigrRGB(0xff, 0xff, 0xff), "How Your Array Populated");
                if(nextLine == 8)
                {
                    ycord += 50;
                    nextLine = 0;
                }

                position = to_string(d);
                pos = position.c_str();

                //Displaying the stuff
                tigrRect(screen, 200, 40, 20, 15, tigrRGB(255, 0, 0));
                tigrPrint(screen, tfont, 220, 40, tigrRGB(0xff, 0xff, 0xff), " = The Position in The Array");
                tigrRect(screen, 75*(nextLine)+65, 70+ycord-5, 20, 15, tigrRGB(255, 0, 0));
                tigrRect(screen, 75*(nextLine)+10, 70+ycord-5, 75, 50, tigrRGB(0, 0, 255));
                tigrPrint(screen, tfont, 75*(nextLine)+10+15, 70+ycord+20, tigrRGB(0xff, 0xff, 0xff), charArr[d]);
                tigrPrint(screen, tfont, 75*(nextLine)+67, 70+ycord-2, tigrRGB(0xff, 0xff, 0xff), pos);
                nextLine++;
            }
            rogueutil :: msleep(1500);

            tigrUpdate(screen);
        }
       doneCycle = 1;
    }
    else
      {
        tigrPrint(screen, tfont, 220,10 , tigrRGB(0xff, 0xff, 0xff), "How Your Array Populated");
        nextLine = 0;
        for(int b = 0; b<arrSize;b++)
        {   //Show Array Elements
            tigrRect(screen, 200, 40, 20, 15, tigrRGB(255, 0, 0));
            tigrPrint(screen, tfont, 220, 40, tigrRGB(0xff, 0xff, 0xff), " = The Position in The Array");
            if(nextLine == 8)
            {
                ycord += 50;
                nextLine = 0;
            }
                position = to_string(b);
                pos = position.c_str();
                tigrRect(screen, 75*(nextLine)+65, 70+ycord-5, 20, 15, tigrRGB(255, 0, 0));
                tigrRect(screen, 75*(nextLine)+10, 70+ycord-5, 75, 50, tigrRGB(0, 0, 255));
                tigrPrint(screen, tfont, 75*(nextLine)+10+15, 70+ycord+20, tigrRGB(0xff, 0xff, 0xff), charArr[b]);
                tigrPrint(screen, tfont, 75*(nextLine)+67, 70+ycord-2, tigrRGB(0xff, 0xff, 0xff), pos);
            nextLine++;
        }
      }
        tigrUpdate(screen);
    }
    tigrFree(screen);

    return 0;
}


bool G6BarGraph(int userAry[], int arySize)
{
    //Variables List
    Tigr *screen = tigrWindow(400,325,"Array Bar Graph", 0);
    TPixel screenColor = tigrRGB(153,204,255);
    TPixel rectColor = tigrRGB(102,102,255);
    TPixel boxColor = tigrRGB(102,102,255);
    int displaySize = 8;
    int offset = 45;
    int xPos = 40;
    int yPos = 225;
    int start = 0;
    bool quit = false;
    string outputAry[arySize];

    for(int j = 0; j < (arySize); j++)
    {
        outputAry[j] = to_string(userAry[j]);

    }

    tigrClear(screen, screenColor);

    while(!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
    {

        if((arySize - start) > displaySize)
        {

            if((arySize > displaySize) && tigrKeyDown(screen, TK_RIGHT))
                {
                    tigrClear(screen, screenColor);
                    start += displaySize;
                    quit = false;
                    xPos = 40;
                }
        }


        if(start != 0 && tigrKeyDown(screen, TK_LEFT))
            {
                tigrClear(screen, screenColor);
                start -= displaySize;
                quit = false;
                xPos = 40;
            }

        if(start != 0 && tigrKeyDown(screen, TK_SPACE))
        {
            tigrClear(screen, screenColor);
            start = 0;
            quit = false;
            xPos = 40;
        }

        if(!quit)
        {

            for(int i = start; (i < displaySize + start) && i < arySize; i++)
            {
                //centering two digit inputs (will expand to more digits in future)
                if(userAry[i] >= 10)
                {
                    tigrPrint(screen, tfont, xPos - 5, yPos, tigrRGB(0xff, 0xff, 0xff), outputAry[i].data());
                }
                else
                {
                    tigrPrint(screen, tfont, xPos, yPos, tigrRGB(0xff, 0xff, 0xff), outputAry[i].data());
                }

                tigrRect(screen, xPos - 14 , yPos - 5, 33, 20, boxColor);
                tigrFillRect(screen, xPos - 15 , (yPos - (userAry[i]*10) - 10), 35, (userAry[i]*10), rectColor);
                tigrPrint(screen, tfont, xPos, (yPos + 25), tigrRGB(0xff, 0xff, 0xff), to_string(i).data());
                tigrPrint(screen, tfont, 5, 5, tigrRGB(0xff, 0xff, 0xff), "Esc");
                tigrPrint(screen, tfont, 85, (yPos + 50), tigrRGB(0xff, 0xff, 0xff), "<-- Back    Arrow Keys    Next -->");
                tigrPrint(screen, tfont, 85, (yPos + 75), tigrRGB(0xff, 0xff, 0xff), "PRESS < SPACE > TO RETURN TO START");
                xPos += offset;

            }

            quit = true;
        }

        tigrUpdate(screen);
    }

    return quit;

}

