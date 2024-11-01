#include "MainForm.h"
#include <Windows.h>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace Komivoyazhor; // Название проекта


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MainForm);

    return 0;

}

int HeightGraf = 75, WeighttGraf = 75;
int NumGrafs = 0, NumLines = 0;
int** matrixPytei = new int* [21];

ref class MyPensil
{
public:
    MyPensil()
    {
        MyPen = gcnew System::Drawing::Pen(System::Drawing::Color::Orange);
        MyPen->Width = 3;
        MyPen->LineJoin = System::Drawing::Drawing2D::LineJoin::Miter;
    }
    System::Drawing::Pen^ MyPen;
};
System::Void Komivoyazhor::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    this->Size = System::Drawing::Size(SystemInformation::VirtualScreen.Width, SystemInformation::VirtualScreen.Height);
    for (int i = 0; i < 21; i++)
    {
        matrixPytei[i] = new int[21]{ -1 };
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            matrixPytei[i][j] = -1;
        }
    }
}
System::Void Komivoyazhor::MainForm::tb_vecRebra_Enter(System::Object^ sender, System::EventArgs^ e)
{
    if (tb_vecRebra->Text == "Введите вес ребра")
    {
        tb_vecRebra->Text = "";
        tb_vecRebra->ForeColor = Color::Black;
    }
}
System::Void Komivoyazhor::MainForm::tb_vecRebra_Leave(System::Object^ sender, System::EventArgs^ e)
{
    if (tb_vecRebra->Text == "")
    {
        tb_vecRebra->ForeColor = Color::DarkGray;
        tb_vecRebra->Text = "Введите вес ребра";
    }
}
bool load = true; //для отрисовки только первичных графов

System::Void Komivoyazhor::MainForm::panel_uzlov_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
    if (load == true)
    {
        AddGrafs(500, 700);
        AddGrafs(700, 220);
        AddGrafs(240, 330);
        AddGrafs(210, 590);
        AddGrafs(350, 100);
        AddGrafs(820, 550);
        load = false;
        AddLines(4 - 1, 1 - 1, 5); //вес между 4 и 1
        AddLines(4 - 1, 3 - 1, 3); //вес между 4 и 3
        AddLines(3 - 1, 5 - 1, 21); //вес между 3 и 5
        AddLines(3 - 1, 2 - 1, 16); //вес между 3 и 2
        AddLines(3 - 1, 1 - 1, 18); //вес между 3 и 1
        AddLines(2 - 1, 1 - 1, 12); //вес между 2 и 1
        AddLines(6 - 1, 1 - 1, 34); //вес между 6 и 1
        AddLines(2 - 1, 6 - 1, 45); //вес между 2 и 6
        AddLines(5 - 1, 2 - 1, 53); //вес между 5 и 2

    }
}

//добавление графа
System::Void Komivoyazhor::MainForm::AddGrafs(int x, int y)
{
    Graphics^ g;
    g = this->panel_uzlov->CreateGraphics();
    g->FillEllipse(Brushes::Orange, x, y, HeightGraf, WeighttGraf);
    AddLocationGrafs(x, y);
}
//запоминание площади положения графов
std::vector<std::vector<int>> LocationGrafs;
System::Void Komivoyazhor::MainForm::AddLocationGrafs(int x, int y)
{
    int indexPust = -1;
    if (LocationGrafs.size() != 0)
    {
        for (int i = 0; i < LocationGrafs.size(); i++)//таблицу с локацией мы не очищаем, а просто перезаписываем на "пустые" места, либо добавляем новые строки
        {
            if (LocationGrafs[i][0] == -1 && LocationGrafs[i][1] == -1) {
                indexPust = i; break;
            }
        }
    }

    NumGrafs++;
    std::vector<int> Temp;
    Temp.push_back(x); 
    Temp.push_back(y);
    if (indexPust == -1) 
    {
        LocationGrafs.push_back(Temp);
        TextOnGrafs(x, y, NumGrafs);
    }
    else
    {
        LocationGrafs[indexPust][0] = x;
        LocationGrafs[indexPust][1] = y;
        TextOnGrafs(x, y, indexPust + 1);
    }
    
    Temp.clear();

}
//расстановка текста графов
System::Void Komivoyazhor::MainForm::TextOnGrafs(int x, int y, int NumGrafs)
{
    System::Windows::Forms::Button^ bt = gcnew System::Windows::Forms::Button();
    bt->Location = System::Drawing::Point(x + WeighttGraf/4, y + HeightGraf/4);
    bt->Size = System::Drawing::Size(WeighttGraf - WeighttGraf / 2, HeightGraf - HeightGraf / 2);
    bt->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    bt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    bt->Text = NumGrafs.ToString();
    bt->BackColor = System::Drawing::Color::Orange;
    bt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    bt->FlatAppearance->BorderSize = 0;
    bt->Cursor = System::Windows::Forms::Cursors::Hand;
    bt->Name = "btnGraf";
    bt->Click += gcnew System::EventHandler(this, &MainForm::btnGraf_MouseClick);
    panel_uzlov->Controls->Add(bt);
}


//добавление линии
System::Void Komivoyazhor::MainForm::AddLines(int indexGraf1, int indexGraf2, int vecRebra)
{
    Graphics^ g;
    MyPensil myPensil;
    g = this->panel_uzlov->CreateGraphics();
    int polovinaX = WeighttGraf / 2, polovinaY = HeightGraf / 2;
    //отцентруем начала лучей относительно графов
    int X1 = LocationGrafs[indexGraf1][0] + polovinaX, 
        Y1 = LocationGrafs[indexGraf1][1] + polovinaY,
        X2 = LocationGrafs[indexGraf2][0] + polovinaX,
        Y2 = LocationGrafs[indexGraf2][1] + polovinaY;

    double lineLength;
    double MAX_LINE_LENGTH;
    lineLength = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
    MAX_LINE_LENGTH = lineLength - WeighttGraf / 2;
    X2 = X1 + (X2 - X1) / lineLength * MAX_LINE_LENGTH;
    Y2 = Y1 + (Y2 - Y1) / lineLength * MAX_LINE_LENGTH;

    lineLength = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
    MAX_LINE_LENGTH = lineLength - WeighttGraf / 2;
    X1 = X2 - (X2 - X1) / lineLength * MAX_LINE_LENGTH;
    Y1 = Y2 - (Y2 - Y1) / lineLength * MAX_LINE_LENGTH;
    g->DrawLine(myPensil.MyPen, X1, Y1, X2, Y2);
    
    TextOnLines(X1, Y1, X2, Y2, indexGraf1, indexGraf2, vecRebra);
}

//печать текста на линии
System::Void Komivoyazhor::MainForm::TextOnLines(int x1, int y1, int x2, int y2, int indexGraf1, int indexGraf2, int vecRebra)
{
    System::Windows::Forms::Button^ bt = gcnew System::Windows::Forms::Button();
    int x = x1 + (x2 - x1) / 2, y = y1 + (y2 - y1) / 2;
    bt->Location = System::Drawing::Point(x, y);
    bt->Size = System::Drawing::Size(35, 20);
    bt->AutoSize = true;
    bt->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    bt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    bt->Text = vecRebra.ToString(); tb_vecRebra->ForeColor = Color::DarkGray; tb_vecRebra->Text = "Введите вес ребра";
    bt->BackColor = System::Drawing::Color::Transparent;
    bt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    bt->FlatAppearance->BorderSize = 0;
    bt->Cursor = System::Windows::Forms::Cursors::Hand;
    bt->Name = "btnLine";
    bt->Click += gcnew System::EventHandler(this, &MainForm::btnLine_MouseClick);
    panel_uzlov->Controls->Add(bt);

    AddLocationLines(x, y, indexGraf1, indexGraf2);
}
//запоминание площади положения ТЕКСТА линии + индексов узлов, которые она соединяет
std::vector<std::vector<std::vector<std::vector<int>>>> LocationLines;
System::Void Komivoyazhor::MainForm::AddLocationLines(int x, int y, int indexGraf1, int indexGraf2)
{
    int indexPust = -1;
    if (LocationLines.size() != 0)
    {
        for (int i = 0; i < LocationLines.size(); i++)//таблицу с локацией мы не очищаем, а просто перезаписываем на "пустые" места, либо добавляем новые строки
        {
            if (LocationLines[i][0][0][0] == -1 &&
                LocationLines[i][0][0][1] == -1 &&
                LocationLines[i][0][1][0] == -1 &&
                LocationLines[i][0][1][1] == -1) {
                indexPust = i; break;
            }
        }
    }
    
    std::vector<int> Temp;
    Temp.push_back(x);
    Temp.push_back(y);
    std::vector<std::vector<int>> Temp2;
    Temp2.push_back(Temp); 
    Temp.clear();
    Temp.push_back(indexGraf1);
    Temp.push_back(indexGraf2);
    Temp2.push_back(Temp);
    std::vector<std::vector<std::vector<int>>> Temp3;
    Temp3.push_back(Temp2);
    if (indexPust == -1)
    {
        LocationLines.push_back(Temp3);
        matrixPytei[indexGraf1][indexGraf2] = LocationLines.size() - 1;
        matrixPytei[indexGraf2][indexGraf1] = LocationLines.size() - 1;
        for (int i = 0; i < NumGrafs; i++)
        {
            if(matrixPytei[NumGrafs - 1][i] == 0)
            matrixPytei[NumGrafs-1][i] = -1;
        }
        for (int i = 0; i < NumGrafs; i++)
        {
            if (matrixPytei[i][NumGrafs - 1] == 0)
            matrixPytei[i][NumGrafs - 1] = -1;
        }
    }
        
    else
    {
        LocationLines[indexPust][0][0][0] = x;
        LocationLines[indexPust][0][0][1] = y;
        LocationLines[indexPust][0][1][0] = indexGraf1;
        LocationLines[indexPust][0][1][1] = indexGraf2;
        matrixPytei[indexGraf1][indexGraf2] = indexPust;
        matrixPytei[indexGraf2][indexGraf1] = indexPust;
    }
    
    Temp.clear();
    for (int i = 0; i < NumGrafs; i++)
    {
        for (int j = 0; j < NumGrafs; j++)
        {
            textBox_console->Text += String::Format("{0,6:F3}", matrixPytei[i][j] + "  ");
            
        }
        textBox_console->Text += "\r\n";
    }
    textBox_console->Text += "\r\n";
    
    NumLines++;
}


System::Void Komivoyazhor::MainForm::panel_uzlov_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    Graphics^ g;
    g = this->panel_uzlov->CreateGraphics();
    if (rb_addUzel->Checked == true)
    {
        g->FillEllipse(Brushes::Orange, (e->Location.X) - HeightGraf / 2, (e->Location.Y) - WeighttGraf / 2, HeightGraf, WeighttGraf);
        AddGrafs((e->Location.X) - HeightGraf / 2, (e->Location.Y) - WeighttGraf / 2);
    }
    
}
int countClic = 0;
//перевод из String^ в string
void MarshalString(String^ s, std::string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}
//сброс количества кликов на кнопки
System::Void Komivoyazhor::MainForm::rb_addRebro_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    countClic = 0;
}
std::string nameGraf1, nameGraf2;
System::Void Komivoyazhor::MainForm::btnGraf_MouseClick(System::Object^ sender, System::EventArgs^ e)
{
    Button^ b = (Button^)sender;
    if (rb_addRebro->Checked == true)
    {
        ++countClic;
        if (countClic == 1)
        {
            MarshalString(b->Text, nameGraf1);
        }
        else
        {
            countClic = 0;
            MarshalString(b->Text, nameGraf2);
            if (nameGraf1 != nameGraf2)
            {
                if (tb_vecRebra->Text != "Введите вес ребра")
                {
                    AddLines(atoi(nameGraf1.c_str()) - 1, atoi(nameGraf2.c_str()) - 1, Convert::ToInt32(tb_vecRebra->Text));
                }
                else MessageBox::Show("Введите вес ребра!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }
    }
    if (rb_deleteUzel->Checked == true)
    {
        Button^ b = (Button^)sender;
        Controls->Remove(b);
        b->Visible = false;

        int indexGrafDelete;
        for (int i = 0; i < LocationGrafs.size(); i++)//для строк матрицы 
        {
            //если локация проверяемого графа равна локации кнопки, на которую нажали - запоминаем индекс этого графа
            if (LocationGrafs[i][0] == b->Location.X - WeighttGraf / 4 && LocationGrafs[i][1] == b->Location.Y - HeightGraf / 4)
            {
                indexGrafDelete = i;
                //зная индекс этого графа, находим в матрице смежности по очереди индексы линий
                for (int j = 0; j < LocationGrafs.size(); j++)
                {
                    if (matrixPytei[i][j] != -1)//если есть связь графа с этой линией
                    {
                        for each (Control^ bt in panel_uzlov->Controls) //для всех контролов панели
                        {
                            if (bt->Name == "btnLine")//если этот контрол - линия
                            {
                                bt->Text;
                                //если локация проверяемой кнопки линии совпадает с локацией линии по индексу этой линии
                                if (bt->Location.X == LocationLines[matrixPytei[i][j]][0][0][0] && 
                                    bt->Location.Y == LocationLines[matrixPytei[i][j]][0][0][1])
                                {
                                    Controls->Remove(bt);//удаляем кнопку линии графически
                                    bt->Visible = false;

                                    deleteLine(i, j, matrixPytei[i][j]);//удаляем данные о линии и графически саму линию
                                    break;
                                }
                            }
                            
                        }
                    }
                }
            }
        }

        deleteGraf(b->Location.X - WeighttGraf / 4, b->Location.Y - HeightGraf / 4, indexGrafDelete);//удаление графа графически и данных о нем

    }
}
System::Void Komivoyazhor::MainForm::deleteGraf(int x, int y, int indexGrafDelete)
{
    Graphics^ g;
    g = this->panel_uzlov->CreateGraphics();
    g->FillEllipse(Brushes::White, x, y, HeightGraf, WeighttGraf);

    for (int i = 0; i < NumGrafs; i++)
    {
        matrixPytei[i][indexGrafDelete] = -1;
    }
    for (int i = 0; i < NumGrafs; i++)
    {
        matrixPytei[indexGrafDelete][i] = -1;
    }
    LocationGrafs[indexGrafDelete][0] = LocationGrafs[indexGrafDelete][1] = -1;

    NumGrafs--;

}
System::Void Komivoyazhor::MainForm::deleteLine(int indexGraf1, int indexGraf2, int indexLineDelete)
{
    Graphics^ g;
    MyPensil myPensil;
    g = this->panel_uzlov->CreateGraphics();

    double polovinaX = WeighttGraf / 2, polovinaY = HeightGraf / 2;
    double X1 = LocationGrafs[indexGraf1][0] + polovinaX,
        Y1 = LocationGrafs[indexGraf1][1] + polovinaY,
        X2 = LocationGrafs[indexGraf2][0] + polovinaX,
        Y2 = LocationGrafs[indexGraf2][1] + polovinaY;
    myPensil.MyPen->Color = System::Drawing::Color::White;

    double lineLength;
    double MAX_LINE_LENGTH;
    lineLength = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
    MAX_LINE_LENGTH = lineLength - WeighttGraf / 2;
    X2 = X1 + (X2 - X1) / lineLength * MAX_LINE_LENGTH;
    Y2 = Y1 + (Y2 - Y1) / lineLength * MAX_LINE_LENGTH;

    lineLength = sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
    MAX_LINE_LENGTH = lineLength - WeighttGraf / 2;
    X1 = X2 - (X2 - X1) / lineLength * MAX_LINE_LENGTH;
    Y1 = Y2 - (Y2 - Y1) / lineLength * MAX_LINE_LENGTH;
    g->DrawLine(myPensil.MyPen, (int)X1, (int)Y1, (int)X2, (int)Y2);

    //заменим в локации линий данные данной линии на -1
    LocationLines[indexLineDelete][0][0][0] =
    LocationLines[indexLineDelete][0][0][1] =
    LocationLines[indexLineDelete][0][1][0] =
    LocationLines[indexLineDelete][0][1][1] = -1;
    //заменим на -1 в матрице
    for (int i = 0; i < NumGrafs; i++)
    {
        for (int j = 0; j < NumGrafs; j++)
        {
            if (matrixPytei[i][j] == indexLineDelete)
            {
                matrixPytei[i][j] = -1;
            }
        }
    }
    NumLines--;
}

System::Void Komivoyazhor::MainForm::btnLine_MouseClick(System::Object^ sender, System::EventArgs^ e)
{
    Button^ b = (Button^)sender;
    int indexGraf1, indexGraf2;
    if (rb_deleteRebro->Checked == true)
    {
        Controls->Remove(b);
        b->Visible = false;
        sender->
        for (int i = 0; i < LocationLines.size(); i++)
        {
            if (LocationLines[i][0][0][0] == b->Location.X && LocationLines[i][0][0][1] == b->Location.Y)
            {
                indexGraf1 = LocationLines[i][0][1][0];
                indexGraf2 = LocationLines[i][0][1][1];
                deleteLine(indexGraf1, indexGraf2, i);
                break;
            }
        }
    }
    if (btn_RedactVesRebro->Checked == true)
    {
        if (tb_vecRebra->Text != "Введите вес ребра")
        {
            b->Text = tb_vecRebra->Text;
        }
        else MessageBox::Show("Введите вес ребра!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        
    }
}
