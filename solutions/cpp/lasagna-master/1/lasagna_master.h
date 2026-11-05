#pragma once
#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime( std::vector<std::string> layers, int averagePrepTime =2); 

amount quantities( std::vector<std::string> layers); 

void addSecretIngredient(std::vector<std::string> &recipe_ingredients, 
                             const std::vector<std::string> &friends_ingredients);

void addSecretIngredient(std::vector<std::string> &recipe_ingredients, std::string secret_ingredient);
    
std::vector<double> scaleRecipe(std::vector<double> amounts, int desired_portions_qty);

    
}  // namespace lasagna_master
