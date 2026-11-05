#include "protein_translation.h"
#include <unordered_map>
namespace protein_translation {

    std::vector<std::string> proteins(std::string code) {
        std::unordered_map<std::string, std::string> codon_to_amino_acid = {
            {"AUG" , "Methionine" },
            {"UUU", "Phenylalanine" },
            {"UUC", "Phenylalanine" },
            {"UUA", "Leucine"},
            {"UUG", "Leucine"},
            {"UCU", "Serine"},
            {"UCC", "Serine"},
            {"UCA", "Serine"},
            {"UCG", "Serine"},
            {"UAU", "Tyrosine"},
            {"UAC", "Tyrosine"},
            {"UGU", "Cysteine"},
            {"UGC", "Cysteine"},
            {"UGG", "Tryptophan"},
            {"UAA", "STOP"},
            {"UAG", "STOP"},
            {"UGA", "STOP"}
        };
        std::vector<std::string> proteins{};
        
        for (size_t i = 0; i < code.length(); i += 3) {
            auto codon = code.substr(i, 3);
            auto protein_decode = codon_to_amino_acid.at(codon);
            if (protein_decode == "STOP") {
                break;
            } else {
                proteins.push_back(protein_decode);
            }
        }
        return proteins;
    }
}  // namespace protein_translation
