
#include <iostream>
#include "View.h"
#include "GameObject.h"

View::View()
{
    size = 11;
    scale = 2;
    origin.x = 0;
    origin.y = 0;
}

void View::Clear()
{
    for (int i = 0; i < view_maxsize; i++)
    {
        for (int j = 0; j < view_maxsize; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

void View::Plot(GameObject *ptr)
{
    // Point2D location_returned;
    // location_returned = ptr->GetLocation();

    int x;
    int y;

    char *selfptr = new char[2];

    ptr->DrawSelf(selfptr);

    if(GetSubscripts(x, y, ptr->GetLocation()) && (ptr->ShouldBeVisible() == true))
    {
        if (grid[x][y][0] != '.' && *selfptr != 't') 
        {
            grid[x][y][0] = '*';
            grid[x][y][1] = ' ';
        }
        else
        {
            if (*selfptr != 't')
            {
                grid[x][y][0] = *selfptr;
                grid[x][y][1] = *(selfptr + 1);
            }
        }
    }

    delete[] selfptr;
}

void View::Draw()
{
    for (int j = size - 1; j >= -1; j--)
    {
        for (int i = -1; i <= size - 1; i++)
        {
            
            if (i == -1 && j % 2 == 0)
            {
                cout << j * 2;
                if (j / 5 == 0)
                {
                    cout << " ";
                }
            }
            else if (i == -1 && j % 2 != 0)
            {
                cout << "  ";
            }
            else if (j == -1 && i % 2 == 0)
            {
                cout << i * 2;
                if (i / 5 == 0)
                {
                    cout << " ";
                }
                cout << "  ";
            }
            
            if (i >= 0 && j >= 0)
            {
                cout << grid[i][j][0] << grid[i][j][1];
            }
        }
        cout << endl;
    }

    cout << endl;
}


bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
    //following code from Albert: 

    /*
    out_x = (location.x - origin.x) / scale;
    out_y = (location.y - origin.y) / scale;

    if (out_x > view_maxsize || out_y > view_maxsize)
    {
        cout << "An Object is oustside the display " << endl;
        return false;
    }
    else
    {
        return true;
    }
    */

   //following code from instructor:

    out_x = (location.x)/2;
    out_y = (location.y)/2;

    if( location.x < 0 || location.x > 20  || location.y < 0 || location.y > 20 ) //Check to see if a object is out of bounds
    {
        cout << "An object is outside the display" << endl;
        return false;
    }
    return true;

}