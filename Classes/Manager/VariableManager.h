//
// Created by Nicolò Aicardi on 08/09/2023.
//

/*************
 *                                                   Variable Manager
 * Il Variable Manager avrà il compito di gestire tutte le variabili che verranno chiamate dal codice LISP-like
 *
 *************/

#include <string>
#include <unordered_map>
#include <sstream>

#ifndef INTERPRETER_VARIABLEMANAGER_H
#define INTERPRETER_VARIABLEMANAGER_H


class VariableManager {
public:
    VariableManager() = default;
    ~VariableManager() {
        valueVector.clear();
    }

    void set_value(const std::string& _name, int value){
        valueVector[_name] = value;
    }

    int get_value(const std::string& _name){
        if (valueVector.find(_name) != valueVector.end()) {
            return valueVector[_name];
        } else {
            std::stringstream _tmp{};
            _tmp << "Tentativo di accesso a variabile non dichiarata";
            throw EvaluationError(_tmp.str());
        }
    }


    std::unordered_map<std::string, int> valueVector;
};

#endif //INTERPRETER_VARIABLEMANAGER_H
