//
//  FileWithExpenses.cpp
//  Budget
//
//  Created by Krystian Lewandowski on 26/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "FileWithExpenses.hpp"
void FileWithExpenses::addExpenseToFile(Expense expense)
{
    AuxiliaryMethods auxiliaryMethods;
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(getNameFile().c_str(),pugi::parse_default|pugi::parse_declaration);
    if (!result)
    {
        //jesli nie istnieje plik;
       
        auto root = doc.append_child("Wydatki"); // tworznie nowego pliku z galezia glowna
        pugi::xml_node Uzytkownik = root.append_child("Wydatek");
           
        pugi::xml_node inconeId = Uzytkownik.append_child("expenseId");
        inconeId.append_child(pugi::node_pcdata).set_value(to_string(expense.getExpenseId()).c_str());
        pugi::xml_node userId = Uzytkownik.append_child("userId");
        userId.append_child(pugi::node_pcdata).set_value(to_string(expense.getUserId()).c_str());
        pugi::xml_node date = Uzytkownik.append_child("date");
        date.append_child(pugi::node_pcdata).set_value(expense.getDate().c_str());
        pugi::xml_node item = Uzytkownik.append_child("item");
        item.append_child(pugi::node_pcdata).set_value(expense.getItem().c_str());
        pugi::xml_node amount = Uzytkownik.append_child("amount");
        amount.append_child(pugi::node_pcdata).set_value(auxiliaryMethods.convertDoubleToString(expense.getAmount()).c_str());
        
       // bool saveSucceeded = doc.save_file(getNameFile().c_str());
       // assert(saveSucceeded);
        doc.save_file(getNameFile().c_str());
    }
    else
    {
        pugi::xml_node root = doc.document_element(); // dodawanie kolejnych uzytkownikow
        pugi::xml_node Uzytkownik = root.append_child("wplyw");
        
        pugi::xml_node inconeId = Uzytkownik.append_child("expenseId");
        inconeId.append_child(pugi::node_pcdata).set_value(to_string(expense.getExpenseId()).c_str());
        pugi::xml_node userId = Uzytkownik.append_child("userId");
        userId.append_child(pugi::node_pcdata).set_value(to_string(expense.getUserId()).c_str());
        pugi::xml_node date = Uzytkownik.append_child("date");
        date.append_child(pugi::node_pcdata).set_value(expense.getDate().c_str());
        pugi::xml_node item = Uzytkownik.append_child("item");
        item.append_child(pugi::node_pcdata).set_value(expense.getItem().c_str());
        pugi::xml_node amount = Uzytkownik.append_child("amount");
        amount.append_child(pugi::node_pcdata).set_value(auxiliaryMethods.convertDoubleToString(expense.getAmount()).c_str());

       // bool saveSucceeded = doc.save_file(getNameFile().c_str());
       //1 assert(saveSucceeded);
        doc.save_file(getNameFile().c_str());
    }
}

vector <Expense> FileWithExpenses::loadExpenseOfLoggedInUserFromFile(int loggedInUserId)
{
    vector <Expense> expenses;
    Expense expense;

    pugi::xml_document doc;
    if (!doc.load_file(getNameFile().c_str())) cout << "nie ma pliku";

    pugi::xml_node selectedNode = doc.child("Wydatki");

    for (pugi::xml_node tool = selectedNode.child("Wydatek"); tool; tool = tool.next_sibling("Wydatek"))
    {
        expense.setExpenseId(tool.child("inconeId").text().as_int());
        expense.setUserId(tool.child("userId").text().as_int());
        expense.setDate(tool.child("date").text().as_string());
        expense.setItem(tool.child("item").text().as_string());
        expense.setAmount(tool.child("amount").text().as_double());
        expenses.push_back(expense);
    }
        return expenses;
}
