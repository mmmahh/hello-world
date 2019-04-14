#include<iostream>
#include<cstring>

class MyString
{
    public:
        MyString(){str=new char[1];str[0]='\0';len=0;};//默认构造函数
        MyString(const char * s);
        MyString(const MyString & s);
        ~MyString();
        int length() const;
        MyString & operator=(const MyString & s);//赋值操作符
        MyString & operator=(const char *);
        char & operator[](int i);
        friend std::ostream & operator<<(std::ostream & os, const MyString & s);
        friend std::istream & operator>>(std::istream & is, MyString & s);
    private:
        char * str;
        int len;
        static const int CINLIM = 80;// cin input limit
};
MyString::MyString(const char * s)
{
    len = strlen(s);
    str = new char [len+1];
    strcpy(str,s);
}
MyString::MyString(const MyString & s)
{
    len = s.len;
    str = new char[len+1];
    strcpy(str,s.str);
}
MyString::~MyString()
{
    delete[] str;
}
int MyString::length() const
{
    return len;
}
MyString & MyString::operator=(const MyString & s)
{
    if(this == &s)
        return *this;
    delete[]str;
    len = s.len;
    str = new char[len+1];
    strcpy(str,s.str);
    return *this;
}
MyString & MyString::operator=(const char * s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    return *this;
}
char & MyString::operator[](int i)
{
    return str[i];
}
std::ostream & operator<<(std::ostream & os,const MyString & s)
{
    os<<s.str;
    return os;
}
std::istream & operator>>(std::istream & is, MyString & s)
{
    char temp[MyString::CINLIM];
    is.get(temp, MyString::CINLIM);
    if(is)
        s = temp;
    while(is && is.get()!='\n')
        continue;
    return is;
}
int main()
{   
    MyString a;
    std::cin>>a;
    std::cout<<a;

    system("pause");
    return 0;
}

