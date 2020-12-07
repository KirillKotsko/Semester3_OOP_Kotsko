/***************************************************************
 * Name:      EncAntMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    hhh ()
 * Created:   2019-03-02
 * Copyright: hhh ()
 * License:
 **************************************************************/

#include "EncAntMain.h"
#include<bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include<ctime>
#include <wx/msgdlg.h>

using namespace std;

long long randomize(long long n)
{
    long n_with_change = n;
    double digit = 0, chislo, procent = 1, recent_t;
    bool check_digit = true;

    while (n_with_change!=0)
    {
        if (n_with_change/10 == 0 && n_with_change%10 != 1 || n==1) check_digit = false;
        if (n_with_change/10 != 0 && n_with_change%10 != 0) check_digit = false;
        n_with_change /= 10;
        digit += 1;
    }
    if (!check_digit) digit += 1;

    long time_now = clock();

    for (long i = time_now; i >= 1; i --)
    {
        recent_t = double(i);
        procent *= sqrt(recent_t)/recent_t;
        while (procent < pow(10, - (digit - 1))) procent *= pow(10, digit - 1);
    }

    chislo = double(n) * procent;
    if (floor(chislo * 10) - floor(chislo)*10 >= 5 || (chislo > 0 && chislo < 1)) chislo = ceil(chislo);
    else chislo = floor(chislo);

    usleep(10);

    return static_cast<long>(chislo);
}

int bit_of_this(int bait, int h)
{
    return (bait >> (7 - h)) % 2;
}

string a,b;

//(*InternalHeaders(EncAntFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(EncAntFrame)
const long EncAntFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long EncAntFrame::ID_BUTTON1 = wxNewId();
const long EncAntFrame::ID_BUTTON2 = wxNewId();
const long EncAntFrame::ID_STATICTEXT1 = wxNewId();
const long EncAntFrame::ID_STATICTEXT2 = wxNewId();
const long EncAntFrame::ID_TEXTCTRL1 = wxNewId();
const long EncAntFrame::ID_STATICBITMAP1 = wxNewId();
const long EncAntFrame::ID_STATICBITMAP2 = wxNewId();
const long EncAntFrame::idInstuction = wxNewId();
const long EncAntFrame::idMenuQuit = wxNewId();
//*)

BEGIN_EVENT_TABLE(EncAntFrame,wxFrame)
    //(*EventTable(EncAntFrame)
    //*)
END_EVENT_TABLE()

EncAntFrame::EncAntFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(EncAntFrame)
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;

    Create(parent, id, _("EncAnt"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(497,417));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_SCROLLBAR));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("images\\Entypo_2712(0)_1024.ico"))));
    	SetIcon(FrameIcon);
    }
    FilePickerCtrl1 = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxPoint(112,25), wxSize(352,23), wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Encrypt"), wxPoint(40,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Decrypt"), wxPoint(200,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Select file:"), wxPoint(32,25), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Times New Roman"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Enter the key:"), wxPoint(32,65), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Times New Roman"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,65), wxSize(328,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("images\\Entypo_2712(0)_1024.png")).Rescale(wxSize(256,256).GetWidth(),wxSize(256,256).GetHeight())), wxPoint(16,144), wxSize(256,256), 0, _T("ID_STATICBITMAP1"));
    StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxBitmap(wxImage(_T("images\\padlock.png")).Rescale(wxSize(199,258).GetWidth(),wxSize(199,258).GetHeight())), wxPoint(280,128), wxSize(199,258), 0, _T("ID_STATICBITMAP2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu1, idInstuction, _("Instuction\tF2"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem2);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Menu"));
    SetMenuBar(MenuBar1);

    Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&EncAntFrame::OnFilePickerCtrl1FileChanged);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EncAntFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EncAntFrame::OnButton2Click2);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&EncAntFrame::OnTextCtrl1Text2);
    Connect(idInstuction,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EncAntFrame::OnInstruction);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&EncAntFrame::OnQuit);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&EncAntFrame::OnClose);
    //*)
}

EncAntFrame::~EncAntFrame()
{
    //(*Destroy(EncAntFrame)
    //*)
}

void EncAntFrame::OnQuit(wxCommandEvent& event)
{
    Destroy();
}

void EncAntFrame::OnInstruction(wxCommandEvent& event)
{
    wxMessageBox("If you want to encrypt your file, select it and then press button. Make sure you select the file you want. When the encryption process is over a file appears in the folder with the key to decrypt. Don't lose it. \nIf you want to decrypt your file, select it, enter the key and then press button. If the key is in the wrong form, the program may give a fatal error.", "Instruction");
}

void EncAntFrame::OnFilePickerCtrl1FileChanged(wxFileDirPickerEvent& event)
{
    wxString v;
    v = FilePickerCtrl1->GetPath();
    a=v.ToStdString();
}

void EncAntFrame::OnTextCtrl1Text2(wxCommandEvent& event)
{
    wxString v;
    v = TextCtrl1->GetValue();
    b=v.ToStdString();
}

void EncAntFrame::OnClose(wxCloseEvent& event)
{
    Destroy();
}

void EncAntFrame::OnButton1Click(wxCommandEvent& event)
{
    wxString msg;
    const char* file_name = &a[0];
    FILE* Langtons_hide = fopen( file_name, "r+b" );

    if (Langtons_hide == NULL)
    {
        msg = "Error opening file.";
        wxMessageBox(msg, _("Error"));
    }
    else
    {
    fseek(Langtons_hide , 0 , SEEK_END);
    long long file_size = ftell(Langtons_hide);
    rewind (Langtons_hide);
    char * file_buffer = (char*) malloc(sizeof(char) * file_size);
    size_t result = fread(file_buffer, 1, file_size, Langtons_hide);
        long long number_of_blocks, width, heigth, rand_choice, block_size, count=0;
        vector<long long> NoB(100000);
        vector<long long> w(100000);
        vector<long long> h(100000);

        for (long long koef_am = 1; koef_am <= ((file_size * 8) / 9); koef_am++)
        {
            if (((file_size * 8) % koef_am) == 0 && ((file_size * 8) / koef_am) >= 8 && ((file_size * 8) / koef_am) % 8 == 0)
            {
                block_size = (file_size * 8) / koef_am;
                for (long long koef_w = 4; koef_w <= (block_size / 2); koef_w++)
                {
                    if ((block_size <= 518400) && (block_size % koef_w) == 0 && (block_size / koef_w) >= 3 && max(koef_w, block_size / koef_w) / min(koef_w, block_size / koef_w) <= 20)
                    {
                            NoB[count] = koef_am;
                            w[count] = koef_w;
                            h[count] = block_size / koef_w;
                            count++;
                    }
                }
            }
        }
        if (count == 0)
        {
            NoB[0] = 1;
            w[0] = (file_size * 8) / 4;
            h[0] = 4;
            NoB[1] = 1;
            w[1] = (file_size * 8) / 8;
            h[1] = 8;
            count = 2;
        }
        rand_choice = randomize(count);
        number_of_blocks = NoB[rand_choice-1];
        width = w[rand_choice - 1];
        heigth = h[rand_choice - 1];

        int buffer_count = 0;
        int buffer_change = 0;
        vector<int> x_of_end(number_of_blocks);
        vector<int> y_of_end(number_of_blocks);
        vector<int> turn_of_end(number_of_blocks);
        vector<long long> amount_of_first_position(number_of_blocks);
        vector<long long> x_of_first_position(number_of_blocks);
        vector<long long> y_of_first_position(number_of_blocks);
        for (int nomer_block = 1; nomer_block <= number_of_blocks; nomer_block++)
        {
            long long on_first_position = 1;
            int block[width][heigth] = {0}, x = randomize(width) - 1, y = randomize(heigth) - 1, forwarding = randomize(4);
            int x_first_position = x, y_first_position = y;
            x_of_first_position[nomer_block - 1] = x_first_position;
            y_of_first_position[nomer_block - 1] = y_first_position;
            bool checker[width][heigth] = {0};
            int counter_checker = 0, ix = 0, iy = 0;
            int new_x_y[width * heigth / 8];
            for (int i = 0 ; i < width * heigth / 8; i++)
            {
                new_x_y[i] = 1;
            }

            for (int i = 1; i <= (width * heigth) / 8; i++)
            {
                int bait = static_cast<int>(file_buffer[buffer_count]);
                if (bait < 0) bait += 256;
                buffer_count++;
                int bit_our[8];
                for (int bitok = 0; bitok <= 7; bitok++) bit_our[bitok] = bit_of_this(bait, bitok);
                int ukazatel = 0;

                while (ukazatel != 8)
                {
                    block[ix][iy] = bit_our[ukazatel];
                    ukazatel++;
                    if (ix < width - 1)
                    {
                        ix++;
                    }
                    else
                    {
                        ix = 0;
                        iy++;
                    }
                }
            }

            while (counter_checker != width * heigth / 8)
            {
                if (block[x][y] == 1)
                {
                    block[x][y] = 0;
                    if (!checker[x][y] && new_x_y[int(ceil(double(y * width + x + 1) / 8) - 1)] == 1)
                    {
                        checker[x][y] = true;
                        new_x_y[int(ceil(double(y * width + x + 1) / 8) - 1)] = 0;
                        counter_checker++;
                    }
                    if (forwarding == 1)
                    {
                        forwarding = 2;
                        if (x + 1 <= width - 1)
                        {
                            x += 1;
                        }
                        else
                        {
                            x = 0;
                            y = (heigth - 1) - y;
                        }
                    }
                    else if (forwarding == 2)
                    {
                        forwarding = 3;
                        if (y + 1 <= heigth - 1)
                        {
                            y += 1;
                        }
                        else
                        {
                            y = 0;
                            x = (width - 1) - x;
                        }
                    }
                    else if (forwarding == 3)
                    {
                        forwarding = 4;
                        if (x >= 1)
                        {
                            x -= 1;
                        }
                        else
                        {
                            x = width - 1;
                            y = (heigth - 1) - y;
                        }
                    }
                    else if (forwarding == 4)
                    {
                        forwarding = 1;
                        if (y >= 1)
                        {
                            y -= 1;
                        }
                        else
                        {
                            y = heigth - 1;
                            x = (width - 1) - x;
                        }
                    }
                }
                else
                {
                    block[x][y] = 1;
                    if (!checker[x][y] && new_x_y[int(ceil(double(y * width + x + 1) / 8) - 1)] == 1)
                    {
                        checker[x][y] = true;
                        new_x_y[int(ceil(double(y * width + x + 1) / 8) - 1)] = 0;
                        counter_checker++;
                    }
                    if (forwarding == 1)
                    {
                        forwarding = 4;
                        if (x >= 1)
                        {
                            x -= 1;
                        }
                        else
                        {
                            x = width - 1;
                            y = (heigth - 1) - y;
                        }
                    }
                    else if (forwarding == 2)
                    {
                        forwarding = 1;
                        if (y >= 1)
                        {
                            y -= 1;
                        }
                        else
                        {
                            y = heigth - 1;
                            x = (width - 1) - x;
                        }
                    }
                    else if (forwarding == 3)
                    {
                        forwarding = 2;
                        if (x + 1 <= width - 1)
                        {
                            x += 1;
                        }
                        else
                        {
                            x = 0;
                            y = (heigth - 1) - y;
                        }
                    }
                    else if (forwarding == 4)
                    {
                        forwarding = 3;
                        if (y + 1 <= heigth - 1)
                        {
                            y += 1;
                        }
                        else
                        {
                            y = 0;
                            x = (width - 1) - x;
                        }
                    }
                }
                if (x == x_first_position && y == y_first_position) on_first_position++;
                /*cout<<counter_checker<<" "<<width * heigth / 8<<" "<<nomer_block<<" "<<number_of_blocks<<" "<<x<<" "<<y<<" "<<block[x][y]<<endl;*/
            }
            x_of_end[nomer_block - 1] = x;
            y_of_end[nomer_block - 1] = y;
            turn_of_end[nomer_block - 1] = forwarding;
            amount_of_first_position[nomer_block - 1] = on_first_position;

            int bit_now = 0;
            int code = 0;
            for (int j = 0; j < heigth; j++)
            {
                for (int i = 0; i < width; i++)
                {
                    code += block[i][j] * pow(2,7-bit_now);
                    if (bit_now != 7) bit_now++;
                    else
                    {
                        bit_now = 0;
                        if (code >= 128) code -= 256;
                        file_buffer[buffer_change] = char(code);
                        buffer_change++;
                        code = 0;
                    }
                }
            }
        }
        fseek(Langtons_hide, 0, SEEK_SET);
        fwrite(file_buffer, 1, file_size, Langtons_hide);
        fclose(Langtons_hide);
        freopen("key.txt","w",stdout);
        cout<<number_of_blocks<<"N"<<width<<"W"<<heigth<<"H_";
        for (int i = 0; i < number_of_blocks; i++) cout<<x_of_end[i]<<"X"<<y_of_end[i]<<"Y"<<turn_of_end[i]<<"F"<<amount_of_first_position[i]<<"A"<<x_of_first_position[i]<<"U"<<y_of_first_position[i]<<"I_";
        fclose(stdout);
        msg="File successfully encrypted. File with key is created in this folder.";
        wxMessageBox(msg, _("All is done"));
    }
}

void EncAntFrame::OnButton2Click2(wxCommandEvent& event)
{
    string key=b;
    wxString msg;

    const char* file_name = &a[0];
    FILE* Langtons_hide = fopen( file_name, "r+b" );

    if (Langtons_hide == NULL)
    {
        msg = "Error opening file.";
        wxMessageBox(msg, _("Error"));
    }
    else
    {
    fseek(Langtons_hide , 0 , SEEK_END);
    long long file_size = ftell(Langtons_hide);
    rewind (Langtons_hide);
    char * file_buffer = (char*) malloc(sizeof(char) * file_size);
    size_t result = fread(file_buffer, 1, file_size, Langtons_hide);

        int ukazatel = 0;
        long long num_of_blo = 0, wid = 0, hei = 0, digit;
        char z;
        while (key[ukazatel] != 'N')
        {
            z = key[ukazatel];
            digit = (int)z - (int)'0';
            num_of_blo = num_of_blo * 10 + digit;
            ukazatel++;
        }
        ukazatel++;
        while (key[ukazatel] != 'W')
        {
            z = key[ukazatel];
            digit = (int)z - (int)'0';
            wid = wid * 10 + digit;
            ukazatel++;
        }
        ukazatel++;
        while (key[ukazatel] != 'H')
        {
            z = key[ukazatel];
            digit = (int)z - (int)'0';
            hei = hei * 10 + digit;
            ukazatel++;
        }
        long long x_end[num_of_blo] = {0}, y_end[num_of_blo] = {0}, turn_end[num_of_blo] = {0}, amount_position[num_of_blo] = {0}, x_fir[num_of_blo] = {0}, y_fir[num_of_blo] = {0};
        for (long long i = 0; i < num_of_blo; i++)
        {
            ukazatel++;
            ukazatel++;
            while (key[ukazatel] != 'X')
            {
                z = key[ukazatel];
                digit = (int)z - (int)'0';
                x_end[i] = x_end[i] * 10 + digit;
                ukazatel++;
            }
            ukazatel++;
            while (key[ukazatel] != 'Y')
            {
                z = key[ukazatel];
                digit = (int)z - (int)'0';
                y_end[i] = y_end[i] * 10 + digit;
                ukazatel++;
            }
            ukazatel++;
            while (key[ukazatel] != 'F')
            {
                z = key[ukazatel];
                digit = (int)z - (int)'0';
                turn_end[i] = turn_end[i] * 10 + digit;
                ukazatel++;
            }
            ukazatel++;
            while (key[ukazatel] != 'A')
            {
                z = key[ukazatel];
                digit = (int)z - (int)'0';
                amount_position[i] = amount_position[i] * 10 + digit;
                ukazatel++;
            }
            ukazatel++;
            while (key[ukazatel] != 'U')
            {
                z = key[ukazatel];
                digit = (int)z - (int)'0';
                x_fir[i] = x_fir[i] * 10 + digit;
                ukazatel++;
            }
            ukazatel++;
            while (key[ukazatel] != 'I')
            {
                z = key[ukazatel];
                digit = (int)z - (int)'0';
                y_fir[i] = y_fir[i] * 10 + digit;
                ukazatel++;
            }
        }

        int buf_co = 0;
        int buf_ch = 0;
        for (int nomer_block = 1; nomer_block <= num_of_blo; nomer_block++)
        {
            long long on_first_position = amount_position[nomer_block - 1];
            int block[wid][hei], x = x_end[nomer_block - 1], y = y_end[nomer_block - 1], forwarding = turn_end[nomer_block - 1];
            int x_first_position = x_fir[nomer_block - 1], y_first_position = y_fir[nomer_block - 1];
            bool checker[wid][hei];
            int counter_checker = 0, ix = 0, iy = 0;

            for (int i = 1; i <= (wid * hei) / 8; i++)
            {
                int bait = static_cast<int>(file_buffer[buf_co]);
                if (bait < 0) bait += 256;
                buf_co++;
                int bit_our[8];
                for (int bitok = 0; bitok <= 7; bitok++) bit_our[bitok] = bit_of_this(bait, bitok);
                int ukaz = 0;

                while (ukaz != 8)
                {
                    block[ix][iy] = bit_our[ukaz];
                    ukaz++;
                    if (ix < wid - 1)
                    {
                        ix++;
                    }
                    else
                    {
                        ix = 0;
                        iy++;
                    }
                }
            }

            while (on_first_position != 0)
            {
                    if (forwarding == 1)
                    {
                        if (y + 1 <= hei - 1)
                        {
                            y += 1;
                        }
                        else
                        {
                            y = 0;
                            x = (wid - 1) - x;
                        }
                    }
                    else if (forwarding == 2)
                    {
                        if (x >= 1)
                        {
                            x -= 1;
                        }
                        else
                        {
                            x = wid - 1;
                            y = (hei - 1) - y;
                        }
                    }
                    else if (forwarding == 3)
                    {
                        if (y >= 1)
                        {
                            y -= 1;
                        }
                        else
                        {
                            y = hei - 1;
                            x = (wid - 1) - x;
                        }
                    }
                    else if (forwarding == 4)
                    {
                        if (x + 1 <= wid - 1)
                        {
                            x += 1;
                        }
                        else
                        {
                            x = 0;
                            y = (hei - 1) - y;
                        }
                    }
                    if (block[x][y] == 1)
                    {
                        block[x][y] = 0;
                        if (forwarding == 1) forwarding = 2;
                        else if (forwarding == 2) forwarding = 3;
                        else if (forwarding == 3) forwarding = 4;
                        else if (forwarding == 4) forwarding = 1;
                    }
                    else
                    {
                        block[x][y] = 1;
                        if (forwarding == 1) forwarding = 4;
                        else if (forwarding == 2) forwarding = 1;
                        else if (forwarding == 3) forwarding = 2;
                        else if (forwarding == 4) forwarding = 3;
                    }
                    if (x == x_first_position && y == y_first_position) on_first_position--;
            }
            int bit_now = 0;
            int code = 0;
            for (int j = 0; j < hei; j++)
            {
                for (int i = 0; i < wid; i++)
                {
                    code+=block[i][j]*pow(2,7-bit_now);
                    if (bit_now != 7) bit_now++;
                    else
                    {
                        bit_now = 0;
                        if (code >= 128) code -= 256;
                        file_buffer[buf_ch] = char(code);
                        buf_ch++;
                        code = 0;
                    }
                }
            }
        }
        fseek(Langtons_hide, 0, SEEK_SET);
        fwrite(file_buffer, 1, file_size, Langtons_hide);
        fclose(Langtons_hide);
        msg="File successfully decrypted.";
        wxMessageBox(msg, _("All is done"));
    }
}
