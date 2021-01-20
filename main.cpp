#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char * ft_read(std::string filename)
{
    size_t lenght = 0;
    char * buf = 0; 
    ifstream fs;
    fs.open(filename, ios::in);
        if (fs.is_open())
        {
            fs.seekg(0, ios::end); //перемещаемся в конец
            lenght = fs.tellg(); //текущая позиция чтения
            buf = new char[1 + lenght];
            buf[lenght] = 0;
            int j = 0;
            for (int i = lenght; i > 0; i--, j++)
            {
                fs.seekg(-i, ios::end);
                buf[j] = fs.get();
                //cout << buf[j] << endl;
            }
            fs.close();
        } 
    return buf;
}

void ft_right(char c, int pos)
{
    ofstream fs;
    fs.open("file_common.txt", ios::app);
    if (fs.is_open())
    {
        fs.seekp(pos, ios::end);
        fs.put(c);
    }
}

int main(int argc, char **argv)
{
    setlocale( LC_ALL,"Russian" );
    char * buf_1 = ft_read("file_1.txt");
    char * buf_2 = ft_read("file_2.txt");

    int i = 0; //счетчик превого массива
    int j = 0; //счетчик второго массива
    int pos = 0; //позиция записи файла

    while (buf_1[i] != '\0')
    {
        while (buf_2[j] != '\0')
        {
            cout << buf_1[i] << endl;
            cout << buf_2[j] << endl;
            
            if (buf_1[i] == buf_2[j])
            {
                cout << "Check OK" << endl;
                ft_right(buf_1[i], pos); //записываем в файл
                //pos++; не используем, запись ведется в конец файла
                j++;
            } 
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}