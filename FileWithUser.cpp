//
//  FileWithUser.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "FileWithUser.hpp"
/*
void FileWithUser::addUserToFile(User user)     
{
    string liniaZDanymiUzytkownika = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAME_FILE.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(user);
        
        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << NAME_FILE << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}
string FileWithUser::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User user)
{
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += AuxiliaryMethods::convertIntToString(user.getId()) + '|';
    liniaZDanymiUzytkownika += user.getName() + '|';
    liniaZDanymiUzytkownika += user.getSurname() + '|';
    liniaZDanymiUzytkownika += user.getLogin() + '|';
    liniaZDanymiUzytkownika += user.getPassword() + '|';

    return liniaZDanymiUzytkownika;
}

bool FileWithUser::czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

void FileWithUser::saveAllUseresToFile(vector <User> &users)
{
    
    string lineWithDataUser = "";

    vector <User>::iterator itrKoniec = --users.end();
    fstream plikTekstowy;
    plikTekstowy.open(NAME_FILE.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            lineWithDataUser = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               plikTekstowy << lineWithDataUser;
            }
            else
            {
                plikTekstowy << lineWithDataUser << endl;
            }
            lineWithDataUser = "";
        }
         plikTekstowy.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << NAME_FILE << endl;
    }
   
}

vector <User> FileWithUser::loadAllUsersWithFile()
{
    vector <User> users;
    User user;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAME_FILE.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            user = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            users.push_back(user);
        }

    }
    plikTekstowy.close();
    return users;
}

User FileWithUser::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    User user;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                    user.setId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                    user.setName(pojedynczaDanaUzytkownika);
                break;
            case 3:
                    user.setSurname(pojedynczaDanaUzytkownika);
                break;
            case 4:
                    user.setLogin(pojedynczaDanaUzytkownika);
                break;
            case 5:
                    user.setPassword(pojedynczaDanaUzytkownika);
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return user;
}
 
*/
void FileWithUser::addUserToFileXML(User user)
{
    AuxiliaryMethods auxiliaryMethods;
    
    pugi::xml_document doc; 
    pugi::xml_parse_result result = doc.load_file("Test",pugi::parse_default|pugi::parse_declaration);
    if (!result)
    {
        //jesli nie istnieje plik;
        cout << "Plik NIe istnieje" << endl;
        auto root = doc.append_child("Uzytkownicy"); // tworznie nowego pliku z galezia glowna
        pugi::xml_node Uzytkownik = root.append_child("Uzytkownik");
           
       pugi::xml_node id = Uzytkownik.append_child("ID");
       id.append_child(pugi::node_pcdata).set_value(auxiliaryMethods.convertIntToString(user.getId()).c_str());
       pugi::xml_node name = Uzytkownik.append_child("Name");
       name.append_child(pugi::node_pcdata).set_value(user.getName().c_str());
       pugi::xml_node surName = Uzytkownik.append_child("Surname");
       surName.append_child(pugi::node_pcdata).set_value(user.getSurname().c_str());
       pugi::xml_node login = Uzytkownik.append_child("Login");
       login.append_child(pugi::node_pcdata).set_value(user.getLogin().c_str());
       pugi::xml_node password = Uzytkownik.append_child("Password");
       password.append_child(pugi::node_pcdata).set_value(user.getPassword().c_str());
           
        //doc.print(std::cout); //wyswietlenie w terminalu;
        bool saveSucceeded = doc.save_file("Test");
        assert(saveSucceeded);
    }
    else
    {
       
    pugi::xml_node root = doc.document_element(); // dodawanie kolejnych uzytkownikow
    pugi::xml_node Uzytkownik = root.append_child("Uzytkownik");
    
    pugi::xml_node id = Uzytkownik.append_child("ID");
    id.append_child(pugi::node_pcdata).set_value(auxiliaryMethods.convertIntToString(user.getId()).c_str());
    pugi::xml_node name = Uzytkownik.append_child("Name");
    name.append_child(pugi::node_pcdata).set_value(user.getName().c_str());
    pugi::xml_node surName = Uzytkownik.append_child("Surname");
    surName.append_child(pugi::node_pcdata).set_value(user.getSurname().c_str());
    pugi::xml_node login = Uzytkownik.append_child("Login");
    login.append_child(pugi::node_pcdata).set_value(user.getLogin().c_str());
    pugi::xml_node password = Uzytkownik.append_child("Password");
    password.append_child(pugi::node_pcdata).set_value(user.getPassword().c_str());
    
     //doc.print(std::cout); //wyswietlenie w terminalu;
      bool saveSucceeded = doc.save_file("Test");
      assert(saveSucceeded);
    }
}


