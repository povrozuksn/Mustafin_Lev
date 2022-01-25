#include "TXLib.h"

struct button
{
    int x;
    int y;
    const char* text;
    string category;
};

struct picture
{
    int x;
    int y;
    HDC image;
    int w;
    int h;
    bool visible;
    string category;
};

    void drawbutton(button btn)
    {
        txSetColor (TX_BLACK, 3);
        txSetFillColor (TX_WHITE);
        Win32::RoundRect (txDC(), btn.x, btn.y, btn.x+155, btn.y+40, 5, 5);
        txSelectFont("Comic Sans MS", 25);
        txDrawText(btn.x, btn.y, btn.x+155, btn.y+40, btn.text);
    }

bool click(button btn)
{
    if (txMouseButtons() == 1 &&
            txMouseX() >= btn.x &&
            txMouseY() >= btn.y &&
            txMouseX() <= btn.x+155 &&
            txMouseY() <= btn.y+40)
            return 1;
     else
     return 0;
}


void drawpicturemenu(picture pct)
{
    if(pct.visible)
        Win32::TransparentBlt(txDC(), pct.x, pct.y, 128, 128, pct.image, 0, 0, pct.w, pct.h, TX_WHITE);
}

void drawpicturecentral(picture pct)
{
    if(pct.visible)
        Win32::TransparentBlt(txDC(), pct.x, pct.y, 64, 64, pct.image, 0, 0, pct.w, pct.h, TX_WHITE);
}

int main()
    {
    txCreateWindow (1366, 780);
    txTextCursor (false);
    txDisableAutoPause();
    const int count_btn = 3;
    const int count_pic = 22;
    int select=-1;
    bool mouse_release=false;
    int numberpic=0;

    HDC BG = txLoadImage("Images/������.bmp");
    HDC Map = txLoadImage("Images/�����.bmp");


    picture menupicture[count_pic];
    menupicture[0] = {50, 625, txLoadImage("Images/Decor/�������/��������_�����.bmp"), 256, 256, false, "�������"};
    menupicture[1] = {150, 625, txLoadImage("Images/Decor/�������/�����_���_�������.bmp"), 256, 256, false, "�������"};
    menupicture[2] = {260, 625, txLoadImage("Images/Decor/�������/��������������_�����.bmp"), 256, 256, false, "�������"};
    menupicture[3] = {370, 625, txLoadImage("Images/Decor/�������/��������_����.bmp"), 256, 256, false, "�������"};
    menupicture[4] = {480, 625, txLoadImage("Images/Decor/�������/������_�����.bmp"), 256, 256, false, "�������"};
    menupicture[5] = {590, 625, txLoadImage("Images/Decor/�������/�����_�����.bmp"), 256, 256, false, "�������"};
    menupicture[6] = {700, 625, txLoadImage("Images/Decor/�������/��������_�����.bmp"), 256, 256, false, "�������"};
    menupicture[7] = {810, 625, txLoadImage("Images/Decor/�������/����_�������.bmp"), 256, 256, false, "�������"};
    menupicture[8] = {920, 625, txLoadImage("Images/Decor/�������/���������_�����.bmp"), 256, 256, false, "�������"};
    menupicture[9] = {50, 625, txLoadImage("Images/Decor/������/���������_�����������.bmp"), 256, 256, false, "������"};
    menupicture[10] = {150, 625, txLoadImage("Images/Decor/������/�������������_������.bmp"), 256, 256, false, "������"};
    menupicture[11] = {260, 625, txLoadImage("Images/Decor/������/�������������_���������.bmp"), 256, 256, false, "������"};
    menupicture[12] = {370, 625, txLoadImage("Images/Decor/������/����������_����.bmp"), 256, 256, false, "������"};
    menupicture[13] = {480, 625, txLoadImage("Images/Decor/������/��������_��_������.bmp"), 256, 256, false, "������"};
    menupicture[14] = {590, 625, txLoadImage("Images/Decor/������/������_����.bmp"), 256, 256, false, "������"};
    menupicture[15] = {700, 625, txLoadImage("Images/Decor/������/������_����.bmp"), 256, 256, false, "������"};
    menupicture[16] = {810, 625, txLoadImage("Images/Decor/������/������_����.bmp"), 256, 256, false, "������"};
    menupicture[17] = {50, 625, txLoadImage("Images/Decor/��������/��������_�����.bmp"), 256, 256, false, "��������"};
    menupicture[18] = {150, 625, txLoadImage("Images/Decor/��������/��������_�����.bmp"), 256, 256, false, "��������"};
    menupicture[19] = {260, 625, txLoadImage("Images/Decor/��������/�������������_�����.bmp"), 256, 256, false, "��������"};
    menupicture[20] = {370, 625, txLoadImage("Images/Decor/��������/����-���.bmp"), 256, 256, false, "��������"};
    menupicture[21] = {480, 625, txLoadImage("Images/Decor/��������/��������_������.bmp"), 256, 256, false, "��������"};

    picture centralpicture[count_pic];

    button btn[count_btn];
    btn[0] = {55, 580, "������� ������", "�������"};
    btn[1] = {225, 580, "������ ������", "������"};
    btn[2] = {395, 580, "��������", "��������"};
    //btn[] = {, , ""};





    while (!GetAsyncKeyState (VK_ESCAPE))
    {
    txBegin();
    txBitBlt (txDC(), 0, 0, 1366, 780, BG, 0, 0);
    Win32::TransparentBlt (txDC(), 700, 50, 600, 700, Map, 0, 0, 600, 700, TX_WHITE);




/* ���� (����������)
    txSetColor (TX_BLACK, 3);
    txRectangle (49, 733, 1330, 765);
    txSelectFont ("Comic Sans MS", 30);
    txDrawText (471, 47, 895, 119, "�������� ��� ��������");
    txDrawText (565, 186, 797, 237, "������");
    txDrawText (565, 256, 797, 307, "���������");
    txDrawText (565, 326, 797, 377, "������");
    txDrawText (565, 396, 797, 447, "�����");
    txSelectFont ("Comic Sans MS", 20);
    txDrawText (49, 733, 1330, 765, "����� ��������, ��� ��������� ��� ��������������, ��� �������������� ��������� ����������� �������� MiHoYo � ������� �������������� �����.");
     */



    for(int nk=0; nk<count_btn; nk++)
    {
        drawbutton(btn[nk]);
    }

    for(int npic=0; npic<count_pic; npic++)
    {
        drawpicturemenu(menupicture[npic]);
    }

    for(int npic=0; npic<count_pic; npic++)
    {
        drawpicturecentral(centralpicture[npic]);
    }

    for(int nk=0; nk <count_btn; nk++)
    {
        if (click(btn[nk]))
            {
             for (int npic=0; npic<count_pic; npic++)
                {
                    menupicture[npic].visible=false;
                    if (menupicture[npic].category == btn[nk].category)
                        {
                            menupicture[npic].visible=true;
                        }
                }
            }
    }

    for(int npic=0; npic<count_pic; npic++)
    {
     if (txMouseButtons() == 1 &&
            menupicture[npic].visible &&
            txMouseX() >= menupicture[npic].x &&
            txMouseY() >= menupicture[npic].y &&
            txMouseX() <= menupicture[npic].x+128 &&
            txMouseY() <= menupicture[npic].y+128)
            {

            //�������� ������� ����� ������ ����
                    while(txMouseButtons() == 1)
                    {
                    txSleep(10);
                    }


             centralpicture[numberpic] = {500,
                                     200,
                                     menupicture[npic].image,
                                     menupicture[npic].w,
                                     menupicture[npic].h,
                                     menupicture[npic].visible,
                                     menupicture[npic].category};

               numberpic++;
            }

    }


    for(int npic=0; npic<count_pic; npic++)
    {
        if (txMouseButtons() == 1 &&
            centralpicture[npic].visible &&
            txMouseX() >= centralpicture[npic].x &&
            txMouseY() >= centralpicture[npic].y &&
            txMouseX() <= centralpicture[npic].x+centralpicture[npic].w &&
            txMouseY() <= centralpicture[npic].y+centralpicture[npic].h)
            {
            select=npic;
            mouse_release=false;
            }
    }

    if(select>=0)
    {
        if(txMouseButtons() == 1 && !mouse_release)
           {
           centralpicture[select].x = txMouseX() - 32;
           centralpicture[select].y = txMouseY() - 32;
           }

        else
            if (txMouseButtons() != 1)
                {
                mouse_release=true;
                }
    }





    txEnd();
     }

    txDeleteDC(BG);
    txDeleteDC(Map);


    return 0;
    }

