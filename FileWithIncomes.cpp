//
//  FileWithIncomes.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 26/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "FileWithIncomes.hpp"
void FileWithIncomes::addIncomeToFile(Income income)
{
    AuxiliaryMethods auxiliaryMethods;
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(getNameFile().c_str(),pugi::parse_default|pugi::parse_declaration);
    if (!result)
    {
        //jesli nie istnieje plik;
       
        auto root = doc.append_child("Wplywy"); // tworznie nowego pliku z galezia glowna
        pugi::xml_node Uzytkownik = root.append_child("wplyw");
           
        pugi::xml_node inconeId = Uzytkownik.append_child("inconeId");
        inconeId.append_child(pugi::node_pcdata).set_value(to_string(income.getIncomeId()).c_str());
        pugi::xml_node userId = Uzytkownik.append_child("userId");
        userId.append_child(pugi::node_pcdata).set_value(to_string(income.getUserId()).c_str());
        pugi::xml_node date = Uzytkownik.append_child("date");
        date.append_child(pugi::node_pcdata).set_value(income.getDate().c_str());
        pugi::xml_node item = Uzytkownik.append_child("item");
        item.append_child(pugi::node_pcdata).set_value(income.getItem().c_str());
        pugi::xml_node amount = Uzytkownik.append_child("amount");
        amount.append_child(pugi::node_pcdata).set_value(auxiliaryMethods.convertDoubleToString(income.getAmount()).c_str());
        
        bool saveSucceeded = doc.save_file(getNameFile().c_str());
        assert(saveSucceeded);
    }
    else
    {
        pugi::xml_node root = doc.document_element(); // dodawanie kolejnych uzytkownikow
        pugi::xml_node Uzytkownik = root.append_child("wplyw");
        
        pugi::xml_node inconeId = Uzytkownik.append_child("inconeId");
        inconeId.append_child(pugi::node_pcdata).set_value(to_string(income.getIncomeId()).c_str());
        pugi::xml_node userId = Uzytkownik.append_child("userId");
        userId.append_child(pugi::node_pcdata).set_value(to_string(income.getUserId()).c_str());
        pugi::xml_node date = Uzytkownik.append_child("date");
        date.append_child(pugi::node_pcdata).set_value(income.getDate().c_str());
        pugi::xml_node item = Uzytkownik.append_child("item");
        item.append_child(pugi::node_pcdata).set_value(income.getItem().c_str());
        pugi::xml_node amount = Uzytkownik.append_child("amount");
        amount.append_child(pugi::node_pcdata).set_value(auxiliaryMethods.convertDoubleToString(income.getAmount()).c_str());

        bool saveSucceeded = doc.save_file(getNameFile().c_str());
        assert(saveSucceeded);
    }
}
int FileWithIncomes::getTheIdOfLastIncome()
{
    return idOfLastIncome;  
}
vector <Income> FileWithIncomes::loadIncomesOfLoggedInUserFromFile(int loggedInUserId)
{
    vector <Income> incomes;
    Income income;

    pugi::xml_document doc;
    if (!doc.load_file(getNameFile().c_str())) cout << "nie ma pliku";

    pugi::xml_node selectedNode = doc.child("Wplywy");

    for (pugi::xml_node tool = selectedNode.child("wplyw"); tool; tool = tool.next_sibling("wplyw"))
    {
        income.setIncomeId(tool.child("inconeId").text().as_int());
        income.setUserId(tool.child("userId").text().as_int());
        income.setDate(tool.child("date").text().as_string());
        income.setItem(tool.child("item").text().as_string());
        income.setAmount(tool.child("amount").text().as_double());
        incomes.push_back(income);
    }
        return incomes;
}


