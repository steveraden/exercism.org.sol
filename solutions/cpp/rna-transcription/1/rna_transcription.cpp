#include <string>
#include <unordered_map>

namespace rna_transcription {
    
    std::unordered_map<char, char> decodes{
        {'G', 'C'},
        {'C', 'G'},
        {'T', 'A'},
        {'A' , 'U'}
    };

    char to_rna(char dna){
        return rna_transcription::decodes.at(dna);
    }

    std::string to_rna(std::string dna){
        std::string result;
        for(auto c : dna) {
            result += to_rna(c);
        }
        return result; 
    }

}  // namespace rna_transcription
