//
//  FileWithUser.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 18/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "FileWithUser.hpp"

void FileWithUser::addUserToFileXML(User user)
{
    AuxiliaryMethods auxiliaryMethods;
    
    pugi::xml_document doc; 
    pugi::xml_parse_result result = doc.load_file(getNameFile().c_str(),pugi::parse_default|pugi::parse_declaration);
    if (!result)
    {
        //jesli nie istnieje plik;
       
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
        bool saveSucceeded = doc.save_file(getNameFile().c_str());
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
      bool saveSucceeded = doc.save_file(getNameFile().c_str());
      assert(saveSucceeded);
    }
}

vector <User> FileWithUser::readUsersFromFile()
{
    vector <User> users;
    User user;

    pugi::xml_document doc;
    if (!doc.load_file(getNameFile().c_str())) cout << "nie ma pliku";

    pugi::xml_node selectedNode = doc.child("Uzytkownicy");

    for (pugi::xml_node tool = selectedNode.child("Uzytkownik"); tool; tool = tool.next_sibling("Uzytkownik"))
    {
        user.setId(tool.child("ID").text().as_int());
        user.setName(tool.child("Name").text().as_string());
        user.setSurname(tool.child("Surname").text().as_string());
        user.setLogin(tool.child("Login").text().as_string());
        user.setPassword(tool.child("Password").text().as_string());
        users.push_back(user);
    }
    return users;
}

void FileWithUser::saveAllUseresToFile(vector <User> &users)
{
    AuxiliaryMethods auxiliaryMethods;
    User user;
    
    pugi::xml_document doc;
    
    auto root = doc.append_child("Uzytkownicy"); // tworznie nowego pliku z galezia glowna
    pugi::xml_node Uzytkownik = root.append_child("Uzytkownik");
      
    
    for (vector<User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        pugi::xml_node id = Uzytkownik.append_child("ID");
        id.append_child(pugi::node_pcdata).set_value(auxiliaryMethods.convertIntToString(itr->getId()).c_str());
        pugi::xml_node name = Uzytkownik.append_child("Name");
        name.append_child(pugi::node_pcdata).set_value(itr->getName().c_str());
        pugi::xml_node surName = Uzytkownik.append_child("Surname");
        surName.append_child(pugi::node_pcdata).set_value(itr->getSurname().c_str());
        pugi::xml_node login = Uzytkownik.append_child("Login");
        login.append_child(pugi::node_pcdata).set_value(itr->getLogin().c_str());
        pugi::xml_node password = Uzytkownik.append_child("Password");
        password.append_child(pugi::node_pcdata).set_value(itr->getPassword().c_str());
    }
    
    //doc.print(std::cout); //wyswietlenie w terminalu;
    bool saveSucceeded = doc.save_file("DocTemp");
    assert(saveSucceeded);
    auxiliaryMethods.deleteFile(getNameFile().c_str());
    auxiliaryMethods.changeNameFile("DocTemp", getNameFile().c_str());
}

