#include "lasagna_master.h"
#include <vector>

namespace lasagna_master {

    int preparationTime(std::vector<std::string> layers, int averagePrepTime){
        return layers.size() * averagePrepTime;
    }
    
    amount quantities( std::vector<std::string> layers){
        amount amounts_need{0,0};
        for ( auto layer : layers) {
           if (layer == "sauce") { amounts_need.sauce += 0.2; }
           if (layer == "noodles"){ amounts_need.noodles += 50; }            
        }
        return amounts_need;
    }

    void addSecretIngredient(std::vector<std::string> &recipe_ingredients, 
                             const std::vector<std::string> &friends_ingredients)  
    {
        recipe_ingredients.back() = friends_ingredients.back();
    }
    
    void addSecretIngredient(std::vector<std::string> &recipe_ingredients,
                            std::string secret_ingredient){
        recipe_ingredients.back() = secret_ingredient;
    }  

    std::vector<double> scaleRecipe(std::vector<double> amounts, int desired_portions_qty){
    std::vector<double> new_amounts;
    double new_amount {0.0};
    for (double amount: amounts){
        new_amount = amount * (desired_portions_qty / 2.0);
        new_amounts.push_back(new_amount);
    }
    return new_amounts;
}    
}  // namespace lasagna_master
