//yas girip ne kadar sürede hayatta olduhunu göstern struct programı :
#include <iostream>
#include <ctime>

using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

//2 tarih arası farkı hesaplayacak fonksiyon :
Date calculateAge(const Date& birthDate,const Date& currentDate){
    Date age;
    age.year=currentDate.year-birthDate.year;
    age.month=currentDate.month-birthDate.month;
    age.day=currentDate.day-birthDate.day;
    
    if(age.day<0){
        age.day+=30;
        age.month--;
    }
    if(age.month<0){
        age.month +=12;
        age.year--;
    }
    return age;
}
int main(){
    //bugunun tarihini alalım
    time_t t= time(nullptr);
    tm* now = localtime(&t);
    Date currentDate;
    currentDate.year=now -> tm_year +1900;
    currentDate.month=now->tm_mon +1;
    currentDate.day=now->tm_mday;

//kullanıcıdan dogum günüün al
Date birthDate;
cout<<"Doğum yılınızı giriniz:";
cin>>birthDate.year;
cout<<"dogum ayınızı giriniz:";
cin>>birthDate.month;
cout<<"dogum gününüzü giriniz:";
cin>>birthDate.day;
Date age = calculateAge(birthDate, currentDate);
cout << "Şu anda " << age.year << " yıl, " << age.month << " ay, " << age.day << " gündür yaşıyorsunuz." << endl;

    return 0;
}

